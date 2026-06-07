/*
* -----------------------------------------------------------------------------
* Example 3: Procedural Landscape (Sine-wave Noise Approximation)
* Demonstrates: Layering, Color Interpolation, and Perlin-like Smoothness.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

struct LandscapeLayer {
    float amplitude;
    float frequency;
    float phase;
    float speed;
    LDL::Color color;
    LandscapeLayer(float amplitudeV, float frequencyV, float phaseV, float speedV, const LDL::Color& colorV) :
         amplitude(amplitudeV),
     frequency(frequencyV),
     phase(phaseV),
     speed(speedV),
     color(colorV)
    {

    }
};

class LandscapeGenerator {
    public:
        std::vector<LandscapeLayer> layers;

public:
    LandscapeGenerator() {
        // Layer 1: Far background (Darker, slow)
        layers.push_back(LandscapeLayer(200.0f, 0.005f, 0.0f, 0.2f, LDL::Color(20, 40, 60, 255)));
        // Layer 2: Middle ground
        layers.push_back(LandscapeLayer(100.0f, 0.01f, 0.0f, 0.5f, LDL::Color(30, 80, 40, 255)));
        // Layer 3: Near foreground (Brighter, faster)
        layers.push_back(LandscapeLayer(50.0f, 0.02f, 0.0f, 1.2f, LDL::Color(50, 150, 60, 255)));
    }

    void Update(float deltaTime) {
        for (size_t i = 0;layers.size(); ++i) {
            layers[i].phase += layers[i].speed * deltaTime;
        }
    }

    void Render(LDL::Render& render, int width, int height) {
        for (size_t i = 0; i < layers.size(); ++i) {
            render.SetColor(layers[i].color);

            // We draw the landscape as a series of vertical strips to simulate waves
            // In a real engine, this would be a triangle strip/mesh.
            for (int x = 0; x < width; x += 4) { // Step by 4 for performance
                float waveY = (float)height - 150.0f; // Base height

                // Combine sine waves to simulate complex noise
                float yOffset = sinf(x * layers[i].frequency + layers[i].phase) * layers[i].amplitude;
                yOffset += sinf(x * (layers[i].frequency * 2.5f) + layers[i].phase * 0.5f) * (layers[i].amplitude * 0.3f);

                float finalY = waveY + yOffset;

                render.Fill(LDL::Vec2i(x, (int)finalY), LDL::Vec2i(4, height - (int)finalY));
            }
        }
    }
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Procedural Landscape", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    LandscapeGenerator landscape;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        landscape.Update(deltaTime);

        render.Begin();
        render.SetColor(LDL::Color(10, 10, 15));
        render.Clear();

        landscape.Render(render, 800, 600);

        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
