#include "ScreenshoterImpl.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include "../OpenGL/Util.hpp"

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
	GL_CHECK(glPixelStorei(GL_PACK_ALIGNMENT, 1));
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_Image->Size().PosX(), (GLsizei)_Image->Size().PosY(), GL_RGBA, GL_UNSIGNED_BYTE, _Image->Pixels()));

	_FullPath = "";

	_FullPath += _ShortPath;
	_FullPath += _Name;
	_FullPath += _BaseScreenshoter.Prefix();
	_FullPath += ".png";

	_ImageWritter.Save(_FullPath, _Render->Size(), 4, _Image->Pixels());
}