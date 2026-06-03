/*
 * -----------------------------------------------------------------------------
 * Example 03 - Archimedean Spiral
 * Draws a parametric spiral using GL_LINE_STRIP with configurable
 * line width and color gradient. Demonstrates dynamic vertex generation
 * of parametric curves and line rendering.
 * Public domain (CC0 1.0 Universal)
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

// Archimedean spiral: r = a + b * theta
// Returns interleaved [x, y, r, g, b] vertices
void GenerateSpiral(std::vector<float>& vertices,
    float a, float b, float maxTheta, int steps)
{
    vertices.clear();
    vertices.reserve(steps * 5);

    for (int i = 0; i < steps; ++i)
    {
        float t = (float)i / (steps - 1);          // 0..1
        float theta = t * maxTheta;
        float r = a + b * theta;
        float x = r * cosf(theta);
        float y = r * sinf(theta);

        vertices.push_back(x);
        vertices.push_back(y);

        // Color gradient: hue shifts from red to violet along spiral
        float hue = t; // 0..1
        float red, green, blue;
        // Simple hue-to-RGB (rainbow)
        int segment = int(hue * 6.0f) % 6;
        float frac = hue * 6.0f - segment;
        float q = 1.0f - frac;
        switch (segment)
        {
        case 0: red = 1.0f; green = frac; blue = 0.0f; break;
        case 1: red = q;    green = 1.0f; blue = 0.0f; break;
        case 2: red = 0.0f; green = 1.0f; blue = frac; break;
        case 3: red = 0.0f; green = q;    blue = 1.0f; break;
        case 4: red = frac; green = 0.0f; blue = 1.0f; break;
        case 5: red = 1.0f; green = 0.0f; blue = q;    break;
        default: red = green = blue = 0.0f; break;
        }
        vertices.push_back(red);
        vertices.push_back(green);
        vertices.push_back(blue);
    }
}

int main()
{
    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;
    LDL::Window  window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Example 03 - Archimedean Spiral", LDL_WindowModeResized);
    LDL::OpenGLLoader loader(result, 3, 0);

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
        return -1;
    }

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    GLuint program = CreateProgram(vertexShaderSource, fragmentShaderSource);
    GLint locMVP = glGetUniformLocation(program, "uMVP");

    // Generate spiral geometry
    std::vector<float> vertices;
    GenerateSpiral(vertices, 0.0f, 0.08f, 8.0f * 3.14159265f, 600);

    // Create VAO and VBO
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    // Position: location 0, 2 floats, stride 5 floats, offset 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color: location 1, 3 floats, stride 5 floats, offset 2 floats
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // Enable line width (note: deprecated in core profile but widely supported)
    glLineWidth(2.5f);

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

        rotation += 0.01f;

        // Orthographic projection
        float aspect = 800.0f / 600.0f;
        float scale = 0.55f; // zoom out to see full spiral
        float proj[16] = {
            scale / aspect, 0.0f, 0.0f, 0.0f,
            0.0f, scale, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        // Rotation around Z
        float c = cosf(rotation);
        float s = sinf(rotation);
        float rot[16] = {
            c,   -s,  0.0f, 0.0f,
            s,    c,  0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        // MVP = proj * rot (column-major)
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

        // Draw as line strip (continuous line through all vertices)
        GLsizei vertexCount = (GLsizei)(vertices.size() / 5);
        glDrawArrays(GL_LINE_STRIP, 0, vertexCount);

        glBindVertexArray(0);
        window.Present();
    }

    // Cleanup
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(program);

    return 0;
}