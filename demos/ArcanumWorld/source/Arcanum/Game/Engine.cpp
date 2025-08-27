// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Game/Engine.hpp>
#include <LDL/Enums/KeyboardKey.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>

using namespace LDL;
using namespace Arcanum;

Engine::Engine(CommandLineParser* commandLineParser, Settings* settings) :
	_commandLineParser(commandLineParser),
	_settings(settings),
	_renderContext(settings->Render()),
	_pathManager(settings->Path()),
	_fileManager(&_pathManager),
	_window(_result, _renderContext, Vec2u(0,0), _settings->Size(), _settings->Title().c_str(), WindowMode::Fixed),
	_render(_result, _renderContext, &_window),
	_fpsLimiter(_settings->Fps()),
	_spriteManager(&_renderContext, &_fileManager, &_artLoader, &_pathManager),
	_locationPainter(&_render, &_locationData),
	_widgetManager(_render),
	_gameMenu(_render),
	_camera(Vec2u(400, 100), _render.Size()),
	_objectManager(_objectAllocator, _spriteManager),
	_locationCreator(&_locationData, &_objectManager),
	_location(&_locationData, &_locationCreator, &_locationPainter),
	_locationSaver(&_xmlWriter),
	_locationLoader(&_xmlReader, &_locationCreator)
{
	_locationLoader.Reset("data/maps/Test.xml");
}

void Engine::ShowFps()
{
	if (_fpsCounter.Calc())
	{
		_title = _settings->Title() + " Fps: " + _convert.ToString(_fpsCounter.Fps());
		_window.Title(_title.c_str());
	}
}

void Engine::Draw()
{
}

void Engine::Update()
{
}

void Engine::Run()
{
	Event report = { 0 };

	while (_window.Running())
	{
		_fpsLimiter.Mark();
		_fpsCounter.Start();

		while (_window.GetEvent(report))
		{
			if (report.Type == IsQuit || report.IsKeyPressed(KeyboardKey::Escape))
			{
				_window.StopEvent();
			}
		}

		_render.Begin();

		_render.Color(Color(0, 0, 0));
		_render.Clear();

		_location.Draw(_camera.Pos());

		_gameMenu.Draw();

		_render.End();

		_camera.Handle(report);

		_fpsLimiter.Throttle();

		ShowFps();

		_window.PollEvents();
	}
}
