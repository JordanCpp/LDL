#include "ScreenshoterImplSoftware.hpp"

using namespace LDL::Graphics;

ScreenShotterImplSoftware::ScreenShotterImplSoftware(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenShotterImplSoftware::Shot()
{
	_fullPath = "";

	_fullPath += _shortPath;
	_fullPath += _name;
	_fullPath += _baseScreenShotter.Prefix();
	_fullPath += ".png";

	_imageWriter.Save(_fullPath, _render->Size(), 4, _image->Pixels());
}
