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
#include <math.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct
{
    float distance;
    float radius;
    float speed;
    float r, g, b;
    float angle;
} Planet;

static Planet planets[] = {
    {1.5f, 0.12f, 120.0f, 0.8f, 0.6f, 0.4f, 0.0f},  /* Mercury */
    {2.2f, 0.15f, 90.0f,  0.9f, 0.7f, 0.3f, 0.0f},  /* Venus */
    {3.0f, 0.18f, 70.0f,  0.2f, 0.5f, 0.9f, 0.0f},  /* Earth */
    {3.8f, 0.16f, 60.0f,  0.9f, 0.3f, 0.2f, 0.0f},  /* Mars */
    {5.0f, 0.35f, 35.0f,  0.7f, 0.6f, 0.4f, 0.0f},  /* Jupiter */
    {6.2f, 0.30f, 28.0f,  0.8f, 0.7f, 0.5f, 0.0f},  /* Saturn */
    {7.2f, 0.25f, 22.0f,  0.5f, 0.7f, 0.9f, 0.0f},  /* Uranus */
    {8.2f, 0.24f, 18.0f,  0.3f, 0.4f, 0.8f, 0.0f}    /* Neptune */
};

#define PLANET_COUNT 8

static float cameraAngleX = 30.0f;
static float cameraAngleY = 0.0f;
static float cameraDistance = 15.0f;
static int cameraRotate = 1;
static size_t lastTime = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;

void Perspective(double fovY, double aspect, double zNear, double zFar)
{
    double fH, fW;

    fH = tan(fovY / 360.0 * M_PI) * zNear;
    fW = fH * aspect;

    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}

void Resize(int width, int height)
{
    float aspect = (float)width / (float)height;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    Perspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawSphere(float radius, float r, float g, float b)
{
    int i, j;
    int stacks = 20;
    int slices = 20;
    float phi, theta;
    float x, y, z;

    for (i = 0; i <= stacks; i++)
    {
        phi = (float)i / (float)stacks * M_PI;

        glBegin(GL_TRIANGLE_STRIP);

        for (j = 0; j <= slices; j++)
        {
            theta = (float)j / (float)slices * 2.0f * M_PI;

            /* First vertex */
            x = radius * sin(phi) * cos(theta);
            y = radius * cos(phi);
            z = radius * sin(phi) * sin(theta);

            glColor3f(r, g, b);
            glVertex3f(x, y, z);

            /* Second vertex */
            phi = (float)(i + 1) / (float)stacks * M_PI;
            x = radius * sin(phi) * cos(theta);
            y = radius * cos(phi);
            z = radius * sin(phi) * sin(theta);

            glColor3f(r * 0.9f, g * 0.9f, b * 0.9f);
            glVertex3f(x, y, z);

            phi = (float)i / (float)stacks * M_PI;
        }

        glEnd();
    }
}

void DrawSun(void)
{
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    DrawSphere(0.8f, 1.0f, 0.8f, 0.2f);
    glPopMatrix();

    /* Sun glow effect */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    DrawSphere(0.85f, 1.0f, 0.6f, 0.0f);
    glPopMatrix();

    glDisable(GL_BLEND);
}

void DrawOrbit(float radius)
{
    int i;
    float angle;
    float x;
    float z;

    glColor3f(0.3f, 0.3f, 0.4f);
    glBegin(GL_LINE_LOOP);

    for (i = 0; i <= 360; i += 10)
    {
        angle = i * M_PI / 180.0f;
        x     = radius * cos(angle);
        z     = radius * sin(angle);

        glVertex3f(x, 0.0f, z);
    }

    glEnd();
}

void DrawPlanet(Planet* p)
{
    int i;
    float angle;
    float x;
    float z;

    glPushMatrix();
    glRotatef(p->angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(p->distance, 0.0f, 0.0f);
    glRotatef(-p->angle, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    DrawSphere(p->radius, p->r, p->g, p->b);
    glPopMatrix();

    /* Saturn's ring */
    if (p->radius > 0.28f && p->radius < 0.32f)
    {
        glBegin(GL_LINE_LOOP);
        glColor3f(0.8f, 0.7f, 0.5f);

        for (i = 0; i <= 360; i += 20)
        {
            angle = i * M_PI / 180.0f;
            x = (p->radius + 0.12f) * cos(angle);
            z = (p->radius + 0.12f) * sin(angle);

            glVertex3f(x, 0.05f, z);
        }

        glEnd();
    }

    glPopMatrix();
}

void UpdatePlanets(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;

    for (i = 0; i < PLANET_COUNT; i++)
    {
        planets[i].angle += planets[i].speed * seconds;
        if (planets[i].angle >= 360.0f)
            planets[i].angle -= 360.0f;
    }

    if (cameraRotate)
    {
        cameraAngleY += 20.0f * seconds;
        if (cameraAngleY >= 360.0f)
            cameraAngleY -= 360.0f;
    }
}

void DrawStars(void)
{
    int i;
    float x;
    float y;
    float brightness;

    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);

    for (i = 0; i < 500; i++)
    {
        /* Use deterministic positions so stars don't move */
        x = (float)((i * 131071) % 10000) / 10000.0f;
        y = (float)((i * 524287) % 10000) / 10000.0f;
        brightness = 0.5f + ((i * 2999) % 100) / 100.0f;

        glColor3f(brightness, brightness, brightness);
        glVertex2f(x, y);
    }

    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
}

void DrawInfo(void)
{
    int width = 800;
    int height = 600;
    int fpsBar = (int)(fps * 2.0f);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width, (double)height, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    /* FPS bar */
    if (fpsBar > 190) fpsBar = 190;

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(200.0f, 0.0f);
    glVertex2f(200.0f, 50.0f);
    glVertex2f(0.0f, 50.0f);

    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 10.0f);
    glVertex2f((float)(5 + fpsBar), 10.0f);
    glVertex2f((float)(5 + fpsBar), 20.0f);
    glVertex2f(5.0f, 20.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(5.0f, 30.0f);
    glVertex2f(195.0f, 30.0f);
    glVertex2f(195.0f, 31.0f);
    glVertex2f(5.0f, 31.0f);
    glEnd();

    /* Camera rotation indicator */
    if (cameraRotate)
    {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f((float)width - 20.0f, 10.0f);
        glVertex2f((float)width - 5.0f, 10.0f);
        glVertex2f((float)width - 5.0f, 25.0f);
        glVertex2f((float)width - 20.0f, 25.0f);
        glEnd();
    }

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void UpdateFPS(void)
{
    size_t currentTime = LDL_Ticks();
    size_t delta = currentTime - lastFpsTime;

    frameCount++;

    if (delta >= 1000)
    {
        fps = (float)frameCount * 1000.0f / (float)delta;
        frameCount = 0;
        lastFpsTime = currentTime;
    }
}

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_Event         event;
    LDL_OpenGLLoader* loader;
    int               width = 800;
    int               height = 600;
    size_t            currentTime;
    size_t            delta;
    int               i;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Solar System (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        lastTime = LDL_Ticks();
        lastFpsTime = lastTime;
        Resize(width, height);

        while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
        {
            while (LDL_WindowGetEvent(window, &event))
            {
                if (event.u.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                {
                    LDL_WindowStopEvent(window);
                }

                if (LDL_EventIsKeyPressed(&event, LDL_KeySpace))
                {
                    cameraRotate = !cameraRotate;
                }

                if (event.u.Type == LDL_EventIsMouseScroll)
                {
                    cameraDistance -= (float)event.u.Mouse.Delta / 100.0f;
                    if (cameraDistance < 5.0f) cameraDistance = 5.0f;
                    if (cameraDistance > 25.0f) cameraDistance = 25.0f;
                }

                if (event.u.Type == LDL_EventIsResize)
                {
                    width = (int)event.u.Resize.Width;
                    height = (int)event.u.Resize.Height;
                    Resize(width, height);
                }
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0 && delta < 100)
            {
                UpdatePlanets(delta);
            }

            UpdateFPS();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Camera */
            glTranslatef(0.0f, -2.0f, -cameraDistance);
            glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
            glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

            DrawStars();

            /* Orbits */
            for (i = 0; i < PLANET_COUNT; i++)
            {
                DrawOrbit(planets[i].distance);
            }

            DrawSun();

            /* Planets */
            for (i = 0; i < PLANET_COUNT; i++)
            {
                DrawPlanet(&planets[i]);
            }

            DrawInfo();

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