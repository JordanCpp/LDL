// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/WinNT/WinSoft.hpp>

using namespace LDL;

LDL_WindowSoftware::LDL_WindowSoftware(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _mainWindow(_result, pos, size, title, mode)
{
    LDL::LDL_memset(&_bitmapInfo, 0, sizeof(_bitmapInfo));
}

LDL_WindowSoftware::~LDL_WindowSoftware()
{
}

void LDL_WindowSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
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
    return _mainWindow._hwnd;
}
