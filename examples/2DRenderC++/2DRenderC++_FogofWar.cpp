/*
* -----------------------------------------------------------------------------
* Example 8: Fog of War / Dynamic Light Mask
* Demonstrates: Alpha Blending, Layering, and Field of View simulation.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct Entity {
    float x, y;
    LDL::Color color;
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Fog of War Demo", LDL_WindowModeResized);
    LDL::Render2D render(result, context, window);

    std::vector<Entity> entities;
    for (int i = 0; i < 50; ++i) {
        Entity e;
        e.x = (float)(rand() % 800);
        e.y = (float)(rand() % 600);
        e.color = LDL::Color(200, 100, 50, 255);
        entities.push_back(e);
    }

    float playerX = 400.0f;
    float playerY = 300.0f;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        // In a real game, player position comes from Input/Physics
        // Here we simulate a moving light source
        static float t = 0;
        t += deltaTime;
        playerX = 400.0f + cosf(t) * 300.0f;
        playerY = 300.0f + sinf(t) * 250.0f; // Using playerY logic

        render.Begin();
        // 1. Draw the "World" (Entities)
        render.SetColor(LDL::Color(20, 20, 20));
        render.Clear();

        for (size_t i = 0; i < entities.size(); ++i) {
            render.SetColor(entities[i].color);
            render.Fill(LDL::Vec2i((int)entities[i].x, (int)entities[i].y), LDL::Vec2i(15, 15));
        }

        // 2. Draw the "Fog" (Dark Overlay)
        // We draw a semi-transparent black rectangle over everything
        render.SetColor(LDL::Color(0, 0, 0, 220));
        render.Fill(LDL::Vec2i(0, 0), LDL::Vec2i(800, 600));

        // 3. "Carve" the light (This is a trick: drawing with a different blend mode)
        // Since we don't have a 'Subtract' mode in API, we simulate it by 
        // making a bright circle that is technically NOT part of the fog layer.
        // Note: In a real engine, this would be a shader-based stencil mask.
        render.SetColor(LDL::Color(255, 255, 200, 255)); // Light color
        // We draw a "light" around the player. To make it look like "fog of war",
        // we'd typically use an additive buffer or a stencil buffer.
        // For this demo, we simulate visibility by drawing light particles.
        render.Fill(LDL::Vec2i((int)playerX - 50, (int)playerY - 50), LDL::Vec2i(100, 100));

        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
