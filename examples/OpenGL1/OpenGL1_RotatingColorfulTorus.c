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

static float angle = 0.0f;
static float colorHue = 0.0f;
static size_t lastTime = 0;
static const float rotationSpeed = 30.0f;  /* degrees per second */
static const float colorSpeed = 45.0f;     /* degrees per second */

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

    /* Perspective projection */
    Perspective(45.0, aspect, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void HSVtoRGB(float h, float s, float v, float* r, float* g, float* b)
{
    int i;
    float f, p, q, t;

    h = (float)fmod(h, 360.0f);
    if (h < 0) h += 360.0f;

    s /= 100.0f;
    v /= 100.0f;

    if (s == 0.0f)
    {
        *r = *g = *b = v;
        return;
    }

    h /= 60.0f;
    i = (int)floor(h);
    f = h - i;
    p = v * (1.0f - s);
    q = v * (1.0f - s * f);
    t = v * (1.0f - s * (1.0f - f));

    switch (i)
    {
    case 0: *r = v; *g = t; *b = p; break;
    case 1: *r = q; *g = v; *b = p; break;
    case 2: *r = p; *g = v; *b = t; break;
    case 3: *r = p; *g = q; *b = v; break;
    case 4: *r = t; *g = p; *b = v; break;
    default: *r = v; *g = p; *b = q; break;
    }
}

void DrawTorus(float radius, float tubeRadius, int rings, int sides)
{
    int i, j;
    float phi, theta;
    float x, y, z;
    float nx, ny, nz;
    float r, g, b;

    for (i = 0; i <= rings; i++)
    {
        phi = (float)i / (float)rings * 2.0f * (float)M_PI;

        glBegin(GL_QUAD_STRIP);

        for (j = 0; j <= sides; j++)
        {
            theta = (float)j / (float)sides * 2.0f * (float)M_PI;

            /* First vertex */
            x = (radius + tubeRadius * (float)cos(theta)) * (float)cos(phi);
            y = (radius + tubeRadius * (float)cos(theta)) * (float)sin(phi);
            z = tubeRadius * (float)sin(theta);

            nx = (float)cos(phi) * (float)cos(theta);
            ny = (float)sin(phi) * (float)cos(theta);
            nz = (float)sin(theta);

            /* Color based on position and hue */
            HSVtoRGB(colorHue + phi * 180.0f / (float)M_PI, 80.0f, 100.0f, &r, &g, &b);
            glColor3f(r, g, b);
            glNormal3f(nx, ny, nz);
            glVertex3f(x, y, z);

            /* Second vertex - next ring */
            phi = (float)(i + 1) / (float)rings * 2.0f * (float)M_PI;
            x = (radius + tubeRadius * (float)cos(theta)) * (float)cos(phi);
            y = (radius + tubeRadius * (float)cos(theta)) * (float)sin(phi);
            z = tubeRadius * (float)sin(theta);

            nx = (float)cos(phi) * (float)cos(theta);
            ny = (float)sin(phi) * (float)cos(theta);
            nz = (float)sin(theta);

            HSVtoRGB(colorHue + phi * 180.0f / (float)M_PI, 80.0f, 100.0f, &r, &g, &b);
            glColor3f(r, g, b);
            glNormal3f(nx, ny, nz);
            glVertex3f(x, y, z);

            phi = (float)i / (float)rings * 2.0f * (float)M_PI;
        }

        glEnd();
    }
}

void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;

    angle += rotationSpeed * seconds;
    if (angle >= 360.0f) angle -= 360.0f;

    colorHue += colorSpeed * seconds;
    if (colorHue >= 360.0f) colorHue -= 360.0f;
}

void Display(void)
{
    float lightPos[] = { 2.0f, 2.0f, 3.0f, 1.0f };

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    /* Camera position */
    glTranslatef(0.0f, 0.0f, -3.5f);
    glRotatef(20.0f, 1.0f, 0.0f, 0.0f);

    /* Rotate the torus */
    glRotatef(angle, 0.0f, 1.0f, 1.0f);

    /* Enable lighting for better look */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    /* Set light position */
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    /* Draw torus */
    DrawTorus(1.0f, 0.3f, 36, 24);

    glDisable(GL_LIGHTING);
}

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_Event         event;
    LDL_OpenGLLoader* loader;
    size_t            currentTime;
    size_t            delta;
    float matSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    float matShininess[] = { 50.0f };
    float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL - Rotating Colorful Torus (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);

        /* Enable features */
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_NORMALIZE);

        /* Set material properties */
        glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
        glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

        /* Set ambient light */
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

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
                UpdateAnimation(delta);
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