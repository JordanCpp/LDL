
#include "SDL_Renderer.hpp"

bool SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
	LDL::Graphics::Color color = renderer->GetRender().Color();

	*r = color.r;
	*g = color.g;
	*b = color.b;
	*a = color.a;

	return true;
}
