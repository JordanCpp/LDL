#ifndef LDL_Creators_Graphics_hpp
#define LDL_Creators_Graphics_hpp

#include <LDL/Graphics/IGpuRender.hpp>
#include <LDL/Graphics/IGpuWindow.hpp>
#include <LDL/Graphics/ICpuWindow.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Allocators/ObjectPool.hpp>

namespace LDL
{
	namespace Creators
	{
		class GraphicsCreator
		{
		public:
			GraphicsCreator(LDL::Allocators::Allocator* allocator);
			~GraphicsCreator();
			LDL::Graphics::IGpuWindow* CreateGpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Fixed);
			LDL::Graphics::ICpuWindow* CreateCpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Fixed);
			LDL::Graphics::IGpuRender* CreateGpuRender(LDL::Graphics::IGpuWindow* gpuWindow);
			LDL::Graphics::IGpuImage* CreateGpuImage(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels);
			void Destroy(LDL::Graphics::IGpuImage* gpuImage);
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Allocators::ObjectPool<LDL::Graphics::IGpuImage*> _GpuImages;
			LDL::Graphics::IGpuWindow* _GpuWindow;
			LDL::Graphics::IGpuRender* _GpuRender;
			LDL::Graphics::ICpuWindow* _CpuWindow;
		};
	}
}

#endif    