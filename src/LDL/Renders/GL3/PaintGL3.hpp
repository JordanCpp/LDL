// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL3_PaintGL3_hpp
#define LDL_Renders_GL3_PaintGL3_hpp

#include <LDL/Mat4f.hpp>
#include <LDL/Texture.hpp>
#include <LDL/OpenGL/GL3_0.hpp>
#include <LDL/Renders/GL3/ShdrGL3.hpp>

class LDL_TexturePainterOpenGL3
{
public:
	LDL_TexturePainterOpenGL3(LDL_ShaderLoaderOpenGL3* shaderLoader);
	void Draw(LDL_Mat4f proj, LDL_ITexture* texture);
private:
	LDL_ShaderLoaderOpenGL3* _shaderLoader;
	GLuint                   _shaderProgram;
	GLuint                   _vertexBufferObject;
	GLuint                   _vertexArraysObject;
	GLuint                   _elementBufferObject;
};

#endif    
