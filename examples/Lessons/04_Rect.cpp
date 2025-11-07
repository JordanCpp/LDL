// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

using namespace LDL;

void ErrorShow(LDL::Result& result)
{
	printf("LDL error: %s", result.Message());
}

int main()
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), __FILE__);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	Render render(result, renderContext, &window);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	Event      report;
	Convert    convert;
	FpsCounter fpsCounter;

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

		render.Color(LDL::Color(0, 162, 232));
		render.Clear();

		render.Color(LDL::Color(237, 28, 36));
		render.Fill(Vec2u(0, 0), Vec2u(400, 300));

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));		
		}
	}

	return 0;
}
