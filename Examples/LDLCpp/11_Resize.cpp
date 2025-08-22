#include <LDL/LDL.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

int main()
{
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(&renderContext, &window);

	Event report;

	FixedLinear allocator(Allocator::Mb * 4);
	ImageLoader loader(&allocator);

	loader.Load("Data/Gorgosaurus_BW_transparent.png");
	Surface image(loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	FpsCounter fpsCounter;
	Convert convert;
	FpsLimiter fpsLimiter;

	Vec2u size;

	while (window.Running())
	{
		fpsLimiter.Mark();

		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}

			if (report.Type == IsMouseMove)
			{
				size = Vec2u(report.Mouse.PosX, report.Mouse.PosY);
			}
		}

		render.Begin();

		render.Color(Color(0, 162, 232));
		render.Clear();

		render.Draw(&image, Vec2u(0, 0), size);

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
