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
#include <time.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static float hourAngle = 0.0f;
static float minuteAngle = 0.0f;
static float secondAngle = 0.0f;
static float cameraAngleX = 25.0f;
static float cameraAngleY = 15.0f;
static float cameraDistance = 4.0f;
static size_t lastTime = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;
static int showNumbers = 1;

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
    Perspective(45.0, aspect, 0.1, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void UpdateTime(void)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    /* Calculate angles in degrees */
    secondAngle = (float)timeinfo->tm_sec * 6.0f;
    minuteAngle = (float)timeinfo->tm_min * 6.0f + (float)timeinfo->tm_sec * 0.1f;
    hourAngle = (float)(timeinfo->tm_hour % 12) * 30.0f + (float)timeinfo->tm_min * 0.5f;
}

void DrawCylinder(float x1, float y1, float z1, float x2, float y2, float z2,
    float radius, float r, float g, float b)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    float length = sqrt(dx * dx + dy * dy + dz * dz);
    float angle;
    float rx, rz;

    if (length < 0.001f) return;

    angle = acos(dy / length) * 180.0f / M_PI;
    rx = dz;
    rz = -dx;

    glPushMatrix();
    glTranslatef(x1, y1, z1);

    if (angle > 0.001f && (rx != 0.0f || rz != 0.0f))
    {
        glRotatef(angle, rx, 0.0f, rz);
    }

    int segments = 8;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; i++)
    {
        float theta = (float)i / (float)segments * 2.0f * M_PI;
        float c = cos(theta);
        float s = sin(theta);

        glColor3f(r, g, b);
        glVertex3f(radius * c, 0.0f, radius * s);
        glVertex3f(radius * c, length, radius * s);
    }
    glEnd();

    glPopMatrix();
}

void DrawSphere(float radius, float r, float g, float b, int stacks, int slices)
{
    int i, j;
    float phi, theta;
    float x, y, z;

    for (i = 0; i <= stacks; i++)
    {
        phi = (float)i / (float)stacks * M_PI;

        glBegin(GL_TRIANGLE_STRIP);

        for (j = 0; j <= slices; j++)
        {
            theta = (float)j / (float)slices * 2.0f * M_PI;

            x = radius * sin(phi) * cos(theta);
            y = radius * cos(phi);
            z = radius * sin(phi) * sin(theta);

            glColor3f(r, g, b);
            glVertex3f(x, y, z);

            phi = (float)(i + 1) / (float)stacks * M_PI;
            x = radius * sin(phi) * cos(theta);
            y = radius * cos(phi);
            z = radius * sin(phi) * sin(theta);

            glColor3f(r * 0.8f, g * 0.8f, b * 0.8f);
            glVertex3f(x, y, z);

            phi = (float)i / (float)stacks * M_PI;
        }

        glEnd();
    }
}

void DrawClockFace(void)
{
    int i;
    float angle;
    float x, z;

    /* Main circle */
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.95f, 0.95f, 0.9f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (i = 0; i <= 360; i += 10)
    {
        angle = i * M_PI / 180.0f;
        x = 1.0f * cos(angle);
        z = 1.0f * sin(angle);
        glColor3f(0.95f, 0.95f, 0.85f);
        glVertex3f(x, 0.0f, z);
    }
    glEnd();

    /* Outer rim */
    glBegin(GL_LINE_LOOP);
    glColor3f(0.3f, 0.3f, 0.3f);
    for (i = 0; i <= 360; i += 5)
    {
        angle = i * M_PI / 180.0f;
        x = 1.02f * cos(angle);
        z = 1.02f * sin(angle);
        glVertex3f(x, 0.0f, z);
    }
    glEnd();

    /* Hour markers */
    for (i = 0; i < 12; i++)
    {
        angle = (float)i * 30.0f * M_PI / 180.0f;
        float x1 = 0.9f * cos(angle);
        float z1 = 0.9f * sin(angle);
        float x2 = 0.98f * cos(angle);
        float z2 = 0.98f * sin(angle);

        glBegin(GL_LINES);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex3f(x1, 0.01f, z1);
        glVertex3f(x2, 0.01f, z2);
        glEnd();
    }

    /* Minute markers */
    for (i = 0; i < 60; i++)
    {
        if (i % 5 == 0) continue;
        angle = (float)i * 6.0f * M_PI / 180.0f;
        float x1 = 0.94f * cos(angle);
        float z1 = 0.94f * sin(angle);
        float x2 = 0.98f * cos(angle);
        float z2 = 0.98f * sin(angle);

        glBegin(GL_LINES);
        glColor3f(0.4f, 0.4f, 0.4f);
        glVertex3f(x1, 0.01f, z1);
        glVertex3f(x2, 0.01f, z2);
        glEnd();
    }

    /* Center dot */
    DrawSphere(0.05f, 0.2f, 0.2f, 0.2f, 8, 8);
}

void DrawNumber(float angle, float radius, char* num)
{
    /* Simple number representation using small spheres */
    float x = radius * cos(angle * M_PI / 180.0f);
    float z = radius * sin(angle * M_PI / 180.0f);

    glPushMatrix();
    glTranslatef(x, 0.02f, z);

    /* Draw a colored dot for each number */
    glColor3f(0.2f, 0.2f, 0.3f);
    DrawSphere(0.045f, 0.2f, 0.2f, 0.3f, 6, 6);

    glPopMatrix();
}

void DrawNumbers(void)
{
    if (!showNumbers) return;

    /* Draw dots for 3, 6, 9, 12 */
    DrawNumber(0.0f, 0.82f, "12");
    DrawNumber(90.0f, 0.82f, "3");
    DrawNumber(180.0f, 0.82f, "6");
    DrawNumber(270.0f, 0.82f, "9");

    /* Additional dots for other hours */
    DrawNumber(30.0f, 0.78f, "1");
    DrawNumber(60.0f, 0.78f, "2");
    DrawNumber(120.0f, 0.78f, "4");
    DrawNumber(150.0f, 0.78f, "5");
    DrawNumber(210.0f, 0.78f, "7");
    DrawNumber(240.0f, 0.78f, "8");
    DrawNumber(300.0f, 0.78f, "10");
    DrawNumber(330.0f, 0.78f, "11");
}

void DrawHourHand(void)
{
    float rad = hourAngle * M_PI / 180.0f;
    float x = 0.45f * sin(rad);
    float z = 0.45f * cos(rad);

    glPushMatrix();
    glTranslatef(0.0f, 0.03f, 0.0f);
    DrawCylinder(0.0f, 0.0f, 0.0f, x, 0.0f, z, 0.045f, 0.1f, 0.1f, 0.1f);

    /* Arrow tip */
    float tipX = 0.52f * sin(rad);
    float tipZ = 0.52f * cos(rad);
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(tipX, 0.03f, tipZ);
    glVertex3f(x - 0.05f * sin(rad - 1.2f), 0.03f, z - 0.05f * cos(rad - 1.2f));
    glVertex3f(x - 0.05f * sin(rad + 1.2f), 0.03f, z - 0.05f * cos(rad + 1.2f));
    glEnd();

    glPopMatrix();
}

void DrawMinuteHand(void)
{
    float rad = minuteAngle * M_PI / 180.0f;
    float x = 0.65f * sin(rad);
    float z = 0.65f * cos(rad);

    glPushMatrix();
    glTranslatef(0.0f, 0.04f, 0.0f);
    DrawCylinder(0.0f, 0.0f, 0.0f, x, 0.0f, z, 0.035f, 0.15f, 0.15f, 0.15f);

    /* Arrow tip */
    float tipX = 0.72f * sin(rad);
    float tipZ = 0.72f * cos(rad);
    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);
    glVertex3f(tipX, 0.04f, tipZ);
    glVertex3f(x - 0.04f * sin(rad - 1.0f), 0.04f, z - 0.04f * cos(rad - 1.0f));
    glVertex3f(x - 0.04f * sin(rad + 1.0f), 0.04f, z - 0.04f * cos(rad + 1.0f));
    glEnd();

    glPopMatrix();
}

void DrawSecondHand(void)
{
    float rad = secondAngle * M_PI / 180.0f;
    float x = 0.85f * sin(rad);
    float z = 0.85f * cos(rad);
    float backX = -0.12f * sin(rad);
    float backZ = -0.12f * cos(rad);

    glPushMatrix();
    glTranslatef(0.0f, 0.05f, 0.0f);

    /* Second hand line */
    DrawCylinder(backX, 0.0f, backZ, x, 0.0f, z, 0.02f, 1.0f, 0.2f, 0.2f);

    /* Center circle */
    DrawSphere(0.04f, 1.0f, 0.2f, 0.2f, 6, 6);

    glPopMatrix();
}

void DrawGlassEffect(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_TRIANGLE_FAN);
    glColor4f(0.8f, 0.9f, 1.0f, 0.08f);
    glVertex3f(0.0f, 0.08f, 0.0f);
    for (int i = 0; i <= 360; i += 15)
    {
        float angle = i * M_PI / 180.0f;
        float x = 1.03f * cos(angle);
        float z = 1.03f * sin(angle);
        glColor4f(0.8f, 0.9f, 1.0f, 0.05f);
        glVertex3f(x, 0.08f, z);
    }
    glEnd();

    glDisable(GL_BLEND);
}

void DrawInfo(void)
{
    int width = 800;
    int height = 600;

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
    glVertex2f(230.0f, 0.0f);
    glVertex2f(230.0f, 70.0f);
    glVertex2f(0.0f, 70.0f);
    glEnd();

    /* FPS bar */
    int fpsBar = (int)(fps * 2.0f);
    if (fpsBar > 220) fpsBar = 220;

    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 10.0f);
    glVertex2f((float)(5 + fpsBar), 10.0f);
    glVertex2f((float)(5 + fpsBar), 20.0f);
    glVertex2f(5.0f, 20.0f);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(5.0f, 25.0f);
    glVertex2f(225.0f, 25.0f);
    glVertex2f(225.0f, 26.0f);
    glVertex2f(5.0f, 26.0f);

    /* Numbers toggle indicator */
    if (showNumbers)
        glColor3f(0.2f, 0.8f, 0.2f);
    else
        glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(5.0f, 35.0f);
    glVertex2f(70.0f, 35.0f);
    glVertex2f(70.0f, 45.0f);
    glVertex2f(5.0f, 45.0f);

    /* Time display as bar */
    glColor3f(1.0f, 0.8f, 0.2f);
    int hourBar = (int)(hourAngle / 360.0f * 200.0f);
    glVertex2f(80.0f, 35.0f);
    glVertex2f((float)(80 + hourBar), 35.0f);
    glVertex2f((float)(80 + hourBar), 42.0f);
    glVertex2f(80.0f, 42.0f);

    int minuteBar = (int)(minuteAngle / 360.0f * 200.0f);
    glColor3f(0.3f, 0.6f, 1.0f);
    glVertex2f(80.0f, 45.0f);
    glVertex2f((float)(80 + minuteBar), 45.0f);
    glVertex2f((float)(80 + minuteBar), 52.0f);
    glVertex2f(80.0f, 52.0f);

    int secondBar = (int)(secondAngle / 360.0f * 200.0f);
    glColor3f(1.0f, 0.3f, 0.3f);
    glVertex2f(80.0f, 55.0f);
    glVertex2f((float)(80 + secondBar), 55.0f);
    glVertex2f((float)(80 + secondBar), 62.0f);
    glVertex2f(80.0f, 62.0f);

    /* Hint */
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(5.0f, 55.0f);
    glVertex2f(75.0f, 55.0f);
    glVertex2f(75.0f, 62.0f);
    glVertex2f(5.0f, 62.0f);
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
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height),
        "LDL - 3D Analog Clock (OpenGL 1.2)", 0);

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
                if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                {
                    LDL_WindowStopEvent(window);
                }

                if (LDL_EventIsKeyPressed(&event, LDL_KeySpace))
                {
                    showNumbers = !showNumbers;
                }

                if (event.Type == LDL_EventIsMouseScroll)
                {
                    cameraDistance -= (float)event.Mouse.Delta / 80.0f;
                    if (cameraDistance < 2.5f) cameraDistance = 2.5f;
                    if (cameraDistance > 6.0f) cameraDistance = 6.0f;
                }

                if (event.Type == LDL_EventIsResize)
                {
                    width = (int)event.Resize.Width;
                    height = (int)event.Resize.Height;
                    Resize(width, height);
                }
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0 && delta < 100)
            {
                UpdateTime();
            }

            UpdateFPS();

            glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Camera */
            glTranslatef(0.0f, 0.2f, -cameraDistance);
            glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
            glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

            /* Draw clock */
            DrawClockFace();
            DrawNumbers();
            DrawSecondHand();
            DrawMinuteHand();
            DrawHourHand();
            DrawGlassEffect();

            DrawInfo();

            LDL_WindowPresent(window);

            LDL_Delay(33);  /* ~30 FPS, enough for smooth second hand */
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