#include <LDL/Graphics/DX9/DX9Screenshoter.hpp>

LDL::Graphics::DX9Screenshoter::DX9Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::DX9Render* render, LDL::Graphics::CpuImage* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void LDL::Graphics::DX9Screenshoter::Shot()
{
}