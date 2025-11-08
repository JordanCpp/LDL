// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_Application.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Window.hpp>

using namespace LDL;

SDL_Window::SDL_Window(Result& result, const char* title, int w, int h, SDL_WindowFlags flags) :
	_result(result),
	_window(_result, _context, Vec2u(0, 0), Vec2u(w, h), title, (size_t)flags)
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

SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags)
{
	void* memory = LDL_malloc(sizeof(SDL_Window));

	SDL_Window* result = new(memory) SDL_Window(App().GetResult(), title, w, h, flags);

	App().Append(result);

	return result;
}

void SDL_DestroyWindow(SDL_Window* window)
{
	window->~SDL_Window();
	LDL_free(window);
}
