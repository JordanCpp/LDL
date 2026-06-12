/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <LDL/C++98/LDL.hpp>
#include <LDL/C++98/GlmLite.hpp>

size_t fvf = LDL_FVF_XYZ | LDL_FVF_COLOR;

struct Vertex
{
    float x, y, z;
    float r, g, b;
};

Vertex data[] =
{
    { 0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f},
    {-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f},
    { 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f}
};

int main() 
{
    const float width  = 800.0f;
    const float height = 600.0f;

    LDL::Result     result;
    LDL::Context    context(result, LDL::Context::GLModern);
    LDL::FpsLimiter limiter(result);
    LDL::Event      event;
    LDL::Window     window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i((int)width, (int)height), "LDL 3D Render - Triangle rotate", LDL::Window::Resized);
    LDL::Render3D   render(result, context, window);

    LDL::VertexBuffer vertexBuffer(context, fvf);
    vertexBuffer.Copy(sizeof(Vertex), 3, data);

    float rotationAngle = 0.0f;

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    while (window.IsRunning() && result.IsOk()) 
    {
        limiter.Mark();

        while (window.GetEvent(event))
        {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
            {
                window.StopEvent();
            }
        }

        rotationAngle += 0.02f;

        glm::mat4 model = glm::mat4(1.0f);

        model = glm::rotate(model, rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));

        render.SetProjection(glm::value_ptr(projection));
        render.SetView(glm::value_ptr(view));
        render.SetWorld(glm::value_ptr(model));

        render.Begin();
        render.Clear(0.1f, 0.1f, 0.1f);
        render.Draw(&vertexBuffer);
        render.End();

        limiter.Throttle();
    }

    return result.IsOk() ? 0 : -1;
}
