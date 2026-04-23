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

#define PLANET_COUNT 8

typedef struct
{
    float distance;
    float radius;
    float speed;
    float angle;
    float orbitTilt;
    float r, g, b;
    char name[8];
} Planet;

static Planet planets[] = {
    {1.8f, 0.12f, 100.0f, 0.0f, 5.0f,  0.8f, 0.6f, 0.4f, "Mercury"},
    {2.5f, 0.14f, 75.0f,  0.0f, 3.0f,  0.9f, 0.7f, 0.5f, "Venus"},
    {3.2f, 0.16f, 60.0f,  0.0f, 2.0f,  0.2f, 0.5f, 0.9f, "Earth"},
    {3.9f, 0.15f, 50.0f,  0.0f, 4.0f,  0.9f, 0.3f, 0.3f, "Mars"},
    {5.0f, 0.32f, 30.0f,  0.0f, 6.0f,  0.7f, 0.6f, 0.4f, "Jupiter"},
    {6.2f, 0.28f, 24.0f,  0.0f, 8.0f,  0.8f, 0.7f, 0.5f, "Saturn"},
    {7.2f, 0.22f, 18.0f,  0.0f, 7.0f,  0.5f, 0.7f, 0.9f, "Uranus"},
    {8.2f, 0.20f, 14.0f,  0.0f, 9.0f,  0.3f, 0.4f, 0.8f, "Neptune"}
};

static float cameraDistance = 14.0f;
static float cameraRotX = 35.0f;
static float cameraRotY = 0.0f;
static float timeAccum = 0.0f;
static int selectedPlanet = -1;
static size_t lastTime = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;

void LookAt(float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ)
{
    float forwardX, forwardY, forwardZ;
    float sideX, sideY, sideZ;
    float upVectorX, upVectorY, upVectorZ;
    float length;

    forwardX = centerX - eyeX;
    forwardY = centerY - eyeY;
    forwardZ = centerZ - eyeZ;

    length = sqrt(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);
    if (length != 0.0f)
    {
        forwardX /= length;
        forwardY /= length;
        forwardZ /= length;
    }

    upVectorX = upX;
    upVectorY = upY;
    upVectorZ = upZ;

    sideX = forwardY * upVectorZ - forwardZ * upVectorY;
    sideY = forwardZ * upVectorX - forwardX * upVectorZ;
    sideZ = forwardX * upVectorY - forwardY * upVectorX;

    length = sqrt(sideX * sideX + sideY * sideY + sideZ * sideZ);
    if (length != 0.0f)
    {
        sideX /= length;
        sideY /= length;
        sideZ /= length;
    }

    upVectorX = sideY * forwardZ - sideZ * forwardY;
    upVectorY = sideZ * forwardX - sideX * forwardZ;
    upVectorZ = sideX * forwardY - sideY * forwardX;

    float mat[16];
    mat[0] = sideX;
    mat[1] = upVectorY;
    mat[2] = -forwardX;
    mat[3] = 0.0f;

    mat[4] = sideY;
    mat[5] = upVectorY;
    mat[6] = -forwardY;
    mat[7] = 0.0f;

    mat[8] = sideZ;
    mat[9] = upVectorZ;
    mat[10] = -forwardZ;
    mat[11] = 0.0f;

    mat[12] = 0.0f;
    mat[13] = 0.0f;
    mat[14] = 0.0f;
    mat[15] = 1.0f;

    glMultMatrixf(mat);
    glTranslatef(-eyeX, -eyeY, -eyeZ);
}

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

void DrawSun(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    for (int i = 0; i < 3; i++)
    {
        float size = 0.85f + i * 0.1f;
        float alpha = 0.25f - i * 0.08f;
        glColor4f(1.0f, 0.6f, 0.1f, alpha);
        DrawSphere(size, 1.0f, 0.6f, 0.1f, 16, 16);
    }

    glDisable(GL_BLEND);
    DrawSphere(0.7f, 1.0f, 0.8f, 0.2f, 20, 20);
}

void DrawOrbit(float radius, float tilt)
{
    float tiltRad = tilt * M_PI / 180.0f;

    glColor3f(0.35f, 0.35f, 0.45f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i += 10)
    {
        float angle = i * M_PI / 180.0f;
        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float y = sin(angle) * tilt * 0.08f;
        glVertex3f(x, y, z);
    }
    glEnd();
}

void DrawPlanet(Planet* p, int index)
{
    float tiltRad = p->orbitTilt * M_PI / 180.0f;
    float angleRad = p->angle * M_PI / 180.0f;

    /* Позиция с учётом наклона орбиты */
    float x = p->distance * cos(angleRad);
    float z = p->distance * sin(angleRad);
    float y = sin(angleRad) * tiltRad * 0.12f;

    glPushMatrix();
    glTranslatef(x, y, z);

    /* Подсветка выбранной планеты */
    if (selectedPlanet == index)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glColor4f(p->r, p->g, p->b, 0.35f);
        DrawSphere(p->radius + 0.06f, p->r, p->g, p->b, 12, 12);
        glDisable(GL_BLEND);
    }

    DrawSphere(p->radius, p->r, p->g, p->b, 16, 16);

    /* Кольца Сатурна в 3D */
    if (p->radius > 0.27f && p->radius < 0.33f)
    {
        glColor3f(0.85f, 0.75f, 0.55f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 360; i += 15)
        {
            float ang = i * M_PI / 180.0f;
            float rx = (p->radius + 0.18f) * cos(ang);
            float rz = (p->radius + 0.18f) * sin(ang);
            glVertex3f(rx, 0.07f, rz);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 360; i += 15)
        {
            float ang = i * M_PI / 180.0f;
            float rx = (p->radius + 0.18f) * cos(ang);
            float rz = (p->radius + 0.18f) * sin(ang);
            glVertex3f(rx, -0.07f, rz);
        }
        glEnd();
    }

    glPopMatrix();
}

void DrawStars(void)
{
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBegin(GL_POINTS);
    for (int i = 0; i < 500; i++)
    {
        float x = (float)((i * 131071) % 10000) / 10000.0f;
        float y = (float)((i * 524287) % 10000) / 10000.0f;
        float bright = 0.4f + ((i * 2999) % 100) / 100.0f;
        glColor3f(bright, bright, bright);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
}

void DrawInfo(int width, int height)
{
    char buf[32];

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(270.0f, 0.0f);
    glVertex2f(270.0f, 85.0f);
    glVertex2f(0.0f, 85.0f);
    glEnd();

    /* FPS */
    int fpsBar = (int)(fps * 2.2f);
    if (fpsBar > 260) fpsBar = 260;

    /* Выбранная планета */
    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 10.0f);
    glVertex2f((float)(5 + fpsBar), 10.0f);
    glVertex2f((float)(5 + fpsBar), 20.0f);
    glVertex2f(5.0f, 20.0f);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(5.0f, 25.0f);
    glVertex2f(265.0f, 25.0f);
    glVertex2f(265.0f, 26.0f);
    glVertex2f(5.0f, 26.0f);

    if (selectedPlanet >= 0)
    {
        glColor3f(planets[selectedPlanet].r, planets[selectedPlanet].g, planets[selectedPlanet].b);
    }
    else
    {
        glColor3f(1.0f, 0.8f, 0.2f);
    }
    glVertex2f(5.0f, 32.0f);
    glVertex2f(100.0f, 32.0f);
    glVertex2f(100.0f, 48.0f);
    glVertex2f(5.0f, 48.0f);

    /* Zoom */
    int zoomBar = (int)((cameraDistance - 7.0f) / 14.0f * 260.0f);
    if (zoomBar < 0) zoomBar = 0;
    if (zoomBar > 260) zoomBar = 260;
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(5.0f, 55.0f);
    glVertex2f((float)(5 + zoomBar), 55.0f);
    glVertex2f((float)(5 + zoomBar), 65.0f);
    glVertex2f(5.0f, 65.0f);

    glColor3f(0.4f, 0.5f, 0.7f);
    glVertex2f(5.0f, 72.0f);
    glVertex2f(265.0f, 72.0f);
    glVertex2f(265.0f, 82.0f);
    glVertex2f(5.0f, 82.0f);
    glEnd();

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void UpdatePlanets(float deltaSec)
{
    int i;
    for (i = 0; i < PLANET_COUNT; i++)
    {
        planets[i].angle += planets[i].speed * deltaSec;
        if (planets[i].angle >= 360.0f)
            planets[i].angle -= 360.0f;
    }
}

void UpdateFPS(void)
{
    size_t now = LDL_Ticks();
    frameCount++;
    if (now - lastFpsTime >= 1000)
    {
        fps = frameCount * 1000.0f / (now - lastFpsTime);
        frameCount = 0;
        lastFpsTime = now;
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
    float             deltaSec;
    int               i;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height),
        "LDL - 3D Solar System (OpenGL 1.2)", 0);

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

                for (i = 0; i < PLANET_COUNT; i++)
                {
                    if (LDL_EventIsKeyPressed(&event, LDL_KeyNum1 + i))
                        selectedPlanet = i;
                }

                if (LDL_EventIsKeyPressed(&event, LDL_KeyNum0))
                    selectedPlanet = -1;

                if (event.Type == LDL_EventIsMouseScroll)
                {
                    cameraDistance -= (float)event.Mouse.Delta / 50.0f;
                    if (cameraDistance < 6.0f) cameraDistance = 6.0f;
                    if (cameraDistance > 22.0f) cameraDistance = 22.0f;
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
            deltaSec = (float)delta / 1000.0f;
            if (deltaSec > 0.03f) deltaSec = 0.03f;

            if (deltaSec > 0)
            {
                timeAccum += deltaSec * 20.0f;
                if (timeAccum >= 360.0f) timeAccum -= 360.0f;
                cameraRotY = timeAccum;

                UpdatePlanets(deltaSec);
            }

            UpdateFPS();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Камера с хорошим обзором */
            float radX = cameraRotX * M_PI / 180.0f;
            float radY = cameraRotY * M_PI / 180.0f;

            float camX = sin(radY) * cameraDistance;
            float camZ = cos(radY) * cameraDistance;
            float camY = sin(radX) * 4.0f + 3.0f;

            /* Точка наблюдения */
            float lookX = 0.0f, lookY = 0.0f, lookZ = 0.0f;
            if (selectedPlanet >= 0)
            {
                float tilt = planets[selectedPlanet].orbitTilt * M_PI / 180.0f;
                float ang = planets[selectedPlanet].angle * M_PI / 180.0f;
                lookX = planets[selectedPlanet].distance * cos(ang);
                lookZ = planets[selectedPlanet].distance * sin(ang);
                lookY = sin(ang) * tilt * 0.12f;
            }

            LookAt(camX, camY, camZ, lookX, lookY, lookZ, 0.0f, 1.0f, 0.0f);

            DrawStars();
            DrawSun();

            for (i = 0; i < PLANET_COUNT; i++)
            {
                DrawOrbit(planets[i].distance, planets[i].orbitTilt);
                DrawPlanet(&planets[i], i);
            }

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
        printf("LDL error: %s\n", LDL_ResultGetMessage(result));
    }

    return 0;
}