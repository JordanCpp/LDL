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

#define MAX_PARTICLES 1000
#define GRAVITY -6.0f

typedef struct
{
    float x, y, z;
    float vx, vy, vz;
    float r, g, b;
    float life;
    float maxLife;
    int active;
} Particle;

static Particle particles[MAX_PARTICLES];
static float timeToNextRocket = 0.0f;
static float rocketX, rocketZ;
static int rocketActive = 0;
static float rocketY;
static float rocketVy;
static float cameraAngleX = 30.0f;
static float cameraAngleY = 20.0f;
static float cameraDistance = 15.0f;
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

    Perspective(50.0, aspect, 0.1, 50.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void InitParticle(Particle* p, float x, float y, float z, float r, float g, float b)
{
    float angle1 = (float)(rand() % 360) * (float)M_PI / 180.0f;
    float angle2 = (float)(rand() % 360) * (float)M_PI / 180.0f;
    float speed = 2.5f + (float)(rand() % 150) / 100.0f;

    p->x = x;
    p->y = y;
    p->z = z;
    p->vx = (float)sin(angle1) * (float)cos(angle2) * speed;
    p->vy = (float)sin(angle2) * speed + 2.0f;
    p->vz = (float)cos(angle1) * (float)cos(angle2) * speed;
    p->r = r;
    p->g = g;
    p->b = b;
    p->life = 1.0f;
    p->maxLife = 1.2f + (float)(rand() % 80) / 100.0f;
    p->active = 1;
}

void Explode(float x, float y, float z)
{
    int i;
    int count = 60 + rand() % 40;
    int particlesCreated = 0;

    for (i = 0; i < MAX_PARTICLES && particlesCreated < count; i++)
    {
        if (!particles[i].active)
        {
            float r = (float)(rand() % 100) / 100.0f;
            float g = (float)(rand() % 100) / 100.0f;
            float b = (float)(rand() % 100) / 100.0f;

            /* Make colors more vibrant and varied */
            int colorType = rand() % 5;
            switch (colorType)
            {
            case 0: r = 1.0f; g = 0.2f; b = 0.2f; break; /* Red */
            case 1: r = 0.2f; g = 1.0f; b = 0.2f; break; /* Green */
            case 2: r = 0.2f; g = 0.2f; b = 1.0f; break; /* Blue */
            case 3: r = 1.0f; g = 1.0f; b = 0.2f; break; /* Yellow */
            case 4: r = 1.0f; g = 0.5f; b = 0.2f; break; /* Orange */
            }

            InitParticle(&particles[i], x, y, z, r, g, b);
            particlesCreated++;
        }
    }
}

void LaunchRocket(void)
{
    rocketX = (float)(rand() % 200 - 100) / 20.0f;
    rocketZ = (float)(rand() % 200 - 100) / 20.0f;
    rocketY = -2.0f;
    rocketVy = 6.0f + (float)(rand() % 50) / 20.0f;
    rocketActive = 1;
}

void UpdateRocket(float deltaSec)
{
    if (!rocketActive) return;

    rocketVy += GRAVITY * deltaSec * 0.5f;
    rocketY += rocketVy * deltaSec;

    /* Explode when reaching peak or hitting ground */
    if (rocketVy < -2.0f || rocketY > 7.0f)
    {
        Explode(rocketX, rocketY, rocketZ);
        rocketActive = 0;
    }
}

void UpdateParticles(float deltaSec)
{
    int i;

    for (i = 0; i < MAX_PARTICLES; i++)
    {
        if (!particles[i].active) continue;

        /* Apply gravity */
        particles[i].vy += GRAVITY * deltaSec;

        /* Update position */
        particles[i].x += particles[i].vx * deltaSec;
        particles[i].y += particles[i].vy * deltaSec;
        particles[i].z += particles[i].vz * deltaSec;

        /* Reduce life */
        particles[i].life -= deltaSec / particles[i].maxLife;

        /* Deactivate if life is over or below ground */
        if (particles[i].life <= 0.0f || particles[i].y < -2.5f)
        {
            particles[i].active = 0;
        }
    }
}

void DrawRocket(void)
{
    float flameSize = 0.08f + (float)(rand() % 30) / 300.0f;

    if (!rocketActive) return;

    glPushMatrix();
    glTranslatef(rocketX, rocketY, rocketZ);

    /* Rocket body */
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex3f(-0.05f, 0.0f, -0.05f);
    glVertex3f(0.05f, 0.0f, -0.05f);
    glVertex3f(0.05f, 0.25f, -0.05f);
    glVertex3f(-0.05f, 0.25f, -0.05f);

    glVertex3f(-0.05f, 0.0f, 0.05f);
    glVertex3f(-0.05f, 0.25f, 0.05f);
    glVertex3f(0.05f, 0.25f, 0.05f);
    glVertex3f(0.05f, 0.0f, 0.05f);

    glVertex3f(-0.05f, 0.0f, -0.05f);
    glVertex3f(-0.05f, 0.25f, -0.05f);
    glVertex3f(-0.05f, 0.25f, 0.05f);
    glVertex3f(-0.05f, 0.0f, 0.05f);

    glVertex3f(0.05f, 0.0f, -0.05f);
    glVertex3f(0.05f, 0.0f, 0.05f);
    glVertex3f(0.05f, 0.25f, 0.05f);
    glVertex3f(0.05f, 0.25f, -0.05f);
    glEnd();

    /* Nose cone */
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.2f, 0.2f);
    glVertex3f(0.0f, 0.35f, 0.0f);
    glVertex3f(-0.06f, 0.25f, -0.06f);
    glVertex3f(0.06f, 0.25f, -0.06f);

    glVertex3f(0.0f, 0.35f, 0.0f);
    glVertex3f(0.06f, 0.25f, -0.06f);
    glVertex3f(0.06f, 0.25f, 0.06f);

    glVertex3f(0.0f, 0.35f, 0.0f);
    glVertex3f(0.06f, 0.25f, 0.06f);
    glVertex3f(-0.06f, 0.25f, 0.06f);

    glVertex3f(0.0f, 0.35f, 0.0f);
    glVertex3f(-0.06f, 0.25f, 0.06f);
    glVertex3f(-0.06f, 0.25f, -0.06f);
    glEnd();

    /* Exhaust flame */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 0.5f, 0.0f, 0.8f);
    glVertex3f(-0.04f, 0.0f, -0.04f);
    glVertex3f(0.04f, 0.0f, -0.04f);
    glVertex3f(0.0f, -flameSize, 0.0f);

    glVertex3f(0.04f, 0.0f, -0.04f);
    glVertex3f(0.04f, 0.0f, 0.04f);
    glVertex3f(0.0f, -flameSize, 0.0f);

    glVertex3f(0.04f, 0.0f, 0.04f);
    glVertex3f(-0.04f, 0.0f, 0.04f);
    glVertex3f(0.0f, -flameSize, 0.0f);

    glVertex3f(-0.04f, 0.0f, 0.04f);
    glVertex3f(-0.04f, 0.0f, -0.04f);
    glVertex3f(0.0f, -flameSize, 0.0f);
    glEnd();

    glDisable(GL_BLEND);

    glPopMatrix();
}

void DrawParticles(void)
{
    int i;
    int a;
    float alpha;
    float size;
    float angle;
    float px;
    float py;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    for (i = 0; i < MAX_PARTICLES; i++)
    {
        if (!particles[i].active) continue;

        alpha = particles[i].life * 0.8f;
        size = 0.08f * (1.0f - particles[i].life * 0.5f);

        glPushMatrix();
        glTranslatef(particles[i].x, particles[i].y, particles[i].z);

        glColor4f(particles[i].r, particles[i].g, particles[i].b, alpha);

        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 0.0f);

        for (a = 0; a <= 360; a += 30)
        {
            angle = (float)a * (float)M_PI / 180.0f;
            px    = size * (float)cos(angle);
            py    = size * (float)sin(angle);

            glVertex3f(px, py, 0.0f);
        }

        glEnd();

        glPopMatrix();
    }

    glDisable(GL_BLEND);
}

void DrawGround(void)
{
    int i;

    /* Ground plane */
    glBegin(GL_QUADS);
    glColor3f(0.08f, 0.12f, 0.08f);
    glVertex3f(-12.0f, -2.2f, -12.0f);
    glVertex3f(12.0f, -2.2f, -12.0f);
    glVertex3f(12.0f, -2.2f, 12.0f);
    glVertex3f(-12.0f, -2.2f, 12.0f);
    glEnd();

    /* Grid */
    glColor3f(0.15f, 0.2f, 0.15f);
    glBegin(GL_LINES);
    for (i = -10; i <= 10; i++)
    {
        glVertex3f((float)i, -2.15f, -10.0f);
        glVertex3f((float)i, -2.15f, 10.0f);
        glVertex3f(-10.0f, -2.15f, (float)i);
        glVertex3f(10.0f, -2.15f, (float)i);
    }
    glEnd();
}

void DrawCityLights(void)
{
    int i;
    int j;
    float brightness;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    for (i = -8; i <= 8; i += 2)
    {
        for (j = -8; j <= 8; j += 2)
        {
            if (abs(i) < 3 && abs(j) < 3) continue;

            brightness = 0.3f + (float)(rand() % 70) / 100.0f;
            glPushMatrix();
            glTranslatef((float)i, -2.1f, (float)j);
            glColor4f(1.0f, 0.8f, 0.4f, brightness * 0.5f);
            glBegin(GL_QUADS);
            glVertex3f(-0.15f, 0.0f, -0.15f);
            glVertex3f(0.15f, 0.0f, -0.15f);
            glVertex3f(0.15f, 0.0f, 0.15f);
            glVertex3f(-0.15f, 0.0f, 0.15f);
            glEnd();
            glPopMatrix();
        }
    }

    glDisable(GL_BLEND);
}

void DrawInfo(void)
{
    int i;
    int width = 800;
    int height = 600;
    int fpsBar = (int)(fps * 2.0f);
    int activeCount = 0;
    int activeBar;

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
    glVertex2f(240.0f, 0.0f);
    glVertex2f(240.0f, 65.0f);
    glVertex2f(0.0f, 65.0f);
    glEnd();

    /* FPS bar */
    if (fpsBar > 230) fpsBar = 230;

    /* Count active particles */
    for (i = 0; i < MAX_PARTICLES; i++)
        if (particles[i].active) activeCount++;

    activeBar = activeCount / 4;
    if (activeBar > 230) activeBar = 230;

    glBegin(GL_QUADS);
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(5.0f, 10.0f);
    glVertex2f((float)(5 + fpsBar), 10.0f);
    glVertex2f((float)(5 + fpsBar), 20.0f);
    glVertex2f(5.0f, 20.0f);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(5.0f, 25.0f);
    glVertex2f(235.0f, 25.0f);
    glVertex2f(235.0f, 26.0f);
    glVertex2f(5.0f, 26.0f);

    glColor3f(1.0f, 0.5f, 0.2f);
    glVertex2f(5.0f, 35.0f);
    glVertex2f((float)(5 + activeBar), 35.0f);
    glVertex2f((float)(5 + activeBar), 45.0f);
    glVertex2f(5.0f, 45.0f);

    /* Rocket indicator */
    if (rocketActive)
        glColor3f(1.0f, 0.2f, 0.2f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(5.0f, 52.0f);
    glVertex2f(35.0f, 52.0f);
    glVertex2f(35.0f, 62.0f);
    glVertex2f(5.0f, 62.0f);

    /* Hint */
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(40.0f, 52.0f);
    glVertex2f(235.0f, 52.0f);
    glVertex2f(235.0f, 62.0f);
    glVertex2f(40.0f, 62.0f);
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
    float             deltaSec;
    int               i;
    int activeCount = 0;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Fireworks Show (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        /* Initialize all particles as inactive */
        for (i = 0; i < MAX_PARTICLES; i++)
            particles[i].active = 0;

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

                if (LDL_EventIsKeyPressed(&event, LDL_KeyF))
                {
                    /* Manual firework */
                    rocketX = (float)(rand() % 200 - 100) / 20.0f;
                    rocketZ = (float)(rand() % 200 - 100) / 20.0f;
                    Explode(rocketX, 3.0f + (float)(rand() % 40) / 10.0f, rocketZ);
                }

                if (event.Type == LDL_EventIsMouseScroll)
                {
                    cameraDistance -= (float)event.u.Mouse.Delta / 60.0f;
                    if (cameraDistance < 8.0f) cameraDistance = 8.0f;
                    if (cameraDistance > 22.0f) cameraDistance = 22.0f;
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
            deltaSec = (float)delta / 1000.0f;

            if (deltaSec > 0.03f) deltaSec = 0.03f;

            /* Automatic rocket launch */
            if (!rocketActive && activeCount < 200)
            {
                timeToNextRocket -= deltaSec;
                if (timeToNextRocket <= 0.0f)
                {
                    LaunchRocket();
                    timeToNextRocket = 1.0f + (float)(rand() % 30) / 10.0f;
                }
            }

            UpdateRocket(deltaSec);
            UpdateParticles(deltaSec);
            UpdateFPS();

            glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Camera */
            glTranslatef(0.0f, -1.0f, -cameraDistance);
            glRotatef(cameraAngleX, 1.0f, 0.0f, 0.0f);
            glRotatef(cameraAngleY, 0.0f, 1.0f, 0.0f);

            DrawGround();
            DrawCityLights();
            DrawRocket();
            DrawParticles();
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