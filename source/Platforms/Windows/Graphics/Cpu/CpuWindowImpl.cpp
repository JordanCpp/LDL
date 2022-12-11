#include "CpuWindowImpl.hpp"

LDL::Graphics::CpuWindowImpl::CpuWindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

LDL::Graphics::CpuWindowImpl::~CpuWindowImpl()
{
}

void LDL::Graphics::CpuWindowImpl::Present(uint8_t* pixels)
{
    _BITMAPINFO.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    _BITMAPINFO.bmiHeader.biWidth = (LONG)_Window.Size().PosX();
    _BITMAPINFO.bmiHeader.biHeight = -(LONG)_Window.Size().PosY();
    _BITMAPINFO.bmiHeader.biPlanes = 1;
    _BITMAPINFO.bmiHeader.biBitCount = 32;
    _BITMAPINFO.bmiHeader.biCompression = BI_RGB;

    SetDIBitsToDevice(_Window._HDC, 0, 0, (DWORD)_Window.Size().PosX(), (DWORD)_Window.Size().PosY(), 0, 0, 0, (UINT)_Window.Size().PosY(), pixels, &_BITMAPINFO, DIB_RGB_COLORS);
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuWindowImpl::Size()
{
    return _Window.Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuWindowImpl::Pos()
{
    return _Window.Pos();
}

bool LDL::Graphics::CpuWindowImpl::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

void LDL::Graphics::CpuWindowImpl::StopEvent()
{
    _Window.StopEvent();
}

const std::string& LDL::Graphics::CpuWindowImpl::Title()
{
    return _Window.Title();
}

void LDL::Graphics::CpuWindowImpl::Title(const std::string& title)
{
    _Window.Title(title);
}