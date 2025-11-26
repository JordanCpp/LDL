// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Null/WinGL1.hpp>

LDL_WindowOpenGL1::LDL_WindowOpenGL1(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _window(result, pos, size, title, mode)
{
}

LDL_WindowOpenGL1::~LDL_WindowOpenGL1()
{
}

bool LDL_WindowOpenGL1::Running()
{
    return _window.Running();
}

void LDL_WindowOpenGL1::Present()
{
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
    return NULL;
}
