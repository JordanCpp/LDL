// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_Application_hpp
#define LDL_APIs_SDL3_SDL_Application_hpp

#include <LDL/PVector.hpp>
#include <LDL/Result.hpp>
#include <LDL/RingBuf.hpp>
#include <LDL/SDL3/events.h>
#include <LDL/SDL3/SDLMem.hpp>
#include <LDL/SDL3/SDLWin.hpp>

class SDL_Application
{
public:
	enum
	{
		Max = 1024
	};
	SDL_Application();
	LDL_Result& GetResult();
	void Append(SDL_Window* window);
	LDL_PodVector<SDL_Window*>& GetWindows();
	void PollEvents();
	bool PollEvent(SDL_Event& dest);
private:
	SDL_Memory                  _memory;
	LDL_Result                  _result;
	LDL_PodVector<SDL_Window*>  _windows;
	LDL_RingBuffer<SDL_Event>   _events;
};

SDL_Application& App();

#endif
