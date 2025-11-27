// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL1_2.hpp>
#include <LDL/OpenGL/GLLoad12.hpp>

LDL_OpenGLLoader_1_2::LDL_OpenGLLoader_1_2(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)_functions.Function("glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)_functions.Function("glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)_functions.Function("glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)_functions.Function("glCopyTexSubImage3D");
}

LDL_OpenGLLoader_1_2::~LDL_OpenGLLoader_1_2()
{
}
