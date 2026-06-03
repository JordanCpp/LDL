/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <LDL/LDL.h>
#include <LDL/OpenGL/GL1_2.h>
#include <LDL/OpenGL/GLLoad.h>

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display()
{
	Identity();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
}

int main()
{
	LDL_Result*       result;
	LDL_Context*      context;
	LDL_Window*       window;
	LDL_Event         event;
	LDL_OpenGLLoader* loader;

	result  = LDL_ResultNew();
	context = LDL_ContextNew(result, LDL_ContextOpenGLLegacy);
	window  = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL - Rectangle red (OpenGL 1.2)", LDL_WindowModeResized);

	if (LDL_ResultIsOk(result))
	{
		loader = LDL_OpenGLLoaderNew(result, 1, 2);

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

			Display();

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
