#include "MainWindow.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

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
        _Eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_MBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Pressed;
        event.Mouse.Button = MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_MBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = ButtonState::Released;
        event.Mouse.Button = MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_SIZE:
        event.Type          = Events::IsResize;
        event.Resize.Width  = LOWORD(LParam);
        event.Resize.Height = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_CLOSE:
        event.Type = Events::IsQuit;
        _Eventer.Push(event);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        event.Type           = IsKeyboard;
        event.Keyboard.State = ButtonState::Pressed;
        event.Keyboard.Key   = ConvertKey(WParam);
        _Eventer.Push(event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type           = IsKeyboard;
        event.Keyboard.State = ButtonState::Released;
        event.Keyboard.Key   = ConvertKey(WParam);
        _Eventer.Push(event);
        break;

    case WM_SETFOCUS:
        event.Type = IsGainedFocus;
        _Eventer.Push(event);
        break;

    case WM_KILLFOCUS:
        event.Type = IsLostFocus;
        _Eventer.Push(event);
        break;

    case WM_MOUSEWHEEL:
        event.Type         = IsMouseScroll;
        event.Mouse.Scroll = MouseScroll::Vertical;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_MOUSEHWHEEL:
        event.Type         = IsMouseScroll;
        event.Mouse.Scroll = MouseScroll::Vertical;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;
    }

    return DefWindowProc(_HWND, Message, WParam, LParam);
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

MainWindow::MainWindow(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _BaseWindow(pos, size, title)
{
    timeBeginPeriod(timePeriod);

    ZeroMemory(&_WNDCLASS, sizeof(WNDCLASS));
    ZeroMemory(&_HINSTANCE, sizeof(HINSTANCE));
    ZeroMemory(&_MSG, sizeof(MSG));
    ZeroMemory(&_ATOM, sizeof(ATOM));
    ZeroMemory(&_HWND, sizeof(HWND));
    ZeroMemory(&_HDC, sizeof(HDC));

    _HINSTANCE = GetModuleHandle(NULL);
    
    if (_HINSTANCE == NULL)
        throw RuntimeError("GetModuleHandle failed");

    _WNDCLASS.hInstance = _HINSTANCE;
    _WNDCLASS.lpszClassName = AppName;
    _WNDCLASS.lpfnWndProc = WndProc;
    _WNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    _WNDCLASS.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _WNDCLASS.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    _WNDCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);

    _ATOM = RegisterClass(&_WNDCLASS);

    if (_ATOM == INVALID_ATOM)
        throw RuntimeError("RegisterClass failed");
    
    DWORD style = 0;
    
    if (mode == WindowMode::Fixed)
        style = WS_OVERLAPPED | WS_SYSMENU;
    else if (mode == WindowMode::Resized)
        style = WS_OVERLAPPEDWINDOW;
    else
        throw RuntimeError("WindowMode failed");

    RECT rect;

    rect.left   = (LONG)_BaseWindow.Pos().x;
    rect.top    = (LONG)_BaseWindow.Pos().y;
    rect.right  = (LONG)_BaseWindow.Size().x;
    rect.bottom = (LONG)_BaseWindow.Size().y;

    if (!AdjustWindowRect(&rect, style, FALSE))
        throw RuntimeError("AdjustWindowRect failed");

    _HWND = CreateWindow(AppName, "", style, (int)_BaseWindow.Pos().x, (int)_BaseWindow.Pos().y, rect.right - rect.left, rect.bottom - rect.top, 0, 0, _HINSTANCE, 0);

    if (_HWND == INVALID_HANDLE_VALUE)
        throw RuntimeError("CreateWindow failed");

#ifdef _WIN64
    SetWindowLongPtr(_HWND, GWLP_WNDPROC, (LONG_PTR)WndProc);
    SetWindowLongPtr(_HWND, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    SetWindowLong(_HWND, GWL_WNDPROC, (LONG)WndProc);
    SetWindowLong(_HWND, GWL_USERDATA, (LONG)this);
#endif  

    _HDC = GetDC(_HWND);

    if (_HDC == INVALID_HANDLE_VALUE)
        throw RuntimeError("GetDC failed");

    Title(title);
    ShowWindow(_HWND, SW_SHOW);
}

MainWindow::~MainWindow()
{
    timeEndPeriod(timePeriod);

    UnregisterClass(AppName, _HINSTANCE);
    ReleaseDC(_HWND, _HDC);
    PostQuitMessage(0);
}

bool MainWindow::Running()
{
    return _Eventer.Running();
}

void MainWindow::PollEvents()
{
    while (PeekMessage(&_MSG, _HWND, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&_MSG);
        DispatchMessage(&_MSG);
    }
}

bool MainWindow::GetEvent(Event& event)
{
    if (!_Eventer.Empty())
    {
        _Eventer.Pop(event);

        return true;
    }

    return false;
}

bool MainWindow::WaitEvent(Event& event)
{
    BOOL result;

    if (_Eventer.Running())
    {
        result = GetMessage(&_MSG, _HWND, 0, 0);
        
        if (result == -1)
        {
            throw RuntimeError("GetMessage failed");
        }
        else
        {
            _Eventer.Pop(event);

            TranslateMessage(&_MSG);
            DispatchMessage(&_MSG);
        }
    }

    return _Eventer.Running();
}

void MainWindow::StopEvent()
{
    _Eventer.Stop();
}

void MainWindow::Title(const std::string& title)
{
    _BaseWindow.Title(title);

    SetWindowText(_HWND, _BaseWindow.Title().c_str());
}

const std::string& MainWindow::Title()
{
    return _BaseWindow.Title();
}

const Vec2u& MainWindow::Size()
{
    RECT rect;

    if (!GetClientRect(_HWND, &rect))
        throw RuntimeError("GetClientRect failed");

    _BaseWindow.Size(Vec2u(rect.right + Pos().x, rect.bottom + Pos().y));

    return _BaseWindow.Size();
}

const Vec2u& MainWindow::Pos()
{
    return _BaseWindow.Pos();
}
