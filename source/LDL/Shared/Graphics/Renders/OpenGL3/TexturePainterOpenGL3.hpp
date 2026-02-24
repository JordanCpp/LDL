// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_TexturePainter_hpp
#define LDL_Graphics_OpenGL3_TexturePainter_hpp

#include <LDL/APIs/OpenGL/OpenGL3_0.hpp>
#include "ShaderLoaderOpenGL3.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Math/Mat4.hpp>

namespace LDL
{
	class TexturePainter
	{
	public:
		TexturePainter(ShaderLoader* shaderLoader);
		void Draw(Mat4f proj, Texture* texture);
	private:
		ShaderLoader* _shaderLoader;
		GLuint        _shaderProgram;
		GLuint        _vertexBufferObject;
		GLuint        _vertexArraysObject;
		GLuint        _elementBufferObject;
	};
}

#endif    
