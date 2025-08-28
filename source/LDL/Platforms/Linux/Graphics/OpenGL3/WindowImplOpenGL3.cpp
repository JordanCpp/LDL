// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "WindowImplOpenGL3.hpp"
#include <assert.h>

using namespace LDL;

WindowImplOpenGL3::WindowImplOpenGL3(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImplOpenGL3::~WindowImplOpenGL3()
{
}

void WindowImplOpenGL3::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void WindowImplOpenGL3::Present()
{
}

const Vec2u& WindowImplOpenGL3::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplOpenGL3::Pos()
{
    return _Window.Pos();
}

bool WindowImplOpenGL3::Running()
{
    return _Window.Running();
}

void WindowImplOpenGL3::PollEvents()
{
    _Window.PollEvents();
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

const char* WindowImplOpenGL3::Title()
{
    return _Window.Title();
}

void WindowImplOpenGL3::Title(const char* title)
{
    _Window.Title(title);
}

void* WindowImplOpenGL3::NativeHandle()
{
    return NULL;
}
