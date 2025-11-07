// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_SDL3_SDL_Application_hpp
#define LDL_Shared_SDL3_SDL_Application_hpp

#include <SDL3/SDL_events.h>
#include <LDL/STL/vector.hpp>
#include <LDL/Core/Result.hpp>
#include <LDL/STL/ring_buffer.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Memory.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_Window.hpp>

class SDL_Application
{
public:
	enum
	{
		ringBufferLimit = 1024
	};
	SDL_Application();
	LDL::Result& GetResult();
	void Append(SDL_Window* window);
	LDL::vector<SDL_Window*>& GetWindows();
	void PollEvents();
	bool PollEvent(SDL_Event& dest);
private:
	SDL_Memory                                   _memory;
	LDL::Result                                  _result;
	LDL::vector<SDL_Window*>                     _windows;
	LDL::ring_buffer<SDL_Event, ringBufferLimit> _events;
};

SDL_Application& App();

#endif
