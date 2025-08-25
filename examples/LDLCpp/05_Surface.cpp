// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/LDL.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Loaders;

void ErrorShow(Result& result)
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

	Event report;

	FpsCounter fpsCounter;
	Convert convert;

	BmpLoader bmpLoader(result);

	if (!bmpLoader.Load("Data/NeHe.bmp"))
	{
		ErrorShow(result);
		return -1;
	}

	Surface surface(bmpLoader.Size(), bmpLoader.Pixels(), bmpLoader.Bpp());

	while (window.Running() || result.Ok())
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

		render.Draw(&surface, Vec2u(0, 0));

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
