#include "ScreenshoterImpl.hpp"

using namespace LDL::Graphics;

ScreenshoterImpl::ScreenshoterImpl(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void ScreenshoterImpl::Shot()
{
}