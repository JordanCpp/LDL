// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "SDL_Renderer.hpp"

bool SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
	LDL::Graphics::Color color = renderer->GetRender().Color();

	*r = color.r;
	*g = color.g;
	*b = color.b;
	*a = color.a;

	return true;
}
