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

#define PARTICLE_COUNT 300
#define TORUS_SPEED 12.0f

 /* Vertex shader for torus */
static const char* torusVertexShader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aNormal;\n"
"layout (location = 2) in vec3 aColor;\n"
"out vec3 FragPos;\n"
"out vec3 Normal;\n"
"out vec3 Color;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    FragPos = vec3(model * vec4(aPos, 1.0));\n"
"    Normal = mat3(transpose(inverse(model))) * aNormal;\n"
"    Color = aColor;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader for torus */
static const char* torusFragmentShader =
"#version 330 core\n"
"in vec3 FragPos;\n"
"in vec3 Normal;\n"
"in vec3 Color;\n"
"out vec4 FragColor;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 viewPos;\n"
"void main()\n"
"{\n"
"    vec3 lightColor = vec3(1.0, 1.0, 1.0);\n"
"    float ambientStrength = 0.3;\n"
"    vec3 ambient = ambientStrength * lightColor;\n"
"    vec3 norm = normalize(Normal);\n"
"    vec3 lightDir = normalize(lightPos - FragPos);\n"
"    float diff = max(dot(norm, lightDir), 0.0);\n"
"    vec3 diffuse = diff * lightColor;\n"
"    float specularStrength = 0.5;\n"
"    vec3 viewDir = normalize(viewPos - FragPos);\n"
"    vec3 reflectDir = reflect(-lightDir, norm);\n"
"    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);\n"
"    vec3 specular = specularStrength * spec * lightColor;\n"
"    vec3 result = (ambient + diffuse + specular) * Color;\n"
"    FragColor = vec4(result, 1.0);\n"
"}\n";

/* Vertex shader for particles */
static const char* particleVertexShader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 Color;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    Color = aColor;\n"
"    gl_PointSize = 5.0;\n"
"    gl_Position = projection * view * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader for particles */
static const char* particleFragmentShader =
"#version 330 core\n"
"in vec3 Color;\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(Color, 1.0);\n"
"}\n";

typedef struct
{
    float x, y, z;
    float vx, vy, vz;
    float r, g, b;
    float life;
    int active;
} Particle;

static Particle particles[PARTICLE_COUNT];
static GLuint torusProgram, particleProgram;
static GLuint torusVAO, torusVBO, torusEBO;
static GLuint particleVAO, particleVBO;
static int torusIndexCount = 0;
static float angle = 0.0f;
static float particleTimer = 0.0f;
static size_t lastTime = 0;

/* Generate torus */
void GenerateTorus(float radius, float tubeRadius, int rings, int sides)
{
    float* vertices;
    unsigned int* indices;
    int i, j;
    int vertexCount = (rings + 1) * (sides + 1) * 9;
    int vIndex = 0, iIndex = 0;

    vertices = (float*)malloc(vertexCount * sizeof(float));
    indices = (unsigned int*)malloc(rings * sides * 6 * sizeof(unsigned int));

    if (!vertices || !indices) return;

    for (i = 0; i <= rings; i++)
    {
        float phi = (float)i / (float)rings * 2.0f * (float)M_PI;
        float cosPhi = (float)cos(phi);
        float sinPhi = (float)sin(phi);

        for (j = 0; j <= sides; j++)
        {
            float theta = (float)j / (float)sides * 2.0f * (float)M_PI;
            float cosTheta = (float)cos(theta);
            float sinTheta = (float)sin(theta);

            float x = (radius + tubeRadius * cosTheta) * cosPhi;
            float y = (radius + tubeRadius * cosTheta) * sinPhi;
            float z = tubeRadius * sinTheta;

            float nx = cosPhi * cosTheta;
            float ny = sinPhi * cosTheta;
            float nz = sinTheta;

            float r = 0.5f + 0.5f * (float)sin(phi + theta);
            float g = 0.5f + 0.5f * (float)sin(phi + theta + 2.0f);
            float b = 0.5f + 0.5f * (float)sin(phi + theta + 4.0f);

            vertices[vIndex++] = x;
            vertices[vIndex++] = y;
            vertices[vIndex++] = z;
            vertices[vIndex++] = nx;
            vertices[vIndex++] = ny;
            vertices[vIndex++] = nz;
            vertices[vIndex++] = r;
            vertices[vIndex++] = g;
            vertices[vIndex++] = b;
        }
    }

    for (i = 0; i < rings; i++)
    {
        for (j = 0; j < sides; j++)
        {
            int first = i * (sides + 1) + j;
            int second = (i + 1) * (sides + 1) + j;

            indices[iIndex++] = first;
            indices[iIndex++] = second;
            indices[iIndex++] = first + 1;

            indices[iIndex++] = second;
            indices[iIndex++] = second + 1;
            indices[iIndex++] = first + 1;
        }
    }

    torusIndexCount = iIndex;

    glGenVertexArrays(1, &torusVAO);
    glGenBuffers(1, &torusVBO);
    glGenBuffers(1, &torusEBO);

    glBindVertexArray(torusVAO);
    glBindBuffer(GL_ARRAY_BUFFER, torusVBO);
    glBufferData(GL_ARRAY_BUFFER, vIndex * sizeof(float), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, torusEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, torusIndexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
    free(vertices);
    free(indices);
}

/* Init particles */
void InitParticles(void)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        particles[i].active = 0;
        particles[i].life = 0.0f;
    }
}

/* Spawn particle at center of torus */
void SpawnParticle(float cx, float cy, float cz)
{
    int i;
    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (!particles[i].active)
        {
            particles[i].x = cx;
            particles[i].y = cy;
            particles[i].z = cz;
            particles[i].vx = (float)(rand() % 200 - 100) / 40.0f;
            particles[i].vy = (float)(rand() % 100) / 30.0f + 1.5f;
            particles[i].vz = (float)(rand() % 200 - 100) / 40.0f;
            particles[i].r = (float)(rand() % 100) / 100.0f;
            particles[i].g = (float)(rand() % 100) / 100.0f;
            particles[i].b = (float)(rand() % 100) / 100.0f;
            particles[i].life = 1.0f;
            particles[i].active = 1;
            break;
        }
    }
}

/* Update particles */
void UpdateParticles(size_t delta, float cx, float cy, float cz)
{
    int i;
    float seconds = (float)delta / 1000.0f;

    particleTimer += seconds;
    if (particleTimer > 0.05f)
    {
        SpawnParticle(cx, cy, cz);
        particleTimer = 0.0f;
    }

    for (i = 0; i < PARTICLE_COUNT; i++)
    {
        if (particles[i].active)
        {
            particles[i].x += particles[i].vx * seconds;
            particles[i].y += particles[i].vy * seconds;
            particles[i].z += particles[i].vz * seconds;
            particles[i].life -= seconds * 2.0f;

            if (particles[i].life <= 0.0f || particles[i].y > 3.0f)
            {
                particles[i].active = 0;
            }
        }
    }
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
            data[vIndex++] = particles[i].x;
            data[vIndex++] = particles[i].y;
            data[vIndex++] = particles[i].z;
            data[vIndex++] = particles[i].r;
            data[vIndex++] = particles[i].g;
            data[vIndex++] = particles[i].b;
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

/* Create particle buffer */
void CreateParticleBuffer(void)
{
    glGenVertexArrays(1, &particleVAO);
    glGenBuffers(1, &particleVBO);

    glBindVertexArray(particleVAO);
    glBindBuffer(GL_ARRAY_BUFFER, particleVBO);
    glBufferData(GL_ARRAY_BUFFER, PARTICLE_COUNT * 6 * sizeof(float), NULL, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

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
int CreateProgram(GLuint* program, const char* vert, const char* frag)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    GLint success;
    GLchar infoLog[512];

    if (!CompileShader(vertexShader, vert)) return 0;
    if (!CompileShader(fragmentShader, frag)) return 0;

    *program = glCreateProgram();
    glAttachShader(*program, vertexShader);
    glAttachShader(*program, fragmentShader);
    glLinkProgram(*program);

    glGetProgramiv(*program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(*program, 512, NULL, infoLog);
        printf("Program error: %s\n", infoLog);
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return 1;
}

/* Matrix functions */
void MatrixIdentity(float* m)
{
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f; m[5] = 1.0f; m[10] = 1.0f; m[15] = 1.0f;
}

void MatrixRotateY(float* m, float angleDeg)
{
    float rad = angleDeg * (float)M_PI / 180.0f;
    float c = (float)cos(rad), s = (float)sin(rad);
    MatrixIdentity(m);
    m[0] = c; m[2] = s;
    m[8] = -s; m[10] = c;
}

void MatrixRotateX(float* m, float angleDeg)
{
    float rad = angleDeg * (float)M_PI / 180.0f;
    float c = (float)cos(rad), s = (float)sin(rad);
    MatrixIdentity(m);
    m[5] = c; m[6] = s;
    m[9] = -s; m[10] = c;
}

void MatrixRotateZ(float* m, float angleDeg)
{
    float rad = angleDeg * (float)M_PI / 180.0f;
    float c = (float)cos(rad), s = (float)sin(rad);
    MatrixIdentity(m);
    m[0] = c; m[1] = -s;
    m[4] = s; m[5] = c;
}

void MatrixMultiply(float* result, float* a, float* b)
{
    float temp[16];
    int i, j, k;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            temp[i * 4 + j] = 0.0f;
            for (k = 0; k < 4; k++)
                temp[i * 4 + j] += a[i * 4 + k] * b[k * 4 + j];
        }
    for (i = 0; i < 16; i++) result[i] = temp[i];
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
    float tanHalfFov = (float)tan(fov / 360.0f * M_PI);
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f / (aspect * tanHalfFov);
    m[5] = 1.0f / tanHalfFov;
    m[10] = -(far + near) / (far - near);
    m[11] = -1.0f;
    m[14] = -(2.0f * far * near) / (far - near);
}

/* Initialize OpenGL */
void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_PROGRAM_POINT_SIZE);

    GenerateTorus(0.8f, 0.25f, 48, 24);
    InitParticles();
    CreateParticleBuffer();
}

/* Render */
void Render(int width, int height)
{
    float model[16], view[16], projection[16];
    float rotY[16], rotX[16], rotZ[16], temp[16];
    float aspect = (float)width / (float)height;

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);

    /* Camera */
    MatrixLookAt(view, 2.0f, 1.5f, 3.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    MatrixPerspective(projection, 45.0f, aspect, 0.1f, 20.0f);

    /* Draw Torus */
    MatrixRotateY(rotY, angle);
    MatrixRotateX(rotX, (float)sin(angle * 1.5f) * 30.0f);
    MatrixRotateZ(rotZ, (float)cos(angle * 0.8f) * 20.0f);
    MatrixMultiply(temp, rotY, rotX);
    MatrixMultiply(model, temp, rotZ);

    glUseProgram(torusProgram);
    glUniformMatrix4fv(glGetUniformLocation(torusProgram, "model"), 1, GL_FALSE, model);
    glUniformMatrix4fv(glGetUniformLocation(torusProgram, "view"), 1, GL_FALSE, view);
    glUniformMatrix4fv(glGetUniformLocation(torusProgram, "projection"), 1, GL_FALSE, projection);
    glUniform3f(glGetUniformLocation(torusProgram, "lightPos"), 2.0f, 3.0f, 2.0f);
    glUniform3f(glGetUniformLocation(torusProgram, "viewPos"), 2.0f, 1.5f, 3.5f);

    glBindVertexArray(torusVAO);
    glDrawElements(GL_TRIANGLES, torusIndexCount, GL_UNSIGNED_INT, 0);

    /* Draw Particles */
    glUseProgram(particleProgram);
    glUniformMatrix4fv(glGetUniformLocation(particleProgram, "view"), 1, GL_FALSE, view);
    glUniformMatrix4fv(glGetUniformLocation(particleProgram, "projection"), 1, GL_FALSE, projection);

    glBindVertexArray(particleVAO);
    glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);

    glBindVertexArray(0);
}

/* Update */
void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    angle += TORUS_SPEED * seconds;
    if (angle >= 360.0f) angle -= 360.0f;

    /* Center of torus (0,0,0) + dancing offset */
    float cx = (float)sin(angle * 1.5f) * 0.2f;
    float cy = (float)cos(angle * 0.8f) * 0.2f;
    float cz = (float)sin(angle) * 0.1f;

    UpdateParticles(delta, cx, cy + 0.2f, cz);
    UpdateParticleBuffer();
}

/* Cleanup */
void CleanupOpenGL(void)
{
    glDeleteVertexArrays(1, &torusVAO);
    glDeleteBuffers(1, &torusVBO);
    glDeleteBuffers(1, &torusEBO);
    glDeleteVertexArrays(1, &particleVAO);
    glDeleteBuffers(1, &particleVBO);
    glDeleteProgram(torusProgram);
    glDeleteProgram(particleProgram);
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
        "LDL - Dancing Torus with Particles", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 3, 3);

        if (LDL_ResultIsOk(result))
        {
            InitOpenGL();

            if (CreateProgram(&torusProgram, torusVertexShader, torusFragmentShader) &&
                CreateProgram(&particleProgram, particleVertexShader, particleFragmentShader))
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
                        UpdateAnimation(delta);
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