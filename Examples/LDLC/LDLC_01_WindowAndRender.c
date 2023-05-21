#include <LDLC/LDL_Render.h>
#include <LDLC/LDL_FpsCounter.h>
#include <LDLC/LDL_NumberToString.h>

int main()
{
	LDL_Window* window = LDL_WindowNew(0, 0, 800, 600, "01_WindowAndRender", LDL_WindowModeResized);

	LDL_RenderContext* renderContext = LDL_RenderContextNew();
	LDL_Render* render = LDL_RenderNew(renderContext, window);
	LDL_NumberToString* convert = LDL_NumberToStringNew();
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
			LDL_WindowSetTitle(window, LDL_NumberToStringConvertInt(convert, LDL_FpsCounterGetFps(counter)));
			LDL_FpsCounterClear(counter);
		}

		LDL_WindowPollEvents(window);
	}

	LDL_FpsCounterFree(counter);
	LDL_NumberToStringFree(convert);
	LDL_RenderFree(render);
	LDL_WindowFree(window);

	return 0;
}