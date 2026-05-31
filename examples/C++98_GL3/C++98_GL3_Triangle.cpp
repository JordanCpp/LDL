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
#include "GlmLite.hpp"

const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"uniform mat4 uMVP;\n"
"void main() {\n"
"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
"}\0";

const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"   FragColor = vec4(0.2f, 0.7f, 0.3f, 1.0f);\n"
"}\n\0";

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

int main()
{
    LDL::Result  result;
    LDL::Context context;
    LDL::Event   event;

    LDL::Window       window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL OpenGL 3 + GLM Example", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsOk())
    {
        GLuint vertexShader = CompileShader(result, vertexShaderSource, GL_VERTEX_SHADER);
        GLuint fragmentShader = CompileShader(result, fragmentShaderSource, GL_FRAGMENT_SHADER);

        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        GLint success;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) 
        {
            std::cerr << "ERROR::SHADER::LINKING_FAILED\n" << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        float vertices[] = 
        {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };

        GLuint VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        float time = 0.0f;
        float lastFrame = 0.0f;

        GLint mvpLocation = glGetUniformLocation(shaderProgram, "uMVP");

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

            glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::rotate(model, time, glm::vec3(0.0f, 0.0f, 1.0f));

            glm::mat4 mvp = projection * view * model;

            glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            window.Present();
        }

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
    }

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
    }

    return result.IsOk() ? 0 : -1;
}
