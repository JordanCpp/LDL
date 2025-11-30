// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Linux/WinGL3.hpp>

LDL_WindowOpenGL3::LDL_WindowOpenGL3(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _Window(pos, size, title, mode)
{
    GLint major = 0;
    GLint minor = 0;

    glXQueryVersion(_Window._Display, &major, &minor);

    GLint ga[] = {
        GLX_RGBA,
        GLX_DOUBLEBUFFER,
        GLX_DEPTH_SIZE, 24,
        GLX_STENCIL_SIZE, 8,
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        GLX_SAMPLE_BUFFERS, 0,
        GLX_SAMPLES, 0,
        None };

    _Visual = glXChooseVisual(_Window._Display, _Window._Screen, ga);

    if (_Visual == NULL)
    {
        _result.Message("glXChooseVisual failed");
        return;
    }

    XSetWindowAttributes wa;

    wa.border_pixel = BlackPixel(_Window._Display, _Window._Screen);
    wa.background_pixel = WhitePixel(_Window._Display, _Window._Screen);
    wa.override_redirect = True;
    wa.colormap = XCreateColormap(_Window._Display, _Window._Root, _Visual->visual, AllocNone);
    wa.event_mask = ExposureMask;

    size_t x = pos.x;
    size_t y = pos.y;
    size_t w = size.x;
    size_t h = size.y;

    _Window._Window = XCreateWindow(_Window._Display, _Window._Root, x, y, w, h, 0, _Visual->depth, InputOutput, _Visual->visual, CWBackPixel | CWColormap | CWBorderPixel | CWEventMask, &wa);

    XSelectInput(_Window._Display, _Window._Window, _Window._EventMask);

    _Context = glXCreateContext(_Window._Display, _Visual, NULL, 1);

    glXMakeCurrent(_Window._Display, _Window._Window, _Context);

    _Window.Title(title);

    _Window.Show();
}

LDL_WindowOpenGL3::~LDL_WindowOpenGL3()
{
    glXDestroyContext(_Window._Display, _Context);
}

void LDL_WindowOpenGL3::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    LDL_ASSERT(pixels != NULL);
    LDL_ASSERT(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void LDL_WindowOpenGL3::Present()
{
    glXSwapBuffers(_Window._Display, _Window._Window);
}

const LDL_Vec2u& LDL_WindowOpenGL3::Size()
{
    return _Window.Size();
}

const LDL_Vec2u& LDL_WindowOpenGL3::Pos()
{
    return _Window.Pos();
}

bool LDL_WindowOpenGL3::Running()
{
    return _Window.Running();
}

void LDL_WindowOpenGL3::PollEvents()
{
    _Window.PollEvents();
}

bool LDL_WindowOpenGL3::GetEvent(LDL_Event& event)
{
    return _Window.GetEvent(event);
}

bool LDL_WindowOpenGL3::WaitEvent(LDL_Event& event)
{
    return _Window.WaitEvent(event);
}

void LDL_WindowOpenGL3::StopEvent()
{
    _Window.StopEvent();
}

const char* LDL_WindowOpenGL3::Title()
{
    return _Window.Title();
}

void LDL_WindowOpenGL3::Title(const char* title)
{
    _Window.Title(title);
}

void* LDL_WindowOpenGL3::NativeHandle()
{
    return NULL;
}
