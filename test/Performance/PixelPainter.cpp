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

		Render render(&window);

		Surface screen(Point2u(800, 600), 4);
		PixelPainter painter;

		painter.Bind(&screen);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window.GetEvent(report))
		{
			painter.Color(Color(35, 35, 35));
			painter.Clear();

			painter.Color(Color(34, 177, 76));

			fpsCounter.Start();

			render.Begin();

			for (size_t i = 0; i < 400; i++)
			{
				for (size_t j = 0; j < 300; j++)
				{
					painter.Pixel(Point2u(i, j));
				}
			}		

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