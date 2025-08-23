// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <vector>
#include <LDL/LDL.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Enums;
using namespace LDL::Math;

int main()
{
	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "12_TileMap2");
	Render render(result, renderContext, &window);

	Event report;

	FixedLinear allocator(Allocator::Mb * 8);
	ImageLoader loader(&allocator);

	loader.Load("Data/SeasonsTiles.png");
	Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	FpsCounter fpsCounter;
	Convert convert;
	FpsLimiter fpsLimiter;

	Isometric isometric;

	Vec2u start = Vec2u(550, 0);
	Vec2u mapSize = Vec2u(9, 9);
	Vec2u tileSize = Vec2u(128, 64);

	size_t dx = 0;
	size_t dy = 0;
	size_t step = tileSize.x / 2;

	std::vector<size_t> tilesX;
	std::vector<size_t> tilesY;

	tilesX.resize(mapSize.x * mapSize.y);
	tilesY.resize(mapSize.x * mapSize.y);

	Random random;

	for (size_t i = 0; i < mapSize.x * mapSize.y; i++)
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

		render.Color(Color(0, 162, 232));
		render.Clear();

		size_t j = 0;

		for (size_t rows = 0; rows < mapSize.x; rows++)
		{
			for (size_t cols = 0; cols < mapSize.y; cols++)
			{
				size_t x = cols * tileSize.x / 2;
				size_t y = rows * tileSize.y;

				Vec2u pt = isometric.CartesianToIsometric(Vec2u(x, y));

				size_t tx = tileSize.x * tilesX[j];
				size_t ty = tileSize.y * tilesY[j];
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
