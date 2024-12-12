#ifndef Arcanum_Game_Engine_hpp
#define Arcanum_Game_Engine_hpp

#include <Arcanum/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/CommandLineParser.hpp>
#include <Arcanum/Managers/PathManager.hpp>
#include <Arcanum/Game/Settings.hpp>
#include <Arcanum/Loaders/ArtLoader.hpp>
#include <Arcanum/Managers/SpriteManager.hpp>
#include <Arcanum/Readers/ByteReader.hpp>
#include <Arcanum/Readers/SecReader.hpp>
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
	namespace Game
	{
		class Engine
		{
		public:
			Engine(LDL::Core::CommandLineParser * commandLineParser, Settings* settings);
			void ShowFps();
			void Draw();
			void Update();
			void Run();
		private:
			LDL::Core::CommandLineParser* _CommandLineParser;
			Readers::XmlReader _XmlReader;
			Settings* _Settings;
			LDL::Graphics::RenderContext _RenderContext;
			Managers::FileManager _FileManager;
			LDL::Allocators::FixedLinear _OriginalAllocator;
			Arcanum::Allocators::ObjectAllocator _ObjectAllocator;
			Managers::PathManager _PathManager;
			std::string _Title;
			LDL::Allocators::FixedLinear _ImageAllocator;
			LDL::Loaders::ImageLoader _ImageLoader;
			LDL::Graphics::Window _Window;
			LDL::Graphics::Render _Render;
			LDL::Time::FpsCounter _FpsCounter;
			LDL::Core::NumberToString _Convert;
			LDL::Time::FpsLimiter _FpsLimiter;
			Loaders::ArtLoader _ArtLoader;
			Managers::SpriteManager _SpriteManager;
			Readers::ByteReader _ByteReader;
			Readers::SecReader _SecReader;
			Painters::LocationPainter _LocationPainter;
			Objects::LocationData _LocationData;
			Managers::WidgetManager _WidgetManager;
			Forms::GameMenu _GameMenu;
			Graphics::Camera _Camera;
			Managers::ObjectManager _ObjectManager;
			Objects::LocationCreator _LocationCreator;
			Objects::Location _Location;
			Writters::XmlWritter _XmlWritter;
			Savers::LocationSaver _LocationSaver;
			Loaders::LocationLoader _LocationLoader;
		};
	}
}

#endif    