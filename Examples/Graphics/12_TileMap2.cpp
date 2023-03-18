#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Isometric.hpp>
#include <vector>
#include <time.h>

using namespace LDL::Graphics;

size_t Random(size_t min, size_t max)
{
	return min + (rand() % (max - min + 1));
}

int main()
{
	try
	{
		srand((uint32_t)time(NULL));

		Window window(Point2u(0, 0), Point2u(800, 600), "12_TileMap2");
		Render render(&window);

		LDL::Events::Event report;

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 8);
		LDL::Loaders::ImageLoader loader(&allocator);

		loader.Load("SeasonsTiles.png");
		Texture image(&render, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;
		LDL::Time::FpsLimiter fpsLimiter;

		Isometric isometric;

		Point2u start = Point2u(550, 0);
		Point2u mapSize = Point2u(9, 9);
		Point2u tileSize = Point2u(128, 64);

		size_t dx = 0;
		size_t dy = 0;
		size_t step = tileSize.PosX() / 2;

		std::vector<size_t> tilesX;
		std::vector<size_t> tilesY;

		tilesX.resize(mapSize.PosX() * mapSize.PosY());
		tilesY.resize(mapSize.PosX() * mapSize.PosY());

		for (size_t i = 0; i < mapSize.PosX() * mapSize.PosY(); i++)
		{
			tilesX[i] = Random(0, 7);
			tilesY[i] = Random(0, 5);
		}

		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			size_t j = 0;

			for (size_t rows = 0; rows < mapSize.PosX(); rows++)
			{
				for (size_t cols = 0; cols < mapSize.PosY(); cols++)
				{
					size_t x = cols * tileSize.PosX() / 2;
					size_t y = rows * tileSize.PosY();

					Point2u pt = isometric.CartesianToIsometric(Point2u(x, y));

					size_t tx = tileSize.PosX() * tilesX[j];
					size_t ty = tileSize.PosY() * tilesY[j];
					j++;
					
					render.Draw(&image, Point2u(start.PosX() + pt.PosX() + dx, start.PosY() + pt.PosY() + dy), Point2u(tx, ty), tileSize);
				}
			}

			render.End();

			fpsLimiter.Throttle();

			if (report.Type == LDL::Events::IsKeyboard && report.Keyboard.State == LDL::Enums::ButtonState::Pressed)
			{
				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::W)
				{
					dy -= step;
				}

				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::S)
				{
					dy += step;;
				}

				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::A)
				{
					dx -= step;;
				}

				if (report.Keyboard.Key == LDL::Enums::KeyboardKey::D)
				{
					dx += step;;
				}
			}

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
				fpsCounter.Clear();
			}
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}