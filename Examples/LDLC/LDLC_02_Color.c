#include <LDLC/LDL_Render.h>
#include <LDLC/LDL_FpsCounter.h>
#include <LDLC/LDL_NumberToString.h>

int main()
{
	LDL_Window* window = LDL_WindowNew(0, 0, 800, 600, "02_Color", LDL_WindowModeResized);

	LDL_RenderContext* renderContext = LDL_RenderContextNew();
	LDL_Render* render = LDL_RenderNew(renderContext, window);
	LDL_NumberToString* convert = LDL_NumberToStringNew();
	LDL_FpsCounter* counter = LDL_FpsCounterNew(60);

	LDL_Event report;

	LDL_RenderSetColor(render, 0, 162, 232, 0);

	while (LDL_WindowGetEvent(window, &report))
	{
		LDL_FpsCounterStart(counter);

		LDL_RenderBegin(render);

		LDL_RenderClear(render);

		LDL_RenderEnd(render);

		if (report.Type == LDL_EventIsQuit)
		{
			LDL_WindowStopEvent(window);
		}

		if (LDL_FpsCounterCalc(counter))
		{
			LDL_WindowSetTitle(window, LDL_NumberToStringConvertInt(convert, LDL_FpsCounterGetFps(counter)));
			LDL_FpsCounterClear(counter);
		}
	}

	LDL_FpsCounterFree(counter);
	LDL_NumberToStringFree(convert);
	LDL_WindowFree(window);
	LDL_RenderFree(render);

	return 0;
}