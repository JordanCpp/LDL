#ifndef Game_Engine_hpp
#define Game_Engine_hpp

#include <LDL/Creators/GraphicsCreator.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/GpuWindow.hpp>

namespace Game
{
	class Engine
	{
	public:
		Engine(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title);
		void Run();
	private:
		LDL::Allocators::FixedLinear _GraphicsAllocator;
		LDL::Creators::GraphicsCreator _Graphics;
		LDL::Allocators::FixedLinear _Allocator;
		LDL::Loaders::ImageLoader _ImageLoader;
		LDL::Graphics::GpuWindow _Window;
		LDL::Graphics::GpuRender _Render;
		LDL::Time::FpsCounter _FpsCounter;
		LDL::Core::IntegerToString _Convert;
		LDL::Time::FpsLimiter _FpsLimiter;
	};
}

#endif    