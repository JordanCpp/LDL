// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL2/SDL_Application.hpp>

using namespace LDL;

void EventConvertor(Event& src, SDL_Event& dst)
{
	if (src.Type == IsQuit)
	{
		dst.type = SDL_QUIT;
	}
}

static SDL_Application mainApplication;

SDL_Application& App()
{
	return mainApplication;
}

SDL_Application::SDL_Application()
{
}

Result& SDL_Application::GetResult()
{
	return _result;
}

void SDL_Application::Append(SDL_Window* window)
{
	if (window)
	{
		_windows.push_back(window);
	}
}

Vector<SDL_Window*>& SDL_Application::GetWindows()
{
	return _windows;
}

void SDL_Application::PollEvents()
{
	Event     src;
	SDL_Event dst;

	for (size_t i = 0; i < _windows.size(); i++)
	{
		SDL_Window* window = _windows[i];

		while (window->_window->GetEvent(src))
		{
			EventConvertor(src, dst);

			_events.enqueue(dst);
		}

		window->_window->PollEvents();
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
