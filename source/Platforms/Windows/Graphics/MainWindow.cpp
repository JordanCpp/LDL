#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

static const char AppName[] = "MainWindow";

size_t LDL::Graphics::Windows::MainWindow::ConvertKey(size_t key)
{
    size_t result = 0;

    switch (key)
    {
    case VK_ESCAPE:
        result = LDL::Enums::KeyboardKey::Escape;
        break;

    case 'A':
        result = LDL::Enums::KeyboardKey::A;
        break;

    case 'B':
        result = LDL::Enums::KeyboardKey::B;
        break;

    case'C':
        result = LDL::Enums::KeyboardKey::C;
        break;

    case 'D':
        result = LDL::Enums::KeyboardKey::D;
        break;

    case 'E':
        result = LDL::Enums::KeyboardKey::E;
        break;

    case 'F':
        result = LDL::Enums::KeyboardKey::F;
        break;

    case 'G':
        result = LDL::Enums::KeyboardKey::G;
        break;

    case 'H':
        result = LDL::Enums::KeyboardKey::H;
        break;

    case 'I':
        result = LDL::Enums::KeyboardKey::I;
        break;

    case 'J':
        result = LDL::Enums::KeyboardKey::J;
        break;

    case 'K':
        result = LDL::Enums::KeyboardKey::K;
        break;

    case 'L':
        result = LDL::Enums::KeyboardKey::L;
        break;

    case 'M':
        result = LDL::Enums::KeyboardKey::M;
        break;

    case 'N':
        result = LDL::Enums::KeyboardKey::N;
        break;

    case 'O':
        result = LDL::Enums::KeyboardKey::O;
        break;

    case 'P':
        result = LDL::Enums::KeyboardKey::P;
        break;

    case 'Q':
        result = LDL::Enums::KeyboardKey::Q;
        break;

    case 'R':
        result = LDL::Enums::KeyboardKey::R;
        break;

    case 'S':
        result = LDL::Enums::KeyboardKey::S;
        break;

    case 'T':
        result = LDL::Enums::KeyboardKey::T;
        break;

    case 'U':
        result = LDL::Enums::KeyboardKey::U;
        break;

    case 'V':
        result = LDL::Enums::KeyboardKey::V;
        break;

    case 'W':
        result = LDL::Enums::KeyboardKey::W;
        break;

    case 'X':
        result = LDL::Enums::KeyboardKey::X;
        break;

    case 'Y':
        result = LDL::Enums::KeyboardKey::Y;
        break;

    case 'Z':
        result = LDL::Enums::KeyboardKey::Z;
        break;
    }

    return result;
}

LRESULT CALLBACK LDL::Graphics::Windows::MainWindow::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
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

    case WM_SIZE:
        event.Type          = Events::IsResize;
        event.Resize.Width  = LOWORD(LParam);
        event.Resize.Height = HIWORD(LParam);
        break;

    case WM_CLOSE:
        event.Type = Events::IsQuit;
        _Eventer.Push(event);
        break;

    case WM_KEYDOWN:
        event.Type = LDL::Events::IsKeyboard;
        event.Keyboard.State = LDL::Enums::ButtonState::Pressed;
        event.Keyboard.Key = ConvertKey(WParam);
        break;

    case WM_KEYUP:
        event.Type = LDL::Events::IsKeyboard;
        event.Keyboard.State = LDL::Enums::ButtonState::Released;
        event.Keyboard.Key = ConvertKey(WParam);
        break;
    }

    return DefWindowProc(_HWND, Message, WParam, LParam);
}

LRESULT CALLBACK LDL::Graphics::Windows::MainWindow::WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result;

#ifdef _WIN64
    LDL::Graphics::Windows::MainWindow* This = (LDL::Graphics::Windows::MainWindow*)GetWindowLongPtr(Hwnd, GWLP_USERDATA);
#elif _WIN32
    LDL::Graphics::Windows::MainWindow* This = (LDL::Graphics::Windows::MainWindow*)GetWindowLong(Hwnd, GWL_USERDATA);
#endif  

    if (This != NULL)
        result = This->Handler(Message, WParam, LParam);
    else
        result = DefWindowProc(Hwnd, Message, WParam, LParam);

    return result;
}

LDL::Graphics::Windows::MainWindow::MainWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, LDL::Enums::WindowMode mode) :
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

    _HWND = CreateWindow(AppName, "", style, (int)_BaseWindow.Pos().PosX(), (int)_BaseWindow.Pos().PosY(), (int)_BaseWindow.Size().PosX(), (int)_BaseWindow.Size().PosY(), 0, 0, _HINSTANCE, 0);

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

LDL::Graphics::Windows::MainWindow::~MainWindow()
{
        UnregisterClass(AppName, _HINSTANCE);
        ReleaseDC(_HWND, _HDC);
        PostQuitMessage(0);
}

bool LDL::Graphics::Windows::MainWindow::GetEvent(LDL::Events::Event& event)
{
    if (_Eventer.Running())
    {
        if (PeekMessage(&_MSG, _HWND, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&_MSG);
            DispatchMessage(&_MSG);

            _Eventer.Pop(event);
        }
    }

    return _Eventer.Running();
}

bool LDL::Graphics::Windows::MainWindow::WaitEvent(LDL::Events::Event& event)
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

void LDL::Graphics::Windows::MainWindow::StopEvent()
{
    _Eventer.Stop();
}

void LDL::Graphics::Windows::MainWindow::Title(const std::string& title)
{
    _BaseWindow.Title(title);

    SetWindowText(_HWND, _BaseWindow.Title().c_str());
}

const std::string& LDL::Graphics::Windows::MainWindow::Title()
{
    return _BaseWindow.Title();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::MainWindow::Size()
{
    return _BaseWindow.Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::MainWindow::Pos()
{
    return _BaseWindow.Pos();
}