// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_SDL3_SDLRndr_hpp
#define LDL_SDL3_SDLRndr_hpp

#include <LDL/Render.hpp>
#include <LDL/SDL3/render.h>
#include <LDL/SDL3/SDLWin.hpp>

struct SDL_Renderer
{
public:
	SDL_Renderer(SDL_Window* window, const char* name);
	LDL_IRender* GetRender();
	LDL_RenderContext& GetRenderContext();
private:
	LDL_IRender*       _render;
	LDL_RenderContext& _renderContext;
};

#endif
