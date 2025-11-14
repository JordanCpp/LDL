// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_Application_hpp
#define LDL_APIs_SDL_SDL_Application_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/RingBuffer.hpp>
#include <LDL/APIs/SDL/SDL_video.h>
#include <LDL/APIs/SDL/SDL_events.h>
#include <LDL/APIs/SDL/SDL_Memory.hpp>

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
	LDL::RenderContext& GetContext();
	LDL::Result& GetResult();
	LDL::Window* GetWindow();
	LDL::Render* GetRender();
	void SetWindow(LDL::Window* window);
	void SetRender(LDL::Render* render);
private:
	SDL_Memory                       _memory;
	LDL::RenderContext               _context;
	LDL::Result                      _result;
	LDL::Window*                     _window;
	LDL::Render*                     _render;
	LDL::ring_buffer<SDL_Event, Max> _events;
};

SDL_Application& App();

#endif
