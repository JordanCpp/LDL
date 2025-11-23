// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <assert.h>
#include <LDL/Linux/WinGL3.hpp>

LDL_WindowOpenGL3::LDL_WindowOpenGL3(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

LDL_WindowOpenGL3::~LDL_WindowOpenGL3()
{
}

void LDL_WindowOpenGL3::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void LDL_WindowOpenGL3::Present()
{
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
