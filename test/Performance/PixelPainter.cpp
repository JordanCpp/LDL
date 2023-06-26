#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

int main()
{
	try
	{
		RenderContext renderContext;

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(&renderContext, &window);

		Surface screen(Vec2u(800, 600), 4);
		PixelPainter painter;

		painter.Bind(&screen);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::NumberToString convert;

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			painter.Color(Color(0, 162, 232));
			painter.Clear();

			painter.Color(Color(237, 28, 36));
			painter.Line(Vec2u(0, 0), Vec2u(render.Size().x - 1, render.Size().y - 1));

			render.Draw(&screen, Vec2u(0, 0));

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