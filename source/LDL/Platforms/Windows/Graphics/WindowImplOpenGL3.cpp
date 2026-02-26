// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL3.hpp>

using namespace LDL;

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

WindowImplOpenGL3::WindowImplOpenGL3(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _result(result),
    _mainWindow(_result,pos, size, title, mode),
    _context(NULL)
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

    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    _mainWindow._hdc = GetDC(_mainWindow._hwnd);

    if (_mainWindow._hdc == NULL)
    {
        _result.Message("GetDC failed");
    }

    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;

    int format = ChoosePixelFormat(_mainWindow._hdc, &pfd);
    if (format == 0)
    {
        _result.Message("ChoosePixelFormat failed");
    }

    if (!SetPixelFormat(_mainWindow._hdc, format, &pfd))
    {
        _result.Message("SetPixelFormat failed");
    }

    _context = wglCreateContext(_mainWindow._hdc);
    if (_context == NULL) _result.Message("wglCreateContext failed");

    if (!wglMakeCurrent(_mainWindow._hdc, _context))
    {
        _result.Message("wglMakeCurrent failed");
    }

    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    if (wglCreateContextAttribsARB == NULL)
    {
        _result.Message("wglGetProcAddress failed");
    }

    if (!wglMakeCurrent(NULL, NULL))
    {
        _result.Message("wglMakeCurrent failed");
    }

    if (!wglDeleteContext(_context))
    {
        _result.Message("wglDeleteContext failed");
    }

    _context = wglCreateContextAttribsARB(_mainWindow._hdc, 0, attribs);
    if (_context == NULL)
    {
        _result.Message("wglCreateContextAttribsARB failed");
    }

    if (!wglMakeCurrent(_mainWindow._hdc, _context))
    {
        _result.Message("wglMakeCurrent failed");
    }

    _loader.Init(3, 3);
}

WindowImplOpenGL3::~WindowImplOpenGL3()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_context);

    ReleaseDC(_mainWindow._hwnd, _mainWindow._hdc);
}

bool WindowImplOpenGL3::Running()
{
    return _mainWindow.Running();
}

void WindowImplOpenGL3::PollEvents()
{
    _mainWindow.PollEvents();
}

void WindowImplOpenGL3::Present()
{
    BOOL result = SwapBuffers(_mainWindow._hdc);
    LDL_ASSERT_DETAIL(result, "SwapBuffers failed");
}

const Vec2u& WindowImplOpenGL3::Size()
{
    return _mainWindow.Size();
}

const Vec2u& WindowImplOpenGL3::Pos()
{
    return _mainWindow.Pos();
}

bool WindowImplOpenGL3::GetEvent(Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool WindowImplOpenGL3::WaitEvent(Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void WindowImplOpenGL3::StopEvent()
{
    _mainWindow.StopEvent();
}

const std::string& WindowImplOpenGL3::Title()
{
    return _mainWindow.Title();
}

void WindowImplOpenGL3::Title(const std::string& title)
{
    _mainWindow.Title(title);
}

void* WindowImplOpenGL3::NativeHandle()
{
    return _mainWindow._hwnd;
}
