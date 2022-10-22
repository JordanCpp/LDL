#include <LDL/Platforms/Windows/Graphics/Window.hpp>
#include <LDL/Core/RuntimeError.hpp>

const char AppName[] = "Lt::Graphics::Window";

LRESULT CALLBACK LDL::Graphics::Windows::Window::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
{
    LDL::Events::Event event;

    switch (Message)
    {
    case WM_PAINT:
        break;

    case WM_DESTROY:
        break;

    case WM_MOUSEMOVE:
        event.Type = Events::IsMouseMove;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONDOWN:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateDown;
        event.Mouse.Button = Events::Mouse::ButtonLeft;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_LBUTTONUP:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateUp;
        event.Mouse.Button = Events::Mouse::ButtonLeft;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONDOWN:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateDown;
        event.Mouse.Button = Events::Mouse::ButtonRight;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_RBUTTONUP:
        event.Type = Events::IsMouseClick;
        event.Mouse.State = Events::Mouse::StateUp;
        event.Mouse.Button = Events::Mouse::ButtonRight;
        event.Mouse.PosX = LOWORD(LParam);
        event.Mouse.PosY = HIWORD(LParam);
        _Eventer.Push(event);
        break;

    case WM_SIZE:
        break;

    case WM_CLOSE:
        event.Type = Events::IsQuit;
        _Eventer.Push(event);
        break;
    }

    return DefWindowProc(_HWND, Message, WParam, LParam);
}

LRESULT CALLBACK LDL::Graphics::Windows::Window::WndProc(HWND Hwnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result;

#ifdef _WIN64
    LDL::Graphics::Windows::Window* This = (LDL::Graphics::Windows::Window*)GetWindowLongPtr(Hwnd, GWLP_USERDATA);
#elif _WIN32
    LDL::Graphics::Windows::Window* This = (LDL::Graphics::Windows::Window*)GetWindowLong(Hwnd, GWL_USERDATA);
#endif  

    if (This != nullptr)
        result = This->Handler(Message, WParam, LParam);
    else
        result = DefWindowProc(Hwnd, Message, WParam, LParam);

    return result;
}

LDL::Graphics::Windows::Window::Window(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title) :
    _BaseWindow(pos, size, title)
{
    ZeroMemory(&_WNDCLASS, sizeof(WNDCLASS));
    ZeroMemory(&_MSG, sizeof(MSG));

    _WNDCLASS.hInstance = _HINSTANCE;
    _WNDCLASS.lpszClassName = AppName;
    _WNDCLASS.lpfnWndProc = WndProc;
    _WNDCLASS.style = CS_HREDRAW | CS_VREDRAW;
    _WNDCLASS.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    _WNDCLASS.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    _WNDCLASS.hCursor = LoadCursor(NULL, IDC_ARROW);

    _ATOM = RegisterClass(&_WNDCLASS);

    if (_ATOM == INVALID_ATOM)
        throw LDL::Core::RuntimeError("ATOM == INVALID_ATOM");

    _HWND = CreateWindow(AppName, "", WS_OVERLAPPEDWINDOW, (int)_BaseWindow.Pos().PosX(), (int)_BaseWindow.Pos().PosY(), (int)_BaseWindow.Size().PosX(), (int)_BaseWindow.Size().PosY(), 0, 0, _HINSTANCE, 0);

    if (_HWND == INVALID_HANDLE_VALUE)
        throw LDL::Core::RuntimeError("HWND == INVALID_HANDLE_VALUE");

#ifdef _WIN64
    SetWindowLongPtr(_HWND, GWLP_WNDPROC, (LONG_PTR)WndProc);
    SetWindowLongPtr(_HWND, GWLP_USERDATA, (LONG_PTR)this);
#elif _WIN32
    SetWindowLong(_HWND, GWL_WNDPROC, (LONG)WndProc);
    SetWindowLong(_HWND, GWL_USERDATA, (LONG)this);
#endif  

    _HDC = GetDC(_HWND);

    if (_HDC == INVALID_HANDLE_VALUE)
        throw LDL::Core::RuntimeError("HDC == INVALID_HANDLE_VALUE");

    Title(title);
    ShowWindow(_HWND, SW_SHOW);
}

LDL::Graphics::Windows::Window::~Window()
{
        UnregisterClass(AppName, _HINSTANCE);
        ReleaseDC(_HWND, _HDC);
        PostQuitMessage(0);
}

bool LDL::Graphics::Windows::Window::GetEvent(LDL::Events::Event& event)
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

bool LDL::Graphics::Windows::Window::WaitEvent(LDL::Events::Event& event)
{
    BOOL result;

    if (_Eventer.Running())
    {
        if ((result = GetMessage(&_MSG, _HWND, NULL, NULL)) != 0)
        {
            if (result == -1)
                throw LDL::Core::RuntimeError("((result = GetMessage(&_MSG, _HWND, NULL, NULL)) != 0)");

            _Eventer.Pop(event);

            TranslateMessage(&_MSG);
            DispatchMessage(&_MSG);
        }
    }

    return _Eventer.Running();
}

void LDL::Graphics::Windows::Window::StopEvent()
{
    _Eventer.Stop();
}

void LDL::Graphics::Windows::Window::Title(const std::string& title)
{
    _BaseWindow.Title(title);

    SetWindowText(_HWND, _BaseWindow.Title().c_str());
}

const std::string& LDL::Graphics::Windows::Window::Title()
{
    return _BaseWindow.Title();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::Window::Size()
{
    return _BaseWindow.Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::Window::Pos()
{
    return _BaseWindow.Pos();
}