// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL3_LineGL3_hpp
#define LDL_Renders_GL3_LineGL3_hpp

#include <LDL/Mat4f.hpp>
#include <LDL/Vec3f.hpp>
#include <LDL/OpenGL/GL3_0.hpp>
#include <LDL/Renders/GL3/ShdrGL3.hpp>

class LDL_LinePainterOpenGL3
{
public:
	LDL_LinePainterOpenGL3(LDL_ShaderLoaderOpenGL3* shaderLoader);
	~LDL_LinePainterOpenGL3();
	void Draw(LDL_Mat4f proj, LDL_Vec3f start, LDL_Vec3f end, LDL_Vec3f color);
private:
	LDL_Vec3f                _lines[2];
	LDL_Vec3f                _color;
	GLuint                   _shaderProgram;
	GLuint                   _vertexBufferObject;
	GLuint                   _vertexArraysObject;
	LDL_ShaderLoaderOpenGL3* _shaderLoader;
};

#endif    
