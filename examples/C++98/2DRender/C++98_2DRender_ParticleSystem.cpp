/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <time.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <LDL/C++98/LDL.hpp>

int Random(int min, int max) 
{
    int range = max - min + 1;
    return min + rand() % range;
}

struct Particle 
{
    float x, y;
    float vx, vy;
    float life;
    float maxLife;
    LDL::Color color;

    Particle() : x(0), y(0), vx(0), vy(0), life(0), maxLife(0), color(255, 255, 255) {}
};

const int MAX_PARTICLES = 1000;

void Init(std::vector<Particle>& particles, size_t count)
{
    for (size_t i = 0; i < MAX_PARTICLES; ++i)
    {
        particles.push_back(Particle());
    }
}

void CreateExplosion(float centerX, float centerY, std::vector<Particle>& particles)
{
    for (size_t i = 0; i < particles.size(); ++i) 
    {
        Particle& p = particles[i];
        p.x = centerX;
        p.y = centerY;

        p.vx = (float)(Random(-800, 800));
        p.vy = (float)(Random(-600, 600));

        p.maxLife = 1.0f + (float)rand() / (float)(RAND_MAX / 2.0f);
        p.life    = p.maxLife;
        p.color   = LDL::Color(Random(150, 255), Random(100, 200), Random(50, 100));
    }
}

void Update(float deltaTime, std::vector<Particle>& particles)
{
    for (size_t i = 0; i < particles.size(); ++i) 
    {
        if (particles[i].life > 0)
        {
            particles[i].x += particles[i].vx * deltaTime;
            particles[i].y += particles[i].vy * deltaTime;

            particles[i].vy += 300.0f * deltaTime;

            particles[i].life -= deltaTime;
        }
    }
}

void Render(LDL::Render2D& render, std::vector<Particle>& particles)
{
    for (size_t i = 0; i < particles.size(); ++i) 
    {
        if (particles[i].life > 0) 
        {
            float lifeRatio = particles[i].life / particles[i].maxLife;
            int size = (int)(10.0f * lifeRatio);
            if (size < 1) size = 1;

            render.SetColor(particles[i].color);
            render.Fill(LDL::Vec2i((int)particles[i].x, (int)particles[i].y), LDL::Vec2i(size, size));
        }
    }
}

int main()
{
    float deltaTime   = 0.0f;
    float fps         = 0.0f;
    float timerAccum  = 0.0f;
    int frameCount    = 0;
    clock_t lastClock = 0;
    std::vector<Particle> particles;

    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Particle System - DeltaTime & FPS", LDL_WindowModeResized);
    LDL::Render2D render(result, context, window);

    Init(particles, MAX_PARTICLES);

    lastClock = clock();

    while (window.IsRunning() && result.IsOk()) 
    {
        clock_t currentClock = clock();
        float secondsPassed = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        deltaTime = secondsPassed;
        lastClock = currentClock;

        timerAccum += deltaTime;
        frameCount++;

        if (timerAccum >= 1.0f) 
        {
            fps = (float)frameCount / timerAccum;
            frameCount = 0;
            timerAccum = 0.0f;
            std::cout << "FPS: " << fps << " | dt: " << deltaTime << std::endl;
        }

        while (window.GetEvent(event)) 
        {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) 
            {
                window.StopEvent();
            }

            if (event.IsKeyPressed(LDL_KeySpace) || event.IsKeyPressed(LDL_KeyQ)) 
            {
                CreateExplosion(window.GetSize().x / 2.0f, window.GetSize().y / 2.0f, particles);
            }
        }

        Update(deltaTime, particles);

        render.Begin();
        render.SetColor(LDL::Color(10, 10, 15));
        render.Clear();

        Render(render, particles);

        render.End();
    }

    return result.IsOk() ? 0 : -1;
}
