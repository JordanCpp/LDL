// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Window.hpp>
#include <LDL/SDL2/SDLApp.hpp>
#include <LDL/SDL2/SDLWin.hpp>

SDL_Window::SDL_Window(LDL_Result& result, const char* title, int x, int y, int w, int h, Uint32 flags) :
	_result(result),
	_window(LDL_CreateWindow(_result, _context, LDL_Vec2u(x, y), LDL_Vec2u(w, h), title, (size_t)flags))
{
}

SDL_Window::~SDL_Window()
{
}

LDL_IWindow* SDL_Window::GetWindow()
{
	return _window;
}

LDL_RenderContext& SDL_Window::GetRenderContext()
{
	return _context;
}
