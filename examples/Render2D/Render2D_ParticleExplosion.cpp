/*
* -----------------------------------------------------------------------------
* Example 4: Firework (Particle Explosion)
* Demonstrates: Particle Systems, Gravity, Alpha Blending, and Randomness.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct Particle {
    float x, y;
    float vx, vy;
    float life;
    float maxLife;
    LDL::Color color;

    Particle() : x(0), y(0), vx(0), vy(0), life(0), maxLife(0), color(255, 255, 255, 255) {}
};

class FireworkSystem {
public:
    std::vector<Particle> particles;

    void Explode(float x, float y) {
        int count = 100 + (rand() % 100); // 100-200 particles per explosion
        for (int i = 0; i < count; ++i) {
            Particle p;
            p.x = x;
            p.y = y;
            // Random direction and speed
            float angle = (float)(rand() % 360) * 3.14159f / 180.0f;
            float speed = (float)(rand() % 200 + 50);
            p.vx = cosf(angle) * speed;
            p.vy = sinf(angle) * speed;

            p.maxLife = 1.0f + (float)(rand() % 200) / 100.0f;
            p.life = p.maxLife;

            // Random bright color
            p.color = LDL::Color(rand() % 256, rand() % 256, rand() % 256, 255);
            particles.push_back(p);
        }
    }

    void Update(float deltaTime) {
        for (size_t i = 0; i < particles.size(); ) {
            if (particles[i].life > 0) {
                // Physics: Velocity + Gravity
                particles[i].vy += 350.0f * deltaTime; // Gravity force
                particles[i].x += particles[i].vx * deltaTime;
                particles[i].y += particles[i].vy * deltaTime;

                // Life decay
                particles[i].life -= deltaTime;

                // Fade alpha based on life
                float alphaPercent = particles[i].life / particles[i].maxLife;
                particles[i].color.a = (unsigned char)(255 * alphaPercent);

                ++i;
            }
            else {
                // Remove dead particle
                particles.erase(particles.begin() + i);
            }
        }
    }

    void Render(LDL::Render& render) {
        for (size_t i = 0; i < particles.size(); ++i) {
            float size = 2.0f + (5.0f * (particles[i].life / particles[i].maxLife));
            render.SetColor(particles[i].color);
            render.Fill(LDL::Vec2i((int)particles[i].x, (int)particles[i].y),
                LDL::Vec2i((int)size, (int)size));
        }
    }
};

int main() {
    srand((unsigned int)time(NULL));
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Firework Demo", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    FireworkSystem fw;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();

            // Explosion on Mouse Click or Space
            if (event.Type == LDL_EventIsMouseClick || event.IsKeyPressed(LDL_KeySpace)) 
            {
                fw.Explode((float)event.u.Mouse.PosX, (float)event.u.Mouse.PosY); // Center explosion
            }
        }

        fw.Update(deltaTime);

        render.Begin();
        render.SetColor(LDL::Color(0, 0, 0));
        render.Clear();
        fw.Render(render);
        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
