/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <LDL/C++98/LDL.hpp>
#include <LDL/OpenGL/GL3_0.h>
#include <LDL/C++98/GlmLite.hpp>

 // Шейдеры
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
const int TERRAIN_SIZE = 200;
const float TERRAIN_SCALE = 1.0f;
const float TERRAIN_REPEAT = 100.0f;

// Параметры камеры
struct Camera
{
    float radius;
    float azimuth;
    float elevation;
    glm::vec3 target;
    float zoomSpeed;
    float moveSpeed;

    Camera()
        : radius(80.0f)
        , azimuth(0.0f)
        , elevation(0.8f)
        , target(TERRAIN_SIZE* TERRAIN_SCALE * 0.5f, 20.0f, TERRAIN_SIZE* TERRAIN_SCALE * 0.5f)
        , zoomSpeed(2.0f)
        , moveSpeed(30.0f)
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

    void zoomIn(float deltaTime)
    {
        radius -= zoomSpeed * deltaTime * 60.0f;
        if (radius < 10.0f) radius = 10.0f;
    }

    void zoomOut(float deltaTime)
    {
        radius += zoomSpeed * deltaTime * 60.0f;
        if (radius > 200.0f) radius = 200.0f;
    }

    void moveForward(float deltaTime)
    {
        target.x += sinf(azimuth) * moveSpeed * deltaTime;
        target.z += cosf(azimuth) * moveSpeed * deltaTime;
        clampPosition();
    }

    void moveBackward(float deltaTime)
    {
        target.x -= sinf(azimuth) * moveSpeed * deltaTime;
        target.z -= cosf(azimuth) * moveSpeed * deltaTime;
        clampPosition();
    }

    void clampPosition()
    {
        float maxCoord = TERRAIN_SIZE * TERRAIN_SCALE;
        if (target.x < 0.0f) target.x = 0.0f;
        if (target.x > maxCoord) target.x = maxCoord;
        if (target.z < 0.0f) target.z = 0.0f;
        if (target.z > maxCoord) target.z = maxCoord;
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

GLuint LoadTexture(LDL::ImageLoader& imageLoader, const char* path)
{
    GLuint textureID;
    glGenTextures(1, &textureID);

    imageLoader.LoadFromFile(path);


    GLenum format = imageLoader.GetPixelFormat() == LDL_PixelFormatRGB24 ? GL_RGB : GL_RGBA;

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, imageLoader.GetSize().x, imageLoader.GetSize().y, 0, format, GL_UNSIGNED_BYTE, imageLoader.GetPixels());
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}

GLuint createDefaultTexture()
{
    unsigned char defaultTex[48] = {
        139,69,19, 160,82,45, 139,69,19, 160,82,45,
        160,82,45, 139,69,19, 160,82,45, 139,69,19,
        139,69,19, 160,82,45, 139,69,19, 160,82,45,
        160,82,45, 139,69,19, 160,82,45, 139,69,19
    };

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, defaultTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    return texture;
}

float getHeight(float x, float z)
{
    float h = 0.0f;

    // Крупные формы
    h += sinf(x * 0.01f) * cosf(z * 0.01f) * 10.0f;
    h += cosf(x * 0.02f + 1.0f) * sinf(z * 0.02f) * 8.0f;

    // Средние детали
    h += sinf(x * 0.05f) * cosf(z * 0.05f) * 4.0f;
    h += cosf(x * 0.07f) * sinf(z * 0.07f + 2.0f) * 3.0f;

    // Мелкие детали
    h += sinf(x * 0.1f) * cosf(z * 0.1f) * 2.0f;
    h += sinf(x * 0.15f + z * 0.15f) * 1.5f;
    h += cosf(x * 0.2f) * sinf(z * 0.2f) * 1.0f;

    // Микродетали
    h += sinf(x * 0.3f + 3.0f) * cosf(z * 0.3f) * 0.5f;

    return h;
}

void createTerrain(std::vector<float>& vertices, std::vector<unsigned int>& indices)
{
    vertices.clear();
    indices.clear();

    std::cout << "Creating terrain " << TERRAIN_SIZE << "x" << TERRAIN_SIZE << "..." << std::endl;

    for (int z = 0; z < TERRAIN_SIZE; ++z)
    {
        for (int x = 0; x < TERRAIN_SIZE; ++x)
        {
            float px = x * TERRAIN_SCALE;
            float pz = z * TERRAIN_SCALE;
            float py = getHeight(px, pz);

            vertices.push_back(px);
            vertices.push_back(py);
            vertices.push_back(pz);
            vertices.push_back(x / (float)(TERRAIN_SIZE - 1) * TERRAIN_REPEAT);
            vertices.push_back(z / (float)(TERRAIN_SIZE - 1) * TERRAIN_REPEAT);
        }

        if (z % 20 == 0)
            std::cout << "Row " << z << "/" << TERRAIN_SIZE << std::endl;
    }

    for (int z2 = 0; z2 < TERRAIN_SIZE - 1; ++z2)
    {
        for (int x2 = 0; x2 < TERRAIN_SIZE - 1; ++x2)
        {
            unsigned int topLeft = z2 * TERRAIN_SIZE + x2;
            unsigned int topRight = topLeft + 1;
            unsigned int bottomLeft = (z2 + 1) * TERRAIN_SIZE + x2;
            unsigned int bottomRight = bottomLeft + 1;

            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }

    std::cout << "Terrain created: " << vertices.size() / 5 << " vertices, "
        << indices.size() / 3 << " triangles" << std::endl;
}

int main()
{
    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;
    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(1024, 768),
        "LDL - Large terrain with flying camera", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);
    LDL::ImageLoader imageLoader(result);

    if (result.IsOk())
    {
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.5f, 0.7f, 1.0f, 1.0f);

        // Шейдер
        GLuint shaderProgram = createShaderProgram();
        GLint mvpLocation = glGetUniformLocation(shaderProgram, "mvp");
        GLint textureLocation = glGetUniformLocation(shaderProgram, "textureSampler");

        // Текстура
        GLuint terrainTexture = LoadTexture(imageLoader, "Files/ba_rock_hm.jpg");
        if (!terrainTexture)
        {
            std::cout << "Creating default texture..." << std::endl;
            terrainTexture = createDefaultTexture();
        }

        // Ландшафт
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        createTerrain(vertices, indices);

        // VAO, VBO, EBO
        GLuint vao, vbo, ebo;
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // Позиция (location 0)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Текстурные координаты (location 1)
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        // Камера
        Camera camera;
        unsigned int lastTime = LDL::Ticks();
        float deltaTime;

        std::cout << std::endl;
        std::cout << "Controls:" << std::endl;
        std::cout << "  W/S or Up/Down - Zoom in/out" << std::endl;
        std::cout << "  A/D or Left/Right - Rotate camera" << std::endl;
        std::cout << "  Space - Move forward" << std::endl;
        std::cout << "  Ctrl - Move backward" << std::endl;
        std::cout << "  Q - Move up" << std::endl;
        std::cout << "  E - Move down" << std::endl;
        std::cout << "  Esc - Exit" << std::endl;
        std::cout << std::endl;

        while (window.IsRunning() && result.IsOk())
        {
            unsigned int currentTime = LDL::Ticks();
            deltaTime = (currentTime - lastTime) / 1000.0f;
            lastTime = currentTime;
            if (deltaTime > 0.1f) deltaTime = 0.1f;

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

            // Управление камерой
            if (LDL_EventIsKeyPressed(&event, LDL_KeyW) || LDL_EventIsKeyPressed(&event, LDL_KeyUp))
                camera.zoomIn(deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyS) || LDL_EventIsKeyPressed(&event, LDL_KeyDown))
                camera.zoomOut(deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyA) || LDL_EventIsKeyPressed(&event, LDL_KeyLeft))
                camera.azimuth -= 1.0f * deltaTime;

            if (LDL_EventIsKeyPressed(&event, LDL_KeyD) || LDL_EventIsKeyPressed(&event, LDL_KeyRight))
                camera.azimuth += 1.0f * deltaTime;

            if (LDL_EventIsKeyPressed(&event, LDL_KeySpace))
                camera.moveForward(deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyLeftControl))
                camera.moveBackward(deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyQ))
                camera.target.y += camera.moveSpeed * deltaTime;

            if (LDL_EventIsKeyPressed(&event, LDL_KeyE))
            {
                camera.target.y -= camera.moveSpeed * deltaTime;
                if (camera.target.y < 0.0f) camera.target.y = 0.0f;
            }

            // Отрисовка
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glUseProgram(shaderProgram);

            glm::mat4 projection = glm::perspective(glm::radians(60.0f), 1024.0f / 768.0f, 0.1f, 500.0f);
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
