// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Game_Engine_hpp
#define Arcanum_Game_Engine_hpp

#include <LDL/LDL.hpp>
#include <Arcanum/Core/RuntimeError.hpp>
#include <Arcanum/Core/CommandLineParser.hpp>
#include <Arcanum/Game/Settings.hpp>
#include <Arcanum/Loaders/ArtLoader.hpp>
#include <Arcanum/Managers/SpriteManager.hpp>
#include <Arcanum/Readers/ByteReader.hpp>
#include <Arcanum/Painters/LocationPainter.hpp>
#include <Arcanum/Managers/WidgetManager.hpp>
#include <Arcanum/Forms/GameMenu.hpp>
#include <Arcanum/Graphics/Camera.hpp>
#include <Arcanum/Allocators/ObjectAllocator.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>
#include <Arcanum/Objects/Location.hpp>
#include <Arcanum/Savers/LocationSaver.hpp>
#include <Arcanum/Objects/LocationCreator.hpp>
#include <Arcanum/Loaders/LocationLoader.hpp>
#include <Arcanum/Managers/FileManager.hpp>

namespace Arcanum
{
	class Engine
	{
	public:
		Engine(CommandLineParser* commandLineParser, Settings* settings);
		void ShowFps();
		void Draw();
		void Update();
		void Run();
	private:
		LDL::Result        _result;
		CommandLineParser* _commandLineParser;
		XmlReader          _xmlReader;
		Settings*          _settings;
		LDL::RenderContext _renderContext;
		PathManager        _pathManager;
		FileManager        _fileManager;
		ObjectAllocator    _objectAllocator;
		std::string        _title;
		LDL::Window        _window;
		LDL::Render        _render;
		LDL::FpsCounter    _fpsCounter;
		LDL::Convert       _convert;
		LDL::FpsLimiter    _fpsLimiter;
		ArtLoader          _artLoader;
		SpriteManager      _spriteManager;
		ByteReader         _byteReader;
		LocationPainter    _locationPainter;
		LocationData       _locationData;
		WidgetManager      _widgetManager;
		GameMenu           _gameMenu;
		Camera             _camera;
		ObjectManager      _objectManager;
		LocationCreator    _locationCreator;
		Location           _location;
		XmlWriter          _xmlWriter;
		LocationSaver      _locationSaver;
		LocationLoader     _locationLoader;
	};
}

#endif 
