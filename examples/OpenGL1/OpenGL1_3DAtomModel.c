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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define ELECTRON_COUNT 6
#define PROTON_COUNT 8
#define NEUTRON_COUNT 8

typedef struct
{
    float angleX;
    float angleY;
    float angleZ;
    float speedX;
    float speedY;
    float speedZ;
    float radius;
    float r, g, b;
} Electron;

static Electron electrons[ELECTRON_COUNT];
static float protonAngles[PROTON_COUNT];
static float neutronAngles[NEUTRON_COUNT];
static float nucleusAngle = 0.0f;
static float cameraAngleX = 25.0f;
static float cameraAngleY = 30.0f;
static float cameraDistance = 8.0f;
static size_t lastTime = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;

void Perspective(double fovY, double aspect, double zNear, double zFar)
{
    double fH, fW;

    fH = (float)tan(fovY / 360.0 * M_PI) * zNear;
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

void InitElectrons(void)
{
    int i;

    for (i = 0; i < ELECTRON_COUNT; i++)
    {
        electrons[i].angleX = (float)(rand() % 360);
        electrons[i].angleY = (float)(rand() % 360);
        electrons[i].angleZ = (float)(rand() % 360);
        electrons[i].speedX = 30.0f + (float)(rand() % 60);
        electrons[i].speedY = 40.0f + (float)(rand() % 50);
        electrons[i].speedZ = 35.0f + (float)(rand() % 55);
        electrons[i].radius = 1.5f + (float)(rand() % 100) / 100.0f;
        electrons[i].r = 0.3f + (float)(rand() % 70) / 100.0f;
        electrons[i].g = 0.3f + (float)(rand() % 70) / 100.0f;
        electrons[i].b = 0.8f + (float)(rand() % 20) / 100.0f;
    }
}

void InitParticles(void)
{
    int i;

    for (i = 0; i < PROTON_COUNT; i++)
    {
        protonAngles[i] = (float)(rand() % 360);
    }

    for (i = 0; i < NEUTRON_COUNT; i++)
    {
        neutronAngles[i] = (float)(rand() % 360);
    }
}

void DrawSphere(float radius, float r, float g, float b, int stacks, int slices)
{
    int i, j;
    float phi, theta;
    float x, y, z;

    for (i = 0; i <= stacks; i++)
    {
        phi = (float)i / (float)stacks * (float)M_PI;

        glBegin(GL_TRIANGLE_STRIP);

        for (j = 0; j <= slices; j++)
        {
            theta = (float)j / (float)slices * 2.0f * (float)M_PI;

            x = radius * (float)sin(phi) * (float)cos(theta);
            y = radius * (float)cos(phi);
            z = radius * (float)sin(phi) * (float)sin(theta);

            glColor3f(r, g, b);
            glVertex3f(x, y, z);

            phi = (float)(i + 1) / (float)stacks * (float)M_PI;
            x = radius * (float)sin(phi) * (float)cos(theta);
            y = radius * (float)cos(phi);
            z = radius * (float)sin(phi) * (float)sin(theta);

            glColor3f(r * 0.8f, g * 0.8f, b * 0.8f);
            glVertex3f(x, y, z);

            phi = (float)i / (float)stacks * (float)M_PI;
        }

        glEnd();
    }
}

void DrawNucleus(void)
{
    int i;
    float angle;
    float x, y, z;
    float radius = 0.6f;

    /* Core */
    DrawSphere(0.45f, 1.0f, 0.2f, 0.2f, 16, 16);

    /* Protons (red) */
    for (i = 0; i < PROTON_COUNT; i++)
    {
        angle = protonAngles[i] * (float)M_PI / 180.0f;
        x = radius * (float)cos(angle) * (float)sin(angle * 2.0f);
        y = radius * (float)sin(angle) * (float)sin(angle * 1.5f);
        z = radius * (float)cos(angle * 1.7f);

        glPushMatrix();
        glTranslatef(x, y, z);
        DrawSphere(0.18f, 1.0f, 0.3f, 0.3f, 10, 10);
        glPopMatrix();
    }

    /* Neutrons (blue) */
    for (i = 0; i < NEUTRON_COUNT; i++)
    {
        angle = neutronAngles[i] * (float)M_PI / 180.0f;
        x = radius * (float)cos(angle + 2.0f) * (float)cos(angle);
        y = radius * (float)sin(angle * 1.3f);
        z = radius * (float)sin(angle + 1.0f) * (float)cos(angle * 0.8f);

        glPushMatrix();
        glTranslatef(x, y, z);
        DrawSphere(0.16f, 0.3f, 0.3f, 1.0f, 10, 10);
        glPopMatrix();
    }
}

void DrawElectronTrajectory(float radius)
{
    int i;
    float angle;
    float x;
    float y;
    float z;

    glColor3f(0.3f, 0.3f, 0.5f);

    glBegin(GL_LINE_LOOP);

    for (i = 0; i <= 360; i += 15)
    {
        angle = (float)i * (float)M_PI / 180.0f;
        x = radius * (float)cos(angle);
        z = radius * (float)sin(angle);

        glVertex3f(x, 0.0f, z);
    }

    glEnd();

    /* Second orbit at angle */
    glBegin(GL_LINE_LOOP);

    for (i = 0; i <= 360; i += 15)
    {
        angle = (float)i * (float)M_PI / 180.0f;
        x = radius * (float)cos(angle);
        y = radius * (float)sin(angle);

        glVertex3f(x, y, 0.0f);
    }

    glEnd();

    /* Third orbit */
    glBegin(GL_LINE_LOOP);

    for (i = 0; i <= 360; i += 15)
    {
        angle = i * (float)M_PI / 180.0f;
        y = radius * (float)cos(angle);
        z = radius * (float)sin(angle);

        glVertex3f(0.0f, y, z);
    }

    glEnd();
}

void DrawElectrons(void)
{
    int i;
    float x, y, z;

    for (i = 0; i < ELECTRON_COUNT; i++)
    {
        Electron* e = &electrons[i];

        /* Position in 3D using spherical coordinates */
        x = e->radius * (float)sin(e->angleX * M_PI / 180.0f) * (float)cos(e->angleY * M_PI / 180.0f);
        y = e->radius * (float)sin(e->angleX * M_PI / 180.0f) * (float)sin(e->angleY * M_PI / 180.0f);
        z = e->radius * (float)cos(e->angleX * M_PI / 180.0f);

        /* Add second harmonic */
        x += e->radius * 0.3f * (float)sin(e->angleZ * M_PI / 180.0f);
        z += e->radius * 0.3f * (float)cos(e->angleZ * M_PI / 180.0f);

        glPushMatrix();
        glTranslatef(x, y, z);

        /* Electron glow */
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        DrawSphere(0.12f, e->r, e->g, e->b, 8, 8);
        glDisable(GL_BLEND);

        /* Core */
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        DrawSphere(0.08f, e->r * 0.7f, e->g * 0.7f, e->b * 0.7f, 8, 8);

        glPopMatrix();
    }
}

void UpdateElectrons(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;

    for (i = 0; i < ELECTRON_COUNT; i++)
    {
        electrons[i].angleX += electrons[i].speedX * seconds;
        electrons[i].angleY += electrons[i].speedY * seconds;
        electrons[i].angleZ += electrons[i].speedZ * seconds;

        if (electrons[i].angleX >= 360.0f) electrons[i].angleX -= 360.0f;
        if (electrons[i].angleY >= 360.0f) electrons[i].angleY -= 360.0f;
        if (electrons[i].angleZ >= 360.0f) electrons[i].angleZ -= 360.0f;
    }

    /* Nucleus particles rotation */
    nucleusAngle += 45.0f * seconds;
    if (nucleusAngle >= 360.0f) nucleusAngle -= 360.0f;

    for (i = 0; i < PROTON_COUNT; i++)
    {
        protonAngles[i] += 30.0f * seconds;
        if (protonAngles[i] >= 360.0f) protonAngles[i] -= 360.0f;
    }

    for (i = 0; i < NEUTRON_COUNT; i++)
    {
        neutronAngles[i] += 25.0f * seconds;
        if (neutronAngles[i] >= 360.0f) neutronAngles[i] -= 360.0f;
    }
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

    /* Panel */
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(220.0f, 0.0f);
    glVertex2f(220.0f, 65.0f);
    glVertex2f(0.0f, 65.0f);
    glEnd();

    /* FPS bar */
    if (fpsBar > 210) fpsBar = 210;

    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 10.0f);
    glVertex2f((float)(5 + fpsBar), 10.0f);
    glVertex2f((float)(5 + fpsBar), 20.0f);
    glVertex2f(5.0f, 20.0f);

    /* Protons count */
    glColor3f(1.0f, 0.3f, 0.3f);
    glVertex2f(5.0f, 30.0f);
    glVertex2f(70.0f, 30.0f);
    glVertex2f(70.0f, 40.0f);
    glVertex2f(5.0f, 40.0f);

    /* Neutrons count */
    glColor3f(0.3f, 0.3f, 1.0f);
    glVertex2f(75.0f, 30.0f);
    glVertex2f(140.0f, 30.0f);
    glVertex2f(140.0f, 40.0f);
    glVertex2f(75.0f, 40.0f);

    /* Electrons count */
    glColor3f(0.3f, 0.8f, 1.0f);
    glVertex2f(145.0f, 30.0f);
    glVertex2f(210.0f, 30.0f);
    glVertex2f(210.0f, 40.0f);
    glVertex2f(145.0f, 40.0f);

    /* Mouse hint */
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(5.0f, 50.0f);
    glVertex2f(210.0f, 50.0f);
    glVertex2f(210.0f, 60.0f);
    glVertex2f(5.0f, 60.0f);
    glEnd();

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

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - 3D Atom Model (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        InitElectrons();
        InitParticles();

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
                UpdateElectrons(delta);
            }

            UpdateFPS();

            glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Camera */
            glTranslatef(0.0f, 0.0f, -cameraDistance);
            glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
            glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

            /* Draw orbits */
            DrawElectronTrajectory(1.5f);
            DrawElectronTrajectory(2.2f);

            DrawNucleus();
            DrawElectrons();

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