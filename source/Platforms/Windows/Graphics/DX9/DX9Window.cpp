#include "DX9Window.hpp"
#include <LDL/Core/RuntimeError.hpp>

LDL::Graphics::Windows::DX9Window::DX9Window(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

LDL::Graphics::Windows::DX9Window::~DX9Window()
{
}

void LDL::Graphics::Windows::DX9Window::Present()
{
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::DX9Window::Size()
{
    return _Window.Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::DX9Window::Pos()
{
    return _Window.Pos();
}

bool LDL::Graphics::Windows::DX9Window::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool LDL::Graphics::Windows::DX9Window::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void LDL::Graphics::Windows::DX9Window::StopEvent()
{
    _Window.StopEvent();
}

const std::string& LDL::Graphics::Windows::DX9Window::Title()
{
    return _Window.Title();
}

void LDL::Graphics::Windows::DX9Window::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND LDL::Graphics::Windows::DX9Window::Hwnd()
{
    return _Window._HWND;
}