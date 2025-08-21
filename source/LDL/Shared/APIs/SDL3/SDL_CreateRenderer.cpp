
#include "SDL_Renderer.hpp"

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, const char* name)
{
	SDL_Renderer* result = new SDL_Renderer(window, name);

	return result;
}
