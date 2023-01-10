#include "GpuImageImpl.hpp"

using namespace LDL::Graphics;

GpuImageImpl::GpuImageImpl(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels):
	_Id(0)
{
}

GpuImageImpl::~GpuImageImpl()
{
}

const Point2u& GpuImageImpl::Size()
{
	return _Size;
}

size_t GpuImageImpl::Id()
{
	return _Id;
}