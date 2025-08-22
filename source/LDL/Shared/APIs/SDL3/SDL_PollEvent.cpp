// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <SDL3/SDL_events.h>
#include "SDL_Application.hpp"

bool SDL_PollEvent(SDL_Event* event)
{
	if (App().PollEvent(*event))
	{
		return true;
	}

	App().PollEvents();

	return false;
}
