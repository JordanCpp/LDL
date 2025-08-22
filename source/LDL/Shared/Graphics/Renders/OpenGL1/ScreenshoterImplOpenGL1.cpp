#include "ScreenshoterImplOpenGL1.hpp"
#include <LDL/APIs/OpenGL/OpenGL1_0.hpp>
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;

ScreenShotterImplOpenGL1::ScreenShotterImplOpenGL1(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenShotterImplOpenGL1::Shot()
{
	GL_CHECK(glPixelStorei(GL_PACK_ALIGNMENT, 1));
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_image->Size().x, (GLsizei)_image->Size().y, GL_RGBA, GL_UNSIGNED_BYTE, _image->Pixels()));

	_fullPath = "";

	_fullPath += _shortPath;
	_fullPath += _name;
	_fullPath += _baseScreenShotter.Prefix();
	_fullPath += ".png";

	_imageWriter.Save(_fullPath, _render->Size(), 4, _image->Pixels());
}
