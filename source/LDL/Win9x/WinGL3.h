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

#ifndef LDL_Win9x_WinGL3_H
#define LDL_Win9x_WinGL3_H

#include <LDL/Win9x/MainWin.h>

typedef struct LDL_WindowOpenGL3
{
	LDL_Result*    Result;
	HDC            DeviceContext;
	HGLRC          OpenGLContext;
	LDL_MainWindow MainWindow;
} LDL_WindowOpenGL3;

void LDL_WindowOpenGL3Init(LDL_WindowOpenGL3* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
void LDL_WindowOpenGL3Deinit(LDL_WindowOpenGL3* window);

LDL_Vec2i LDL_WindowOpenGL3GetPos(LDL_WindowOpenGL3* window);
LDL_Vec2i LDL_WindowOpenGL3GetSize(LDL_WindowOpenGL3* window);

const char* LDL_WindowOpenGL3GetTitle(LDL_WindowOpenGL3* window);
void LDL_WindowOpenGL3SetTitle(LDL_WindowOpenGL3* window, const char* title);

bool LDL_WindowOpenGL3GetEvent(LDL_WindowOpenGL3* window, LDL_Event* event);
void LDL_WindowOpenGL3StopEvent(LDL_WindowOpenGL3* window);
bool LDL_WindowOpenGL3IsRunning(LDL_WindowOpenGL3* window);

void LDL_WindowOpenGL3Present(LDL_WindowOpenGL3* window);

#endif
