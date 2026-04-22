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

#include <LDL/BaseWin.h>
#include <LDL/StrSpan.h>

void LDL_BaseWindowInit(LDL_BaseWindow* baseWindow, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	LDL_StringSpan strTitle;

	if (baseWindow)
	{
		baseWindow->Pos  = pos;
		baseWindow->Size = size;

		strTitle = LDL_GetStringSpan(baseWindow->Title, LDL_BaseWindowTitleMax);
		LDL_StringSpanCopy(&strTitle, title);
	}
}

bool LDL_BaseWindowHasMode(LDL_BaseWindow* baseWindow, size_t mode)
{
	return (baseWindow->Mode & mode) != 0;
}

LDL_Vec2i LDL_BaseWindowGetPos(LDL_BaseWindow* baseWindow)
{
	if (baseWindow)
	{
		return baseWindow->Pos;
	}

	return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_BaseWindowGetSize(LDL_BaseWindow* baseWindow)
{
	if (baseWindow)
	{
		return baseWindow->Size;
	}

	return LDL_GetVec2i(0, 0);
}

const char* LDL_BaseWindowGetTitle(LDL_BaseWindow* baseWindow)
{
	return baseWindow->Title;
}
