#include <LDL/Creators/GraphicsCreator.hpp>

#if (LDL_GPU_SUPPORT_OPENGL1)
#include "../Graphics/GL1/GL1Render.hpp"
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
	_GpuImages(_Allocator),
	_GpuWindow(NULL),
	_GpuRender(NULL)
{
}

LDL::Creators::GraphicsCreator::~GraphicsCreator()
{
	if (_GpuWindow)
		delete _GpuWindow;

	if (_GpuRender)
		delete _GpuRender;
}

LDL::Graphics::IGpuWindow* LDL::Creators::GraphicsCreator::CreateGpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode)
{
	assert(_GpuWindow == NULL);

#if (LDL_GPU_SUPPORT_OPENGL1)
	_GpuWindow = new LDL::Graphics::GpuWindowImpl(pos, size, title, mode);
#elif (LDL_GPU_SUPPORT_DIRECTX9)
	_GpuWindow = new LDL::Graphics::Windows::DX9Window(pos, size, title, mode);
#elif (LDL_GPU_SUPPORT_DIRECTX5)
	_GpuWindow = new LDL::Graphics::Windows::DX5Window(pos, size, title, mode);
#endif

	return _GpuWindow;
}

LDL::Graphics::IGpuRender* LDL::Creators::GraphicsCreator::CreateGpuRender(LDL::Graphics::IGpuWindow* gpuWindow)
{
	assert(_GpuRender == NULL);

#if (LDL_GPU_SUPPORT_OPENGL1)
	_GpuRender = new LDL::Graphics::GL1Render(gpuWindow);
#elif (LDL_GPU_SUPPORT_DIRECTX9)
	_GpuRender = new LDL::Graphics::DX9Render(gpuWindow);
#elif (LDL_GPU_SUPPORT_DIRECTX5)
	_GpuRender = new LDL::Graphics::DX5Render(gpuWindow);
#endif

	return _GpuRender;
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