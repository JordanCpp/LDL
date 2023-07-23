#include "WindowImplOpenGL1.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplOpenGL1::WindowImplOpenGL1(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _HGLRC(NULL),
    _Window(pos, size, title, mode)
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

    _HGLRC = wglCreateContext(_Window._HDC);

    if (_HGLRC == NULL)
        throw LDL::Core::RuntimeError("wglCreateContext failed");

    if (!wglMakeCurrent(_Window._HDC, _HGLRC))
        throw LDL::Core::RuntimeError("wglMakeCurrent failed");

    _OpenGLLoader.Init(1, 1);
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);

    ReleaseDC(_Window._HWND, _Window._HDC);
}

bool WindowImplOpenGL1::Running()
{
    return _Window.Running();
}

void WindowImplOpenGL1::Present()
{
    if (!SwapBuffers(_Window._HDC))
        throw LDL::Core::RuntimeError("SwapBuffers failed");
}

void WindowImplOpenGL1::PollEvents()
{
    _Window.PollEvents();
}

const Vec2u& WindowImplOpenGL1::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplOpenGL1::Pos()
{
    return _Window.Pos();
}

bool WindowImplOpenGL1::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplOpenGL1::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplOpenGL1::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplOpenGL1::Title()
{
    return _Window.Title();
}

void WindowImplOpenGL1::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND WindowImplOpenGL1::Hwnd()
{
    return _Window._HWND;
}
