#include <LDL/Graphics/Window.hpp>

#include "Creators/WindowImplCreator.hpp"

#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

Window::Window(RenderContext* renderContext, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode)
{
	WindowImplCreator creator;

	_WindowImpl = creator.Create(renderContext, pos, size, title, mode);
}

Window::~Window()
{
	delete _WindowImpl;
}

bool Window::Running()
{
	return _WindowImpl->Running();
}

void Window::PollEvents()
{
	_WindowImpl->PollEvents();
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

const Vec2u& Window::Size()
{
	return _WindowImpl->Size();
}

const Vec2u& Window::Pos()
{
	return _WindowImpl->Pos();
}

WindowImpl* Window::GetWindowImpl()
{
	return _WindowImpl;
}