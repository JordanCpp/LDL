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

size_t style = LDL_WindowMode::Centered | LDL_WindowMode::Fixed;

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result result;
	LDL_RenderContext renderContext;

	window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(800, 600), __FILE__, style);
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

	LDL_Event      report;
	LDL_FpsCounter fpsCounter;
	LDL_Convert    convert;

	render->SetColor(LDL_Color(0, 162, 232));

	while (window->Running())
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

		render->Clear();

		render->End();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	CleanUp();

	return 0;
}
