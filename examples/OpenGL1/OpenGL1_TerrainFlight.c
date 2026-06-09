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

#define MAP_SIZE 32
#define MAP_STEP 0.5f

static float heightmap[MAP_SIZE][MAP_SIZE];
static float cameraAngle = 0.0f;
static float cameraDistance = 12.0f;
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

    Perspective(70.0, aspect, 0.1, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void LookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ)
{
    float forwardX, forwardY, forwardZ;
    float sideX, sideY, sideZ;
    float upVectorX, upVectorY, upVectorZ;
    float length;
    float mat[16];

    forwardX = centerX - eyeX;
    forwardY = centerY - eyeY;
    forwardZ = centerZ - eyeZ;

    length = (float)sqrt(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);
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

    length = (float)sqrt(sideX * sideX + sideY * sideY + sideZ * sideZ);
    if (length != 0.0f)
    {
        sideX /= length;
        sideY /= length;
        sideZ /= length;
    }

    upVectorX = sideY * forwardZ - sideZ * forwardY;
    upVectorY = sideZ * forwardX - sideX * forwardZ;
    upVectorZ = sideX * forwardY - sideY * forwardX;


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

void GenerateHeightmap(void)
{
    int x, z, fx, fz;

    for (x = 0; x < MAP_SIZE; x++)
    {
        for (z = 0; z < MAP_SIZE; z++)
        {
            fx = (int)((float)x / (float)MAP_SIZE * 8.0f);
            fz = (int)((float)z / (float)MAP_SIZE * 8.0f);

            heightmap[x][z] = (float)sin((float)fx * 1.2f) * (float)cos((float)fz * 1.2f) * 1.2f;
        }
    }
}

void DrawTerrain(void)
{
    int x, z;
    float h;

    for (x = 0; x < MAP_SIZE - 1; x++)
    {
        glBegin(GL_TRIANGLE_STRIP);

        for (z = 0; z < MAP_SIZE; z++)
        {
            h = heightmap[x][z];
            glColor3f(0.3f, 0.5f + h * 0.15f, 0.2f);
            glVertex3f(
                (float)(x - MAP_SIZE / 2) * MAP_STEP,
                h,
                (float)(z - MAP_SIZE / 2) * MAP_STEP
            );

            h = heightmap[x + 1][z];
            glColor3f(0.3f, 0.5f + h * 0.15f, 0.2f);
            glVertex3f(
                (float)(x + 1 - MAP_SIZE / 2) * MAP_STEP,
                h,
                (float)(z - MAP_SIZE / 2) * MAP_STEP
            );
        }

        glEnd();
    }
}

void DrawGrid(void)
{
    int i;

    glColor3f(0.15f, 0.25f, 0.1f);
    glBegin(GL_LINES);

    for (i = -MAP_SIZE / 2; i <= MAP_SIZE / 2; i += 2)
    {
        glVertex3f((float)i, -0.1f, (float)(-MAP_SIZE / 2));
        glVertex3f((float)i, -0.1f, (float)(MAP_SIZE / 2));
        glVertex3f((float)(-MAP_SIZE / 2), -0.1f, (float)i);
        glVertex3f((float)(MAP_SIZE / 2), -0.1f, (float)i);
    }

    glEnd();
}

void DrawSky(void)
{
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.15f, 0.25f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glColor3f(0.25f, 0.35f, 0.55f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void DrawFPS(void)
{
    int width = 800;
    int height = 600;
    int f = (int)fps;
    int digits[3] = { f / 100, (f / 10) % 10, f % 10 };
    int i;
    int val;


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
    glVertex2f((float)width, 0.0f);
    glVertex2f((float)width, 20.0f);
    glVertex2f(0.0f, 20.0f);
    glEnd();

    for (i = 0; i < 3; i++)
    {
        val = digits[i];

        if (val < 0) val = 0;
        if (val > 9) val = 9;

        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(10.0f + i * 15.0f, 5.0f);
        glVertex2f(10.0f + i * 15.0f + val * 2.0f, 5.0f);
        glVertex2f(10.0f + i * 15.0f + val * 2.0f, 15.0f);
        glVertex2f(10.0f + i * 15.0f, 15.0f);
        glEnd();
    }

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
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
    size_t            currentTime, delta;
    float             timeAccum = 0.0f;
    float rad;
    float camX;
    float camZ;
    float camY;

    result = LDL_ResultCreate();
    context = LDL_ContextCreate(result, LDL_ContextOpenGLLegacy);
    window = LDL_WindowCreate(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Terrain Flight (OpenGL 1.2)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 1, 2);
        glEnable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);

        GenerateHeightmap();

        lastTime = LDL_Ticks();
        lastFpsTime = lastTime;
        Resize(width, height);

        while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
        {
            while (LDL_WindowGetEvent(window, &event))
            {
                if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                    LDL_WindowStopEvent(window);
                if (event.Type == LDL_EventIsResize)
                    Resize((int)event.u.Resize.Width, (int)event.u.Resize.Height);
            }

            currentTime = LDL_Ticks();
            delta = currentTime - lastTime;
            lastTime = currentTime;

            if (delta > 0 && delta < 100)
            {
                /* Плавное накопление времени */
                timeAccum += (float)delta / 1000.0f;
                if (timeAccum > 10.0f) timeAccum -= 10.0f;

                /* Плавное изменение угла */
                cameraAngle = timeAccum * 30.0f;
                if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;
            }

            UpdateFPS();

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glLoadIdentity();

            /* Плавные координаты камеры */
            rad = cameraAngle * (float)M_PI / 180.0f;
            camX = (float)sin(rad) * cameraDistance;
            camZ = (float)cos(rad) * cameraDistance;
            camY = 4.0f + (float)sin(rad * 0.5f) * 1.5f;

            /* Камера смотрит на центр */
            LookAt(camX, camY, camZ, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

            DrawSky();
            DrawTerrain();
            DrawGrid();
            DrawFPS();

            LDL_WindowPresent(window);
            LDL_Delay(16);
        }

        LDL_OpenGLLoaderFree(loader);
    }

    LDL_ContextDestroy(context);
    LDL_WindowDestroy(window);
    LDL_ResultDestroy(result);

    if (LDL_ResultIsFail(result))
        printf("LDL error: %s\n", LDL_ResultGetMessage(result));

    return 0;
}