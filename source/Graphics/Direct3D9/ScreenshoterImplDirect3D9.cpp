#include "ScreenshoterImplDirect3D9.hpp"

using namespace LDL::Graphics;

ScreenshoterImplDirect3D9::ScreenshoterImplDirect3D9(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void ScreenshoterImplDirect3D9::Shot()
{
}