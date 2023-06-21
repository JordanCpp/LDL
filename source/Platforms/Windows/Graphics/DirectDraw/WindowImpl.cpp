#include "WindowImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

WindowImpl::WindowImpl(const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImpl::~WindowImpl()
{
}

bool WindowImpl::Running()
{
    return _Window.Running();
}

void WindowImpl::PollEvents()
{
    _Window.PollEvents();
}

void WindowImpl::Present(uint8_t* pixels, uint8_t bytesPerPixel)
{
}

const Vec2u& WindowImpl::Size()
{
    return _Window.Size();
}

const Vec2u& WindowImpl::Pos()
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