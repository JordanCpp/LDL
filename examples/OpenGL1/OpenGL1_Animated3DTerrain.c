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

#define GRID_SIZE 40
#define GRID_STEP 0.3f

static float heights[GRID_SIZE][GRID_SIZE];
static float timeOffset = 0.0f;
static float rotationAngle = 0.0f;
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

    Perspective(60.0, aspect, 0.1, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void UpdateHeights(float time)
{
    int x, z;
    float fx, fz;

    for (x = 0; x < GRID_SIZE; x++)
    {
        for (z = 0; z < GRID_SIZE; z++)
        {
            fx = (float)x / (float)GRID_SIZE * 8.0f;
            fz = (float)z / (float)GRID_SIZE * 8.0f;

            /* Multiple sine waves for realistic terrain */
            heights[x][z] =
                (float)sin(fx * 1.2f + time) * (float)cos(fz * 1.0f + time * 0.7f) * 0.6f +
                (float)sin(fx * 2.5f - time * 1.3f) * 0.3f +
                (float)cos(fz * 2.0f + time * 0.9f) * 0.3f +
                (float)sin((fx * 0.5f + fz * 0.5f) * 1.5f + time * 0.5f) * 0.2f;
        }
    }
}

void DrawTerrain(void)
{
    int x, z;
    float r, g, b;
    float height;

    for (x = 0; x < GRID_SIZE - 1; x++)
    {
        glBegin(GL_TRIANGLE_STRIP);

        for (z = 0; z < GRID_SIZE; z++)
        {
            /* First vertex */
            height = heights[x][z];

            /* Color based on height */
            if (height < -0.5f)
            {
                r = 0.0f; g = 0.2f; b = 0.5f;
            }      /* Deep water */
            else if (height < -0.2f)
            {
                r = 0.0f; g = 0.4f; b = 0.7f;
            }      /* Shallow water */
            else if (height < 0.0f)
            {
                r = 0.5f; g = 0.6f; b = 0.3f;
            }      /* Sand */
            else if (height < 0.3f)
            {
                r = 0.3f; g = 0.7f; b = 0.2f;
            }      /* Grass */
            else if (height < 0.6f)
            {
                r = 0.5f; g = 0.5f; b = 0.2f;
            }      /* Dirt */
            else
            {
                r = 0.8f; g = 0.8f; b = 0.8f;
            }      /* Snow */

            glColor3f(r, g, b);
            glVertex3f(
                ((float)x - GRID_SIZE / 2) * GRID_STEP,
                heights[x][z],
                ((float)z - GRID_SIZE / 2) * GRID_STEP
            );

            /* Second vertex */
            height = heights[x + 1][z];

            if (height < -0.5f)
            {
                r = 0.0f; g = 0.2f; b = 0.5f;
            }
            else if (height < -0.2f)
            {
                r = 0.0f; g = 0.4f; b = 0.7f;
            }
            else if (height < 0.0f)
            {
                r = 0.5f; g = 0.6f; b = 0.3f;
            }
            else if (height < 0.3f)
            {
                r = 0.3f; g = 0.7f; b = 0.2f;
            }
            else if (height < 0.6f)
            {
                r = 0.5f; g = 0.5f; b = 0.2f;
            }
            else
            {
                r = 0.8f; g = 0.8f; b = 0.8f;
            }

            glColor3f(r, g, b);
            glVertex3f(
                ((float)(x + 1) - GRID_SIZE / 2) * GRID_STEP,
                heights[x + 1][z],
                ((float)z - GRID_SIZE / 2) * GRID_STEP
            );
        }

        glEnd();
    }
}

void DrawSky(void)
{
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    /* Gradient sky */
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(1.0f, 0.5f);

    glColor3f(0.4f, 0.6f, 0.9f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
}

void DrawInfoOverlay(int width, int height)
{
    /* Draw FPS bar */
    int fpsBar = (int)(fps * 2.0f);
    if (fpsBar > 190) fpsBar = 190;

    /* Switch to 2D mode */
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width, (double)height, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    /* Draw info panel */
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(200.0f, 0.0f);
    glVertex2f(200.0f, 60.0f);
    glVertex2f(0.0f, 60.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 15.0f);
    glVertex2f((float)(5 + fpsBar), 15.0f);
    glVertex2f((float)(5 + fpsBar), 25.0f);
    glVertex2f(5.0f, 25.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(5.0f, 35.0f);
    glVertex2f(195.0f, 35.0f);
    glVertex2f(195.0f, 36.0f);
    glVertex2f(5.0f, 36.0f);

    glColor3f(0.2f, 0.5f, 1.0f);
    glVertex2f(5.0f, 45.0f);
    glVertex2f((float)fpsBar, 45.0f);
    glVertex2f((float)fpsBar, 55.0f);
    glVertex2f(5.0f, 55.0f);
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
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Animated 3D Terrain (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);

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

            if (delta > 0)
            {
                timeOffset += (float)delta / 500.0f;
                rotationAngle += 20.0f * ((float)delta / 1000.0f);
                if (rotationAngle >= 360.0f) rotationAngle -= 360.0f;

                UpdateHeights(timeOffset);
            }

            UpdateFPS();

            /* Clear */
            glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            /* Setup camera */
            glLoadIdentity();
            glTranslatef(0.0f, -2.0f, -8.0f);
            glRotatef(25.0f, 1.0f, 0.0f, 0.0f);
            glRotatef(rotationAngle * 0.2f, 0.0f, 1.0f, 0.0f);

            DrawTerrain();
            DrawInfoOverlay(width, height);

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