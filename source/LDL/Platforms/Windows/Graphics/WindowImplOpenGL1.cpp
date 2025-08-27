// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include "WindowImplOpenGL1.hpp"

using namespace LDL;
using namespace LDL::Events;
using namespace LDL::Graphics;

WindowImplOpenGL1::WindowImplOpenGL1(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _HGLRC(NULL),
    _Window(_result, pos, size, title, mode)
{
    PIXELFORMATDESCRIPTOR pfd;

    LDL::memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    _Window._hdc = GetDC(_Window._hwnd);
    if (_Window._hdc == NULL)
    {
        _result.Message("GetDC failed");
        return;
    }

    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_Window._hdc, &pfd);
    if (format == 0)
    {
        _result.Message("ChoosePixelFormat failed");
        return;
    }

    if (!SetPixelFormat(_Window._hdc, format, &pfd))
    {
        _result.Message("SetPixelFormat failed");
        return;
    }

    _HGLRC = wglCreateContext(_Window._hdc);
    if (_HGLRC == NULL)
    {
        _result.Message("wglCreateContext failed");
        return;
    }

    if (!wglMakeCurrent(_Window._hdc, _HGLRC))
    {
        _result.Message("wglMakeCurrent failed");
        return;
    }

    _OpenGLLoader.Init(1, 1);
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);
}

bool WindowImplOpenGL1::Running()
{
    return _Window.Running();
}

void WindowImplOpenGL1::Present()
{
    SwapBuffers(_Window._hdc);
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

bool WindowImplOpenGL1::GetEvent(Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplOpenGL1::WaitEvent(Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplOpenGL1::StopEvent()
{
    _Window.StopEvent();
}

const char* WindowImplOpenGL1::Title()
{
    return _Window.Title();
}

void WindowImplOpenGL1::Title(const char* title)
{
    _Window.Title(title);
}

void* WindowImplOpenGL1::NativeHandle()
{
    return _Window._hwnd;
}
