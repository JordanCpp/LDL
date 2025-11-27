// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL1_3.hpp>
#include <LDL/OpenGL/GLLoad13.hpp>

LDL_OpenGLLoader_1_3::LDL_OpenGLLoader_1_3(LDL_Result& result) :
	_result(result),
	_functions(_result)
{
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)_functions.Function("glActiveTexture");
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)_functions.Function("glSampleCoverage");
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)_functions.Function("glCompressedTexImage3D");
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)_functions.Function("glCompressedTexImage2D");
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)_functions.Function("glCompressedTexImage1D");
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)_functions.Function("glCompressedTexSubImage3D");
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)_functions.Function("glCompressedTexSubImage2D");
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)_functions.Function("glCompressedTexSubImage1D");
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)_functions.Function("glGetCompressedTexImage");
	glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)_functions.Function("glClientActiveTexture");
	glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)_functions.Function("glMultiTexCoord1d");
	glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)_functions.Function("glMultiTexCoord1dv");
	glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)_functions.Function("glMultiTexCoord1f");
	glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)_functions.Function("glMultiTexCoord1fv");
	glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)_functions.Function("glMultiTexCoord1i");
	glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)_functions.Function("glMultiTexCoord1iv");
	glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)_functions.Function("glMultiTexCoord1s");
	glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)_functions.Function("glMultiTexCoord1sv");
	glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)_functions.Function("glMultiTexCoord2d");
	glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)_functions.Function("glMultiTexCoord2dv");
	glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)_functions.Function("glMultiTexCoord2f");
	glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)_functions.Function("glMultiTexCoord2fv");
	glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)_functions.Function("glMultiTexCoord2i");
	glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)_functions.Function("glMultiTexCoord2iv");
	glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)_functions.Function("glMultiTexCoord2s");
	glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)_functions.Function("glMultiTexCoord2sv");
	glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)_functions.Function("glMultiTexCoord3d");
	glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)_functions.Function("glMultiTexCoord3dv");
	glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)_functions.Function("glMultiTexCoord3f");
	glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)_functions.Function("glMultiTexCoord3fv");
	glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)_functions.Function("glMultiTexCoord3i");
	glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)_functions.Function("glMultiTexCoord3iv");
	glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)_functions.Function("glMultiTexCoord3s");
	glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)_functions.Function("glMultiTexCoord3sv");
	glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)_functions.Function("glMultiTexCoord4d");
	glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)_functions.Function("glMultiTexCoord4dv");
	glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)_functions.Function("glMultiTexCoord4f");
	glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)_functions.Function("glMultiTexCoord4fv");
	glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)_functions.Function("glMultiTexCoord4i");
	glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)_functions.Function("glMultiTexCoord4iv");
	glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)_functions.Function("glMultiTexCoord4s");
	glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)_functions.Function("glMultiTexCoord4sv");
	glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)_functions.Function("glLoadTransposeMatrixf");
	glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)_functions.Function("glLoadTransposeMatrixd");
	glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)_functions.Function("glMultTransposeMatrixf");
	glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)_functions.Function("glMultTransposeMatrixd");
}

LDL_OpenGLLoader_1_3::~LDL_OpenGLLoader_1_3()
{
}
