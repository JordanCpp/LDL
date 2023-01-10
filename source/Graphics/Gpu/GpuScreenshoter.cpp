#include <LDL/Graphics/Gpu/GpuScreenshoter.hpp>

#ifdef LDL_GPU_SUPPORT_OPENGL1
#include "../GL1/GpuScreenshoterImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX1
#include "../DirectDraw1/GpuScreenshoterImpl.hpp"
#endif

using namespace LDL::Graphics;

GpuScreenshoter::GpuScreenshoter(const std::string& path, const std::string& name, GpuRender* render, CpuImage* image) :
	_GpuScreenshoterImpl(new GpuScreenshoterImpl(path, name, render, image))
{
}

GpuScreenshoter::~GpuScreenshoter()
{
	delete _GpuScreenshoterImpl;
}

void GpuScreenshoter::Shot()
{
	_GpuScreenshoterImpl->Shot();
}