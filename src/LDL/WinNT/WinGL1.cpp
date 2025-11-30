// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/WinNT/WinGL1.hpp>

LDL_WindowOpenGL1::LDL_WindowOpenGL1(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _hglrc(NULL),
    _window(_result, pos, size, title, mode)
{
    PIXELFORMATDESCRIPTOR pfd;

    LDL_memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_window.GetHdc(), &pfd);
    if (format == 0)
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    PIXELFORMATDESCRIPTOR chosenPfd;
    DescribePixelFormat(_window.GetHdc(), format, sizeof(chosenPfd), &chosenPfd);

    if (!(chosenPfd.dwFlags & PFD_SUPPORT_OPENGL))
    {
        _result.Message("OpenGL not supported by selected pixel format");
        return;
    }

    if (!SetPixelFormat(_window.GetHdc(), format, &pfd))
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    _hglrc = wglCreateContext(_window.GetHdc());
    if (_hglrc == NULL)
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return;
    }

    if (!wglMakeCurrent(_window.GetHdc(), _hglrc))
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return;
    }
}

LDL_WindowOpenGL1::~LDL_WindowOpenGL1()
{
    if (_hglrc != NULL)
    {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(_hglrc);
        _hglrc = NULL;
    }
}

bool LDL_WindowOpenGL1::Running()
{
    return _window.Running();
}

void LDL_WindowOpenGL1::Present()
{
    SwapBuffers(_window.GetHdc());
}

void LDL_WindowOpenGL1::PollEvents()
{
    _window.PollEvents();
}

const LDL_Vec2u& LDL_WindowOpenGL1::Size()
{
    return _window.Size();
}

const LDL_Vec2u& LDL_WindowOpenGL1::Pos()
{
    return _window.Pos();
}

bool LDL_WindowOpenGL1::GetEvent(LDL_Event& event)
{
    return _window.GetEvent(event);
}

bool LDL_WindowOpenGL1::WaitEvent(LDL_Event& event)
{
    return _window.WaitEvent(event);
}

void LDL_WindowOpenGL1::StopEvent()
{
    _window.StopEvent();
}

const char* LDL_WindowOpenGL1::Title()
{
    return _window.Title();
}

void LDL_WindowOpenGL1::Title(const char* title)
{
    _window.Title(title);
}

void* LDL_WindowOpenGL1::NativeHandle()
{
    return _window.GetHwnd();
}
