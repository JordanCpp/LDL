#include "ScreenshoterImplDirect3D6.hpp"

using namespace LDL::Graphics;

ScreenshoterImplDirect3D6::ScreenshoterImplDirect3D6(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void ScreenshoterImplDirect3D6::Shot()
{
	_FullPath = "";

	_FullPath += _ShortPath;
	_FullPath += _Name;
	_FullPath += _BaseScreenshoter.Prefix();
	_FullPath += ".png";

	_ImageWritter.Save(_FullPath, _Render->Size(), 4, _Image->Pixels());
}
