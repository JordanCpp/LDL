#include "GpuScreenshoterImpl.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>

LDL::Graphics::GpuScreenshoterImpl::GpuScreenshoterImpl(const std::string& path, const std::string& name, LDL::Graphics::GpuRender* render, LDL::Graphics::CpuImage* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void LDL::Graphics::GpuScreenshoterImpl::Shot()
{
}