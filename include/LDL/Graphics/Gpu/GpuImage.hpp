#ifndef LDL_Graphics_Gpu_GpuImage_hpp
#define LDL_Graphics_Gpu_GpuImage_hpp

#if defined(LDL_GPU_SUPPORT_OPENGL1)
#include <LDL/Graphics/GL1/GL1Image.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::GL1Image GpuImage;
	}
}
#elif defined(LDL_GPU_SUPPORT_DIRECTX9)
#include <LDL/Graphics/DX9/DX9Image.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::DX9Image GpuImage;
	}
}
#elif defined(LDL_GPU_SUPPORT_DIRECTX5)
#include <LDL/Graphics/DX5/DX5Image.hpp>
namespace LDL
{
	namespace Graphics
	{
		typedef LDL::Graphics::DX5Image GpuImage;
	}
}
#else
#error Not implementation: Graphics::GpuWindow
#endif

#endif 