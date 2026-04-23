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
    float x, y, z;
    float angleX, angleY, angleZ;
    float length;
    float thickness;
    int level;
    int maxLevel;
} Branch;

static Branch branches[1024];
static int branchCount = 0;
static float windAngle = 0.0f;
static float cameraAngleX = 25.0f;
static float cameraAngleY = 30.0f;
static float cameraDistance = 12.0f;
static size_t lastTime = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;
static int showLeaves = 1;

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
    Perspective(45.0, aspect, 0.1, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GenerateBranch(float x, float y, float z, float angleX, float angleY, float angleZ,
    float length, float thickness, int level, int maxLevel)
{
    float endX, endY, endZ;
    float radYaw, radPitch;
    float newLength;
    float newThickness;
    int newLevel;

    if (level > maxLevel || branchCount >= 1023) return;

    /* Store branch */
    branches[branchCount].x = x;
    branches[branchCount].y = y;
    branches[branchCount].z = z;
    branches[branchCount].angleX = angleX;
    branches[branchCount].angleY = angleY;
    branches[branchCount].angleZ = angleZ;
    branches[branchCount].length = length;
    branches[branchCount].thickness = thickness;
    branches[branchCount].level = level;
    branches[branchCount].maxLevel = maxLevel;
    branchCount++;

    /* Calculate end point - Y is UP, X is right, Z is forward */
    radYaw = angleY * M_PI / 180.0f;   /* Rotation around Y axis */
    radPitch = angleX * M_PI / 180.0f; /* Rotation around X axis */

    endX = x + length * cos(radPitch) * sin(radYaw);
    endY = y + length * sin(radPitch);
    endZ = z + length * cos(radPitch) * cos(radYaw);

    newLength = length * 0.68f;
    newThickness = thickness * 0.7f;
    newLevel = level + 1;

    /* Generate child branches */
    if (newLevel <= maxLevel)
    {
        /* Main continuation */
        GenerateBranch(endX, endY, endZ,
            angleX, angleY, angleZ,
            newLength, newThickness, newLevel, maxLevel);

        /* Branch left */
        GenerateBranch(endX, endY, endZ,
            angleX - 20.0f, angleY - 25.0f, angleZ,
            newLength, newThickness, newLevel, maxLevel);

        /* Branch right */
        GenerateBranch(endX, endY, endZ,
            angleX - 20.0f, angleY + 25.0f, angleZ,
            newLength, newThickness, newLevel, maxLevel);

        /* Branch forward */
        GenerateBranch(endX, endY, endZ,
            angleX - 15.0f, angleY, angleZ + 20.0f,
            newLength, newThickness, newLevel, maxLevel);

        /* Branch back */
        GenerateBranch(endX, endY, endZ,
            angleX - 15.0f, angleY, angleZ - 20.0f,
            newLength, newThickness, newLevel, maxLevel);
    }
}

void GenerateTree(void)
{
    branchCount = 0;
    /* Start from ground, Y goes UP, initial pitch 90 degrees (straight up) */
    GenerateBranch(0.0f, 0.0f, 0.0f, 90.0f, 0.0f, 0.0f, 1.2f, 0.22f, 0, 6);
}

void DrawCylinder(float x1, float y1, float z1, float x2, float y2, float z2,
    float radius1, float radius2, float r, float g, float b)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    float length = sqrt(dx * dx + dy * dy + dz * dz);
    float angle;
    float rx, rz;

    if (length < 0.001f) return;

    /* Calculate rotation angle and axis to align cylinder */
    angle = acos(dy / length) * 180.0f / M_PI;
    rx = dz;
    rz = -dx;

    glPushMatrix();
    glTranslatef(x1, y1, z1);

    if (angle > 0.001f && (rx != 0.0f || rz != 0.0f))
    {
        glRotatef(angle, rx, 0.0f, rz);
    }

    /* Draw cylinder as a series of quads */
    int segments = 6;
    float nx, nz;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; i++)
    {
        float theta = (float)i / (float)segments * 2.0f * M_PI;
        float c = cos(theta);
        float s = sin(theta);

        /* Bottom ring */
        nx = radius1 * c;
        nz = radius1 * s;
        glColor3f(r, g, b);
        glVertex3f(nx, 0.0f, nz);

        /* Top ring */
        nx = radius2 * c;
        nz = radius2 * s;
        glColor3f(r * 0.7f, g * 0.7f, b * 0.7f);
        glVertex3f(nx, length, nz);
    }
    glEnd();

    glPopMatrix();
}

void DrawLeaf(float x, float y, float z, float size, float r, float g, float b)
{
    glPushMatrix();
    glTranslatef(x, y, z);

    /* Make leaves face camera roughly */
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_TRIANGLES);
    glColor4f(r, g, b, 0.8f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(size, size * 0.6f, 0.0f);
    glVertex3f(-size, size * 0.6f, 0.0f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, size * 0.6f, size);
    glVertex3f(0.0f, size * 0.6f, -size);
    glEnd();

    glDisable(GL_BLEND);

    glPopMatrix();
}

void DrawTree(float wind)
{
    int i;
    float endX, endY, endZ;
    float radYaw, radPitch;
    float windYaw, windPitch;
    float r, g, bl;

    for (i = 0; i < branchCount; i++)
    {
        Branch* b = &branches[i];

        /* Apply wind effect */
        windYaw = wind * sin(wind * 5.0f) * 15.0f;
        windPitch = wind * cos(wind * 3.0f) * 10.0f;

        radYaw = (b->angleY + windYaw) * M_PI / 180.0f;
        radPitch = (b->angleX + windPitch) * M_PI / 180.0f;

        endX = b->x + b->length * cos(radPitch) * sin(radYaw);
        endY = b->y + b->length * sin(radPitch);
        endZ = b->z + b->length * cos(radPitch) * cos(radYaw);

        /* Color based on level */
        if (b->level == 0)
        {
            r = 0.55f; g = 0.35f; bl = 0.15f;  /* Trunk - brown */
        }
        else if (b->level < 3)
        {
            r = 0.45f; g = 0.30f; bl = 0.12f;  /* Branches - dark brown */
        }
        else
        {
            r = 0.35f; g = 0.25f; bl = 0.10f;  /* Twigs - very dark brown */
        }

        DrawCylinder(b->x, b->y, b->z, endX, endY, endZ,
            b->thickness, b->thickness * 0.75f, r, g, bl);

        /* Add leaves at ends of highest level branches */
        if (showLeaves && b->level >= b->maxLevel - 1)
        {
            float leafR = 0.2f + (float)(i % 4) * 0.1f;
            float leafG = 0.5f + (float)(i % 3) * 0.1f;
            float leafB = 0.1f;
            DrawLeaf(endX, endY, endZ, 0.1f, leafR, leafG, leafB);
        }
    }
}

void DrawGround(void)
{
    /* Ground plane */
    glBegin(GL_QUADS);
    glColor3f(0.12f, 0.25f, 0.08f);
    glVertex3f(-6.0f, -0.05f, -6.0f);
    glVertex3f(6.0f, -0.05f, -6.0f);
    glVertex3f(6.0f, -0.05f, 6.0f);
    glVertex3f(-6.0f, -0.05f, 6.0f);
    glEnd();

    /* Grass circle around tree */
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.15f, 0.45f, 0.15f);
    glVertex3f(0.0f, -0.04f, 0.0f);
    for (int i = 0; i <= 360; i += 30)
    {
        float angle = i * M_PI / 180.0f;
        float x = 1.3f * cos(angle);
        float z = 1.3f * sin(angle);
        glColor3f(0.2f, 0.5f, 0.2f);
        glVertex3f(x, -0.04f, z);
    }
    glEnd();
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
    glVertex2f(210.0f, 0.0f);
    glVertex2f(210.0f, 60.0f);
    glVertex2f(0.0f, 60.0f);
    glEnd();

    /* FPS bar */
    int fpsBar = (int)(fps * 2.0f);
    if (fpsBar > 200) fpsBar = 200;

    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 10.0f);
    glVertex2f((float)(5 + fpsBar), 10.0f);
    glVertex2f((float)(5 + fpsBar), 20.0f);
    glVertex2f(5.0f, 20.0f);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(5.0f, 25.0f);
    glVertex2f(205.0f, 25.0f);
    glVertex2f(205.0f, 26.0f);
    glVertex2f(5.0f, 26.0f);

    /* Branch count bar */
    int barLength = branchCount / 4;
    if (barLength > 200) barLength = 200;
    glColor3f(0.3f, 0.7f, 0.3f);
    glVertex2f(5.0f, 35.0f);
    glVertex2f((float)(5 + barLength), 35.0f);
    glVertex2f((float)(5 + barLength), 45.0f);
    glVertex2f(5.0f, 45.0f);

    /* Hint text as bar */
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(5.0f, 52.0f);
    glVertex2f(205.0f, 52.0f);
    glVertex2f(205.0f, 58.0f);
    glVertex2f(5.0f, 58.0f);
    glEnd();

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void UpdateWind(void)
{
    static float time = 0.0f;
    time += 0.033f;
    windAngle = sin(time) * 0.8f;
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
        "LDL - Fractal Tree (OpenGL 1.2)", 0);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        GenerateTree();

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
                    showLeaves = !showLeaves;
                }

                if (LDL_EventIsKeyPressed(&event, LDL_KeyR))
                {
                    GenerateTree();
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
                UpdateWind();
            }

            UpdateFPS();

            glClearColor(0.05f, 0.05f, 0.15f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Camera - looking at the tree */
            glTranslatef(0.0f, -1.0f, -cameraDistance);
            glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
            glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

            DrawGround();
            DrawTree(windAngle);
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