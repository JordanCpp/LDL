#include <LDL/Graphics/Gpu/GpuScreenshoter.hpp>
#include "../GL1/GpuScreenshoterImpl.hpp"

LDL::Graphics::GpuScreenshoter::GpuScreenshoter(const std::string& path, const std::string& name, LDL::Graphics::GpuRender* render, LDL::Graphics::CpuImage* image) :
	_GpuScreenshoterImpl(new LDL::Graphics::GpuScreenshoterImpl(path, name, render, image))
{
}

LDL::Graphics::GpuScreenshoter::~GpuScreenshoter()
{
	delete _GpuScreenshoterImpl;
}

void LDL::Graphics::GpuScreenshoter::Shot()
{
	_GpuScreenshoterImpl->Shot();
}