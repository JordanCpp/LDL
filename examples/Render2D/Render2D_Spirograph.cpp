/*
 * -----------------------------------------------------------------------------
 * Spirograph (Hypotrochoid)
 * This example demonstrates parametric equations, trigonometric oscillation,
 * and a continuous buffer of points to create complex patterns.
 * -----------------------------------------------------------------------------
 */

#include <time.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <LDL/C++98/LDL.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Spirograph {
    float R; // Радиус неподвижного круга
    float r; // Радиус катящегося круга
    float d; // Расстояние от центра малого круга до точки рисования
    float theta; // Текущий угол (прогресс рисунка)

    Spirograph() : R(150.0f), r(52.0f), d(80.0f), theta(0.0f) {}

    // Параметрическое уравнение гипотрохоида
    void CalculatePoint(float& x, float& y) {
        x = (R - r) * cos(theta) + d * cos((float)(R - r) / r * theta);
        y = (R - r) * sin(theta) - d * sin((float)(R - r) / r * theta);
    }
};

struct PathPoint 
{
    float x, y;
    LDL::Color color;
};

const size_t MAX_POINTS = 2000;
std::vector<PathPoint> path;

void UpdateSpirograph(float deltaTime, Spirograph& spiro, float totalTime) 
{
    float step = 0.1f;
    spiro.theta += step;

    spiro.r = 50.0f + 40.0f * sin(totalTime * 0.5f);
    spiro.d = 70.0f + 30.0f * cos(totalTime * 0.7f);

    // Вычисляем новую точку
    float newX, newY;
    spiro.CalculatePoint(newX, newY);

    float hue = fmod(totalTime, 6.28f);
    LDL::Color newColor((int)(127.0f + 127.0f * sin(hue)), (int)(127.0f + 127.0f * sin(hue + 2.0f)), (int)(127.0f + 127.0f * sin(hue + 4.0f)));

    PathPoint p;
    p.x = newX;
    p.y = newY;
    p.color = newColor;
    path.push_back(p);

    if (path.size() > MAX_POINTS) 
    {
        path.erase(path.begin());
    }
}

void RenderSpirograph(LDL::Render& render, const std::vector<PathPoint>& points, float screenCenterX, float screenCenterY) 
{
    for (size_t i = 0; i < points.size(); ++i) 
    {
        render.SetColor(points[i].color);

        int size = 2;
        render.Fill(LDL::Vec2i((int)(screenCenterX + points[i].x), (int)(screenCenterY + points[i].y)), LDL::Vec2i(size, size));
    }

    if (!points.empty())
    {
        render.SetColor(LDL::Color(255, 255, 255));
        render.Fill(LDL::Vec2i((int)(screenCenterX + points.back().x), (int)(screenCenterY + points.back().y)), LDL::Vec2i(4, 4));
    }
}

int main() {
    float deltaTime = 0.0f;
    float totalTime = 0.0f;
    float timerAccum = 0.0f;
    int frameCount = 0;
    clock_t lastClock = clock();

    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Spirograph - Mathematical Beauty", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    Spirograph spiro;

    lastClock = clock();

    while (window.IsRunning() && result.IsOk())
    {
        clock_t currentClock = clock();
        float secondsPassed = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        deltaTime = secondsPassed;
        lastClock = currentClock;

        totalTime += deltaTime;

        // FPS calculation
        timerAccum += deltaTime;
        frameCount++;
        if (timerAccum >= 1.0f) {
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

        // Update logic
        UpdateSpirograph(deltaTime, spiro, totalTime);

        // Rendering
        render.Begin();
        render.SetColor(LDL::Color(5, 5, 10)); // Глубокий темный фон
        render.Clear();

        float centerX = window.GetSize().x / 2.0f;
        float centerY = window.GetSize().y / 2.0f; // Ошибка в тексте, просто centerY
        // Исправлено:
        float cX = (float)window.GetSize().x / 2.0f;
        float cY = (float)window.GetSize().y / 2.0f;

        RenderSpirograph(render, path, cX, cY);

        render.End();
    }

    return result.IsOk() ? 0 : -1;
}
