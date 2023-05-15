#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
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

		FixedLinear allocator(Allocator::Mb * 4);
		ImageLoader loader(&allocator);

		loader.Load("trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");
		Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

		FpsCounter fpsCounter;
		NumberToString convert;

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			//render.Draw(&image, Point2u(0, 0), window.Size(), Point2u(0, 0), Point2u(512, 615));
			render.Draw(&image, Point2u(0, 0), window.Size(), Point2u(0, 0), image.Size());

			render.End();

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