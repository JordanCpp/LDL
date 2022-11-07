#ifndef LDL_Graphics_GpuScreenshoter_hpp
#define LDL_Graphics_GpuScreenshoter_hpp

#if defined(LDL_GPU_SUPPORT_OPENGL1)
#include <LDL/Graphics/GL1/GL1Screenshoter.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::GL1Screenshoter GpuScreenshoter;
	}
}
#elif defined(LDL_GPU_SUPPORT_DIRECTX9)
#include <LDL/Graphics/DX9/DX9Screenshoter.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::DX9Screenshoter GpuScreenshoter;
	}
}
#else
#error Not implementation: Graphics::GpuRender
#endif

#endif 