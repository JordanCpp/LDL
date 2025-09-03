// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>

static int totalCount = 0;
static int totalBytes = 0;

void* CustomMalloc(size_t bytes)
{
	totalCount++;
	totalBytes += (int)bytes;

	return malloc(bytes);
}

void CustomFree(void* ptr)
{
	free(ptr);
}

void ErrorShow(LDL::Result& result)
{
	printf("LDL error: %s", result.Message());
}

int main()
{
	LDL::MemoryManager::Instance().Functions(CustomMalloc, NULL, NULL, CustomFree);

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
	LDL::Convert    convert;
	LDL::FpsLimiter fpsLimiter;

	while (window.Running())
	{
		fpsLimiter.Mark();

		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == LDL::IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();
		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
		}

		printf("Allocation count: %d allocation bytes %d\n", totalCount, totalBytes);
	}

	return 0;
}
