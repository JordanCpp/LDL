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
    StructureNotifyMask | PointerMotionMask | ButtonMotionMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask | KeyReleaseMask;

void LDL_MainWindowInit(LDL_MainWindow *mainWindow, LDL_Result *result, LDL_Vec2i pos, LDL_Vec2i size, const char *title, size_t mode)
{
    if (mainWindow && result)
    {
        LDL_KeyMapperInit(&mainWindow->KeyMapper);
        LDL_EventHandlerInit(&mainWindow->EventHandler);
        LDL_BaseWindowInit(&mainWindow->BaseWindow, pos, size, title, mode);

        mainWindow->EventMask = eventMask;

        mainWindow->Display = XOpenDisplay(NULL);
        if (!mainWindow->Display)
        {
            LDL_ResultAddMessage(result, "Error: XOpenDisplay\n");
            return;
        }

        mainWindow->Screen = DefaultScreen(mainWindow->Display);

        mainWindow->Root = RootWindow(mainWindow->Display, mainWindow->Screen);
        if (mainWindow->Root == None)
        {
            LDL_ResultAddMessage(result, "Error: RootWindow\n");
            return;
        }
    }
}

void LDL_MainWindowDeinit(LDL_MainWindow *mainWindow)
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

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow *mainWindow)
{
    if (mainWindow)
    {
        return LDL_BaseWindowGetPos(&mainWindow->BaseWindow);
    }

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_MainWindowGetSize(LDL_MainWindow *mainWindow)
{
    if (mainWindow)
    {
        return LDL_BaseWindowGetSize(&mainWindow->BaseWindow);
    }

    return LDL_GetVec2i(0, 0);
}

const char *LDL_MainWindowGetTitle(LDL_MainWindow *mainWindow)
{
    if (mainWindow)
    {
        return LDL_BaseWindowGetTitle(&mainWindow->BaseWindow);
    }

    return NULL;
}

void LDL_MainWindowSetTitle(LDL_MainWindow *mainWindow, const char *title)
{
    if (mainWindow)
    {
        LDL_BaseWindowSetTitle(&mainWindow->BaseWindow, title);

        if (mainWindow->Display && mainWindow->Window)
        {
            XStoreName(mainWindow->Display, mainWindow->Window, LDL_BaseWindowGetTitle(&mainWindow->BaseWindow));
        }
    }
}

void LDL_MainWindowPollEvents(LDL_MainWindow *mainWindow)
{
    XEvent event;
    LDL_Event report;
    size_t button;
    size_t key;
    size_t code;

    if (mainWindow && mainWindow->Display)
    {
        while (XPending(mainWindow->Display))
        {
            XNextEvent(mainWindow->Display, &event);

            switch (event.type)
            {

            case ConfigureNotify:
                report.Type = LDL_EventIsResize;
                report.u.Resize.Width = event.xconfigure.width;
                report.u.Resize.Height = event.xconfigure.height;
                LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
                break;

            case MotionNotify:
                report.Type = LDL_EventIsMouseMove;
                report.u.Mouse.PosX = event.xmotion.x;
                report.u.Mouse.PosY = event.xmotion.y;
                LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
                break;

            case KeyPress:
                report.Type = LDL_EventIsKeyboard;
                report.u.Keyboard.State = LDL_ButtonStatePressed;
                code = XKeycodeToKeysym(mainWindow->Display, event.xkey.keycode, 0);
                key = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, code);
                report.u.Keyboard.Key = key;
                LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
                break;

            case KeyRelease:
                report.Type = LDL_EventIsKeyboard;
                report.u.Keyboard.State = LDL_ButtonStateReleased;
                code = XKeycodeToKeysym(mainWindow->Display, event.xkey.keycode, 0);
                key = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, code);
                report.u.Keyboard.Key = key;
                LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
                break;

            case ButtonPress:
                report.Type = LDL_EventIsMouseClick;
                report.u.Mouse.State = LDL_ButtonStatePressed;

                button = 0;

                switch (event.xbutton.button)
                {
                case 1:
                    button = LDL_MouseButtonLeft;
                    break;
                case 2:
                    button = LDL_MouseButtonRight;
                    break;
                case 3:
                    button = LDL_MouseButtonMiddle;
                    break;
                }

                report.u.Mouse.Button = button;
                report.u.Mouse.PosX = event.xbutton.x;
                report.u.Mouse.PosY = event.xbutton.y;
                LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
                break;
            }
        }
    }
}

bool LDL_MainWindowGetEvent(LDL_MainWindow *mainWindow, LDL_Event *event)
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

void LDL_MainWindowStopEvent(LDL_MainWindow *mainWindow)
{
    if (mainWindow)
    {
        LDL_EventHandlerStop(&mainWindow->EventHandler);
    }
}

bool LDL_MainWindowIsRunning(LDL_MainWindow *mainWindow)
{
    if (mainWindow)
    {
        return LDL_EventHandlerRunning(&mainWindow->EventHandler);
    }

    return false;
}
