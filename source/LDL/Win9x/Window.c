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
#include <LDL/Win9x/WinGL3.h>

struct LDL_Window
{
	LDL_Result*       Result;
	LDL_Context*      Context;
	LDL_WindowOpenGL1 WindowOpenGL1;
	LDL_WindowOpenGL3 WindowOpenGL3;
};

LDL_Window* LDL_WindowNew(LDL_Result* result, LDL_Context* context, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_Window* window = (LDL_Window*)malloc(sizeof(LDL_Window));

	if (window && result && context)
	{
		window->Context = context;
		window->Result  = result;

		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1Init(&window->WindowOpenGL1, result, pos, size, title, mode);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3Init(&window->WindowOpenGL3, result, pos, size, title, mode);
			break;
		};

		return window;
	}

	if (window)
	{
		free(window);
	}

	return NULL;
}

void LDL_WindowFree(LDL_Window* window)
{
	if (window)
	{
		if (window->Context)
		{
			switch (LDL_ContextGet(window->Context))
			{
			case LDL_ContextOpenGLLegacy:
			case LDL_ContextOpenGLHybrid:
				LDL_WindowOpenGL1Deinit(&window->WindowOpenGL1);
				break;
			case LDL_ContextOpenGLModern:
				LDL_WindowOpenGL3Deinit(&window->WindowOpenGL3);
				break;
			};
		}

		free(window);
	}
}

bool LDL_WindowIsRunning(LDL_Window* window)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1IsRunning(&window->WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3IsRunning(&window->WindowOpenGL3);
			break;
		};
	}

	return false;
}

void LDL_WindowStopEvent(LDL_Window* window)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1StopEvent(&window->WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3StopEvent(&window->WindowOpenGL3);
			break;
		};
	}
}

bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event)
{
	if (window && window->Context && event)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1GetEvent(&window->WindowOpenGL1, event);
			break;
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3GetEvent(&window->WindowOpenGL3, event);
			break;
		};
	}

	return false;
}

LDL_Vec2i LDL_WindowGetSize(LDL_Window* window)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1GetSize(&window->WindowOpenGL1);
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3GetSize(&window->WindowOpenGL3);
		};
	}

	return LDL_GetVec2i(0, 0);
}

const char* LDL_WindowGetTitle(LDL_Window* window)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1GetTitle(&window->WindowOpenGL1);
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3GetTitle(&window->WindowOpenGL3);
		};
	}

	return NULL;
}

void LDL_WindowSetTitle(LDL_Window* window, const char* title)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1SetTitle(&window->WindowOpenGL1, title);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3SetTitle(&window->WindowOpenGL3, title);
			break;
		};
	}
}

void LDL_WindowPresent(LDL_Window* window)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1Present(&window->WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3Present(&window->WindowOpenGL3);
			break;
		};
	}
}
