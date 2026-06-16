/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static float cubeAngle = 0.0f;
static float cameraDistance = 5.0f;
static int mouseX = 0, mouseY = 0;
static int mousePressed = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;
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
    float aspect = (float)width / (float)height;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    Perspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DrawCube(void)
{
    glBegin(GL_QUADS);
    /* Front - Red */
    glColor3f(1.0f, 0.2f, 0.2f);
    glVertex3f(-0.8f, -0.8f, 0.8f);
    glVertex3f(0.8f, -0.8f, 0.8f);
    glVertex3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-0.8f, 0.8f, 0.8f);

    /* Back - Green */
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex3f(-0.8f, -0.8f, -0.8f);
    glVertex3f(-0.8f, 0.8f, -0.8f);
    glVertex3f(0.8f, 0.8f, -0.8f);
    glVertex3f(0.8f, -0.8f, -0.8f);

    /* Top - Blue */
    glColor3f(0.2f, 0.2f, 1.0f);
    glVertex3f(-0.8f, 0.8f, -0.8f);
    glVertex3f(-0.8f, 0.8f, 0.8f);
    glVertex3f(0.8f, 0.8f, 0.8f);
    glVertex3f(0.8f, 0.8f, -0.8f);

    /* Bottom - Yellow */
    glColor3f(1.0f, 1.0f, 0.2f);
    glVertex3f(-0.8f, -0.8f, -0.8f);
    glVertex3f(0.8f, -0.8f, -0.8f);
    glVertex3f(0.8f, -0.8f, 0.8f);
    glVertex3f(-0.8f, -0.8f, 0.8f);

    /* Right - Magenta */
    glColor3f(1.0f, 0.2f, 1.0f);
    glVertex3f(0.8f, -0.8f, -0.8f);
    glVertex3f(0.8f, 0.8f, -0.8f);
    glVertex3f(0.8f, 0.8f, 0.8f);
    glVertex3f(0.8f, -0.8f, 0.8f);

    /* Left - Cyan */
    glColor3f(0.2f, 1.0f, 1.0f);
    glVertex3f(-0.8f, -0.8f, -0.8f);
    glVertex3f(-0.8f, -0.8f, 0.8f);
    glVertex3f(-0.8f, 0.8f, 0.8f);
    glVertex3f(-0.8f, 0.8f, -0.8f);
    glEnd();
}

void DrawAxes(void)
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    /* X - Red */
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);

    /* Y - Green */
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    /* Z - Blue */
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -2.0f);
    glVertex3f(0.0f, 0.0f, 2.0f);
    glEnd();
    glLineWidth(1.0f);
}

void DrawGrid(void)
{
    int i;

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_LINES);

    for (i = -5; i <= 5; i++)
    {
        glVertex3f((float)i, -1.0f, -5.0f);
        glVertex3f((float)i, -1.0f, 5.0f);
        glVertex3f(-5.0f, -1.0f, (float)i);
        glVertex3f(5.0f, -1.0f, (float)i);
    }

    glEnd();
}

void DrawInfo(int width, int height)
{
    int barWidth = (int)(fps * 4.0f);
    int distBar = (int)((cameraDistance - 3.0f) / 7.0f * (width - 20));
    int mouseBar = (int)((float)mouseX / (float)width * (width - 20));

    /* Switch to 2D mode for overlay */
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width, (double)height, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    /* Draw colored rectangles as "text" */
    glBegin(GL_QUADS);
    /* Background bar */
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f((float)width, 0.0f);
    glVertex2f((float)width, 80.0f);
    glVertex2f(0.0f, 80.0f);
    glEnd();

    /* Use colored bars to represent information */
    if (barWidth > width - 20) barWidth = width - 20;

    glBegin(GL_QUADS);
    /* FPS bar */
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(10.0f, 20.0f);
    glVertex2f((float)(10 + barWidth), 20.0f);
    glVertex2f((float)(10 + barWidth), 35.0f);
    glVertex2f(10.0f, 35.0f);

    /* Camera distance bar */
    
    glColor3f(1.0f, 1.0f, 0.2f);
    glVertex2f(10.0f, 45.0f);
    glVertex2f((float)(10 + distBar), 45.0f);
    glVertex2f((float)(10 + distBar), 60.0f);
    glVertex2f(10.0f, 60.0f);

    /* Mouse position bar */
    
    glColor3f(0.2f, 0.5f, 1.0f);
    glVertex2f(10.0f, 70.0f);
    glVertex2f((float)(10 + mouseBar), 70.0f);
    glVertex2f((float)(10 + mouseBar), 80.0f);
    glVertex2f(10.0f, 80.0f);
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

    result = LDL_ResultCreate();
    context = LDL_ContextCreate(result, LDL_ContextOpenGLLegacy);
    window = LDL_WindowCreate(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Interactive 3D Cube (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);

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

                if (event.Type == LDL_EventIsResize)
                {
                    width = (int)event.u.Resize.Width;
                    height = (int)event.u.Resize.Height;
                    Resize(width, height);
                }

                /* Mouse wheel */
                if (event.Type == LDL_EventIsMouseScroll)
                {
                    cameraDistance -= (float)event.u.Mouse.Delta / 100.0f;
                    if (cameraDistance < 3.0f) cameraDistance = 3.0f;
                    if (cameraDistance > 10.0f) cameraDistance = 10.0f;
                }

                /* Mouse position */
                if (event.Type == LDL_EventIsMouseMove)
                {
                    mouseX = (int)event.u.Mouse.PosX;
                    mouseY = (int)event.u.Mouse.PosY;
                }

                /* Mouse button */
                if (LDL_EventIsMousePressed(&event, LDL_MouseButtonLeft))
                {
                    mousePressed = 1;
                }

                if (LDL_EventIsMouseReleased(&event, LDL_MouseButtonLeft))
                {
                    mousePressed = 0;
                }
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0)
            {
                cubeAngle += 45.0f * ((float)delta / 1000.0f);
                if (cubeAngle >= 360.0f) cubeAngle -= 360.0f;
            }

            UpdateFPS();

            /* Clear screen */
            glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            /* Setup 3D view */
            glLoadIdentity();

            /* Camera position */
            glTranslatef(0.0f, 0.0f, -cameraDistance);
            glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
            glRotatef(cubeAngle, 0.0f, 1.0f, 0.0f);

            DrawGrid();
            DrawAxes();
            DrawCube();

            /* Draw info overlay */
            DrawInfo(width, height);

            LDL_WindowPresent(window);

            LDL_Delay(16);
        }

        LDL_OpenGLLoaderFree(loader);
    }

    LDL_ContextDestroy(context);
    LDL_WindowDestroy(window);
    LDL_ResultDestroy(result);

    if (LDL_ResultIsFail(result))
    {
        printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
    }

    return 0;
}