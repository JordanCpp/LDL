// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "SDL_Renderer.hpp"

bool SDL_RenderClear(SDL_Renderer* renderer)
{
	renderer->GetRender().Clear();

	return true;
}
