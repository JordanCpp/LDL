// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "SDL_Application.hpp"

using namespace LDL;

void EventConvertor(Event& src, SDL_Event& dst)
{
	if (src.Type == IsQuit)
	{
		dst.type = SDL_EVENT_QUIT;
	}
	else if (src.Type == IsMouseMove)
	{
		dst.type = SDL_EVENT_MOUSE_MOTION;
		dst.motion.x = (float)src.Mouse.PosX;
		dst.motion.y = (float)src.Mouse.PosY;
	}
}

static SDL_Application mainApplication;

SDL_Application& App()
{
	return mainApplication;
}

LDL::Result& SDL_Application::GetResult()
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

vector<SDL_Window*>& SDL_Application::GetWindows()
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

		while (window->_window.GetEvent(src))
		{
			EventConvertor(src, dst);

			_events.enqueue(dst);
		}

		window->_window.PollEvents();
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
