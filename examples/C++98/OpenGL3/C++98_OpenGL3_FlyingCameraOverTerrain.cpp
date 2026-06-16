/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <LDL/C++98/LDL.hpp>
#include <LDL/OpenGL/GL3_0.h>
#include <LDL/C++98/GlmLite.hpp>

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include <LDL/Ext/stb_image.h>

 // Простой шейдер для текстурированного ландшафта
const char* vertexShaderSource =
"#version 130\n"
"in vec3 position;\n"
"in vec2 texCoord;\n"
"uniform mat4 mvp;\n"
"out vec2 vTexCoord;\n"
"void main()\n"
"{\n"
"    gl_Position = mvp * vec4(position, 1.0);\n"
"    vTexCoord = texCoord;\n"
"}\n";

const char* fragmentShaderSource =
"#version 130\n"
"in vec2 vTexCoord;\n"
"uniform sampler2D textureSampler;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"    fragColor = texture(textureSampler, vTexCoord);\n"
"}\n";

// Размеры ландшафта
const int TERRAIN_SIZE = 50;        // 50x50 вершин
const float TERRAIN_SCALE = 0.5f;   // расстояние между вершинами
const float TERRAIN_REPEAT = 25.0f; // повторяемость текстуры

// Параметры камеры
struct Camera
{
    float radius;
    float azimuth;
    float elevation;
    glm::vec3 target;

    Camera()
        : radius(15.0f)
        , azimuth(0.0f)
        , elevation(0.6f)
        , target(TERRAIN_SIZE* TERRAIN_SCALE * 0.5f, 0.0f, TERRAIN_SIZE* TERRAIN_SCALE * 0.5f)
    {
    }

    glm::vec3 getEyePosition() const
    {
        return glm::vec3(
            target.x + radius * cosf(elevation) * sinf(azimuth),
            target.y + radius * sinf(elevation),
            target.z + radius * cosf(elevation) * cosf(azimuth)
        );
    }

    glm::mat4 getViewMatrix() const
    {
        return glm::lookAt(
            getEyePosition(),
            target,
            glm::vec3(0.0f, 1.0f, 0.0f)
        );
    }
};

GLuint compileShader(GLenum type, const char* source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader compilation error: " << infoLog << std::endl;
    }
    return shader;
}

GLuint createShaderProgram()
{
    GLuint vs = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr << "Program linking error: " << infoLog << std::endl;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

GLuint loadTexture(const char* filename)
{
    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 3);

    if (!data)
    {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return 0;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    return texture;
}

// Функция высоты для ландшафта
float getHeight(float x, float z)
{
    return sinf(x * 0.3f) * cosf(z * 0.3f) * 1.5f +
        sinf(x * 0.7f + z * 0.5f) * 0.5f;
}

void createTerrain(std::vector<float>& vertices, std::vector<unsigned int>& indices)
{
    vertices.clear();
    indices.clear();

    // Создание вершин
    for (int z = 0; z < TERRAIN_SIZE; ++z)
    {
        for (int x = 0; x < TERRAIN_SIZE; ++x)
        {
            float px = x * TERRAIN_SCALE;
            float pz = z * TERRAIN_SCALE;
            float py = getHeight(px, pz);

            // Позиция
            vertices.push_back(px);
            vertices.push_back(py);
            vertices.push_back(pz);

            // Текстурные координаты
            vertices.push_back(x / (float)(TERRAIN_SIZE - 1) * TERRAIN_REPEAT);
            vertices.push_back(z / (float)(TERRAIN_SIZE - 1) * TERRAIN_REPEAT);
        }
    }

    // Создание индексов
    for (int z2 = 0; z2 < TERRAIN_SIZE - 1; ++z2)
    {
        for (int x2 = 0; x2 < TERRAIN_SIZE - 1; ++x2)
        {
            unsigned int topLeft = z2 * TERRAIN_SIZE + x2;
            unsigned int topRight = topLeft + 1;
            unsigned int bottomLeft = (z2 + 1) * TERRAIN_SIZE + x2;
            unsigned int bottomRight = bottomLeft + 1;

            // Первый треугольник
            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            // Второй треугольник
            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }
}

int main()
{
    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;
    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600),
        "LDL C++98 lesson - Flying camera over terrain", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsOk())
    {
        // Настройка OpenGL
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.5f, 0.7f, 1.0f, 1.0f);

        // Создание шейдера
        GLuint shaderProgram = createShaderProgram();
        GLint mvpLocation = glGetUniformLocation(shaderProgram, "mvp");
        GLint textureLocation = glGetUniformLocation(shaderProgram, "textureSampler");

        // Загрузка текстуры
        GLuint terrainTexture = loadTexture("Files/ba_rock_hm.jpg");
        if (!terrainTexture)
        {
            std::cerr << "Place earth.png texture in the same directory as executable" << std::endl;
            return -1;
        }

        // Создание ландшафта
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        createTerrain(vertices, indices);

        // Создание VAO и VBO
        GLuint vao, vbo, ebo;
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // Позиция
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Текстурные координаты
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        // Камера
        Camera camera;

        // Угол обзора
        float fov = 45.0f;

        while (window.IsRunning() && result.IsOk())
        {
            while (window.GetEvent(event))
            {
                if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                {
                    window.StopEvent();
                }

                if (event.Type == LDL_EventIsResize)
                {
                    glViewport(0, 0, (GLsizei)event.u.Resize.Width, (GLsizei)event.u.Resize.Height);
                }
            }

            // Обновление камеры
            camera.azimuth += 0.005f;
            if (camera.azimuth > 2.0f * 3.14159f)
                camera.azimuth -= 2.0f * 3.14159f;

            // Отрисовка
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glUseProgram(shaderProgram);

            // Матрицы с использованием GLM
            glm::mat4 projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
            glm::mat4 view = camera.getViewMatrix();
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 mvp = projection * view * model;

            glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));
            glUniform1i(textureLocation, 0);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, terrainTexture);

            glBindVertexArray(vao);
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            window.Present();
        }

        // Очистка
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        glDeleteProgram(shaderProgram);
        glDeleteTextures(1, &terrainTexture);
    }

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
    }

    return result.IsOk() ? 0 : -1;
}