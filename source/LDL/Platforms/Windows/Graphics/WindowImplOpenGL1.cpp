// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include "WindowImplOpenGL1.hpp"

using namespace LDL::Core;
using namespace LDL::Events;
using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplOpenGL1::WindowImplOpenGL1(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _HGLRC(NULL),
    _Window(pos, size, title, mode)
{
    PIXELFORMATDESCRIPTOR pfd;

    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

    _Window._hdc = GetDC(_Window._hwnd);
    LDL_ASSERT_DETAIL(_Window._hdc != NULL, "GetDC failed");


    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_Window._hdc, &pfd);
    LDL_ASSERT_DETAIL(format != 0, "ChoosePixelFormat failed");

    BOOL result = SetPixelFormat(_Window._hdc, format, &pfd);
    LDL_ASSERT_DETAIL(result, "SetPixelFormat failed");

    _HGLRC = wglCreateContext(_Window._hdc);
    LDL_ASSERT_DETAIL(_HGLRC != NULL, "wglCreateContext failed");

    result = wglMakeCurrent(_Window._hdc, _HGLRC);
    LDL_ASSERT_DETAIL(result, "wglMakeCurrent failed");

    _OpenGLLoader.Init(1, 1);
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_HGLRC);

    ReleaseDC(_Window._hwnd, _Window._hdc);
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

const std::string& WindowImplOpenGL1::Title()
{
    return _Window.Title();
}

void WindowImplOpenGL1::Title(const std::string& title)
{
    _Window.Title(title);
}

void* WindowImplOpenGL1::NativeHandle()
{
    return _Window._hwnd;
}
