// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_Application.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Renderer.hpp>

using namespace LDL;

SDL_Renderer::SDL_Renderer(SDL_Window* window, const char* name) :
	_render(App().GetResult(), window->GetRenderContext(), &window->GetWindow()),
	_renderContext(window->GetRenderContext())
{
}

Render& SDL_Renderer::GetRender()
{
	return _render;
}

RenderContext& SDL_Renderer::GetRenderContext()
{
	return _renderContext;
}

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, const char* name)
{
	void* memory = LDL_malloc(sizeof(SDL_Renderer));

	SDL_Renderer* result = new(memory) SDL_Renderer(window, name);

	return result;
}

void SDL_DestroyRenderer(SDL_Renderer* renderer)
{
	delete renderer;
}

bool SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a)
{
	LDL::Color color = renderer->GetRender().Color();

	*r = color.r;
	*g = color.g;
	*b = color.b;
	*a = color.a;

	return true;
}

bool SDL_RenderClear(SDL_Renderer* renderer)
{
	renderer->GetRender().Clear();

	return true;
}

bool SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	renderer->GetRender().Color(LDL::Color(r, g, b, a));

	return true;
}

bool SDL_RenderPresent(SDL_Renderer* renderer)
{
	renderer->GetRender().End();

	return true;
}
