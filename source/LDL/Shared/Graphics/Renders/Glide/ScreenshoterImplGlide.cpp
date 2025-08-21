#include "ScreenshoterImplGlide.hpp"

using namespace LDL::Graphics;

ScreenShotterImplGlide::ScreenShotterImplGlide(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenShotterImplGlide::Shot()
{
}
