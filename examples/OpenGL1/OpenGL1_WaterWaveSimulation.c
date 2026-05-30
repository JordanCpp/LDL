/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
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

#define WATER_SIZE 40
#define WATER_STEP 0.25f

static float waterHeights[WATER_SIZE][WATER_SIZE];
static float waterVelocities[WATER_SIZE][WATER_SIZE];
static float timeOffset = 0.0f;
static float cameraAngleX = 35.0f;
static float cameraAngleY = 25.0f;
static float cameraDistance = 8.0f;
static int wireframeMode = 0;
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

void InitWater(void)
{
    int x, z;

    for (x = 0; x < WATER_SIZE; x++)
    {
        for (z = 0; z < WATER_SIZE; z++)
        {
            waterHeights[x][z] = 0.0f;
            waterVelocities[x][z] = 0.0f;
        }
    }

    /* Create initial ripple in the center */
    waterHeights[WATER_SIZE / 2][WATER_SIZE / 2] = 0.5f;
}

void UpdateWaveEquation(void)
{
    int x, z;
    float laplacian;
    float damping = 0.995f;
    float speed = 0.02f;
    float newHeights[WATER_SIZE][WATER_SIZE];

    /* Update velocities and heights using wave equation */
    for (x = 1; x < WATER_SIZE - 1; x++)
    {
        for (z = 1; z < WATER_SIZE - 1; z++)
        {
            laplacian =
                waterHeights[x + 1][z] + waterHeights[x - 1][z] +
                waterHeights[x][z + 1] + waterHeights[x][z - 1] -
                4.0f * waterHeights[x][z];

            waterVelocities[x][z] += laplacian * speed;
            waterVelocities[x][z] *= damping;
            newHeights[x][z] = waterHeights[x][z] + waterVelocities[x][z];
        }
    }

    /* Copy new heights */
    for (x = 1; x < WATER_SIZE - 1; x++)
    {
        for (z = 1; z < WATER_SIZE - 1; z++)
        {
            waterHeights[x][z] = newHeights[x][z];
        }
    }

    /* Add random ripples occasionally */
    if ((int)(timeOffset * 10) % 50 == 0)
    {
        int rx = rand() % (WATER_SIZE - 10) + 5;
        int rz = rand() % (WATER_SIZE - 10) + 5;
        waterHeights[rx][rz] += 0.3f;
    }
}

void UpdateWater(size_t delta)
{
    int step;
    int updateSteps = (int)(delta / 16);

    if (updateSteps > 3) updateSteps = 3;

    for (step = 0; step < updateSteps; step++)
    {
        UpdateWaveEquation();
    }

    timeOffset += (float)delta / 1000.0f;
}

void DrawWater(void)
{
    int x, z;
    float r, g, b;
    float height;

    if (wireframeMode)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    for (x = 0; x < WATER_SIZE - 1; x++)
    {
        glBegin(GL_TRIANGLE_STRIP);

        for (z = 0; z < WATER_SIZE; z++)
        {
            /* Vertex 1 */
            height = waterHeights[x][z];

            /* Color based on height and wave phase */
            r = 0.2f + height * 0.3f;
            g = 0.4f + height * 0.4f;
            b = 0.7f + height * 0.2f;

            glColor4f(r, g, b, 0.8f);
            glVertex3f(
                ((float)x - WATER_SIZE / 2) * WATER_STEP,
                height,
                ((float)z - WATER_SIZE / 2) * WATER_STEP
            );

            /* Vertex 2 */
            height = waterHeights[x + 1][z];

            r = 0.2f + height * 0.3f;
            g = 0.4f + height * 0.4f;
            b = 0.7f + height * 0.2f;

            glColor4f(r, g, b, 0.8f);
            glVertex3f(
                ((float)(x + 1) - WATER_SIZE / 2) * WATER_STEP,
                height,
                ((float)z - WATER_SIZE / 2) * WATER_STEP
            );
        }

        glEnd();
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void DrawWaterFloor(void)
{
    int i;

    /* Sandy bottom */
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.5f, 0.3f);
    glVertex3f(-5.5f, -0.8f, -5.5f);
    glVertex3f(5.5f, -0.8f, -5.5f);
    glVertex3f(5.5f, -0.8f, 5.5f);
    glVertex3f(-5.5f, -0.8f, 5.5f);
    glEnd();

    /* Grid on bottom */
    glColor3f(0.4f, 0.3f, 0.2f);
    glBegin(GL_LINES);

    for (i = -5; i <= 5; i++)
    {
        glVertex3f((float)i, -0.79f, -5.0f);
        glVertex3f((float)i, -0.79f, 5.0f);
        glVertex3f(-5.0f, -0.79f, (float)i);
        glVertex3f(5.0f, -0.79f, (float)i);
    }

    glEnd();
}

void DrawSkybox(void)
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    /* Gradient sky */
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.2f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);

    glColor3f(0.3f, 0.5f, 0.7f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(0.0f, 0.6f);

    glColor3f(0.5f, 0.7f, 0.9f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(0.0f, 0.6f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

void DrawInfo(int width, int height)
{
    int fpsBar = (int)(fps);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width, (double)height, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    /* Background panel */
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(220.0f, 0.0f);
    glVertex2f(220.0f, 70.0f);
    glVertex2f(0.0f, 70.0f);
    glEnd();

    /* FPS bar */
    if (fpsBar > 210) fpsBar = 210;

    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 15.0f);
    glVertex2f((float)(5 + fpsBar), 15.0f);
    glVertex2f((float)(5 + fpsBar), 25.0f);
    glVertex2f(5.0f, 25.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(5.0f, 35.0f);
    glVertex2f(215.0f, 35.0f);
    glVertex2f(215.0f, 36.0f);
    glVertex2f(5.0f, 36.0f);

    /* Wireframe mode indicator */
    if (wireframeMode)
        glColor3f(1.0f, 0.5f, 0.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glVertex2f(5.0f, 50.0f);
    glVertex2f(25.0f, 50.0f);
    glVertex2f(25.0f, 65.0f);
    glVertex2f(5.0f, 65.0f);
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
    context = LDL_ContextNew(LDL_ContextOpenGLLegacy);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Water Wave Simulation (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glShadeModel(GL_SMOOTH);

        InitWater();

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
                    wireframeMode = !wireframeMode;
                }

                if (LDL_EventIsKeyPressed(&event, LDL_KeyR))
                {
                    InitWater();
                }

                if (event.Type == LDL_EventIsMouseScroll)
                {
                    cameraDistance -= (float)event.u.Mouse.Delta / 100.0f;
                    if (cameraDistance < 3.0f) cameraDistance = 3.0f;
                    if (cameraDistance > 15.0f) cameraDistance = 15.0f;
                }

                if (event.Type == LDL_EventIsResize)
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
                UpdateWater(delta);
            }

            UpdateFPS();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Camera */
            glTranslatef(0.0f, -1.5f, -cameraDistance);
            glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
            glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

            DrawSkybox();
            DrawWaterFloor();
            DrawWater();
            DrawInfo(width, height);

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