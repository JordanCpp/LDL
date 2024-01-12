#include "LDL/LDL_GL1.hpp"
#include <stdio.h>

int main()
{
	LDL_Result result;

	LDL_Window window(&result, LDL_Point(0, 0), LDL_Point(800, 600), "test.cpp", LDL_WindowMode::Resized);

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

			window.PollEvents();
			window.Update();
		}
	}
	else
	{
		printf("%s/n", result.Message());
	}

	return 0;
}