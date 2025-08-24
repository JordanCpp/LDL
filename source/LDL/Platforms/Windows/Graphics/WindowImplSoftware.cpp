// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "WindowImplSoftware.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Events;
using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplSoftware::WindowImplSoftware(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _Window(_result, pos, size, title, mode)
{
    ZeroMemory(&_BITMAPINFO, sizeof(_BITMAPINFO));
}

WindowImplSoftware::~WindowImplSoftware()
{
}

void WindowImplSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    LDL_ASSERT(pixels != NULL);
    LDL_ASSERT(bytesPerPixel >= 1 && bytesPerPixel <= 4);

    _BITMAPINFO.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    _BITMAPINFO.bmiHeader.biWidth       = (LONG)_Window.Size().x;
    _BITMAPINFO.bmiHeader.biHeight      = -(LONG)_Window.Size().y;
    _BITMAPINFO.bmiHeader.biPlanes      = 1;
    _BITMAPINFO.bmiHeader.biBitCount    = bytesPerPixel * 8;
    _BITMAPINFO.bmiHeader.biCompression = BI_RGB;

    int result = SetDIBitsToDevice(_Window._hdc, 0, 0, (DWORD)_Window.Size().x, (DWORD)_Window.Size().y, 0, 0, 0, (UINT)_Window.Size().y, pixels, &_BITMAPINFO, DIB_RGB_COLORS);
    LDL_ASSERT_DETAIL(result != 0, "SetDIBitsToDevice failed");
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
    return _Window._hwnd;
}
