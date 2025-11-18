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
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext;

	IWindow* window = CreateWindowImpl(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), __FILE__, 0);
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

	BmpLoader bmpLoader(result);

	bmpLoader.Load("data/trehmachtovyiy-korabl-kartina-maslom-60x50_512x.bmp");
	ITexture* image = CreateTextureImpl(&renderContext, bmpLoader.Format(), bmpLoader.Size(), bmpLoader.Pixels());

	FpsCounter fpsCounter;
	Convert convert;

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

		render->SetColor(Color(0, 162, 232));
		render->Clear();

		render->Draw(image, Vec2u(0, 0), window->Size(), Vec2u(0, 0), image->Size());

		render->End();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
