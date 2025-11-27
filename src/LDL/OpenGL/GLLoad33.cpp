// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL3_3.hpp>
#include <LDL/OpenGL/GLLoad33.hpp>

LDL_OpenGLLoader_3_3::LDL_OpenGLLoader_3_3(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)_functions.Function("glBindFragDataLocationIndexed");
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)_functions.Function("glGetFragDataIndex");
	glGenSamplers = (PFNGLGENSAMPLERSPROC)_functions.Function("glGenSamplers");
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)_functions.Function("glDeleteSamplers");
	glIsSampler = (PFNGLISSAMPLERPROC)_functions.Function("glIsSampler");
	glBindSampler = (PFNGLBINDSAMPLERPROC)_functions.Function("glBindSampler");
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)_functions.Function("glSamplerParameteri");
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)_functions.Function("glSamplerParameteriv");
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)_functions.Function("glSamplerParameterf");
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)_functions.Function("glSamplerParameterfv");
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)_functions.Function("glSamplerParameterIiv");
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)_functions.Function("glSamplerParameterIuiv");
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)_functions.Function("glGetSamplerParameteriv");
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)_functions.Function("glGetSamplerParameterIiv");
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)_functions.Function("glGetSamplerParameterfv");
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)_functions.Function("glGetSamplerParameterIuiv");
	glQueryCounter = (PFNGLQUERYCOUNTERPROC)_functions.Function("glQueryCounter");
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)_functions.Function("glGetQueryObjecti64v");
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)_functions.Function("glGetQueryObjectui64v");
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)_functions.Function("glVertexAttribDivisor");
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)_functions.Function("glVertexAttribP1ui");
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)_functions.Function("glVertexAttribP1uiv");
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)_functions.Function("glVertexAttribP2ui");
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)_functions.Function("glVertexAttribP2uiv");
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)_functions.Function("glVertexAttribP3ui");
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)_functions.Function("glVertexAttribP3uiv");
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)_functions.Function("glVertexAttribP4ui");
	glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)_functions.Function("glVertexAttribP4uiv");
	glVertexP2ui = (PFNGLVERTEXP2UIPROC)_functions.Function("glVertexP2ui");
	glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)_functions.Function("glVertexP2uiv");
	glVertexP3ui = (PFNGLVERTEXP3UIPROC)_functions.Function("glVertexP3ui");
	glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)_functions.Function("glVertexP3uiv");
	glVertexP4ui = (PFNGLVERTEXP4UIPROC)_functions.Function("glVertexP4ui");
	glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)_functions.Function("glVertexP4uiv");
	glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)_functions.Function("glTexCoordP1ui");
	glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)_functions.Function("glTexCoordP1uiv");
	glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)_functions.Function("glTexCoordP2ui");
	glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)_functions.Function("glTexCoordP2uiv");
	glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)_functions.Function("glTexCoordP3ui");
	glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)_functions.Function("glTexCoordP3uiv");
	glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)_functions.Function("glTexCoordP4ui");
	glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)_functions.Function("glTexCoordP4uiv");
	glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)_functions.Function("glMultiTexCoordP1ui");
	glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)_functions.Function("glMultiTexCoordP1uiv");
	glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)_functions.Function("glMultiTexCoordP2ui");
	glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)_functions.Function("glMultiTexCoordP2uiv");
	glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)_functions.Function("glMultiTexCoordP3ui");
	glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)_functions.Function("glMultiTexCoordP3uiv");
	glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)_functions.Function("glMultiTexCoordP4ui");
	glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)_functions.Function("glMultiTexCoordP4uiv");
	glNormalP3ui = (PFNGLNORMALP3UIPROC)_functions.Function("glNormalP3ui");
	glNormalP3uiv = (PFNGLNORMALP3UIVPROC)_functions.Function("glNormalP3uiv");
	glColorP3ui = (PFNGLCOLORP3UIPROC)_functions.Function("glColorP3ui");
	glColorP3uiv = (PFNGLCOLORP3UIVPROC)_functions.Function("glColorP3uiv");
	glColorP4ui = (PFNGLCOLORP4UIPROC)_functions.Function("glColorP4ui");
	glColorP4uiv = (PFNGLCOLORP4UIVPROC)_functions.Function("glColorP4uiv");
	glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)_functions.Function("glSecondaryColorP3ui");
	glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)_functions.Function("glSecondaryColorP3uiv");
}

LDL_OpenGLLoader_3_3::~LDL_OpenGLLoader_3_3()
{
}
