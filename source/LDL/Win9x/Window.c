
#include <stdlib.h>
#include <LDL/Window.h>
#include <LDL/Win9x/WinGL1.h>

typedef struct LDL_Window
{
	LDL_Result*       Result;
	LDL_WindowOpenGL1 WindowOpenGL1;
} LDL_Window;

LDL_Window* LDL_WindowNew(LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_Window* window = (LDL_Window*)malloc(sizeof(LDL_Window));

	if (window)
	{
		LDL_WindowOpenGL1Init(&window->WindowOpenGL1, result, pos, size, title, mode);

		return window;
	}

	return NULL;
}

void LDL_WindowFree(LDL_Window* window)
{
	if (window)
	{
		LDL_WindowOpenGL1Deinit(&window->WindowOpenGL1);
		free(window);
	}
}

bool LDL_WindowIsRunning(LDL_Window* window)
{
	return LDL_WindowOpenGL1IsRunning(&window->WindowOpenGL1);
}

void LDL_WindowStopEvent(LDL_Window* window)
{
	LDL_WindowOpenGL1StopEvent(&window->WindowOpenGL1);
}

bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event)
{
	return LDL_WindowOpenGL1GetEvent(&window->WindowOpenGL1, event);;
}

void LDL_WindowPresent(LDL_Window* window)
{
	LDL_WindowOpenGL1Present(&window->WindowOpenGL1);
}
