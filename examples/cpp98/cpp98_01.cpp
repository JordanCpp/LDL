#include <LDL/Cpp98/Render.hpp>
#include <stdio.h>

using namespace LDL::Graphics;

int main()
{
	RenderContext renderContext;
	Window window(&renderContext, LDL_Point2u(0, 0), LDL_Point2u(800, 600), "");

	Render render(&renderContext, &window);

	LDL_Event report;

	while (window.Running())
	{
		while (window.GetEvent(report))
		{
			if (report.Type == LDL_Events::IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();
		render.End();

		window.PollEvents();
	}

	return 0;
}