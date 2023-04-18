#include "WindowImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <assert.h>

using namespace LDL::Graphics;

WindowImpl::WindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
    ZeroMemory(&_BITMAPINFO, sizeof(_BITMAPINFO));
}

WindowImpl::~WindowImpl()
{
}

void WindowImpl::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
    assert(pixels != NULL);
    assert(bytesPerPixel == 1 || bytesPerPixel == 2 || bytesPerPixel == 3 || bytesPerPixel == 4);

    _BITMAPINFO.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    _BITMAPINFO.bmiHeader.biWidth = (LONG)_Window.Size().PosX();
    _BITMAPINFO.bmiHeader.biHeight = -(LONG)_Window.Size().PosY();
    _BITMAPINFO.bmiHeader.biPlanes = 1;
    _BITMAPINFO.bmiHeader.biBitCount = bytesPerPixel * 8;
    _BITMAPINFO.bmiHeader.biCompression = BI_RGB;

    if (SetDIBitsToDevice(_Window._HDC, 0, 0, (DWORD)_Window.Size().PosX(), (DWORD)_Window.Size().PosY(), 0, 0, 0, (UINT)_Window.Size().PosY(), pixels, &_BITMAPINFO, DIB_RGB_COLORS) == 0)
        throw LDL::Core::RuntimeError("SetDIBitsToDevice failed");
}

const Point2u& WindowImpl::Size()
{
    return _Window.Size();
}

const Point2u& WindowImpl::Pos()
{
    return _Window.Pos();
}

bool WindowImpl::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImpl::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImpl::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImpl::Title()
{
    return _Window.Title();
}

void WindowImpl::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND WindowImpl::Hwnd()
{
    return _Window._HWND;
}