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

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <LDL/Ext/stb_image_write.h>

const char* vertexShaderSource =
"#version 130\n"
"in vec2 aPos;\n"
"in vec2 aTexCoord;\n"
"out vec2 vTexCoord;\n"
"uniform mat4 uMVP;\n"
"void main()\n"
"{\n"
"    gl_Position = uMVP * vec4(aPos, 0.0, 1.0);\n"
"    vTexCoord = aTexCoord;\n"
"}\n";

const char* fragmentShaderSource =
"#version 130\n"
"in vec2 vTexCoord;\n"
"out vec4 fragColor;\n"
"uniform sampler2D uTexture;\n"
"void main()\n"
"{\n"
"    fragColor = texture(uTexture, vTexCoord);\n"
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

// Generate a simple procedural texture atlas (2x2 grid of colored shapes)
// Frame 0: Red circle
// Frame 1: Green square
// Frame 2: Blue triangle
// Frame 3: Yellow star-like pattern
void GenerateAtlasTexture(unsigned char* pixels, int atlasSize)
{
    int halfSize = atlasSize / 2;
    int cx0 = halfSize / 2;
    int cy0 = halfSize / 2;
    int cx1 = halfSize + halfSize / 2;
    int cy1 = halfSize / 2;
    int cx2 = halfSize / 2;
    int cy2 = halfSize + halfSize / 2;
    int cx3 = halfSize + halfSize / 2;
    int cy3 = halfSize + halfSize / 2;

    for (int y = 0; y < atlasSize; ++y)
    {
        for (int x = 0; x < atlasSize; ++x)
        {
            int idx = (y * atlasSize + x) * 4;
            int frameX = x < halfSize ? 0 : 1;
            int frameY = y < halfSize ? 0 : 1;
            int localX = x - frameX * halfSize;
            int localY = y - frameY * halfSize;

            unsigned char r = 30, g = 30, b = 30, a = 255;

            if (frameX == 0 && frameY == 0)
            {
                // Frame 0: red circle
                int dx = localX - cx0;
                int dy = localY - cy0;
                if (dx * dx + dy * dy < (halfSize / 3) * (halfSize / 3))
                {
                    r = 220; g = 60; b = 60;
                }
            }
            else if (frameX == 1 && frameY == 0)
            {
                // Frame 1: green square
                int margin = halfSize / 5;
                if (localX >= margin && localX < halfSize - margin &&
                    localY >= margin && localY < halfSize - margin)
                {
                    r = 60; g = 200; b = 80;
                }
            }
            else if (frameX == 0 && frameY == 1)
            {
                // Frame 2: blue triangle (pointing up)
                if (localY < halfSize - localX && localY < localX)
                {
                    r = 60; g = 80; b = 220;
                }
            }
            else
            {
                // Frame 3: yellow diamond
                int dx = localX - cx3 + halfSize;
                int dy = localY - cy3 + halfSize;
                if (abs(dx) + abs(dy) < halfSize / 2)
                {
                    r = 220; g = 200; b = 50;
                }
            }

            pixels[idx + 0] = r;
            pixels[idx + 1] = g;
            pixels[idx + 2] = b;
            pixels[idx + 3] = a;
        }
    }
}

// Generate sprite quad with UVs for a specific frame in the atlas
// Atlas is 2x2 grid, frame index 0..3
// Returns interleaved [x, y, u, v] vertices
void GenerateSpriteQuad(std::vector<float>& vertices,
    float x, float y, float size,
    int frame, int cols, int rows)
{
    float u0 = (float)(frame % cols) / cols;
    float v0 = (float)(frame / cols) / rows;
    float u1 = u0 + 1.0f / cols;
    float v1 = v0 + 1.0f / rows;

    float halfSize = size * 0.5f;

    // Triangle 1: top-left, bottom-left, top-right
    vertices.push_back(x - halfSize); vertices.push_back(y + halfSize);
    vertices.push_back(u0); vertices.push_back(v0);

    vertices.push_back(x - halfSize); vertices.push_back(y - halfSize);
    vertices.push_back(u0); vertices.push_back(v1);

    vertices.push_back(x + halfSize); vertices.push_back(y + halfSize);
    vertices.push_back(u1); vertices.push_back(v0);

    // Triangle 2: top-right, bottom-left, bottom-right
    vertices.push_back(x + halfSize); vertices.push_back(y + halfSize);
    vertices.push_back(u1); vertices.push_back(v0);

    vertices.push_back(x - halfSize); vertices.push_back(y - halfSize);
    vertices.push_back(u0); vertices.push_back(v1);

    vertices.push_back(x + halfSize); vertices.push_back(y - halfSize);
    vertices.push_back(u1); vertices.push_back(v1);
}

int main()
{
    LDL::Result  result;
    LDL::Context context(result);
    LDL::Event   event;
    LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600),
        "LDL Example 06 - Texture Atlas Animation", LDL_WindowModeResized);
    LDL::OpenGLLoader loader = LDL::OpenGLLoader(result, 3, 0);

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
        return -1;
    }

    int windowWidth = 800;
    int windowHeight = 600;
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glViewport(0, 0, windowWidth, windowHeight);

    // Enable blending for smooth edges
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLuint program = CreateProgram(vertexShaderSource, fragmentShaderSource);
    GLint locMVP = glGetUniformLocation(program, "uMVP");
    GLint locTexture = glGetUniformLocation(program, "uTexture");

    // Generate procedural texture atlas
    const int atlasSize = 256;
    const int atlasChannels = 4;
    std::vector<unsigned char> atlasPixels(atlasSize * atlasSize * atlasChannels);
    GenerateAtlasTexture(&atlasPixels[0], atlasSize);

    // Create OpenGL texture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, atlasSize, atlasSize, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, &atlasPixels[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Generate sprite quad vertices for all 4 frames
    // Each frame is 6 vertices * 4 floats = 24 floats
    // Total: 4 frames * 24 = 96 floats
    std::vector<float> allVertices;
    for (int frame = 0; frame < 4; ++frame)
    {
        GenerateSpriteQuad(allVertices, 0.0f, 0.0f, 0.5f, frame, 2, 2);
    }

    // Create VAO and VBO for sprite
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, allVertices.size() * sizeof(float),
        &allVertices[0], GL_STATIC_DRAW);

    // Position: location 0, 2 floats, stride 4 floats, offset 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // TexCoord: location 1, 2 floats, stride 4 floats, offset 2 floats
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
        (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    float animationTimer = 0.0f;
    float frameDuration = 0.25f; // 250ms per frame
    int currentFrame = 0;

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
                windowWidth = (int)event.u.Resize.Width;
                windowHeight = (int)event.u.Resize.Height;
                glViewport(0, 0, (GLsizei)windowWidth, (GLsizei)windowHeight);
            }
        }

        // Update animation
        animationTimer += 0.016f; // ~60fps delta
        if (animationTimer >= frameDuration)
        {
            animationTimer -= frameDuration;
            currentFrame = (currentFrame + 1) % 4;
        }

        // Build MVP matrix
        float aspect = (float)windowWidth / windowHeight;
        float scale = 1.2f;
        float proj[16] = {
            scale / aspect, 0.0f, 0.0f, 0.0f,
            0.0f, scale, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        // Add gentle rotation
        float rotAngle = (float)currentFrame * 0.3f;
        float c = cosf(rotAngle);
        float s = sinf(rotAngle);
        float rot[16] = {
            c,   -s,  0.0f, 0.0f,
            s,    c,  0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

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

        // Bind texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glUniform1i(locTexture, 0);

        // Draw only the current frame's vertices (6 vertices starting at frame offset)
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, currentFrame * 6, 6);

        glBindVertexArray(0);
        window.Present();
    }

    // Cleanup
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteTextures(1, &texture);
    glDeleteProgram(program);

    return 0;
}
