#include "WindowImplOpenGL3.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Events;
using namespace LDL::Graphics;

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
    LDL_ASSERT_DETAIL(_Window._HDC != NULL, "GetDC failed");


    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;

    int format = ChoosePixelFormat(_Window._HDC, &pfd);
    LDL_ASSERT_DETAIL(format != 0, "ChoosePixelFormat failed");

    bool result = SetPixelFormat(_Window._HDC, format, &pfd);
    LDL_ASSERT_DETAIL(result, "SetPixelFormat failed");

    _HGLRC = wglCreateContext(_Window._HDC);
    LDL_ASSERT_DETAIL(_HGLRC != NULL, "wglCreateContext failed");

    result = wglMakeCurrent(_Window._HDC, _HGLRC);
    LDL_ASSERT_DETAIL(result, "wglMakeCurrent failed");

    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    LDL_ASSERT_DETAIL(wglCreateContextAttribsARB != NULL, "wglGetProcAddress failed");

    result = wglMakeCurrent(NULL, NULL);
    LDL_ASSERT_DETAIL(result, "wglMakeCurrent failed");

    result = wglDeleteContext(_HGLRC);
    LDL_ASSERT_DETAIL(result, "wglDeleteContext failed");

    _HGLRC = wglCreateContextAttribsARB(_Window._HDC, 0, attribs);
    LDL_ASSERT_DETAIL(_HGLRC != NULL, "wglCreateContextAttribsARB failed");

    result = wglMakeCurrent(_Window._HDC, _HGLRC);
    LDL_ASSERT_DETAIL(result, "wglMakeCurrent failed");

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
    BOOL result = SwapBuffers(_Window._HDC);
    LDL_ASSERT_DETAIL(result, "SwapBuffers failed");
}

const Vec2u& WindowImplOpenGL3::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplOpenGL3::Pos()
{
    return _Window.Pos();
}

bool WindowImplOpenGL3::GetEvent(Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplOpenGL3::WaitEvent(Event& event)
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

void* WindowImplOpenGL3::NativeHandle()
{
    return _Window._HWND;
}
