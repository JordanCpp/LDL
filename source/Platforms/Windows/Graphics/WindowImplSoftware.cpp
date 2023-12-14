#include "WindowImplSoftware.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <assert.h>

using namespace LDL::Core;
using namespace LDL::Events;
using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImplSoftware::WindowImplSoftware(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
    ZeroMemory(&_BITMAPINFO, sizeof(_BITMAPINFO));
}

WindowImplSoftware::~WindowImplSoftware()
{
}

void WindowImplSoftware::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);

    _BITMAPINFO.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    _BITMAPINFO.bmiHeader.biWidth       = (LONG)_Window.Size().x;
    _BITMAPINFO.bmiHeader.biHeight      = -(LONG)_Window.Size().y;
    _BITMAPINFO.bmiHeader.biPlanes      = 1;
    _BITMAPINFO.bmiHeader.biBitCount    = bytesPerPixel * 8;
    _BITMAPINFO.bmiHeader.biCompression = BI_RGB;

    if (SetDIBitsToDevice(_Window._HDC, 0, 0, (DWORD)_Window.Size().x, (DWORD)_Window.Size().y, 0, 0, 0, (UINT)_Window.Size().y, pixels, &_BITMAPINFO, DIB_RGB_COLORS) == 0)
        throw RuntimeError("SetDIBitsToDevice failed");
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

const std::string& WindowImplSoftware::Title()
{
    return _Window.Title();
}

void WindowImplSoftware::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND WindowImplSoftware::Hwnd()
{
    return _Window._HWND;
}
