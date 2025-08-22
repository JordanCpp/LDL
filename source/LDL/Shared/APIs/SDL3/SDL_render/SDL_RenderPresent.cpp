
#include "SDL_Renderer.hpp"

bool SDL_RenderPresent(SDL_Renderer* renderer)
{
	renderer->GetRender().End();

	return true;
}
