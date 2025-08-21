
#include <SDL3/SDL.h>

int main()
{
	SDL_Init(0);

	SDL_Window* window     = SDL_CreateWindow("Example: SDL3_Renderer", 800, 600, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

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

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
