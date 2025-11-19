// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_LinePainter_hpp
#define LDL_Graphics_OpenGL3_LinePainter_hpp

#include <LDL/OpenGL/OpenGL3_0.hpp>
#include <LDL/Mat4.hpp>
#include <LDL/Vec3.hpp>
#include "ShaderLoaderOpenGL3.hpp"

class LinePainter
{
public:
	LinePainter(ShaderLoader* shaderLoader);
	~LinePainter();
	void Draw(Mat4f proj, Vec3f start, Vec3f end, Vec3f color);
private:
	Vec3f   _lines[2];
	Vec3f   _color;
	GLuint        _shaderProgram;
	GLuint        _vertexBufferObject;
	GLuint        _vertexArraysObject;
	ShaderLoader* _shaderLoader;
};

#endif    
