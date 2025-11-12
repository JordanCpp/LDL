// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL2/SDL_Application.hpp>
#include <LDL/APIs/SDL2/SDL_Window.hpp>

using namespace LDL;

SDL_Window::SDL_Window(Result& result, const char* title, int x, int y, int w, int h, Uint32 flags) :
	_result(result),
	_window(_result, _context, Vec2u(x, y), Vec2u(w, h), title, (size_t)flags)
{
}

SDL_Window::~SDL_Window()
{
}

Window& SDL_Window::GetWindow()
{
	return _window;
}

RenderContext& SDL_Window::GetRenderContext()
{
	return _context;
}
