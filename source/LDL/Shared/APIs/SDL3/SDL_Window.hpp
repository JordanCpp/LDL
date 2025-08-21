
#ifndef LDL_Shared_SDL3_SDL_Window_hpp
#define LDL_Shared_SDL3_SDL_Window_hpp

#include <SDL3/SDL_video.h>
#include <LDL/Graphics/Window.hpp>

struct SDL_Window
{
	LDL::Graphics::RenderContext _context;
	LDL::Graphics::Window        _window;
	SDL_Window(const char* title, int w, int h, SDL_WindowFlags flags);
	LDL::Graphics::Window& GetWindow();
	LDL::Graphics::RenderContext& GetRenderContext();
};

#endif
