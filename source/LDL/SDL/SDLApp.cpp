// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL/SDL_mouse.h>
#include <LDL/SDL/SDLApp.hpp>

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
		LDL_Event     src;
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
				if (src.Mouse.State == LDL_ButtonState::Pressed)
				{
					dst.type = SDL_MOUSEBUTTONDOWN;
					dst.button.state = SDL_PRESSED;
				}
				else
				{
					dst.type = SDL_MOUSEBUTTONUP;
					dst.button.state = SDL_RELEASED;
				}

				if (src.Mouse.Button == LDL_MouseButton::Left)
				{
					dst.button.button = SDL_BUTTON_LEFT;
				}
				else if (src.Mouse.Button == LDL_MouseButton::Middle)
				{
					dst.button.button = SDL_BUTTON_MIDDLE;
				}
				else if (src.Mouse.Button == LDL_MouseButton::Right)
				{
					dst.button.button = SDL_BUTTON_RIGHT;
				}

				dst.button.x = (Uint16)src.Mouse.PosX;
				dst.button.y = (Uint16)src.Mouse.PosY;
			}
			else if (src.Type == IsResize)
			{
				dst.type     = SDL_VIDEORESIZE;
				dst.resize.w = (int)src.Resize.Width;
				dst.resize.h = (int)src.Resize.Height;
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

LDL_RenderContext& SDL_Application::GetContext()
{
	return _context;
}

LDL_Result& SDL_Application::GetResult()
{
	return _result;
}

LDL_IWindow* SDL_Application::GetWindow()
{
	return _window;
}

LDL_IRender* SDL_Application::GetRender()
{
	return _render;
}

void SDL_Application::SetWindow(LDL_IWindow* window)
{
	_window = window;
}

void SDL_Application::SetRender(LDL_IRender* render)
{
	_render = render;
}
