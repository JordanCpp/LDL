#include "WindowImplDirect3D9.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;

WindowImplDirect3D9::WindowImplDirect3D9(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImplDirect3D9::~WindowImplDirect3D9()
{
}

void WindowImplDirect3D9::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
}

const Vec2u& WindowImplDirect3D9::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImplDirect3D9::Pos()
{
    return _Window.Pos();
}

bool WindowImplDirect3D9::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool WindowImplDirect3D9::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void WindowImplDirect3D9::StopEvent()
{
    _Window.StopEvent();
}

const std::string& WindowImplDirect3D9::Title()
{
    return _Window.Title();
}

void WindowImplDirect3D9::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND WindowImplDirect3D9::Hwnd()
{
    return _Window._HWND;
}