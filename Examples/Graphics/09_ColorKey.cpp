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

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), "Window!");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		FixedLinear allocator(Allocator::Mb * 8);
		ImageLoader loader(&allocator);

		loader.Load(Color(163, 73, 164), "Gorgosaurus_BW_transparent.bmp");
		Surface image(loader.Size(), loader.Pixels(), loader.BytesPerPixel());

		FpsCounter fpsCounter;
		NumberToString convert;
		FpsLimiter fpsLimiter;

		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			render.Draw(&image, window.Pos(), window.Size());

			render.End();

			fpsLimiter.Throttle();

			if (report.Type == IsQuit)
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
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}