#include <LDL/LDL.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Math;

int main()
{
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(&renderContext, &window);

	Event report;

	FpsCounter fpsCounter;
	Convert convert;

	while (window.Running())
	{
		fpsCounter.Start();

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

		render.Color(Color(237, 28, 36));
		render.Line(Vec2u(0, 0), Vec2u(render.Size().x, render.Size().y));
		render.Line(Vec2u(render.Size().x, 0), Vec2u(0, render.Size().y));

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			fpsCounter.Clear();
		}

		window.PollEvents();
	}

	return 0;
}
