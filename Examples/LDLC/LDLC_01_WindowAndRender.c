// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL.h>

int main()
{
	LDL_RenderContext* renderContext = LDL_RenderContextNew();

	LDL_Window* window = LDL_WindowNew(renderContext, 0, 0, 800, 600, "01_WindowAndRender", LDL_WindowModeResized);
	LDL_Render* render = LDL_RenderNew(renderContext, window);

	LDL_Convert* convert = LDL_ConvertNew();
	LDL_FpsCounter* counter = LDL_FpsCounterNew();

	LDL_Event report;

	while (LDL_WindowRunning(window))
	{
		LDL_FpsCounterStart(counter);

		while (LDL_WindowGetEvent(window, &report))
		{
			if (report.Type == LDL_EventIsQuit)
			{
				LDL_WindowStopEvent(window);
			}
		}

		LDL_RenderBegin(render);
		LDL_RenderEnd(render);

		if (LDL_FpsCounterCalc(counter))
		{
			LDL_WindowSetTitle(window, LDL_ConvertToString(convert, LDL_FpsCounterGetFps(counter)));
		}
	}

	LDL_FpsCounterFree(counter);
	LDL_ConvertFree(convert);
	LDL_RenderFree(render);
	LDL_WindowFree(window);
	LDL_RenderContextFree(renderContext);

	return 0;
}
