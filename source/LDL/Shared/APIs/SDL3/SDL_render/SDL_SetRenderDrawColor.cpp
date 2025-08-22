
#include "SDL_Renderer.hpp"

bool SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	renderer->GetRender().Color(LDL::Graphics::Color(r, g, b, a));

	return true;
}
