/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define TARGET_COUNT 8
#define MAX_SHOTS 16

typedef struct
{
    float x, y, z;
    float radius;
    float r, g, b;
    int active;
    float speedX, speedZ;
} Target;

typedef struct
{
    float x, y, z;
    float vx, vy, vz;
    int active;
    float life;
} Shot;

static Target targets[TARGET_COUNT];
static Shot shots[MAX_SHOTS];
static int score = 0;
static int ammo = 30;
static float playerAngle = 0.0f;
static float bulletCooldown = 0.0f;
static size_t lastTime = 0;
static size_t frameCount = 0;
static float fps = 0.0f;
static size_t lastFpsTime = 0;
static int mouseX = 400, mouseY = 300;
static int centerX = 400, centerY = 300;
static int mouseControl = 1;

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

    centerX = width / 2;
    centerY = height / 2;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    Perspective(75.0, aspect, 0.01, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void InitTargets(void)
{
    int i;

    for (i = 0; i < TARGET_COUNT; i++)
    {
        targets[i].x = (float)(rand() % 120 - 60) / 10.0f;
        targets[i].z = (float)(rand() % 80 - 40) / 10.0f - 5.0f;
        targets[i].y = 0.5f;
        targets[i].radius = 0.4f;
        targets[i].r = 1.0f;
        targets[i].g = 0.2f + (float)(rand() % 80) / 100.0f;
        targets[i].b = 0.2f;
        targets[i].active = 1;
        targets[i].speedX = (float)(rand() % 40 - 20) / 20.0f;
        targets[i].speedZ = (float)(rand() % 40 - 20) / 20.0f;
    }
}

void InitShots(void)
{
    int i;

    for (i = 0; i < MAX_SHOTS; i++)
    {
        shots[i].active = 0;
    }
}

void FireShot(void)
{
    int i;

    if (ammo <= 0) return;

    for (i = 0; i < MAX_SHOTS; i++)
    {
        if (!shots[i].active)
        {
            shots[i].x = 0.0f;
            shots[i].y = 0.2f;
            shots[i].z = 0.0f;
            shots[i].vx = (float)sin(playerAngle * M_PI / 180.0f) * 12.0f;
            shots[i].vz = (float)cos(playerAngle * M_PI / 180.0f) * 12.0f;
            shots[i].vy = (float)(rand() % 20 - 10) / 50.0f;
            shots[i].active = 1;
            shots[i].life = 2.0f;
            ammo--;
            break;
        }
    }
}

void UpdateTargets(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;
    float speed;

    for (i = 0; i < TARGET_COUNT; i++)
    {
        if (targets[i].active)
        {
            targets[i].x += targets[i].speedX * seconds;
            targets[i].z += targets[i].speedZ * seconds;

            /* Bounce off boundaries */
            if (targets[i].x > 8.0f) { targets[i].x = 8.0f; targets[i].speedX = -targets[i].speedX; }
            if (targets[i].x < -8.0f) { targets[i].x = -8.0f; targets[i].speedX = -targets[i].speedX; }
            if (targets[i].z > 5.0f) { targets[i].z = 5.0f; targets[i].speedZ = -targets[i].speedZ; }
            if (targets[i].z < -15.0f) { targets[i].z = -15.0f; targets[i].speedZ = -targets[i].speedZ; }

            /* Color flash based on speed */
            speed = (float)sqrt(targets[i].speedX * targets[i].speedX + targets[i].speedZ * targets[i].speedZ);
            targets[i].r = 0.8f + speed * 0.3f;
        }
    }
}

void UpdateShots(size_t delta)
{
    int i, j, k;
    float seconds = (float)delta / 1000.0f;
    float dx, dz, dist;

    for (i = 0; i < MAX_SHOTS; i++)
    {
        if (shots[i].active)
        {
            shots[i].x += shots[i].vx * seconds;
            shots[i].z += shots[i].vz * seconds;
            shots[i].y += shots[i].vy * seconds;
            shots[i].life -= seconds;

            /* Check collision with targets */
            for (j = 0; j < TARGET_COUNT; j++)
            {
                if (targets[j].active)
                {
                    dx = shots[i].x - targets[j].x;
                    dz = shots[i].z - targets[j].z;
                    dist = (float)sqrt(dx * dx + dz * dz);

                    if (dist < targets[j].radius)
                    {
                        shots[i].active = 0;
                        targets[j].active = 0;
                        score++;
                        ammo += 2;
                        if (ammo > 50) ammo = 50;
                        break;
                    }
                }
            }

            /* Remove if out of bounds or expired */
            if (shots[i].life <= 0.0f || shots[i].z < -20.0f || shots[i].z > 10.0f ||
                shots[i].x < -12.0f || shots[i].x > 12.0f)
            {
                shots[i].active = 0;
            }
        }
    }

    /* Respawn inactive targets */
    for (k = 0; k < TARGET_COUNT; k++)
    {
        if (!targets[k].active)
        {
            targets[k].active = 1;
            targets[k].x = (float)(rand() % 120 - 60) / 10.0f;
            targets[k].z = (float)(rand() % 60 - 30) / 10.0f - 5.0f;
            targets[k].speedX = (float)(rand() % 40 - 20) / 20.0f;
            targets[k].speedZ = (float)(rand() % 40 - 20) / 20.0f;
            targets[k].r = 1.0f;
            targets[k].g = 0.2f + (float)(rand() % 80) / 100.0f;
        }
    }
}

void DrawTarget(Target* t)
{
    glPushMatrix();
    glTranslatef(t->x, t->y, t->z);

    /* Body */
    glBegin(GL_QUADS);
    glColor3f(t->r, t->g, t->b);
    glVertex3f(-t->radius, -t->radius, t->radius);
    glVertex3f(t->radius, -t->radius, t->radius);
    glVertex3f(t->radius, t->radius, t->radius);
    glVertex3f(-t->radius, t->radius, t->radius);

    glColor3f(t->r * 0.7f, t->g * 0.7f, t->b * 0.7f);
    glVertex3f(-t->radius, -t->radius, -t->radius);
    glVertex3f(-t->radius, t->radius, -t->radius);
    glVertex3f(t->radius, t->radius, -t->radius);
    glVertex3f(t->radius, -t->radius, -t->radius);

    glColor3f(t->r * 0.8f, t->g * 0.8f, t->b * 0.8f);
    glVertex3f(-t->radius, t->radius, -t->radius);
    glVertex3f(-t->radius, t->radius, t->radius);
    glVertex3f(t->radius, t->radius, t->radius);
    glVertex3f(t->radius, t->radius, -t->radius);

    glColor3f(t->r * 0.6f, t->g * 0.6f, t->b * 0.6f);
    glVertex3f(-t->radius, -t->radius, -t->radius);
    glVertex3f(t->radius, -t->radius, -t->radius);
    glVertex3f(t->radius, -t->radius, t->radius);
    glVertex3f(-t->radius, -t->radius, t->radius);
    glEnd();

    /* Target bullseye */
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-t->radius * 0.3f, -t->radius * 0.3f, t->radius + 0.01f);
    glVertex3f(t->radius * 0.3f, -t->radius * 0.3f, t->radius + 0.01f);
    glVertex3f(t->radius * 0.3f, t->radius * 0.3f, t->radius + 0.01f);
    glVertex3f(-t->radius * 0.3f, t->radius * 0.3f, t->radius + 0.01f);
    glEnd();

    glPopMatrix();
}

void DrawShot(Shot* s)
{
    glPushMatrix();
    glTranslatef(s->x, s->y, s->z);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.05f, -0.05f, 0.05f);
    glVertex3f(0.05f, -0.05f, 0.05f);
    glVertex3f(0.05f, 0.05f, 0.05f);
    glVertex3f(-0.05f, 0.05f, 0.05f);
    glEnd();

    glPopMatrix();
}

void DrawGround(void)
{
    int i;
    int j;

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-12.0f, -0.2f, -20.0f);
    glVertex3f(12.0f, -0.2f, -20.0f);
    glVertex3f(12.0f, -0.2f, 10.0f);
    glVertex3f(-12.0f, -0.2f, 10.0f);
    glEnd();

    /* Grid */
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_LINES);

    for (i = -10; i <= 10; i++)
    {
        glVertex3f((float)i, -0.19f, -15.0f);
        glVertex3f((float)i, -0.19f, 8.0f);
    }

    for (j = -15; j <= 8; j++)
    {
        glVertex3f(-10.0f, -0.19f, (float)j);
        glVertex3f(10.0f, -0.19f, (float)j);
    }

    glEnd();
}

void DrawCrosshair(int width, int height)
{
    int ammoBar = (ammo * 80) / 50;
    int scoreBar = (score * 100) / 50;
    int fpsBar = (int)(fps);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, (double)width, (double)height, 0.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    /* Crosshair */
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f((float)centerX - 15.0f, (float)centerY);
    glVertex2f((float)centerX - 5.0f, (float)centerY);
    glVertex2f((float)centerX + 5.0f, (float)centerY);
    glVertex2f((float)centerX + 15.0f, (float)centerY);
    glVertex2f((float)centerX, (float)centerY - 15.0f);
    glVertex2f((float)centerX, (float)centerY - 5.0f);
    glVertex2f((float)centerX, (float)centerY + 5.0f);
    glVertex2f((float)centerX, (float)centerY + 15.0f);

    /* Hit indicator when shooting */
    if (bulletCooldown > 0.05f)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f((float)centerX - 8.0f, (float)centerY - 8.0f);
        glVertex2f((float)centerX + 8.0f, (float)centerY + 8.0f);
        glVertex2f((float)centerX + 8.0f, (float)centerY - 8.0f);
        glVertex2f((float)centerX - 8.0f, (float)centerY + 8.0f);
    }
    glEnd();

    /* Ammo indicator */
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f((float)width - 100.0f, 10.0f);
    glVertex2f((float)width - 10.0f, 10.0f);
    glVertex2f((float)width - 10.0f, 40.0f);
    glVertex2f((float)width - 100.0f, 40.0f);


    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex2f((float)width - 95.0f, 15.0f);
    glVertex2f((float)width - 95.0f + (float)ammoBar, 15.0f);
    glVertex2f((float)width - 95.0f + (float)ammoBar, 35.0f);
    glVertex2f((float)width - 95.0f, 35.0f);
    glEnd();

    /* Score */
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(10.0f, 10.0f);
    glVertex2f(120.0f, 10.0f);
    glVertex2f(120.0f, 40.0f);
    glVertex2f(10.0f, 40.0f);


    if (scoreBar > 100) scoreBar = 100;
    glColor3f(0.2f, 1.0f, 0.2f);
    glVertex2f(15.0f, 15.0f);
    glVertex2f(15.0f + (float)scoreBar, 15.0f);
    glVertex2f(15.0f + (float)scoreBar, 35.0f);
    glVertex2f(15.0f, 35.0f);
    glEnd();

    /* FPS */

    if (fpsBar > 100) fpsBar = 100;
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f((float)width - 100.0f, (float)height - 30.0f);
    glVertex2f((float)width - 10.0f, (float)height - 30.0f);
    glVertex2f((float)width - 10.0f, (float)height - 10.0f);
    glVertex2f((float)width - 100.0f, (float)height - 10.0f);

    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f((float)width - 95.0f, (float)height - 25.0f);
    glVertex2f((float)width - 95.0f + (float)fpsBar, (float)height - 25.0f);
    glVertex2f((float)width - 95.0f + (float)fpsBar, (float)height - 15.0f);
    glVertex2f((float)width - 95.0f, (float)height - 15.0f);
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
    int i;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Target Shooter (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);

        srand(42);
        InitTargets();
        InitShots();

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

                if (LDL_EventIsKeyPressed(&event, LDL_KeyR))
                {
                    score = 0;
                    ammo = 30;
                    InitTargets();
                }

                if (LDL_EventIsMousePressed(&event, LDL_MouseButtonLeft))
                {
                    if (bulletCooldown <= 0.0f)
                    {
                        FireShot();
                        bulletCooldown = 0.2f;
                    }
                }

                if (event.Type == LDL_EventIsMouseMove && mouseControl)
                {
                    mouseX = (int)event.u.Mouse.PosX;
                    mouseY = (int)event.u.Mouse.PosY;

                    playerAngle += ((float)mouseX - (float)centerX) * 0.2f;

                    if (playerAngle > 360.0f) playerAngle -= 360.0f;
                    if (playerAngle < 0.0f) playerAngle += 360.0f;
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
                if (bulletCooldown > 0.0f)
                    bulletCooldown -= (float)delta / 1000.0f;

                UpdateTargets(delta);
                UpdateShots(delta);
            }

            UpdateFPS();

            glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* First person camera */
            glRotatef(-playerAngle, 0.0f, 1.0f, 0.0f);
            glTranslatef(0.0f, -0.5f, 0.0f);

            DrawGround();

            for (i = 0; i < TARGET_COUNT; i++)
            {
                if (targets[i].active)
                    DrawTarget(&targets[i]);
            }

            for (i = 0; i < MAX_SHOTS; i++)
            {
                if (shots[i].active)
                    DrawShot(&shots[i]);
            }

            DrawCrosshair(width, height);

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