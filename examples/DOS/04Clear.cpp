#include <LDL/LDL.hpp>
#include <stdio.h>


void InitPalette(LDL_Palette& palette)
{
	palette.Set(0, LDL_Color(0, 162, 232));
	palette.Set(1, LDL_Color(237, 28, 36));
}

int main()
{
	LDL_Result result;

	LDL_Palette palette;
	InitPalette(palette);

	LDL_Window window(&result, LDL_Vec2i(0, 0), LDL_Vec2i(320, 200), "04Clear");
	LDL_Render render(&window, &palette);

	LDL_FpsCounter     fpsCounter;
	LDL_NumberToString convert;

	if (result.Ok())
	{
		LDL_Event report;

		while (window.Running())
		{
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == LDL_Event::IsQuit)
				{
					window.StopEvent();
				}
			}
			
			render.Begin();

			render.SetColor(0);
			render.Clear();

			render.SetColor(1);
			render.Fill(LDL_Vec2i(5, 10), LDL_Vec2i(55, 75));

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
		printf("%s/n", result.Message());
	}

	return 0;
}