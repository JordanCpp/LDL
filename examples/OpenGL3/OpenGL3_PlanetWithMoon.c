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

 /* Vertex shader with lighting */
static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aNormal;\n"
"layout (location = 2) in vec2 aTexCoord;\n"
"out vec3 FragPos;\n"
"out vec3 Normal;\n"
"out vec2 TexCoord;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"    FragPos = vec3(model * vec4(aPos, 1.0));\n"
"    Normal = mat3(transpose(inverse(model))) * aNormal;\n"
"    TexCoord = aTexCoord;\n"
"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
"}\n";

/* Fragment shader */
static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec3 FragPos;\n"
"in vec3 Normal;\n"
"in vec2 TexCoord;\n"
"out vec4 FragColor;\n"
"uniform sampler2D ourTexture;\n"
"uniform vec3 lightPos;\n"
"uniform vec3 viewPos;\n"
"uniform vec3 objectColor;\n"
"void main()\n"
"{\n"
"    vec4 texColor = texture(ourTexture, TexCoord);\n"
"    vec3 lightColor = vec3(1.0, 1.0, 1.0);\n"
"    float ambientStrength = 0.3;\n"
"    vec3 ambient = ambientStrength * lightColor;\n"
"    vec3 norm = normalize(Normal);\n"
"    vec3 lightDir = normalize(lightPos - FragPos);\n"
"    float diff = max(dot(norm, lightDir), 0.0);\n"
"    vec3 diffuse = diff * lightColor;\n"
"    float specularStrength = 0.3;\n"
"    vec3 viewDir = normalize(viewPos - FragPos);\n"
"    vec3 reflectDir = reflect(-lightDir, norm);\n"
"    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);\n"
"    vec3 specular = specularStrength * spec * lightColor;\n"
"    vec3 result = (ambient + diffuse + specular) * texColor.rgb * objectColor;\n"
"    FragColor = vec4(result, 1.0);\n"
"}\n";

/* Sphere generation data */
static GLuint sphereVAO, sphereVBO, sphereEBO;
static int sphereIndexCount = 0;
static GLuint moonVAO, moonVBO, moonEBO;
static int moonIndexCount = 0;
static GLuint ShaderProgram;
static GLuint planetTexture, moonTexture;
static float planetAngle = 0.0f;
static float moonAngle = 0.0f;
static float cameraAngle = 0.0f;
static size_t lastTime = 0;

/* Generate sphere mesh */
void GenerateSphere(GLuint* vao, GLuint* vbo, GLuint* ebo, int* indexCount, float radius, int sectors, int stacks)
{
    float* vertices;
    unsigned int* indices;
    int i, j;
    int vertexCount = (sectors + 1) * (stacks + 1) * 8;
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

            /* Normalize normal */
            float nx = x / radius;
            float ny = y / radius;
            float nz = z / radius;

            vertices[vIndex++] = x;
            vertices[vIndex++] = y;
            vertices[vIndex++] = z;
            vertices[vIndex++] = nx;
            vertices[vIndex++] = ny;
            vertices[vIndex++] = nz;
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

    *indexCount = iIndex;

    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ebo);

    glBindVertexArray(*vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, vIndex * sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, *indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    /* Position attribute */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    /* Normal attribute */
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    /* TexCoord attribute */
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    free(vertices);
    free(indices);
}

/* Create planet texture (earth-like) */
void CreatePlanetTexture(GLuint* textureID)
{
    int width = 512;
    int height = 512;
    unsigned char* data;
    int x, y;

    data = (unsigned char*)malloc(width * height * 3);
    if (!data) return;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            float fx = (float)x / width * 2.0f - 1.0f;
            float fy = (float)y / height * 2.0f - 1.0f;
            float dist = (float)sqrt(fx * fx + fy * fy);
            int r, g, b;

            if (dist < 0.5f)
            {
                /* Ocean (blue) */
                r = (int)(50 + 50 * sin(fx * 10.0f) * cos(fy * 10.0f));
                g = (int)(100 + 50 * sin(fx * 8.0f + fy * 8.0f));
                b = (int)(180 + 75 * sin(fx * 12.0f));
            }
            else
            {
                /* Land (green/brown) */
                r = (int)(120 + 80 * sin(fx * 15.0f + fy * 15.0f));
                g = (int)(100 + 60 * cos(fx * 12.0f - fy * 12.0f));
                b = (int)(60 + 40 * sin(fx * 20.0f));
            }

            data[(y * width + x) * 3 + 0] = (unsigned char)r;
            data[(y * width + x) * 3 + 1] = (unsigned char)g;
            data[(y * width + x) * 3 + 2] = (unsigned char)b;
        }
    }

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    free(data);
}

/* Create moon texture (grey rock) */
void CreateMoonTexture(GLuint* textureID)
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
            int gray = 100 + (rand() % 80);
            data[(y * width + x) * 3 + 0] = (unsigned char)gray;
            data[(y * width + x) * 3 + 1] = (unsigned char)gray;
            data[(y * width + x) * 3 + 2] = (unsigned char)gray;
        }
    }

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
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
    float tanHalfFov = (float)tan(fov / 360.0f * (float)M_PI);
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

    GenerateSphere(&sphereVAO, &sphereVBO, &sphereEBO, &sphereIndexCount, 0.8f, 48, 32);
    GenerateSphere(&moonVAO, &moonVBO, &moonEBO, &moonIndexCount, 0.25f, 24, 16);

    CreatePlanetTexture(&planetTexture);
    CreateMoonTexture(&moonTexture);
}

/* Draw sphere mesh */
void DrawSphere(GLuint vao, int indexCount, GLuint textureID, float r, float g, float b)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glUniform1i(glGetUniformLocation(ShaderProgram, "ourTexture"), 0);
    glUniform3f(glGetUniformLocation(ShaderProgram, "objectColor"), r, g, b);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

/* Render scene */
void Render(int width, int height)
{
    float model[16], view[16], projection[16];
    float rot[16], trans[16], scale[16];
    int modelLoc, viewLoc, projLoc;
    int lightPosLoc, viewPosLoc;
    float aspect = (float)width / (float)height;

    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width, height);

    /* View matrix (rotating camera) */
    float camX = (float)sin(cameraAngle) * 4.0f;
    float camZ = (float)cos(cameraAngle) * 4.0f;
    MatrixLookAt(view, camX, 1.5f, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    /* Projection matrix */
    MatrixPerspective(projection, 45.0f, aspect, 0.1f, 20.0f);

    glUseProgram(ShaderProgram);

    modelLoc = glGetUniformLocation(ShaderProgram, "model");
    viewLoc = glGetUniformLocation(ShaderProgram, "view");
    projLoc = glGetUniformLocation(ShaderProgram, "projection");
    lightPosLoc = glGetUniformLocation(ShaderProgram, "lightPos");
    viewPosLoc = glGetUniformLocation(ShaderProgram, "viewPos");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection);
    glUniform3f(lightPosLoc, 2.0f, 3.0f, 2.0f);
    glUniform3f(viewPosLoc, camX, 1.5f, camZ);

    /* Draw planet */
    MatrixRotateY(rot, planetAngle);
    MatrixScale(scale, 0.8f, 0.8f, 0.8f);
    MatrixMultiply(model, rot, scale);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);
    DrawSphere(sphereVAO, sphereIndexCount, planetTexture, 1.0f, 1.0f, 1.0f);

    /* Draw moon orbiting */
    float moonOrbitAngle = moonAngle;
    float moonX = 1.5f * (float)sin(moonOrbitAngle);
    float moonZ = 1.5f * (float)cos(moonOrbitAngle);

    MatrixTranslate(trans, moonX, 0.2f, moonZ);
    MatrixRotateY(rot, -moonAngle);
    MatrixMultiply(model, trans, rot);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);
    DrawSphere(moonVAO, moonIndexCount, moonTexture, 0.8f, 0.8f, 0.9f);

    glBindVertexArray(0);
}

/* Update animation */
void UpdateAnimation(size_t delta)
{
    float seconds = (float)delta / 1000.0f;
    planetAngle += 10.0f * seconds;      /* было 30 */
    if (planetAngle >= 360.0f) planetAngle -= 360.0f;

    moonAngle += 10.0f * seconds;        /* было 90 */
    if (moonAngle >= 360.0f) moonAngle -= 360.0f;

    cameraAngle += 5.0f * seconds;       /* было 15 */
    if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;
}

/* Cleanup */
void CleanupOpenGL(void)
{
    glDeleteVertexArrays(1, &sphereVAO);
    glDeleteBuffers(1, &sphereVBO);
    glDeleteBuffers(1, &sphereEBO);
    glDeleteVertexArrays(1, &moonVAO);
    glDeleteBuffers(1, &moonVBO);
    glDeleteBuffers(1, &moonEBO);
    glDeleteTextures(1, &planetTexture);
    glDeleteTextures(1, &moonTexture);
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
    context = LDL_ContextNew(LDL_ContextOpenGL3);
    window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(width, height),
        "LDL - Planet with Moon (OpenGL 3.3)", LDL_WindowModeResized);

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
