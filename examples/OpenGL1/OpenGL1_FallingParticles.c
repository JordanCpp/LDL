/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

#define PARTICLE_COUNT 20

typedef struct
{
    float x;
    float y;
    float speed;
    float size;
    float r, g, b;
} Particle;

static Particle particles[PARTICLE_COUNT];
static int windowWidth = 800;
static int windowHeight = 600;

void Resize(int width, int height)
{
    float aspect = (float)width / (float)height;

    windowWidth = width;
    windowHeight = height;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* World coordinates: -10 to 10 horizontally, proportional vertically */
    glOrtho(-10.0, 10.0, -10.0 / aspect, 10.0 / aspect, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void InitParticles(void)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        /* Random position */
        particles[i].x = (float)(rand() % 200 - 100) / 10.0f;  /* -10 to 10 */
        particles[i].y = (float)(rand() % 140 - 70) / 10.0f;   /* -7 to 7 */

        /* Random speed (0.5 to 3.0 units per second) */
        particles[i].speed = 0.5f + (float)(rand() % 25) / 10.0f;

        /* Random size (0.1 to 0.4) */
        particles[i].size = 0.1f + (float)(rand() % 30) / 100.0f;

        /* Random color */
        particles[i].r = (float)(rand() % 100) / 100.0f;
        particles[i].g = (float)(rand() % 100) / 100.0f;
        particles[i].b = (float)(rand() % 100) / 100.0f;
    }
}

void UpdateParticles(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;
    float aspect = (float)windowWidth / (float)windowHeight;
    float bottom = -10.0f / aspect;

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        /* Move down */
        particles[i].y -= particles[i].speed * seconds;

        /* Reset if below bottom */
        if (particles[i].y < bottom - 0.5f)
        {
            /* Respawn at top with random x */
            particles[i].x = (float)(rand() % 200 - 100) / 10.0f;
            particles[i].y = 10.0f / aspect;

            /* Slightly change color on respawn */
            particles[i].r = (float)(rand() % 100) / 100.0f;
            particles[i].g = (float)(rand() % 100) / 100.0f;
            particles[i].b = (float)(rand() % 100) / 100.0f;
        }
    }
}

void DrawParticles(void)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        glPushMatrix();
        glTranslatef(particles[i].x, particles[i].y, 0.0f);

        glBegin(GL_QUADS);
        glColor3f(particles[i].r, particles[i].g, particles[i].b);
        glVertex2f(-particles[i].size, -particles[i].size);
        glVertex2f(particles[i].size, -particles[i].size);
        glVertex2f(particles[i].size, particles[i].size);
        glVertex2f(-particles[i].size, particles[i].size);
        glEnd();

        glPopMatrix();
    }
}

void DrawGrid(void)
{
    int i;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);

    for (i = -10; i <= 10; i++)
    {
        glVertex2f((float)i, -8.0f);
        glVertex2f((float)i, 8.0f);
        glVertex2f(-10.0f, (float)i);
        glVertex2f(10.0f, (float)i);
    }

    glEnd();
}

void DrawInfo(void)
{
    int i;

    /* Draw simple text indicator using points (since no font yet) */
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);

    /* Just a visual marker in top-left */
    for (i = 0; i < 10; i++)
    {
        glVertex2f(-9.5f + (float)i * 0.2f, 7.8f);
    }

    glEnd();
}

void Display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawGrid();
    DrawParticles();
    DrawInfo();
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
    context = LDL_ContextNew(LDL_ContextOpenGLLegacy);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL - Falling Particles (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        InitParticles();
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

                if (event.Type == LDL_EventIsResize)
                {
                    Resize((int)event.u.Resize.Width, (int)event.u.Resize.Height);
                }
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0)
            {
                UpdateParticles(delta);
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