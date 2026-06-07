/*
* ------------------------------------------------int
* Example 9: Conway's Game of Life
* Demonstrates: Grid-based logic, Massive primitive rendering, and State management.
* -----------------------------------------------------------------------------
*/

#include <time.h>
#include <vector>
#include <math.h>
#include <LDL/C++98/LDL.hpp>

const int GRID_W = 100;
const int GRID_H = 75;
const int CELL_SIZE = 8;

class GameOfLife {
public:
    bool grid[GRID_W][GRID_H];
    bool nextGrid[GRID_W][GRID_H];

    GameOfLife() {
        for (int x = 0; x < GRID_W; ++x) {
            for (int y = 0; y < GRID_H; ++y) {
                grid[x][y] = (rand() % 5 == 0); // 20% density
                nextGrid[x][y] = false;
            }
        }
    }

    void Update() {
        for (int x = 0; x < GRID_W; ++x) {
            for (int y = 0; y < GRID_H; ++y) {
                int neighbors = CountNeighbors(x, y);
                if (grid[x][y]) {
                    nextGrid[x][y] = (neighbors == 2 || neighbors == 3);
                }
                else {
                    nextGrid[x][y] = (neighbors == 3);
                }
            }
        }
        for (int x = 0; x < GRID_W; ++x) {
            for (int y = 0; y < GRID_H; ++y) {
                grid[x][y] = nextGrid[x][y];
            }
        }
    }

    int CountNeighbors(int cx, int cy) {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int nx = cx + i;
                int ny = cy + j;
                if (nx >= 0 && nx < GRID_W && ny >= 0 && ny < GRID_H) {
                    if (grid[nx][ny]) count++;
                }
            }
        }
        return count;
    }

    void Render(LDL::Render& render) {
        for (int x = 0; x < GRID_W; ++x) {
            for (int y = 0; y < GRID_H; ++y) {
                if (grid[x][y]) {
                    render.SetColor(LDL::Color(0, 255, 100));
                    render.Fill(LDL::Vec2i(x * CELL_SIZE, y * CELL_SIZE),
                        LDL::Vec2i(CELL_SIZE - 1, CELL_SIZE - 1));
                }
            }
        }
    }
};

int main() {
    LDL::Result result;
    LDL::Context context(result);
    LDL::Event event;
    LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "Conway's Game of Life", LDL_WindowModeResized);
    LDL::Render render(result, context, window);

    GameOfLife gol;
    float timer = 0;
    float deltaTime = 0;
    clock_t lastClock = clock();

    while (window.IsRunning() && result.IsOk()) {
        clock_t currentClock = clock();
        deltaTime = (float)(currentClock - lastClock) / CLOCKS_PER_SEC;
        lastClock = currentClock;
        timer += deltaTime;

        while (window.GetEvent(event)) {
            if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape)) window.StopEvent();
        }

        // Update logic at a fixed rate (e.g., 10 ticks per second)
        if (timer > 0.1f) {
            gol.Update();
            timer = 0;
        }

        render.Begin();
        render.SetColor(LDL::Color(10, 10, 10));
        render.Clear();
        gol.Render(render);
        render.End();
    }
    return result.IsOk() ? 0 : -1;
}
