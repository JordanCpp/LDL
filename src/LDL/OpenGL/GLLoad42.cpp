// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_2.hpp>
#include <LDL/OpenGL/GLLoad42.hpp>

LDL_OpenGLLoader_4_2::LDL_OpenGLLoader_4_2(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)_functions.Function("glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)_functions.Function("glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)_functions.Function("glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)_functions.Function("glGetInternalformativ");
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)_functions.Function("glGetActiveAtomicCounterBufferiv");
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)_functions.Function("glBindImageTexture");
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)_functions.Function("glMemoryBarrier");
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)_functions.Function("glTexStorage1D");
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)_functions.Function("glTexStorage2D");
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)_functions.Function("glTexStorage3D");
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)_functions.Function("glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)_functions.Function("glDrawTransformFeedbackStreamInstanced");
}

LDL_OpenGLLoader_4_2::~LDL_OpenGLLoader_4_2()
{
}
