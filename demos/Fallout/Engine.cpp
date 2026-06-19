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
#include "LocationPainter.hpp"
#include "LocationReader.hpp"

using namespace LDL;
using namespace Fallout;

Engine::Engine(Config& config) :
	_context(_result, LDL::Context::Software),
	_window(_result, _context, Vec2i(0, 0), config.Size, config.Title, config.Mode),
	_render(_result, _context, _window),
	_imageLoader(_result, _context),
	_spriteManager(_imageLoader),
	_location()
{

	LocationReader reader(_result);
	reader.Load("data/Locations/test.txt", _location);
}

Engine::~Engine()
{
}

void Engine::Input(LDL::Event& event)
{
	if (event.IsKeyPressed(LDL_KeyD))
	{
		_camera.Right();
	}

	if (event.IsKeyPressed(LDL_KeyA))
	{
		_camera.Left();
	}

	if (event.IsKeyPressed(LDL_KeyW))
	{
		_camera.Up();
	}

	if (event.IsKeyPressed(LDL_KeyS))
	{
		_camera.Down();
	}
}

void Engine::Run()
{
	Event event;
	LocationPainter locationPainter(_location, _render, _spriteManager);

	while (_window.IsRunning() && _result.IsOk())
	{
		while (_window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				_window.StopEvent();
			}

			Input(event);

			_render.Begin();

			_render.SetColor(Color(255, 127, 39));
			_render.Clear();

			locationPainter.Draw(_camera.GetPos());

			_render.End();
		}
	}
}

LDL::Result& Engine::GetResult()
{
	return _result;
}
