
#ifndef LDL_Shared_SDL3_SDL_Renderer_hpp
#define LDL_Shared_SDL3_SDL_Renderer_hpp

#include <LDL/Shared/APIs/SDL3/SDL_video/SDL_Window.hpp>
#include <SDL3/SDL_render.h>
#include <LDL/Graphics/Render.hpp>

struct SDL_Renderer
{
	LDL::Graphics::Render _render;
	SDL_Renderer(SDL_Window* window, const char* name);
	LDL::Graphics::Render& GetRender();
};

#endif
