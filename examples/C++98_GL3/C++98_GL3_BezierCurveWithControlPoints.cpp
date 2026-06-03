/*
 * -----------------------------------------------------------------------------
 * Example 05 - Bezier Curve with Interactive Control Points
 * Renders a cubic Bezier curve with 4 draggable control points.
 * Left mouse button drags the nearest control point.
 * Demonstrates dynamic VBO updates, mouse input handling,
 * and parametric curve evaluation.
 * Public domain (CC0 1.0 Universal)
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <float.h>
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

// Evaluate cubic Bezier at parameter t (0..1)
// B(t) = (1-t)^3*P0 + 3*(1-t)^2*t*P1 + 3*(1-t)*t^2*P2 + t^3*P3
void EvaluateBezier(float t, float p0x, float p0y, float p1x, float p1y,
    float p2x, float p2y, float p3x, float p3y,
    float& outX, float& outY)
{
    float u = 1.0f - t;
    float u2 = u * u;
    float u3 = u2 * u;
    float t2 = t * t;
    float t3 = t2 * t;

    outX = u3 * p0x + 3.0f * u2 * t * p1x + 3.0f * u * t2 * p2x + t3 * p3x;
    outY = u3 * p0y + 3.0f * u2 * t * p1y + 3.0f * u * t2 * p2y + t3 * p3y;
}

// Generate curve vertices (line strip) and control point vertices (points)
void GenerateCurve(std::vector<float>& curveVertices,
    float p0x, float p0y, float p1x, float p1y,
    float p2x, float p2y, float p3x, float p3y,
    int segments)
{
    curveVertices.clear();
    for (int i = 0; i <= segments; ++i)
    {
        float t = (float)i / segments;
        float x, y;
        EvaluateBezier(t, p0x, p0y, p1x, p1y, p2x, p2y, p3x, p3y, x, y);

        // Gradient from blue (start) to red (end)
        curveVertices.push_back(x);
        curveVertices.push_back(y);
        curveVertices.push_back(t);           // r: 0->1
        curveVertices.push_back(0.2f);        // g
        curveVertices.push_back(1.0f - t);    // b: 1->0
        curveVertices.push_back(1.0f);        // a
    }
}

// Find index of nearest control point within threshold, returns -1 if none
int FindNearestPoint(float mouseX, float mouseY,
    const float points[4][2], float threshold)
{
    int nearest = -1;
    float minDist = threshold;

    for (int i = 0; i < 4; ++i)
    {
        float dx = mouseX - points[i][0];
        float dy = mouseY - points[i][1];
        float dist = sqrtf(dx * dx + dy * dy);
        if (dist < minDist)
        {
            minDist = dist;
            nearest = i;
        }
    }
    return nearest;
}

// Convert screen coordinates to world coordinates (simple ortho)
void ScreenToWorld(int screenX, int screenY, int windowWidth, int windowHeight,
    float& worldX, float& worldY)
{
    float aspect = (float)windowWidth / windowHeight;
    float scale = 0.8f;
    worldX = ((float)screenX / windowWidth * 2.0f - 1.0f) * aspect / scale;
    worldY = (1.0f - (float)screenY / windowHeight * 2.0f) / scale;
}

int main()
{
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL Example 05 - Bezier Curve", LDL_WindowModeResized);
    LDL::OpenGLLoader loader(result, 3, 0);

    if (result.IsFail())
    {
        std::cout << "LDL result error: " << result.Message() << std::endl;
        return -1;
    }

    int windowWidth = 800;
    int windowHeight = 600;
    glClearColor(0.08f, 0.08f, 0.13f, 1.0f);
    glViewport(0, 0, windowWidth, windowHeight);

    // Enable blending for control points
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLuint program = CreateProgram(vertexShaderSource, fragmentShaderSource);
    GLint locMVP = glGetUniformLocation(program, "uMVP");

    // Initial control points
    float points[4][2] = {
        {-0.6f, -0.3f},  // P0
        {-0.3f,  0.6f},  // P1
        { 0.3f, -0.5f},  // P2
        { 0.6f,  0.2f}   // P3
    };

    // Control point colors
    float pointColors[4][4] = {
        {1.0f, 0.3f, 0.3f, 1.0f},  // P0: red
        {0.3f, 1.0f, 0.3f, 1.0f},  // P1: green
        {0.3f, 0.3f, 1.0f, 1.0f},  // P2: blue
        {1.0f, 1.0f, 0.3f, 1.0f}   // P3: yellow
    };

    // Control polygon line vertices (lines connecting points)
    float polygonVertices[24]; // 4 points * 6 floats (pos + rgba)
    for (int i = 0; i < 4; ++i)
    {
        polygonVertices[i * 6 + 0] = points[i][0];
        polygonVertices[i * 6 + 1] = points[i][1];
        polygonVertices[i * 6 + 2] = 0.5f;
        polygonVertices[i * 6 + 3] = 0.5f;
        polygonVertices[i * 6 + 4] = 0.5f;
        polygonVertices[i * 6 + 5] = 0.4f;
    }

    // Curve vertices (dynamic)
    std::vector<float> curveVertices;
    GenerateCurve(curveVertices,
        points[0][0], points[0][1], points[1][0], points[1][1],
        points[2][0], points[2][1], points[3][0], points[3][1],
        200);

    // Create VAOs and VBOs
    // Control points (4 points rendered as GL_POINTS)
    GLuint pointsVao, pointsVbo;
    glGenVertexArrays(1, &pointsVao);
    glGenBuffers(1, &pointsVbo);
    glBindVertexArray(pointsVao);
    glBindBuffer(GL_ARRAY_BUFFER, pointsVbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 6 * sizeof(float), NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    // Control polygon (line strip through 4 points)
    GLuint polygonVao, polygonVbo;
    glGenVertexArrays(1, &polygonVao);
    glGenBuffers(1, &polygonVbo);
    glBindVertexArray(polygonVao);
    glBindBuffer(GL_ARRAY_BUFFER, polygonVbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 6 * sizeof(float), NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    // Curve (line strip)
    GLuint curveVao, curveVbo;
    glGenVertexArrays(1, &curveVao);
    glGenBuffers(1, &curveVbo);
    glBindVertexArray(curveVao);
    glBindBuffer(GL_ARRAY_BUFFER, curveVbo);
    glBufferData(GL_ARRAY_BUFFER, curveVertices.size() * sizeof(float), &curveVertices[0], GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    int draggedPoint = -1;
    bool mouseDown = false;

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

            // Mouse button down
            if (event.Type == LDL_EventIsMouseClick && event.u.Mouse.State == LDL_ButtonStatePressed && event.u.Mouse.Button == LDL_MouseButtonLeft)
            {
                float worldX, worldY;
                ScreenToWorld(event.u.Mouse.PosX, event.u.Mouse.PosY,
                    windowWidth, windowHeight, worldX, worldY);
                draggedPoint = FindNearestPoint(worldX, worldY, points, 0.12f);
                mouseDown = true;
            }

            // Mouse button up
            if (event.Type == LDL_EventIsMouseClick && event.u.Mouse.State == LDL_ButtonStateReleased && event.u.Mouse.Button == LDL_MouseButtonLeft)
            {
                draggedPoint = -1;
                mouseDown = false;
            }

            // Mouse move (drag)
            if (event.Type == LDL_EventIsMouseMove && mouseDown && draggedPoint >= 0)
            {
                float worldX, worldY;
                ScreenToWorld(event.u.Mouse.PosX, event.u.Mouse.PosY,
                    windowWidth, windowHeight, worldX, worldY);
                points[draggedPoint][0] = worldX;
                points[draggedPoint][1] = worldY;

                // Regenerate curve
                GenerateCurve(curveVertices,
                    points[0][0], points[0][1], points[1][0], points[1][1],
                    points[2][0], points[2][1], points[3][0], points[3][1],
                    200);
                glBindBuffer(GL_ARRAY_BUFFER, curveVbo);
                glBufferSubData(GL_ARRAY_BUFFER, 0,
                    curveVertices.size() * sizeof(float), &curveVertices[0]);
            }
        }

        // Update control point and polygon buffers
        float pointData[24];
        for (int i = 0; i < 4; ++i)
        {
            pointData[i * 6 + 0] = points[i][0];
            pointData[i * 6 + 1] = points[i][1];
            pointData[i * 6 + 2] = pointColors[i][0];
            pointData[i * 6 + 3] = pointColors[i][1];
            pointData[i * 6 + 4] = pointColors[i][2];
            pointData[i * 6 + 5] = pointColors[i][3];
        }

        glBindBuffer(GL_ARRAY_BUFFER, pointsVbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(pointData), pointData);

        float polygonData[24];
        for (int j = 0; j < 4; ++j)
        {
            polygonData[j * 6 + 0] = points[j][0];
            polygonData[j * 6 + 1] = points[j][1];
            polygonData[j * 6 + 2] = 0.5f;
            polygonData[j * 6 + 3] = 0.5f;
            polygonData[j * 6 + 4] = 0.5f;
            polygonData[j * 6 + 5] = 0.4f;
        }
        glBindBuffer(GL_ARRAY_BUFFER, polygonVbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(polygonData), polygonData);

        // Build MVP
        float aspect = (float)windowWidth / windowHeight;
        float scale = 0.8f;
        float proj[16] = {
            scale / aspect, 0.0f, 0.0f, 0.0f,
            0.0f, scale, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };

        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);

        // Draw control polygon (dashed look via stipple not available in core, use solid thin line)
        glLineWidth(1.5f);
        glUniformMatrix4fv(locMVP, 1, GL_FALSE, proj);
        glBindVertexArray(polygonVao);
        glDrawArrays(GL_LINE_STRIP, 0, 4);

        // Draw curve
        glLineWidth(3.0f);
        glBindVertexArray(curveVao);
        glDrawArrays(GL_LINE_STRIP, 0, (GLsizei)(curveVertices.size() / 6));

        // Draw control points
        glPointSize(14.0f);
        glBindVertexArray(pointsVao);
        glDrawArrays(GL_POINTS, 0, 4);

        glBindVertexArray(0);
        window.Present();
    }

    // Cleanup
    glDeleteVertexArrays(1, &pointsVao);
    glDeleteBuffers(1, &pointsVbo);
    glDeleteVertexArrays(1, &polygonVao);
    glDeleteBuffers(1, &polygonVbo);
    glDeleteVertexArrays(1, &curveVao);
    glDeleteBuffers(1, &curveVbo);
    glDeleteProgram(program);

    return 0;
}
