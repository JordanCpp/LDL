#include "MainWindow.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

using namespace LDL::Graphics;

static const char AppName[] = "MainWindow";

size_t MainWindow::ConvertKey(size_t key)
{
    switch (key)
    {
    case VK_LWIN:       return LDL::Enums::KeyboardKey::LSystem;
    case VK_RWIN:       return LDL::Enums::KeyboardKey::RSystem;
    case VK_APPS:       return LDL::Enums::KeyboardKey::Menu;
    case VK_OEM_1:      return LDL::Enums::KeyboardKey::Semicolon;
    case VK_OEM_2:      return LDL::Enums::KeyboardKey::Slash;
    case VK_OEM_PLUS:   return LDL::Enums::KeyboardKey::Equal;
    case VK_OEM_MINUS:  return LDL::Enums::KeyboardKey::Hyphen;
    case VK_OEM_4:      return LDL::Enums::KeyboardKey::LBracket;
    case VK_OEM_6:      return LDL::Enums::KeyboardKey::RBracket;
    case VK_OEM_COMMA:  return LDL::Enums::KeyboardKey::Comma;
    case VK_OEM_PERIOD: return LDL::Enums::KeyboardKey::Period;
    case VK_OEM_7:      return LDL::Enums::KeyboardKey::Quote;
    case VK_OEM_5:      return LDL::Enums::KeyboardKey::Backslash;
    case VK_OEM_3:      return LDL::Enums::KeyboardKey::Tilde;
    case VK_ESCAPE:     return LDL::Enums::KeyboardKey::Escape;
    case VK_SPACE:      return LDL::Enums::KeyboardKey::Space;
    case VK_RETURN:     return LDL::Enums::KeyboardKey::Enter;
    case VK_BACK:       return LDL::Enums::KeyboardKey::Backspace;
    case VK_TAB:        return LDL::Enums::KeyboardKey::Tab;
    case VK_PRIOR:      return LDL::Enums::KeyboardKey::PageUp;
    case VK_NEXT:       return LDL::Enums::KeyboardKey::PageDown;
    case VK_END:        return LDL::Enums::KeyboardKey::End;
    case VK_HOME:       return LDL::Enums::KeyboardKey::Home;
    case VK_INSERT:     return LDL::Enums::KeyboardKey::Insert;
    case VK_DELETE:     return LDL::Enums::KeyboardKey::Delete;
    case VK_ADD:        return LDL::Enums::KeyboardKey::Add;
    case VK_SUBTRACT:   return LDL::Enums::KeyboardKey::Subtract;
    case VK_MULTIPLY:   return LDL::Enums::KeyboardKey::Multiply;
    case VK_DIVIDE:     return LDL::Enums::KeyboardKey::Divide;
    case VK_PAUSE:      return LDL::Enums::KeyboardKey::Pause;
    case VK_F1:         return LDL::Enums::KeyboardKey::F1;
    case VK_F2:         return LDL::Enums::KeyboardKey::F2;
    case VK_F3:         return LDL::Enums::KeyboardKey::F3;
    case VK_F4:         return LDL::Enums::KeyboardKey::F4;
    case VK_F5:         return LDL::Enums::KeyboardKey::F5;
    case VK_F6:         return LDL::Enums::KeyboardKey::F6;
    case VK_F7:         return LDL::Enums::KeyboardKey::F7;
    case VK_F8:         return LDL::Enums::KeyboardKey::F8;
    case VK_F9:         return LDL::Enums::KeyboardKey::F9;
    case VK_F10:        return LDL::Enums::KeyboardKey::F10;
    case VK_F11:        return LDL::Enums::KeyboardKey::F11;
    case VK_F12:        return LDL::Enums::KeyboardKey::F12;
    case VK_F13:        return LDL::Enums::KeyboardKey::F13;
    case VK_F14:        return LDL::Enums::KeyboardKey::F14;
    case VK_F15:        return LDL::Enums::KeyboardKey::F15;
    case VK_LEFT:       return LDL::Enums::KeyboardKey::Left;
    case VK_RIGHT:      return LDL::Enums::KeyboardKey::Right;
    case VK_UP:         return LDL::Enums::KeyboardKey::Up;
    case VK_DOWN:       return LDL::Enums::KeyboardKey::Down;
    case VK_NUMPAD0:    return LDL::Enums::KeyboardKey::Numpad0;
    case VK_NUMPAD1:    return LDL::Enums::KeyboardKey::Numpad1;
    case VK_NUMPAD2:    return LDL::Enums::KeyboardKey::Numpad2;
    case VK_NUMPAD3:    return LDL::Enums::KeyboardKey::Numpad3;
    case VK_NUMPAD4:    return LDL::Enums::KeyboardKey::Numpad4;
    case VK_NUMPAD5:    return LDL::Enums::KeyboardKey::Numpad5;
    case VK_NUMPAD6:    return LDL::Enums::KeyboardKey::Numpad6;
    case VK_NUMPAD7:    return LDL::Enums::KeyboardKey::Numpad7;
    case VK_NUMPAD8:    return LDL::Enums::KeyboardKey::Numpad8;
    case VK_NUMPAD9:    return LDL::Enums::KeyboardKey::Numpad9;
    case 'A':           return LDL::Enums::KeyboardKey::A;
    case 'Z':           return LDL::Enums::KeyboardKey::Z;
    case 'E':           return LDL::Enums::KeyboardKey::E;
    case 'R':           return LDL::Enums::KeyboardKey::R;
    case 'T':           return LDL::Enums::KeyboardKey::T;
    case 'Y':           return LDL::Enums::KeyboardKey::Y;
    case 'U':           return LDL::Enums::KeyboardKey::U;
    case 'I':           return LDL::Enums::KeyboardKey::I;
    case 'O':           return LDL::Enums::KeyboardKey::O;
    case 'P':           return LDL::Enums::KeyboardKey::P;
    case 'Q':           return LDL::Enums::KeyboardKey::Q;
    case 'S':           return LDL::Enums::KeyboardKey::S;
    case 'D':           return LDL::Enums::KeyboardKey::D;
    case 'F':           return LDL::Enums::KeyboardKey::F;
    case 'G':           return LDL::Enums::KeyboardKey::G;
    case 'H':           return LDL::Enums::KeyboardKey::H;
    case 'J':           return LDL::Enums::KeyboardKey::J;
    case 'K':           return LDL::Enums::KeyboardKey::K;
    case 'L':           return LDL::Enums::KeyboardKey::L;
    case 'M':           return LDL::Enums::KeyboardKey::M;
    case 'W':           return LDL::Enums::KeyboardKey::W;
    case 'X':           return LDL::Enums::KeyboardKey::X;
    case 'C':           return LDL::Enums::KeyboardKey::C;
    case 'V':           return LDL::Enums::KeyboardKey::V;
    case 'B':           return LDL::Enums::KeyboardKey::B;
    case 'N':           return LDL::Enums::KeyboardKey::N;
    case '0':           return LDL::Enums::KeyboardKey::Num0;
    case '1':           return LDL::Enums::KeyboardKey::Num1;
    case '2':           return LDL::Enums::KeyboardKey::Num2;
    case '3':           return LDL::Enums::KeyboardKey::Num3;
    case '4':           return LDL::Enums::KeyboardKey::Num4;
    case '5':           return LDL::Enums::KeyboardKey::Num5;
    case '6':           return LDL::Enums::KeyboardKey::Num6;
    case '7':           return LDL::Enums::KeyboardKey::Num7;
    case '8':           return LDL::Enums::KeyboardKey::Num8;
    case '9':           return LDL::Enums::KeyboardKey::Num9;
    case VK_LSHIFT:     return LDL::Enums::KeyboardKey::Leftshift;
    case VK_RSHIFT:     return LDL::Enums::KeyboardKey::RightShift;
    case VK_LCONTROL:   return LDL::Enums::KeyboardKey::LeftControl;
    case VK_RCONTROL:   return LDL::Enums::KeyboardKey::RightControl;
    }

    return LDL::Enums::KeyboardKey::Unknown;
}

LRESULT CALLBACK MainWindow::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
{
    LDL::Events::Event event;

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
        event.Mouse.State  = LDL::Enums::ButtonState::Pressed;
        event.Mouse.Button = LDL::Enums::MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = LDL::Enums::ButtonState::Released;
        event.Mouse.Button = LDL::Enums::MouseButton::Left;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = LDL::Enums::ButtonState::Pressed;
        event.Mouse.Button = LDL::Enums::MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = LDL::Enums::ButtonState::Released;
        event.Mouse.Button = LDL::Enums::MouseButton::Right;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_MBUTTONDOWN:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = LDL::Enums::ButtonState::Pressed;
        event.Mouse.Button = LDL::Enums::MouseButton::Middle;
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_MBUTTONUP:
        event.Type         = Events::IsMouseClick;
        event.Mouse.State  = LDL::Enums::ButtonState::Released;
        event.Mouse.Button = LDL::Enums::MouseButton::Middle;
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
        event.Type           = LDL::Events::IsKeyboard;
        event.Keyboard.State = LDL::Enums::ButtonState::Pressed;
        event.Keyboard.Key   = ConvertKey(WParam);
        _Eventer.Push(event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type           = LDL::Events::IsKeyboard;
        event.Keyboard.State = LDL::Enums::ButtonState::Released;
        event.Keyboard.Key   = ConvertKey(WParam);
        _Eventer.Push(event);
        break;

    case WM_SETFOCUS:
        event.Type = LDL::Events::IsGainedFocus;
        _Eventer.Push(event);
        break;

    case WM_KILLFOCUS:
        event.Type = LDL::Events::IsLostFocus;
        _Eventer.Push(event);
        break;

    case WM_MOUSEWHEEL:
        event.Type         = LDL::Events::IsMouseScroll;
        event.Mouse.Scroll = LDL::Enums::MouseScroll::Vertical;
        event.Mouse.Delta  = HIWORD(WParam);
        event.Mouse.PosX   = LOWORD(LParam);
        event.Mouse.PosY   = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_MOUSEHWHEEL:
        event.Type         = LDL::Events::IsMouseScroll;
        event.Mouse.Scroll = LDL::Enums::MouseScroll::Vertical;
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

MainWindow::MainWindow(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _BaseWindow(pos, size, title)
{
    ZeroMemory(&_WNDCLASS, sizeof(WNDCLASS));
    ZeroMemory(&_HINSTANCE, sizeof(HINSTANCE));
    ZeroMemory(&_MSG, sizeof(MSG));
    ZeroMemory(&_ATOM, sizeof(ATOM));
    ZeroMemory(&_HWND, sizeof(HWND));
    ZeroMemory(&_HDC, sizeof(HDC));

    _HINSTANCE = GetModuleHandle(NULL);
    
    if (_HINSTANCE == NULL)
        throw LDL::Core::RuntimeError("GetModuleHandle failed");

    _WNDCLASS.hInstance = _HINSTANCE;
    _WNDCLASS.lpszClassName = AppName;
    _WNDCLASS.lpfnWndProc = WndProc;
    _WNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    _WNDCLASS.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _WNDCLASS.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    _WNDCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);

    _ATOM = RegisterClass(&_WNDCLASS);

    if (_ATOM == INVALID_ATOM)
        throw LDL::Core::RuntimeError("RegisterClass failed");
    
    DWORD style = 0;
    
    if (mode == LDL::Enums::WindowMode::Fixed)
        style = WS_OVERLAPPED | WS_SYSMENU;
    else if (mode == LDL::Enums::WindowMode::Resized)
        style = WS_OVERLAPPEDWINDOW;
    else
        throw LDL::Core::RuntimeError("WindowMode failed");

    RECT rect;

    rect.left   = (LONG)_BaseWindow.Pos().PosX();
    rect.top    = (LONG)_BaseWindow.Pos().PosY();
    rect.right  = (LONG)_BaseWindow.Size().PosX();
    rect.bottom = (LONG)_BaseWindow.Size().PosY();

    if (!AdjustWindowRect(&rect, style, FALSE))
        throw LDL::Core::RuntimeError("AdjustWindowRect failed");

    _HWND = CreateWindow(AppName, "", style, (int)_BaseWindow.Pos().PosX(), (int)_BaseWindow.Pos().PosY(), rect.right - rect.left, rect.bottom - rect.top, 0, 0, _HINSTANCE, 0);

    if (_HWND == INVALID_HANDLE_VALUE)
        throw LDL::Core::RuntimeError("CreateWindow failed");

#ifdef _WIN64
    SetWindowLongPtr(_HWND, GWLP_WNDPROC, (LONG_PTR)WndProc);
    SetWindowLongPtr(_HWND, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    SetWindowLong(_HWND, GWL_WNDPROC, (LONG)WndProc);
    SetWindowLong(_HWND, GWL_USERDATA, (LONG)this);
#endif  

    _HDC = GetDC(_HWND);

    if (_HDC == INVALID_HANDLE_VALUE)
        throw LDL::Core::RuntimeError("GetDC failed");

    Title(title);
    ShowWindow(_HWND, SW_SHOW);
}

MainWindow::~MainWindow()
{
        UnregisterClass(AppName, _HINSTANCE);
        ReleaseDC(_HWND, _HDC);
        PostQuitMessage(0);
}

bool MainWindow::GetEvent(LDL::Events::Event& event)
{
    if (_Eventer.Empty())
    {
        while (PeekMessage(&_MSG, _HWND, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&_MSG);
            DispatchMessage(&_MSG);
        }
    }

    if (!_Eventer.Empty())
    {
        _Eventer.Pop(event);
    }

    return _Eventer.Running();
}

bool MainWindow::WaitEvent(LDL::Events::Event& event)
{
    BOOL result;

    if (_Eventer.Running())
    {
        result = GetMessage(&_MSG, _HWND, 0, 0);
        
        if (result == -1)
        {
            throw LDL::Core::RuntimeError("GetMessage failed");
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

const Point2u& MainWindow::Size()
{
    RECT rect;

    if (!GetClientRect(_HWND, &rect))
        throw LDL::Core::RuntimeError("GetClientRect failed");

    _BaseWindow.Size(Point2u(rect.right + Pos().PosX(), rect.bottom + Pos().PosY()));

    return _BaseWindow.Size();
}

const Point2u& MainWindow::Pos()
{
    return _BaseWindow.Pos();
}