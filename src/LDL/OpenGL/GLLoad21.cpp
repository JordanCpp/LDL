// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL2_1.hpp>
#include <LDL/OpenGL/GLLoad21.hpp>

LDL_OpenGLLoader_2_1::LDL_OpenGLLoader_2_1(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)_functions.Function("glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)_functions.Function("glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)_functions.Function("glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)_functions.Function("glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)_functions.Function("glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)_functions.Function("glUniformMatrix4x3fv");
}

LDL_OpenGLLoader_2_1::~LDL_OpenGLLoader_2_1()
{
}
