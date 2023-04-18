#include "WindowImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

WindowImpl::WindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

WindowImpl::~WindowImpl()
{
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

void WindowImpl::Hwnd(HWND hwnd)
{
    _Window._HWND = hwnd;
}

HDC WindowImpl::Hdc()
{
    return _Window._HDC;
}

void WindowImpl::Hdc(HDC hdc)
{
    _Window._HDC = hdc;
}