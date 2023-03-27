#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL::Graphics;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(800, 600), "Window!");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Surface screen(Point2u(800, 600), 4);
		PixelPainter painter;

		painter.Bind(&screen);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			painter.Color(Color(0, 162, 232));
			painter.Clear();

			painter.Color(Color(237, 28, 36));
			painter.Line(Point2u(0, 0), Point2u(render.Size().PosX() - 1, render.Size().PosY() - 1));

			render.Draw(&screen, Point2u(0, 0));

			render.End();

			if (report.Type == LDL::Events::IsQuit)
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
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}