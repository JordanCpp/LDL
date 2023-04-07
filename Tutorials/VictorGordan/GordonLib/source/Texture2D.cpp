#include "Texture2D.h"

Texture2D::Texture2D(const std::string& image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType, LDL::Loaders::ImageLoader& loader)
{
	// Assigns the type of the texture ot the texture object
	type = texType;

	loader.Load(image);

	// Generates an OpenGL texture object
	glGenTextures(1, &ID);
	// Assigns the texture to a Texture Unit
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	// Configures the type of algorithm that is used to make the image smaller or bigger
	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// Configures the way the texture repeats (if it does at all)
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
	// float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
	// glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

	// Assigns the image to the OpenGL Texture object
	glTexImage2D(texType, 0, GL_RGBA, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, format, pixelType, loader.Pixels());
	// Generates MipMaps
	glGenerateMipmap(texType);

	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
	glBindTexture(texType, 0);
}

void Texture2D::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	// Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets the value of the uniform
	glUniform1i(texUni, unit);
}

void Texture2D::Bind()
{
	glBindTexture(type, ID);
}

void Texture2D::Unbind()
{
	glBindTexture(type, 0);
}

void Texture2D::Delete()
{
	glDeleteTextures(1, &ID);
}