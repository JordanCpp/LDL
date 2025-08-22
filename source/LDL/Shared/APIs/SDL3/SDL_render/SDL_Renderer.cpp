
#include "SDL_Renderer.hpp"

using namespace LDL::Math;
using namespace LDL::Events;
using namespace LDL::Graphics;

SDL_Renderer::SDL_Renderer(SDL_Window* window, const char* name) :
	_render(&window->GetRenderContext(), &window->GetWindow())
{
}

LDL::Graphics::Render& SDL_Renderer::GetRender()
{
	return _render;
}
