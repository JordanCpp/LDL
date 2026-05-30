/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL3_3.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define PARTICLE_COUNT 500
#define GRAVITY -9.8f

typedef struct
{
    float x, y, z;
    float vx, vy, vz;
    float r, g, b;
    float size;
    float life;
    int active;
} Particle;

static Particle particles[PARTICLE_COUNT];
static GLuint ShaderProgram;
static GLuint VAO, VBO;
static size_t lastTime = 0;
static float cameraAngle = 0.0f;
static float cameraDist = 8.0f;

/* Vertex shader (instanced particles) */
static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 Color;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    Color = aColor;\n"
"    gl_Position = projection * view * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader */
static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec3 Color;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(Color, 1.0);\n"
"}\n";

/* Compile shader */
int CompileShader(GLuint shader, const char* source)
{
    GLint success;
    GLchar infoLog[512];
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Shader error: %s\n", infoLog);
        return 0;
    }
    return 1;
}

/* Create shader program */
int CreateShaderProgram(void)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    GLint success;
    GLchar infoLog[512];

    if (!CompileShader(vertexShader, vertexShaderSource)) return 0;
    if (!CompileShader(fragmentShader, fragmentShaderSource)) return 0;

    ShaderProgram = glCreateProgram();
    glAttachShader(ShaderProgram, vertexShader);
    glAttachShader(ShaderProgram, fragmentShader);
    glLinkProgram(ShaderProgram);

    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ShaderProgram, 512, NULL, infoLog);
        printf("Program error: %s\n", infoLog);
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return 1;
}

/* Initialize particles */
void InitParticles(void)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        particles[i].x = (float)(rand() % 200 - 100) / 10.0f;
        particles[i].y = (float)(rand() % 200) / 20.0f;
        particles[i].z = (float)(rand() % 200 - 100) / 10.0f;
        particles[i].vx = (float)(rand() % 100 - 50) / 20.0f;
        particles[i].vy = (float)(rand() % 100) / 10.0f + 2.0f;
        particles[i].vz = (float)(rand() % 100 - 50) / 20.0f;
        particles[i].r = (float)(rand() % 100) / 100.0f;
        particles[i].g = (float)(rand() % 100) / 100.0f;
        particles[i].b = (float)(rand() % 100) / 100.0f;
        particles[i].size = 0.05f + (float)(rand() % 50) / 500.0f;
        particles[i].life = 1.0f;
        particles[i].active = 1;
    }
}

/* Update particles with physics */
void UpdateParticles(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;
    float bound = 6.0f;

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (!particles[i].active) continue;

        /* Apply gravity */
        particles[i].vy += GRAVITY * seconds;

        /* Update position */
        particles[i].x += particles[i].vx * seconds;
        particles[i].y += particles[i].vy * seconds;
        particles[i].z += particles[i].vz * seconds;

        /* Reduce life */
        particles[i].life -= seconds * 0.5f;

        /* Collision with ground (y = -2.0) */
        if (particles[i].y < -2.0f)
        {
            particles[i].y = -2.0f;
            particles[i].vy = -particles[i].vy * 0.5f;
            particles[i].life -= 0.3f;

            /* Change color on bounce */
            particles[i].r = (float)(rand() % 100) / 100.0f;
            particles[i].g = (float)(rand() % 100) / 100.0f;
        }

        /* Collision with walls */
        if (fabs(particles[i].x) > bound)
        {
            particles[i].x = (particles[i].x > 0) ? bound : -bound;
            particles[i].vx = -particles[i].vx * 0.8f;
        }
        if (fabs(particles[i].z) > bound)
        {
            particles[i].z = (particles[i].z > 0) ? bound : -bound;
            particles[i].vz = -particles[i].vz * 0.8f;
        }

        /* Respawn dead particles */
        if (particles[i].life <= 0.0f || particles[i].y < -3.0f)
        {
            particles[i].x = (float)(rand() % 200 - 100) / 10.0f;
            particles[i].y = 4.0f;
            particles[i].z = (float)(rand() % 200 - 100) / 10.0f;
            particles[i].vx = (float)(rand() % 100 - 50) / 20.0f;
            particles[i].vy = (float)(rand() % 100) / 8.0f + 3.0f;
            particles[i].vz = (float)(rand() % 100 - 50) / 20.0f;
            particles[i].r = (float)(rand() % 100) / 100.0f;
            particles[i].g = (float)(rand() % 100) / 100.0f;
            particles[i].b = (float)(rand() % 100) / 100.0f;
            particles[i].size = 0.05f + (float)(rand() % 50) / 500.0f;
            particles[i].life = 1.0f;
        }
    }
}

/* Setup particle buffer */
void CreateParticleBuffer(void)
{
    float* vertexData;
    int dataSize = PARTICLE_COUNT * 6; /* xyz + rgb */

    vertexData = (float*)malloc(dataSize * sizeof(float));
    if (!vertexData) return;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dataSize * sizeof(float), NULL, GL_DYNAMIC_DRAW);

    /* Position attribute */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Color attribute */
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    free(vertexData);
}

/* Update particle buffer data */
void UpdateParticleBuffer(void)
{
    float* vertexData;
    int i;
    int dataSize = PARTICLE_COUNT * 6;
    int vIndex = 0;

    vertexData = (float*)malloc(dataSize * sizeof(float));
    if (!vertexData) return;

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (particles[i].active)
        {
            vertexData[vIndex++] = particles[i].x;
            vertexData[vIndex++] = particles[i].y;
            vertexData[vIndex++] = particles[i].z;
            vertexData[vIndex++] = particles[i].r;
            vertexData[vIndex++] = particles[i].g;
            vertexData[vIndex++] = particles[i].b;
        }
        else
        {
            /* Inactive particles at origin */
            vertexData[vIndex++] = 0.0f;
            vertexData[vIndex++] = -10.0f;
            vertexData[vIndex++] = 0.0f;
            vertexData[vIndex++] = 0.0f;
            vertexData[vIndex++] = 0.0f;
            vertexData[vIndex++] = 0.0f;
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, dataSize * sizeof(float), vertexData);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    free(vertexData);
}

/* Matrix functions */
void MatrixIdentity(float* m)
{
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f; m[5] = 1.0f; m[10] = 1.0f; m[15] = 1.0f;
}

void MatrixLookAt(float* m, float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ)
{
    float f[3], s[3], u[3], len;
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
}

void MatrixPerspective(float* m, float fov, float aspect, float near, float far)
{
    float tanHalfFov = (float)tan(fov / 360.0f * (float)M_PI);
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f / (aspect * tanHalfFov);
    m[5] = 1.0f / tanHalfFov;
    m[10] = -(far + near) / (far - near);
    m[11] = -1.0f;
    m[14] = -(2.0f * far * near) / (far - near);
}

void MatrixRotateY(float* m, float angleDeg)
{
    float rad = angleDeg * (float)M_PI / 180.0f;
    float c = (float)cos(rad), s = (float)sin(rad);
    MatrixIdentity(m);
    m[0] = c; m[2] = s;
    m[8] = -s; m[10] = c;
}

/* Initialize OpenGL */
void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glPointSize(4.0f);

    CreateParticleBuffer();
    InitParticles();
}

/* Render scene */
void Render(int width, int height)
{
    float view[16], projection[16];
    float rot[16];
    int viewLoc, projLoc;
    float aspect = (float)width / (float)height;

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);

    /* View matrix (rotating camera) */
    MatrixRotateY(rot, cameraAngle);
    float eyeX = (float)sin(cameraAngle * (float)M_PI / 180.0f) * cameraDist;
    float eyeZ = (float)cos(cameraAngle * (float)M_PI / 180.0f) * cameraDist;
    MatrixLookAt(view, eyeX, 2.0f, eyeZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Projection matrix */
    MatrixPerspective(projection, 60.0f, aspect, 0.1f, 50.0f);

    glUseProgram(ShaderProgram);

    viewLoc = glGetUniformLocation(ShaderProgram, "view");
    projLoc = glGetUniformLocation(ShaderProgram, "projection");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection);

    /* Draw particles as points */
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);
    glBindVertexArray(0);
}

/* Cleanup */
void CleanupOpenGL(void)
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(ShaderProgram);
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
    context = LDL_ContextNew(LDL_ContextOpenGLModern);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height),
        "LDL - Particle System (OpenGL 3.3)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 3, 3);

        if (LDL_ResultIsOk(result))
        {
            InitOpenGL();

            if (CreateShaderProgram())
            {
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
                        }
                    }

                    currentTime = LDL_Ticks();
                    delta = currentTime - lastTime;
                    lastTime = currentTime;

                    if (delta > 0 && delta < 100)
                    {
                        cameraAngle += 20.0f * ((float)delta / 1000.0f);
                        if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;

                        UpdateParticles(delta);
                        UpdateParticleBuffer();
                    }

                    Render(width, height);
                    LDL_WindowPresent(window);
                    LDL_Delay(16);
                }

                CleanupOpenGL();
            }
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
