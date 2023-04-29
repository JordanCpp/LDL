#ifndef Arcanum_Game_Engine_hpp
#define Arcanum_Game_Engine_hpp

#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <Arcanum/Game/Settings.hpp>
#include <Arcanum/Formats/Art.hpp>

namespace Arcanum
{
	namespace Game
	{
		class Engine
		{
		public:
			Engine(Settings* settings);
			void Run();
		private:
			Settings* _Settings;
			std::string _Title;
			LDL::Allocators::FixedLinear _ImageAllocator;
			LDL::Loaders::ImageLoader _ImageLoader;
			LDL::Graphics::Window _Window;
			LDL::Graphics::RenderContext _RenderContext;
			LDL::Graphics::Render _Render;
			LDL::Time::FpsCounter _FpsCounter;
			LDL::Core::NumberToString _Convert;
			LDL::Time::FpsLimiter _FpsLimiter;
			ArtFile _ArtFile;
			LDL::Graphics::Texture* _Texture;
		};
	}
}

#endif    