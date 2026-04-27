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

#include <LDL/Linux/WinGL1.h>

void LDL_WindowOpenGL1Init(LDL_WindowOpenGL1* window, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
}

void LDL_WindowOpenGL1Deinit(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        LDL_MainWindowDeinit(&window->MainWindow);
    }
}

LDL_Vec2i LDL_WindowOpenGL1GetPos(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        return LDL_MainWindowGetPos(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_WindowOpenGL1GetSize(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        return LDL_MainWindowGetSize(&window->MainWindow);
    }

    return LDL_GetVec2i(0, 0);
}

bool LDL_WindowOpenGL1GetEvent(LDL_WindowOpenGL1* window, LDL_Event* event)
{
    if (window && event)
    {
        return LDL_MainWindowGetEvent(&window->MainWindow, event);
    }

    return false;
}

void LDL_WindowOpenGL1Present(LDL_WindowOpenGL1* window)
{
}

void LDL_WindowOpenGL1StopEvent(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        LDL_MainWindowStopEvent(&window->MainWindow);
    }
}

bool LDL_WindowOpenGL1IsRunning(LDL_WindowOpenGL1* window)
{
    if (window)
    {
        return LDL_MainWindowIsRunning(&window->MainWindow);
    }

    return false;
}
