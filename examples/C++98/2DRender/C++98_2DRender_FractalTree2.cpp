/*
* -----------------------------------------------------------------------------
* Example 1: Fractal Tree (Recursive L-System)
* Demonstrates: Recursion, Rotation, Scaling, and Trigonometry.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <LDL/C++98/LDL.hpp>

#define PI 3.14159265358979323846f

struct TreeConfig {
    float branchAngle;
    float reductionFactor;
    int maxDepth;
    float currentGrowth; // For animation
};

void DrawBranch(LDL::Render2D& render, float x, float y, float angle, float length, int depth, const TreeConfig& config) {
    if (depth <= 0) return;

    // Calculate end point of the branch
    float endX = x + cosf(angle) * length;
    float endY = y + sinf(angle) * length;

    // Color changes based on depth (brown to green)
    float lerp = (float)depth / config.maxDepth;
    LDL::Color branchColor(100, 50, 20, 255); // Brownish
    if (depth < 3) {
        branchColor = LDL::Color(34, 139, 34, 255); // Forest Green for leaves
    }

    render.SetColor(branchColor);
    render.Line(LDL::Vec2i((int)x, (int)y), LDL::Vec2i((int)endX, (int)endY));

    // Recursive calls for sub-branches
    float nextLength = length * config.reductionFactor;

    // Apply animation: oscillate angle slightly over time
    float animatedAngle = config.branchAngle;

    DrawBranch(render, endX, endY, angle - animatedAngle, nextLength, depth - 1, config);
    DrawBranch(render, endX, endY, angle + animatedAngle, nextLength, depth - 1, config);
}

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Fractal Tree - Recursion", LDL_WindowModeResized);
    LDL::Render2D render(result, context, window);

    TreeConfig config;
    config.maxDepth = 10;
    config.reductionFactor = 0.75f;
    config.branchAngle = 0.4f; // Radians
    config.currentGrowth = 0.0f;

    float deltaTime = 0.0f;
    float timerAccum = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        timerAccum += deltaTime;
        if (timerAccum >= 1.0f) { timerAccum = 0.0f; }

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) {
                window.StopEvent();
            }
        }

        // Animation: Oscillate the angle of branches using sine wave
        config.branchAngle = 0.3f + 0.2f * sinf(timerAccum * 2.0f);

        render.Begin();
        render.SetColor(LDL::Color(20, 20, 25)); // Dark background
        render.Clear();

        // Draw the tree starting from bottom center
        DrawBranch(render, 400.0f, 550.0f, -PI / 2.0f, 150.0f, config.maxDepth, config);

        render.End();
    }

    return result.IsOk() ? 0 : -1;
}
