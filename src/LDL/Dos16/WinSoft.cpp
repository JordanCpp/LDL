// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Dos16/WinSoft.hpp>

LDL_WindowSoftware::LDL_WindowSoftware(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _mainWindow(result, pos, size, title, mode)
{
}

LDL_WindowSoftware::~LDL_WindowSoftware()
{
}

void LDL_WindowSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
}

void LDL_WindowSoftware::Present()
{
}

const LDL_Vec2u& LDL_WindowSoftware::Size()
{
    return _mainWindow.Size();
}

const LDL_Vec2u& LDL_WindowSoftware::Pos()
{
    return _mainWindow.Pos();
}

bool LDL_WindowSoftware::Running()
{
    return _mainWindow.Running();
}

void LDL_WindowSoftware::PollEvents()
{
    _mainWindow.PollEvents();
}

bool LDL_WindowSoftware::GetEvent(LDL_Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool LDL_WindowSoftware::WaitEvent(LDL_Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void LDL_WindowSoftware::StopEvent()
{
    _mainWindow.StopEvent();
}

const char* LDL_WindowSoftware::Title()
{
    return _mainWindow.Title();
}

void LDL_WindowSoftware::Title(const char* title)
{
    _mainWindow.Title(title);
}

void* LDL_WindowSoftware::NativeHandle()
{
    return NULL;
}
