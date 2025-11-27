// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_6.hpp>
#include <LDL/OpenGL/GLLoad46.hpp>

LDL_OpenGLLoader_4_6::LDL_OpenGLLoader_4_6(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)_functions.Function("glSpecializeShader");
	glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)_functions.Function("glMultiDrawArraysIndirectCount");
	glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)_functions.Function("glMultiDrawElementsIndirectCount");
	glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)_functions.Function("glPolygonOffsetClamp");
}

LDL_OpenGLLoader_4_6::~LDL_OpenGLLoader_4_6()
{
}
