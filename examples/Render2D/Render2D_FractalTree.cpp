/*
 * -----------------------------------------------------------------------------
 * Fractal Tree (Procedural Art)
 * This example demonstrates recursion, trigonometry for transformations,
 * and time-based animation.
 * -----------------------------------------------------------------------------
 */

#include <time.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <LDL/C++98/LDL.hpp>

 // Константы для математики
#ifndef M_PI
#define M_PI 3.1415926     // В C++98 M_PI не всегда определен в cmath
#endif

// Структура настроек дерева, чтобы не передавать 20 аргументов в рекурсию
struct TreeConfig 
{
    int maxDepth;
    float initialLength;
    float branchAngle;    // Базовый угол ветвления
    float scaleFactor;    // На сколько уменьшается ветка (scale)
    float animationSpeed; // Скорость "раскачивания"
};

void DrawFractalTree(LDL::Render& render, float x1, float y1, float angle, float length, int depth, const TreeConfig& config, float time)
{
    if (depth <= 0) return;

    float x2 = x1 + cos(angle) * length;
    float y2 = y1 + sin(angle) * length;

    float colorIntensity = (float)depth / config.maxDepth;
    render.SetColor(LDL::Color((int)(255 * colorIntensity), (int)(150 * colorIntensity), (int)(50 * colorIntensity)));

    float thickness = (float)depth * 1.5f;
    render.Fill(LDL::Vec2i((int)x1, (int)y1), LDL::Vec2i((int)thickness, (int)thickness));
    render.Fill(LDL::Vec2i((int)x2, (int)y2), LDL::Vec2i(1, 1));

    float nextLength = length * config.scaleFactor;
    float dynamicAngleOffset = config.branchAngle + sin(time * config.animationSpeed) * 0.2f;
    DrawFractalTree(render, x2, y2, angle - dynamicAngleOffset, nextLength, depth - 1, config, time);
    DrawFractalTree(render, x2, y2, angle + dynamicAngleOffset, nextLength, depth - 1, config, time);
}

int main()
{
    float deltaTime   = 0.0f;
    float totalTime   = 0.0f;
    float timerAccum  = 0.0f;
    int frameCount    = 0;
    clock_t lastClock = clock();

    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Procedural Art: Fractal Tree", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    TreeConfig tree;
    tree.maxDepth       = 10;
    tree.initialLength  = 150.0f;
    tree.branchAngle    = 0.45f;
    tree.scaleFactor    = 0.75f;
    tree.animationSpeed = 2.0f;

    lastClock = clock();

    while (window.IsRunning() && result.IsOk())
    {
        clock_t currentClock = clock();
        float secondsPassed = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        deltaTime = secondsPassed;
        lastClock = currentClock;

        totalTime += deltaTime;

        timerAccum += deltaTime;
        frameCount++;
        if (timerAccum >= 1.0f) 
        {
            std::cout << "Running... Time: " << totalTime << std::endl;
            frameCount = 0;
            timerAccum = 0.0f;
        }

        while (window.GetEvent(event))
        {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
            {
                window.StopEvent();
            }
        }

        render.Begin();
        render.SetColor(LDL::Color(15, 15, 25));
        render.Clear();

        float startX = window.GetSize().x / 2.0f;
        float startY = window.GetSize().y - 50.0f;
        float startAngle = -M_PI / 2.0f;

        DrawFractalTree(render, startX, startY, startAngle, tree.initialLength, tree.maxDepth, tree, totalTime);

        render.End();
    }

    return result.IsOk() ? 0 : -1;
}
