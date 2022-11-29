#include "DX5Screenshoter.hpp"

LDL::Graphics::DX5Screenshoter::DX5Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::IGpuRender* render, LDL::Graphics::CpuImage* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void LDL::Graphics::DX5Screenshoter::Shot()
{
}