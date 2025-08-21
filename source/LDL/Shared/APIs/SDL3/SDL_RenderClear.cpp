
#include "SDL_Renderer.hpp"

bool SDL_RenderClear(SDL_Renderer* renderer)
{
	renderer->GetRender().Clear();

	return true;
}
