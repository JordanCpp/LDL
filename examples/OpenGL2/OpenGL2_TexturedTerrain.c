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

#define TERRAIN_SIZE 64
#define TERRAIN_STEP 0.15f

 /* Vertex shader (GLSL 1.20) */
static const char* vertexShaderSource =
"#version 120\n"
"attribute vec3 aPos;\n"
"attribute vec2 aTexCoord;\n"
"varying vec2 TexCoord;\n"
"varying vec3 FragPos;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    FragPos = vec3(model * vec4(aPos, 1.0));\n"
"    TexCoord = aTexCoord;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader (GLSL 1.20) */
static const char* fragmentShaderSource =
"#version 120\n"
"varying vec2 TexCoord;\n"
"varying vec3 FragPos;\n"
"uniform sampler2D grassTexture;\n"
"uniform sampler2D rockTexture;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 viewPos;\n"
"uniform float time;\n"
"void main()\n"
"{\n"
"    vec3 lightColor = vec3(1.0, 1.0, 1.0);\n"
"    float ambientStrength = 0.4;\n"
"    float specularStrength = 0.3;\n"
"    vec4 texColor = texture2D(grassTexture, TexCoord);\n"
"    vec4 rockColor = texture2D(rockTexture, TexCoord * 2.0);\n"
"    float slope = abs(dFdx(FragPos.y)) + abs(dFdy(FragPos.y));\n"
"    slope = clamp(slope * 5.0, 0.0, 1.0);\n"
"    vec4 finalColor = mix(texColor, rockColor, slope);\n"
"    vec3 normal = normalize(cross(dFdx(FragPos), dFdy(FragPos)));\n"
"    vec3 lightDir = normalize(lightPos - FragPos);\n"
"    float diff = max(dot(normal, lightDir), 0.2);\n"
"    vec3 viewDir = normalize(viewPos - FragPos);\n"
"    vec3 reflectDir = reflect(-lightDir, normal);\n"
"    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16.0) * specularStrength;\n"
"    vec3 ambient = ambientStrength * lightColor;\n"
"    vec3 diffuse = diff * lightColor;\n"
"    float fogDensity = 0.08;\n"
"    float dist = length(viewPos - FragPos);\n"
"    float fogFactor = exp(-pow(dist * fogDensity, 2.0));\n"
"    fogFactor = clamp(fogFactor, 0.2, 1.0);\n"
"    vec3 fogColor = vec3(0.5, 0.6, 0.7);\n"
"    vec3 color = (ambient + diffuse + spec) * finalColor.rgb;\n"
"    color = mix(fogColor, color, fogFactor);\n"
"    gl_FragColor = vec4(color, 1.0);\n"
"}\n";

static float terrain[TERRAIN_SIZE][TERRAIN_SIZE];
static GLuint shaderProgram;
static GLuint vbo, ebo;
static GLuint grassTexture, rockTexture;
static GLuint attrPos, attrTexCoord;
static GLuint uniModel, uniView, uniProjection, uniLightPos, uniViewPos, uniTime;
static int indexCount = 0;
static float angle = 0.0f;
static float cameraDist = 6.0f;
static size_t lastTime = 0;

/* Generate terrain heights */
void GenerateTerrain(void)
{
    int x, z;

    for (z = 0; z < TERRAIN_SIZE; z++)
    {
        for (x = 0; x < TERRAIN_SIZE; x++)
        {
            float fx = (float)x / TERRAIN_SIZE * 8.0f;
            float fz = (float)z / TERRAIN_SIZE * 8.0f;

            float h = 0.0f;
            h += sin(fx * 1.2f) * cos(fz * 1.2f) * 0.8f;
            h += sin(fx * 2.5f) * 0.3f;
            h += cos(fz * 2.2f) * 0.3f;
            h += sin((fx + fz) * 1.5f) * 0.2f;

            terrain[x][z] = h;
        }
    }
}

/* Create procedural textures */
void CreateProceduralTextures(void)
{
    int width = 256;
    int height = 256;
    unsigned char* data;
    int x, y;

    data = (unsigned char*)malloc(width * height * 3);
    if (!data) return;

    /* Grass texture */
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            int r = 50 + (x + y) % 80;
            int g = 100 + (x * 2 + y) % 100;
            int b = 30 + (x + y * 2) % 60;
            data[(y * width + x) * 3 + 0] = (unsigned char)r;
            data[(y * width + x) * 3 + 1] = (unsigned char)g;
            data[(y * width + x) * 3 + 2] = (unsigned char)b;
        }
    }

    glGenTextures(1, &grassTexture);
    glBindTexture(GL_TEXTURE_2D, grassTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    /* Rock texture (reusing same data buffer) */
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            int gray = 80 + (x * y) % 100;
            data[(y * width + x) * 3 + 0] = (unsigned char)(gray + 20);
            data[(y * width + x) * 3 + 1] = (unsigned char)(gray);
            data[(y * width + x) * 3 + 2] = (unsigned char)(gray - 20);
        }
    }

    glGenTextures(1, &rockTexture);
    glBindTexture(GL_TEXTURE_2D, rockTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    free(data);
}

/* Create terrain buffers */
void CreateTerrainBuffers(void)
{
    float* vertices;
    unsigned int* indices;
    int x, z;
    int vIndex = 0, iIndex = 0;
    int vertexCount = TERRAIN_SIZE * TERRAIN_SIZE * 5;
    int indexCountTotal = (TERRAIN_SIZE - 1) * (TERRAIN_SIZE - 1) * 6;

    vertices = (float*)malloc(vertexCount * sizeof(float));
    indices = (unsigned int*)malloc(indexCountTotal * sizeof(unsigned int));

    if (!vertices || !indices) return;

    /* Generate vertices */
    for (z = 0; z < TERRAIN_SIZE; z++)
    {
        float fz = ((float)z - TERRAIN_SIZE / 2.0f) * TERRAIN_STEP;
        float tz = (float)z / TERRAIN_SIZE;

        for (x = 0; x < TERRAIN_SIZE; x++)
        {
            float fx = ((float)x - TERRAIN_SIZE / 2.0f) * TERRAIN_STEP;
            float tx = (float)x / TERRAIN_SIZE;
            float y = terrain[x][z];

            vertices[vIndex++] = fx;
            vertices[vIndex++] = y;
            vertices[vIndex++] = fz;
            vertices[vIndex++] = tx;
            vertices[vIndex++] = tz;
        }
    }

    /* Generate indices */
    for (z = 0; z < TERRAIN_SIZE - 1; z++)
    {
        for (x = 0; x < TERRAIN_SIZE - 1; x++)
        {
            int topLeft = z * TERRAIN_SIZE + x;
            int topRight = topLeft + 1;
            int bottomLeft = (z + 1) * TERRAIN_SIZE + x;
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

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vIndex * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    free(vertices);
    free(indices);
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

    attrPos = glGetAttribLocation(shaderProgram, "aPos");
    attrTexCoord = glGetAttribLocation(shaderProgram, "aTexCoord");
    uniModel = glGetUniformLocation(shaderProgram, "model");
    uniView = glGetUniformLocation(shaderProgram, "view");
    uniProjection = glGetUniformLocation(shaderProgram, "projection");
    uniLightPos = glGetUniformLocation(shaderProgram, "lightPos");
    uniViewPos = glGetUniformLocation(shaderProgram, "viewPos");
    uniTime = glGetUniformLocation(shaderProgram, "time");

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
    float rad = angleDeg * M_PI / 180.0f;
    float c = cos(rad), s = sin(rad);
    MatrixIdentity(m);
    m[0] = c; m[2] = s;
    m[8] = -s; m[10] = c;
}

void MatrixLookAt(float* m, float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ)
{
    float f[3], s[3], u[3], len;
    f[0] = centerX - eyeX;
    f[1] = centerY - eyeY;
    f[2] = centerZ - eyeZ;
    len = sqrt(f[0] * f[0] + f[1] * f[1] + f[2] * f[2]);
    if (len != 0.0f) { f[0] /= len; f[1] /= len; f[2] /= len; }

    s[0] = f[1] * upZ - f[2] * upY;
    s[1] = f[2] * upX - f[0] * upZ;
    s[2] = f[0] * upY - f[1] * upX;
    len = sqrt(s[0] * s[0] + s[1] * s[1] + s[2] * s[2]);
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
    float tanHalfFov = tan(fov / 360.0f * M_PI);
    int i;
    for (i = 0; i < 16; i++) m[i] = 0.0f;
    m[0] = 1.0f / (aspect * tanHalfFov);
    m[5] = 1.0f / tanHalfFov;
    m[10] = -(far + near) / (far - near);
    m[11] = -1.0f;
    m[14] = -(2.0f * far * near) / (far - near);
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

    GenerateTerrain();
    CreateTerrainBuffers();
    CreateProceduralTextures();
}

void Render(int width, int height)
{
    float model[16], view[16], projection[16];
    int posLoc, texLoc, modelLoc, viewLoc, projLoc;
    int lightPosLoc, viewPosLoc, timeLoc;
    float aspect = (float)width / (float)height;
    float timeValue = (float)LDL_Ticks() / 1000.0f;
    float camY = 1.5f;

    glClearColor(0.5f, 0.6f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    MatrixIdentity(model);

    float camX = sin(angle) * cameraDist;
    float camZ = cos(angle) * cameraDist;
    MatrixLookAt(view, camX, camY, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    MatrixPerspective(projection, 60.0f, aspect, 0.1f, 30.0f);

    glUseProgram(shaderProgram);

    glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);
    glUniformMatrix4fv(uniView, 1, GL_FALSE, view);
    glUniformMatrix4fv(uniProjection, 1, GL_FALSE, projection);
    glUniform3f(uniLightPos, 2.0f, 4.0f, 2.0f);
    glUniform3f(uniViewPos, camX, camY, camZ);
    glUniform1f(uniTime, timeValue);

    /* Bind textures */
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, grassTexture);
    glUniform1i(glGetUniformLocation(shaderProgram, "grassTexture"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, rockTexture);
    glUniform1i(glGetUniformLocation(shaderProgram, "rockTexture"), 1);

    /* Setup vertex attributes */
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glEnableVertexAttribArray(attrPos);
    glEnableVertexAttribArray(attrTexCoord);

    glVertexAttribPointer(attrPos, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(attrTexCoord, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(attrPos);
    glDisableVertexAttribArray(attrTexCoord);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    angle += 1.0f * seconds;
    if (angle >= 360.0f) angle -= 360.0f;
}

void CleanupOpenGL(void)
{
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteTextures(1, &grassTexture);
    glDeleteTextures(1, &rockTexture);
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
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height), "LDL - Textured Terrain (OpenGL 2.1)", LDL_WindowModeResized);

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

                        if (event.Type == LDL_EventIsMouseScroll)
                        {
                            cameraDist -= (float)event.u.Mouse.Delta / 80.0f;
                            if (cameraDist < 4.0f) cameraDist = 4.0f;
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
