// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL1_5.hpp>
#include <LDL/OpenGL/GLLoad15.hpp>

LDL_OpenGLLoader_1_5::LDL_OpenGLLoader_1_5(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glGenQueries = (PFNGLGENQUERIESPROC)_functions.Function("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)_functions.Function("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)_functions.Function("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)_functions.Function("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)_functions.Function("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)_functions.Function("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)_functions.Function("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)_functions.Function("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)_functions.Function("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)_functions.Function("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)_functions.Function("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)_functions.Function("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)_functions.Function("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)_functions.Function("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)_functions.Function("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)_functions.Function("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)_functions.Function("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)_functions.Function("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)_functions.Function("glGetBufferPointerv");
}

LDL_OpenGLLoader_1_5::~LDL_OpenGLLoader_1_5()
{
}
