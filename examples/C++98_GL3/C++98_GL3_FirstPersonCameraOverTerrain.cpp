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

#include "GlmLite.hpp"

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

// Камера от первого лица
class Camera
{
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;
    float movementSpeed;
    float mouseSensitivity;

    void updateCameraVectors()
    {
        glm::vec3 newFront;
        newFront.x = cosf(glm::radians(yaw)) * cosf(glm::radians(pitch));
        newFront.y = sinf(glm::radians(pitch));
        newFront.z = sinf(glm::radians(yaw)) * cosf(glm::radians(pitch));
        front = glm::normalize(newFront);

        right = glm::normalize(glm::cross(front, worldUp));
        up = glm::normalize(glm::cross(right, front));
    }

public:
    Camera(glm::vec3 startPosition = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 startUp = glm::vec3(0.0f, 1.0f, 0.0f),
        float startYaw = -90.0f,
        float startPitch = 0.0f)
        : position(startPosition)
        , worldUp(startUp)
        , yaw(startYaw)
        , pitch(startPitch)
        , movementSpeed(30.0f)
        , mouseSensitivity(0.1f)
    {
        updateCameraVectors();
    }

    glm::mat4 getViewMatrix() const
    {
        return glm::lookAt(position, position + front, up);
    }

    void processKeyboard(const char* direction, float deltaTime)
    {
        float velocity = movementSpeed * deltaTime;

        if (strcmp(direction, "forward") == 0)
            position += front * velocity;
        if (strcmp(direction, "backward") == 0)
            position -= front * velocity;
        if (strcmp(direction, "left") == 0)
            position -= right * velocity;
        if (strcmp(direction, "right") == 0)
            position += right * velocity;
        if (strcmp(direction, "up") == 0)
            position += worldUp * velocity;
        if (strcmp(direction, "down") == 0)
            position -= worldUp * velocity;

        // Ограничение высоты
        if (position.y < 2.0f) position.y = 2.0f;
        if (position.y > 100.0f) position.y = 100.0f;

        // Ограничение по краям карты
        float maxCoord = TERRAIN_SIZE * TERRAIN_SCALE;
        if (position.x < 0.0f) position.x = 0.0f;
        if (position.x > maxCoord) position.x = maxCoord;
        if (position.z < 0.0f) position.z = 0.0f;
        if (position.z > maxCoord) position.z = maxCoord;
    }

    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true)
    {
        xoffset *= mouseSensitivity;
        yoffset *= mouseSensitivity;

        yaw += xoffset;
        pitch += yoffset;

        if (constrainPitch)
        {
            if (pitch > 89.0f) pitch = 89.0f;
            if (pitch < -89.0f) pitch = -89.0f;
        }

        updateCameraVectors();
    }

    void setSpeed(float speed)
    {
        movementSpeed = speed;
    }

    float getSpeed() const
    {
        return movementSpeed;
    }

    glm::vec3 getPosition() const
    {
        return position;
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

    std::cout << "Texture loaded: " << width << "x" << height << std::endl;

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
    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(100, 100), LDL::Vec2i(1024, 768),
        "LDL - First Person Camera over Terrain", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsOk())
    {
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.5f, 0.7f, 1.0f, 1.0f);

        // Шейдер
        GLuint shaderProgram = createShaderProgram();
        GLint mvpLocation = glGetUniformLocation(shaderProgram, "mvp");
        GLint textureLocation = glGetUniformLocation(shaderProgram, "textureSampler");

        // Текстура
        GLuint terrainTexture = loadTexture("ba_rock_hm.jpg");
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

        // Камера от первого лица
        Camera camera(glm::vec3(100.0f, 20.0f, 100.0f));

        // Переменные для мыши
        int lastMouseX = 512;
        int lastMouseY = 384;
        bool firstMouse = true;

        unsigned int lastTime = LDL::Ticks();
        float deltaTime;

        std::cout << std::endl;
        std::cout << "First Person Camera Controls:" << std::endl;
        std::cout << "  W/S - Move forward/backward" << std::endl;
        std::cout << "  A/D - Strafe left/right" << std::endl;
        std::cout << "  Q/E - Fly up/down" << std::endl;
        std::cout << "  Mouse - Look around" << std::endl;
        std::cout << "  Shift - Boost speed" << std::endl;
        std::cout << "  Esc - Exit" << std::endl;
        std::cout << std::endl;

        while (window.IsRunning() && result.IsOk())
        {
            unsigned int currentTime = LDL::Ticks();
            deltaTime = (currentTime - lastTime) / 1000.0f;
            lastTime = currentTime;
            if (deltaTime > 0.1f) deltaTime = 0.1f;

            // Обработка событий
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

                // Обработка движения мыши
                if (event.Type == LDL_EventIsMouseMove)
                {
                    int mouseX = event.u.Mouse.PosX;
                    int mouseY = event.u.Mouse.PosY;

                    if (firstMouse)
                    {
                        lastMouseX = mouseX;
                        lastMouseY = mouseY;
                        firstMouse = false;
                    }

                    float xoffset = (float)(mouseX - lastMouseX);
                    float yoffset = (float)(lastMouseY - mouseY); // Инвертировано, так как Y экрана идет вниз

                    lastMouseX = mouseX;
                    lastMouseY = mouseY;

                    camera.processMouseMovement(xoffset, yoffset);
                }
            }

            // Управление с клавиатуры
            float normalSpeed = 30.0f;
            float boostSpeed = 80.0f;

            // Проверяем Shift для ускорения
            if (LDL_EventIsKeyPressed(&event, LDL_KeyLeftShift) || LDL_EventIsKeyPressed(&event, LDL_KeyRightShift))
                camera.setSpeed(boostSpeed);
            else
                camera.setSpeed(normalSpeed);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyW) || LDL_EventIsKeyPressed(&event, LDL_KeyUp))
                camera.processKeyboard("forward", deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyS) || LDL_EventIsKeyPressed(&event, LDL_KeyDown))
                camera.processKeyboard("backward", deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyA) || LDL_EventIsKeyPressed(&event, LDL_KeyLeft))
                camera.processKeyboard("left", deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyD) || LDL_EventIsKeyPressed(&event, LDL_KeyRight))
                camera.processKeyboard("right", deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyQ))
                camera.processKeyboard("up", deltaTime);

            if (LDL_EventIsKeyPressed(&event, LDL_KeyE))
                camera.processKeyboard("down", deltaTime);

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
            glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
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
