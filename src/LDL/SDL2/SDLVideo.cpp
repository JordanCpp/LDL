// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL2/video.h>
#include <LDL/SDL2/SDLWin.hpp>
#include <LDL/SDL2/SDLApp.hpp>

SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	void* memory = SDL_malloc(sizeof(SDL_Window));

	SDL_Window* result = new(memory) SDL_Window(App().GetResult(), title, x, y, w, h, flags);

	App().Append(result);

	return result;
}

void SDL_DestroyWindow(SDL_Window* window)
{
	window->~SDL_Window();
	SDL_free(window);
}
