/*
 * -----------------------------------------------------------------------------
 * Example 01 - Color Fan
 * Renders a rotating fan of colored triangles using basic vertex attributes
 * and uniforms. Demonstrates VBO, VAO, shader program, and matrix uniform.
 * Public domain (CC0 1.0 Universal)
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <LDL/C++98/LDL.hpp>
#include <LDL/OpenGL/GL3_0.h>

 // Vertex shader: pass color from attribute, apply MVP matrix
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

// Fragment shader: output interpolated color
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

// Generate fan triangles: center + N points around circle
// Each triangle: center, point_i, point_(i+1)
// Colors: center white, points colored by HSV hue
void GenerateFan(std::vector<float>& vertices, int segments)
{
    vertices.clear();
    // Center vertex
    vertices.push_back(0.0f); // x
    vertices.push_back(0.0f); // y
    vertices.push_back(1.0f); // r
    vertices.push_back(1.0f); // g
    vertices.push_back(1.0f); // b

    for (int i = 0; i <= segments; ++i)
    {
        float angle = 2.0f * 3.14159265f * i / segments;
        float x = cosf(angle);
        float y = sinf(angle);
        // HSV to RGB simple conversion: hue varies, full saturation/value
        float h = (float)i / segments;
        float r, g, b;
        // Simple hue->rgb (6 segments)
        int hi = int(h * 6.0f) % 6;
        float f = h * 6.0f - hi;
        float q = 1.0f - f;
        switch (hi)
        {
        case 0: r = 1.0f; g = f;   b = 0.0f; break;
        case 1: r = q;    g = 1.0f; b = 0.0f; break;
        case 2: r = 0.0f; g = 1.0f; b = f;   break;
        case 3: r = 0.0f; g = q;    b = 1.0f; break;
        case 4: r = f;    g = 0.0f; b = 1.0f; break;
        case 5: r = 1.0f; g = 0.0f; b = q;    break;
        }
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(r);
        vertices.push_back(g);
        vertices.push_back(b);
    }
}

int main()
{
    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;
    LDL::Window  window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Example 01 - Color Fan", LDL_WindowModeResized);
    LDL::OpenGLLoader loader(result, 3, 0);

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
        return -1;
    }

    // Setup OpenGL state
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);

    // Create shader program
    GLuint program = CreateProgram(vertexShaderSource, fragmentShaderSource);
    GLint locMVP = glGetUniformLocation(program, "uMVP");

    // Generate geometry
    std::vector<float> vertices;
    const int segments = 32;
    GenerateFan(vertices, segments);

    // Create VAO and VBO
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    // Position attribute (location 0)
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color attribute (location 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
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

        // Update rotation
        rotation += 0.02f;
        if (rotation > 2.0f * 3.14159265f)
            rotation -= 2.0f * 3.14159265f;

        // Simple ortho projection with rotation
        float aspect = 800.0f / 600.0f;
        // Orthographic projection matrix (column-major)
        float proj[16] = {
            1.0f / aspect, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };
        // Rotation around Z
        float rot[16] = {
            cosf(rotation), -sinf(rotation), 0.0f, 0.0f,
            sinf(rotation),  cosf(rotation), 0.0f, 0.0f,
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
        glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);
        glBindVertexArray(0);

        window.Present();
    }

    // Cleanup
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(program);

    return 0;
}