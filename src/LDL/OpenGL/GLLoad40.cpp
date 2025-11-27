// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_0.hpp>
#include <LDL/OpenGL/GLLoad40.hpp>

LDL_OpenGLLoader_4_0::LDL_OpenGLLoader_4_0(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)_functions.Function("glMinSampleShading");
	glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)_functions.Function("glBlendEquationi");
	glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)_functions.Function("glBlendEquationSeparatei");
	glBlendFunci = (PFNGLBLENDFUNCIPROC)_functions.Function("glBlendFunci");
	glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)_functions.Function("glBlendFuncSeparatei");
	glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)_functions.Function("glDrawArraysIndirect");
	glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)_functions.Function("glDrawElementsIndirect");
	glUniform1d = (PFNGLUNIFORM1DPROC)_functions.Function("glUniform1d");
	glUniform2d = (PFNGLUNIFORM2DPROC)_functions.Function("glUniform2d");
	glUniform3d = (PFNGLUNIFORM3DPROC)_functions.Function("glUniform3d");
	glUniform4d = (PFNGLUNIFORM4DPROC)_functions.Function("glUniform4d");
	glUniform1dv = (PFNGLUNIFORM1DVPROC)_functions.Function("glUniform1dv");
	glUniform2dv = (PFNGLUNIFORM2DVPROC)_functions.Function("glUniform2dv");
	glUniform3dv = (PFNGLUNIFORM3DVPROC)_functions.Function("glUniform3dv");
	glUniform4dv = (PFNGLUNIFORM4DVPROC)_functions.Function("glUniform4dv");
	glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)_functions.Function("glUniformMatrix2dv");
	glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)_functions.Function("glUniformMatrix3dv");
	glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)_functions.Function("glUniformMatrix4dv");
	glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)_functions.Function("glUniformMatrix2x3dv");
	glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)_functions.Function("glUniformMatrix2x4dv");
	glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)_functions.Function("glUniformMatrix3x2dv");
	glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)_functions.Function("glUniformMatrix3x4dv");
	glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)_functions.Function("glUniformMatrix4x2dv");
	glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)_functions.Function("glUniformMatrix4x3dv");
	glGetUniformdv = (PFNGLGETUNIFORMDVPROC)_functions.Function("glGetUniformdv");
	glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)_functions.Function("glGetSubroutineUniformLocation");
	glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)_functions.Function("glGetSubroutineIndex");
	glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)_functions.Function("glGetActiveSubroutineUniformiv");
	glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)_functions.Function("glGetActiveSubroutineUniformName");
	glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)_functions.Function("glGetActiveSubroutineName");
	glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)_functions.Function("glUniformSubroutinesuiv");
	glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)_functions.Function("glGetUniformSubroutineuiv");
	glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)_functions.Function("glGetProgramStageiv");
	glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)_functions.Function("glPatchParameteri");
	glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)_functions.Function("glPatchParameterfv");
	glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)_functions.Function("glBindTransformFeedback");
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)_functions.Function("glDeleteTransformFeedbacks");
	glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)_functions.Function("glGenTransformFeedbacks");
	glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)_functions.Function("glIsTransformFeedback");
	glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)_functions.Function("glPauseTransformFeedback");
	glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)_functions.Function("glResumeTransformFeedback");
	glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)_functions.Function("glDrawTransformFeedback");
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)_functions.Function("glDrawTransformFeedbackStream");
	glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)_functions.Function("glBeginQueryIndexed");
	glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)_functions.Function("glEndQueryIndexed");
	glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)_functions.Function("glGetQueryIndexediv");
}

LDL_OpenGLLoader_4_0::~LDL_OpenGLLoader_4_0()
{
}
