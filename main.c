
#include <stdio.h>
#include <LDL/LDL.h>

int main()
{
	LDL_Result* result;
	LDL_Window* window;
	LDL_Event   event;

	result = LDL_ResultNew();
	window = LDL_WindowNew(result, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "", 0);

	if (LDL_ResultIsOk(result))
	{
		while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
		{
			while (LDL_WindowGetEvent(window, &event))
			{
				if (event.Type == LDL_EventIsQuit)
				{
					LDL_WindowStopEvent(window);
				}
			}
		}

		LDL_ResultFree(result);
		LDL_WindowFree(window);
	}

	if (LDL_ResultIsFail(result))
	{
		printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
	}

	return 0;
}
