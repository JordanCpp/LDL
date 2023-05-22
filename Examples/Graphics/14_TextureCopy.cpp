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

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), "14_TextureCopy");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		FixedLinear allocator(Allocator::Mb * 1);
		ImageLoader loader(&allocator);

		Texture image(&renderContext, Point2u(1024, 1024), loader.BytesPerPixel());

		loader.Load("NeHe.bmp");

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				image.Copy(Point2u(i * loader.Size().PosX(), j * loader.Size().PosY()), loader.Size(), loader.Pixels(), loader.BytesPerPixel());
			}
		}

		loader.Load(Color(0, 0, 255), "bg1bg23d_0_0_0.bmp");

		Surface image2(loader.Size(), loader.Pixels(), loader.BytesPerPixel());

		for (size_t x = 0; x < image.Size().PosX() / image2.Size().PosX(); x++)
		{
			for (size_t y = 0; y < image.Size().PosY() / image2.Size().PosY(); y++)
			{
				image.Copy(Point2u(x * loader.Size().PosX(), y * loader.Size().PosY()), &image2, loader.Size());
			}
		}

		FpsCounter fpsCounter;
		NumberToString convert;
		FpsLimiter fpsLimiter;

		Point2u start = Point2u(550, 0);
		Point2u mapSize = Point2u(100, 100);
		Point2u tileSize = Point2u(128, 64);

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