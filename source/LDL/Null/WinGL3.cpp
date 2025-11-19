// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Null/WinGL3.hpp>

LDL_WindowOpenGL3::LDL_WindowOpenGL3(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _mainWindow(result,pos, size, title, mode)
{
}

LDL_WindowOpenGL3::~LDL_WindowOpenGL3()
{
}

bool LDL_WindowOpenGL3::Running()
{
    return _mainWindow.Running();
}

void LDL_WindowOpenGL3::PollEvents()
{
    _mainWindow.PollEvents();
}

void LDL_WindowOpenGL3::Present()
{
}

const LDL_Vec2u& LDL_WindowOpenGL3::Size()
{
    return _mainWindow.Size();
}

const LDL_Vec2u& LDL_WindowOpenGL3::Pos()
{
    return _mainWindow.Pos();
}

bool LDL_WindowOpenGL3::GetEvent(LDL_Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool LDL_WindowOpenGL3::WaitEvent(LDL_Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void LDL_WindowOpenGL3::StopEvent()
{
    _mainWindow.StopEvent();
}

const char* LDL_WindowOpenGL3::Title()
{
    return _mainWindow.Title();
}

void LDL_WindowOpenGL3::Title(const char* title)
{
    _mainWindow.Title(title);
}

void* LDL_WindowOpenGL3::NativeHandle()
{
    return NULL;
}
