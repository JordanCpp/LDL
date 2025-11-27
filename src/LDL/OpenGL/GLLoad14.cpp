// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL1_4.hpp>
#include <LDL/OpenGL/GLLoad14.hpp>

LDL_OpenGLLoader_1_4::LDL_OpenGLLoader_1_4(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)_functions.Function("glBlendFuncSeparate");
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)_functions.Function("glMultiDrawArrays");
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)_functions.Function("glMultiDrawElements");
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)_functions.Function("glPointParameterf");
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)_functions.Function("glPointParameterfv");
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)_functions.Function("glPointParameteri");
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)_functions.Function("glPointParameteriv");
	glFogCoordf = (PFNGLFOGCOORDFPROC)_functions.Function("glFogCoordf");
	glFogCoordfv = (PFNGLFOGCOORDFVPROC)_functions.Function("glFogCoordfv");
	glFogCoordd = (PFNGLFOGCOORDDPROC)_functions.Function("glFogCoordd");
	glFogCoorddv = (PFNGLFOGCOORDDVPROC)_functions.Function("glFogCoorddv");
	glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)_functions.Function("glFogCoordPointer");
	glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)_functions.Function("glSecondaryColor3b");
	glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)_functions.Function("glSecondaryColor3bv");
	glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)_functions.Function("glSecondaryColor3d");
	glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)_functions.Function("glSecondaryColor3dv");
	glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)_functions.Function("glSecondaryColor3f");
	glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)_functions.Function("glSecondaryColor3fv");
	glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)_functions.Function("glSecondaryColor3i");
	glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)_functions.Function("glSecondaryColor3iv");
	glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)_functions.Function("glSecondaryColor3s");
	glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)_functions.Function("glSecondaryColor3sv");
	glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)_functions.Function("glSecondaryColor3ub");
	glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)_functions.Function("glSecondaryColor3ubv");
	glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)_functions.Function("glSecondaryColor3ui");
	glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)_functions.Function("glSecondaryColor3uiv");
	glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)_functions.Function("glSecondaryColor3us");
	glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)_functions.Function("glSecondaryColor3usv");
	glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)_functions.Function("glSecondaryColorPointer");
	glWindowPos2d = (PFNGLWINDOWPOS2DPROC)_functions.Function("glWindowPos2d");
	glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)_functions.Function("glWindowPos2dv");
	glWindowPos2f = (PFNGLWINDOWPOS2FPROC)_functions.Function("glWindowPos2f");
	glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)_functions.Function("glWindowPos2fv");
	glWindowPos2i = (PFNGLWINDOWPOS2IPROC)_functions.Function("glWindowPos2i");
	glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)_functions.Function("glWindowPos2iv");
	glWindowPos2s = (PFNGLWINDOWPOS2SPROC)_functions.Function("glWindowPos2s");
	glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)_functions.Function("glWindowPos2sv");
	glWindowPos3d = (PFNGLWINDOWPOS3DPROC)_functions.Function("glWindowPos3d");
	glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)_functions.Function("glWindowPos3dv");
	glWindowPos3f = (PFNGLWINDOWPOS3FPROC)_functions.Function("glWindowPos3f");
	glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)_functions.Function("glWindowPos3fv");
	glWindowPos3i = (PFNGLWINDOWPOS3IPROC)_functions.Function("glWindowPos3i");
	glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)_functions.Function("glWindowPos3iv");
	glWindowPos3s = (PFNGLWINDOWPOS3SPROC)_functions.Function("glWindowPos3s");
	glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)_functions.Function("glWindowPos3sv");
	glBlendColor = (PFNGLBLENDCOLORPROC)_functions.Function("glBlendColor");
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)_functions.Function("glBlendEquation");
}

LDL_OpenGLLoader_1_4::~LDL_OpenGLLoader_1_4()
{
}
