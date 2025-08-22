// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_LinePainter_hpp
#define LDL_Graphics_OpenGL3_LinePainter_hpp

#include <LDL/APIs/OpenGL/OpenGL3_0.hpp>
#include <LDL/Math/Mat4.hpp>
#include <LDL/Math/Vec3.hpp>
#include "ShaderLoaderOpenGL3.hpp"

namespace LDL
{
	namespace Graphics
	{
		class LinePainter
		{
		public:
			LinePainter(ShaderLoader* shaderLoader);
			~LinePainter();
			void Draw(Math::Mat4f proj, Math::Vec3f start, Math::Vec3f end, Math::Vec3f color);
		private:
			Math::Vec3f   _lines[2];
			Math::Vec3f   _color;
			GLuint        _shaderProgram;
			GLuint        _vertexBufferObject;
			GLuint        _vertexArraysObject;
			ShaderLoader* _shaderLoader;
		};
	}
}

#endif    
