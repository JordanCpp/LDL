// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_3.hpp>
#include <LDL/OpenGL/GLLoad43.hpp>

LDL_OpenGLLoader_4_3::LDL_OpenGLLoader_4_3(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)_functions.Function("glClearBufferData");
	glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)_functions.Function("glClearBufferSubData");
	glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)_functions.Function("glDispatchCompute");
	glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)_functions.Function("glDispatchComputeIndirect");
	glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)_functions.Function("glCopyImageSubData");
	glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)_functions.Function("glFramebufferParameteri");
	glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)_functions.Function("glGetFramebufferParameteriv");
	glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)_functions.Function("glGetInternalformati64v");
	glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)_functions.Function("glInvalidateTexSubImage");
	glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)_functions.Function("glInvalidateTexImage");
	glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)_functions.Function("glInvalidateBufferSubData");
	glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)_functions.Function("glInvalidateBufferData");
	glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)_functions.Function("glInvalidateFramebuffer");
	glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)_functions.Function("glInvalidateSubFramebuffer");
	glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)_functions.Function("glMultiDrawArraysIndirect");
	glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)_functions.Function("glMultiDrawElementsIndirect");
	glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)_functions.Function("glGetProgramInterfaceiv");
	glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)_functions.Function("glGetProgramResourceIndex");
	glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)_functions.Function("glGetProgramResourceName");
	glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)_functions.Function("glGetProgramResourceiv");
	glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)_functions.Function("glGetProgramResourceLocation");
	glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)_functions.Function("glGetProgramResourceLocationIndex");
	glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)_functions.Function("glShaderStorageBlockBinding");
	glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)_functions.Function("glTexBufferRange");
	glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)_functions.Function("glTexStorage2DMultisample");
	glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)_functions.Function("glTexStorage3DMultisample");
	glTextureView = (PFNGLTEXTUREVIEWPROC)_functions.Function("glTextureView");
	glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)_functions.Function("glBindVertexBuffer");
	glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)_functions.Function("glVertexAttribFormat");
	glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)_functions.Function("glVertexAttribIFormat");
	glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)_functions.Function("glVertexAttribLFormat");
	glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)_functions.Function("glVertexAttribBinding");
	glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)_functions.Function("glVertexBindingDivisor");
	glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)_functions.Function("glDebugMessageControl");
	glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)_functions.Function("glDebugMessageInsert");
	glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)_functions.Function("glDebugMessageCallback");
	glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)_functions.Function("glGetDebugMessageLog");
	glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)_functions.Function("glPushDebugGroup");
	glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)_functions.Function("glPopDebugGroup");
	glObjectLabel = (PFNGLOBJECTLABELPROC)_functions.Function("glObjectLabel");
	glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)_functions.Function("glGetObjectLabel");
	glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)_functions.Function("glObjectPtrLabel");
	glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)_functions.Function("glGetObjectPtrLabel");
}

LDL_OpenGLLoader_4_3::~LDL_OpenGLLoader_4_3()
{
}
