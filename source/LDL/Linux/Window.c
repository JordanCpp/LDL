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
#include <LDL/Linux/WinGL.h>

typedef struct LDL_Window
{
	LDL_Result*      Result;
	LDL_Context*     Context;
	LDL_WindowOpenGL WindowOpenGL;
} LDL_Window;

LDL_Window* LDL_WindowCreate(LDL_Result* result, LDL_Context* context, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
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
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGLInit(&window->WindowOpenGL, result, pos, size, title, mode);
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

void LDL_WindowDestroy(LDL_Window* window)
{
	if (window)
	{
		if (window->Context)
		{
			switch (LDL_ContextGet(window->Context))
			{
			case LDL_ContextOpenGLLegacy:
			case LDL_ContextOpenGLHybrid:
			case LDL_ContextOpenGLModern:
				LDL_WindowOpenGLDeinit(&window->WindowOpenGL);
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
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGLIsRunning(&window->WindowOpenGL);
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
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGLStopEvent(&window->WindowOpenGL);
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
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGLGetEvent(&window->WindowOpenGL, event);
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
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGLGetSize(&window->WindowOpenGL);
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
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGLGetTitle(&window->WindowOpenGL);
		};
	}
}

void LDL_WindowSetTitle(LDL_Window* window, const char* title)
{
	if (window && window->Context)
	{
		switch (LDL_ContextGet(window->Context))
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGLSetTitle(&window->WindowOpenGL, title);
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
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGLPresent(&window->WindowOpenGL);
			break;
		};
	}
}

LDL_Surface* LDL_WindowGetScreen(LDL_Window* window)
{
	return NULL;
}
