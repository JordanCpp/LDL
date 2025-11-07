// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_Renderer.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Texture.hpp>

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
	void* memory = LDL_malloc(sizeof(SDL_Texture));

	SDL_Texture* texture = new(memory) SDL_Texture(&renderer->GetRenderContext(), format, Vec2u(w, h));

	return texture;
}

void SDL_DestroyTexture(SDL_Texture* texture)
{
	delete texture;
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
	void* memory = LDL_malloc(sizeof(SDL_Texture));

	SDL_Texture* texture = new(memory) SDL_Texture(&renderer->GetRenderContext(), (SDL_SurfaceDetail*)surface);

	return texture;
}

bool SDL_RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_FRect* srcrect, const SDL_FRect* dstrect)
{
	Vec2u srcPos;
	Vec2u srcSize;

	Vec2u dstPos;
	Vec2u dstSize;

	if (srcrect == NULL)
	{
		srcPos  = Vec2u(0, 0);
		srcSize = texture->GetTexture().Size();
	}
	else
	{
		srcPos  = Vec2u((uint32_t)srcrect->x, (uint32_t)srcrect->y);
		srcSize = Vec2u((uint32_t)srcrect->w, (uint32_t)srcrect->h);
	}

	if (dstrect == NULL)
	{
		dstPos  = Vec2u(0, 0);
		dstSize = texture->GetTexture().Size();
	}
	else
	{
		dstPos  = Vec2u((uint32_t)dstrect->x, (uint32_t)dstrect->y);
		dstSize = Vec2u((uint32_t)dstrect->w, (uint32_t)dstrect->h);
	}

	renderer->GetRender().Draw(&texture->GetTexture(), dstPos, dstSize, srcPos, srcSize);

	return true;
}
