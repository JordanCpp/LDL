// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL3/SDL_Renderer.hpp>
#include <LDL/APIs/SDL3/SDL_Texture.hpp>

using namespace LDL;

SDL_Texture::SDL_Texture(RenderContext* renderContext, size_t pixelFormat, const Vec2u& size) :
	_texture(renderContext, pixelFormat, size)
{
}

SDL_Texture::SDL_Texture(RenderContext* renderContext, SDL_SurfaceDetail* surface) :
	_texture(renderContext, surface->GetSurface().Format(), surface->GetSurface().Size(), surface->GetSurface().Pixels())
{
}

Texture& SDL_Texture::GetTexture()
{
	return _texture;
}

SDL_Texture* SDL_CreateTexture(SDL_Renderer* renderer, SDL_PixelFormat format, SDL_TextureAccess access, int w, int h)
{
	LDL_UNUSED(access);

	void* memory = SDL_malloc(sizeof(SDL_Texture));

	SDL_Texture* texture = new(memory) SDL_Texture(&renderer->GetRenderContext(), format, Vec2u(w, h));

	return texture;
}

void SDL_DestroyTexture(SDL_Texture* texture)
{
	texture->~SDL_Texture();
	SDL_free(texture);
}

bool SDL_GetTextureSize(SDL_Texture* texture, float* w, float* h)
{
	Vec2u size = texture->GetTexture().Size();

	*w = (float)size.x;
	*h = (float)size.y;

	return true;
}

SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface)
{
	void* memory = SDL_malloc(sizeof(SDL_Texture));

	SDL_Texture* texture = new(memory) SDL_Texture(&renderer->GetRenderContext(), (SDL_SurfaceDetail*)surface);

	return texture;
}
