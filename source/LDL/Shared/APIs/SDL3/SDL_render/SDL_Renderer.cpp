// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_Application.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_render/SDL_Renderer.hpp>

using namespace LDL::Math;
using namespace LDL::Events;
using namespace LDL::Graphics;

SDL_Renderer::SDL_Renderer(SDL_Window* window, const char* name) :
	_render(App().GetResult(), window->GetRenderContext(), &window->GetWindow())
{
}

Render& SDL_Renderer::GetRender()
{
	return _render;
}
