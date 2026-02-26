// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Windows/Graphics/WindowImplDirect3D6.hpp>

using namespace LDL;

WindowImplDirect3D6::WindowImplDirect3D6(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _result(result),
    _mainWindow(_result, pos, size, title, mode)
{
}

WindowImplDirect3D6::~WindowImplDirect3D6()
{
    wglMakeCurrent(NULL, NULL);
    ReleaseDC(_mainWindow._hwnd, _mainWindow._hdc);
}

bool WindowImplDirect3D6::Running()
{
    return _mainWindow.Running();
}

void WindowImplDirect3D6::Present()
{
}

void WindowImplDirect3D6::PollEvents()
{
    _mainWindow.PollEvents();
}

const Vec2u& WindowImplDirect3D6::Size()
{
    return _mainWindow.Size();
}

const Vec2u& WindowImplDirect3D6::Pos()
{
    return _mainWindow.Pos();
}

bool WindowImplDirect3D6::GetEvent(Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool WindowImplDirect3D6::WaitEvent(Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void WindowImplDirect3D6::StopEvent()
{
    _mainWindow.StopEvent();
}

const std::string& WindowImplDirect3D6::Title()
{
    return _mainWindow.Title();
}

void WindowImplDirect3D6::Title(const std::string& title)
{
    _mainWindow.Title(title);
}

void* WindowImplDirect3D6::NativeHandle()
{
    return _mainWindow._hwnd;
}
