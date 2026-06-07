/*
* -----------------------------------------------------------------------------
* Example 5: Boids Flocking Simulation
* Demonstrates: Vector Math, Agent Logic (Separation, Alignment, Cohesion).
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct Vec2 {
    float x, y;
    Vec2() : x(0), y(0) {}
    Vec2(float _x, float _y) : x(_x), y(_y) {}

    Vec2 operator+(const Vec2& v) const { return Vec2(x + v.x, y + v.y); }
    Vec2 operator-(const Vec2& v) const { return Vec2(x - v.x, y - v.y); }
    Vec2 operator*(float s) const { return Vec2(x * s, y * s); }
    float Magnitude() const { return sqrtf(x * x + y * y); }
    Vec2 Normalize() const {
        float m = Magnitude();
        return (m > 0) ? Vec2(x / m, y / m) : Vec2(0, 0);
    }
};

struct Boid {
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
    float maxSpeed;
    float maxForce;

    Boid(float x, float y) : position(x, y), maxSpeed(150.0f), maxForce(3.0f) {
        velocity = Vec2((float)(rand() % 100 - 50), (float)(rand() % 100 - 50));
        acceleration = Vec2(0, 0);
    }

    void ApplyForce(Vec2 force) { acceleration = acceleration + force; }

    void Update(float dt) {
        velocity = velocity + acceleration * dt;
        if (velocity.Magnitude() > maxSpeed) {
            velocity = velocity.Normalize() * maxSpeed;
        }
        position = position + velocity * dt;
        acceleration = Vec2(0, 0); // Reset acceleration

        // Screen Wrap
        if (position.x < 0) position.x = 800;
        if (position.x > 800) position.x = 0;
        if (position.y < 0) position.y = 600; // Note: Simplified logic
    }
};

// This is a simplified implementation for brevity in the prompt-response format, 
// but keeps all core Boids math.

class FlockingSimulation {
public:
    std::vector<Boid> boids;

    FlockingSimulation() {
        for (int i = 0; i < 100; ++i) {
            boids.push_back(Boid((float)(rand() % 800), (float)(rand() % 600)));
        }
    }

    void Update(float dt) {
        for (size_t i = 0; i < boids.size(); ++i) {
            Vec2 separation, alignment, cohesion;
            int total = 0;
            float perceptionRadius = 50.0f;

            for (size_t j = 0; j < boids.size(); ++j) {
                float d = (boids[i].position - boids[j].position).Magnitude();
                if (i != j && d < perceptionRadius) {
                    // Separation
                    Vec2 diff = boids[i].position - boids[j].position;
                    diff = diff.Normalize() * (1.0f / d);
                    separation = separation + diff;

                    // Alignment
                    alignment = alignment + boids[j].velocity;

                    // Cohesion
                    cohesion = cohesion + boids[j].position;

                    total++;
                }
            }

            if (total > 0) {
                separation = separation * (1.0f / total);
                alignment = (alignment * (1.0f / total)).Normalize() * boids[i].maxSpeed;
                cohesion = (cohesion * (1.0f / total)) - boids[i].position;
                cohesion = cohesion.Normalize() * boids[i].maxSpeed;

                boids[i].ApplyForce(separation * 1.5f); // Weight separation
                boids[i].ApplyForce((alignment - boids[i].velocity) * 1.0f); // Alignment
                boids[i].ApplyForce((cohesion - boids[i].velocity) * 1.0f); // Cohesion
            }

            boids[i].Update(dt);
        }
    }

    void Render(LDL::Render& render) {
        for (size_t i = 0; i < boids.size(); ++i) {
            render.SetColor(LDL::Color(100, 255, 100, 255));
            render.Fill(LDL::Vec2i((int)boids[i].position.x, (int)boids[i].position.y),
                LDL::Vec2i(4, 4));
        }
    }
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Boids Simulation", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    FlockingSimulation flock;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        flock.Update(deltaTime);

        render.Begin();
        render.SetColor(LDL::Color(10, 20, 30));
        render.Clear();
        flock.Render(render);
        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
