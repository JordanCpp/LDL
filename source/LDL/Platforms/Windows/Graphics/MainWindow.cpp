// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/string.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>

using namespace LDL;

static const UINT timePeriod = 1;
static const char AppName[]  = "MainWindow";

LRESULT CALLBACK MainWindow::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
{
    Event event;

    ZeroMemory(&event, sizeof(event));

    switch (Message)
    {
    case WM_PAINT:
        break;

    case WM_DESTROY:
        break;

    case WM_MOUSEMOVE:
        event.Type       = IsMouseMove;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type         = IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type         = IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type         = IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type         = IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MBUTTONDOWN:
        event.Type         = IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MBUTTONUP:
        event.Type         = IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_SIZE:
        event.Type          = IsResize;
        event.Resize.Width  = LOWORD(LParam);
        event.Resize.Height = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_CLOSE:
        event.Type = IsQuit;
        _eventer.Push(event);
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        event.Type           = IsKeyboard;
        event.Keyboard.State = ButtonState::Pressed;
        event.Keyboard.Key   = _keyMapper.ConvertKey(WParam);
        _eventer.Push(event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type           = IsKeyboard;
        event.Keyboard.State = ButtonState::Released;
        event.Keyboard.Key   = _keyMapper.ConvertKey(WParam);
        _eventer.Push(event);
        break;

    case WM_SETFOCUS:
        event.Type = IsGainedFocus;
        _eventer.Push(event);
        break;

    case WM_KILLFOCUS:
        event.Type = IsLostFocus;
        _eventer.Push(event);
        break;

    case WM_MOUSEWHEEL:
        event.Type         = IsMouseScroll;
        event.Mouse.Scroll = MouseScroll::Vertical;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MOUSEHWHEEL:
        event.Type         = IsMouseScroll;
        event.Mouse.Scroll = MouseScroll::Horizontal;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;
    }

    return DefWindowProc(_hwnd, Message, WParam, LParam);
}

LRESULT CALLBACK MainWindow::WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result;

#ifdef _WIN64
    MainWindow* This = (MainWindow*)GetWindowLongPtr(Hwnd, GWLP_USERDATA);
#elif _WIN32
    MainWindow* This = (MainWindow*)GetWindowLong(Hwnd, GWL_USERDATA);
#endif  

    if (This != NULL)
        result = This->Handler(Message, WParam, LParam);
    else
        result = DefWindowProc(Hwnd, Message, WParam, LParam);

    return result;
}

MainWindow::MainWindow(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _baseWindow(pos, size, title),
    _result(result)
{
    timeBeginPeriod(timePeriod);

    LDL::LDL_memset(&_windowClass, 0, sizeof(WNDCLASS));
    LDL::LDL_memset(&_instance, 0, sizeof(HINSTANCE));
    LDL::LDL_memset(&_msg, 0, sizeof(MSG));
    LDL::LDL_memset(&_atom, 0, sizeof(ATOM));
    LDL::LDL_memset(&_hwnd, 0, sizeof(HWND));
    LDL::LDL_memset(&_hdc, 0, sizeof(HDC));

    _instance = GetModuleHandle(NULL);
    if (_instance == NULL)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    _windowClass.hInstance = _instance;
    _windowClass.lpszClassName = AppName;
    _windowClass.lpfnWndProc = WndProc;
    _windowClass.style = CS_HREDRAW | CS_VREDRAW;
    _windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    _windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);

    _atom = RegisterClass(&_windowClass);
    if (_atom == INVALID_ATOM)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    DWORD style = 0;
    
    if (mode == WindowMode::Fixed)
    {
        style = WS_OVERLAPPED | WS_SYSMENU;
    }
    else if (mode == WindowMode::Resized)
    {
        style = WS_OVERLAPPEDWINDOW;
    }

    RECT rect;

    rect.left   = (LONG)_baseWindow.Pos().x;
    rect.top    = (LONG)_baseWindow.Pos().y;
    rect.right  = (LONG)_baseWindow.Size().x;
    rect.bottom = (LONG)_baseWindow.Size().y;

    BOOL adjust = AdjustWindowRect(&rect, style, FALSE);
    if (!adjust)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    _hwnd = CreateWindow(AppName, "", style, (int)_baseWindow.Pos().x, (int)_baseWindow.Pos().y, rect.right - rect.left, rect.bottom - rect.top, 0, 0, _instance, 0);
    if (_hwnd == NULL)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

#ifdef _WIN64
    LONG_PTR setWindow = SetWindowLongPtr(_hwnd, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    LONG     setWindow = SetWindowLong(_hwnd, GWL_USERDATA, (LONG)this);
#endif  

    if (setWindow == 0 && GetLastError() != 0)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    _hdc = GetDC(_hwnd);
    if (_hdc == NULL)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    Title(title);
    ShowWindow(_hwnd, SW_SHOW);
}

MainWindow::~MainWindow()
{
    timeEndPeriod(timePeriod);

    UnregisterClass(AppName, _instance);
    ReleaseDC(_hwnd, _hdc);
}

bool MainWindow::Running()
{
    return _eventer.Running();
}

void MainWindow::PollEvents()
{
    while (PeekMessage(&_msg, _hwnd, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&_msg);
        DispatchMessage(&_msg);
    }
}

bool MainWindow::GetEvent(Event& event)
{
    if (!_eventer.Empty())
    {
        _eventer.Pop(event);

        return true;
    }

    PollEvents();

    return false;
}

bool MainWindow::WaitEvent(Event& event)
{
    if (_eventer.Running())
    {
        if (GetMessage(&_msg, _hwnd, 0, 0) == -1)
        {
        }
        else
        {
            _eventer.Pop(event);

            TranslateMessage(&_msg);
            DispatchMessage(&_msg);
        }
    }

    return _eventer.Running();
}

void MainWindow::StopEvent()
{
    _eventer.Stop();
}

void MainWindow::Title(const char* title)
{
    _baseWindow.Title(title);

    SetWindowText(_hwnd, _baseWindow.Title());
}

const char* MainWindow::Title()
{
    return _baseWindow.Title();
}

const Vec2u& MainWindow::Size()
{
    RECT rect;

    LDL_memset(&rect, 0, sizeof(rect));

    if (GetClientRect(_hwnd, &rect))
    {
        _baseWindow.Size(Vec2u(rect.right - rect.left, rect.bottom - rect.top));
    }

    return _baseWindow.Size();
}

const Vec2u& MainWindow::Pos()
{
    return _baseWindow.Pos();
}
