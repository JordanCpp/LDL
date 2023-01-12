#include "WindowImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

WindowImpl::WindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode),
    _ContextImpl("opengl32")
{
    PIXELFORMATDESCRIPTOR pfd;

    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

    _Window._HDC = GetDC(_Window._HWND);

    if (_Window._HDC == NULL)
        throw LDL::Core::RuntimeError("GetDC failed");

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_Window._HDC, &pfd);

    if (format == 0)
        throw LDL::Core::RuntimeError("ChoosePixelFormat failed");

    if (!SetPixelFormat(_Window._HDC, format, &pfd))
        throw LDL::Core::RuntimeError("SetPixelFormat failed");

    _ContextImpl.Create(_Window._HDC);
}

WindowImpl::~WindowImpl()
{
    ReleaseDC(_Window._HWND, _Window._HDC);
}

void WindowImpl::Present()
{
    if (!SwapBuffers(_Window._HDC))
        throw LDL::Core::RuntimeError("SwapBuffers failed");
}

const Point2u& WindowImpl::Size()
{
    return _Window.Size();
}

const Point2u& WindowImpl::View()
{
    return _Window.View();
}

const Point2u& WindowImpl::Pos()
{
    return _Window.Pos();
}

bool WindowImpl::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImpl::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImpl::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImpl::Title()
{
    return _Window.Title();
}

void WindowImpl::Title(const std::string& title)
{
    _Window.Title(title);
}