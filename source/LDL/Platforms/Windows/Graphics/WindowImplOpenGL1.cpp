// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL1.hpp>

using namespace LDL;

WindowImplOpenGL1::WindowImplOpenGL1(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _result(result),
    _context(NULL),
    _mainWindow(_result, pos, size, title, mode)
{
    PIXELFORMATDESCRIPTOR pfd;

    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));

    _mainWindow._hdc = GetDC(_mainWindow._hwnd);
    LDL_ASSERT_DETAIL(_mainWindow._hdc != NULL, "GetDC failed");


    pfd.nSize      = sizeof(pfd);
    pfd.nVersion   = 1;
    pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int format = ChoosePixelFormat(_mainWindow._hdc, &pfd);
    if (format != 0)
    {
        _result.Message("ChoosePixelFormat failed");
    }

    if (!SetPixelFormat(_mainWindow._hdc, format, &pfd))
    {
        _result.Message("SetPixelFormat failed");
    }

    _context = wglCreateContext(_mainWindow._hdc);
    if (_context != NULL)
    {
        _result.Message("wglCreateContext failed");
    }

    if (!wglMakeCurrent(_mainWindow._hdc, _context))
    {
        _result.Message("wglMakeCurrent failed");
    }

    _loader.Init(1, 1);
}

WindowImplOpenGL1::~WindowImplOpenGL1()
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(_context);

    ReleaseDC(_mainWindow._hwnd, _mainWindow._hdc);
}

bool WindowImplOpenGL1::Running()
{
    return _mainWindow.Running();
}

void WindowImplOpenGL1::Present()
{
    SwapBuffers(_mainWindow._hdc);
}

void WindowImplOpenGL1::PollEvents()
{
    _mainWindow.PollEvents();
}

const Vec2u& WindowImplOpenGL1::Size()
{
    return _mainWindow.Size();
}

const Vec2u& WindowImplOpenGL1::Pos()
{
    return _mainWindow.Pos();
}

bool WindowImplOpenGL1::GetEvent(Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool WindowImplOpenGL1::WaitEvent(Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void WindowImplOpenGL1::StopEvent()
{
    _mainWindow.StopEvent();
}

const std::string& WindowImplOpenGL1::Title()
{
    return _mainWindow.Title();
}

void WindowImplOpenGL1::Title(const std::string& title)
{
    _mainWindow.Title(title);
}

void* WindowImplOpenGL1::NativeHandle()
{
    return _mainWindow._hwnd;
}
