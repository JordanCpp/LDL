// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL3/SDLApp.hpp>
#include <LDL/SDL3/SDLRndr.hpp>
#include <LDL/SDL3/SDLTex.hpp>
#include <LDL/Render.hpp>
#include <LDL/Texture.hpp>

SDL_Renderer::SDL_Renderer(SDL_Window* window, const char* name) :
	_render(LDL_CreateRender(App().GetResult(), window->GetRenderContext(), window->GetWindow())),
	_renderContext(window->GetRenderContext())
{
	LDL_UNUSED(name);
}

LDL_IRender* SDL_Renderer::GetRender()
{
	return _render;
}

LDL_RenderContext& SDL_Renderer::GetRenderContext()
{
	return _renderContext;
}

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, const char* name)
{
	void* memory = SDL_malloc(sizeof(SDL_Renderer));

	SDL_Renderer* result = new(memory) SDL_Renderer(window, name);

	return result;
}

void SDL_DestroyRenderer(SDL_Renderer* renderer)
{
	renderer->~SDL_Renderer();
	SDL_free(renderer);
}

bool SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
	LDL_Color color = renderer->GetRender()->GetColor();

	*r = color.r;
	*g = color.g;
	*b = color.b;
	*a = color.a;

	return true;
}

bool SDL_RenderClear(SDL_Renderer* renderer)
{
	renderer->GetRender()->Clear();

	return true;
}

bool SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	renderer->GetRender()->SetColor(LDL_Color(r, g, b, a));

	return true;
}

bool SDL_RenderPresent(SDL_Renderer* renderer)
{
	renderer->GetRender()->End();

	return true;
}

bool SDL_RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_FRect* srcrect, const SDL_FRect* dstrect)
{
	LDL_Vec2u srcPos;
	LDL_Vec2u srcSize;

	LDL_Vec2u dstPos;
	LDL_Vec2u dstSize;

	if (srcrect == NULL)
	{
		srcPos = LDL_Vec2u(0, 0);
		srcSize = texture->GetTexture()->Size();
	}
	else
	{
		srcPos = LDL_Vec2u((uint32_t)srcrect->x, (uint32_t)srcrect->y);
		srcSize = LDL_Vec2u((uint32_t)srcrect->w, (uint32_t)srcrect->h);
	}

	if (dstrect == NULL)
	{
		dstPos = LDL_Vec2u(0, 0);
		dstSize = texture->GetTexture()->Size();
	}
	else
	{
		dstPos = LDL_Vec2u((uint32_t)dstrect->x, (uint32_t)dstrect->y);
		dstSize = LDL_Vec2u((uint32_t)dstrect->w, (uint32_t)dstrect->h);
	}

	renderer->GetRender()->Draw(texture->GetTexture(), dstPos, dstSize, srcPos, srcSize);

	return true;
}
