// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_Application_hpp
#define LDL_APIs_SDL_SDL_Application_hpp

#include <LDL/Result.hpp>
#include <LDL/Render.hpp>
#include <LDL/Window.hpp>
#include <LDL/RingBuffer.hpp>
#include <LDL/SDL/SDL_video.h>
#include <LDL/SDL/SDL_events.h>
#include <LDL/SDL/SDLMem.hpp>

class SDL_Application
{
public:
	enum
	{
		Max = 1024
	};
	SDL_Application();
	void PollEvents();
	bool PollEvent(SDL_Event& dest);
	LDL_RenderContext& GetContext();
	LDL_Result& GetResult();
	LDL_IWindow* GetWindow();
	LDL_IRender* GetRender();
	void SetWindow(LDL_IWindow* window);
	void SetRender(LDL_IRender* render);
private:
	SDL_Memory                       _memory;
	LDL_RenderContext               _context;
	LDL_Result                      _result;
	LDL_IWindow*                     _window;
	LDL_IRender*                     _render;
	LDL_RingBuffer<SDL_Event, Max> _events;
};

SDL_Application& App();

#endif
