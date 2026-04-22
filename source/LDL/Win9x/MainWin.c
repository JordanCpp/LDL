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

    memset(&event, 0, sizeof(event));

    switch (Message)
    {
    case WM_PAINT:
        break;

    case WM_DESTROY:
        break;

    case WM_MOUSEMOVE:
        event.Type = LDL_EventIsMouseMove;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_LBUTTONDOWN:
        event.Type = LDL_EventIsMouseClick;
        event.Mouse.State = LDL_ButtonStatePressed;
        event.Mouse.Button = LDL_MouseButtonLeft;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_LBUTTONUP:
        event.Type = LDL_EventIsMouseClick;
        event.Mouse.State = LDL_ButtonStateReleased;
        event.Mouse.Button = LDL_MouseButtonLeft;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_RBUTTONDOWN:
        event.Type = LDL_EventIsMouseClick;
        event.Mouse.State = LDL_ButtonStatePressed;
        event.Mouse.Button = LDL_MouseButtonRight;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_RBUTTONUP:
        event.Type = LDL_EventIsMouseClick;
        event.Mouse.State = LDL_ButtonStateReleased;
        event.Mouse.Button = LDL_MouseButtonRight;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_MBUTTONDOWN:
        event.Type = LDL_EventIsMouseClick;
        event.Mouse.State = LDL_ButtonStatePressed;
        event.Mouse.Button = LDL_MouseButtonMiddle;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_MBUTTONUP:
        event.Type = LDL_EventIsMouseClick;
        event.Mouse.State = LDL_ButtonStateReleased;
        event.Mouse.Button = LDL_MouseButtonMiddle;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_SIZE:
        event.Type = LDL_EventIsResize;
        event.Resize.Width = LOWORD(LParam);
        event.Resize.Height = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_CLOSE:
        event.Type = LDL_EventIsQuit;
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        event.Type = LDL_EventIsKeyboard;
        event.Keyboard.State = LDL_ButtonStatePressed;
        event.Keyboard.Key = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, WParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type = LDL_EventIsKeyboard;
        event.Keyboard.State = LDL_ButtonStateReleased;
        event.Keyboard.Key = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, WParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_SETFOCUS:
        event.Type = LDL_EventIsGainedFocus;
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_KILLFOCUS:
        event.Type = LDL_EventIsLostFocus;
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_MOUSEWHEEL:
        event.Type = LDL_EventIsMouseScroll;
        event.Mouse.Scroll = LDL_MouseScrollVertical;
        event.Mouse.Delta = HIWORD(WParam);
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;

    case WM_MOUSEHWHEEL:
        event.Type = LDL_EventIsMouseScroll;
        event.Mouse.Scroll = LDL_MouseScrollHorizontal;
        event.Mouse.Delta = HIWORD(WParam);
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        LDL_EventHandlerPush(&mainWindow->EventHandler, &event);
        break;
    }

    return DefWindowProcA(mainWindow->Hwnd, Message, WParam, LParam);
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

#ifdef _WIN64
    LONG_PTR setWindow;
#elif _WIN32
    LONG     setWindow;
#endif 

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

    windowClass.hInstance     = instance;
    windowClass.lpszClassName = AppName;
    windowClass.lpfnWndProc   = WndProc;
    windowClass.style         = CS_HREDRAW | CS_VREDRAW;
    windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    windowClass.hIcon         = LoadIconA(NULL, IDI_APPLICATION);
    windowClass.hCursor       = LoadCursorA(NULL, IDC_ARROW);

    atom = RegisterClassA(&windowClass);
    if (atom == INVALID_ATOM)
    {
        LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
        return;
    }

    rect.left   = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).x;
    rect.top    = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).y;
    rect.right  = LDL_BaseWindowGetSize(&mainWindow->BaseWindow).x;
    rect.bottom = LDL_BaseWindowGetSize(&mainWindow->BaseWindow).y;

    style = WS_OVERLAPPEDWINDOW;

    adjust = AdjustWindowRect(&rect, style, FALSE);
    if (!adjust)
    {
        LDL_ResultAddMessage(result, "%s\n", LDL_WindowErrorGetMessage(&mainWindow->WindowError));
        return;
    }

    posX = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).x;
    posY = LDL_BaseWindowGetPos(&mainWindow->BaseWindow).y;

    mainWindow->Hwnd = CreateWindowA(AppName, "", style, posX, posY, rect.right - rect.left, rect.bottom - rect.top, 0, 0, instance, 0);
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

    ShowWindow(mainWindow->Hwnd, SW_SHOW);
}

void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow)
{
}

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow* mainWindow)
{
	return LDL_BaseWindowGetPos(&mainWindow->BaseWindow);
}

void LDL_MainWindowPollEvents(LDL_MainWindow* mainWindow)
{
    MSG msg;

    while (PeekMessageA(&msg, mainWindow->Hwnd, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

bool LDL_MainWindowGetEvent(LDL_MainWindow* mainWindow, LDL_Event* event)
{
    
    if (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
    {
        LDL_EventHandlerPop(&mainWindow->EventHandler, event);

        return true;
    }

    LDL_MainWindowPollEvents(mainWindow);

    return false;
}

void LDL_MainWindowStopEvent(LDL_MainWindow* mainWindow)
{
    LDL_EventHandlerStop(&mainWindow->EventHandler);
}

bool LDL_MainWindowIsRunning(LDL_MainWindow* mainWindow)
{
    return LDL_EventHandlerRunning(&mainWindow->EventHandler);
}
