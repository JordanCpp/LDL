#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

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
	try
	{
		RenderContext renderContext;

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "14_TextureCopy");
		Render render(&renderContext, &window);

		Event report;

		FixedLinear allocator(Allocator::Mb * 1);
		ImageLoader loader(&allocator);

		Texture image(&renderContext, Vec2u(1024, 1024), loader.BytesPerPixel());

		loader.Load("NeHe.bmp");

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				image.Copy(Vec2u(i * loader.Size().x, j * loader.Size().y), loader.Size(), loader.Pixels(), loader.BytesPerPixel());
			}
		}

		loader.Load(Color(0, 0, 255), "bg1bg23d_0_0_0.bmp");

		Surface image2(loader.Size(), loader.Pixels(), loader.BytesPerPixel());

		for (size_t x = 0; x < image.Size().x / image2.Size().x; x++)
		{
			for (size_t y = 0; y < image.Size().y / image2.Size().y; y++)
			{
				image.Copy(Vec2u(x * loader.Size().x, y * loader.Size().y), &image2, loader.Size());
			}
		}

		FpsCounter fpsCounter;
		NumberToString convert;
		FpsLimiter fpsLimiter;

		Vec2u start = Vec2u(550, 0);
		Vec2u mapSize = Vec2u(100, 100);
		Vec2u tileSize = Vec2u(128, 64);

		while (window.Running())
		{
			fpsCounter.Start();
			fpsLimiter.Mark();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}
			}

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			render.Draw(&image, window.Pos(), window.Size());

			render.End();

			fpsLimiter.Throttle();

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}