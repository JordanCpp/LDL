// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/WinNT/WinGL3.hpp>

typedef HGLRC(WINAPI* PFNWGLCREATECONTEXT)(HDC);
typedef BOOL (WINAPI* PFNWGLMAKECURRENT  )(HDC, HGLRC);
typedef BOOL (WINAPI* PFNWGLDELETECONTEXT)(HGLRC);

typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);

const int WGL_CONTEXT_MAJOR_VERSION_ARB             = 0x2091;
const int WGL_CONTEXT_MINOR_VERSION_ARB             = 0x2092;
const int WGL_CONTEXT_FLAGS_ARB                     = 0x2094;
const int WGL_CONTEXT_PROFILE_MASK_ARB              = 0x9126;
const int WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB    = 0x00000002;
const int WGL_CONTEXT_CORE_PROFILE_BIT_ARB          = 0x00000001;
const int WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;

LDL_WindowOpenGL3::LDL_WindowOpenGL3(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _mainWindow(_result,pos, size, title, mode),
    _hglrc(NULL)
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

    LDL_memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    WindowError windowError;

    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;

    int format = ChoosePixelFormat(_mainWindow.GetHdc(), &pfd);
    if (format == 0)
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!SetPixelFormat(_mainWindow.GetHdc(), format, &pfd))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    _hglrc = wglCreateContext(_mainWindow.GetHdc());
    if (_hglrc == NULL)
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!wglMakeCurrent(_mainWindow.GetHdc(), _hglrc))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    if (wglCreateContextAttribsARB == NULL)
    {
        _result.Message("wglGetProcAddress failed");
        return;
    }

    if (!wglMakeCurrent(NULL, NULL))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!wglDeleteContext(_hglrc))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    _hglrc = wglCreateContextAttribsARB(_mainWindow.GetHdc(), 0, attribs);
    if (_hglrc == NULL)
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!wglMakeCurrent(_mainWindow.GetHdc(), _hglrc))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }
}

LDL_WindowOpenGL3::~LDL_WindowOpenGL3()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_hglrc);

    ReleaseDC(_mainWindow.GetHwnd(), _mainWindow.GetHdc());
}

bool LDL_WindowOpenGL3::Running()
{
    return _mainWindow.Running();
}

void LDL_WindowOpenGL3::PollEvents()
{
    _mainWindow.PollEvents();
}

void LDL_WindowOpenGL3::Present()
{
    BOOL result = SwapBuffers(_mainWindow.GetHdc());
    LDL_ASSERT_DETAIL(result, "SwapBuffers failed");
}

const LDL_Vec2u& LDL_WindowOpenGL3::Size()
{
    return _mainWindow.Size();
}

const LDL_Vec2u& LDL_WindowOpenGL3::Pos()
{
    return _mainWindow.Pos();
}

bool LDL_WindowOpenGL3::GetEvent(LDL_Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool LDL_WindowOpenGL3::WaitEvent(LDL_Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void LDL_WindowOpenGL3::StopEvent()
{
    _mainWindow.StopEvent();
}

const char* LDL_WindowOpenGL3::Title()
{
    return _mainWindow.Title();
}

void LDL_WindowOpenGL3::Title(const char* title)
{
    _mainWindow.Title(title);
}

void* LDL_WindowOpenGL3::NativeHandle()
{
    return _mainWindow.GetHwnd();
}
