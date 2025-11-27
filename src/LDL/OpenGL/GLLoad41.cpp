// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_1.hpp>
#include <LDL/OpenGL/GLLoad41.hpp>

LDL_OpenGLLoader_4_1::LDL_OpenGLLoader_4_1(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)_functions.Function("glReleaseShaderCompiler");
	glShaderBinary = (PFNGLSHADERBINARYPROC)_functions.Function("glShaderBinary");
	glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)_functions.Function("glGetShaderPrecisionFormat");
	glDepthRangef = (PFNGLDEPTHRANGEFPROC)_functions.Function("glDepthRangef");
	glClearDepthf = (PFNGLCLEARDEPTHFPROC)_functions.Function("glClearDepthf");
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)_functions.Function("glGetProgramBinary");
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)_functions.Function("glProgramBinary");
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)_functions.Function("glProgramParameteri");
	glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)_functions.Function("glUseProgramStages");
	glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)_functions.Function("glActiveShaderProgram");
	glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)_functions.Function("glCreateShaderProgramv");
	glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)_functions.Function("glBindProgramPipeline");
	glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)_functions.Function("glDeleteProgramPipelines");
	glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)_functions.Function("glGenProgramPipelines");
	glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)_functions.Function("glIsProgramPipeline");
	glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)_functions.Function("glGetProgramPipelineiv");
	glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)_functions.Function("glProgramUniform1i");
	glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)_functions.Function("glProgramUniform1iv");
	glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)_functions.Function("glProgramUniform1f");
	glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)_functions.Function("glProgramUniform1fv");
	glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)_functions.Function("glProgramUniform1d");
	glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)_functions.Function("glProgramUniform1dv");
	glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)_functions.Function("glProgramUniform1ui");
	glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)_functions.Function("glProgramUniform1uiv");
	glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)_functions.Function("glProgramUniform2i");
	glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)_functions.Function("glProgramUniform2iv");
	glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)_functions.Function("glProgramUniform2f");
	glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)_functions.Function("glProgramUniform2fv");
	glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)_functions.Function("glProgramUniform2d");
	glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)_functions.Function("glProgramUniform2dv");
	glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)_functions.Function("glProgramUniform2ui");
	glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)_functions.Function("glProgramUniform2uiv");
	glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)_functions.Function("glProgramUniform3i");
	glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)_functions.Function("glProgramUniform3iv");
	glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)_functions.Function("glProgramUniform3f");
	glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)_functions.Function("glProgramUniform3fv");
	glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)_functions.Function("glProgramUniform3d");
	glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)_functions.Function("glProgramUniform3dv");
	glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)_functions.Function("glProgramUniform3ui");
	glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)_functions.Function("glProgramUniform3uiv");
	glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)_functions.Function("glProgramUniform4i");
	glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)_functions.Function("glProgramUniform4iv");
	glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)_functions.Function("glProgramUniform4f");
	glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)_functions.Function("glProgramUniform4fv");
	glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)_functions.Function("glProgramUniform4d");
	glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)_functions.Function("glProgramUniform4dv");
	glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)_functions.Function("glProgramUniform4ui");
	glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)_functions.Function("glProgramUniform4uiv");
	glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)_functions.Function("glProgramUniformMatrix2fv");
	glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)_functions.Function("glProgramUniformMatrix3fv");
	glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)_functions.Function("glProgramUniformMatrix4fv");
	glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)_functions.Function("glProgramUniformMatrix2dv");
	glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)_functions.Function("glProgramUniformMatrix3dv");
	glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)_functions.Function("glProgramUniformMatrix4dv");
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)_functions.Function("glProgramUniformMatrix2x3fv");
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)_functions.Function("glProgramUniformMatrix3x2fv");
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)_functions.Function("glProgramUniformMatrix2x4fv");
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)_functions.Function("glProgramUniformMatrix4x2fv");
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)_functions.Function("glProgramUniformMatrix3x4fv");
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)_functions.Function("glProgramUniformMatrix4x3fv");
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)_functions.Function("glProgramUniformMatrix2x3dv");
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)_functions.Function("glProgramUniformMatrix3x2dv");
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)_functions.Function("glProgramUniformMatrix2x4dv");
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)_functions.Function("glProgramUniformMatrix4x2dv");
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)_functions.Function("glProgramUniformMatrix3x4dv");
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)_functions.Function("glProgramUniformMatrix4x3dv");
	glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)_functions.Function("glValidateProgramPipeline");
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)_functions.Function("glGetProgramPipelineInfoLog");
	glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)_functions.Function("glVertexAttribL1d");
	glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)_functions.Function("glVertexAttribL2d");
	glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)_functions.Function("glVertexAttribL3d");
	glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)_functions.Function("glVertexAttribL4d");
	glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)_functions.Function("glVertexAttribL1dv");
	glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)_functions.Function("glVertexAttribL2dv");
	glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)_functions.Function("glVertexAttribL3dv");
	glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)_functions.Function("glVertexAttribL4dv");
	glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)_functions.Function("glVertexAttribLPointer");
	glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)_functions.Function("glGetVertexAttribLdv");
	glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)_functions.Function("glViewportArrayv");
	glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)_functions.Function("glViewportIndexedf");
	glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)_functions.Function("glViewportIndexedfv");
	glScissorArrayv = (PFNGLSCISSORARRAYVPROC)_functions.Function("glScissorArrayv");
	glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)_functions.Function("glScissorIndexed");
	glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)_functions.Function("glScissorIndexedv");
	glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)_functions.Function("glDepthRangeArrayv");
	glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)_functions.Function("glDepthRangeIndexed");
	glGetFloati_v = (PFNGLGETFLOATI_VPROC)_functions.Function("glGetFloati_v");
	glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)_functions.Function("glGetDoublei_v");
}

LDL_OpenGLLoader_4_1::~LDL_OpenGLLoader_4_1()
{
}
