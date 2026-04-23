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

#include <stdlib.h>
#include <LDL/Window.h>
#include <LDL/Win9x/WinGL1.h>

typedef struct LDL_Window
{
	LDL_Result*       Result;
	LDL_Context*      Context;
	LDL_WindowOpenGL1 WindowOpenGL1;
} LDL_Window;

LDL_Window* LDL_WindowNew(LDL_Result* result, LDL_Context* context, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_Window* window = (LDL_Window*)malloc(sizeof(LDL_Window));

	if (window)
	{
		window->Context = context;
		window->Result  = result;

		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_WindowOpenGL1Init(&window->WindowOpenGL1, result, pos, size, title, mode);
			break;
		};

		return window;
	}

	return NULL;
}

void LDL_WindowFree(LDL_Window* window)
{
	if (window)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGL1:
			LDL_WindowOpenGL1Deinit(&window->WindowOpenGL1);
		};

		free(window);
	}
}

bool LDL_WindowIsRunning(LDL_Window* window)
{
	return LDL_WindowOpenGL1IsRunning(&window->WindowOpenGL1);
}

void LDL_WindowStopEvent(LDL_Window* window)
{
	switch (LDL_ContextGet(window->Context))
	{
	case LDL_ContextOpenGL1:
		LDL_WindowOpenGL1StopEvent(&window->WindowOpenGL1);
	};
}

bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event)
{
	switch (LDL_ContextGet(window->Context))
	{
	case LDL_ContextOpenGL1:
		return LDL_WindowOpenGL1GetEvent(&window->WindowOpenGL1, event);
	default:
		return false;
	};
}

void LDL_WindowPresent(LDL_Window* window)
{
	switch (LDL_ContextGet(window->Context))
	{
	case LDL_ContextOpenGL1:
		LDL_WindowOpenGL1Present(&window->WindowOpenGL1);
	};
}
