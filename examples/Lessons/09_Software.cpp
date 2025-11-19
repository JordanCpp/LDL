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

int main()
{
	LDL_Random rnd;

	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result result;
	LDL_RenderContext renderContext(LDL_RenderMode::Software);

	LDL_Vec2u windowSize = LDL_Vec2u(800, 600);
	LDL_IWindow* window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(800, 600), __FILE__, LDL_WindowMode::Fixed);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	LDL_IRender* render = LDL_CreateRender(result, renderContext, window);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	LDL_Event report;

	LDL_FpsCounter fpsCounter;
	LDL_Convert    convert;

	LDL_Color colorScreen;
	LDL_Color colorRect;
	LDL_Vec2u posRect;
	LDL_Vec2u sizeRect;

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

		render->SetColor(colorScreen);
		render->Clear();

		render->SetColor(colorRect);
		render->Fill(posRect, sizeRect);

		render->End();

		if (fpsCounter.Calc())
		{
			colorScreen = LDL_Color(rnd.Range(0, 255), rnd.Range(0, 255), rnd.Range(0, 255));
			colorRect   = LDL_Color(rnd.Range(0, 255), rnd.Range(0, 255), rnd.Range(0, 255));

			posRect  = LDL_Vec2u(rnd.Range(0, 500), rnd.Range(0, 500));
			sizeRect = LDL_Vec2u(rnd.Range(0, 300), rnd.Range(0, 300));

			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
