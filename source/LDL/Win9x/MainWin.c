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
#include <LDL/Win9x/MainWin.h>

static const char AppName[] = "MainWindow";

LRESULT CALLBACK LDL_MainWindowHandler(LDL_MainWindow* mainWindow, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LDL_Event event;

    if (mainWindow && mainWindow->Hwnd)
    {
        memset(&event, 0, sizeof(event));

        switch (Message)
        {
        case WM_PAINT:
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_MOUSEMOVE:
            event.u.Type = LDL_EventIsMouseMove;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_LBUTTONDOWN:
            event.u.Type = LDL_EventIsMouseClick;
            event.u.Mouse.State = LDL_ButtonStatePressed;
            event.u.Mouse.Button = LDL_MouseButtonLeft;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_LBUTTONUP:
            event.u.Type = LDL_EventIsMouseClick;
            event.u.Mouse.State = LDL_ButtonStateReleased;
            event.u.Mouse.Button = LDL_MouseButtonLeft;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_RBUTTONDOWN:
            event.u.Type = LDL_EventIsMouseClick;
            event.u.Mouse.State = LDL_ButtonStatePressed;
            event.u.Mouse.Button = LDL_MouseButtonRight;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_RBUTTONUP:
            event.u.Type = LDL_EventIsMouseClick;
            event.u.Mouse.State = LDL_ButtonStateReleased;
            event.u.Mouse.Button = LDL_MouseButtonRight;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_MBUTTONDOWN:
            event.u.Type = LDL_EventIsMouseClick;
            event.u.Mouse.State = LDL_ButtonStatePressed;
            event.u.Mouse.Button = LDL_MouseButtonMiddle;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_MBUTTONUP:
            event.u.Type = LDL_EventIsMouseClick;
            event.u.Mouse.State = LDL_ButtonStateReleased;
            event.u.Mouse.Button = LDL_MouseButtonMiddle;
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_SIZE:
            event.u.Type = LDL_EventIsResize;
            event.u.Resize.Width = LOWORD(LParam);
            event.u.Resize.Height = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_CLOSE:
            event.u.Type = LDL_EventIsQuit;
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
            event.u.Type = LDL_EventIsKeyboard;
            event.u.Keyboard.State = LDL_ButtonStatePressed;
            event.u.Keyboard.Key = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, (uint32_t)WParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_KEYUP:
        case WM_SYSKEYUP:
            event.u.Type = LDL_EventIsKeyboard;
            event.u.Keyboard.State = LDL_ButtonStateReleased;
            event.u.Keyboard.Key = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, (uint32_t)WParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_SETFOCUS:
            event.u.Type = LDL_EventIsGainedFocus;
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_KILLFOCUS:
            event.u.Type = LDL_EventIsLostFocus;
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_MOUSEWHEEL:
            event.u.Type = LDL_EventIsMouseScroll;
            event.u.Mouse.Scroll = LDL_MouseScrollVertical;
            event.u.Mouse.Delta = GET_WHEEL_DELTA_WPARAM(WParam);
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;

        case WM_MOUSEHWHEEL:
            event.u.Type = LDL_EventIsMouseScroll;
            event.u.Mouse.Scroll = LDL_MouseScrollHorizontal;
            event.u.Mouse.Delta = GET_WHEEL_DELTA_WPARAM(WParam);
            event.u.Mouse.PosX = LOWORD(LParam);
            event.u.Mouse.PosY = HIWORD(LParam);
            LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
            break;
        }

        return DefWindowProcA(mainWindow->Hwnd, Message, WParam, LParam);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result;

#ifdef _WIN64
    LDL_MainWindow* This = (LDL_MainWindow*)GetWindowLongPtrA(Hwnd, GWLP_USERDATA);
#elif _WIN32
    LDL_MainWindow* This = (LDL_MainWindow*)GetWindowLongA(Hwnd, GWL_USERDATA);
#endif  

    if (This != NULL)
        result = LDL_MainWindowHandler(This, Message, WParam, LParam);
    else
        result = DefWindowProcA(Hwnd, Message, WParam, LParam);

    return result;
}

void LDL_MainWindowInit(LDL_MainWindow* mainWindow, LDL_Result* result, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode)
{
	HINSTANCE instance;
    WNDCLASSA windowClass;
    ATOM      atom;
    RECT      rect;
    BOOL      adjust;
    DWORD     style;
    int       posX;
    int       posY;
    int showCmd = SW_SHOW;

#ifdef _WIN64
    LONG_PTR setWindow;
#elif _WIN32
    LONG     setWindow;
#endif 

    if (mainWindow && result)
    {
        LDL_WindowErrorInit(&mainWindow->WindowError);
        LDL_KeyMapperInit(&mainWindow->KeyMapper);
        LDL_EventHandlerInit(&mainWindow->EventHandler);
        LDL_BaseWindowInit(&mainWindow->BaseWindow, pos, size, title, mode);

        instance = GetModuleHandleA(NULL);
        if (instance == NULL)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
            return;
        }

        memset(&windowClass, 0, sizeof(windowClass));

        windowClass.hInstance = instance;
        windowClass.lpszClassName = AppName;
        windowClass.lpfnWndProc = WndProc;
        windowClass.style = CS_HREDRAW | CS_VREDRAW;
        windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        windowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
        windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);

        atom = RegisterClassA(&windowClass);
        if (atom == INVALID_ATOM)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
            return;
        }

        rect.left = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).x;
        rect.top = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).y;
        rect.right = LDL_BaseWindowGetSize(&mainWindow->BaseWindow).x;
        rect.bottom = LDL_BaseWindowGetSize(&mainWindow->BaseWindow).y;

        if (mode & LDL_WindowModeFullScreen)
        {
            style = WS_POPUP;
        }
        else if (mode & LDL_WindowModeFixed)
        {
            style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
        }
        else
        {
            style = WS_OVERLAPPEDWINDOW;
        }

        if (mode & LDL_WindowModeMinimized)
        {
            showCmd = SW_SHOWMINIMIZED;
        }
        else if (mode & LDL_WindowModeMaximized)
        {
            showCmd = SW_SHOWMAXIMIZED;
        }
        else
        {
            showCmd = SW_SHOWNORMAL;
        }

        adjust = AdjustWindowRect(&rect, style, FALSE);
        if (!adjust)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
            return;
        }

        if (mode & LDL_WindowModeCentered)
        {
            posX = CW_USEDEFAULT;
            posY = CW_USEDEFAULT;
        }
        else
        {
            posX = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).x;
            posY = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).y;
        }

        mainWindow->Hwnd = CreateWindowA(AppName, LDL_BaseWindowGetTitle(&mainWindow->BaseWindow), style, posX, posY, rect.right - rect.left, rect.bottom - rect.top, 0, 0, instance, 0);
        if (mainWindow->Hwnd == NULL)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
            return;
        }

#ifdef _WIN64
        setWindow = SetWindowLongPtrA(mainWindow->Hwnd, GWLP_USERDATA, (LONG_PTR)mainWindow);
#elif _WIN32
        setWindow = SetWindowLongA(mainWindow->Hwnd, GWL_USERDATA, (LONG)mainWindow);
#endif  

        if (setWindow == 0 && GetLastError() != 0)
        {
            LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
            return;
        }

        ShowWindow(mainWindow->Hwnd, showCmd);
    }
}

void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
    {
        if (mainWindow->Hwnd)
        {
            DestroyWindow(mainWindow->Hwnd);
            mainWindow->Hwnd = NULL;
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
    MSG msg;

    if (mainWindow && mainWindow->Hwnd)
    {
        while (PeekMessageA(&msg, mainWindow->Hwnd, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }
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
