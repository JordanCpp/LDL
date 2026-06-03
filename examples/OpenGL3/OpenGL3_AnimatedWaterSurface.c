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

#define GRID_SIZE 64
#define GRID_STEP 0.12f
#define WAVE_SPEED 2.5f

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
"uniform float time;\n"
"void main()\n"
"{\n"
"    vec3 pos = aPos;\n"
"    pos.y += sin(pos.x * 1.5 + time * 2.0) * cos(pos.z * 1.5 + time * 1.5) * 0.15;\n"
"    pos.y += sin(pos.x * 3.0 - time * 3.0) * 0.08;\n"
"    pos.y += cos(pos.z * 2.5 + time * 2.2) * 0.08;\n"
"    pos.y += sin((pos.x + pos.z) * 2.0 + time * 2.8) * 0.06;\n"
"    FragPos = vec3(model * vec4(pos, 1.0));\n"
"    Normal = aNormal;\n"
"    gl_Position = projection * view * model * vec4(pos, 1.0);\n"
"}\n";

/* Fragment shader with water colors */
static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec3 FragPos;\n"
"in vec3 Normal;\n"
"out vec4 FragColor;\n"
"uniform vec3 viewPos;\n"
"uniform float time;\n"
"void main()\n"
"{\n"
"    float height = FragPos.y;\n"
"    vec3 lightPos = vec3(3.0, 5.0, 3.0);\n"
"    vec3 lightColor = vec3(1.0, 1.0, 1.0);\n"
"    float ambientStrength = 0.4;\n"
"    vec3 ambient = ambientStrength * lightColor;\n"
"    vec3 norm = normalize(Normal);\n"
"    vec3 lightDir = normalize(lightPos - FragPos);\n"
"    float diff = max(dot(norm, lightDir), 0.0);\n"
"    vec3 diffuse = diff * lightColor;\n"
"    float specularStrength = 0.6;\n"
"    vec3 viewDir = normalize(viewPos - FragPos);\n"
"    vec3 reflectDir = reflect(-lightDir, norm);\n"
"    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);\n"
"    vec3 specular = specularStrength * spec * lightColor;\n"
"    vec3 deepColor = vec3(0.0, 0.1, 0.4);\n"
"    vec3 shallowColor = vec3(0.2, 0.6, 0.8);\n"
"    vec3 waveColor = vec3(0.4, 0.8, 1.0);\n"
"    float t = (height + 0.5) / 1.0;\n"
"    t = clamp(t, 0.0, 1.0);\n"
"    vec3 baseColor = mix(deepColor, shallowColor, t);\n"
"    float wavePattern = sin(FragPos.x * 8.0 + time * 5.0) * cos(FragPos.z * 8.0 + time * 4.0);\n"
"    wavePattern = max(wavePattern, 0.0) * 0.5;\n"
"    vec3 color = baseColor + waveColor * wavePattern;\n"
"    vec3 result = (ambient + diffuse + specular) * color;\n"
"    FragColor = vec4(result, 0.9);\n"
"}\n";

static GLuint ShaderProgram;
static GLuint VAO, VBO, EBO;
static int indexCount = 0;
static float timeValue = 0.0f;
static size_t lastTime = 0;
static float cameraAngle = 0.0f;
static float cameraDist = 5.0f;
static float cameraHeight = 2.0f;

/* Generate water grid */
void GenerateWaterGrid(void)
{
    float* vertices;
    unsigned int* indices;
    int x, z;
    int vIndex = 0, iIndex = 0;
    int vertexCount = GRID_SIZE * GRID_SIZE * 6;
    int indexCountTotal = (GRID_SIZE - 1) * (GRID_SIZE - 1) * 6;

    vertices = (float*)malloc(vertexCount * sizeof(float));
    indices = (unsigned int*)malloc(indexCountTotal * sizeof(unsigned int));

    if (!vertices || !indices) return;

    /* Generate vertices */
    for (z = 0; z < GRID_SIZE; z++)
    {
        float fz = ((float)z - GRID_SIZE / 2.0f) * GRID_STEP;
        for (x = 0; x < GRID_SIZE; x++)
        {
            float fx = ((float)x - GRID_SIZE / 2.0f) * GRID_STEP;
            float y = 0.0f;

            /* Initial flat positions (animation in vertex shader) */
            vertices[vIndex++] = fx;
            vertices[vIndex++] = y;
            vertices[vIndex++] = fz;

            /* Normal (approximate, will be recalculated in shader) */
            vertices[vIndex++] = 0.0f;
            vertices[vIndex++] = 1.0f;
            vertices[vIndex++] = 0.0f;
        }
    }

    /* Generate indices */
    for (z = 0; z < GRID_SIZE - 1; z++)
    {
        for (x = 0; x < GRID_SIZE - 1; x++)
        {
            int topLeft = z * GRID_SIZE + x;
            int topRight = topLeft + 1;
            int bottomLeft = (z + 1) * GRID_SIZE + x;
            int bottomRight = bottomLeft + 1;

            indices[iIndex++] = topLeft;
            indices[iIndex++] = bottomLeft;
            indices[iIndex++] = topRight;

            indices[iIndex++] = topRight;
            indices[iIndex++] = bottomLeft;
            indices[iIndex++] = bottomRight;
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Normal attribute */
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    free(vertices);
    free(indices);
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

/* Initialize OpenGL */
void InitOpenGL(void)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    GenerateWaterGrid();
}

/* Render scene */
void Render(int width, int height)
{
    float model[16], view[16], projection[16];
    int modelLoc, viewLoc, projLoc, timeLoc, viewPosLoc;
    float aspect = (float)width / (float)height;
    float camX;
    float camZ;

    glClearColor(0.02f, 0.03f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);

    /* Model matrix */
    MatrixIdentity(model);

    /* View matrix (rotating around water) */
    camX = (float)sin(cameraAngle) * cameraDist;
    camZ = (float)cos(cameraAngle) * cameraDist;
    MatrixLookAt(view, camX, cameraHeight, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Projection matrix */
    MatrixPerspective(projection, 60.0f, aspect, 0.1f, 20.0f);

    glUseProgram(ShaderProgram);

    modelLoc = glGetUniformLocation(ShaderProgram, "model");
    viewLoc = glGetUniformLocation(ShaderProgram, "view");
    projLoc = glGetUniformLocation(ShaderProgram, "projection");
    timeLoc = glGetUniformLocation(ShaderProgram, "time");
    viewPosLoc = glGetUniformLocation(ShaderProgram, "viewPos");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection);
    glUniform1f(timeLoc, timeValue);
    glUniform3f(viewPosLoc, camX, cameraHeight, camZ);

    /* Draw water */
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

/* Update animation */
void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    timeValue += seconds * WAVE_SPEED;
    if (timeValue >= 360.0f) timeValue -= 360.0f;

    /* Slow camera rotation */
    cameraAngle += 8.0f * seconds;
    if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;
}

/* Cleanup */
void CleanupOpenGL(void)
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
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
        "LDL - Animated Water Surface (OpenGL 3.3)", LDL_WindowModeResized);

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

                        /* Mouse wheel zoom */
                        if (event.Type == LDL_EventIsMouseScroll)
                        {
                            cameraDist -= (float)event.u.Mouse.Delta / 100.0f;
                            if (cameraDist < 3.0f) cameraDist = 3.0f;
                            if (cameraDist > 10.0f) cameraDist = 10.0f;
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
