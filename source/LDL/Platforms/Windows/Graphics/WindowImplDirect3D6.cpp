// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Windows/Graphics/WindowImplDirect3D6.hpp>

using namespace LDL::Core;
using namespace LDL::Events;
using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplDirect3D6::WindowImplDirect3D6(Result& result, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _result(result),
    _Window(_result, pos, size, title, mode)
{
}

WindowImplDirect3D6::~WindowImplDirect3D6()
{
    wglMakeCurrent(NULL, NULL);
    ReleaseDC(_Window._hwnd, _Window._hdc);
}

bool WindowImplDirect3D6::Running()
{
    return _Window.Running();
}

void WindowImplDirect3D6::Present()
{
}

void WindowImplDirect3D6::PollEvents()
{
    _Window.PollEvents();
}

const Vec2u& WindowImplDirect3D6::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplDirect3D6::Pos()
{
    return _Window.Pos();
}

bool WindowImplDirect3D6::GetEvent(Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplDirect3D6::WaitEvent(Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplDirect3D6::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplDirect3D6::Title()
{
    return _Window.Title();
}

void WindowImplDirect3D6::Title(const std::string& title)
{
    _Window.Title(title);
}

void* WindowImplDirect3D6::NativeHandle()
{
    return _Window._hwnd;
}
