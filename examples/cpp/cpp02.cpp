#include <LDL/Cpp/Render.hpp>
#include <LDL/Low/FpsCount.hpp>
#include <LDL/Low/Conv.hpp>
#include <LDL/Low/Errors.hpp>
#include <stdio.h>

int main()
{
	LDL_RenderContext renderContext;

	LDL_Window window(&renderContext, LDL_Point2u(0, 0), LDL_Point2u(800, 600), "", LDL_WindowMode::Fixed);

	if (!LDL_IsError())
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

			render.SetColor(LDL_Color(0, 162, 232));
			render.Clear();

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
		printf("%s\n", LDL_GetError());
	}

	return 0;
}