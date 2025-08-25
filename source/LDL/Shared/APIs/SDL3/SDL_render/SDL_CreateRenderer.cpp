// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_render/SDL_Renderer.hpp>

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, const char* name)
{
	SDL_Renderer* result = new SDL_Renderer(window, name);

	return result;
}
