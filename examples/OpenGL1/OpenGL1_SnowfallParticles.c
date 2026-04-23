/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
License for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define PARTICLE_COUNT 500

typedef struct
{
    float x;
    float y;
    float z;
    float speed;
    float size;
    float alpha;
} Particle;

static Particle particles[PARTICLE_COUNT];
static float wind = 0.0f;
static size_t lastTime = 0;

void Perspective(double fovY, double aspect, double zNear, double zFar)
{
    double fH, fW;

    fH = tan(fovY / 360.0 * M_PI) * zNear;
    fW = fH * aspect;

    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}

void Resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)width / (float)height;
    Perspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void InitParticles(void)
{
    int i;

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        particles[i].x = (float)(rand() % 200 - 100) / 10.0f;  /* -10 to 10 */
        particles[i].y = (float)(rand() % 150) / 10.0f;        /* 0 to 15 */
        particles[i].z = (float)(rand() % 100 - 50) / 10.0f;   /* -5 to 5 */
        particles[i].speed = 0.5f + (float)(rand() % 30) / 10.0f;
        particles[i].size = 0.05f + (float)(rand() % 20) / 100.0f;
        particles[i].alpha = 0.3f + (float)(rand() % 70) / 100.0f;
    }
}

void UpdateParticles(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;

    /* Random wind changes */
    wind += (float)(rand() % 100 - 50) / 1000.0f;
    if (wind > 1.0f) wind = 1.0f;
    if (wind < -1.0f) wind = -1.0f;

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        /* Fall down */
        particles[i].y -= particles[i].speed * seconds;

        /* Wind effect */
        particles[i].x += wind * seconds * 1.5f;

        /* Reset if below bottom */
        if (particles[i].y < -2.0f)
        {
            particles[i].x = (float)(rand() % 200 - 100) / 10.0f;
            particles[i].y = 12.0f;
            particles[i].z = (float)(rand() % 100 - 50) / 10.0f;
            particles[i].speed = 0.5f + (float)(rand() % 30) / 10.0f;
        }

        /* Bounce off invisible walls */
        if (particles[i].x > 12.0f) particles[i].x = -12.0f;
        if (particles[i].x < -12.0f) particles[i].x = 12.0f;
    }
}

void DrawParticles(void)
{
    int i;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_POINT_SMOOTH);

    glPointSize(3.0f);

    glBegin(GL_POINTS);

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        /* White with varying alpha */
        float brightness = 0.7f + particles[i].alpha * 0.3f;
        glColor4f(brightness, brightness, brightness, particles[i].alpha);
        glVertex3f(particles[i].x, particles[i].y, particles[i].z);
    }

    glEnd();

    glDisable(GL_POINT_SMOOTH);
    glDisable(GL_BLEND);
}

void DrawGround(void)
{
    /* Simple ground plane */
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.3f);
    glVertex3f(-12.0f, -2.0f, -5.0f);
    glVertex3f(12.0f, -2.0f, -5.0f);
    glVertex3f(12.0f, -2.0f, 5.0f);
    glVertex3f(-12.0f, -2.0f, 5.0f);
    glEnd();

    /* Grid on ground */
    glColor3f(0.3f, 0.3f, 0.4f);
    glBegin(GL_LINES);
    for (int i = -10; i <= 10; i++)
    {
        glVertex3f((float)i, -1.9f, -4.0f);
        glVertex3f((float)i, -1.9f, 4.0f);
        glVertex3f(-10.0f, -1.9f, (float)i);
        glVertex3f(10.0f, -1.9f, (float)i);
    }
    glEnd();
}

void Display(void)
{
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    /* Camera position */
    glTranslatef(0.0f, 3.0f, -15.0f);
    glRotatef(15.0f, 1.0f, 0.0f, 0.0f);

    DrawGround();
    DrawParticles();
}

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_Event         event;
    LDL_OpenGLLoader* loader;
    size_t            currentTime;
    size_t            delta;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600),
        "LDL - Snowfall Particles (OpenGL 1.2)", 0);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);

        InitParticles();
        lastTime = LDL_Ticks();
        Resize(800, 600);

        while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
        {
            while (LDL_WindowGetEvent(window, &event))
            {
                if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                {
                    LDL_WindowStopEvent(window);
                }

                if (event.Type == LDL_EventIsResize)
                {
                    Resize((int)event.Resize.Width, (int)event.Resize.Height);
                }
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0 && delta < 100)
            {
                UpdateParticles(delta);
            }

            Display();
            LDL_WindowPresent(window);

            LDL_Delay(16);
        }

        LDL_OpenGLLoaderFree(loader);
    }

    LDL_ContextFree(context);
    LDL_WindowFree(window);
    LDL_ResultFree(result);

    if (LDL_ResultIsFail(result))
    {
        printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
    }

    return 0;
}