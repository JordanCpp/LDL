// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_Texture_hpp
#define LDL_APIs_SDL3_SDL_Texture_hpp

#include <LDL/SDL3/SDL_render.h>
#include <LDL/Render.hpp>
#include <LDL/SDL3/SDL_Window.hpp>
#include <LDL/SDL3/SDL_Surface.hpp>

struct SDL_Texture
{
	LDL_ITexture* _texture;
	SDL_Texture(LDL_RenderContext* renderContext, size_t pixelFormat, const LDL_Vec2u& size);
	SDL_Texture(LDL_RenderContext* renderContext, SDL_SurfaceDetail* surface);
	LDL_ITexture* GetTexture();
};

#endif
