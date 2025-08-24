// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>
#include <LDL/std/string.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Graphics;
using namespace LDL::Math;

static const UINT timePeriod = 1;
static const char AppName[]  = "MainWindow";

uint8_t MainWindow::ConvertKey(size_t key)
{
    switch (key)
    {
    case VK_LWIN:       return KeyboardKey::LSystem;
    case VK_RWIN:       return KeyboardKey::RSystem;
    case VK_APPS:       return KeyboardKey::Menu;
    case VK_OEM_1:      return KeyboardKey::Semicolon;
    case VK_OEM_2:      return KeyboardKey::Slash;
    case VK_OEM_PLUS:   return KeyboardKey::Equal;
    case VK_OEM_MINUS:  return KeyboardKey::Hyphen;
    case VK_OEM_4:      return KeyboardKey::LBracket;
    case VK_OEM_6:      return KeyboardKey::RBracket;
    case VK_OEM_COMMA:  return KeyboardKey::Comma;
    case VK_OEM_PERIOD: return KeyboardKey::Period;
    case VK_OEM_7:      return KeyboardKey::Quote;
    case VK_OEM_5:      return KeyboardKey::Backslash;
    case VK_OEM_3:      return KeyboardKey::Tilde;
    case VK_ESCAPE:     return KeyboardKey::Escape;
    case VK_SPACE:      return KeyboardKey::Space;
    case VK_RETURN:     return KeyboardKey::Enter;
    case VK_BACK:       return KeyboardKey::Backspace;
    case VK_TAB:        return KeyboardKey::Tab;
    case VK_PRIOR:      return KeyboardKey::PageUp;
    case VK_NEXT:       return KeyboardKey::PageDown;
    case VK_END:        return KeyboardKey::End;
    case VK_HOME:       return KeyboardKey::Home;
    case VK_INSERT:     return KeyboardKey::Insert;
    case VK_DELETE:     return KeyboardKey::Delete;
    case VK_ADD:        return KeyboardKey::Add;
    case VK_SUBTRACT:   return KeyboardKey::Subtract;
    case VK_MULTIPLY:   return KeyboardKey::Multiply;
    case VK_DIVIDE:     return KeyboardKey::Divide;
    case VK_PAUSE:      return KeyboardKey::Pause;
    case VK_F1:         return KeyboardKey::F1;
    case VK_F2:         return KeyboardKey::F2;
    case VK_F3:         return KeyboardKey::F3;
    case VK_F4:         return KeyboardKey::F4;
    case VK_F5:         return KeyboardKey::F5;
    case VK_F6:         return KeyboardKey::F6;
    case VK_F7:         return KeyboardKey::F7;
    case VK_F8:         return KeyboardKey::F8;
    case VK_F9:         return KeyboardKey::F9;
    case VK_F10:        return KeyboardKey::F10;
    case VK_F11:        return KeyboardKey::F11;
    case VK_F12:        return KeyboardKey::F12;
    case VK_F13:        return KeyboardKey::F13;
    case VK_F14:        return KeyboardKey::F14;
    case VK_F15:        return KeyboardKey::F15;
    case VK_LEFT:       return KeyboardKey::Left;
    case VK_RIGHT:      return KeyboardKey::Right;
    case VK_UP:         return KeyboardKey::Up;
    case VK_DOWN:       return KeyboardKey::Down;
    case VK_NUMPAD0:    return KeyboardKey::Numpad0;
    case VK_NUMPAD1:    return KeyboardKey::Numpad1;
    case VK_NUMPAD2:    return KeyboardKey::Numpad2;
    case VK_NUMPAD3:    return KeyboardKey::Numpad3;
    case VK_NUMPAD4:    return KeyboardKey::Numpad4;
    case VK_NUMPAD5:    return KeyboardKey::Numpad5;
    case VK_NUMPAD6:    return KeyboardKey::Numpad6;
    case VK_NUMPAD7:    return KeyboardKey::Numpad7;
    case VK_NUMPAD8:    return KeyboardKey::Numpad8;
    case VK_NUMPAD9:    return KeyboardKey::Numpad9;
    case 'A':           return KeyboardKey::A;
    case 'Z':           return KeyboardKey::Z;
    case 'E':           return KeyboardKey::E;
    case 'R':           return KeyboardKey::R;
    case 'T':           return KeyboardKey::T;
    case 'Y':           return KeyboardKey::Y;
    case 'U':           return KeyboardKey::U;
    case 'I':           return KeyboardKey::I;
    case 'O':           return KeyboardKey::O;
    case 'P':           return KeyboardKey::P;
    case 'Q':           return KeyboardKey::Q;
    case 'S':           return KeyboardKey::S;
    case 'D':           return KeyboardKey::D;
    case 'F':           return KeyboardKey::F;
    case 'G':           return KeyboardKey::G;
    case 'H':           return KeyboardKey::H;
    case 'J':           return KeyboardKey::J;
    case 'K':           return KeyboardKey::K;
    case 'L':           return KeyboardKey::L;
    case 'M':           return KeyboardKey::M;
    case 'W':           return KeyboardKey::W;
    case 'X':           return KeyboardKey::X;
    case 'C':           return KeyboardKey::C;
    case 'V':           return KeyboardKey::V;
    case 'B':           return KeyboardKey::B;
    case 'N':           return KeyboardKey::N;
    case '0':           return KeyboardKey::Num0;
    case '1':           return KeyboardKey::Num1;
    case '2':           return KeyboardKey::Num2;
    case '3':           return KeyboardKey::Num3;
    case '4':           return KeyboardKey::Num4;
    case '5':           return KeyboardKey::Num5;
    case '6':           return KeyboardKey::Num6;
    case '7':           return KeyboardKey::Num7;
    case '8':           return KeyboardKey::Num8;
    case '9':           return KeyboardKey::Num9;
    case VK_LSHIFT:     return KeyboardKey::Leftshift;
    case VK_RSHIFT:     return KeyboardKey::RightShift;
    case VK_LCONTROL:   return KeyboardKey::LeftControl;
    case VK_RCONTROL:   return KeyboardKey::RightControl;
    }

    return KeyboardKey::Unknown;
}

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
        event.Type       = Events::IsMouseMove;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_MBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_SIZE:
        event.Type          = Events::IsResize;
        event.Resize.Width  = LOWORD(LParam);
        event.Resize.Height = HIWORD(LParam);
        _eventer.Push(event);
        break;

    case WM_CLOSE:
        event.Type = Events::IsQuit;
        _eventer.Push(event);
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        event.Type           = IsKeyboard;
        event.Keyboard.State = ButtonState::Pressed;
        event.Keyboard.Key   = ConvertKey(WParam);
        _eventer.Push(event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type           = IsKeyboard;
        event.Keyboard.State = ButtonState::Released;
        event.Keyboard.Key   = ConvertKey(WParam);
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

MainWindow::MainWindow(Core::Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _baseWindow(pos, size, title),
    _result(result)
{
    timeBeginPeriod(timePeriod);

    LDL::memset(&_windowClass, 0, sizeof(WNDCLASS));
    LDL::memset(&_instance, 0, sizeof(HINSTANCE));
    LDL::memset(&_msg, 0, sizeof(MSG));
    LDL::memset(&_atom, 0, sizeof(ATOM));
    LDL::memset(&_hwnd, 0, sizeof(HWND));
    LDL::memset(&_hdc, 0, sizeof(HDC));

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
        style = WS_OVERLAPPED | WS_SYSMENU;
    else if (mode == WindowMode::Resized)
        style = WS_OVERLAPPEDWINDOW;
    //else
        //throw RuntimeError("WindowMode failed");

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

    LONG setWindow = 0;

#ifdef _WIN64
    setWindow = SetWindowLongPtr(_hwnd, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    setWindow = SetWindowLong(_hwnd, GWL_USERDATA, (LONG)this);
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
            //throw RuntimeError("GetMessage failed");
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
