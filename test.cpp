#define LDL_RENDER_OPENGL1
#include <LDL/LDL_WinX.hpp>
#include <LDL/LDL_GL.hpp>

#include <stdio.h>

int main()
{
	LDL_Result result;

	LDL_Window window(&result, LDL_Vec2i(0, 0), LDL_Vec2i(800, 600), "test.cpp", LDL_WindowMode::Resized);

	if (result.Ok())
	{
		LDL_OpenGLLoader loader(1, 2);

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

			glClearColor(0.0f, 3.0f, 0.0f, 0.5f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			window.Present();
			window.PollEvents();
		}
	}
	else
	{
		printf("%s/n", result.Message());
	}

	return 0;
}