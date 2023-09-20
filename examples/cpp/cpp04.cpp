#include <LDL/Cpp/Render.hpp>
#include <LDL/Low/FpsCount.hpp>
#include <LDL/Low/Conv.hpp>
#include <LDL/Low/BmpLoad.hpp>
#include <stdio.h>

int main()
{
	LDL_ErrorHandler errorHandler;
	LDL_RenderContext renderContext;

	LDL_Window window(&errorHandler, &renderContext, LDL_Point2u(0, 0), LDL_Point2u(800, 600), "", LDL_WindowMode::Fixed);

	LDL_BmpLoader bmpLoader(&errorHandler);

	bmpLoader.Load("C://img24.bmp");

	if (errorHandler.Ok())
	{
		LDL_Render render(&renderContext, &window);

		LDL_Event report;

		LDL_FpsCounter fpsCounter;
		LDL_NumberToString convert;

		LDL_Surface surface(&renderContext, &window, bmpLoader.Size(), bmpLoader.Pixels(), bmpLoader.Bpp());

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

			render.SetColor(LDL_Color(237, 28, 36));
			render.Line(LDL_Point2u(0, 50), LDL_Point2u(window.Size().x, 50));

			render.SetColor(LDL_Color(255, 127, 39));
			render.Fill(LDL_Point2u(75, 75), LDL_Point2u(150, 100));

			render.Draw(&surface, LDL_Point2u(0, 0));

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