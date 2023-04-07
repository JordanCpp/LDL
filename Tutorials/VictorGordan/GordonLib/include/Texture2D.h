#ifndef TEXTURE2D_CLASS_H
#define TEXTURE2D_CLASS_H

#include <LDL/Loaders/ImageLoader.hpp>

#include "shaderClass.h"

class Texture2D
{
public:
	GLuint ID;
	GLenum type;
	Texture2D(const std::string& image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType, LDL::Loaders::ImageLoader& loader);

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