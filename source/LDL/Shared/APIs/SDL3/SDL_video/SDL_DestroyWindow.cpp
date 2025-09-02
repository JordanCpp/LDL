// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_video/SDL_Window.hpp>

void SDL_DestroyWindow(SDL_Window* window)
{
	delete window;
}
