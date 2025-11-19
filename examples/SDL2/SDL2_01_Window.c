// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL2/SDL.h> 

int main()
{
	SDL_Window* window = NULL;
	SDL_Event event;
	bool running = true;

	window = SDL_CreateWindow(__FILE__, 0, 0, 640, 480, 0);

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}

	SDL_DestroyWindow(window);

	return 0;
}
