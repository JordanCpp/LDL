#ifndef Game_Engine_hpp
#define Game_Engine_hpp

#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

namespace Game
{
	class Engine
	{
	public:
		Engine(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title);
		void Run();
	private:
		LDL::Allocators::FixedLinear _GraphicsAllocator;
		LDL::Allocators::FixedLinear _Allocator;
		LDL::Loaders::ImageLoader _ImageLoader;
		LDL::Graphics::Window _Window;
		LDL::Graphics::Render _Render;
		LDL::Time::FpsCounter _FpsCounter;
		LDL::Core::IntegerToString _Convert;
		LDL::Time::FpsLimiter _FpsLimiter;
	};
}

#endif    