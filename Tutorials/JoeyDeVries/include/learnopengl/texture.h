#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/OpenGL/OpenGL3_3.hpp>

using namespace LDL::Loaders;

GLuint LoadTexture(const std::string& path, ImageLoader& loader)
{
    GLuint result = 0;

    glGenTextures(1, &result);
    glBindTexture(GL_TEXTURE_2D, result);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    loader.Load(path);

    GLenum format = 0;

    if (loader.BytesPerPixel() == 4)
        format = GL_RGBA;
    else
        format = GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)loader.Size().PosX(), (GLsizei)loader.Size().PosY(), 0, format, GL_UNSIGNED_BYTE, loader.Pixels());

    glGenerateMipmap(GL_TEXTURE_2D);

    return result;
}

#endif