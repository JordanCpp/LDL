// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL1_1.hpp>
#include <LDL/OpenGL/GLLoad11.hpp>

LDL_OpenGLLoader_1_1::LDL_OpenGLLoader_1_1(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glDrawArrays = (PFNGLDRAWARRAYSPROC)_functions.Function("glDrawArrays");
	glDrawElements = (PFNGLDRAWELEMENTSPROC)_functions.Function("glDrawElements");
	glGetPointerv = (PFNGLGETPOINTERVPROC)_functions.Function("glGetPointerv");
	glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)_functions.Function("glPolygonOffset");
	glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)_functions.Function("glCopyTexImage1D");
	glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)_functions.Function("glCopyTexImage2D");
	glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)_functions.Function("glCopyTexSubImage1D");
	glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)_functions.Function("glCopyTexSubImage2D");
	glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)_functions.Function("glTexSubImage1D");
	glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)_functions.Function("glTexSubImage2D");
	glBindTexture = (PFNGLBINDTEXTUREPROC)_functions.Function("glBindTexture");
	glDeleteTextures = (PFNGLDELETETEXTURESPROC)_functions.Function("glDeleteTextures");
	glGenTextures = (PFNGLGENTEXTURESPROC)_functions.Function("glGenTextures");
	glIsTexture = (PFNGLISTEXTUREPROC)_functions.Function("glIsTexture");
	glArrayElement = (PFNGLARRAYELEMENTPROC)_functions.Function("glArrayElement");
	glColorPointer = (PFNGLCOLORPOINTERPROC)_functions.Function("glColorPointer");
	glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)_functions.Function("glDisableClientState");
	glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC)_functions.Function("glEdgeFlagPointer");
	glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)_functions.Function("glEnableClientState");
	glIndexPointer = (PFNGLINDEXPOINTERPROC)_functions.Function("glIndexPointer");
	glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC)_functions.Function("glInterleavedArrays");
	glNormalPointer = (PFNGLNORMALPOINTERPROC)_functions.Function("glNormalPointer");
	glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)_functions.Function("glTexCoordPointer");
	glVertexPointer = (PFNGLVERTEXPOINTERPROC)_functions.Function("glVertexPointer");
	glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC)_functions.Function("glAreTexturesResident");
	glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)_functions.Function("glPrioritizeTextures");
	glIndexub = (PFNGLINDEXUBPROC)_functions.Function("glIndexub");
	glIndexubv = (PFNGLINDEXUBVPROC)_functions.Function("glIndexubv");
	glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC)_functions.Function("glPopClientAttrib");
	glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC)_functions.Function("glPushClientAttrib");
}

LDL_OpenGLLoader_1_1::~LDL_OpenGLLoader_1_1()
{
}
