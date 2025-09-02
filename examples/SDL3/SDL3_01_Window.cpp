// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <SDL3/SDL.h>

int main()
{
	SDL_Init(0);

	SDL_Window* window = SDL_CreateWindow(__FILE__, 800, 600, 0);

	bool running = true;

	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) 
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
