#include <LDL/Graphics/GL1/GL1Screen.hpp>
#include <LDL/Graphics/OpenGL.hpp>

LDL::Graphics::GL1Screen::GL1Screen(const LDL::Graphics::Point2u& size) :
	_Size(size),
	_Screen(0)
{
	glGenTextures(1, (GLuint*)&_Screen);

	glBindTexture(GL_TEXTURE_2D, _Screen);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_Size.PosX(), (GLsizei)_Size.PosY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
}

LDL::Graphics::GL1Screen::~GL1Screen()
{
	glDeleteTextures(0, (GLuint*)&_Screen);
}

void LDL::Graphics::GL1Screen::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	glBindTexture(GL_TEXTURE_2D, _Screen);

	GLint x = (GLint)pos.PosX();
	GLint y = (GLint)pos.PosY();
	GLint w = (GLint)size.PosX();
	GLint h = (GLint)size.PosY();

	glBegin(GL_QUADS);
	glTexCoord2i(0, 0);
	glVertex2i(x, y + h);
	glTexCoord2i(0, 1);
	glVertex2i(x, y);
	glTexCoord2i(1, 1);
	glVertex2i(x + w, y);
	glTexCoord2i(1, 0);
	glVertex2i(x + w, y + h);
	glEnd();

	int format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, image->Size().PosX(), image->Size().PosY(), format, GL_UNSIGNED_BYTE, image->Pixels());
}

void LDL::Graphics::GL1Screen::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos)
{
	Draw(image, pos, image->Size());
}