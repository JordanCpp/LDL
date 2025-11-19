// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_TexturePainter_hpp
#define LDL_Graphics_OpenGL3_TexturePainter_hpp

#include <LDL/Mat4.hpp>
#include <LDL/Texture.hpp>
#include <LDL/OpenGL/OpenGL3_0.hpp>
#include <LDL/Renders/OpenGL3/ShaderLoaderOpenGL3.hpp>

class TexturePainter
{
public:
	TexturePainter(ShaderLoader* shaderLoader);
	void Draw(Mat4f proj, LDL_ITexture* texture);
private:
	ShaderLoader* _shaderLoader;
	GLuint        _shaderProgram;
	GLuint        _vertexBufferObject;
	GLuint        _vertexArraysObject;
	GLuint        _elementBufferObject;
};

#endif    
