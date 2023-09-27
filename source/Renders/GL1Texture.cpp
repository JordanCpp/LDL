#include "GL1Texture.hpp"
#include "OpenGL.hpp"
#include <LDL/OpenGL/OpenGL1_2.hpp>

LDL_GL1Texture::LDL_GL1Texture(LDL_IRenderContext* renderContext, const LDL_Vec2u& size, uint8_t* pixels, uint8_t bpp) :
	_RenderContext(renderContext),
	_Id(0)
{
	_Size = size;

	GLint format = 0;

	if (bpp == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	size_t sz = GLSelectTextureSize(_Size);

	_Quad = LDL_Vec2u(sz, sz);

	_Id = GLCreateTexture((GLsizei)_Quad.x, (GLsizei)_Quad.y, format);

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)0, (GLint)0, (GLsizei)size.x, (GLsizei)size.y, format, GL_UNSIGNED_BYTE, pixels));
}

LDL_GL1Texture::~LDL_GL1Texture()
{
	GLDeleteTexture((GLint)_Id);
}

const LDL_Vec2u& LDL_GL1Texture::Size()
{
	return _Size;
}

const LDL_Vec2u& LDL_GL1Texture::Quad()
{
	return _Quad;
}

size_t LDL_GL1Texture::Id()
{
	return _Id;
}
