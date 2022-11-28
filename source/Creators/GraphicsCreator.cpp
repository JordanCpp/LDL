#include <LDL/Creators/GraphicsCreator.hpp>
#include "../Graphics/GL1/GL1Render.hpp"
#include "../Platforms/Windows/Graphics/GL1/GL1Window.hpp"
#include "../Platforms/Windows/Graphics/Cpu/CpuWindow.hpp"
#include <assert.h>

LDL::Creators::GraphicsCreator::GraphicsCreator() :
	_GpuWindow(NULL),
	_GpuRender(NULL),
	_CpuWindow(NULL)
{
}

LDL::Creators::GraphicsCreator::~GraphicsCreator()
{
	delete _CpuWindow;
	delete _GpuRender;
	delete _GpuWindow;
}

LDL::Graphics::IGpuWindow* LDL::Creators::GraphicsCreator::CreateGpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode)
{
	assert(_GpuWindow == NULL);

	_GpuWindow = new LDL::Graphics::Windows::GL1Window(pos, size, title, mode);

	return _GpuWindow;
}

LDL::Graphics::ICpuWindow* LDL::Creators::GraphicsCreator::CreateCpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode)
{
	assert(_CpuWindow == NULL);

	_CpuWindow = new LDL::Graphics::Windows::CpuWindow(pos, size, title, mode);

	return _CpuWindow;
}

LDL::Graphics::IGpuRender* LDL::Creators::GraphicsCreator::CreateGpuRender(LDL::Graphics::IGpuWindow* gpuWindow)
{
	assert(_GpuRender == NULL);

	_GpuRender = new LDL::Graphics::GL1Render(gpuWindow);

	return _GpuRender;
}

LDL::Graphics::IGpuImage* LDL::Creators::GraphicsCreator::CreateGpuImage(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels)
{
	return new LDL::Graphics::GL1Image(size, bytesPerPixel, pixels);
}

void LDL::Creators::GraphicsCreator::Destroy(LDL::Graphics::IGpuImage* gpuImage)
{
	delete gpuImage;
}