// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Math;

int main()
{
	    Result result;
		RenderContext renderContext;

		Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
		Render render(result, renderContext, &window);

		Surface screen(Vec2u(800, 600), 4);
		PixelPainter painter;

		painter.Bind(&screen);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::Convert convert;

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
				window.Title(convert.ToString(fpsCounter.Fps()));
				fpsCounter.Clear();
			}
		}

	return 0;
}
