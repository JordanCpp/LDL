#define LDL_RENDER_OPENGL1
#include <LDL/LDL_RdrX.hpp>

#include <stdio.h>

int main()
{
	LDL_Result result;

	LDL_Window window(&result, LDL_Vec2i(0, 0), LDL_Vec2i(800, 600), "test.cpp");
	LDL_Render render(&window);

	render.SetColor(LDL_Color(0, 162, 232));

	if (result.Ok())
	{
		LDL_Event report;

		while (window.Running())
		{
			while (window.GetEvent(report))
			{
				if (report.Type == LDL_Event::IsQuit)
				{
					window.StopEvent();
				}
			}

			render.Begin();

			render.Clear();

			render.End();

			window.PollEvents();
		}
	}
	else
	{
		printf("%s/n", result.Message());
	}

	return 0;
}