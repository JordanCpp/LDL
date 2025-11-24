// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/StdFuncs.hpp>
#include <LDL/Assert.hpp>
#include <LDL/Enums.hpp>
#include <LDL/WinNT/MainWin.hpp>

static const UINT timePeriod = 1;
static const WCHAR AppName[]  = L"MainWindow";

HWND LDL_MainWindow::GetHwnd()
{
    return _hwnd;
}

HDC LDL_MainWindow::GetHdc()
{
    return _hdc;
}

LRESULT CALLBACK LDL_MainWindow::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
{
    LDL_Event event;

    ZeroMemory(&event, sizeof(event));

    switch (Message)
    {
    case WM_PAINT:
        break;

    case WM_DESTROY:
        event.Type = IsQuit;
        _eventer.Push(event);
        break;

    case WM_MOUSEMOVE:
        event.Type       = IsMouseMove;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type         = IsMouseClick;
        event.Mouse.State  = LDL_ButtonState::Pressed;
        event.Mouse.Button = LDL_MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type         = IsMouseClick;
        event.Mouse.State  = LDL_ButtonState::Released;
        event.Mouse.Button = LDL_MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type         = IsMouseClick;
        event.Mouse.State  = LDL_ButtonState::Pressed;
        event.Mouse.Button = LDL_MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type         = IsMouseClick;
        event.Mouse.State  = LDL_ButtonState::Released;
        event.Mouse.Button = LDL_MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MBUTTONDOWN:
        event.Type         = IsMouseClick;
        event.Mouse.State  = LDL_ButtonState::Pressed;
        event.Mouse.Button = LDL_MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MBUTTONUP:
        event.Type         = IsMouseClick;
        event.Mouse.State  = LDL_ButtonState::Released;
        event.Mouse.Button = LDL_MouseButton::Middle;
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
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        event.Type           = IsKeyboard;
        event.Keyboard.State = LDL_ButtonState::Pressed;
        event.Keyboard.Key   = _keyMapper.ConvertKey(WParam);
        _eventer.Push(event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type           = IsKeyboard;
        event.Keyboard.State = LDL_ButtonState::Released;
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
        event.Mouse.Scroll = LDL_MouseScroll::Vertical;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MOUSEHWHEEL:
        event.Type         = IsMouseScroll;
        event.Mouse.Scroll = LDL_MouseScroll::Horizontal;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;
    }

    return DefWindowProcW(_hwnd, Message, WParam, LParam);
}

LRESULT CALLBACK LDL_MainWindow::WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result;

#ifdef _WIN64
    LDL_MainWindow* This = (LDL_MainWindow*)GetWindowLongPtrW(Hwnd, GWLP_USERDATA);
#elif _WIN32
    LDL_MainWindow* This = (LDL_MainWindow*)GetWindowLongW(Hwnd, GWL_USERDATA);
#endif  

    if (This != NULL)
        result = This->Handler(Message, WParam, LParam);
    else
        result = DefWindowProcW(Hwnd, Message, WParam, LParam);

    return result;
}

LDL_MainWindow::LDL_MainWindow(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _baseWindow(pos, size, title, mode),
    _result(result)
{
    timeBeginPeriod(timePeriod);

    LDL_memset(&_windowClass, 0, sizeof(WNDCLASSEXW));
    LDL_memset(&_instance, 0, sizeof(HINSTANCE));
    LDL_memset(&_msg, 0, sizeof(MSG));
    LDL_memset(&_atom, 0, sizeof(ATOM));
    LDL_memset(&_hwnd, 0, sizeof(HWND));
    LDL_memset(&_hdc, 0, sizeof(HDC));

    _instance = GetModuleHandle(NULL);
    if (_instance == NULL)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    _windowClass.cbSize = sizeof(WNDCLASSEXW);
    _windowClass.hInstance     = _instance;
    _windowClass.lpszClassName = AppName;
    _windowClass.lpfnWndProc   = WndProc;
    _windowClass.style         = CS_HREDRAW | CS_VREDRAW;
    _windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _windowClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    _windowClass.hCursor       = LoadCursor(NULL, IDC_ARROW);

    _atom = RegisterClassExW(&_windowClass);
    if (_atom == INVALID_ATOM)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

    DWORD style = 0;
    
    if (_baseWindow.IsFixed())
    {
        style = WS_OVERLAPPED | WS_SYSMENU;
    }
    else if (_baseWindow.IsResized())
    {
        style = WS_OVERLAPPEDWINDOW;
    }
    else
    {
        style = WS_OVERLAPPED | WS_SYSMENU;
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

    if (_baseWindow.IsCentered())
    {

    }

    _hwnd = CreateWindowW(AppName, L"", style, (int)_baseWindow.Pos().x, (int)_baseWindow.Pos().y, rect.right - rect.left, rect.bottom - rect.top, 0, 0, _instance, 0);
    if (_hwnd == NULL)
    {
        _result.Message(_windowError.GetErrorMessage());
        return;
    }

#ifdef _WIN64
    LONG_PTR setWindow = SetWindowLongPtr(_hwnd, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    LONG     setWindow = SetWindowLongW(_hwnd, GWL_USERDATA, (LONG)this);
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

LDL_MainWindow::~LDL_MainWindow()
{
    timeEndPeriod(timePeriod);

    UnregisterClassW(AppName, _instance);
    ReleaseDC(_hwnd, _hdc);
}

bool LDL_MainWindow::Running()
{
    return _eventer.Running();
}

void LDL_MainWindow::PollEvents()
{
    while (PeekMessageW(&_msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&_msg);
        DispatchMessageW(&_msg);
    }
}

bool LDL_MainWindow::GetEvent(LDL_Event& event)
{
    if (!_eventer.Empty())
    {
        _eventer.Pop(event);

        return true;
    }

    PollEvents();

    return false;
}

bool LDL_MainWindow::WaitEvent(LDL_Event& event)
{
    if (_eventer.Running())
    {
        if (GetMessageW(&_msg, _hwnd, 0, 0) == -1)
        {
        }
        else
        {
            _eventer.Pop(event);

            TranslateMessage(&_msg);
            DispatchMessageW(&_msg);
        }
    }

    return _eventer.Running();
}

void LDL_MainWindow::StopEvent()
{
    _eventer.Stop();
}

void LDL_MainWindow::Title(const char* title)
{
    _baseWindow.Title(title);

    _utfConverter.convertToUTF16(title);
    
    SetWindowTextW(_hwnd, (LPCWSTR)_utfConverter.getUTF16Data());
}

const char* LDL_MainWindow::Title()
{
    return _baseWindow.Title();
}

const LDL_Vec2u& LDL_MainWindow::Size()
{
    RECT rect;

    LDL_memset(&rect, 0, sizeof(rect));

    if (GetClientRect(_hwnd, &rect))
    {
        _baseWindow.Size(LDL_Vec2u(rect.right - rect.left, rect.bottom - rect.top));
    }

    return _baseWindow.Size();
}

const LDL_Vec2u& LDL_MainWindow::Pos()
{
    return _baseWindow.Pos();
}
