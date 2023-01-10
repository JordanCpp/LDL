#include <LDL/Graphics/Gpu/GpuImage.hpp>

#ifdef LDL_GPU_SUPPORT_OPENGL1
#include "../GL1/GpuImageImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX1
#include "../DirectDraw1/GpuImageImpl.hpp"
#endif

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