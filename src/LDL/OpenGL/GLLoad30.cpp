// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL3_0.hpp>
#include <LDL/OpenGL/GLLoad30.hpp>

LDL_OpenGLLoader_3_0::LDL_OpenGLLoader_3_0(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glColorMaski = (PFNGLCOLORMASKIPROC)_functions.Function("glColorMaski");
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)_functions.Function("glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)_functions.Function("glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)_functions.Function("glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)_functions.Function("glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)_functions.Function("glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)_functions.Function("glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)_functions.Function("glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)_functions.Function("glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)_functions.Function("glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)_functions.Function("glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)_functions.Function("glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)_functions.Function("glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)_functions.Function("glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)_functions.Function("glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)_functions.Function("glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)_functions.Function("glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)_functions.Function("glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)_functions.Function("glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)_functions.Function("glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)_functions.Function("glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)_functions.Function("glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)_functions.Function("glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)_functions.Function("glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)_functions.Function("glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)_functions.Function("glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)_functions.Function("glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)_functions.Function("glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)_functions.Function("glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)_functions.Function("glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)_functions.Function("glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)_functions.Function("glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)_functions.Function("glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)_functions.Function("glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)_functions.Function("glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)_functions.Function("glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)_functions.Function("glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)_functions.Function("glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)_functions.Function("glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)_functions.Function("glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)_functions.Function("glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)_functions.Function("glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)_functions.Function("glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)_functions.Function("glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)_functions.Function("glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)_functions.Function("glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)_functions.Function("glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)_functions.Function("glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)_functions.Function("glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)_functions.Function("glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)_functions.Function("glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)_functions.Function("glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)_functions.Function("glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)_functions.Function("glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)_functions.Function("glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)_functions.Function("glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)_functions.Function("glClearBufferfi");
	glGetStringi = (PFNGLGETSTRINGIPROC)_functions.Function("glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)_functions.Function("glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)_functions.Function("glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)_functions.Function("glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)_functions.Function("glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)_functions.Function("glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)_functions.Function("glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)_functions.Function("glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)_functions.Function("glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)_functions.Function("glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)_functions.Function("glGenFramebuffers");
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)_functions.Function("glCheckFramebufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)_functions.Function("glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)_functions.Function("glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)_functions.Function("glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)_functions.Function("glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)_functions.Function("glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)_functions.Function("glGenerateMipmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)_functions.Function("glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)_functions.Function("glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)_functions.Function("glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)_functions.Function("glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)_functions.Function("glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)_functions.Function("glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)_functions.Function("glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)_functions.Function("glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)_functions.Function("glIsVertexArray");
}

LDL_OpenGLLoader_3_0::~LDL_OpenGLLoader_3_0()
{
}
