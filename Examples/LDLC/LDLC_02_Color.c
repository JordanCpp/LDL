#include <LDLC/LDL_Render.h>

int main()
{
	LDL_Window* window = LDL_WindowNew(0, 0, 800, 600, "LDLC_01_WindowAndRender.c", 1);

	LDL_RenderContext* renderContext = LDL_RenderContextNew();
	LDL_Render* render = LDL_RenderNew(renderContext, window);

	LDL_Event report;

	LDL_RenderSetColor(render, 0, 162, 232, 0);

	while (LDL_WindowGetEvent(window, &report))
	{
		LDL_RenderBegin(render);

		LDL_RenderClear(render);

		LDL_RenderEnd(render);

		if (report.Type == LDL_EventIsQuit)
		{
			LDL_WindowStopEvent(window);
		}
	}

	LDL_WindowFree(window);
	LDL_RenderFree(render);

	return 0;
}