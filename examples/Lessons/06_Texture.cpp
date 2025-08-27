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

	LDL::Window window(result, renderContext, LDL::Vec2u(0, 0), LDL::Vec2u(800, 600), "Window!");
	LDL::Render render(result, renderContext, &window);

	LDL::Event report;

	LDL::BmpLoader loader(result);

	loader.Load("Data/trehmachtovyiy-korabl-kartina-maslom-60x50_512x.bmp");
	LDL::Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.Bpp());

	LDL::FpsCounter fpsCounter;
	LDL::Convert convert;

	while (window.Running())
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

		render.Draw(&image, LDL::Vec2u(0, 0), window.Size(), LDL::Vec2u(0, 0), image.Size());

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));

		}
	}

	return 0;
}
