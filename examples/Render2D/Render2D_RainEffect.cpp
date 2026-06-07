/*
* -----------------------------------------------------------------------------
* Example 6: Rain Effect
* Demonstrates: Simple particle motion, boundary resets, and line rendering.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct RainDrop {
    float x, y;
    float speed;
    float length;

    RainDrop() : x(0), y(0), speed(0), length(0) { Reset(); }

    void Reset() {
        x = (float)(rand() % 800);
        y = -(float)(rand() % 600); // Start above screen
        speed = (float)(rand() % 400 + 500);
        length = (float)(rand() % 20 + 10);
    }

    void Update(float dt) {
        y += speed * dt;
        if (y > 600) Reset(); // Re-spawn when off screen
    }
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Rain Effect", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    std::vector<RainDrop> rain;
    for (int i = 0; i < 300; ++i) rain.push_back(RainDrop());

    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        render.Begin();
        render.SetColor(LDL::Color(5, 10, 20)); // Dark stormy sky
        render.Clear();

        render.SetColor(LDL::Color(150, 150, 255, 180)); // Semi-transparent blueish rain
        for (size_t i = 0; i < rain.size(); ++i) {
            rain[i].Update(deltaTime);
            render.Line(
                LDL::Vec2i((int)rain[i].x, (int)rain[i].y),
                LDL::Vec2i((int)rain[i].x, (int)(rain[i].y + rain[i].length))
            );
        }

        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
