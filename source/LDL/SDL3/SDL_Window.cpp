// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL3/SDL_Application.hpp>
#include <LDL/SDL3/SDL_Window.hpp>
#include <LDL/Window.hpp>

SDL_Window::SDL_Window(LDL_Result& result, const char* title, int w, int h, SDL_WindowFlags flags) :
	_result(result),
	_window(LDL_CreateWindow(_result, _context, LDL_Vec2u(0, 0), LDL_Vec2u(w, h), title, (size_t)flags))
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

SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags)
{
	void* memory = SDL_malloc(sizeof(SDL_Window));

	SDL_Window* result = new(memory) SDL_Window(App().GetResult(), title, w, h, flags);

	App().Append(result);

	return result;
}

void SDL_DestroyWindow(SDL_Window* window)
{
	window->~SDL_Window();
	SDL_free(window);
}
