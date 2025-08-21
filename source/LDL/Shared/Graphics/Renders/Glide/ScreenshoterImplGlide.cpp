#include "ScreenshoterImplGlide.hpp"

using namespace LDL::Graphics;

ScreenshoterImplGlide::ScreenshoterImplGlide(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenshoterImplGlide::Shot()
{
}
