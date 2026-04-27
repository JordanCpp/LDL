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
#include <LDL/Linux/MainWin.h>

const size_t eventMask =
PointerMotionMask
| ButtonMotionMask
| ButtonPressMask
| ButtonReleaseMask
| KeyPressMask
| KeyReleaseMask;

void LDL_MainWindowInit(LDL_MainWindow* mainWindow, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
    if (mainWindow && result)
    {
        LDL_KeyMapperInit(&mainWindow->KeyMapper);
        LDL_EventHandlerInit(&mainWindow->EventHandler);
        LDL_BaseWindowInit(&mainWindow->BaseWindow, pos, size, title, mode);

        mainWindow->Display = XOpenDisplay(NULL);

        mainWindow->Screen = DefaultScreen(mainWindow->Display);
        mainWindow->Root = RootWindow(mainWindow->Display, mainWindow->Screen);
    }
}

void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        if (mainWindow->Display)
        {
            XCloseDisplay(mainWindow->Display);
        }

        while (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
        {
            LDL_Event event;
            LDL_EventHandlerPop(&mainWindow->EventHandler, &event);
        }
    }
}

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        return LDL_BaseWindowGetPos(&mainWindow->BaseWindow);
    }

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_MainWindowGetSize(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        return LDL_BaseWindowGetSize(&mainWindow->BaseWindow);
    }

    return LDL_GetVec2i(0, 0);
}

const char* LDL_MainWindowGetTitle(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        return LDL_BaseWindowGetTitle(&mainWindow->BaseWindow);
    }

    return NULL;
}


void LDL_MainWindowPollEvents(LDL_MainWindow* mainWindow)
{
}

bool LDL_MainWindowGetEvent(LDL_MainWindow* mainWindow, LDL_Event* event)
{
    if (mainWindow && event)
    {
        LDL_MainWindowPollEvents(mainWindow);

        if (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
        {
            return LDL_EventHandlerPop(&mainWindow->EventHandler, event);
        }
    }

    return false;
}

void LDL_MainWindowStopEvent(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        LDL_EventHandlerStop(&mainWindow->EventHandler);
    }
}

bool LDL_MainWindowIsRunning(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        return LDL_EventHandlerRunning(&mainWindow->EventHandler);
    }

    return false;
}
