
#include <SDL3/SDL.h>

int main()
{
	SDL_Init(0);

	SDL_Window* window = SDL_CreateWindow("Example: SDL3_Window", 800, 600, 0);

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
