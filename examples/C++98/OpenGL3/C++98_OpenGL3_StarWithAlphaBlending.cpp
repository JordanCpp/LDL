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

const char* vertexShaderSource =
"#version 130\n"
"in vec2 aPos;\n"
"in vec4 aColor;\n"
"out vec4 vColor;\n"
"uniform mat4 uMVP;\n"
"void main()\n"
"{\n"
"    gl_Position = uMVP * vec4(aPos, 0.0, 1.0);\n"
"    vColor = aColor;\n"
"}\n";

const char* fragmentShaderSource =
"#version 130\n"
"in vec4 vColor;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"    fragColor = vColor;\n"
"}\n";

GLuint CompileShader(GLenum type, const char* source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    return shader;
}

GLuint CreateProgram(const char* vsSource, const char* fsSource)
{
    GLuint vs = CompileShader(GL_VERTEX_SHADER, vsSource);
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fsSource);
    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}


void BuildCheckerboard(std::vector<float>& vertices, std::vector<unsigned int>& indices, int gridSize, float cellSize)
{
    const int vertsPerSide = gridSize + 1;

    for (int row = 0; row < vertsPerSide; ++row)
    {
        for (int col = 0; col < vertsPerSide; ++col)
        {
            float x = (col - gridSize * 0.5f) * cellSize;
            float y = (row - gridSize * 0.5f) * cellSize;
            vertices.push_back(x);
            vertices.push_back(y);

            bool isDark = ((row + col) % 2) == 0;
            if (isDark)
            {
                vertices.push_back(0.25f);
                vertices.push_back(0.25f);
                vertices.push_back(0.35f);
                vertices.push_back(1.0f);
            }
            else
            {
                vertices.push_back(0.5f);
                vertices.push_back(0.5f);
                vertices.push_back(0.6f);
                vertices.push_back(1.0f);
            }
        }
    }

    for (int row2 = 0; row2 < gridSize; ++row2)
    {
        for (int col2 = 0; col2 < gridSize; ++col2)
        {
            unsigned int topLeft = row2 * vertsPerSide + col2;
            unsigned int topRight = topLeft + 1;
            unsigned int bottomLeft = (row2 + 1) * vertsPerSide + col2;
            unsigned int bottomRight = bottomLeft + 1;

            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }
}

void GenerateStar(std::vector<float>& vertices, float outerRadius, float innerRadius, int points, float centerAlpha, float tipAlpha)
{
    // Center vertex
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(1.0f);  // yellow
    vertices.push_back(0.9f);
    vertices.push_back(0.2f);
    vertices.push_back(centerAlpha);

    const int totalVertices = points * 2;
    for (int i = 0; i <= totalVertices; ++i)
    {
        float angle = (3.14159265f * 0.5f) + (2.0f * 3.14159265f * i / totalVertices);
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;

        float x = radius * cosf(angle);
        float y = radius * sinf(angle);

        // Alpha gradient: interpolate between centerAlpha and tipAlpha based on radius
        float t = (radius - innerRadius) / (outerRadius - innerRadius);
        t = t < 0.0f ? 0.0f : (t > 1.0f ? 1.0f : t);
        float alpha = centerAlpha + t * (tipAlpha - centerAlpha);

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(1.0f);  // warm orange
        vertices.push_back(0.6f);
        vertices.push_back(0.0f);
        vertices.push_back(alpha);
    }
}

int main()
{
    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;
    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Example 04 - Star with Alpha Blending", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
        return -1;
    }

    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glViewport(0, 0, 800, 600);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLuint program = CreateProgram(vertexShaderSource, fragmentShaderSource);
    GLint locMVP = glGetUniformLocation(program, "uMVP");

    // Background checkerboard
    std::vector<float> bgVertices;
    std::vector<unsigned int> bgIndices;
    BuildCheckerboard(bgVertices, bgIndices, 12, 0.16f);

    GLuint bgVao, bgVbo, bgEbo;
    glGenVertexArrays(1, &bgVao);
    glGenBuffers(1, &bgVbo);
    glGenBuffers(1, &bgEbo);

    glBindVertexArray(bgVao);
    glBindBuffer(GL_ARRAY_BUFFER, bgVbo);
    glBufferData(GL_ARRAY_BUFFER, bgVertices.size() * sizeof(float), &bgVertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bgEbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, bgIndices.size() * sizeof(unsigned int), &bgIndices[0], GL_STATIC_DRAW);

    // Position: location 0, 2 floats, stride 6 floats, offset 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color: location 1, 4 floats, stride 6 floats, offset 2 floats
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    // Star geometry
    std::vector<float> starVertices;
    GenerateStar(starVertices, 0.5f, 0.22f, 5, 0.95f, 0.15f);

    GLuint starVao, starVbo;
    glGenVertexArrays(1, &starVao);
    glGenBuffers(1, &starVbo);

    glBindVertexArray(starVao);
    glBindBuffer(GL_ARRAY_BUFFER, starVbo);
    glBufferData(GL_ARRAY_BUFFER, starVertices.size() * sizeof(float), &starVertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    float rotation = 0.0f;

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

        rotation += 0.015f;

        float aspect = 800.0f / 600.0f;
        float proj[16] = {
            1.0f / aspect, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        glClear(GL_COLOR_BUFFER_BIT);

        // --- Pass 1: Draw opaque background first ---
        // Identity matrix for background (no rotation)
        float identity[16] = {
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        float bgMvp[16];
        for (int col = 0; col < 4; ++col)
        {
            for (int row = 0; row < 4; ++row)
            {
                bgMvp[col * 4 + row] = 0.0f;
                for (int k = 0; k < 4; ++k)
                {
                    bgMvp[col * 4 + row] += proj[k * 4 + row] * identity[col * 4 + k];
                }
            }
        }

        glUseProgram(program);
        glUniformMatrix4fv(locMVP, 1, GL_FALSE, bgMvp);
        glBindVertexArray(bgVao);
        glDrawElements(GL_TRIANGLES, (GLsizei)bgIndices.size(), GL_UNSIGNED_INT, 0);

        // --- Pass 2: Draw translucent star on top ---
        float c = cosf(rotation);
        float s = sinf(rotation);
        float rot[16] = {
            c,   -s,  0.0f, 0.0f,
            s,    c,  0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        float starMvp[16];
        for (int col2 = 0; col2 < 4; ++col2)
        {
            for (int row2 = 0; row2 < 4; ++row2)
            {
                starMvp[col2 * 4 + row2] = 0.0f;
                for (int k = 0; k < 4; ++k)
                {
                    starMvp[col2 * 4 + row2] += proj[k * 4 + row2] * rot[col2 * 4 + k];
                }
            }
        }

        glUniformMatrix4fv(locMVP, 1, GL_FALSE, starMvp);
        glBindVertexArray(starVao);
        glDrawArrays(GL_TRIANGLE_FAN, 0, (GLsizei)(starVertices.size() / 6));

        glBindVertexArray(0);
        window.Present();
    }

    // Cleanup
    glDeleteVertexArrays(1, &bgVao);
    glDeleteBuffers(1, &bgVbo);
    glDeleteBuffers(1, &bgEbo);
    glDeleteVertexArrays(1, &starVao);
    glDeleteBuffers(1, &starVbo);
    glDeleteProgram(program);

    return 0;
}