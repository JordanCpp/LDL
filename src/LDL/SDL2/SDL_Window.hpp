// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL2_SDL_Window_hpp
#define LDL_APIs_SDL2_SDL_Window_hpp

#include <LDL/Result.hpp>
#include <LDL/Window.hpp>
#include <LDL/SDL2/SDL_video.h>

struct SDL_Window
{
	SDL_Window(LDL_Result& result, const char* title, int x, int y, int w, int h, Uint32 flags);
	~SDL_Window();
	LDL_IWindow* GetWindow();
	LDL_RenderContext& GetRenderContext();
	LDL_Result&       _result;
	LDL_RenderContext _context;
	LDL_IWindow*   _window;
};

#endif
