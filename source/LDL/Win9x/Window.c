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
#include <LDL/Win9x/WinSoft.h>

struct LDL_Window
{
	LDL_ContextType ContextType;
	LDL_Result*     Result;
	union
	{
		LDL_WindowOpenGL1  WindowOpenGL1;
		LDL_WindowOpenGL3  WindowOpenGL3;
		LDL_WindowSoftware WindowSoftware;
	} u;
};

LDL_Window* LDL_WindowCreate(LDL_Result* result, LDL_Context* context, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_Window* window = (LDL_Window*)malloc(sizeof(LDL_Window));

	if (window && result && context)
	{
		window->ContextType = LDL_ContextGet(context);
		window->Result      = result;

		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1Init(&window->u.WindowOpenGL1, result, pos, size, title, mode);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3Init(&window->u.WindowOpenGL3, result, pos, size, title, mode);
			break;
		case LDL_ContextSoftware:
			LDL_WindowSoftwareInit(&window->u.WindowSoftware, result, pos, size, title, mode);
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
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1Deinit(&window->u.WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3Deinit(&window->u.WindowOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_WindowSoftwareDeinit(&window->u.WindowSoftware);
			break;
		};

		free(window);
	}
}

bool LDL_WindowIsRunning(LDL_Window* window)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1IsRunning(&window->u.WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3IsRunning(&window->u.WindowOpenGL3);
			break;
		case LDL_ContextSoftware:
			return LDL_WindowSoftwareIsRunning(&window->u.WindowSoftware);
			break;
		};
	}

	return false;
}

void LDL_WindowStopEvent(LDL_Window* window)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1StopEvent(&window->u.WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3StopEvent(&window->u.WindowOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_WindowSoftwareStopEvent(&window->u.WindowSoftware);
			break;
		};
	}
}

bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event)
{
	if (window && event)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1GetEvent(&window->u.WindowOpenGL1, event);
			break;
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3GetEvent(&window->u.WindowOpenGL3, event);
			break;
		case LDL_ContextSoftware:
			return LDL_WindowSoftwareGetEvent(&window->u.WindowSoftware, event);
			break;
		};
	}

	return false;
}

LDL_Vec2i LDL_WindowGetSize(LDL_Window* window)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1GetSize(&window->u.WindowOpenGL1);
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3GetSize(&window->u.WindowOpenGL3);
		case LDL_ContextSoftware:
			return LDL_WindowSoftwareGetSize(&window->u.WindowSoftware);
		};
	}

	return LDL_GetVec2i(0, 0);
}

const char* LDL_WindowGetTitle(LDL_Window* window)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			return LDL_WindowOpenGL1GetTitle(&window->u.WindowOpenGL1);
		case LDL_ContextOpenGLModern:
			return LDL_WindowOpenGL3GetTitle(&window->u.WindowOpenGL3);
		case LDL_ContextSoftware:
			return LDL_WindowSoftwareGetTitle(&window->u.WindowSoftware);
		};
	}

	return NULL;
}

void LDL_WindowSetTitle(LDL_Window* window, const char* title)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1SetTitle(&window->u.WindowOpenGL1, title);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3SetTitle(&window->u.WindowOpenGL3, title);
			break;
		case LDL_ContextSoftware:
			LDL_WindowSoftwareSetTitle(&window->u.WindowSoftware, title);
			break;
		};
	}
}

void LDL_WindowPresent(LDL_Window* window)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextOpenGLLegacy:
		case LDL_ContextOpenGLHybrid:
			LDL_WindowOpenGL1Present(&window->u.WindowOpenGL1);
			break;
		case LDL_ContextOpenGLModern:
			LDL_WindowOpenGL3Present(&window->u.WindowOpenGL3);
			break;
		case LDL_ContextSoftware:
			LDL_WindowSoftwarePresent(&window->u.WindowSoftware);
			break;
		};
	}
}

LDL_Surface* LDL_WindowGetScreen(LDL_Window* window)
{
	if (window)
	{
		switch (window->ContextType)
		{
		case LDL_ContextSoftware:
			return window->u.WindowSoftware.Screen;
		};
	}

	return NULL;
}
