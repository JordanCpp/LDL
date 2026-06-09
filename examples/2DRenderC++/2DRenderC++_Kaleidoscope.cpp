/*
* -----------------------------------------------------------------------------
* Example 7: Kaleidoscope Effect
* Demonstrates: Rotation, Symmetry, and Geometric Transformations.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct PatternElement {
    float offsetX, offsetY;
    float size;
    LDL::Color color;
};

class Kaleidoscope {
public:
    std::vector<PatternElement> elements;
    int symmetrySlices;
    float rotationAngle;

    Kaleidoscope() : symmetrySlices(8), rotationAngle(0.0f) {
        for (int i = 0; i < 15; ++i) {
            PatternElement e;
            e.offsetX = (float)(rand() % 200);
            e.offsetY = (int)(rand() % 200);
            e.size = (float)(rand() % 30 + 5);
            e.color = LDL::Color(rand() % 256, rand() % 256, 255, 255);
            elements.push_back(e);
        }
    }

    void Update(float deltaTime) {
        rotationAngle += 0.5f * deltaTime; // Slow rotation
    }

    void Render(LDL::Render2D& render, int centerX, int centerY) {
        for (size_t i = 0; i < elements.size(); ++i) {
            for (int s = 0; s < symmetrySlices; ++s) {
                float sliceAngle = (2.0f * 3.14159f / symmetrySlices) * s + rotationAngle;

                // Rotate the element's position around center
                float cosA = cosf(sliceAngle);
                float sinA = sinf(sliceAngle);

                float rx = elements[i].offsetX * cosA - elements[i].offsetY * sinA;
                float ry = elements[i].offsetX * sinA + elements[i].offsetY * cosA;

                int drawX = centerX + (int)rx;
                int drawY = centerY + (int)ry;

                render.SetColor(elements[i].color);
                render.Fill(LDL::Vec2i(drawX, drawY), LDL::Vec2i((int)elements[i].size, (int)elements[i].size));
            }
        }
    }
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Kaleidoscope Demo", LDL_WindowModeResized);
    LDL::Render2D render(result, context, window);

    Kaleidoscope k;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {

            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        k.Update(deltaTime);

        render.Begin();
        render.SetColor(LDL::Color(0, 0, 0));
        render.Clear();

        k.Render(render, 400, 300);

        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
