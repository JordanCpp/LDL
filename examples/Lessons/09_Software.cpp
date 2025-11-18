// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

using namespace LDL;

void ErrorShow(Result& result)
{
	printf("LDL error: %s", result.Message());
}

int main()
{
	Random rnd;

	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext(RenderMode::Software);

	Vec2u windowSize = Vec2u(800, 600);
	IWindow* window = CreateWindowImpl(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), __FILE__, WindowMode::Fixed);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	LDL::IRender* render = CreateRenderImpl(result, renderContext, window);
	if (!result.Ok())
	{
		ErrorShow(result);
		return -1;
	}

	Event report;

	FpsCounter fpsCounter;
	Convert    convert;

	Color colorScreen;
	Color colorRect;
	Vec2u posRect;
	Vec2u sizeRect;

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
			colorScreen = Color(rnd.Range(0, 255), rnd.Range(0, 255), rnd.Range(0, 255));
			colorRect   = Color(rnd.Range(0, 255), rnd.Range(0, 255), rnd.Range(0, 255));

			posRect  = Vec2u(rnd.Range(0, 500), rnd.Range(0, 500));
			sizeRect = Vec2u(rnd.Range(0, 300), rnd.Range(0, 300));

			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
