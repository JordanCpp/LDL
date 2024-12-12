#include "ScreenshoterImplDirect3D6.hpp"

using namespace LDL::Graphics;

ScreenshoterImplDirect3D6::ScreenshoterImplDirect3D6(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenshoterImplDirect3D6::Shot()
{
	_fullPath = "";

	_fullPath += _shortPath;
	_fullPath += _name;
	_fullPath += _baseScreenshoter.Prefix();
	_fullPath += ".png";

	_imageWritter.Save(_fullPath, _render->Size(), 4, _image->Pixels());
}
