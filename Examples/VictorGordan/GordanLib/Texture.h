#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <LDL/Loaders/ImageLoader.hpp>
#include "shaderClass.h"

class TextureGL
{
public:
	GLuint ID;
	GLenum type;
	TextureGL(LDL::ImageLoader& loader, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	// Assigns a texture unit to a texture
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
};
#endif