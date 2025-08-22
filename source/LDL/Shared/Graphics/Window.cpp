// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Shared/Graphics/Creators/WindowImplCreator.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

Window::Window(RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode)
{
	WindowImplCreator creator;

	_impl = creator.Create(renderContext, pos, size, title, mode);
}

Window::~Window()
{
	delete _impl;
}

bool Window::Running()
{
	return _impl->Running();
}

void Window::PollEvents()
{
	_impl->PollEvents();
}

bool Window::GetEvent(LDL::Events::Event& event)
{
	return _impl->GetEvent(event);
}

bool Window::WaitEvent(LDL::Events::Event& event)
{
	return _impl->WaitEvent(event);
}

void Window::StopEvent()
{
	_impl->StopEvent();
}

void Window::Title(const std::string& title)
{
	_impl->Title(title);
}

const std::string& Window::Title()
{
	return _impl->Title();
}

const Vec2u& Window::Size()
{
	return _impl->Size();
}

const Vec2u& Window::Pos()
{
	return _impl->Pos();
}

WindowImpl* Window::GetWindowImpl()
{
	return _impl;
}

void* Window::NativeHandle()
{
	return _impl->NativeHandle();
}