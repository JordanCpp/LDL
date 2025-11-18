// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/WinNT/Graphics/WindowImplSoftware.hpp>

using namespace LDL;

WindowImplSoftware::WindowImplSoftware(Result& result, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _mainWindow(_result, pos, size, title, mode)
{
    LDL::LDL_memset(&_bitmapInfo, 0, sizeof(_bitmapInfo));
}

WindowImplSoftware::~WindowImplSoftware()
{
}

void WindowImplSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    LDL_ASSERT(pixels != NULL);
    LDL_ASSERT(bytesPerPixel >= 1 && bytesPerPixel <= 4);

    _bitmapInfo.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    _bitmapInfo.bmiHeader.biWidth       = (LONG)_mainWindow.Size().x;
    _bitmapInfo.bmiHeader.biHeight      = -(LONG)_mainWindow.Size().y;
    _bitmapInfo.bmiHeader.biPlanes      = 1;
    _bitmapInfo.bmiHeader.biBitCount    = bytesPerPixel * 8;
    _bitmapInfo.bmiHeader.biCompression = BI_RGB;

    int result = SetDIBitsToDevice(_mainWindow._hdc, 0, 0, (DWORD)_mainWindow.Size().x, (DWORD)_mainWindow.Size().y, 0, 0, 0, (UINT)_mainWindow.Size().y, pixels, &_bitmapInfo, DIB_RGB_COLORS);
    LDL_ASSERT_DETAIL(result != 0, "SetDIBitsToDevice failed");
}

void WindowImplSoftware::Present()
{
}

const Vec2u& WindowImplSoftware::Size()
{
    return _mainWindow.Size();
}

const Vec2u& WindowImplSoftware::Pos()
{
    return _mainWindow.Pos();
}

bool WindowImplSoftware::Running()
{
    return _mainWindow.Running();
}

void WindowImplSoftware::PollEvents()
{
    _mainWindow.PollEvents();
}

bool WindowImplSoftware::GetEvent(Event& event)
{
    return _mainWindow.GetEvent(event);
}

bool WindowImplSoftware::WaitEvent(Event& event)
{
    return _mainWindow.WaitEvent(event);
}

void WindowImplSoftware::StopEvent()
{
    _mainWindow.StopEvent();
}

const char* WindowImplSoftware::Title()
{
    return _mainWindow.Title();
}

void WindowImplSoftware::Title(const char* title)
{
    _mainWindow.Title(title);
}

void* WindowImplSoftware::NativeHandle()
{
    return _mainWindow._hwnd;
}
