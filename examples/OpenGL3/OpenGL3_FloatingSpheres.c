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

#define SPHERE_COUNT 16

 /* Speed constants */
#define CAMERA_SPEED     5.0f   /* Camera rotation speed (was 20) */
#define SPHERE_BOUNCE_H  0.9f   /* Horizontal bounce damping */
#define SPHERE_BOUNCE_V  0.8f   /* Vertical bounce damping */
#define SPHERE_SPEED_MIN 2.0f   /* Minimum rotation speed (was 20) */
#define SPHERE_SPEED_MAX 15.0f  /* Maximum rotation speed (was 80) */

/* Vertex shader */
static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aNormal;\n"
"out vec3 FragPos;\n"
"out vec3 Normal;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    FragPos = vec3(model * vec4(aPos, 1.0));\n"
"    Normal = mat3(transpose(inverse(model))) * aNormal;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader with lighting */
static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec3 FragPos;\n"
"in vec3 Normal;\n"
"out vec4 FragColor;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 viewPos;\n"
"uniform vec3 objectColor;\n"
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
"    vec3 result = (ambient + diffuse + specular) * objectColor;\n"
"    FragColor = vec4(result, 1.0);\n"
"}\n";

typedef struct
{
    float x, y, z;
    float vx, vy, vz;
    float r, g, b;
    float angle;
    float speed;
} FloatingSphere;

static FloatingSphere spheres[SPHERE_COUNT];
static GLuint VAO, VBO, EBO, ShaderProgram;
static GLuint sphereVAO, sphereVBO, sphereEBO;
static int sphereIndexCount = 0;
static float lightX = 2.0f, lightY = 3.0f, lightZ = 2.0f;
static float cameraAngle = 0.0f;
static size_t lastTime = 0;

/* Generate sphere vertices */
void GenerateSphere(float radius, int sectors, int stacks)
{
    float* vertices;
    unsigned int* indices;
    int i, j;
    int vertexCount = (sectors + 1) * (stacks + 1) * 6;
    int indexCount = sectors * stacks * 6;
    int vIndex = 0, iIndex = 0;
    float x, y, z, nx, ny, nz;
    float length;

    vertices = (float*)malloc(vertexCount * sizeof(float));
    indices = (unsigned int*)malloc(indexCount * sizeof(unsigned int));

    /* Generate vertices */
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

            x = radius * sinPhi * cosTheta;
            y = radius * cosPhi;
            z = radius * sinPhi * sinTheta;

            nx = x;
            ny = y;
            nz = z;
            length = (float)sqrt(nx * nx + ny * ny + nz * nz);
            if (length != 0.0f)
            {
                nx /= length;
                ny /= length;
                nz /= length;
            }

            vertices[vIndex++] = x;
            vertices[vIndex++] = y;
            vertices[vIndex++] = z;
            vertices[vIndex++] = nx;
            vertices[vIndex++] = ny;
            vertices[vIndex++] = nz;
        }
    }

    /* Generate indices */
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

    sphereIndexCount = indexCount;

    glGenVertexArrays(1, &sphereVAO);
    glGenBuffers(1, &sphereVBO);
    glGenBuffers(1, &sphereEBO);

    glBindVertexArray(sphereVAO);

    glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    /* Position attribute */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Normal attribute */
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    free(vertices);
    free(indices);
}

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

void InitSpheres(void)
{
    int i;
    for (i = 0; i < SPHERE_COUNT; i++)
    {
        spheres[i].x = (float)(rand() % 200 - 100) / 20.0f;
        spheres[i].y = (float)(rand() % 100) / 20.0f;
        spheres[i].z = (float)(rand() % 200 - 100) / 20.0f;
        spheres[i].vx = (float)(rand() % 100 - 50) / 200.0f;
        spheres[i].vy = (float)(rand() % 100) / 100.0f + 0.3f;
        spheres[i].vz = (float)(rand() % 100 - 50) / 200.0f;
        spheres[i].r = (float)(rand() % 100) / 100.0f;
        spheres[i].g = (float)(rand() % 100) / 100.0f;
        spheres[i].b = (float)(rand() % 100) / 100.0f;
        spheres[i].angle = (float)(rand() % 360);
        spheres[i].speed = SPHERE_SPEED_MIN + (float)(rand() % (int)(SPHERE_SPEED_MAX - SPHERE_SPEED_MIN));
    }
}

void DrawSphere(float x, float y, float z, float r, float g, float b)
{
    float model[16];
    int modelLoc, colorLoc, lightPosLoc, viewPosLoc;
    int i;

    /* Model matrix */
    for (i = 0; i < 16; i++) model[i] = 0.0f;
    model[0] = 0.15f; model[5] = 0.15f; model[10] = 0.15f; model[15] = 1.0f;
    model[12] = x;
    model[13] = y;
    model[14] = z;

    glUseProgram(ShaderProgram);

    modelLoc = glGetUniformLocation(ShaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);

    colorLoc = glGetUniformLocation(ShaderProgram, "objectColor");
    glUniform3f(colorLoc, r, g, b);

    lightPosLoc = glGetUniformLocation(ShaderProgram, "lightPos");
    glUniform3f(lightPosLoc, lightX, lightY, lightZ);

    viewPosLoc = glGetUniformLocation(ShaderProgram, "viewPos");
    glUniform3f(viewPosLoc, 0.0f, 1.5f, 5.0f);

    glBindVertexArray(sphereVAO);
    glDrawElements(GL_TRIANGLES, sphereIndexCount, GL_UNSIGNED_INT, 0);
}

void UpdateSpheres(size_t delta)
{
    int i;
    float seconds = (float)delta / 1000.0f;
    float bound = 4.5f;

    for (i = 0; i < SPHERE_COUNT; i++)
    {
        spheres[i].x += spheres[i].vx * seconds;
        spheres[i].y += spheres[i].vy * seconds;
        spheres[i].z += spheres[i].vz * seconds;
        spheres[i].angle += spheres[i].speed * seconds;

        /* Bounce off walls (horizontal) */
        if (spheres[i].x > bound) { spheres[i].x = bound; spheres[i].vx = -spheres[i].vx * SPHERE_BOUNCE_H; }
        if (spheres[i].x < -bound) { spheres[i].x = -bound; spheres[i].vx = -spheres[i].vx * SPHERE_BOUNCE_H; }
        if (spheres[i].z > bound) { spheres[i].z = bound; spheres[i].vz = -spheres[i].vz * SPHERE_BOUNCE_H; }
        if (spheres[i].z < -bound) { spheres[i].z = -bound; spheres[i].vz = -spheres[i].vz * SPHERE_BOUNCE_H; }

        /* Bounce off floor and ceiling (vertical) */
        if (spheres[i].y > 3.5f) { spheres[i].y = 3.5f; spheres[i].vy = -spheres[i].vy * SPHERE_BOUNCE_V; }
        if (spheres[i].y < 0.3f) { spheres[i].y = 0.3f; spheres[i].vy = -spheres[i].vy * SPHERE_BOUNCE_V; }

        /* Change color on floor bounce */
        if (spheres[i].y < 0.35f && spheres[i].vy < 0)
        {
            spheres[i].r = (float)(rand() % 100) / 100.0f;
            spheres[i].g = (float)(rand() % 100) / 100.0f;
            spheres[i].b = (float)(rand() % 100) / 100.0f;
        }
    }

    /* Move light */
    lightX = 2.0f * (float)sin(cameraAngle);
    lightZ = 2.0f * (float)cos(cameraAngle);
}

void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    GenerateSphere(0.15f, 24, 16);
}

void Render(int width, int height)
{
    int i;
    float view[16], projection[16];
    int viewLoc, projLoc;
    float aspect = (float)width / (float)height;
    float camX;
    float camZ;
    float camY;
    float forward[3];
    float len;
    float right[3];
    float up[3];
    float realUp[3];
    float tanHalfFov;

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);

    /* View matrix (rotating camera) */
    for (i = 0; i < 16; i++) view[i] = 0.0f;
    view[0] = 1.0f; view[5] = 1.0f; view[10] = 1.0f; view[15] = 1.0f;

    /* Simple look from rotating point */
    camX = (float)sin(cameraAngle) * 6.0f;
    camZ = (float)cos(cameraAngle) * 6.0f;
    camY = 2.5f;

    forward[0] = -camX;
    forward[1] = -camY;
    forward[2] = -camZ;

    len = (float)sqrt(forward[0] * forward[0] + forward[1] * forward[1] + forward[2] * forward[2]);
    if (len != 0.0f) { forward[0] /= len; forward[1] /= len; forward[2] /= len; }

    right[3];
    up[0] = 0.0f;
    up[1] = 1.0f;
    up[2] = 0.0f;

    right[0] = forward[1] * up[2] - forward[2] * up[1];
    right[1] = forward[2] * up[0] - forward[0] * up[2];
    right[2] = forward[0] * up[1] - forward[1] * up[0];
    len = (float)sqrt(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]);
    if (len != 0.0f) { right[0] /= len; right[1] /= len; right[2] /= len; }

    realUp[0] = right[1] * forward[2] - right[2] * forward[1];
    realUp[1] = right[2] * forward[0] - right[0] * forward[2];
    realUp[2] = right[0] * forward[1] - right[1] * forward[0];

    view[0] = right[0]; view[1] = realUp[0]; view[2] = -forward[0];
    view[4] = right[1]; view[5] = realUp[1]; view[6] = -forward[1];
    view[8] = right[2]; view[9] = realUp[2]; view[10] = -forward[2];
    view[12] = -(right[0] * camX + right[1] * camY + right[2] * camZ);
    view[13] = -(realUp[0] * camX + realUp[1] * camY + realUp[2] * camZ);
    view[14] = forward[0] * camX + forward[1] * camY + forward[2] * camZ;

    /* Projection matrix */
    for (i = 0; i < 16; i++) projection[i] = 0.0f;
    tanHalfFov = (float)tan(45.0f / 360.0f * M_PI);
    projection[0] = 1.0f / (aspect * tanHalfFov);
    projection[5] = 1.0f / tanHalfFov;
    projection[10] = -(10.1f) / (9.9f);
    projection[11] = -1.0f;
    projection[14] = -(2.0f * 10.0f * 0.1f) / (9.9f);

    glUseProgram(ShaderProgram);

    viewLoc = glGetUniformLocation(ShaderProgram, "view");
    projLoc = glGetUniformLocation(ShaderProgram, "projection");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection);

    /* Draw all spheres */
    for (i = 0; i < SPHERE_COUNT; i++)
    {
        DrawSphere(spheres[i].x, spheres[i].y, spheres[i].z,
            spheres[i].r, spheres[i].g, spheres[i].b);
    }
}

void CleanupOpenGL(void)
{
    glDeleteVertexArrays(1, &sphereVAO);
    glDeleteBuffers(1, &sphereVBO);
    glDeleteBuffers(1, &sphereEBO);
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
    context = LDL_ContextNew(result, LDL_ContextOpenGLModern);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height),
        "LDL - Floating Spheres (OpenGL 3.3)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 3, 3);

        if (LDL_ResultIsOk(result))
        {
            InitOpenGL();

            if (CreateShaderProgram())
            {
                InitSpheres();
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
                        cameraAngle += CAMERA_SPEED * ((float)delta / 1000.0f);
                        if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;
                        UpdateSpheres(delta);
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
