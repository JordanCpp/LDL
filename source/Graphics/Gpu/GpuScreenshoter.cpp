#include <LDL/Graphics/Gpu/GpuScreenshoter.hpp>
#include "../GL1/GpuScreenshoterImpl.hpp"

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