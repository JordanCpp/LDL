// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL2/events.h>
#include <LDL/SDL2/SDLApp.hpp>

int SDL_PollEvent(SDL_Event* event)
{
	if (App().PollEvent(*event))
	{
		return true;
	}

	App().PollEvents();

	return false;
}
