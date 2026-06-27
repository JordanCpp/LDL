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

#include <LDL/Mouse.h>
#include <LDL/Win9x/WinX.h>

LDL_Vec2i LDL_MouseGetPos()
{
    POINT point;

    if (GetCursorPos(&point))
    {
        return LDL_GetVec2i(point.x, point.y);
    }

	return LDL_GetVec2i(0, 0);
}

void LDL_MouseSetPos(LDL_Vec2i pos)
{
    SetCursorPos(pos.x, pos.y);
}

void LDL_MouseHide()
{
    ShowCursor(FALSE);
}

void LDL_MouseShow()
{
    ShowCursor(TRUE);
}
