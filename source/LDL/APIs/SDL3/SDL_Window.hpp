// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_Window_hpp
#define LDL_APIs_SDL3_SDL_Window_hpp

#include <LDL/APIs/SDL3/SDL_video.h>
#include <LDL/Core/Result.hpp>
#include <LDL/Graphics/Window.hpp>

struct SDL_Window
{
	SDL_Window(LDL::Result& result, const char* title, int w, int h, SDL_WindowFlags flags);
	~SDL_Window();
	LDL::IWindow* GetWindow();
	LDL::RenderContext& GetRenderContext();
	LDL::Result&       _result;
	LDL::RenderContext _context;
	LDL::IWindow*   _window;
};

#endif
