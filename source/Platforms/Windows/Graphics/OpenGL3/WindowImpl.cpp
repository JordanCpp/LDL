#include "WindowImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);

#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092  
#define WGL_CONTEXT_FLAGS_ARB                     0x2094 
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126  
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB    0x00000002 
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002


WindowImpl::WindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode),
    _HGLRC(NULL),
    _OpenGLLoader(3, 3)
{
    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;

    int attribs[] =
    {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
        WGL_CONTEXT_MINOR_VERSION_ARB, 3,
        WGL_CONTEXT_FLAGS_ARB,         WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
        WGL_CONTEXT_PROFILE_MASK_ARB,  WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        0
    };

    PIXELFORMATDESCRIPTOR pfd;

    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

    _Window._HDC = GetDC(_Window._HWND);

    if (_Window._HDC == NULL)
        throw LDL::Core::RuntimeError("GetDC failed");

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;

    int format = ChoosePixelFormat(_Window._HDC, &pfd);

    if (format == 0)
        throw LDL::Core::RuntimeError("ChoosePixelFormat failed");

    if (!SetPixelFormat(_Window._HDC, format, &pfd))
        throw LDL::Core::RuntimeError("SetPixelFormat failed");

    _HGLRC = wglCreateContext(_Window._HDC);

    if (!_HGLRC)
        throw LDL::Core::RuntimeError("wglCreateContext failed");

    if (!wglMakeCurrent(_Window._HDC, _HGLRC))
        throw LDL::Core::RuntimeError("wglMakeCurrent failed");

    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");

    if (!wglCreateContextAttribsARB)
        throw LDL::Core::RuntimeError("wglGetProcAddress failed");

    if (!wglMakeCurrent(NULL, NULL))
        throw LDL::Core::RuntimeError("wglMakeCurrent failed");

    if (!wglDeleteContext(_HGLRC))
        throw LDL::Core::RuntimeError("wglDeleteContext failed");

    _HGLRC = wglCreateContextAttribsARB(_Window._HDC, 0, attribs);

    if (!_HGLRC)
        throw LDL::Core::RuntimeError("wglCreateContextAttribsARB failed");

    if (!wglMakeCurrent(_Window._HDC, _HGLRC))
        throw LDL::Core::RuntimeError("wglMakeCurrent failed");

    _OpenGLLoader.Init();
}

WindowImpl::~WindowImpl()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);

    ReleaseDC(_Window._HWND, _Window._HDC);
}

void WindowImpl::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    if (!SwapBuffers(_Window._HDC))
        throw LDL::Core::RuntimeError("SwapBuffers failed");
}

const Point2u& WindowImpl::Size()
{
    return _Window.Size();
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

HWND WindowImpl::Hwnd()
{
    return _Window._HWND;
}