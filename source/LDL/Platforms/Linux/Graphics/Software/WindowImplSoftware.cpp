// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "WindowImplSoftware.hpp"
#include <assert.h>

using namespace LDL;

WindowImplSoftware::WindowImplSoftware(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImplSoftware::~WindowImplSoftware()
{
}

void WindowImplSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void WindowImplSoftware::Present()
{
}

const Vec2u& WindowImplSoftware::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplSoftware::Pos()
{
    return _Window.Pos();
}

bool WindowImplSoftware::Running()
{
    return _Window.Running();
}

void WindowImplSoftware::PollEvents()
{
    _Window.PollEvents();
}

bool WindowImplSoftware::GetEvent(Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplSoftware::WaitEvent(Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplSoftware::StopEvent()
{
    _Window.StopEvent();
}

const char* WindowImplSoftware::Title()
{
    return _Window.Title();
}

void WindowImplSoftware::Title(const char* title)
{
    _Window.Title(title);
}

void* WindowImplSoftware::NativeHandle()
{
    return NULL;
}