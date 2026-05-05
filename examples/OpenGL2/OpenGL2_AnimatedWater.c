/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL2_1.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define GRID_SIZE 64
#define GRID_STEP 0.15f
#define WATER_HEIGHT -0.5f

 /* Vertex data for water */
static float waterVertices[GRID_SIZE * GRID_SIZE * 3];
static unsigned int waterIndices[(GRID_SIZE - 1) * (GRID_SIZE - 1) * 6];
static int waterIndexCount = 0;

/* Island vertices (simple cone) */
static float islandVertices[100 * 3];
static unsigned int islandIndices[100 * 3];
static int islandIndexCount = 0;

/* Skybox vertices */
static float skyVertices[8 * 3];
static unsigned int skyIndices[12 * 3];
static int skyIndexCount = 0;

/* OpenGL buffers */
static GLuint waterVBO, waterEBO;
static GLuint islandVBO, islandEBO;
static GLuint skyVBO, skyEBO;

static float timeValue = 0.0f;
static float cameraAngle = 0.0f;
static float cameraDist = 5.0f;
static size_t lastTime = 0;

/* Generate water grid */
void GenerateWaterGrid(void)
{
    int x, z;
    int vIndex = 0, iIndex = 0;

    for (z = 0; z < GRID_SIZE; z++)
    {
        float fz = ((float)z - GRID_SIZE / 2.0f) * GRID_STEP;

        for (x = 0; x < GRID_SIZE; x++)
        {
            float fx = ((float)x - GRID_SIZE / 2.0f) * GRID_STEP;

            waterVertices[vIndex++] = fx;
            waterVertices[vIndex++] = WATER_HEIGHT;
            waterVertices[vIndex++] = fz;
        }
    }

    for (z = 0; z < GRID_SIZE - 1; z++)
    {
        for (x = 0; x < GRID_SIZE - 1; x++)
        {
            int topLeft = z * GRID_SIZE + x;
            int topRight = topLeft + 1;
            int bottomLeft = (z + 1) * GRID_SIZE + x;
            int bottomRight = bottomLeft + 1;

            waterIndices[iIndex++] = topLeft;
            waterIndices[iIndex++] = bottomLeft;
            waterIndices[iIndex++] = topRight;
            waterIndices[iIndex++] = topRight;
            waterIndices[iIndex++] = bottomLeft;
            waterIndices[iIndex++] = bottomRight;
        }
    }

    waterIndexCount = iIndex;

    glGenBuffers(1, &waterVBO);
    glGenBuffers(1, &waterEBO);

    glBindBuffer(GL_ARRAY_BUFFER, waterVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(waterVertices), waterVertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, waterEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, waterIndexCount * sizeof(unsigned int), waterIndices, GL_STATIC_DRAW);
}

/* Generate island (simple mountain) */
void GenerateIsland(void)
{
    float vertices[100 * 3];
    unsigned int indices[100 * 3];
    int vIndex = 0, iIndex = 0;
    int i, j;
    float radius = 2.0f;
    float height = 1.2f;
    int rings = 20;
    int sectors = 20;

    /* Center top */
    vertices[vIndex++] = 0.0f;
    vertices[vIndex++] = height;
    vertices[vIndex++] = 0.0f;

    /* Rings */
    for (i = 1; i <= rings; i++)
    {
        float r = radius * (float)i / (float)rings;
        float y = height * (1.0f - (float)i / (float)rings);

        for (j = 0; j < sectors; j++)
        {
            float angle = (float)j / (float)sectors * 2.0f * (float)M_PI;
            float x = r * (float)cos(angle);
            float z = r * (float)sin(angle);

            vertices[vIndex++] = x;
            vertices[vIndex++] = y;
            vertices[vIndex++] = z;
        }
    }

    /* Bottom ring (ground) */
    for (j = 0; j < sectors; j++)
    {
        float angle = (float)j / (float)sectors * 2.0f * (float)M_PI;
        float x = radius * (float)cos(angle);
        float z = radius * (float)sin(angle);

        vertices[vIndex++] = x;
        vertices[vIndex++] = -0.2f;
        vertices[vIndex++] = z;
    }

    /* Indices for triangles */
    int vertexCount = 1 + rings * sectors + sectors;

    /* Top to first ring */
    for (j = 0; j < sectors; j++)
    {
        int next = (j + 1) % sectors;
        indices[iIndex++] = 0;
        indices[iIndex++] = 1 + j;
        indices[iIndex++] = 1 + next;
    }

    /* Between rings */
    for (i = 0; i < rings - 1; i++)
    {
        for (j = 0; j < sectors; j++)
        {
            int next = (j + 1) % sectors;
            int currentRing = 1 + i * sectors + j;
            int nextRing = 1 + (i + 1) * sectors + j;

            indices[iIndex++] = currentRing;
            indices[iIndex++] = nextRing;
            indices[iIndex++] = nextRing + 1;

            indices[iIndex++] = currentRing;
            indices[iIndex++] = nextRing + 1;
            indices[iIndex++] = currentRing + 1;
        }
    }

    /* Last ring to bottom */
    int lastRingStart = 1 + (rings - 1) * sectors;
    int bottomStart = 1 + rings * sectors;

    for (j = 0; j < sectors; j++)
    {
        int next = (j + 1) % sectors;
        indices[iIndex++] = lastRingStart + j;
        indices[iIndex++] = bottomStart + j;
        indices[iIndex++] = bottomStart + next;
    }

    islandIndexCount = iIndex;

    glGenBuffers(1, &islandVBO);
    glGenBuffers(1, &islandEBO);

    glBindBuffer(GL_ARRAY_BUFFER, islandVBO);
    glBufferData(GL_ARRAY_BUFFER, vIndex * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, islandEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, islandIndexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    /* Copy to global for rendering */
    memcpy(islandVertices, vertices, vIndex * sizeof(float));
    memcpy(islandIndices, indices, islandIndexCount * sizeof(unsigned int));
}

/* Generate skybox */
void GenerateSkybox(void)
{
    float size = 8.0f;
    int vIndex = 0, iIndex = 0;

    /* 8 corners */
    float vertices[] = {
        -size, -size, -size,
         size, -size, -size,
         size, -size,  size,
        -size, -size,  size,
        -size,  size, -size,
         size,  size, -size,
         size,  size,  size,
        -size,  size,  size
    };

    unsigned int indices[] = {
        /* Bottom */
        0, 2, 1, 0, 3, 2,
        /* Top */
        4, 5, 6, 4, 6, 7,
        /* Front */
        0, 1, 5, 0, 5, 4,
        /* Back */
        3, 6, 2, 3, 7, 6,
        /* Left */
        0, 4, 7, 0, 7, 3,
        /* Right */
        1, 2, 6, 1, 6, 5
    };

    memcpy(skyVertices, vertices, sizeof(vertices));
    memcpy(skyIndices, indices, sizeof(indices));

    skyIndexCount = 36;

    glGenBuffers(1, &skyVBO);
    glGenBuffers(1, &skyEBO);

    glBindBuffer(GL_ARRAY_BUFFER, skyVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, skyEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

/* Draw island */
void DrawIsland(void)
{
    glColor3f(0.3f, 0.5f, 0.2f);

    glBindBuffer(GL_ARRAY_BUFFER, islandVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, islandEBO);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glDrawElements(GL_TRIANGLES, islandIndexCount, GL_UNSIGNED_INT, 0);

    glDisableClientState(GL_VERTEX_ARRAY);
}

/* Draw skybox */
void DrawSkybox(void)
{
    glDepthMask(GL_FALSE);
    glDisable(GL_DEPTH_TEST);

    glColor3f(0.3f, 0.5f, 0.7f);

    glBindBuffer(GL_ARRAY_BUFFER, skyVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, skyEBO);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glDrawElements(GL_TRIANGLES, skyIndexCount, GL_UNSIGNED_INT, 0);

    glDisableClientState(GL_VERTEX_ARRAY);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
}

/* Draw water with wave animation */
void DrawWater(float time)
{
    int x, z;
    float waveHeight;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    for (z = 0; z < GRID_SIZE - 1; z++)
    {
        glBegin(GL_TRIANGLE_STRIP);

        for (x = 0; x < GRID_SIZE; x++)
        {
            float fx = ((float)x - GRID_SIZE / 2.0f) * GRID_STEP;
            float fz = ((float)z - GRID_SIZE / 2.0f) * GRID_STEP;
            float fx2 = ((float)x - GRID_SIZE / 2.0f) * GRID_STEP;
            float fz2 = ((float)(z + 1) - GRID_SIZE / 2.0f) * GRID_STEP;

            /* Wave calculation */
            waveHeight = WATER_HEIGHT;
            waveHeight += (float)sin(fx * 1.8f + time * 3.0f) * 0.08f;
            waveHeight += (float)cos(fz * 1.6f + time * 2.5f) * 0.08f;
            waveHeight += (float)sin((fx + fz) * 2.2f + time * 4.0f) * 0.05f;
            waveHeight += (float)sin(fx * 3.5f - time * 5.0f) * 0.04f;

            /* Color based on wave height */
            float brightness = 0.5f + waveHeight * 1.0f;
            float r = 0.2f;
            float g = 0.5f + waveHeight * 0.5f;
            float b = 0.8f + waveHeight * 0.2f;
            float alpha = 0.85f;

            if (waveHeight > WATER_HEIGHT + 0.1f)
            {
                r = 0.5f;
                g = 0.8f;
                b = 1.0f;
            }

            glColor4f(r, g, b, alpha);
            glVertex3f(fx, waveHeight, fz);

            float waveHeight2 = WATER_HEIGHT;
            waveHeight2 += (float)sin(fx2 * 1.8f + time * 3.0f) * 0.08f;
            waveHeight2 += (float)cos(fz2 * 1.6f + time * 2.5f) * 0.08f;
            waveHeight2 += (float)sin((fx2 + fz2) * 2.2f + time * 4.0f) * 0.05f;
            waveHeight2 += (float)sin(fx2 * 3.5f - time * 5.0f) * 0.04f;

            float brightness2 = 0.5f + waveHeight2 * 1.0f;
            float r2 = 0.2f;
            float g2 = 0.5f + waveHeight2 * 0.5f;
            float b2 = 0.8f + waveHeight2 * 0.2f;

            if (waveHeight2 > WATER_HEIGHT + 0.1f)
            {
                r2 = 0.5f;
                g2 = 0.8f;
                b2 = 1.0f;
            }

            glColor4f(r2, g2, b2, alpha);
            glVertex3f(fx2, waveHeight2, fz2);
        }

        glEnd();
    }

    glDisable(GL_BLEND);
}

/* Draw reflection (simple mirror) */
void DrawReflection(float time, float eyeY)
{
    glPushMatrix();
    glScalef(1.0f, -1.0f, 1.0f);
    glTranslatef(0.0f, -2.0f * WATER_HEIGHT, 0.0f);
    glColor4f(0.3f, 0.5f, 0.7f, 0.4f);
    DrawWater(time);
    glPopMatrix();
}

/* Draw sun */
void DrawSun(float time)
{
    float sunX = 3.0f * (float)sin(time * 0.5f);
    float sunY = 3.0f;
    float sunZ = 3.0f * (float)cos(time * 0.5f);

    glDisable(GL_DEPTH_TEST);

    glPushMatrix();
    glTranslatef(sunX, sunY, sunZ);

    /* Sun glow */
    for (int i = 0; i < 3; i++)
    {
        float size = 0.3f + i * 0.1f;
        float alpha = 0.3f - i * 0.1f;
        glColor4f(1.0f, 0.8f, 0.2f, alpha);

        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 0.0f);
        for (int a = 0; a <= 360; a += 30)
        {
            float rad = a * (float)M_PI / 180.0f;
            glVertex3f(size * (float)cos(rad), size * (float)sin(rad), 0.0f);
        }
        glEnd();
    }

    glPopMatrix();

    glEnable(GL_DEPTH_TEST);
}

/* Matrix functions */
void MatrixLookAt(float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ)
{
    float f[3], s[3], u[3], len;
    float m[16];

    f[0] = centerX - eyeX;
    f[1] = centerY - eyeY;
    f[2] = centerZ - eyeZ;
    len = (float)sqrt(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
    if (len != 0.0f) { f[0] /= len; f[1] /= len; f[2] /= len; }

    s[0] = f[1] * upZ - f[2] * upY;
    s[1] = f[2] * upX - f[0] * upZ;
    s[2] = f[0] * upY - f[1] * upX;
    len = (float)sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
    if (len != 0.0f) { s[0] /= len; s[1] /= len; s[2] /= len; }

    u[0] = s[1] * f[2] - s[2] * f[1];
    u[1] = s[2] * f[0] - s[0] * f[2];
    u[2] = s[0] * f[1] - s[1] * f[0];

    m[0] = s[0]; m[1] = u[0]; m[2] = -f[0]; m[3] = 0.0f;
    m[4] = s[1]; m[5] = u[1]; m[6] = -f[1]; m[7] = 0.0f;
    m[8] = s[2]; m[9] = u[2]; m[10] = -f[2]; m[11] = 0.0f;
    m[12] = -(s[0] * eyeX + s[1] * eyeY + s[2] * eyeZ);
    m[13] = -(u[0] * eyeX + u[1] * eyeY + u[2] * eyeZ);
    m[14] = f[0] * eyeX + f[1] * eyeY + f[2] * eyeZ;
    m[15] = 1.0f;

    glMultMatrixf(m);
}

void MatrixPerspective(float fov, float aspect, float near, float far)
{
    float m[16];
    float tanHalfFov = (float)tan(fov / 360.0f * (float)M_PI);
    int i;

    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f / (aspect * tanHalfFov);
    m[5] = 1.0f / tanHalfFov;
    m[10] = -(far + near) / (far - near);
    m[11] = -1.0f;
    m[14] = -(2.0f * far * near) / (far - near);

    glMultMatrixf(m);
}

void Resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GenerateWaterGrid();
    GenerateIsland();
    GenerateSkybox();
}

void Render(int width, int height)
{
    float aspect = (float)width / (float)height;

    glClearColor(0.3f, 0.5f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    MatrixPerspective(60.0f, aspect, 0.1f, 30.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Camera (rotating around island) */
    float camX = (float)sin(cameraAngle) * cameraDist;
    float camZ = (float)cos(cameraAngle) * cameraDist;
    MatrixLookAt(camX, 2.0f, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Draw skybox first */
    DrawSkybox();

    /* Draw island */
    DrawIsland();

    /* Draw reflection */
    DrawReflection(timeValue, 2.0f);

    /* Draw water on top */
    DrawWater(timeValue);

    /* Draw sun */
    DrawSun(timeValue);
}

void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    timeValue += seconds;
    if (timeValue >= 360.0f) timeValue -= 360.0f;

    cameraAngle += 12.0f * seconds;
    if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;
}

void CleanupOpenGL(void)
{
    glDeleteBuffers(1, &waterVBO);
    glDeleteBuffers(1, &waterEBO);
    glDeleteBuffers(1, &islandVBO);
    glDeleteBuffers(1, &islandEBO);
    glDeleteBuffers(1, &skyVBO);
    glDeleteBuffers(1, &skyEBO);
}

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_Event         event;
    LDL_OpenGLLoader* loader;
    int               width = 800, height = 600;
    size_t            currentTime, delta;

    result = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Animated Water with Reflection (OpenGL 2.1)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 2, 1);

        if (LDL_ResultIsOk(result))
        {
            InitOpenGL();
            lastTime = LDL_Ticks();

            while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
            {
                while (LDL_WindowGetEvent(window, &event))
                {
                    if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                        LDL_WindowStopEvent(window);

                    if (event.Type == LDL_EventIsResize)
                    {
                        width = (int)event.u.Resize.Width;
                        height = (int)event.u.Resize.Height;
                        Resize(width, height);
                    }

                    if (event.Type == LDL_EventIsMouseScroll)
                    {
                        cameraDist -= (float)event.u.Mouse.Delta / 80.0f;
                        if (cameraDist < 3.0f) cameraDist = 3.0f;
                        if (cameraDist > 8.0f) cameraDist = 8.0f;
                    }
                }

                currentTime = LDL_Ticks();
                delta = currentTime - lastTime;
                lastTime = currentTime;

                if (delta > 0 && delta < 100)
                {
                    UpdateAnimation(delta);
                }

                Render(width, height);
                LDL_WindowPresent(window);
                LDL_Delay(16);
            }

            CleanupOpenGL();
        }

        LDL_OpenGLLoaderFree(loader);
        LDL_WindowFree(window);
        LDL_ContextFree(context);
        LDL_ResultFree(result);
    }

    if (LDL_ResultIsFail(result))
    {
        printf("LDL error: %s\n", LDL_ResultGetMessage(result));
    }

    return 0;
}
