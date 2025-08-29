// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

void ErrorShow(LDL::Result& result)
{
	printf("LDL error: %s", result.Message());
}

int main()
{
	LDL::MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL::Result result;
	LDL::RenderContext renderContext;

	LDL::Window window(result, renderContext, LDL::Vec2u(0, 0), LDL::Vec2u(800, 600), __FILE__);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	LDL::Render render(result, renderContext, &window);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	LDL::Event report;

	LDL::FpsCounter fpsCounter;
	LDL::Convert convert;

	LDL::BmpLoader bmpLoader(result);

	if (!bmpLoader.Load("Data/NeHe.bmp"))
	{
		ErrorShow(result);
		return -1;
	}

	LDL::Surface surface(bmpLoader.GetPixelFormat(), bmpLoader.Size(), bmpLoader.Pixels());

	while (window.Running() || result.Ok())
	{
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == LDL::IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.Color(LDL::Color(0, 162, 232));
		render.Clear();

		render.Draw(&surface, LDL::Vec2u(0, 0));

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	return 0;
}
