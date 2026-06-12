/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include "Engine.hpp"

using namespace LDL;
using namespace Fallout;

Engine::Engine(Config& config) :
	_context(_result),
	_window(_result, _context, Vec2i(0, 0), config.Size, config.Title, config.Mode),
	_render(_result, _context, _window),
	_imageLoader(_result, _context),
	_spriteManager(_imageLoader),
	_location(_render, _spriteManager)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
	Event event;
	Vec2i pos;

	while (_window.IsRunning() && _result.IsOk())
	{
		while (_window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				_window.StopEvent();
			}

			if (event.IsKeyPressed(LDL_KeyD))
			{
				pos.x += Tile::Width;
			}

			if (event.IsKeyPressed(LDL_KeyA))
			{
				pos.x -= Tile::Width;
			}

			if (event.IsKeyPressed(LDL_KeyW))
			{
				pos.y += Tile::Width;
			}

			if (event.IsKeyPressed(LDL_KeyS))
			{
				pos.y -= Tile::Width;
			}

			_render.Begin();

			_render.SetColor(Color(255, 127, 39));
			_render.Clear();

			_location.Draw(pos);

			_render.End();
		}
	}
}
