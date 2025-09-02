// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/stdlib.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Application.hpp>

SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags)
{
	SDL_Window* result = new(LDL::LDL_malloc(sizeof(SDL_Window))) SDL_Window(App().GetResult(), title, w, h, flags);

	App().Append(result);

	return result;
}
