// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_SDL3_SDL_Window_hpp
#define LDL_Shared_SDL3_SDL_Window_hpp

#include <SDL3/SDL_video.h>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Core/Result.hpp>
struct SDL_Window
{
	LDL::Core::Result&           _result;
	LDL::Graphics::RenderContext _context;
	LDL::Graphics::Window        _window;
	SDL_Window(LDL::Core::Result& result, const char* title, int w, int h, SDL_WindowFlags flags);
	LDL::Graphics::Window& GetWindow();
	LDL::Graphics::RenderContext& GetRenderContext();
};

#endif
