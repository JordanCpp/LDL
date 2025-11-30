// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Linux/WinSoft.hpp>

LDL_WindowSoftware::LDL_WindowSoftware(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

LDL_WindowSoftware::~LDL_WindowSoftware()
{
}

void LDL_WindowSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    LDL_ASSERT(pixels != NULL);
    LDL_ASSERT(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);
}

void LDL_WindowSoftware::Present()
{
}

const LDL_Vec2u& LDL_WindowSoftware::Size()
{
    return _Window.Size();
}

const LDL_Vec2u& LDL_WindowSoftware::Pos()
{
    return _Window.Pos();
}

bool LDL_WindowSoftware::Running()
{
    return _Window.Running();
}

void LDL_WindowSoftware::PollEvents()
{
    _Window.PollEvents();
}

bool LDL_WindowSoftware::GetEvent(LDL_Event& event)
{
    return _Window.GetEvent(event);
}

bool LDL_WindowSoftware::WaitEvent(LDL_Event& event)
{
    return _Window.WaitEvent(event);
}

void LDL_WindowSoftware::StopEvent()
{
    _Window.StopEvent();
}

const char* LDL_WindowSoftware::Title()
{
    return _Window.Title();
}

void LDL_WindowSoftware::Title(const char* title)
{
    _Window.Title(title);
}

void* LDL_WindowSoftware::NativeHandle()
{
    return NULL;
}
