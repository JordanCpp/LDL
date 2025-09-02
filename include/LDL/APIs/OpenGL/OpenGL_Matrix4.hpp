// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_OpenGL_Matrix4_hpp
#define LDL_OpenGL_Matrix4_hpp

#include <LDL/Math/Matrix4.hpp>

namespace LDL
{
	namespace Math
	{
		typedef Matrix4<GLdouble> MatrixGLDouble;
		typedef Matrix4<GLfloat>  MatrixGLFloat;
	}
}

#endif     
