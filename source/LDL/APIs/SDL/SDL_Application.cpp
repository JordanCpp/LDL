// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL_mouse.h>
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
			else if (src.Type == IsMouseMove)
			{
				dst.type     = SDL_MOUSEMOTION;
				dst.motion.x = (Uint16)src.Mouse.PosX;
				dst.motion.y = (Uint16)src.Mouse.PosY;
			}
			else if (src.Type == IsMouseClick)
			{
				if (src.Mouse.State == ButtonState::Pressed)
				{
					dst.type = SDL_MOUSEBUTTONDOWN;
					dst.button.state = SDL_PRESSED;
				}
				else
				{
					dst.type = SDL_MOUSEBUTTONUP;
					dst.button.state = SDL_RELEASED;
				}

				if (src.Mouse.Button == MouseButton::Left)
				{
					dst.button.button = SDL_BUTTON_LEFT;
				}
				else if (src.Mouse.Button == MouseButton::Middle)
				{
					dst.button.button = SDL_BUTTON_MIDDLE;
				}
				else if (src.Mouse.Button == MouseButton::Right)
				{
					dst.button.button = SDL_BUTTON_RIGHT;
				}

				dst.button.x = (Uint16)src.Mouse.PosX;
				dst.button.y = (Uint16)src.Mouse.PosY;
			}
			else if (src.Type == IsResize)
			{
				dst.type     = SDL_VIDEORESIZE;
				dst.resize.w = src.Resize.Width;
				dst.resize.h = src.Resize.Height;
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

RenderContext& SDL_Application::GetContext()
{
	return _context;
}

Result& SDL_Application::GetResult()
{
	return _result;
}

Window* SDL_Application::GetWindow()
{
	return _window;
}

Render* SDL_Application::GetRender()
{
	return _render;
}

void SDL_Application::SetWindow(Window* window)
{
	_window = window;
}

void SDL_Application::SetRender(Render* render)
{
	_render = render;
}
