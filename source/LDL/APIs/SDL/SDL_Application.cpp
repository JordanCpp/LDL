// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL_Memory.hpp>
#include <LDL/APIs/SDL/SDL_Application.hpp>

using namespace LDL;

static SDL_Application mainApplication;

SDL_Application& App()
{
	return mainApplication;
}

SDL_Application::SDL_Application() :
	_window(NULL),
	_render(NULL)
{
}

void SDL_Application::PollEvents()
{
	if (_window)
	{
		Event     src;
		SDL_Event dst;

		while (_window->GetEvent(src))
		{
			if (src.Type == IsQuit)
			{
				dst.type = SDL_QUIT;
			}

			_events.enqueue(dst);
		}

		_window->PollEvents();
	}
}

bool SDL_Application::PollEvent(SDL_Event& dest)
{
	if (!_events.empty())
	{
		_events.dequeue(dest);

		return true;
	}

	return false;
}
