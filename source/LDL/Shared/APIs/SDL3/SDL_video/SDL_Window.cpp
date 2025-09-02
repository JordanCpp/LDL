// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_video/SDL_Window.hpp>

using namespace LDL;

SDL_Window::SDL_Window(LDL::Result& result, const char* title, int w, int h, SDL_WindowFlags flags) :
	_result(result),
	_window(_result, _context, Vec2u(0, 0), Vec2u(w, h), title, (size_t)flags)
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
