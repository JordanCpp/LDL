#include <LDL/Graphics/Window.hpp>

#include "../Platforms/Windows/Graphics/WindowImpl.hpp"

using namespace LDL::Graphics;

Window::Window(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
	_WindowImpl(new WindowImpl(pos, size, title, mode))
{
}

Window::~Window()
{
	delete _WindowImpl;
}

bool Window::GetEvent(LDL::Events::Event& event)
{
	return _WindowImpl->GetEvent(event);
}

bool Window::WaitEvent(LDL::Events::Event& event)
{
	return _WindowImpl->WaitEvent(event);
}

void Window::StopEvent()
{
	_WindowImpl->StopEvent();
}

void Window::Title(const std::string& title)
{
	_WindowImpl->Title(title);
}

const std::string& Window::Title()
{
	return _WindowImpl->Title();
}

const Point2u& Window::Size()
{
	return _WindowImpl->Size();
}

const Point2u& Window::Pos()
{
	return _WindowImpl->Pos();
}

WindowImpl* Window::GetWindowImpl()
{
	return _WindowImpl;
}