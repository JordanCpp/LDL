// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_SDL3_SDL_Texture_hpp
#define LDL_Shared_SDL3_SDL_Texture_hpp

#include <SDL3/SDL_render.h>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Window.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Surface.hpp>

struct SDL_Texture
{
	LDL::Texture _texture;
	SDL_Texture(LDL::RenderContext* renderContext, size_t pixelFormat, const LDL::Vec2u& size);
	SDL_Texture(LDL::RenderContext* renderContext, SDL_SurfaceDetail* surface);
	LDL::Texture& GetTexture();
};

#endif
