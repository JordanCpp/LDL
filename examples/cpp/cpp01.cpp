#include <LDL/Cpp/Render.hpp>
#include <LDL/Low/FpsCount.hpp>
#include <LDL/Low/Conv.hpp>
#include <stdio.h>

int main()
{
	LDL_ErrorHandler errorHandler;
	LDL_RenderContext renderContext;

	LDL_Window window(&errorHandler, &renderContext, LDL_Point2u(0, 0), LDL_Point2u(800, 600), "", LDL_WindowMode::Fixed);

	if (errorHandler.Ok())
	{
		LDL_Render render(&renderContext, &window);

		LDL_Event report;

		LDL_FpsCounter fpsCounter;
		LDL_NumberToString convert;

		while (window.Running())
		{
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == LDL_Events::IsQuit)
				{
					window.StopEvent();
				}
			}

			render.Begin();
			render.End();

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}
	}
	else
	{
		printf("%s\n", errorHandler.Message());
	}

	return 0;
}