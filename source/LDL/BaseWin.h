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

#ifndef LDL_BaseWin_H
#define LDL_BaseWin_H

#include <LDL/Types.h>
#include <LDL/Vec2i.h>

enum
{
	LDL_BaseWindowTitleMax = 64
};

typedef struct LDL_BaseWindow
{
	size_t    Mode;
	LDL_Vec2i Pos;
	LDL_Vec2i Size;
	char      Title[LDL_BaseWindowTitleMax];
} LDL_BaseWindow;

void LDL_BaseWindowInit(LDL_BaseWindow* baseWindow, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);

bool LDL_BaseWindowHasMode(LDL_BaseWindow* baseWindow, size_t mode);

LDL_Vec2i LDL_BaseWindowGetPos(LDL_BaseWindow* baseWindow);

LDL_Vec2i LDL_BaseWindowGetSize(LDL_BaseWindow* baseWindow);
void LDL_BaseWindowSetSize(LDL_BaseWindow* baseWindow, LDL_Vec2i size);

const char* LDL_BaseWindowGetTitle(LDL_BaseWindow* baseWindow);
void LDL_BaseWindowSetTitle(LDL_BaseWindow* baseWindow, const char* title);

bool LDL_BaseWindowIsFullscreen(LDL_BaseWindow* baseWindow);
bool LDL_BaseWindowIsResized(LDL_BaseWindow* baseWindow);
bool LDL_BaseWindowIsFixed(LDL_BaseWindow* baseWindow);
bool LDL_BaseWindowIsMinimized(LDL_BaseWindow* baseWindow);
bool LDL_BaseWindowIsMaximized(LDL_BaseWindow* baseWindow);
bool LDL_BaseWindowIsCentered(LDL_BaseWindow* baseWindow);

#endif
