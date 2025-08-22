
#include "SDL_Renderer.hpp"

void SDL_DestroyRenderer(SDL_Renderer* renderer)
{
	delete renderer;
}
