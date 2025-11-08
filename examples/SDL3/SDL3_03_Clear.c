// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/APIs/SDL3/SDL.h>

int main()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL_Init: %s\n", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow(__FILE__, 800, 600, 0);
	if (window == NULL)
	{
		printf("SDL_CreateWindow: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
	if (renderer == NULL)
	{
		printf("SDL_CreateRenderer: %s\n", SDL_GetError());
		return -1;
	}

	bool running = true;

	while (running)
	{
		SDL_Event event;

		SDL_SetRenderDrawColor(renderer, 0, 162, 232, 0);

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
