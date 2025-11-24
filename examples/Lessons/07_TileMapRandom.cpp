// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

void ErrorShow(LDL_Result& result)
{
	printf("LDL error: %s", result.Message());
}

uint32_t CartToIsoX(const LDL_Vec2u& pt)
{
	return pt.x - pt.y;
}

uint32_t CartToIsoY(const LDL_Vec2u& pt)
{
	return (pt.x + pt.y) / 2;
}

LDL_IWindow* window = NULL;
LDL_IRender* render = NULL;
LDL_ITexture* image = NULL;

void CleanUp()
{
	if (image != NULL)
	{
		delete image;
	}

	if (render != NULL)
	{
		delete render;
	}

	if (window != NULL)
	{
		delete window;
	}
}

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result result;
	LDL_RenderContext renderContext;

	window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(800, 600), __FILE__, 0);
	if (!result.Ok())
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	render = LDL_CreateRender(result, renderContext, window);
	if (!result.Ok())
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	LDL_Event report;

	LDL_BmpLoader bmpLoader(result);

	if (!bmpLoader.Load("data/SeasonsTiles.bmp"))
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	LDL_Surface surface(bmpLoader.Format(), bmpLoader.Size(), bmpLoader.Pixels());

	surface.ColorKey(LDL_Color(255, 255, 255));
	
	image = LDL_CreateTexture(&renderContext,  &surface);

	LDL_FpsCounter fpsCounter;
	LDL_Convert    convert;
	LDL_FpsLimiter fpsLimiter;

	LDL_Vec2u start    = LDL_Vec2u(550, 0);
	LDL_Vec2u mapSize  = LDL_Vec2u(9, 9);
	LDL_Vec2u tileSize = LDL_Vec2u(128, 64);

	uint32_t dx   = 0;
	uint32_t dy   = 0;
	uint32_t step = tileSize.x / 2;

	LDL_PodVector<uint32_t> tilesX;
	LDL_PodVector<uint32_t> tilesY;

	tilesX.resize(mapSize.x * mapSize.y);
	tilesY.resize(mapSize.x * mapSize.y);

	LDL_Random random;

	for (uint32_t i = 0; i < mapSize.x * mapSize.y; i++)
	{
		tilesX[i] = random.Range(0, 7);
		tilesY[i] = random.Range(0, 5);
	}

	while (window->Running())
	{
		fpsLimiter.Mark();

		fpsCounter.Start();

		while (window->GetEvent(report))
		{
			if (report.IsKeyPressed(LDL_KeyboardKey::Q))
			{
				for (uint32_t i = 0; i < mapSize.x * mapSize.y; i++)
				{
					tilesX[i] = random.Range(0, 7);
					tilesY[i] = random.Range(0, 5);
				}
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::W))
			{
				dy -= step;
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::S))
			{
				dy += step;;
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::A))
			{
				dx -= step;;
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::D))
			{
				dx += step;;
			}

			if (report.Type == IsQuit)
			{
				window->StopEvent();
			}
		}

		render->Begin();

		render->SetColor(LDL_Color(0, 162, 232));
		render->Clear();

		uint32_t j = 0;

		for (uint32_t rows = 0; rows < mapSize.x; rows++)
		{
			for (uint32_t cols = 0; cols < mapSize.y; cols++)
			{
				uint32_t x = cols * tileSize.x / 2;
				uint32_t y = rows * tileSize.y;

				uint32_t isoX = CartToIsoX(LDL_Vec2u(x, y));
				uint32_t isoY = CartToIsoY(LDL_Vec2u(x, y));

				LDL_Vec2u pt = LDL_Vec2u(isoX, isoY);

				uint32_t tx = tileSize.x * tilesX[j];
				uint32_t ty = tileSize.y * tilesY[j];
				j++;

				render->Draw(image, LDL_Vec2u(start.x + pt.x + dx, start.y + pt.y + dy), LDL_Vec2u(tx, ty), tileSize);
			}
		}

		render->End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	CleanUp();

	return 0;
}
