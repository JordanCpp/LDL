/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <stdio.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL3_3.h>
#include <LDL/OpenGL/GLLoad.h>

int main()
{
	LDL_Result* result;
	LDL_Context* context;
	LDL_Window* window;
	LDL_Event         event;
	LDL_OpenGLLoader* loader;

	result = LDL_ResultNew();
	context = LDL_ContextNew(LDL_ContextOpenGL3);
	window = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL - Rectangle red (OpenGL 3.3)", LDL_WindowModeResized);

	if (LDL_ResultIsOk(result))
	{
		loader = LDL_OpenGLLoaderNew(result, 3, 3);

		while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
		{
			while (LDL_WindowGetEvent(window, &event))
			{
				if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
				{
					LDL_WindowStopEvent(window);
				}

				if (event.Type == LDL_EventIsResize)
				{
					glViewport(0, 0, (GLsizei)event.u.Resize.Width, (GLsizei)event.u.Resize.Height);
				}
			}

			LDL_WindowPresent(window);
		}

		LDL_OpenGLLoaderFree(loader);
		LDL_ContextFree(context);
		LDL_WindowFree(window);
		LDL_ResultFree(result);
	}

	if (LDL_ResultIsFail(result))
	{
		printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
	}

	return 0;
}
