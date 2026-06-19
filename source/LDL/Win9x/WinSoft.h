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

#ifndef LDL_Win9x_WinSoft_H
#define LDL_Win9x_WinSoft_H

#include <LDL/Surface.h>
#include <LDL/Win9x/MainWin.h>

typedef struct LDL_WindowSoftware
{
	LDL_Result*    Result;
	LDL_Surface*   Screen;
	HDC            DeviceContext;
	BITMAPINFO     BitmapInfo;
	LDL_MainWindow MainWindow;
} LDL_WindowSoftware;

void LDL_WindowSoftwareInit(LDL_WindowSoftware* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);
void LDL_WindowSoftwareDeinit(LDL_WindowSoftware* window);

LDL_Vec2i LDL_WindowSoftwareGetPos(LDL_WindowSoftware* window);
LDL_Vec2i LDL_WindowSoftwareGetSize(LDL_WindowSoftware* window);

const char* LDL_WindowSoftwareGetTitle(LDL_WindowSoftware* window);
void LDL_WindowSoftwareSetTitle(LDL_WindowSoftware* window, const char* title);

bool LDL_WindowSoftwareGetEvent(LDL_WindowSoftware* window, LDL_Event* event);
void LDL_WindowSoftwareStopEvent(LDL_WindowSoftware* window);
bool LDL_WindowSoftwareIsRunning(LDL_WindowSoftware* window);

void LDL_WindowSoftwarePresent(LDL_WindowSoftware* window);

#endif
