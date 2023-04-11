#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), "Window!");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		NumberToString convert;

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();
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