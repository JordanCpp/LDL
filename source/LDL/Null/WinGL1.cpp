// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/WinNT/WinGL1.hpp>

using namespace LDL;

WindowImplOpenGL1::WindowImplOpenGL1(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _hglrc(NULL),
    _window(_result, pos, size, title, mode)
{
    PIXELFORMATDESCRIPTOR pfd;

    LDL_memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    WindowError windowError;

    _window._hdc = GetDC(_window._hwnd);
    if (_window._hdc == NULL)
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_window._hdc, &pfd);
    if (format == 0)
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!SetPixelFormat(_window._hdc, format, &pfd))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    _hglrc = wglCreateContext(_window._hdc);
    if (_hglrc == NULL)
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!wglMakeCurrent(_window._hdc, _hglrc))
    {
        _result.Message(windowError.GetErrorMessage());
        return;
    }
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_hglrc);
}

bool WindowImplOpenGL1::Running()
{
    return _window.Running();
}

void WindowImplOpenGL1::Present()
{
    SwapBuffers(_window._hdc);
}

void WindowImplOpenGL1::PollEvents()
{
    _window.PollEvents();
}

const LDL_Vec2u& WindowImplOpenGL1::Size()
{
    return _window.Size();
}

const LDL_Vec2u& WindowImplOpenGL1::Pos()
{
    return _window.Pos();
}

bool WindowImplOpenGL1::GetEvent(LDL_Event& event)
{
    return _window.GetEvent(event);
}

bool WindowImplOpenGL1::WaitEvent(LDL_Event& event)
{
    return _window.WaitEvent(event);
}

void WindowImplOpenGL1::StopEvent()
{
    _window.StopEvent();
}

const char* WindowImplOpenGL1::Title()
{
    return _window.Title();
}

void WindowImplOpenGL1::Title(const char* title)
{
    _window.Title(title);
}

void* WindowImplOpenGL1::NativeHandle()
{
    return _window._hwnd;
}
