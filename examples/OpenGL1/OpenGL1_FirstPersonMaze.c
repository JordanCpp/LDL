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

/* Maze layout: 15x15, 1 = wall, 0 = path */
static const int maze[15][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,1,1,0,1,0,1,1,1,0,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static float playerX = 1.5f;
static float playerZ = 1.5f;
static float playerAngle = 0.0f;
static float moveSpeed = 3.0f;
static float turnSpeed = 90.0f;
static int moveForward = 0;
static int moveBack = 0;
static int turnLeft = 0;
static int turnRight = 0;
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

    Perspective(75.0, aspect, 0.01, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int CheckCollision(float x, float z)
{
    int gridX = (int)(x + 0.5f);
    int gridZ = (int)(z + 0.5f);

    if (gridX < 0 || gridX >= 15 || gridZ < 0 || gridZ >= 15)
        return 1;

    return maze[gridZ][gridX];
}

void UpdateMovement(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    float move = moveSpeed * seconds;
    float turn = turnSpeed * seconds;
    float newX, newZ;

    if (turnLeft)
        playerAngle += turn;
    if (turnRight)
        playerAngle -= turn;

    if (playerAngle >= 360.0f) playerAngle -= 360.0f;
    if (playerAngle < 0.0f) playerAngle += 360.0f;

    if (moveForward)
    {
        newX = playerX + sin(playerAngle * M_PI / 180.0f) * move;
        newZ = playerZ + cos(playerAngle * M_PI / 180.0f) * move;

        if (!CheckCollision(newX, newZ))
        {
            playerX = newX;
            playerZ = newZ;
        }
    }

    if (moveBack)
    {
        newX = playerX - sin(playerAngle * M_PI / 180.0f) * move;
        newZ = playerZ - cos(playerAngle * M_PI / 180.0f) * move;

        if (!CheckCollision(newX, newZ))
        {
            playerX = newX;
            playerZ = newZ;
        }
    }
}

void DrawWall(float x, float z, float colorR, float colorG, float colorB)
{
    glBegin(GL_QUADS);
    /* Front face */
    glColor3f(colorR, colorG, colorB);
    glVertex3f(x - 0.5f, 0.0f, z - 0.5f);
    glVertex3f(x + 0.5f, 0.0f, z - 0.5f);
    glVertex3f(x + 0.5f, 1.0f, z - 0.5f);
    glVertex3f(x - 0.5f, 1.0f, z - 0.5f);

    /* Back face */
    glColor3f(colorR * 0.7f, colorG * 0.7f, colorB * 0.7f);
    glVertex3f(x - 0.5f, 0.0f, z + 0.5f);
    glVertex3f(x - 0.5f, 1.0f, z + 0.5f);
    glVertex3f(x + 0.5f, 1.0f, z + 0.5f);
    glVertex3f(x + 0.5f, 0.0f, z + 0.5f);

    /* Left face */
    glColor3f(colorR * 0.8f, colorG * 0.8f, colorB * 0.8f);
    glVertex3f(x - 0.5f, 0.0f, z - 0.5f);
    glVertex3f(x - 0.5f, 1.0f, z - 0.5f);
    glVertex3f(x - 0.5f, 1.0f, z + 0.5f);
    glVertex3f(x - 0.5f, 0.0f, z + 0.5f);

    /* Right face */
    glColor3f(colorR * 0.9f, colorG * 0.9f, colorB * 0.9f);
    glVertex3f(x + 0.5f, 0.0f, z - 0.5f);
    glVertex3f(x + 0.5f, 0.0f, z + 0.5f);
    glVertex3f(x + 0.5f, 1.0f, z + 0.5f);
    glVertex3f(x + 0.5f, 1.0f, z - 0.5f);

    /* Top face */
    glColor3f(colorR * 1.1f, colorG * 1.1f, colorB * 1.1f);
    glVertex3f(x - 0.5f, 1.0f, z - 0.5f);
    glVertex3f(x + 0.5f, 1.0f, z - 0.5f);
    glVertex3f(x + 0.5f, 1.0f, z + 0.5f);
    glVertex3f(x - 0.5f, 1.0f, z + 0.5f);
    glEnd();
}

void DrawMaze(void)
{
    int i, j;

    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (maze[i][j])
            {
                /* Different color based on position */
                float r = 0.5f + (i % 3) * 0.15f;
                float g = 0.4f + (j % 3) * 0.15f;
                float b = 0.3f;
                DrawWall((float)j, (float)i, r, g, b);
            }
        }
    }
}

void DrawFloor(void)
{
    int i;

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.4f);
    glVertex3f(-7.5f, -0.01f, -7.5f);
    glVertex3f(7.5f, -0.01f, -7.5f);
    glVertex3f(7.5f, -0.01f, 7.5f);
    glVertex3f(-7.5f, -0.01f, 7.5f);
    glEnd();

    /* Grid on floor */
    glColor3f(0.5f, 0.5f, 0.6f);
    glBegin(GL_LINES);

    for (i = -7; i <= 7; i++)
    {
        glVertex3f((float)i, -0.005f, -7.5f);
        glVertex3f((float)i, -0.005f, 7.5f);
        glVertex3f(-7.5f, -0.005f, (float)i);
        glVertex3f(7.5f, -0.005f, (float)i);
    }

    glEnd();
}

void DrawCrosshair(void)
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

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    /* Horizontal line */
    glVertex2f((float)width / 2 - 10.0f, (float)height / 2);
    glVertex2f((float)width / 2 - 4.0f, (float)height / 2);
    glVertex2f((float)width / 2 + 4.0f, (float)height / 2);
    glVertex2f((float)width / 2 + 10.0f, (float)height / 2);
    /* Vertical line */
    glVertex2f((float)width / 2, (float)height / 2 - 10.0f);
    glVertex2f((float)width / 2, (float)height / 2 - 4.0f);
    glVertex2f((float)width / 2, (float)height / 2 + 4.0f);
    glVertex2f((float)width / 2, (float)height / 2 + 10.0f);
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
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - First Person Maze (OpenGL 1.2)", LDL_WindowModeResized);

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

                if (LDL_EventIsKeyPressed(&event, LDL_KeyW))
                    moveForward = 1;
                if (LDL_EventIsKeyPressed(&event, LDL_KeyS))
                    moveBack = 1;
                if (LDL_EventIsKeyPressed(&event, LDL_KeyA))
                    turnLeft = 1;
                if (LDL_EventIsKeyPressed(&event, LDL_KeyD))
                    turnRight = 1;

                if (LDL_EventIsKeyReleased(&event, LDL_KeyW))
                    moveForward = 0;
                if (LDL_EventIsKeyReleased(&event, LDL_KeyS))
                    moveBack = 0;
                if (LDL_EventIsKeyReleased(&event, LDL_KeyA))
                    turnLeft = 0;
                if (LDL_EventIsKeyReleased(&event, LDL_KeyD))
                    turnRight = 0;

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
                UpdateMovement(delta);
            }

            UpdateFPS();

            /* Clear */
            glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            /* Setup camera (first person) */
            glLoadIdentity();
            glRotatef(-playerAngle, 0.0f, 1.0f, 0.0f);
            glTranslatef(-playerX, -0.5f, -playerZ);

            DrawFloor();
            DrawMaze();
            DrawCrosshair();

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