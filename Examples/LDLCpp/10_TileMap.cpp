#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Isometric.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

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
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "10_TileMap");
	Render render(&renderContext, &window);

	Event report;

	FixedLinear allocator(Allocator::Mb * 8);
	ImageLoader loader(&allocator);

	loader.Load(Color(0, 0, 255), "Data/bg1bg23d_0_0_0.bmp");
	Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	FpsCounter fpsCounter;
	Convert convert;
	FpsLimiter fpsLimiter;

	Isometric isometric;

	Vec2u start = Vec2u(350, 150);
	Vec2u mapSize = Vec2u(9, 9);
	Vec2u tileSize = Vec2u(80, 40);

	size_t dx = 0;
	size_t dy = 0;
	size_t step = tileSize.x / 2;

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

		for (size_t rows = 0; rows < mapSize.x; rows++)
		{
			for (size_t cols = 0; cols < mapSize.y; cols++)
			{
				size_t x = cols * tileSize.x / 2;
				size_t y = rows * tileSize.y;

				Vec2u pt = isometric.CartesianToIsometric(Vec2u(x, y));

				render.Draw(&image, Vec2u(start.x + pt.x + dx, start.y + pt.y + dy));
			}
		}

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			fpsCounter.Clear();
		}

		window.PollEvents();
	}

	return 0;
}
