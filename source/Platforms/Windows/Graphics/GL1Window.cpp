#include <LDL/Platforms/Windows/Graphics/GL1Window.hpp>
#include <LDL/Core/RuntimeError.hpp>

LDL::Graphics::Windows::GL1Window::GL1Window(const Point2u& pos, const Point2u& size, const std::string& title) :
    _Window(pos, size, title)
{
    PIXELFORMATDESCRIPTOR pfd = { 0 };

    int format = 0;

    _Window._HDC = GetDC(_Window._HWND);

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    format = ChoosePixelFormat(_Window._HDC, &pfd);

    if (format == 0)
        throw LDL::Core::RuntimeError("ChoosePixelFormat");

    SetPixelFormat(_Window._HDC, format, &pfd);
    _HGLRC = wglCreateContext(_Window._HDC);
    wglMakeCurrent(_Window._HDC, _HGLRC);
}

LDL::Graphics::Windows::GL1Window::~GL1Window()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);
    ReleaseDC(_Window._HWND, _Window._HDC);
}

void LDL::Graphics::Windows::GL1Window::Present()
{
    SwapBuffers(_Window._HDC);
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::GL1Window::Size()
{
    return _Window.Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::GL1Window::Pos()
{
    return _Window.Pos();
}

bool LDL::Graphics::Windows::GL1Window::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool LDL::Graphics::Windows::GL1Window::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void LDL::Graphics::Windows::GL1Window::StopEvent()
{
    _Window.StopEvent();
}

const std::string& LDL::Graphics::Windows::GL1Window::Title()
{
    return _Window.Title();
}

void LDL::Graphics::Windows::GL1Window::Title(const std::string& title)
{
    _Window.Title(title);
}