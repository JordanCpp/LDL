// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Cpp98.hpp>

using namespace LDL;

Vec2u::Vec2u() :
	LDL_Vec2u(0, 0)
{
}

Vec2u::Vec2u(uint32_t x, uint32_t) :
	LDL_Vec2u(x, y)
{
}

Window::Window(Result& result, RenderContext& renderContext, const Vec2u& pos, const Vec2u& size, const char* title, size_t mode)
{
	_window = LDL_CreateWindow(result, renderContext, pos, size, title, mode);
}

Window::~Window()
{
	delete _window;
}

bool Window::Running()
{
	return _window->Running();
}

void Window::Present()
{
	_window->Present();
}

void Window::PollEvents()
{
	_window->PollEvents();
}

bool Window::GetEvent(LDL_Event& event)
{
	return _window->GetEvent(event);
}

bool Window::WaitEvent(LDL_Event& event)
{
	return _window->WaitEvent(event);
}

void Window::StopEvent()
{
	_window->StopEvent();
}

void Window::Title(const char* title)
{
	_window->Title(title);
}

const char* Window::Title()
{
	return _window->Title();
}

const Vec2u& Window::Size()
{
	_vec = Vec2u(_window->Size().x, _window->Size().y);

	return _vec;
}

const Vec2u& Window::Pos()
{
	_vec = Vec2u(_window->Pos().x, _window->Pos().y);

	return _vec;
}

void* Window::NativeHandle()
{
	return _window->NativeHandle();
}


