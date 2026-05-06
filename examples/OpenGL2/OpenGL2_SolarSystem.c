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

#define PLANET_COUNT 9
#define PARTICLE_COUNT 200

 /* Planet data */
typedef struct {
    float distance;
    float radius;
    float speed;
    float angle;
    float r, g, b;
    char name[10];
} Planet;

static Planet planets[] = {
    {1.8f, 0.12f, 45.0f, 0.0f, 0.7f, 0.5f, 0.3f, "Mercury"},
    {2.5f, 0.15f, 35.0f, 0.0f, 0.8f, 0.6f, 0.4f, "Venus"},
    {3.2f, 0.18f, 28.0f, 0.0f, 0.2f, 0.5f, 0.8f, "Earth"},
    {4.0f, 0.16f, 22.0f, 0.0f, 0.9f, 0.3f, 0.3f, "Mars"},
    {5.2f, 0.35f, 12.0f, 0.0f, 0.7f, 0.5f, 0.3f, "Jupiter"},
    {6.5f, 0.30f, 9.0f,  0.0f, 0.8f, 0.7f, 0.4f, "Saturn"},
    {7.8f, 0.25f, 7.0f,  0.0f, 0.5f, 0.6f, 0.8f, "Uranus"},
    {9.0f, 0.24f, 5.5f,  0.0f, 0.3f, 0.4f, 0.7f, "Neptune"},
    {10.5f, 0.10f, 3.8f, 0.0f, 0.6f, 0.5f, 0.4f, "Pluto"}
};

/* Particle system */
typedef struct {
    float x, y, z;
    float vx, vy, vz;
    float r, g, b;
    float life;
    int active;
} Particle;

static Particle particles[PARTICLE_COUNT];
static float particleTimer = 0.0f;

/* OpenGL buffers */
static GLuint sphereVBO, sphereEBO;
static GLuint particleVBO;
static int sphereIndexCount = 0;
static float cameraAngle = 0.0f;
static float cameraDist = 14.0f;
static size_t lastTime = 0;

/* Generate sphere mesh */
void GenerateSphere(float radius, int sectors, int stacks)
{
    float* vertices;
    unsigned int* indices;
    int i, j;
    int vIndex = 0, iIndex = 0;
    int vertexCount = (sectors + 1) * (stacks + 1) * 3;
    int indexCountTotal = sectors * stacks * 6;

    vertices = (float*)malloc(vertexCount * sizeof(float));
    indices = (unsigned int*)malloc(indexCountTotal * sizeof(unsigned int));

    if (!vertices || !indices) return;

    for (i = 0; i <= stacks; i++)
    {
        float phi = (float)i / (float)stacks * (float)M_PI;
        float sinPhi = (float)sin(phi);
        float cosPhi = (float)cos(phi);

        for (j = 0; j <= sectors; j++)
        {
            float theta = (float)j / (float)sectors * 2.0f * (float)M_PI;
            float sinTheta = (float)sin(theta);
            float cosTheta = (float)cos(theta);

            float x = radius * sinPhi * cosTheta;
            float y = radius * cosPhi;
            float z = radius * sinPhi * sinTheta;

            vertices[vIndex++] = x;
            vertices[vIndex++] = y;
            vertices[vIndex++] = z;
        }
    }

    for (i = 0; i < stacks; i++)
    {
        for (j = 0; j < sectors; j++)
        {
            int first = i * (sectors + 1) + j;
            int second = first + sectors + 1;

            indices[iIndex++] = first;
            indices[iIndex++] = second;
            indices[iIndex++] = first + 1;
            indices[iIndex++] = second;
            indices[iIndex++] = second + 1;
            indices[iIndex++] = first + 1;
        }
    }

    sphereIndexCount = iIndex;

    glGenBuffers(1, &sphereVBO);
    glGenBuffers(1, &sphereEBO);

    glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
    glBufferData(GL_ARRAY_BUFFER, vIndex * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sphereIndexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    free(vertices);
    free(indices);
}

/* Draw sphere with given color */
void DrawSphere(float r, float g, float b)
{
    glColor3f(r, g, b);

    glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereEBO);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glDrawElements(GL_TRIANGLES, sphereIndexCount, GL_UNSIGNED_INT, 0);

    glDisableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/* Initialize particles */
void InitParticles(void)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        particles[i].active = 0;
    }
}

/* Spawn particle at sun */
void SpawnParticle(void)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (!particles[i].active)
        {
            float angle1 = (float)(rand() % 360) * (float)M_PI / 180.0f;
            float angle2 = (float)(rand() % 360) * (float)M_PI / 180.0f;
            float speed = 1.5f + (float)(rand() % 100) / 100.0f;

            particles[i].x = 0.0f;
            particles[i].y = 0.0f;
            particles[i].z = 0.0f;
            particles[i].vx = (float)sin(angle1) * (float)cos(angle2) * speed;
            particles[i].vy = (float)sin(angle2) * speed;
            particles[i].vz = (float)cos(angle1) * (float)cos(angle2) * speed;
            particles[i].r = 1.0f;
            particles[i].g = 0.5f + (float)(rand() % 50) / 100.0f;
            particles[i].b = 0.2f;
            particles[i].life = 1.0f;
            particles[i].active = 1;
            break;
        }
    }
}

/* Update particles */
void UpdateParticles(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;
    float bound = 12.0f;

    particleTimer += seconds;
    if (particleTimer > 0.03f)
    {
        SpawnParticle();
        particleTimer = 0.0f;
    }

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (particles[i].active)
        {
            particles[i].x += particles[i].vx * seconds;
            particles[i].y += particles[i].vy * seconds;
            particles[i].z += particles[i].vz * seconds;
            particles[i].life -= seconds * 1.5f;

            if (particles[i].life <= 0.0f ||
                fabs(particles[i].x) > bound ||
                fabs(particles[i].z) > bound)
            {
                particles[i].active = 0;
            }
        }
    }
}

/* Create particle buffer */
void CreateParticleBuffer(void)
{
    glGenBuffers(1, &particleVBO);
    glBindBuffer(GL_ARRAY_BUFFER, particleVBO);
    glBufferData(GL_ARRAY_BUFFER, PARTICLE_COUNT * 6 * sizeof(float), NULL, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/* Update particle buffer */
void UpdateParticleBuffer(void)
{
    float* data;
    int i, vIndex = 0;

    data = (float*)malloc(PARTICLE_COUNT * 6 * sizeof(float));
    if (!data) return;

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (particles[i].active)
        {
            float brightness = particles[i].life;
            data[vIndex++] = particles[i].x;
            data[vIndex++] = particles[i].y;
            data[vIndex++] = particles[i].z;
            data[vIndex++] = particles[i].r * brightness;
            data[vIndex++] = particles[i].g * brightness;
            data[vIndex++] = particles[i].b * brightness;
        }
        else
        {
            data[vIndex++] = 0.0f;
            data[vIndex++] = -10.0f;
            data[vIndex++] = 0.0f;
            data[vIndex++] = 0.0f;
            data[vIndex++] = 0.0f;
            data[vIndex++] = 0.0f;
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, particleVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, PARTICLE_COUNT * 6 * sizeof(float), data);
    free(data);
}

/* Draw particles */
void DrawParticles(void)
{
    glBindBuffer(GL_ARRAY_BUFFER, particleVBO);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 6 * sizeof(float), 0);
    glColorPointer(3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/* Matrix functions */
void MatrixIdentity(float* m)
{
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f; m[5] = 1.0f; m[10] = 1.0f; m[15] = 1.0f;
}

void MatrixTranslate(float* m, float x, float y, float z)
{
    MatrixIdentity(m);
    m[12] = x;
    m[13] = y;
    m[14] = z;
}

void MatrixScale(float* m, float sx, float sy, float sz)
{
    MatrixIdentity(m);
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
}

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
    float tanHalfFov = (float)tan(fov / 360.0f * M_PI);
    int i;

    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f / (aspect * tanHalfFov);
    m[5] = 1.0f / tanHalfFov;
    m[10] = -(far + near) / (far - near);
    m[11] = -1.0f;
    m[14] = -(2.0f * far * near) / (far - near);

    glMultMatrixf(m);
}

/* Draw orbit circle */
void DrawOrbit(float radius)
{
    glColor3f(0.3f, 0.3f, 0.4f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 360; i += 15)
    {
        float rad = i * (float)M_PI / 180.0f;
        float x = radius * (float)cos(rad);
        float z = radius * (float)sin(rad);
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
}

void Resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GenerateSphere(0.18f, 36, 24);
    CreateParticleBuffer();
    InitParticles();
}

void Render(int width, int height)
{
    int i;
    float aspect = (float)width / (float)height;

    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    MatrixPerspective(50.0f, aspect, 0.1f, 30.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Camera */
    float camX = (float)sin(cameraAngle) * cameraDist;
    float camZ = (float)cos(cameraAngle) * cameraDist;
    MatrixLookAt(camX, 3.0f, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Draw orbits */
    for (i = 0; i < PLANET_COUNT; i++)
    {
        DrawOrbit(planets[i].distance);
    }

    /* Draw Sun */
    glPushMatrix();
    glScalef(0.9f, 0.9f, 0.9f);
    DrawSphere(1.0f, 0.8f, 0.2f);
    glPopMatrix();

    /* Draw planets */
    for (i = 0; i < PLANET_COUNT; i++)
    {
        float rad = planets[i].angle * (float)M_PI / 180.0f;
        float x = planets[i].distance * (float)sin(rad);
        float z = planets[i].distance * (float)cos(rad);

        glPushMatrix();
        glTranslatef(x, 0.0f, z);
        glScalef(planets[i].radius / 0.18f, planets[i].radius / 0.18f, planets[i].radius / 0.18f);
        DrawSphere(planets[i].r, planets[i].g, planets[i].b);
        glPopMatrix();
    }

    /* Draw particles */
    DrawParticles();
}

void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    int i;

    cameraAngle += 3.0f * seconds;
    if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;

    for (i = 0; i < PLANET_COUNT; i++)
    {
        planets[i].angle += planets[i].speed * seconds;
        if (planets[i].angle >= 360.0f) planets[i].angle -= 360.0f;
    }

    UpdateParticles(delta);
    UpdateParticleBuffer();
}

void CleanupOpenGL(void)
{
    glDeleteBuffers(1, &sphereVBO);
    glDeleteBuffers(1, &sphereEBO);
    glDeleteBuffers(1, &particleVBO);
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
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Solar System with Pluto (OpenGL 2.1)", LDL_WindowModeResized);

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
                        if (cameraDist < 9.0f) cameraDist = 9.0f;
                        if (cameraDist > 22.0f) cameraDist = 22.0f;
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
