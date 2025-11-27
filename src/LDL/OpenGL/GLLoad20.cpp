// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL2_0.hpp>
#include <LDL/OpenGL/GLLoad20.hpp>

LDL_OpenGLLoader_2_0::LDL_OpenGLLoader_2_0(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)_functions.Function("glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)_functions.Function("glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)_functions.Function("glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)_functions.Function("glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)_functions.Function("glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)_functions.Function("glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)_functions.Function("glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)_functions.Function("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)_functions.Function("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)_functions.Function("glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)_functions.Function("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)_functions.Function("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)_functions.Function("glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)_functions.Function("glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)_functions.Function("glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)_functions.Function("glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)_functions.Function("glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)_functions.Function("glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)_functions.Function("glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)_functions.Function("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)_functions.Function("glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)_functions.Function("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)_functions.Function("glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)_functions.Function("glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)_functions.Function("glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)_functions.Function("glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)_functions.Function("glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)_functions.Function("glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)_functions.Function("glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)_functions.Function("glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)_functions.Function("glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)_functions.Function("glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)_functions.Function("glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)_functions.Function("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)_functions.Function("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)_functions.Function("glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)_functions.Function("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)_functions.Function("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)_functions.Function("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)_functions.Function("glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)_functions.Function("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)_functions.Function("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)_functions.Function("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)_functions.Function("glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)_functions.Function("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)_functions.Function("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)_functions.Function("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)_functions.Function("glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)_functions.Function("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)_functions.Function("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)_functions.Function("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)_functions.Function("glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)_functions.Function("glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)_functions.Function("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)_functions.Function("glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)_functions.Function("glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)_functions.Function("glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)_functions.Function("glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)_functions.Function("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)_functions.Function("glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)_functions.Function("glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)_functions.Function("glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)_functions.Function("glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)_functions.Function("glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)_functions.Function("glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)_functions.Function("glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)_functions.Function("glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)_functions.Function("glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)_functions.Function("glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)_functions.Function("glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)_functions.Function("glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)_functions.Function("glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)_functions.Function("glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)_functions.Function("glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)_functions.Function("glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)_functions.Function("glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)_functions.Function("glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)_functions.Function("glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)_functions.Function("glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)_functions.Function("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)_functions.Function("glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)_functions.Function("glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)_functions.Function("glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)_functions.Function("glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)_functions.Function("glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)_functions.Function("glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)_functions.Function("glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)_functions.Function("glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)_functions.Function("glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)_functions.Function("glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)_functions.Function("glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)_functions.Function("glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)_functions.Function("glVertexAttribPointer");
}

LDL_OpenGLLoader_2_0::~LDL_OpenGLLoader_2_0()
{
}
