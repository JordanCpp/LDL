/*
* -----------------------------------------------------------------------------
* Example 10: 2D Cloth Simulation (Verlet Integration)
* Demonstrates: Verlet Physics, Constraints, and Mass-Spring systems.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <cmath>
#include <LDL/C++98/LDL.hpp>

struct Point {
    float x, y;
    float oldX, oldY;
    bool pinned;

    Point(float _x, float _y, bool _p) : x(_x), y(_y), oldX(_x), oldY(_y), pinned(_p) {}
};

struct Link {
    int p1, p2;
    float distance;
};

class Cloth {
public:
    std::vector<Point> points;
    std::vector<Link> links;
    float gravity;

    Cloth() : gravity(500.0f) {
        int width = 15;
        int height = 12;
        // Create points
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool isPinned = (y == 0); // Pin the top row
                points.push_back(Point(300.0f + x * 20.0f, 100.0f + y * 20.0f, isPinned));
            }
        }
        // Create links
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x < width - 1) addLink(y * width + x, y * width + (x + 1));
                if (y < height - 1) addLink(y * width + x, (y + 1) * width + x);
            }
        }
    }

    void addLink(int i, int j) {
        float dx = points[i].x - points[j].x;
        float dy = points[i].y - points[j].y;
        links.push_back({ i, j, sqrtf(dx * dx + dy * dy) });
    }

    void Update(float dt) {
        // 1. Verlet Integration
        for (size_t i = 0; i < points.size(); ++i) {
            if (points[i].pinned) continue;

            float vx = points[i].x - points[i].oldX;
            float vy = points[i].y - points[i].oldY;

            points[i].oldX = points[i].x;
            points[i].oldY = points[i].y;

            points[i].x += vx;
            points[i].y += vy + gravity * dt * dt;
    }

    // 2. Constraints (Satisfy links)
    for (int iter = 0; iter < 5; ++iter) {
        for (size_t i = 0; i < links.size(); ++i) {
            Point& p1 = points[links[i].p1];
            Point& p2 = points[links[i].p2];

            float dx = p2.x - p1.x;
            float dy = p2.y - p1.y;
            float dist = sqrtf(dx * dx + dy * dy);
            float diff = (dist - links[i].distance) / dist;

            float offsetX = dx * 0.5f * diff;
            float offsetY = dy * 0.5f * diff;

            if (!p1.pinned) { p1.x += offsetX; p1.y += offsetY; }
            if (!p2.pinned) { p2.x -= offsetX; p2.y -= offsetY; }
        }
    }
}

void Render(LDL::Render& render) {
    render.SetColor(LDL::Color(200, 200, 200));
    for (size_t i = 0; i < links.size(); ++i) {
        render.Line(
            LDL::Vec2i((int)points[links[i].p1].x, (int)points[links[i].p1].y),
            LDL::Vec2i((int)points[links[i].p2].x, (int)points[links[i].p2].y)
        );
    }
}
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Verlet Cloth Simulation", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    Cloth cloth;
    float deltaTime = 0.0f;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;
        if (deltaTime > 0.02f) deltaTime = 0.02f; // Cap dt to prevent explosion

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        cloth.Update(deltaTime);

        render.Begin();
        render.SetColor(LDL::Color(10, 15, 25));
        render.Clear();
        cloth.Render(render);
        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
