#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

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
		render.Fill(Vec2u(0, 0), Vec2u(400, 300));

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
