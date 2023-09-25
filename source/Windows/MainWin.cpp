#include "MainWin.hpp"
#include <LDL/Low/Enums.hpp>
#include <LDL/Low/Errors.hpp>

static const char AppName[] = "MainWindow";

LDL_MainWinow::LDL_MainWinow(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
    _BaseWindow(pos, size, title)
{
    ClearStruct();

    if (InitHinstance())
    {
        if (InitWndClass())
        {
            if (InitHwnd(mode))
            {
                if (InitPointer())
                {
                    if (InitHdc())
                    {
                        //Title(title);
                        ShowWindow(_HWND, SW_SHOW);
                    }
                }

            }
        }
    }
}

LDL_MainWinow::~LDL_MainWinow()
{
    UnregisterClass(AppName, _HINSTANCE);
    ReleaseDC(_HWND, _HDC);
    PostQuitMessage(0);
}

bool LDL_MainWinow::Running()
{
    return _Eventer.Running();
}

void LDL_MainWinow::PollEvents()
{
    while (PeekMessage(&_MSG, _HWND, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&_MSG);
        DispatchMessage(&_MSG);
    }
}

bool LDL_MainWinow::GetEvent(LDL_Event& event)
{
    if (!_Eventer.Empty())
    {
        _Eventer.Pop(event);

        return true;
    }

    return false;
}

bool LDL_MainWinow::WaitEvent(LDL_Event& event)
{
    if (_Eventer.Running())
    {
        GetMessage(&_MSG, _HWND, 0, 0);

        _Eventer.Pop(event);

        TranslateMessage(&_MSG);
        DispatchMessage(&_MSG);
    }

    return _Eventer.Running();
}

void LDL_MainWinow::StopEvent()
{
    _Eventer.Stop();
}

void LDL_MainWinow::Title(const char* title)
{
    _BaseWindow.Title(title);

    SetWindowText(_HWND, _BaseWindow.Title());
}

const char* LDL_MainWinow::Title()
{
    return _BaseWindow.Title();
}

const LDL_Point2u& LDL_MainWinow::Size()
{
    return _BaseWindow.Size();
}

const LDL_Point2u& LDL_MainWinow::Pos()
{
    return _BaseWindow.Pos();
}

void LDL_MainWinow::ClearStruct()
{
    ZeroMemory(&_WNDCLASS, sizeof(WNDCLASS));
    ZeroMemory(&_HINSTANCE, sizeof(HINSTANCE));
    ZeroMemory(&_MSG, sizeof(MSG));
    ZeroMemory(&_ATOM, sizeof(ATOM));
    ZeroMemory(&_HWND, sizeof(HWND));
    ZeroMemory(&_HDC, sizeof(HDC));
}

bool LDL_MainWinow::InitHinstance()
{
    _HINSTANCE = GetModuleHandle(NULL);

    if (_HINSTANCE == NULL)
    {
        LDL_AddError("GetModuleHandle failed");

        return false;
    }

    return true;
}

bool LDL_MainWinow::InitWndClass()
{
    _WNDCLASS.hInstance = _HINSTANCE;
    _WNDCLASS.lpszClassName = AppName;
    _WNDCLASS.lpfnWndProc = WndProc;
    _WNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    _WNDCLASS.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _WNDCLASS.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    _WNDCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);

    _ATOM = RegisterClass(&_WNDCLASS);

    if (_ATOM == INVALID_ATOM)
    {
        LDL_AddError("RegisterClass failed");

        return true;
    }

    return true;
}

bool LDL_MainWinow::InitHwnd(size_t mode)
{
    DWORD style = 0;

    if (mode == LDL_WindowMode::Fixed)
        style = WS_OVERLAPPED | WS_SYSMENU;
    else if (mode == LDL_WindowMode::Resized)
        style = WS_OVERLAPPEDWINDOW;

    RECT rect;

    rect.left = (LONG)_BaseWindow.Pos().x;
    rect.top = (LONG)_BaseWindow.Pos().y;
    rect.right = (LONG)_BaseWindow.Size().x;
    rect.bottom = (LONG)_BaseWindow.Size().y;

    if (!AdjustWindowRect(&rect, style, FALSE))
    {
        LDL_AddError("AdjustWindowRect failed");

        return false;
    }
    else
    {
        _HWND = CreateWindow(AppName, "", style, (int)_BaseWindow.Pos().x, (int)_BaseWindow.Pos().y, rect.right - rect.left, rect.bottom - rect.top, 0, 0, _HINSTANCE, 0);

        if (_HWND == INVALID_HANDLE_VALUE)
        {
            LDL_AddError("CreateWindow failed");

            return false;
        }
    }

    return true;
}

bool LDL_MainWinow::InitPointer()
{
#ifdef _WIN64
    SetWindowLongPtr(_HWND, GWLP_WNDPROC, (LONG_PTR)WndProc);
    SetWindowLongPtr(_HWND, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    SetWindowLong(_HWND, GWL_WNDPROC, (LONG)WndProc);
    SetWindowLong(_HWND, GWL_USERDATA, (LONG)this);
#endif  

    return true;
}

bool LDL_MainWinow::InitHdc()
{
    _HDC = GetDC(_HWND);

    if (_HDC == INVALID_HANDLE_VALUE)
    {
        LDL_AddError("GetDC failed");

        return false;
    }

    return true;
}

size_t LDL_MainWinow::ConvertKey(size_t key)
{
    switch (key)
    {
    case VK_LWIN:       return LDL_KeyboardKey::LSystem;
    case VK_RWIN:       return LDL_KeyboardKey::RSystem;
    case VK_APPS:       return LDL_KeyboardKey::Menu;
    case VK_OEM_1:      return LDL_KeyboardKey::Semicolon;
    case VK_OEM_2:      return LDL_KeyboardKey::Slash;
    case VK_OEM_PLUS:   return LDL_KeyboardKey::Equal;
    case VK_OEM_MINUS:  return LDL_KeyboardKey::Hyphen;
    case VK_OEM_4:      return LDL_KeyboardKey::LBracket;
    case VK_OEM_6:      return LDL_KeyboardKey::RBracket;
    case VK_OEM_COMMA:  return LDL_KeyboardKey::Comma;
    case VK_OEM_PERIOD: return LDL_KeyboardKey::Period;
    case VK_OEM_7:      return LDL_KeyboardKey::Quote;
    case VK_OEM_5:      return LDL_KeyboardKey::Backslash;
    case VK_OEM_3:      return LDL_KeyboardKey::Tilde;
    case VK_ESCAPE:     return LDL_KeyboardKey::Escape;
    case VK_SPACE:      return LDL_KeyboardKey::Space;
    case VK_RETURN:     return LDL_KeyboardKey::Enter;
    case VK_BACK:       return LDL_KeyboardKey::Backspace;
    case VK_TAB:        return LDL_KeyboardKey::Tab;
    case VK_PRIOR:      return LDL_KeyboardKey::PageUp;
    case VK_NEXT:       return LDL_KeyboardKey::PageDown;
    case VK_END:        return LDL_KeyboardKey::End;
    case VK_HOME:       return LDL_KeyboardKey::Home;
    case VK_INSERT:     return LDL_KeyboardKey::Insert;
    case VK_DELETE:     return LDL_KeyboardKey::Delete;
    case VK_ADD:        return LDL_KeyboardKey::Add;
    case VK_SUBTRACT:   return LDL_KeyboardKey::Subtract;
    case VK_MULTIPLY:   return LDL_KeyboardKey::Multiply;
    case VK_DIVIDE:     return LDL_KeyboardKey::Divide;
    case VK_PAUSE:      return LDL_KeyboardKey::Pause;
    case VK_F1:         return LDL_KeyboardKey::F1;
    case VK_F2:         return LDL_KeyboardKey::F2;
    case VK_F3:         return LDL_KeyboardKey::F3;
    case VK_F4:         return LDL_KeyboardKey::F4;
    case VK_F5:         return LDL_KeyboardKey::F5;
    case VK_F6:         return LDL_KeyboardKey::F6;
    case VK_F7:         return LDL_KeyboardKey::F7;
    case VK_F8:         return LDL_KeyboardKey::F8;
    case VK_F9:         return LDL_KeyboardKey::F9;
    case VK_F10:        return LDL_KeyboardKey::F10;
    case VK_F11:        return LDL_KeyboardKey::F11;
    case VK_F12:        return LDL_KeyboardKey::F12;
    case VK_F13:        return LDL_KeyboardKey::F13;
    case VK_F14:        return LDL_KeyboardKey::F14;
    case VK_F15:        return LDL_KeyboardKey::F15;
    case VK_LEFT:       return LDL_KeyboardKey::Left;
    case VK_RIGHT:      return LDL_KeyboardKey::Right;
    case VK_UP:         return LDL_KeyboardKey::Up;
    case VK_DOWN:       return LDL_KeyboardKey::Down;
    case VK_NUMPAD0:    return LDL_KeyboardKey::Numpad0;
    case VK_NUMPAD1:    return LDL_KeyboardKey::Numpad1;
    case VK_NUMPAD2:    return LDL_KeyboardKey::Numpad2;
    case VK_NUMPAD3:    return LDL_KeyboardKey::Numpad3;
    case VK_NUMPAD4:    return LDL_KeyboardKey::Numpad4;
    case VK_NUMPAD5:    return LDL_KeyboardKey::Numpad5;
    case VK_NUMPAD6:    return LDL_KeyboardKey::Numpad6;
    case VK_NUMPAD7:    return LDL_KeyboardKey::Numpad7;
    case VK_NUMPAD8:    return LDL_KeyboardKey::Numpad8;
    case VK_NUMPAD9:    return LDL_KeyboardKey::Numpad9;
    case 'A':           return LDL_KeyboardKey::A;
    case 'Z':           return LDL_KeyboardKey::Z;
    case 'E':           return LDL_KeyboardKey::E;
    case 'R':           return LDL_KeyboardKey::R;
    case 'T':           return LDL_KeyboardKey::T;
    case 'Y':           return LDL_KeyboardKey::Y;
    case 'U':           return LDL_KeyboardKey::U;
    case 'I':           return LDL_KeyboardKey::I;
    case 'O':           return LDL_KeyboardKey::O;
    case 'P':           return LDL_KeyboardKey::P;
    case 'Q':           return LDL_KeyboardKey::Q;
    case 'S':           return LDL_KeyboardKey::S;
    case 'D':           return LDL_KeyboardKey::D;
    case 'F':           return LDL_KeyboardKey::F;
    case 'G':           return LDL_KeyboardKey::G;
    case 'H':           return LDL_KeyboardKey::H;
    case 'J':           return LDL_KeyboardKey::J;
    case 'K':           return LDL_KeyboardKey::K;
    case 'L':           return LDL_KeyboardKey::L;
    case 'M':           return LDL_KeyboardKey::M;
    case 'W':           return LDL_KeyboardKey::W;
    case 'X':           return LDL_KeyboardKey::X;
    case 'C':           return LDL_KeyboardKey::C;
    case 'V':           return LDL_KeyboardKey::V;
    case 'B':           return LDL_KeyboardKey::B;
    case 'N':           return LDL_KeyboardKey::N;
    case '0':           return LDL_KeyboardKey::Num0;
    case '1':           return LDL_KeyboardKey::Num1;
    case '2':           return LDL_KeyboardKey::Num2;
    case '3':           return LDL_KeyboardKey::Num3;
    case '4':           return LDL_KeyboardKey::Num4;
    case '5':           return LDL_KeyboardKey::Num5;
    case '6':           return LDL_KeyboardKey::Num6;
    case '7':           return LDL_KeyboardKey::Num7;
    case '8':           return LDL_KeyboardKey::Num8;
    case '9':           return LDL_KeyboardKey::Num9;
    case VK_LSHIFT:     return LDL_KeyboardKey::Leftshift;
    case VK_RSHIFT:     return LDL_KeyboardKey::RightShift;
    case VK_LCONTROL:   return LDL_KeyboardKey::LeftControl;
    case VK_RCONTROL:   return LDL_KeyboardKey::RightControl;
    }

    return LDL_KeyboardKey::Unknown;
}

LRESULT CALLBACK LDL_MainWinow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result;

#ifdef _WIN64
    LDL_MainWinow* This = (LDL_MainWinow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
#elif _WIN32
    LDL_MainWinow* This = (LDL_MainWinow*)GetWindowLong(hwnd, GWL_USERDATA);
#endif  

    if (This != NULL)
        result = This->Handler(message, wParam, lParam);
    else
        result = DefWindowProc(hwnd, message, wParam, lParam);

    return result;
}

LRESULT CALLBACK LDL_MainWinow::Handler(UINT message, WPARAM wParam, LPARAM lParam)
{
    LDL_Event event;

    ZeroMemory(&event, sizeof(event));

    switch (message)
    {
    case WM_PAINT:
        break;

    case WM_DESTROY:
        break;

    case WM_MOUSEMOVE:
        event.Type = LDL_Events::IsMouseMove;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type = LDL_Events::IsMouseClick;
        event.Mouse.State = LDL_ButtonState::Pressed;
        event.Mouse.Button = LDL_MouseButton::Left;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type = LDL_Events::IsMouseClick;
        event.Mouse.State = LDL_ButtonState::Released;
        event.Mouse.Button = LDL_MouseButton::Left;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type = LDL_Events::IsMouseClick;
        event.Mouse.State = LDL_ButtonState::Pressed;
        event.Mouse.Button = LDL_MouseButton::Right;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type = LDL_Events::IsMouseClick;
        event.Mouse.State = LDL_ButtonState::Released;
        event.Mouse.Button = LDL_MouseButton::Right;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_MBUTTONDOWN:
        event.Type = LDL_Events::IsMouseClick;
        event.Mouse.State = LDL_ButtonState::Pressed;
        event.Mouse.Button = LDL_MouseButton::Middle;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_MBUTTONUP:
        event.Type = LDL_Events::IsMouseClick;
        event.Mouse.State = LDL_ButtonState::Released;
        event.Mouse.Button = LDL_MouseButton::Middle;
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_SIZE:
        event.Type = LDL_Events::IsResize;
        event.Resize.Width = LOWORD(lParam);
        event.Resize.Height = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_CLOSE:
        event.Type = LDL_Events::IsQuit;
        _Eventer.Push(event);
        break;

    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        event.Type = LDL_Events::IsKeyboard;
        event.Keyboard.State = LDL_ButtonState::Pressed;
        event.Keyboard.Key = ConvertKey(wParam);
        _Eventer.Push(event);
        break;

    case WM_KEYUP:
    case WM_SYSKEYUP:
        event.Type = LDL_Events::IsKeyboard;
        event.Keyboard.State = LDL_ButtonState::Released;
        event.Keyboard.Key = ConvertKey(wParam);
        _Eventer.Push(event);
        break;

    case WM_SETFOCUS:
        event.Type = LDL_Events::IsGainedFocus;
        _Eventer.Push(event);
        break;

    case WM_KILLFOCUS:
        event.Type = LDL_Events::IsLostFocus;
        _Eventer.Push(event);
        break;

    case WM_MOUSEWHEEL:
        event.Type = LDL_Events::IsMouseScroll;
        event.Mouse.Scroll = LDL_MouseScroll::Vertical;
        event.Mouse.Delta = HIWORD(wParam);
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;

    case WM_MOUSEHWHEEL:
        event.Type = LDL_Events::IsMouseScroll;
        event.Mouse.Scroll = LDL_MouseScroll::Vertical;
        event.Mouse.Delta = HIWORD(wParam);
        event.Mouse.PosX = LOWORD(lParam);
        event.Mouse.PosY = HIWORD(lParam);
        _Eventer.Push(event);
        break;
    }

	return DefWindowProc(_HWND, message, wParam, lParam);
}
