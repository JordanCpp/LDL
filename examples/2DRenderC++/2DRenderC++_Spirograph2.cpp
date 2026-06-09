/*
* -----------------------------------------------------------------------------
* Example 2: Spirograph (Hypotrochoid)
* Demonstrates: Trigonometry, Line Strips, and Continuous Path Generation.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct Point {
    float x, y;
};

class Spirograph {
public:
    std::vector<Point> path;
    float R, r, d;
    float theta;
    float rotationSpeed;

    Spirograph() : R(150.0f), r(52.63f), d(70.0f), theta(0.0f), rotationSpeed(1.0f) {}

    void Update(float deltaTime) {
        // Increment angle based on time
        theta += rotationSpeed * deltaTime;

        // Calculate new point using Hypotrochoid formula:
        // x = (R-r)cos(theta) + d*cos(((R-r)/r)*theta)
        // y = (R-r)sin(theta) - d*sin(((R-r)/r)*theta)
        float x = (R - r) * cosf(theta) + d * cosf(((R - r) / r) * theta);
        float y = (R - r) * sinf(theta) - d * sinf(((R - r) / r) * theta);

        // Add to path. We keep a fixed number of points for performance/looping
        Point newPt;
        newPt.x = x + 400.0f; // Center offset
        newPt.y = y + 300.0f;
        path.push_back(newPt);

        if (path.size() > 2000) {
            path.erase(path.begin());
        }
    }

    void Render(LDL::Render2D& render) {
        if (path.size() < 2) return;

        render.SetColor(LDL::Color(0, 255, 200, 255)); // Cyan neon line
        for (size_t i = 1; i < path.size(); ++i) {
            render.Line(
                LDL::Vec2i((int)path[i - 1].x, (int)path[i - 1].y),
                LDL::Vec2i((int)path[i].x, (int)path[i].y)
            );
        }
    }
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Spirograph - Trig Demo", LDL_WindowModeResized);
    LDL::Render2D render(result, context, window);

    Spirograph spiro;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed( LDL_KeyEscape)) window.StopEvent();
        }

        spiro.Update(deltaTime);

        render.Begin();
        render.SetColor(LDL::Color(0, 0, 0));
        render.Clear();

        spiro.Render(render);

        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
