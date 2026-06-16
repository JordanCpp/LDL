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

#include <LDL/Enums.h>
#include <LDL/BaseWin.h>
#include <LDL/StrSpan.h>

void LDL_BaseWindowInit(LDL_BaseWindow* baseWindow, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_StringSpan strTitle;

	if (baseWindow)
	{
		baseWindow->Mode = mode;
		baseWindow->Pos  = pos;
		baseWindow->Size = size;

		strTitle = LDL_GetStringSpan(baseWindow->Title, LDL_BaseWindowTitleMax);
		LDL_StringSpanCopy(&strTitle, title);
	}
}

bool LDL_BaseWindowHasMode(LDL_BaseWindow* baseWindow, size_t mode)
{
	return baseWindow ? (baseWindow->Mode & mode) != 0 : false;
}

LDL_Vec2i LDL_BaseWindowGetPos(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? baseWindow->Pos : LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_BaseWindowGetSize(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? baseWindow->Size : LDL_GetVec2i(0, 0);
}

void LDL_BaseWindowSetSize(LDL_BaseWindow* baseWindow, LDL_Vec2i size)
{
	if (baseWindow)
	{
		baseWindow->Size = size;
	}
}

const char* LDL_BaseWindowGetTitle(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? baseWindow->Title : NULL;
}

void LDL_BaseWindowSetTitle(LDL_BaseWindow* baseWindow, const char* title)
{
	LDL_StringSpan strTitle;

	if (baseWindow)
	{
		strTitle = LDL_GetStringSpan(baseWindow->Title, LDL_BaseWindowTitleMax);
		LDL_StringSpanCopy(&strTitle, title);
	}
}

bool LDL_BaseWindowIsFullscreen(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? (baseWindow->Mode & LDL_WindowModeFullScreen) != 0 : false;
}

bool LDL_BaseWindowIsResized(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? (baseWindow->Mode & LDL_WindowModeResized) != 0 : false;
}

bool LDL_BaseWindowIsFixed(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? (baseWindow->Mode & LDL_WindowModeFixed) != 0 : false;
}

bool LDL_BaseWindowIsMinimized(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? (baseWindow->Mode & LDL_WindowModeMinimized) != 0 : false;
}

bool LDL_BaseWindowIsMaximized(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? (baseWindow->Mode & LDL_WindowModeMaximized) != 0 : false;
}

bool LDL_BaseWindowIsCentered(LDL_BaseWindow* baseWindow)
{
	return baseWindow ? (baseWindow->Mode & LDL_WindowModeCentered) != 0 : false;
}
