// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL2_SDL_Window_hpp
#define LDL_APIs_SDL2_SDL_Window_hpp

#include <LDL/Core/Result.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/SDL2/SDL_video.h>

struct SDL_Window
{
	SDL_Window(LDL::Result& result, const char* title, int x, int y, int w, int h, Uint32 flags);
	~SDL_Window();
	LDL::Window& GetWindow();
	LDL::RenderContext& GetRenderContext();
	LDL::Result&       _result;
	LDL::RenderContext _context;
	LDL::Window        _window;
};

#endif
