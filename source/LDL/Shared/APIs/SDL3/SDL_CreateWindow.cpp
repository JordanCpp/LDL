
#include "SDL_Application.hpp"

SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags)
{
	SDL_Window* result = new SDL_Window(title, w, h, flags);

	App().Append(result);

	return result;
}
