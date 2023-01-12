#include "ScreenshoterImpl.hpp"

LDL::Graphics::ScreenshoterImpl::ScreenshoterImpl(const std::string& path, const std::string& name, LDL::Graphics::Render* render, LDL::Graphics::Surface* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void LDL::Graphics::ScreenshoterImpl::Shot()
{
	_FullPath = "";

	_FullPath += _ShortPath;
	_FullPath += _Name;
	_FullPath += _BaseScreenshoter.Prefix();
	_FullPath += ".png";

	_ImageWritter.Save(_FullPath, _Render->Size(), 4, _Image->Pixels());
}