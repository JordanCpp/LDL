/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL2_1.h>
#include <LDL/OpenGL/GLLoad.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

 /* Vertex shader (GLSL 1.20) */
static const char* vertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"attribute vec3 aColor;\n"
"varying vec3 Color;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    Color = aColor;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader (GLSL 1.20) */
static const char* fragmentShaderSource =
"#version 120\n"
"varying vec3 Color;\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(Color, 1.0);\n"
"}\n";

/* Cube vertices (8 corners) */
static float vertices[] = {
    /* positions        colors */
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, /* 0 front bottom left */
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, /* 1 front bottom right */
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, /* 2 front top right */
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, /* 3 front top left */

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, /* 4 back bottom left */
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, /* 5 back bottom right */
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, /* 6 back top right */
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, /* 7 back top left */

     0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, /* 8 right bottom back */
     0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, /* 9 right top back */
     0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, /* 10 right top front */
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, /* 11 right bottom front */

    -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, /* 12 left bottom back */
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, /* 13 left top back */
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, /* 14 left top front */
    -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f, /* 15 left bottom front */

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, /* 16 top back left */
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, /* 17 top back right */
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, /* 18 top front right */
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 1.0f, /* 19 top front left */

    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f, /* 20 bottom back left */
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f, /* 21 bottom back right */
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, /* 22 bottom front right */
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f  /* 23 bottom front left */
};

/* Indices for 6 faces * 2 triangles = 36 indices */
static unsigned int indices[] = {
    0,1,2, 2,3,0,      /* front */
    4,5,6, 6,7,4,      /* back */
    8,9,10, 10,11,8,   /* right */
    12,13,14, 14,15,12, /* left */
    16,17,18, 18,19,16, /* top */
    20,21,22, 22,23,20  /* bottom */
};

static GLuint shaderProgram;
static GLuint vbo, ebo;
static GLuint attrPos, attrColor;
static GLuint uniModel, uniView, uniProjection;
static float angle = 0.0f;
static size_t lastTime = 0;

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

void MatrixPerspective(float* m, float fov, float aspect, float nearV, float farV)
{
    float tanHalfFov = (float)tan(fov / 360.0f * M_PI);
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f / (aspect * tanHalfFov);
    m[5] = 1.0f / tanHalfFov;
    m[10] = -(farV + nearV) / (farV - nearV);
    m[11] = -1.0f;
    m[14] = -(2.0f * farV * nearV) / (farV - nearV);
}

/* Shader compilation */
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

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("Program error: %s\n", infoLog);
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    /* Get attribute and uniform locations */
    attrPos = glGetAttribLocation(shaderProgram, "aPos");
    attrColor = glGetAttribLocation(shaderProgram, "aColor");
    uniModel = glGetUniformLocation(shaderProgram, "model");
    uniView = glGetUniformLocation(shaderProgram, "view");
    uniProjection = glGetUniformLocation(shaderProgram, "projection");

    return 1;
}

/* Setup VBO for OpenGL 2.1 (no VAO) */
void CreateBuffers(void)
{
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    /* Enable vertex attributes (OpenGL 2.1 style) */
    glEnableVertexAttribArray(attrPos);
    glEnableVertexAttribArray(attrColor);

    glVertexAttribPointer(attrPos, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(attrColor, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    CreateBuffers();
}

void Render(int width, int height)
{
    float model[16], view[16], projection[16];
    float rotX[16], rotY[16];
    float aspect = (float)width / (float)height;

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Model matrix */
    MatrixRotateY(rotY, angle);
    MatrixRotateX(rotX, angle * 0.7f);
    MatrixMultiply(model, rotY, rotX);

    /* View matrix */
    MatrixLookAt(view, 2.0f, 1.5f, 3.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Projection matrix */
    MatrixPerspective(projection, 45.0f, aspect, 0.1f, 100.0f);

    glUseProgram(shaderProgram);

    glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);
    glUniformMatrix4fv(uniView, 1, GL_FALSE, view);
    glUniformMatrix4fv(uniProjection, 1, GL_FALSE, projection);

    /* Bind buffers and draw */
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    /* Re-enable attributes (in case they were disabled) */
    glEnableVertexAttribArray(attrPos);
    glEnableVertexAttribArray(attrColor);

    glVertexAttribPointer(attrPos, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(attrColor, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    angle += 45.0f * seconds;
    if (angle >= 360.0f) angle -= 360.0f;
}

void CleanupOpenGL(void)
{
    glDisableVertexAttribArray(attrPos);
    glDisableVertexAttribArray(attrColor);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteProgram(shaderProgram);
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
    context = LDL_ContextNew(result, LDL_ContextOpenGLLegacy);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Shader Cube (OpenGL 2.1)", LDL_WindowModeResized);

    if (LDL_ResultIsOk(result))
    {
        loader = LDL_OpenGLLoaderNew(result, 2, 1);

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
                            Resize(width, height);
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
