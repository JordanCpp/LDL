/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <stdio.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

static float playerX = 0.0f;
static float playerY = 0.0f;
static const float playerSpeed = 5.0f; /* units per second */
static int leftPressed = 0;
static int rightPressed = 0;
static int upPressed = 0;
static int downPressed = 0;

void Identity(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* Keep aspect ratio: world coordinates from -10 to 10 horizontally */
    if (height == 0) height = 1;
    float aspect = (float)width / (float)height;

    glOrtho(-10.0, 10.0, -10.0 / aspect, 10.0 / aspect, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void UpdateMovement(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    float move = playerSpeed * seconds;

    if (leftPressed)  playerX -= move;
    if (rightPressed) playerX += move;
    if (upPressed)    playerY += move;
    if (downPressed)  playerY -= move;

    /* Boundaries (world: -8 to 8 horizontally, -6 to 6 vertically) */
    if (playerX < -8.0f) playerX = -8.0f;
    if (playerX > 8.0f)  playerX = 8.0f;
    if (playerY < -6.0f) playerY = -6.0f;
    if (playerY > 6.0f)  playerY = 6.0f;
}

void DrawPlayer(void)
{
    glPushMatrix();
    glTranslatef(playerX, playerY, 0.0f);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);  /* Green player */
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    /* Draw eyes */
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, 0.2f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

    glPopMatrix();
}

void DrawGrid(void)
{
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_LINES);
    for (int i = -9; i <= 9; i++)
    {
        glVertex2f((float)i, -7.0f);
        glVertex2f((float)i, 7.0f);
        glVertex2f(-9.0f, (float)i);
        glVertex2f(9.0f, (float)i);
    }
    glEnd();
}

void DrawBorder(void)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-9.0f, -6.5f);
    glVertex2f(9.0f, -6.5f);
    glVertex2f(9.0f, 6.5f);
    glVertex2f(-9.0f, 6.5f);
    glEnd();
}

void Display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawGrid();
    DrawBorder();
    DrawPlayer();
}

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_Event         event;
    LDL_OpenGLLoader* loader;
    size_t            lastTime;
    size_t            currentTime;
    size_t            delta;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600),
        "LDL - Move Player with WASD/Arrows (OpenGL 1.2)", 0);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

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

                if (LDL_EventIsKeyPressed(&event, LDL_KeyW) || LDL_EventIsKeyPressed(&event, LDL_KeyUp))
                    upPressed = 1;
                if (LDL_EventIsKeyPressed(&event, LDL_KeyS) || LDL_EventIsKeyPressed(&event, LDL_KeyDown))
                    downPressed = 1;
                if (LDL_EventIsKeyPressed(&event, LDL_KeyA) || LDL_EventIsKeyPressed(&event, LDL_KeyLeft))
                    leftPressed = 1;
                if (LDL_EventIsKeyPressed(&event, LDL_KeyD) || LDL_EventIsKeyPressed(&event, LDL_KeyRight))
                    rightPressed = 1;

                if (LDL_EventIsKeyReleased(&event, LDL_KeyW) || LDL_EventIsKeyReleased(&event, LDL_KeyUp))
                    upPressed = 0;
                if (LDL_EventIsKeyReleased(&event, LDL_KeyS) || LDL_EventIsKeyReleased(&event, LDL_KeyDown))
                    downPressed = 0;
                if (LDL_EventIsKeyReleased(&event, LDL_KeyA) || LDL_EventIsKeyReleased(&event, LDL_KeyLeft))
                    leftPressed = 0;
                if (LDL_EventIsKeyReleased(&event, LDL_KeyD) || LDL_EventIsKeyReleased(&event, LDL_KeyRight))
                    rightPressed = 0;

                if (event.Type == LDL_EventIsResize)
                {
                    Resize((int)event.Resize.Width, (int)event.Resize.Height);
                }
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0)
            {
                UpdateMovement(delta);
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