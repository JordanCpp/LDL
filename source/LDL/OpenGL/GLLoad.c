/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <stdlib.h>
#include <LDL/OpenGL/GLLoad.h>
#include <LDL/Win9x/GLFuncs.h>
#include <LDL/OpenGL/GL4_6.h>

struct LDL_OpenGLLoader
{
	size_t              Major;
	size_t              Minor;
	LDL_Result*         Result;
	LDL_OpenGLFunctions Functions;
};

typedef struct LDL_VersionOpenGLLoader
{
	size_t              Major;
	size_t              Minor;
	void(*Loader)(LDL_OpenGLLoader*);
} LDL_VersionOpenGLLoader;

void LDL_OpenGLLoader_1_0(LDL_OpenGLLoader* loader)
{
	glCullFace = (PFNGLCULLFACEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCullFace");
	glFrontFace = (PFNGLFRONTFACEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFrontFace");
	glHint = (PFNGLHINTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glHint");
	glLineWidth = (PFNGLLINEWIDTHPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLineWidth");
	glPointSize = (PFNGLPOINTSIZEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPointSize");
	glPolygonMode = (PFNGLPOLYGONMODEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPolygonMode");
	glScissor = (PFNGLSCISSORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glScissor");
	glTexParameterf = (PFNGLTEXPARAMETERFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexParameterf");
	glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexParameterfv");
	glTexParameteri = (PFNGLTEXPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexParameteri");
	glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexParameteriv");
	glTexImage1D = (PFNGLTEXIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexImage1D");
	glTexImage2D = (PFNGLTEXIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexImage2D");
	glDrawBuffer = (PFNGLDRAWBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawBuffer");
	glClear = (PFNGLCLEARPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClear");
	glClearColor = (PFNGLCLEARCOLORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearColor");
	glClearStencil = (PFNGLCLEARSTENCILPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearStencil");
	glClearDepth = (PFNGLCLEARDEPTHPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearDepth");
	glStencilMask = (PFNGLSTENCILMASKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glStencilMask");
	glColorMask = (PFNGLCOLORMASKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorMask");
	glDepthMask = (PFNGLDEPTHMASKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDepthMask");
	glDisable = (PFNGLDISABLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDisable");
	glEnable = (PFNGLENABLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEnable");
	glFinish = (PFNGLFINISHPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFinish");
	glFlush = (PFNGLFLUSHPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFlush");
	glBlendFunc = (PFNGLBLENDFUNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendFunc");
	glLogicOp = (PFNGLLOGICOPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLogicOp");
	glStencilFunc = (PFNGLSTENCILFUNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glStencilFunc");
	glStencilOp = (PFNGLSTENCILOPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glStencilOp");
	glDepthFunc = (PFNGLDEPTHFUNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDepthFunc");
	glPixelStoref = (PFNGLPIXELSTOREFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelStoref");
	glPixelStorei = (PFNGLPIXELSTOREIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelStorei");
	glReadBuffer = (PFNGLREADBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glReadBuffer");
	glReadPixels = (PFNGLREADPIXELSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glReadPixels");
	glGetBooleanv = (PFNGLGETBOOLEANVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetBooleanv");
	glGetDoublev = (PFNGLGETDOUBLEVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetDoublev");
	glGetError = (PFNGLGETERRORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetError");
	glGetFloatv = (PFNGLGETFLOATVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetFloatv");
	glGetIntegerv = (PFNGLGETINTEGERVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetIntegerv");
	glGetString = (PFNGLGETSTRINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetString");
	glGetTexImage = (PFNGLGETTEXIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexImage");
	glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexParameterfv");
	glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexParameteriv");
	glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexLevelParameterfv");
	glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexLevelParameteriv");
	glIsEnabled = (PFNGLISENABLEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsEnabled");
	glDepthRange = (PFNGLDEPTHRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDepthRange");
	glViewport = (PFNGLVIEWPORTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glViewport");
	glNewList = (PFNGLNEWLISTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNewList");
	glEndList = (PFNGLENDLISTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEndList");
	glCallList = (PFNGLCALLLISTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCallList");
	glCallLists = (PFNGLCALLLISTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCallLists");
	glDeleteLists = (PFNGLDELETELISTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteLists");
	glGenLists = (PFNGLGENLISTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenLists");
	glListBase = (PFNGLLISTBASEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glListBase");
	glBegin = (PFNGLBEGINPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBegin");
	glBitmap = (PFNGLBITMAPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBitmap");
	glColor3b = (PFNGLCOLOR3BPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3b");
	glColor3bv = (PFNGLCOLOR3BVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3bv");
	glColor3d = (PFNGLCOLOR3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3d");
	glColor3dv = (PFNGLCOLOR3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3dv");
	glColor3f = (PFNGLCOLOR3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3f");
	glColor3fv = (PFNGLCOLOR3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3fv");
	glColor3i = (PFNGLCOLOR3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3i");
	glColor3iv = (PFNGLCOLOR3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3iv");
	glColor3s = (PFNGLCOLOR3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3s");
	glColor3sv = (PFNGLCOLOR3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3sv");
	glColor3ub = (PFNGLCOLOR3UBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3ub");
	glColor3ubv = (PFNGLCOLOR3UBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3ubv");
	glColor3ui = (PFNGLCOLOR3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3ui");
	glColor3uiv = (PFNGLCOLOR3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3uiv");
	glColor3us = (PFNGLCOLOR3USPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3us");
	glColor3usv = (PFNGLCOLOR3USVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor3usv");
	glColor4b = (PFNGLCOLOR4BPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4b");
	glColor4bv = (PFNGLCOLOR4BVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4bv");
	glColor4d = (PFNGLCOLOR4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4d");
	glColor4dv = (PFNGLCOLOR4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4dv");
	glColor4f = (PFNGLCOLOR4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4f");
	glColor4fv = (PFNGLCOLOR4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4fv");
	glColor4i = (PFNGLCOLOR4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4i");
	glColor4iv = (PFNGLCOLOR4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4iv");
	glColor4s = (PFNGLCOLOR4SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4s");
	glColor4sv = (PFNGLCOLOR4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4sv");
	glColor4ub = (PFNGLCOLOR4UBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4ub");
	glColor4ubv = (PFNGLCOLOR4UBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4ubv");
	glColor4ui = (PFNGLCOLOR4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4ui");
	glColor4uiv = (PFNGLCOLOR4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4uiv");
	glColor4us = (PFNGLCOLOR4USPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4us");
	glColor4usv = (PFNGLCOLOR4USVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColor4usv");
	glEdgeFlag = (PFNGLEDGEFLAGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEdgeFlag");
	glEdgeFlagv = (PFNGLEDGEFLAGVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEdgeFlagv");
	glEnd = (PFNGLENDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEnd");
	glIndexd = (PFNGLINDEXDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexd");
	glIndexdv = (PFNGLINDEXDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexdv");
	glIndexf = (PFNGLINDEXFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexf");
	glIndexfv = (PFNGLINDEXFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexfv");
	glIndexi = (PFNGLINDEXIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexi");
	glIndexiv = (PFNGLINDEXIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexiv");
	glIndexs = (PFNGLINDEXSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexs");
	glIndexsv = (PFNGLINDEXSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexsv");
	glNormal3b = (PFNGLNORMAL3BPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3b");
	glNormal3bv = (PFNGLNORMAL3BVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3bv");
	glNormal3d = (PFNGLNORMAL3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3d");
	glNormal3dv = (PFNGLNORMAL3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3dv");
	glNormal3f = (PFNGLNORMAL3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3f");
	glNormal3fv = (PFNGLNORMAL3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3fv");
	glNormal3i = (PFNGLNORMAL3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3i");
	glNormal3iv = (PFNGLNORMAL3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3iv");
	glNormal3s = (PFNGLNORMAL3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3s");
	glNormal3sv = (PFNGLNORMAL3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormal3sv");
	glRasterPos2d = (PFNGLRASTERPOS2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2d");
	glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2dv");
	glRasterPos2f = (PFNGLRASTERPOS2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2f");
	glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2fv");
	glRasterPos2i = (PFNGLRASTERPOS2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2i");
	glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2iv");
	glRasterPos2s = (PFNGLRASTERPOS2SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2s");
	glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos2sv");
	glRasterPos3d = (PFNGLRASTERPOS3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3d");
	glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3dv");
	glRasterPos3f = (PFNGLRASTERPOS3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3f");
	glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3fv");
	glRasterPos3i = (PFNGLRASTERPOS3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3i");
	glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3iv");
	glRasterPos3s = (PFNGLRASTERPOS3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3s");
	glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos3sv");
	glRasterPos4d = (PFNGLRASTERPOS4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4d");
	glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4dv");
	glRasterPos4f = (PFNGLRASTERPOS4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4f");
	glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4fv");
	glRasterPos4i = (PFNGLRASTERPOS4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4i");
	glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4iv");
	glRasterPos4s = (PFNGLRASTERPOS4SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4s");
	glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRasterPos4sv");
	glRectd = (PFNGLRECTDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRectd");
	glRectdv = (PFNGLRECTDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRectdv");
	glRectf = (PFNGLRECTFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRectf");
	glRectfv = (PFNGLRECTFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRectfv");
	glRecti = (PFNGLRECTIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRecti");
	glRectiv = (PFNGLRECTIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRectiv");
	glRects = (PFNGLRECTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRects");
	glRectsv = (PFNGLRECTSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRectsv");
	glTexCoord1d = (PFNGLTEXCOORD1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1d");
	glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1dv");
	glTexCoord1f = (PFNGLTEXCOORD1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1f");
	glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1fv");
	glTexCoord1i = (PFNGLTEXCOORD1IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1i");
	glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1iv");
	glTexCoord1s = (PFNGLTEXCOORD1SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1s");
	glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord1sv");
	glTexCoord2d = (PFNGLTEXCOORD2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2d");
	glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2dv");
	glTexCoord2f = (PFNGLTEXCOORD2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2f");
	glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2fv");
	glTexCoord2i = (PFNGLTEXCOORD2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2i");
	glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2iv");
	glTexCoord2s = (PFNGLTEXCOORD2SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2s");
	glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord2sv");
	glTexCoord3d = (PFNGLTEXCOORD3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3d");
	glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3dv");
	glTexCoord3f = (PFNGLTEXCOORD3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3f");
	glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3fv");
	glTexCoord3i = (PFNGLTEXCOORD3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3i");
	glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3iv");
	glTexCoord3s = (PFNGLTEXCOORD3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3s");
	glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord3sv");
	glTexCoord4d = (PFNGLTEXCOORD4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4d");
	glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4dv");
	glTexCoord4f = (PFNGLTEXCOORD4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4f");
	glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4fv");
	glTexCoord4i = (PFNGLTEXCOORD4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4i");
	glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4iv");
	glTexCoord4s = (PFNGLTEXCOORD4SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4s");
	glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoord4sv");
	glVertex2d = (PFNGLVERTEX2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2d");
	glVertex2dv = (PFNGLVERTEX2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2dv");
	glVertex2f = (PFNGLVERTEX2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2f");
	glVertex2fv = (PFNGLVERTEX2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2fv");
	glVertex2i = (PFNGLVERTEX2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2i");
	glVertex2iv = (PFNGLVERTEX2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2iv");
	glVertex2s = (PFNGLVERTEX2SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2s");
	glVertex2sv = (PFNGLVERTEX2SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex2sv");
	glVertex3d = (PFNGLVERTEX3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3d");
	glVertex3dv = (PFNGLVERTEX3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3dv");
	glVertex3f = (PFNGLVERTEX3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3f");
	glVertex3fv = (PFNGLVERTEX3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3fv");
	glVertex3i = (PFNGLVERTEX3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3i");
	glVertex3iv = (PFNGLVERTEX3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3iv");
	glVertex3s = (PFNGLVERTEX3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3s");
	glVertex3sv = (PFNGLVERTEX3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex3sv");
	glVertex4d = (PFNGLVERTEX4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4d");
	glVertex4dv = (PFNGLVERTEX4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4dv");
	glVertex4f = (PFNGLVERTEX4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4f");
	glVertex4fv = (PFNGLVERTEX4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4fv");
	glVertex4i = (PFNGLVERTEX4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4i");
	glVertex4iv = (PFNGLVERTEX4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4iv");
	glVertex4s = (PFNGLVERTEX4SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4s");
	glVertex4sv = (PFNGLVERTEX4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertex4sv");
	glClipPlane = (PFNGLCLIPPLANEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClipPlane");
	glColorMaterial = (PFNGLCOLORMATERIALPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorMaterial");
	glFogf = (PFNGLFOGFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogf");
	glFogfv = (PFNGLFOGFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogfv");
	glFogi = (PFNGLFOGIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogi");
	glFogiv = (PFNGLFOGIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogiv");
	glLightf = (PFNGLLIGHTFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightf");
	glLightfv = (PFNGLLIGHTFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightfv");
	glLighti = (PFNGLLIGHTIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLighti");
	glLightiv = (PFNGLLIGHTIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightiv");
	glLightModelf = (PFNGLLIGHTMODELFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightModelf");
	glLightModelfv = (PFNGLLIGHTMODELFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightModelfv");
	glLightModeli = (PFNGLLIGHTMODELIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightModeli");
	glLightModeliv = (PFNGLLIGHTMODELIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLightModeliv");
	glLineStipple = (PFNGLLINESTIPPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLineStipple");
	glMaterialf = (PFNGLMATERIALFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMaterialf");
	glMaterialfv = (PFNGLMATERIALFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMaterialfv");
	glMateriali = (PFNGLMATERIALIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMateriali");
	glMaterialiv = (PFNGLMATERIALIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMaterialiv");
	glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPolygonStipple");
	glShadeModel = (PFNGLSHADEMODELPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glShadeModel");
	glTexEnvf = (PFNGLTEXENVFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexEnvf");
	glTexEnvfv = (PFNGLTEXENVFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexEnvfv");
	glTexEnvi = (PFNGLTEXENVIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexEnvi");
	glTexEnviv = (PFNGLTEXENVIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexEnviv");
	glTexGend = (PFNGLTEXGENDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexGend");
	glTexGendv = (PFNGLTEXGENDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexGendv");
	glTexGenf = (PFNGLTEXGENFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexGenf");
	glTexGenfv = (PFNGLTEXGENFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexGenfv");
	glTexGeni = (PFNGLTEXGENIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexGeni");
	glTexGeniv = (PFNGLTEXGENIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexGeniv");
	glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFeedbackBuffer");
	glSelectBuffer = (PFNGLSELECTBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSelectBuffer");
	glRenderMode = (PFNGLRENDERMODEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRenderMode");
	glInitNames = (PFNGLINITNAMESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInitNames");
	glLoadName = (PFNGLLOADNAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLoadName");
	glPassThrough = (PFNGLPASSTHROUGHPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPassThrough");
	glPopName = (PFNGLPOPNAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPopName");
	glPushName = (PFNGLPUSHNAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPushName");
	glClearAccum = (PFNGLCLEARACCUMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearAccum");
	glClearIndex = (PFNGLCLEARINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearIndex");
	glIndexMask = (PFNGLINDEXMASKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexMask");
	glAccum = (PFNGLACCUMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glAccum");
	glPopAttrib = (PFNGLPOPATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPopAttrib");
	glPushAttrib = (PFNGLPUSHATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPushAttrib");
	glMap1d = (PFNGLMAP1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMap1d");
	glMap1f = (PFNGLMAP1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMap1f");
	glMap2d = (PFNGLMAP2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMap2d");
	glMap2f = (PFNGLMAP2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMap2f");
	glMapGrid1d = (PFNGLMAPGRID1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapGrid1d");
	glMapGrid1f = (PFNGLMAPGRID1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapGrid1f");
	glMapGrid2d = (PFNGLMAPGRID2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapGrid2d");
	glMapGrid2f = (PFNGLMAPGRID2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapGrid2f");
	glEvalCoord1d = (PFNGLEVALCOORD1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord1d");
	glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord1dv");
	glEvalCoord1f = (PFNGLEVALCOORD1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord1f");
	glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord1fv");
	glEvalCoord2d = (PFNGLEVALCOORD2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord2d");
	glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord2dv");
	glEvalCoord2f = (PFNGLEVALCOORD2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord2f");
	glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalCoord2fv");
	glEvalMesh1 = (PFNGLEVALMESH1PROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalMesh1");
	glEvalPoint1 = (PFNGLEVALPOINT1PROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalPoint1");
	glEvalMesh2 = (PFNGLEVALMESH2PROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalMesh2");
	glEvalPoint2 = (PFNGLEVALPOINT2PROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEvalPoint2");
	glAlphaFunc = (PFNGLALPHAFUNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glAlphaFunc");
	glPixelZoom = (PFNGLPIXELZOOMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelZoom");
	glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelTransferf");
	glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelTransferi");
	glPixelMapfv = (PFNGLPIXELMAPFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelMapfv");
	glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelMapuiv");
	glPixelMapusv = (PFNGLPIXELMAPUSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPixelMapusv");
	glCopyPixels = (PFNGLCOPYPIXELSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyPixels");
	glDrawPixels = (PFNGLDRAWPIXELSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawPixels");
	glGetClipPlane = (PFNGLGETCLIPPLANEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetClipPlane");
	glGetLightfv = (PFNGLGETLIGHTFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetLightfv");
	glGetLightiv = (PFNGLGETLIGHTIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetLightiv");
	glGetMapdv = (PFNGLGETMAPDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetMapdv");
	glGetMapfv = (PFNGLGETMAPFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetMapfv");
	glGetMapiv = (PFNGLGETMAPIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetMapiv");
	glGetMaterialfv = (PFNGLGETMATERIALFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetMaterialfv");
	glGetMaterialiv = (PFNGLGETMATERIALIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetMaterialiv");
	glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetPixelMapfv");
	glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetPixelMapuiv");
	glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetPixelMapusv");
	glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetPolygonStipple");
	glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexEnvfv");
	glGetTexEnviv = (PFNGLGETTEXENVIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexEnviv");
	glGetTexGendv = (PFNGLGETTEXGENDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexGendv");
	glGetTexGenfv = (PFNGLGETTEXGENFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexGenfv");
	glGetTexGeniv = (PFNGLGETTEXGENIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexGeniv");
	glIsList = (PFNGLISLISTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsList");
	glFrustum = (PFNGLFRUSTUMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFrustum");
	glLoadIdentity = (PFNGLLOADIDENTITYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLoadIdentity");
	glLoadMatrixf = (PFNGLLOADMATRIXFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLoadMatrixf");
	glLoadMatrixd = (PFNGLLOADMATRIXDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLoadMatrixd");
	glMatrixMode = (PFNGLMATRIXMODEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMatrixMode");
	glMultMatrixf = (PFNGLMULTMATRIXFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultMatrixf");
	glMultMatrixd = (PFNGLMULTMATRIXDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultMatrixd");
	glOrtho = (PFNGLORTHOPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glOrtho");
	glPopMatrix = (PFNGLPOPMATRIXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPopMatrix");
	glPushMatrix = (PFNGLPUSHMATRIXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPushMatrix");
	glRotated = (PFNGLROTATEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRotated");
	glRotatef = (PFNGLROTATEFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRotatef");
	glScaled = (PFNGLSCALEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glScaled");
	glScalef = (PFNGLSCALEFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glScalef");
	glTranslated = (PFNGLTRANSLATEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTranslated");
	glTranslatef = (PFNGLTRANSLATEFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTranslatef");
}

void LDL_OpenGLLoader_1_1(LDL_OpenGLLoader* loader)
{
	glDrawArrays = (PFNGLDRAWARRAYSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawArrays");
	glDrawElements = (PFNGLDRAWELEMENTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElements");
	glGetPointerv = (PFNGLGETPOINTERVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetPointerv");
	glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPolygonOffset");
	glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTexImage1D");
	glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTexImage2D");
	glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTexSubImage1D");
	glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTexSubImage2D");
	glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexSubImage1D");
	glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexSubImage2D");
	glBindTexture = (PFNGLBINDTEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindTexture");
	glDeleteTextures = (PFNGLDELETETEXTURESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteTextures");
	glGenTextures = (PFNGLGENTEXTURESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenTextures");
	glIsTexture = (PFNGLISTEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsTexture");
	glArrayElement = (PFNGLARRAYELEMENTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glArrayElement");
	glColorPointer = (PFNGLCOLORPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorPointer");
	glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDisableClientState");
	glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEdgeFlagPointer");
	glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEnableClientState");
	glIndexPointer = (PFNGLINDEXPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexPointer");
	glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInterleavedArrays");
	glNormalPointer = (PFNGLNORMALPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormalPointer");
	glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordPointer");
	glVertexPointer = (PFNGLVERTEXPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexPointer");
	glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glAreTexturesResident");
	glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPrioritizeTextures");
	glIndexub = (PFNGLINDEXUBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexub");
	glIndexubv = (PFNGLINDEXUBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIndexubv");
	glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPopClientAttrib");
	glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPushClientAttrib");
}

void LDL_OpenGLLoader_1_2(LDL_OpenGLLoader* loader)
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTexSubImage3D");
}

void LDL_OpenGLLoader_1_3(LDL_OpenGLLoader* loader)
{
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glActiveTexture");
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSampleCoverage");
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTexImage3D");
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTexImage2D");
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTexImage1D");
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTexSubImage3D");
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTexSubImage2D");
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTexSubImage1D");
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetCompressedTexImage");
	glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClientActiveTexture");
	glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1d");
	glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1dv");
	glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1f");
	glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1fv");
	glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1i");
	glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1iv");
	glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1s");
	glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord1sv");
	glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2d");
	glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2dv");
	glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2f");
	glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2fv");
	glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2i");
	glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2iv");
	glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2s");
	glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord2sv");
	glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3d");
	glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3dv");
	glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3f");
	glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3fv");
	glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3i");
	glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3iv");
	glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3s");
	glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord3sv");
	glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4d");
	glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4dv");
	glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4f");
	glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4fv");
	glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4i");
	glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4iv");
	glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4s");
	glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoord4sv");
	glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLoadTransposeMatrixf");
	glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLoadTransposeMatrixd");
	glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultTransposeMatrixf");
	glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultTransposeMatrixd");
}

void LDL_OpenGLLoader_1_4(LDL_OpenGLLoader* loader)
{
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendFuncSeparate");
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawArrays");
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawElements");
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPointParameterf");
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPointParameterfv");
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPointParameteri");
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPointParameteriv");
	glFogCoordf = (PFNGLFOGCOORDFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogCoordf");
	glFogCoordfv = (PFNGLFOGCOORDFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogCoordfv");
	glFogCoordd = (PFNGLFOGCOORDDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogCoordd");
	glFogCoorddv = (PFNGLFOGCOORDDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogCoorddv");
	glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFogCoordPointer");
	glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3b");
	glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3bv");
	glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3d");
	glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3dv");
	glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3f");
	glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3fv");
	glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3i");
	glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3iv");
	glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3s");
	glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3sv");
	glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3ub");
	glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3ubv");
	glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3ui");
	glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3uiv");
	glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3us");
	glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColor3usv");
	glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColorPointer");
	glWindowPos2d = (PFNGLWINDOWPOS2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2d");
	glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2dv");
	glWindowPos2f = (PFNGLWINDOWPOS2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2f");
	glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2fv");
	glWindowPos2i = (PFNGLWINDOWPOS2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2i");
	glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2iv");
	glWindowPos2s = (PFNGLWINDOWPOS2SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2s");
	glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos2sv");
	glWindowPos3d = (PFNGLWINDOWPOS3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3d");
	glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3dv");
	glWindowPos3f = (PFNGLWINDOWPOS3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3f");
	glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3fv");
	glWindowPos3i = (PFNGLWINDOWPOS3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3i");
	glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3iv");
	glWindowPos3s = (PFNGLWINDOWPOS3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3s");
	glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWindowPos3sv");
	glBlendColor = (PFNGLBLENDCOLORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendColor");
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendEquation");
}

void LDL_OpenGLLoader_1_5(LDL_OpenGLLoader* loader)
{
	glGenQueries = (PFNGLGENQUERIESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetBufferPointerv");
}

void LDL_OpenGLLoader_2_0(LDL_OpenGLLoader* loader)
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribPointer");
}

void LDL_OpenGLLoader_2_1(LDL_OpenGLLoader* loader)
{
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix4x3fv");
}

void LDL_OpenGLLoader_3_0(LDL_OpenGLLoader* loader)
{
	glColorMaski = (PFNGLCOLORMASKIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorMaski");
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearBufferfi");
	glGetStringi = (PFNGLGETSTRINGIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenFramebuffers");
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCheckFramebufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenerateMipmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsVertexArray");
}

void LDL_OpenGLLoader_3_1(LDL_OpenGLLoader* loader)
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformBlockBinding");
}

void LDL_OpenGLLoader_3_2(LDL_OpenGLLoader* loader)
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferTexture");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexImage2DMultisample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSampleMaski");
}

void LDL_OpenGLLoader_3_3(LDL_OpenGLLoader* loader)
{
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindFragDataLocationIndexed");
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetFragDataIndex");
	glGenSamplers = (PFNGLGENSAMPLERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenSamplers");
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteSamplers");
	glIsSampler = (PFNGLISSAMPLERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsSampler");
	glBindSampler = (PFNGLBINDSAMPLERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindSampler");
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSamplerParameteri");
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSamplerParameteriv");
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSamplerParameterf");
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSamplerParameterfv");
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSamplerParameterIiv");
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSamplerParameterIuiv");
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSamplerParameteriv");
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSamplerParameterIiv");
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSamplerParameterfv");
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSamplerParameterIuiv");
	glQueryCounter = (PFNGLQUERYCOUNTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glQueryCounter");
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryObjecti64v");
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryObjectui64v");
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribDivisor");
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP1ui");
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP1uiv");
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP2ui");
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP2uiv");
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP3ui");
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP3uiv");
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP4ui");
	glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribP4uiv");
	glVertexP2ui = (PFNGLVERTEXP2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexP2ui");
	glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexP2uiv");
	glVertexP3ui = (PFNGLVERTEXP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexP3ui");
	glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexP3uiv");
	glVertexP4ui = (PFNGLVERTEXP4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexP4ui");
	glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexP4uiv");
	glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP1ui");
	glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP1uiv");
	glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP2ui");
	glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP2uiv");
	glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP3ui");
	glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP3uiv");
	glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP4ui");
	glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexCoordP4uiv");
	glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP1ui");
	glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP1uiv");
	glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP2ui");
	glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP2uiv");
	glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP3ui");
	glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP3uiv");
	glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP4ui");
	glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiTexCoordP4uiv");
	glNormalP3ui = (PFNGLNORMALP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormalP3ui");
	glNormalP3uiv = (PFNGLNORMALP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNormalP3uiv");
	glColorP3ui = (PFNGLCOLORP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorP3ui");
	glColorP3uiv = (PFNGLCOLORP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorP3uiv");
	glColorP4ui = (PFNGLCOLORP4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorP4ui");
	glColorP4uiv = (PFNGLCOLORP4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glColorP4uiv");
	glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColorP3ui");
	glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSecondaryColorP3uiv");
}

void LDL_OpenGLLoader_4_0(LDL_OpenGLLoader* loader)
{
	glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMinSampleShading");
	glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendEquationi");
	glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendEquationSeparatei");
	glBlendFunci = (PFNGLBLENDFUNCIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendFunci");
	glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlendFuncSeparatei");
	glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawArraysIndirect");
	glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElementsIndirect");
	glUniform1d = (PFNGLUNIFORM1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1d");
	glUniform2d = (PFNGLUNIFORM2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2d");
	glUniform3d = (PFNGLUNIFORM3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3d");
	glUniform4d = (PFNGLUNIFORM4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4d");
	glUniform1dv = (PFNGLUNIFORM1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform1dv");
	glUniform2dv = (PFNGLUNIFORM2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform2dv");
	glUniform3dv = (PFNGLUNIFORM3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform3dv");
	glUniform4dv = (PFNGLUNIFORM4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniform4dv");
	glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix2dv");
	glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix3dv");
	glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix4dv");
	glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix2x3dv");
	glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix2x4dv");
	glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix3x2dv");
	glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix3x4dv");
	glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix4x2dv");
	glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformMatrix4x3dv");
	glGetUniformdv = (PFNGLGETUNIFORMDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformdv");
	glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSubroutineUniformLocation");
	glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetSubroutineIndex");
	glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveSubroutineUniformiv");
	glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveSubroutineUniformName");
	glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveSubroutineName");
	glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUniformSubroutinesuiv");
	glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetUniformSubroutineuiv");
	glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramStageiv");
	glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPatchParameteri");
	glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPatchParameterfv");
	glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindTransformFeedback");
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteTransformFeedbacks");
	glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenTransformFeedbacks");
	glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsTransformFeedback");
	glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPauseTransformFeedback");
	glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glResumeTransformFeedback");
	glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawTransformFeedback");
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawTransformFeedbackStream");
	glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBeginQueryIndexed");
	glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEndQueryIndexed");
	glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryIndexediv");
}

void LDL_OpenGLLoader_4_1(LDL_OpenGLLoader* loader)
{
	glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glReleaseShaderCompiler");
	glShaderBinary = (PFNGLSHADERBINARYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glShaderBinary");
	glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetShaderPrecisionFormat");
	glDepthRangef = (PFNGLDEPTHRANGEFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDepthRangef");
	glClearDepthf = (PFNGLCLEARDEPTHFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearDepthf");
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramBinary");
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramBinary");
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramParameteri");
	glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUseProgramStages");
	glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glActiveShaderProgram");
	glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateShaderProgramv");
	glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindProgramPipeline");
	glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDeleteProgramPipelines");
	glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenProgramPipelines");
	glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glIsProgramPipeline");
	glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramPipelineiv");
	glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1i");
	glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1iv");
	glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1f");
	glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1fv");
	glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1d");
	glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1dv");
	glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1ui");
	glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform1uiv");
	glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2i");
	glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2iv");
	glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2f");
	glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2fv");
	glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2d");
	glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2dv");
	glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2ui");
	glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform2uiv");
	glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3i");
	glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3iv");
	glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3f");
	glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3fv");
	glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3d");
	glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3dv");
	glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3ui");
	glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform3uiv");
	glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4i");
	glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4iv");
	glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4f");
	glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4fv");
	glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4d");
	glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4dv");
	glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4ui");
	glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniform4uiv");
	glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix2fv");
	glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix3fv");
	glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix4fv");
	glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix2dv");
	glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix3dv");
	glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix4dv");
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix2x3fv");
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix3x2fv");
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix2x4fv");
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix4x2fv");
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix3x4fv");
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix4x3fv");
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix2x3dv");
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix3x2dv");
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix2x4dv");
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix4x2dv");
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix3x4dv");
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glProgramUniformMatrix4x3dv");
	glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glValidateProgramPipeline");
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramPipelineInfoLog");
	glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL1d");
	glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL2d");
	glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL3d");
	glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL4d");
	glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL1dv");
	glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL2dv");
	glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL3dv");
	glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribL4dv");
	glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribLPointer");
	glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexAttribLdv");
	glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glViewportArrayv");
	glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glViewportIndexedf");
	glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glViewportIndexedfv");
	glScissorArrayv = (PFNGLSCISSORARRAYVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glScissorArrayv");
	glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glScissorIndexed");
	glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glScissorIndexedv");
	glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDepthRangeArrayv");
	glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDepthRangeIndexed");
	glGetFloati_v = (PFNGLGETFLOATI_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetFloati_v");
	glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetDoublei_v");
}

void LDL_OpenGLLoader_4_2(LDL_OpenGLLoader* loader)
{
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetInternalformativ");
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetActiveAtomicCounterBufferiv");
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindImageTexture");
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMemoryBarrier");
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexStorage1D");
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexStorage2D");
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexStorage3D");
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDrawTransformFeedbackStreamInstanced");
}

void LDL_OpenGLLoader_4_3(LDL_OpenGLLoader* loader)
{
	glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearBufferData");
	glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearBufferSubData");
	glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDispatchCompute");
	glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDispatchComputeIndirect");
	glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyImageSubData");
	glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFramebufferParameteri");
	glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetFramebufferParameteriv");
	glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetInternalformati64v");
	glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateTexSubImage");
	glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateTexImage");
	glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateBufferSubData");
	glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateBufferData");
	glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateFramebuffer");
	glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateSubFramebuffer");
	glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawArraysIndirect");
	glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawElementsIndirect");
	glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramInterfaceiv");
	glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramResourceIndex");
	glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramResourceName");
	glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramResourceiv");
	glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramResourceLocation");
	glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetProgramResourceLocationIndex");
	glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glShaderStorageBlockBinding");
	glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexBufferRange");
	glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexStorage2DMultisample");
	glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTexStorage3DMultisample");
	glTextureView = (PFNGLTEXTUREVIEWPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureView");
	glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindVertexBuffer");
	glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribFormat");
	glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribIFormat");
	glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribLFormat");
	glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexAttribBinding");
	glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexBindingDivisor");
	glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDebugMessageControl");
	glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDebugMessageInsert");
	glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDebugMessageCallback");
	glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetDebugMessageLog");
	glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPushDebugGroup");
	glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPopDebugGroup");
	glObjectLabel = (PFNGLOBJECTLABELPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glObjectLabel");
	glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetObjectLabel");
	glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glObjectPtrLabel");
	glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetObjectPtrLabel");
}

void LDL_OpenGLLoader_4_4(LDL_OpenGLLoader* loader)
{
	glBufferStorage = (PFNGLBUFFERSTORAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBufferStorage");
	glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearTexImage");
	glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearTexSubImage");
	glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindBuffersBase");
	glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindBuffersRange");
	glBindTextures = (PFNGLBINDTEXTURESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindTextures");
	glBindSamplers = (PFNGLBINDSAMPLERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindSamplers");
	glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindImageTextures");
	glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindVertexBuffers");
}

void LDL_OpenGLLoader_4_5(LDL_OpenGLLoader* loader)
{
	glClipControl = (PFNGLCLIPCONTROLPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClipControl");
	glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateTransformFeedbacks");
	glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTransformFeedbackBufferBase");
	glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTransformFeedbackBufferRange");
	glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTransformFeedbackiv");
	glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTransformFeedbacki_v");
	glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTransformFeedbacki64_v");
	glCreateBuffers = (PFNGLCREATEBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateBuffers");
	glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedBufferStorage");
	glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedBufferData");
	glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedBufferSubData");
	glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyNamedBufferSubData");
	glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearNamedBufferData");
	glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearNamedBufferSubData");
	glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapNamedBuffer");
	glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMapNamedBufferRange");
	glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glUnmapNamedBuffer");
	glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glFlushMappedNamedBufferRange");
	glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedBufferParameteriv");
	glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedBufferParameteri64v");
	glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedBufferPointerv");
	glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedBufferSubData");
	glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateFramebuffers");
	glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferRenderbuffer");
	glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferParameteri");
	glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferTexture");
	glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferTextureLayer");
	glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferDrawBuffer");
	glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferDrawBuffers");
	glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedFramebufferReadBuffer");
	glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateNamedFramebufferData");
	glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glInvalidateNamedFramebufferSubData");
	glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearNamedFramebufferiv");
	glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearNamedFramebufferuiv");
	glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearNamedFramebufferfv");
	glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glClearNamedFramebufferfi");
	glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBlitNamedFramebuffer");
	glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCheckNamedFramebufferStatus");
	glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedFramebufferParameteriv");
	glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedFramebufferAttachmentParameteriv");
	glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateRenderbuffers");
	glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedRenderbufferStorage");
	glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glNamedRenderbufferStorageMultisample");
	glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetNamedRenderbufferParameteriv");
	glCreateTextures = (PFNGLCREATETEXTURESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateTextures");
	glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureBuffer");
	glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureBufferRange");
	glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureStorage1D");
	glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureStorage2D");
	glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureStorage3D");
	glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureStorage2DMultisample");
	glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureStorage3DMultisample");
	glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureSubImage1D");
	glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureSubImage2D");
	glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureSubImage3D");
	glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTextureSubImage1D");
	glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTextureSubImage2D");
	glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCompressedTextureSubImage3D");
	glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTextureSubImage1D");
	glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTextureSubImage2D");
	glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCopyTextureSubImage3D");
	glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureParameterf");
	glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureParameterfv");
	glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureParameteri");
	glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureParameterIiv");
	glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureParameterIuiv");
	glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureParameteriv");
	glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGenerateTextureMipmap");
	glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glBindTextureUnit");
	glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureImage");
	glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetCompressedTextureImage");
	glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureLevelParameterfv");
	glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureLevelParameteriv");
	glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureParameterfv");
	glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureParameterIiv");
	glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureParameterIuiv");
	glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureParameteriv");
	glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateVertexArrays");
	glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glDisableVertexArrayAttrib");
	glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glEnableVertexArrayAttrib");
	glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayElementBuffer");
	glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayVertexBuffer");
	glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayVertexBuffers");
	glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayAttribBinding");
	glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayAttribFormat");
	glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayAttribIFormat");
	glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayAttribLFormat");
	glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glVertexArrayBindingDivisor");
	glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexArrayiv");
	glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexArrayIndexediv");
	glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetVertexArrayIndexed64iv");
	glCreateSamplers = (PFNGLCREATESAMPLERSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateSamplers");
	glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateProgramPipelines");
	glCreateQueries = (PFNGLCREATEQUERIESPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glCreateQueries");
	glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryBufferObjecti64v");
	glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryBufferObjectiv");
	glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryBufferObjectui64v");
	glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetQueryBufferObjectuiv");
	glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMemoryBarrierByRegion");
	glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetTextureSubImage");
	glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetCompressedTextureSubImage");
	glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetGraphicsResetStatus");
	glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnCompressedTexImage");
	glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnTexImage");
	glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnUniformdv");
	glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnUniformfv");
	glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnUniformiv");
	glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnUniformuiv");
	glReadnPixels = (PFNGLREADNPIXELSPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glReadnPixels");
	glGetnMapdv = (PFNGLGETNMAPDVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnMapdv");
	glGetnMapfv = (PFNGLGETNMAPFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnMapfv");
	glGetnMapiv = (PFNGLGETNMAPIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnMapiv");
	glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnPixelMapfv");
	glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnPixelMapuiv");
	glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnPixelMapusv");
	glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnPolygonStipple");
	glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnColorTable");
	glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnConvolutionFilter");
	glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnSeparableFilter");
	glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnHistogram");
	glGetnMinmax = (PFNGLGETNMINMAXPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glGetnMinmax");
	glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glTextureBarrier");
}

void LDL_OpenGLLoader_4_6(LDL_OpenGLLoader* loader)
{
	glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glSpecializeShader");
	glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawArraysIndirectCount");
	glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glMultiDrawElementsIndirectCount");
	glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)LDL_OpenGLFunctionsGetFunction(&loader->Functions,"glPolygonOffsetClamp");
}

LDL_OpenGLLoader* LDL_OpenGLLoaderNew(LDL_Result* result, size_t major, size_t minor)
{
	size_t i;
	LDL_OpenGLLoader* loader = (LDL_OpenGLLoader*)malloc(sizeof(LDL_OpenGLLoader));
	LDL_VersionOpenGLLoader versions[] =
	{
		{1, 0, LDL_OpenGLLoader_1_0},
		{1, 1, LDL_OpenGLLoader_1_1},
		{1, 2, LDL_OpenGLLoader_1_2},
		{1, 3, LDL_OpenGLLoader_1_3},
		{1, 4, LDL_OpenGLLoader_1_4},
		{1, 5, LDL_OpenGLLoader_1_5},
		{2, 0, LDL_OpenGLLoader_2_0},
		{2, 1, LDL_OpenGLLoader_2_1},
		{3, 0, LDL_OpenGLLoader_3_0},
		{3, 1, LDL_OpenGLLoader_3_1},
		{3, 2, LDL_OpenGLLoader_3_2},
		{3, 3, LDL_OpenGLLoader_3_3},
		{4, 0, LDL_OpenGLLoader_4_0},
		{4, 1, LDL_OpenGLLoader_4_1},
		{4, 2, LDL_OpenGLLoader_4_2},
		{4, 3, LDL_OpenGLLoader_4_3},
		{4, 4, LDL_OpenGLLoader_4_4},
		{4, 5, LDL_OpenGLLoader_4_5},
		{4, 6, LDL_OpenGLLoader_4_6},
		{0, 0, NULL},
	};

	if (loader)
	{
		loader->Result = result;
		LDL_OpenGLFunctionsInit(&loader->Functions, result);

		for (i = 0; versions[i].Loader != NULL; i++)
		{
			if ((versions[i].Major < major) || (versions[i].Major == major && versions[i].Minor <= minor))
			{
				versions[i].Loader(loader);
			}
		}

		LDL_ResultReset(result);
		return loader;
	}

	return NULL;
}

void LDL_OpenGLLoaderFree(LDL_OpenGLLoader* loader)
{
	if (loader)
	{
		LDL_OpenGLFunctionsDeinit(&loader->Functions);

		free(loader);
	}
}
