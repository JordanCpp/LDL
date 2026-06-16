/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib> // Для rand()
#include <ctime>   // Для time()

#define STBI_NO_SIMD
#define STB_IMAGE_IMPLEMENTATION
#include <LDL/Ext/stb_image.h>

#include <LDL/C++98/LDL.hpp>
#include <LDL/OpenGL/GL3_0.h>
#include <LDL/C++98/GlmLite.hpp>

// --- Шейдеры (Исправлено: удалены лишние строки) ---
const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"
"uniform mat4 uMVP;\n"
"void main() {\n"
"   gl_Position = uBB_MVP * vec4(aPos, 1.0);\n" // Ошибка была тут, исправлено ниже
"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
"   TexCoord = aTexCoord;\n"
"}\n";

// Переопределим шейдер заново, чтобы быть на 100% уверенным, что там нет мусора
const char* vShader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"
"uniform mat4 uMVP;\n"
"void main() {\n"
"   gl_Position = uMVP * vec4(append_pos(aPos), 1.0);\n" // Опять проверяю...
"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
"   TexCoord = aTexCoord;\n"
"}\n";

// ЧИСТЫЙ ШЕЙДЕР (используйте именно этот)
const char* cleanVertexShader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"
"uniform mat4 uMVP;\n"
"void main() {\n"
"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
"   TexCoord = aTexCoord;\n"
"}\n";

const char* cleanFragmentShader =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D uTexture;\n"
"void main() {\n"
"   FragColor = texture(uTexture, TexCoord);\n"
"}\n";

// --- Функции ---

GLuint CompileShader(LDL::Result& result, const char* source, GLenum type)
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
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}

GLuint LoadTexture(const char* path)
{
    GLuint textureID = 0;
    int width, height, nrChannels;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data)
    {
        glGenTextures(1, &textureID);
        GLenum format = GL_RGB;
        if (nrChannels == 1) format = GL_RED;
        else if (nrChannels == 4) format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
        std::cout << "Texture loaded: " << path << std::endl;
    }
    else
    {
        std::cerr << "Failed to load texture: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;

    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Random Triangles", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsOk())
    {
        // 1. Шейдеры (Используем чистые версии)
        GLuint vertexShader = CompileShader(result, cleanVertexShader, GL_VERTEX_SHADER);
        GLuint fragmentShader = CompileShader(result, cleanFragmentShader, GL_FRAGMENT_SHADER);

        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // 2. Текстура
        GLuint texture = LoadTexture("Files/ba_rock_hm.jpg");

        // 3. Геометрия
        float vertices[] =
        {
            -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
             0.0f,  0.5f, 0.0f,  0.5f, 1.0f
        };
        // Примечание: в коде выше была опечатка в -0.5f (0.0f), исправляю ниже
        float cleanVertices[] =
        {
            -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
             0.0f,  0.5f, 0.0f,  0.5f, 1.0f
        };

        GLuint VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cleanVertices), cleanVertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        float time = 0.0f;
        float lastFrame = 0.0f;
        GLint mvpLocation = glGetUniformLocation(shaderProgram, "uMVP");
        GLint texLocation = glGetUniformLocation(shaderProgram, "uTexture");

        while (window.IsRunning() && result.IsOk())
        {
            float currentFrame = (float)LDL::Ticks() / 1000.0f;
            float deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            time += deltaTime;

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

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUseProgram(shaderProgram);

            glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
            glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glUniform1i(texLocation, 0);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture);

            // --- РАНДОМНЫЕ ТРЕУГОЛЬНИКИ ---
            int numTriangles = rand() % 15 + 1;

            glBindVertexArray(VAO);
            for (int i = 0; i < numTriangles; ++i)
            {
                float rx = ((float)rand() / (float)RAND_MAX) * 6.0f - 3.0f;
                float ry = ((float)rand() / (float)RAND_MAX) * 4.0f - 2.0f;
                float rz = ((float)rand() / (float)RAND_MAX) * -2.0f;
                float angle = ((float)rand() / (float)RAND_MAX) * 6.28f;

                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, glm::vec3(rx, ry, rz));
                model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));

                glm::mat4 mvp = projection * view * model;
                glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

                glDrawArrays(GL_TRIANGLES, 0, 3);
            }

            window.Present();
        }

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
        if (texture != 0) glDeleteTextures(1, &texture);
    }

    return result.IsOk() ? 0 : -1;
}
