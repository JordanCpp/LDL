#include <LDL/Graphics/Gpu/GpuImage.hpp>
#include "../GL1/GpuImageImpl.hpp"

LDL::Graphics::GpuImage::GpuImage(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels) :
	_GpuImageImpl(new LDL::Graphics::GpuImageImpl(size, bytesPerPixel, pixels))
{
}

LDL::Graphics::GpuImage::~GpuImage()
{
	delete _GpuImageImpl;
}

const LDL::Graphics::Point2u& LDL::Graphics::GpuImage::Size()
{
	return _GpuImageImpl->Size();
}

size_t LDL::Graphics::GpuImage::Id()
{
	return _GpuImageImpl->Id();
}