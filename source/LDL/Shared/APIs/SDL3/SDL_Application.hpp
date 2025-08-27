// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_SDL3_SDL_Application_hpp
#define LDL_Shared_SDL3_SDL_Application_hpp

#include <LDL/STL/vector.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_video/SDL_Window.hpp>
#include <SDL3/SDL_events.h>
#include <LDL/STL/ring_buffer.hpp>
#include <LDL/Core/Result.hpp>

class SDL_Application
{
public:
	LDL::Result& GetResult();
	void Append(SDL_Window* window);
	LDL::vector<SDL_Window*>& GetWindows();
	void PollEvents();
	bool PollEvent(SDL_Event& dest);
private:
	LDL::Result                       _result;
	LDL::vector<SDL_Window*>          _windows;
	LDL::ring_buffer<SDL_Event, 1024> _events;
};

SDL_Application& App();

#endif
