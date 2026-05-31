/*
 * -----------------------------------------------------------------------------
 * Example 02 - Checkerboard
 * Renders an 8x8 grid of colored quads using index buffer.
 * Demonstrates element rendering (glDrawElements), index buffers,
 * and procedural geometry generation without textures.
 * Public domain (CC0 1.0 Universal)
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>
#include <LDL/OpenGL/GL3_0.h>

const char* vertexShaderSource =
"#version 130\n"
"in vec2 aPos;\n"
"in vec3 aColor;\n"
"out vec3 vColor;\n"
"uniform mat4 uMVP;\n"
"void main()\n"
"{\n"
"    gl_Position = uMVP * vec4(aPos, 0.0, 1.0);\n"
"    vColor = aColor;\n"
"}\n";

const char* fragmentShaderSource =
"#version 130\n"
"in vec3 vColor;\n"
"out vec4 fragColor;\n"
"void main()\n"
"{\n"
"    fragColor = vec4(vColor, 1.0);\n"
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

// Build 8x8 checkerboard: (8+1)x(8+1) vertices forming 64 quads
// Each quad is 2 triangles = 6 indices
// Colors: dark and light squares alternating
void BuildCheckerboard(std::vector<float>& vertices, std::vector<unsigned int>& indices,int gridSize, float cellSize)
{
    const int vertsPerSide = gridSize + 1;

    // Generate vertices (position + color interleaved: 5 floats per vertex)
    for (int row = 0; row < vertsPerSide; ++row)
    {
        for (int col = 0; col < vertsPerSide; ++col)
        {
            // Position: center the board around origin
            float x = (col - gridSize * 0.5f) * cellSize;
            float y = (row - gridSize * 0.5f) * cellSize;
            vertices.push_back(x);
            vertices.push_back(y);

            // Color: alternating based on (row + col) parity
            bool isDark = ((row + col) % 2) == 0;
            if (isDark)
            {
                vertices.push_back(0.2f); // r
                vertices.push_back(0.2f); // g
                vertices.push_back(0.3f); // b
            }
            else
            {
                vertices.push_back(0.8f); // r
                vertices.push_back(0.75f); // g
                vertices.push_back(0.7f); // b
            }
        }
    }

    // Generate indices: 2 triangles per cell, 6 indices per cell
    for (int row2 = 0; row2 < gridSize; ++row2)
    {
        for (int col2 = 0; col2 < gridSize; ++col2)
        {
            unsigned int topLeft = row2 * vertsPerSide + col2;
            unsigned int topRight = topLeft + 1;
            unsigned int bottomLeft = (row2 + 1) * vertsPerSide + col2;
            unsigned int bottomRight = bottomLeft + 1;

            // First triangle: top-left, bottom-left, top-right
            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);

            // Second triangle: top-right, bottom-left, bottom-right
            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }
}

int main()
{
    LDL::Result  result;
    LDL::Context context;
    LDL::Event   event;
    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600),
        "LDL Example 02 - Checkerboard", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
        return -1;
    }

    // Setup OpenGL state
    glClearColor(0.15f, 0.15f, 0.2f, 1.0f);

    // Create shader program
    GLuint program = CreateProgram(vertexShaderSource, fragmentShaderSource);
    GLint locMVP = glGetUniformLocation(program, "uMVP");

    // Build geometry
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    const int gridSize = 8;
    const float cellSize = 0.18f;
    BuildCheckerboard(vertices, indices, gridSize, cellSize);

    // Create VAO, VBO, EBO
    GLuint vao, vbo, ebo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    // Upload vertex data
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    // Upload index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // Position attribute (location 0): 2 floats, stride 5 floats, offset 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute (location 1): 3 floats, stride 5 floats, offset 2 floats
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    float angle = 0.0f;

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

        // Gentle rotation for visual interest
        angle += 0.008f;

        // Orthographic projection matrix (column-major)
        float aspect = 800.0f / 600.0f;
        float proj[16] = {
            1.0f / aspect, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        // Rotation around Z
        float c = cosf(angle);
        float s = sinf(angle);
        float rot[16] = {
            c,   -s,  0.0f, 0.0f,
            s,    c,  0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        // MVP = proj * rot (column-major multiplication)
        float mvp[16];
        for (int col = 0; col < 4; ++col)
        {
            for (int row = 0; row < 4; ++row)
            {
                mvp[col * 4 + row] = 0.0f;
                for (int k = 0; k < 4; ++k)
                {
                    mvp[col * 4 + row] += proj[k * 4 + row] * rot[col * 4 + k];
                }
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glUniformMatrix4fv(locMVP, 1, GL_FALSE, mvp);
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, (GLsizei)indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        window.Present();
    }

    // Cleanup
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteProgram(program);

    return 0;
}