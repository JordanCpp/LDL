// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Windows/Graphics/WindowImplGlide.hpp>

using namespace LDL;

WindowImplGlide::WindowImplGlide(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _mainWindow(_result, pos, size, title, mode)
{
}

WindowImplGlide::~WindowImplGlide()
{
    wglMakeCurrent(NULL, NULL);
    ReleaseDC(_mainWindow._hwnd, _mainWindow._hdc);
}

bool WindowImplGlide::Running()
{
    return _mainWindow.Running();
}

void WindowImplGlide::Present()
{
}

void WindowImplGlide::PollEvents()
{
    _mainWindow.PollEvents();
}

const Vec2u& WindowImplGlide::Size()
{
    return _mainWindow.Size();
}

const Vec2u& WindowImplGlide::Pos()
{
    return _mainWindow.Pos();
}

bool WindowImplGlide::GetEvent(Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool WindowImplGlide::WaitEvent(Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void WindowImplGlide::StopEvent()
{
    _mainWindow.StopEvent();
}

const char* WindowImplGlide::Title()
{
    return _mainWindow.Title();
}

void WindowImplGlide::Title(const char* title)
{
    _mainWindow.Title(title);
}

void* WindowImplGlide::NativeHandle()
{
    return _mainWindow._hwnd;
}
