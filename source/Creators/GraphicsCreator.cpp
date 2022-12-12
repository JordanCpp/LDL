#include <LDL/Creators/GraphicsCreator.hpp>

#if (LDL_GPU_SUPPORT_OPENGL1)
#include "../Graphics/GL1/GpuRenderImpl.hpp"
#include "../Platforms/Windows/Graphics/GL1/GpuWindowImpl.hpp"
#include "../Platforms/Windows/Graphics/Cpu/CpuWindowImpl.hpp"
#elif (LDL_GPU_SUPPORT_DIRECTX9)
#include "../Graphics/DX9/DX9Render.hpp"
#include "../Platforms/Windows/Graphics/DX9/DX9Window.hpp"
#include "../Graphics/DX9/DX9Image.hpp"
#include "../Platforms/Windows/Graphics/Cpu/CpuWindow.hpp"
#elif (LDL_GPU_SUPPORT_DIRECTX5)
#include "../Graphics/DX5/DX5Render.hpp"
#include "../Platforms/Windows/Graphics/DX5/DX5Window.hpp"
#include "../Graphics/DX5/DX5Image.hpp"
#include "../Platforms/Windows/Graphics/Cpu/CpuWindow.hpp"
#else
#error Not implementation: GraphicsCreator
#endif

#include <assert.h>

LDL::Creators::GraphicsCreator::GraphicsCreator(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator),
	_GpuImages(_Allocator)
{
}

LDL::Creators::GraphicsCreator::~GraphicsCreator()
{
}

LDL::Graphics::IGpuImage* LDL::Creators::GraphicsCreator::CreateGpuImage(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels)
{

#if (LDL_GPU_SUPPORT_OPENGL1)
	return new LDL::Graphics::GL1Image(size, bytesPerPixel, pixels);
#elif (LDL_GPU_SUPPORT_DIRECTX9)
	return new LDL::Graphics::DX9Image(size, bytesPerPixel, pixels);
#elif (LDL_GPU_SUPPORT_DIRECTX5)
	return new LDL::Graphics::DX5Image(size, bytesPerPixel, pixels);
#endif

}

void LDL::Creators::GraphicsCreator::Destroy(LDL::Graphics::IGpuImage* gpuImage)
{
	assert(gpuImage != NULL);

	_GpuImages.Free((LDL::Graphics::IGpuImage**)gpuImage);

	delete gpuImage;
}