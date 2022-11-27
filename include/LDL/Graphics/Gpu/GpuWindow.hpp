#ifndef LDL_Graphics_Gpu_GpuWindow_hpp
#define LDL_Graphics_Gpu_GpuWindow_hpp

#if defined(LDL_GPU_SUPPORT_OPENGL1)
#include <LDL/Graphics/GL1/GL1Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::GL1Window GpuWindow;
	}
}
#elif defined(LDL_GPU_SUPPORT_DIRECTX9)
#include <LDL/Graphics/DX9/DX9Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::DX9Window GpuWindow;
	}
}
#elif defined(LDL_GPU_SUPPORT_DIRECTX5)
#include <LDL/Graphics/DX5/DX5Window.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::DX5Window GpuWindow;
	}
}
#else
#error Not implementation: Graphics::GpuWindow
#endif

#endif 