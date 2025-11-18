// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_Application_hpp
#define LDL_APIs_SDL3_SDL_Application_hpp

#include <LDL/Core/Vector.hpp>
#include <LDL/Core/Result.hpp>
#include <LDL/Core/RingBuffer.hpp>
#include <LDL/APIs/SDL3/SDL_events.h>
#include <LDL/APIs/SDL3/SDL_Memory.hpp>
#include <LDL/APIs/SDL3/SDL_Window.hpp>

class SDL_Application
{
public:
	enum
	{
		Max = 1024
	};
	SDL_Application();
	LDL::Result& GetResult();
	void Append(SDL_Window* window);
	LDL::Vector<SDL_Window*>& GetWindows();
	void PollEvents();
	bool PollEvent(SDL_Event& dest);
private:
	SDL_Memory                       _memory;
	LDL::Result                      _result;
	LDL::Vector<SDL_Window*>         _windows;
	LDL::RingBuffer<SDL_Event, Max> _events;
};

SDL_Application& App();

#endif
