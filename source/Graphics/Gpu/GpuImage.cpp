#include <LDL/Graphics/Gpu/GpuImage.hpp>
#include "../GL1/GpuImageImpl.hpp"

using namespace LDL::Graphics;

GpuImage::GpuImage(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels) :
	_GpuImageImpl(new GpuImageImpl(size, bytesPerPixel, pixels))
{
}

GpuImage::~GpuImage()
{
	delete _GpuImageImpl;
}

const Point2u& GpuImage::Size()
{
	return _GpuImageImpl->Size();
}

size_t GpuImage::Id()
{
	return _GpuImageImpl->Id();
}