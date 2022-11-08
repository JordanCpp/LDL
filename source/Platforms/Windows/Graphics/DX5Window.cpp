#include <LDL/Platforms/Windows/Graphics/DX5Window.hpp>
#include <LDL/Core/RuntimeError.hpp>

LDL::Graphics::Windows::DX5Window::DX5Window(const Point2u& pos, const Point2u& size, const std::string& title) :
    _Window(pos, size, title)
{
}

LDL::Graphics::Windows::DX5Window::~DX5Window()
{
}

void LDL::Graphics::Windows::DX5Window::Present()
{
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::DX5Window::Size()
{
    return _Window.Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::Windows::DX5Window::Pos()
{
    return _Window.Pos();
}

bool LDL::Graphics::Windows::DX5Window::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool LDL::Graphics::Windows::DX5Window::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void LDL::Graphics::Windows::DX5Window::StopEvent()
{
    _Window.StopEvent();
}

const std::string& LDL::Graphics::Windows::DX5Window::Title()
{
    return _Window.Title();
}

void LDL::Graphics::Windows::DX5Window::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND LDL::Graphics::Windows::DX5Window::Hwnd()
{
    return _Window._HWND;
}