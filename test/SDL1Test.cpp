// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/APIs/SDL/SDL.h>

void SDL_SetVideoModeTest()
{
	SDL_Surface* surface = SDL_SetVideoMode(640, 480, 24, 0);

	LDL_TEST_EQUAL(surface    != NULL);
	LDL_TEST_EQUAL(surface->w == 640);
	LDL_TEST_EQUAL(surface->h == 480);

	if (surface)
	{
		SDL_FreeSurface(surface);
	}
}

void SDL_SurfaceCreateTest()
{
	SDL_Surface* surfRgb = SDL_CreateRGBSurface(0, 640, 480, 0, 0, 0, 0, 0);

	LDL_TEST_EQUAL(surfRgb != NULL);
	LDL_TEST_EQUAL(surfRgb->w == 640);
	LDL_TEST_EQUAL(surfRgb->h == 480);

	if (surfRgb)
	{
		SDL_FreeSurface(surfRgb);
	}
}

int main()
{
	SDL_SetVideoModeTest();
	SDL_SurfaceCreateTest();

	return 0;
}
