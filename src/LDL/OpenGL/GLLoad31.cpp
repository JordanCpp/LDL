// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL3_1.hpp>
#include <LDL/OpenGL/GLLoad31.hpp>

LDL_OpenGLLoader_3_1::LDL_OpenGLLoader_3_1(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)_functions.Function("glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)_functions.Function("glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)_functions.Function("glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)_functions.Function("glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)_functions.Function("glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)_functions.Function("glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)_functions.Function("glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)_functions.Function("glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)_functions.Function("glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)_functions.Function("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)_functions.Function("glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)_functions.Function("glUniformBlockBinding");
}

LDL_OpenGLLoader_3_1::~LDL_OpenGLLoader_3_1()
{
}
