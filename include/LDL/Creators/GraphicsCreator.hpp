#ifndef LDL_Creators_Graphics_hpp
#define LDL_Creators_Graphics_hpp

#include <LDL/Graphics/GpuWindow.hpp>
#include <LDL/Graphics/GpuRender.hpp>
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
			LDL::Graphics::IGpuImage* CreateGpuImage(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels);
			void Destroy(LDL::Graphics::IGpuImage* gpuImage);
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Allocators::ObjectPool<LDL::Graphics::IGpuImage*> _GpuImages;
		};
	}
}

#endif    