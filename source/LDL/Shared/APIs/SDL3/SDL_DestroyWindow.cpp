
#include "SDL_Window.hpp"

void SDL_DestroyWindow(SDL_Window* window)
{
	delete window;
}
