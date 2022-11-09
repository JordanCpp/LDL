#include <LDL/Platforms/Windows/Graphics/MainWindow.hpp>
#include <LDL/Core/RuntimeError.hpp>

static const char AppName[] = "MainWindow";

LRESULT CALLBACK LDL::Graphics::Windows::MainWindow::Handler(UINT Message, WPARAM WParam, LPARAM LParam)
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

LDL::Graphics::Windows::MainWindow::MainWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title) :
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

    _HWND = CreateWindow(AppName, "", WS_OVERLAPPEDWINDOW, (int)_BaseWindow.Pos().PosX(), (int)_BaseWindow.Pos().PosY(), (int)_BaseWindow.Size().PosX(), (int)_BaseWindow.Size().PosY(), 0, 0, _HINSTANCE, 0);

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