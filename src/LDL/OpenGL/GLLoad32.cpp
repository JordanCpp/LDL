// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL3_2.hpp>
#include <LDL/OpenGL/GLLoad32.hpp>

LDL_OpenGLLoader_3_2::LDL_OpenGLLoader_3_2(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)_functions.Function("glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)_functions.Function("glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)_functions.Function("glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)_functions.Function("glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)_functions.Function("glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)_functions.Function("glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)_functions.Function("glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)_functions.Function("glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)_functions.Function("glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)_functions.Function("glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)_functions.Function("glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)_functions.Function("glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)_functions.Function("glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)_functions.Function("glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)_functions.Function("glFramebufferTexture");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)_functions.Function("glTexImage2DMultisample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)_functions.Function("glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)_functions.Function("glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)_functions.Function("glSampleMaski");
}

LDL_OpenGLLoader_3_2::~LDL_OpenGLLoader_3_2()
{
}
