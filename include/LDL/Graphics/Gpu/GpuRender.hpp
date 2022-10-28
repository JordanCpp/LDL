#ifndef LDL_Graphics_GpuRender_hpp
#define LDL_Graphics_GpuRender_hpp

#if defined(LDL_GPU_SUPPORT_OPENGL1)
#include <LDL/Graphics/GL1/GL1Render.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::GL1Render GpuRender;
	}
}
#elif defined(LDL_GPU_SUPPORT_DIRECTX9)
#include <LDL/Graphics/DX9/DX9Render.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::DX9Render GpuRender;
	}
}
#else
#error Not implementation: Graphics::GpuRender
#endif

#endif 