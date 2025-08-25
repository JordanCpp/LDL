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
using namespace LDL::Utils;

static const UINT timePeriod = 1;
static const char AppName[]  = "MainWindow";

uint8_t MainWindow::ConvertKey(size_t key)
{
    return _keyMapping.FindKey(key);
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
    InitKeyMapping();

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

void MainWindow::InitKeyMapping()
{
    _keyMapping.Add(KeyMap(VK_LWIN,       KeyboardKey::LSystem));
    _keyMapping.Add(KeyMap(VK_RWIN,       KeyboardKey::RSystem));
    _keyMapping.Add(KeyMap(VK_APPS,       KeyboardKey::Menu));

    _keyMapping.Add(KeyMap(VK_OEM_1,      KeyboardKey::Semicolon));
    _keyMapping.Add(KeyMap(VK_OEM_2,      KeyboardKey::Slash));
    _keyMapping.Add(KeyMap(VK_OEM_PLUS,   KeyboardKey::Equal));
    _keyMapping.Add(KeyMap(VK_OEM_MINUS,  KeyboardKey::Hyphen));
    _keyMapping.Add(KeyMap(VK_OEM_4,      KeyboardKey::LBracket));
    _keyMapping.Add(KeyMap(VK_OEM_6,      KeyboardKey::RBracket));
    _keyMapping.Add(KeyMap(VK_OEM_COMMA,  KeyboardKey::Comma));
    _keyMapping.Add(KeyMap(VK_OEM_PERIOD, KeyboardKey::Period));
    _keyMapping.Add(KeyMap(VK_OEM_7,      KeyboardKey::Quote));
    _keyMapping.Add(KeyMap(VK_OEM_5,      KeyboardKey::Backslash));
    _keyMapping.Add(KeyMap(VK_OEM_3,      KeyboardKey::Tilde));

    _keyMapping.Add(KeyMap(VK_ESCAPE,     KeyboardKey::Escape));
    _keyMapping.Add(KeyMap(VK_SPACE,      KeyboardKey::Space));
    _keyMapping.Add(KeyMap(VK_RETURN,     KeyboardKey::Enter));
    _keyMapping.Add(KeyMap(VK_BACK,       KeyboardKey::Backspace));
    _keyMapping.Add(KeyMap(VK_TAB,        KeyboardKey::Tab));

    _keyMapping.Add(KeyMap(VK_PRIOR,      KeyboardKey::PageUp));
    _keyMapping.Add(KeyMap(VK_NEXT,       KeyboardKey::PageDown));
    _keyMapping.Add(KeyMap(VK_END,        KeyboardKey::End));
    _keyMapping.Add(KeyMap(VK_HOME,       KeyboardKey::Home));
    _keyMapping.Add(KeyMap(VK_INSERT,     KeyboardKey::Insert));
    _keyMapping.Add(KeyMap(VK_DELETE,     KeyboardKey::Delete));

    _keyMapping.Add(KeyMap(VK_LEFT,       KeyboardKey::Left));
    _keyMapping.Add(KeyMap(VK_RIGHT,      KeyboardKey::Right));
    _keyMapping.Add(KeyMap(VK_UP,         KeyboardKey::Up));
    _keyMapping.Add(KeyMap(VK_DOWN,       KeyboardKey::Down));

    _keyMapping.Add(KeyMap(VK_F1,         KeyboardKey::F1));
    _keyMapping.Add(KeyMap(VK_F2,         KeyboardKey::F2));
    _keyMapping.Add(KeyMap(VK_F3,         KeyboardKey::F3));
    _keyMapping.Add(KeyMap(VK_F4,         KeyboardKey::F4));
    _keyMapping.Add(KeyMap(VK_F5,         KeyboardKey::F5));
    _keyMapping.Add(KeyMap(VK_F6,         KeyboardKey::F6));
    _keyMapping.Add(KeyMap(VK_F7,         KeyboardKey::F7));
    _keyMapping.Add(KeyMap(VK_F8,         KeyboardKey::F8));
    _keyMapping.Add(KeyMap(VK_F9,         KeyboardKey::F9));
    _keyMapping.Add(KeyMap(VK_F10,        KeyboardKey::F10));
    _keyMapping.Add(KeyMap(VK_F11,        KeyboardKey::F11));
    _keyMapping.Add(KeyMap(VK_F12,        KeyboardKey::F12));
    _keyMapping.Add(KeyMap(VK_F13,        KeyboardKey::F13));
    _keyMapping.Add(KeyMap(VK_F14,        KeyboardKey::F14));
    _keyMapping.Add(KeyMap(VK_F15,        KeyboardKey::F15));

    _keyMapping.Add(KeyMap(VK_NUMPAD0,    KeyboardKey::Numpad0));
    _keyMapping.Add(KeyMap(VK_NUMPAD1,    KeyboardKey::Numpad1));
    _keyMapping.Add(KeyMap(VK_NUMPAD2,    KeyboardKey::Numpad2));
    _keyMapping.Add(KeyMap(VK_NUMPAD3,    KeyboardKey::Numpad3));
    _keyMapping.Add(KeyMap(VK_NUMPAD4,    KeyboardKey::Numpad4));
    _keyMapping.Add(KeyMap(VK_NUMPAD5,    KeyboardKey::Numpad5));
    _keyMapping.Add(KeyMap(VK_NUMPAD6,    KeyboardKey::Numpad6));
    _keyMapping.Add(KeyMap(VK_NUMPAD7,    KeyboardKey::Numpad7));
    _keyMapping.Add(KeyMap(VK_NUMPAD8,    KeyboardKey::Numpad8));
    _keyMapping.Add(KeyMap(VK_NUMPAD9,    KeyboardKey::Numpad9));

    _keyMapping.Add(KeyMap(VK_ADD,        KeyboardKey::Add));
    _keyMapping.Add(KeyMap(VK_SUBTRACT,   KeyboardKey::Subtract));
    _keyMapping.Add(KeyMap(VK_MULTIPLY,   KeyboardKey::Multiply));
    _keyMapping.Add(KeyMap(VK_DIVIDE,     KeyboardKey::Divide));

    _keyMapping.Add(KeyMap(VK_PAUSE,      KeyboardKey::Pause));

    _keyMapping.Add(KeyMap('A',           KeyboardKey::A));
    _keyMapping.Add(KeyMap('Z',           KeyboardKey::Z));
    _keyMapping.Add(KeyMap('E',           KeyboardKey::E));
    _keyMapping.Add(KeyMap('R',           KeyboardKey::R));
    _keyMapping.Add(KeyMap('T',           KeyboardKey::T));
    _keyMapping.Add(KeyMap('Y',           KeyboardKey::Y));
    _keyMapping.Add(KeyMap('U',           KeyboardKey::U));
    _keyMapping.Add(KeyMap('I',           KeyboardKey::I));
    _keyMapping.Add(KeyMap('O',           KeyboardKey::O));
    _keyMapping.Add(KeyMap('P',           KeyboardKey::P));
    _keyMapping.Add(KeyMap('Q',           KeyboardKey::Q));
    _keyMapping.Add(KeyMap('S',           KeyboardKey::S));
    _keyMapping.Add(KeyMap('D',           KeyboardKey::D));
    _keyMapping.Add(KeyMap('F',           KeyboardKey::F));
    _keyMapping.Add(KeyMap('G',           KeyboardKey::G));
    _keyMapping.Add(KeyMap('H',           KeyboardKey::H));
    _keyMapping.Add(KeyMap('J',           KeyboardKey::J));
    _keyMapping.Add(KeyMap('K',           KeyboardKey::K));
    _keyMapping.Add(KeyMap('W',           KeyboardKey::W));
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
