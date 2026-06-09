/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <LDL/C++98/LDL.hpp>

int Random(int min, int max)
{
	int range = max - min + 1;

	return min + rand() % range;
}

LDL::Vec2i CartToIso(const LDL::Vec2i& pt)
{
	return LDL::Vec2i(pt.x - pt.y, (pt.x + pt.y) / 2);
}

int main()
{
	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 lesson 09 - Tile map", LDL_WindowModeResized);
	LDL::Render2D render(result, context, window);
	LDL::OpenGLLoader loader(result, 3, 0);
	LDL::BmpLoader bmpLoader(result);
	
	LDL::Vec2i start = LDL::Vec2i(550, 0);
	LDL::Vec2i mapSize = LDL::Vec2i(9, 9);
	LDL::Vec2i tileSize = LDL::Vec2i(128, 64);

	int dx = 0;
	int dy = 0;
	int step = tileSize.x / 2;

	std::vector<int> tilesX;
	std::vector<int> tilesY;

	tilesX.resize(mapSize.x * mapSize.y);
	tilesY.resize(mapSize.x * mapSize.y);

	for (int i = 0; i < mapSize.x * mapSize.y; i++)
	{
		tilesX[i] = Random(0, 7);
		tilesY[i] = Random(0, 5);
	}

	int count = 0;

	bmpLoader.Load("seasons_tiles.bmp");
	LDL::Surface surface(result, bmpLoader.GetPixelFormat(), bmpLoader.GetSize(), bmpLoader.GetPixels());
	surface.SetColorKey(LDL::Color(255, 255, 255));

	LDL::Texture texture(result, context, &surface);

	while (window.IsRunning() && result.IsOk())
	{
		while (window.GetEvent(event))
		{
			if (event.IsKeyPressed(LDL_KeyE))
			{
				count++;

				mapSize.x =+ count;
				mapSize.y =+ count;

				tilesX.resize(mapSize.x * mapSize.y);
				tilesY.resize(mapSize.x * mapSize.y);

				for (int i = 0; i < mapSize.x * mapSize.y; i++)
				{
					tilesX[i] = Random(0, 7);
					tilesY[i] = Random(0, 5);
				}
			}

			if (event.IsKeyPressed(LDL_KeyQ))
			{
				for (int i = 0; i < mapSize.x * mapSize.y; i++)
				{
					tilesX[i] = Random(0, 7);
					tilesY[i] = Random(0, 5);
				}
			}

			if (event.IsKeyPressed(LDL_KeyW))
			{
				dy -= step;
			}

			if (event.IsKeyPressed(LDL_KeyS))
			{
				dy += step;
			}

			if (event.IsKeyPressed(LDL_KeyA))
			{
				dx -= step;
			}

			if (event.IsKeyPressed(LDL_KeyD))
			{
				dx += step;
			}

			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.SetColor(LDL::Color(255, 127, 39));
		render.Clear();

		int j = 0;

		for (int rows = 0; rows < mapSize.x; rows++)
		{
			for (int cols = 0; cols < mapSize.y; cols++)
			{
				LDL::Vec2i pt = CartToIso(LDL::Vec2i(cols * tileSize.x / 2, rows * tileSize.y));
				LDL::Vec2i tz = LDL::Vec2i(tileSize.x * tilesX[j], tileSize.y * tilesY[j]);
				j++;

				render.Draw(&texture, LDL::Vec2i(start.x + pt.x + dx, start.y + pt.y + dy), tileSize, tz, tileSize);
			}
		}
		
		render.End();
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
