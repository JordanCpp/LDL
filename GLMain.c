
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
	LDL_Result* result;
	LDL_Window* window;
	LDL_Event   event;
	LDL_OpenGLLoader* loader;

	result = LDL_ResultNew();
	window = LDL_WindowNew(result, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "", 0);

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
					glViewport(0, 0, (GLsizei)event.Resize.Width, (GLsizei)event.Resize.Height);
				}
			}

			Display();

			LDL_WindowPresent(window);
		}

		LDL_ResultFree(result);
		LDL_WindowFree(window);
		LDL_OpenGLLoaderFree(loader);
	}

	if (LDL_ResultIsFail(result))
	{
		printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
	}

	return 0;
}
