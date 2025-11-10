// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

using namespace LDL;

void ErrorShow(Result& result)
{
	printf("LDL error: %s", result.Message());
}

uint32_t CartToIsoX(const Vec2u& pt)
{
	return pt.x - pt.y;
}

uint32_t CartToIsoY(const Vec2u& pt)
{
	return (pt.x + pt.y) / 2;
}

int main()
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), __FILE__);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	Render render(result, renderContext, &window);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	Event report;

	BmpLoader bmpLoader(result);

	bmpLoader.Load("data/SeasonsTiles.bmp");

	Surface surface(bmpLoader.Format(), bmpLoader.Size(), bmpLoader.Pixels());

	surface.ColorKey(Color(255, 255, 255));

	Texture image(&renderContext,  &surface);

	FpsCounter fpsCounter;
	Convert    convert;
	FpsLimiter fpsLimiter;

	Vec2u start    = Vec2u(550, 0);
	Vec2u mapSize  = Vec2u(9, 9);
	Vec2u tileSize = Vec2u(128, 64);

	uint32_t dx   = 0;
	uint32_t dy   = 0;
	uint32_t step = tileSize.x / 2;

	vector<uint32_t> tilesX;
	vector<uint32_t> tilesY;

	tilesX.resize(mapSize.x * mapSize.y);
	tilesY.resize(mapSize.x * mapSize.y);

	Random random;

	for (uint32_t i = 0; i < mapSize.x * mapSize.y; i++)
	{
		tilesX[i] = random.Range(0, 7);
		tilesY[i] = random.Range(0, 5);
	}

	while (window.Running())
	{
		fpsLimiter.Mark();

		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.IsKeyPressed(KeyboardKey::Q))
			{
				for (uint32_t i = 0; i < mapSize.x * mapSize.y; i++)
				{
					tilesX[i] = random.Range(0, 7);
					tilesY[i] = random.Range(0, 5);
				}
			}

			if (report.IsKeyPressed(KeyboardKey::W))
			{
				dy -= step;
			}

			if (report.IsKeyPressed(KeyboardKey::S))
			{
				dy += step;;
			}

			if (report.IsKeyPressed(KeyboardKey::A))
			{
				dx -= step;;
			}

			if (report.IsKeyPressed(KeyboardKey::D))
			{
				dx += step;;
			}

			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.SetColor(Color(0, 162, 232));
		render.Clear();

		uint32_t j = 0;

		for (uint32_t rows = 0; rows < mapSize.x; rows++)
		{
			for (uint32_t cols = 0; cols < mapSize.y; cols++)
			{
				uint32_t x = cols * tileSize.x / 2;
				uint32_t y = rows * tileSize.y;

				uint32_t isoX = CartToIsoX(Vec2u(x, y));
				uint32_t isoY = CartToIsoY(Vec2u(x, y));

				Vec2u pt = Vec2u(isoX, isoY);

				uint32_t tx = tileSize.x * tilesX[j];
				uint32_t ty = tileSize.y * tilesY[j];
				j++;

				render.Draw(&image, Vec2u(start.x + pt.x + dx, start.y + pt.y + dy), Vec2u(tx, ty), tileSize);
			}
		}

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
