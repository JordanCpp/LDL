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

 /* Vertex shader */
static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    TexCoord = aTexCoord;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader with texture */
static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec2 TexCoord;\n"
"out vec4 FragColor;\n"
"uniform sampler2D ourTexture;\n"
"void main()\n"
"{\n"
"    FragColor = texture(ourTexture, TexCoord);\n"
"}\n";

static GLuint ShaderProgram;
static GLuint VAO, VBO, EBO;
static GLuint textureID;
static int indexCount = 0;
static float angle = 0.0f;
static size_t lastTime = 0;

/* Generate sphere vertices with texture coordinates */
void GenerateSphere(float radius, int sectors, int stacks)
{
    float* vertices;
    unsigned int* indices;
    int i, j;
    int vertexCount = (sectors + 1) * (stacks + 1) * 5; /* xyz + uv */
    int vIndex = 0, iIndex = 0;

    vertices = (float*)malloc(vertexCount * sizeof(float));
    indices = (unsigned int*)malloc(sectors * stacks * 6 * sizeof(unsigned int));

    if (!vertices || !indices) return;

    /* Generate vertices */
    for (i = 0; i <= stacks; i++)
    {
        float phi = (float)i / (float)stacks * (float)M_PI;
        float sinPhi = (float)sin(phi);
        float cosPhi = (float)cos(phi);
        float v = 1.0f - (float)i / (float)stacks;

        for (j = 0; j <= sectors; j++)
        {
            float theta = (float)j / (float)sectors * 2.0f * (float)M_PI;
            float sinTheta = (float)sin(theta);
            float cosTheta = (float)cos(theta);
            float u = (float)j / (float)sectors;

            float x = radius * sinPhi * cosTheta;
            float y = radius * cosPhi;
            float z = radius * sinPhi * sinTheta;

            vertices[vIndex++] = x;
            vertices[vIndex++] = y;
            vertices[vIndex++] = z;
            vertices[vIndex++] = u;
            vertices[vIndex++] = v;
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

    indexCount = iIndex;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vIndex * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    /* Position attribute */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* TexCoord attribute */
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    free(vertices);
    free(indices);
}

/* Create checkerboard texture procedurally */
void CreateCheckerTexture(void)
{
    int width = 256;
    int height = 256;
    unsigned char* data;
    int x, y;

    data = (unsigned char*)malloc(width * height * 3);
    if (!data) return;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            int cx = (x / 32) % 2;
            int cy = (y / 32) % 2;
            int isWhite = (cx == cy);

            data[(y * width + x) * 3 + 0] = isWhite ? 255 : 100;  /* R */
            data[(y * width + x) * 3 + 1] = isWhite ? 200 : 50;   /* G */
            data[(y * width + x) * 3 + 2] = isWhite ? 100 : 200;  /* B */
        }
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    free(data);
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

    GenerateSphere(0.8f, 48, 32);
    CreateCheckerTexture();
}

/* Render scene */
void Render(int width, int height)
{
    float model[16], view[16], projection[16];
    float rotX[16], rotY[16];
    int modelLoc, viewLoc, projLoc;
    float aspect = (float)width / (float)height;

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);

    /* Model matrix (rotation around Y and X) */
    MatrixRotateY(rotY, angle);
    MatrixRotateX(rotX, angle * 0.5f);
    MatrixMultiply(model, rotY, rotX);

    /* View matrix */
    MatrixLookAt(view, 0.0f, 0.0f, 2.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Projection matrix */
    MatrixPerspective(projection, 45.0f, aspect, 0.1f, 100.0f);

    glUseProgram(ShaderProgram);

    modelLoc = glGetUniformLocation(ShaderProgram, "model");
    viewLoc = glGetUniformLocation(ShaderProgram, "view");
    projLoc = glGetUniformLocation(ShaderProgram, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection);

    /* Bind texture */
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glUniform1i(glGetUniformLocation(ShaderProgram, "ourTexture"), 0);

    /* Draw sphere */
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

/* Cleanup */
void CleanupOpenGL(void)
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteTextures(1, &textureID);
    glDeleteProgram(ShaderProgram);
}

/* Update animation */
void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    angle += 45.0f * seconds;
    if (angle >= 360.0f) angle -= 360.0f;
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
        "LDL - Textured Sphere (OpenGL 3.3)", LDL_WindowModeResized);

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
