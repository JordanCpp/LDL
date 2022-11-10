#include <LDL/Graphics/GL1/GL1Screenshoter.hpp>
#include <LDL/Graphics/OpenGL.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../dependencies/stb/stb_image_write.h"  

LDL::Graphics::GL1Screenshoter::GL1Screenshoter(const std::string& path, const std::string& name, LDL::Graphics::GL1Render* render, LDL::Graphics::CpuImage* image) :
	_ShortPath(path),
	_Name(name),
	_Render(render),
	_Image(image)
{
}

void LDL::Graphics::GL1Screenshoter::Shot()
{
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, (GLsizei)_Image->Size().PosX(), (GLsizei)_Image->Size().PosY(), GL_RGBA, GL_UNSIGNED_BYTE, _Image->Pixels());

	_FullPath = "";

	_FullPath += _ShortPath;
	_FullPath += _Name;
	_FullPath += _BaseScreenshoter.Prefix();
	_FullPath += ".png";

	stbi_flip_vertically_on_write(true);

	stbi_write_png(_FullPath.c_str(), (int)_Render->Size().PosX(), (int)_Render->Size().PosY(), 4, _Image->Pixels(), (int)_Render->Size().PosX() * 4);
}