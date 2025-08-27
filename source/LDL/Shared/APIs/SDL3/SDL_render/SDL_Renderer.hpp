// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_SDL3_SDL_Renderer_hpp
#define LDL_Shared_SDL3_SDL_Renderer_hpp

#include <SDL3/SDL_render.h>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_video/SDL_Window.hpp>

struct SDL_Renderer
{
	LDL::Render _render;
	SDL_Renderer(SDL_Window* window, const char* name);
	LDL::Render& GetRender();
};

#endif
