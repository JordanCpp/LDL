// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "SDL_Window.hpp"

using namespace LDL::Math;
using namespace LDL::Events;
using namespace LDL::Graphics;

SDL_Window::SDL_Window(const char* title, int w, int h, SDL_WindowFlags flags) :
	_window(_context, Vec2u(0, 0), Vec2u(w, h), title, (size_t)flags)
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
