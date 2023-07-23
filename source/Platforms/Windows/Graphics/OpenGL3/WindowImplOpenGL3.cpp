#include "WindowImplOpenGL3.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

typedef HGLRC(WINAPI* PFNWGLCREATECONTEXT)(HDC);
typedef BOOL (WINAPI* PFNWGLMAKECURRENT  )(HDC, HGLRC);
typedef BOOL (WINAPI* PFNWGLDELETECONTEXT)(HGLRC);

typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);

#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092  
#define WGL_CONTEXT_FLAGS_ARB                     0x2094 
#define WGL_CONTEXT_PROFILE_MASK_ARB              0x9126  
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB    0x00000002 
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002


WindowImplOpenGL3::WindowImplOpenGL3(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode),
    _HGLRC(NULL)
{
    PFNWGLCREATECONTEXT wglCreateContext = NULL;
    PFNWGLMAKECURRENT   wglMakeCurrent   = NULL;
    PFNWGLDELETECONTEXT wglDeleteContext = NULL;

    wglCreateContext = (PFNWGLCREATECONTEXT)wglGetProcAddress("wglCreateContext");
    wglMakeCurrent   = (PFNWGLMAKECURRENT  )wglGetProcAddress("wglMakeCurrent");
    wglDeleteContext = (PFNWGLDELETECONTEXT)wglGetProcAddress("wglDeleteContext");

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

    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
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

    _OpenGLLoader.Init(3, 3);
}

WindowImplOpenGL3::~WindowImplOpenGL3()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);

    ReleaseDC(_Window._HWND, _Window._HDC);
}

bool WindowImplOpenGL3::Running()
{
    return _Window.Running();
}

void WindowImplOpenGL3::PollEvents()
{
    _Window.PollEvents();
}

void WindowImplOpenGL3::Present()
{
    if (!SwapBuffers(_Window._HDC))
        throw LDL::Core::RuntimeError("SwapBuffers failed");
}

const Vec2u& WindowImplOpenGL3::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplOpenGL3::Pos()
{
    return _Window.Pos();
}

bool WindowImplOpenGL3::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplOpenGL3::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplOpenGL3::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplOpenGL3::Title()
{
    return _Window.Title();
}

void WindowImplOpenGL3::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND WindowImplOpenGL3::Hwnd()
{
    return _Window._HWND;
}
