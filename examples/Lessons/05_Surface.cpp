// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

void ErrorShow(LDL_Result& result)
{
	printf("LDL error: %s", result.Message());
}

LDL_IWindow* window = NULL;
LDL_IRender* render = NULL;

void CleanUp()
{
	if (render != NULL)
	{
		delete render;
	}

	if (window != NULL)
	{
		delete window;
	}
}

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result result;
	LDL_RenderContext renderContext;

	window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(800, 600), __FILE__, 0);
	if (!result.Ok())
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	render = LDL_CreateRender(result, renderContext, window);
	if (!result.Ok())
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	LDL_Event report;

	LDL_FpsCounter fpsCounter;
	LDL_Convert convert;

	LDL_BmpLoader bmpLoader(result);

	if (!bmpLoader.Load("data/NeHe.bmp"))
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	LDL_Surface surface(bmpLoader.Format(), bmpLoader.Size(), bmpLoader.Pixels());

	while (window->Running() || result.Ok())
	{
		fpsCounter.Start();

		while (window->GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window->StopEvent();
			}
		}

		render->Begin();

		render->SetColor(LDL_Color(0, 162, 232));
		render->Clear();

		render->Draw(&surface, LDL_Vec2u(0, 0));

		render->End();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	if (!result.Ok())
	{
		ErrorShow(result);
		CleanUp();
		return -1;
	}

	CleanUp();

	return 0;
}
