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

using namespace LDL::Graphics;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), "10_TileMap");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		LDL::Events::Event report;

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 8);
		LDL::Loaders::ImageLoader loader(&allocator);

		loader.Load(Color(0, 0, 255), "bg1bg23d_0_0_0.bmp");
		Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;
		LDL::Time::FpsLimiter fpsLimiter;

		Isometric isometric;

		Point2u start = Point2u(350, 150);
		Point2u mapSize = Point2u(9, 9);
		Point2u tileSize = Point2u(80, 40);

		size_t dx = 0;
		size_t dy = 0;
		size_t step = tileSize.PosX() / 2;

		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			for (size_t rows = 0; rows < mapSize.PosX(); rows++)
			{
				for (size_t cols = 0; cols < mapSize.PosY(); cols++)
				{
					size_t x = cols * tileSize.PosX() / 2;
					size_t y = rows * tileSize.PosY();

					Point2u pt = isometric.CartesianToIsometric(Point2u(x, y));

					render.Draw(&image, Point2u(start.PosX() + pt.PosX() + dx, start.PosY() + pt.PosY() + dy));
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