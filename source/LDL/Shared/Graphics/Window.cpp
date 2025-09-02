// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)


#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Shared/Graphics/Creators/WindowImplCreator.hpp>

using namespace LDL;
using namespace LDL::Graphics;

Window::Window(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode)
{
	WindowImplCreator creator;

	_impl = creator.Create(_memory, result, renderContext, pos, size, title, mode);
}

Window::~Window()
{
	_impl->~WindowImpl();
}

bool Window::Running()
{
	return _impl->Running();
}

void Window::PollEvents()
{
	_impl->PollEvents();
}

bool Window::GetEvent(Event& event)
{
	return _impl->GetEvent(event);
}

bool Window::WaitEvent(Event& event)
{
	return _impl->WaitEvent(event);
}

void Window::StopEvent()
{
	_impl->StopEvent();
}

void Window::Title(const char* title)
{
	_impl->Title(title);
}

const char* Window::Title()
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
