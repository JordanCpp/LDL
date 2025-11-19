// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/OpenGL4_6.hpp>
#include <LDL/OpenGL/GLLoader.hpp>

OpenGLLoader::OpenGLLoader(LDL_Result& result) :
	_result(result),
	_major(0),
	_minor(0)
{
}

OpenGLLoader::~OpenGLLoader()
{
}

bool OpenGLLoader::Init(size_t major, size_t minor)
{
	_major = major;
	_minor = minor;

	if (Equal(1, 0))
	{
		Init_1_0();
	}
	else if (Equal(1, 1))
	{
		Init_1_0();
		Init_1_1();
	}
	else if (Equal(1, 2))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
	}
	else if (Equal(1, 3))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
	}
	else if (Equal(1, 4))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
	}
	else if (Equal(1, 5))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
	}
	else if (Equal(2, 0))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
	}
	else if (Equal(2, 1))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
	}
	else if (Equal(3, 0))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
	}
	else if (Equal(3, 1))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
	}
	else if (Equal(3, 2))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
	}
	else if (Equal(3, 3))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
	}
	else if (Equal(4, 0))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
	}
	else if (Equal(4, 1))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
	}
	else if (Equal(4, 2))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
	}
	else if (Equal(4, 3))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
	}
	else if (Equal(4, 4))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
		Init_4_4();
	}
	else if (Equal(4, 5))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
		Init_4_4();
		Init_4_5();
	}
	else if (Equal(4, 6))
	{
		Init_1_0();
		Init_1_1();
		Init_1_2();
		Init_1_3();
		Init_1_4();
		Init_1_5();
		Init_2_0();
		Init_2_1();
		Init_3_0();
		Init_3_1();
		Init_3_2();
		Init_3_3();
		Init_4_0();
		Init_4_1();
		Init_4_2();
		Init_4_3();
		Init_4_4();
		Init_4_6();
	}
	else
	{
		LDL_Formatter formatter;
		_result.Message(formatter.Format("OpenGL %d.%d not support", Major(), Minor()));

		return false;
	}

	return true;
}

bool OpenGLLoader::Equal(size_t major, size_t minor)
{
	return Major() == major && Minor() == minor;
}

size_t OpenGLLoader::Major()
{
	return _major;
}

size_t OpenGLLoader::Minor()
{
	return _minor;
}

void OpenGLLoader::Init_1_0()
{
	glCullFace = (PFNGLCULLFACEPROC)_functions.Function("glCullFace");
	glFrontFace = (PFNGLFRONTFACEPROC)_functions.Function("glFrontFace");
	glHint = (PFNGLHINTPROC)_functions.Function("glHint");
	glLineWidth = (PFNGLLINEWIDTHPROC)_functions.Function("glLineWidth");
	glPointSize = (PFNGLPOINTSIZEPROC)_functions.Function("glPointSize");
	glPolygonMode = (PFNGLPOLYGONMODEPROC)_functions.Function("glPolygonMode");
	glScissor = (PFNGLSCISSORPROC)_functions.Function("glScissor");
	glTexParameterf = (PFNGLTEXPARAMETERFPROC)_functions.Function("glTexParameterf");
	glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)_functions.Function("glTexParameterfv");
	glTexParameteri = (PFNGLTEXPARAMETERIPROC)_functions.Function("glTexParameteri");
	glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)_functions.Function("glTexParameteriv");
	glTexImage1D = (PFNGLTEXIMAGE1DPROC)_functions.Function("glTexImage1D");
	glTexImage2D = (PFNGLTEXIMAGE2DPROC)_functions.Function("glTexImage2D");
	glDrawBuffer = (PFNGLDRAWBUFFERPROC)_functions.Function("glDrawBuffer");
	glClear = (PFNGLCLEARPROC)_functions.Function("glClear");
	glClearColor = (PFNGLCLEARCOLORPROC)_functions.Function("glClearColor");
	glClearStencil = (PFNGLCLEARSTENCILPROC)_functions.Function("glClearStencil");
	glClearDepth = (PFNGLCLEARDEPTHPROC)_functions.Function("glClearDepth");
	glStencilMask = (PFNGLSTENCILMASKPROC)_functions.Function("glStencilMask");
	glColorMask = (PFNGLCOLORMASKPROC)_functions.Function("glColorMask");
	glDepthMask = (PFNGLDEPTHMASKPROC)_functions.Function("glDepthMask");
	glDisable = (PFNGLDISABLEPROC)_functions.Function("glDisable");
	glEnable = (PFNGLENABLEPROC)_functions.Function("glEnable");
	glFinish = (PFNGLFINISHPROC)_functions.Function("glFinish");
	glFlush = (PFNGLFLUSHPROC)_functions.Function("glFlush");
	glBlendFunc = (PFNGLBLENDFUNCPROC)_functions.Function("glBlendFunc");
	glLogicOp = (PFNGLLOGICOPPROC)_functions.Function("glLogicOp");
	glStencilFunc = (PFNGLSTENCILFUNCPROC)_functions.Function("glStencilFunc");
	glStencilOp = (PFNGLSTENCILOPPROC)_functions.Function("glStencilOp");
	glDepthFunc = (PFNGLDEPTHFUNCPROC)_functions.Function("glDepthFunc");
	glPixelStoref = (PFNGLPIXELSTOREFPROC)_functions.Function("glPixelStoref");
	glPixelStorei = (PFNGLPIXELSTOREIPROC)_functions.Function("glPixelStorei");
	glReadBuffer = (PFNGLREADBUFFERPROC)_functions.Function("glReadBuffer");
	glReadPixels = (PFNGLREADPIXELSPROC)_functions.Function("glReadPixels");
	glGetBooleanv = (PFNGLGETBOOLEANVPROC)_functions.Function("glGetBooleanv");
	glGetDoublev = (PFNGLGETDOUBLEVPROC)_functions.Function("glGetDoublev");
	glGetError = (PFNGLGETERRORPROC)_functions.Function("glGetError");
	glGetFloatv = (PFNGLGETFLOATVPROC)_functions.Function("glGetFloatv");
	glGetIntegerv = (PFNGLGETINTEGERVPROC)_functions.Function("glGetIntegerv");
	glGetString = (PFNGLGETSTRINGPROC)_functions.Function("glGetString");
	glGetTexImage = (PFNGLGETTEXIMAGEPROC)_functions.Function("glGetTexImage");
	glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)_functions.Function("glGetTexParameterfv");
	glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)_functions.Function("glGetTexParameteriv");
	glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)_functions.Function("glGetTexLevelParameterfv");
	glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)_functions.Function("glGetTexLevelParameteriv");
	glIsEnabled = (PFNGLISENABLEDPROC)_functions.Function("glIsEnabled");
	glDepthRange = (PFNGLDEPTHRANGEPROC)_functions.Function("glDepthRange");
	glViewport = (PFNGLVIEWPORTPROC)_functions.Function("glViewport");
	glNewList = (PFNGLNEWLISTPROC)_functions.Function("glNewList");
	glEndList = (PFNGLENDLISTPROC)_functions.Function("glEndList");
	glCallList = (PFNGLCALLLISTPROC)_functions.Function("glCallList");
	glCallLists = (PFNGLCALLLISTSPROC)_functions.Function("glCallLists");
	glDeleteLists = (PFNGLDELETELISTSPROC)_functions.Function("glDeleteLists");
	glGenLists = (PFNGLGENLISTSPROC)_functions.Function("glGenLists");
	glListBase = (PFNGLLISTBASEPROC)_functions.Function("glListBase");
	glBegin = (PFNGLBEGINPROC)_functions.Function("glBegin");
	glBitmap = (PFNGLBITMAPPROC)_functions.Function("glBitmap");
	glColor3b = (PFNGLCOLOR3BPROC)_functions.Function("glColor3b");
	glColor3bv = (PFNGLCOLOR3BVPROC)_functions.Function("glColor3bv");
	glColor3d = (PFNGLCOLOR3DPROC)_functions.Function("glColor3d");
	glColor3dv = (PFNGLCOLOR3DVPROC)_functions.Function("glColor3dv");
	glColor3f = (PFNGLCOLOR3FPROC)_functions.Function("glColor3f");
	glColor3fv = (PFNGLCOLOR3FVPROC)_functions.Function("glColor3fv");
	glColor3i = (PFNGLCOLOR3IPROC)_functions.Function("glColor3i");
	glColor3iv = (PFNGLCOLOR3IVPROC)_functions.Function("glColor3iv");
	glColor3s = (PFNGLCOLOR3SPROC)_functions.Function("glColor3s");
	glColor3sv = (PFNGLCOLOR3SVPROC)_functions.Function("glColor3sv");
	glColor3ub = (PFNGLCOLOR3UBPROC)_functions.Function("glColor3ub");
	glColor3ubv = (PFNGLCOLOR3UBVPROC)_functions.Function("glColor3ubv");
	glColor3ui = (PFNGLCOLOR3UIPROC)_functions.Function("glColor3ui");
	glColor3uiv = (PFNGLCOLOR3UIVPROC)_functions.Function("glColor3uiv");
	glColor3us = (PFNGLCOLOR3USPROC)_functions.Function("glColor3us");
	glColor3usv = (PFNGLCOLOR3USVPROC)_functions.Function("glColor3usv");
	glColor4b = (PFNGLCOLOR4BPROC)_functions.Function("glColor4b");
	glColor4bv = (PFNGLCOLOR4BVPROC)_functions.Function("glColor4bv");
	glColor4d = (PFNGLCOLOR4DPROC)_functions.Function("glColor4d");
	glColor4dv = (PFNGLCOLOR4DVPROC)_functions.Function("glColor4dv");
	glColor4f = (PFNGLCOLOR4FPROC)_functions.Function("glColor4f");
	glColor4fv = (PFNGLCOLOR4FVPROC)_functions.Function("glColor4fv");
	glColor4i = (PFNGLCOLOR4IPROC)_functions.Function("glColor4i");
	glColor4iv = (PFNGLCOLOR4IVPROC)_functions.Function("glColor4iv");
	glColor4s = (PFNGLCOLOR4SPROC)_functions.Function("glColor4s");
	glColor4sv = (PFNGLCOLOR4SVPROC)_functions.Function("glColor4sv");
	glColor4ub = (PFNGLCOLOR4UBPROC)_functions.Function("glColor4ub");
	glColor4ubv = (PFNGLCOLOR4UBVPROC)_functions.Function("glColor4ubv");
	glColor4ui = (PFNGLCOLOR4UIPROC)_functions.Function("glColor4ui");
	glColor4uiv = (PFNGLCOLOR4UIVPROC)_functions.Function("glColor4uiv");
	glColor4us = (PFNGLCOLOR4USPROC)_functions.Function("glColor4us");
	glColor4usv = (PFNGLCOLOR4USVPROC)_functions.Function("glColor4usv");
	glEdgeFlag = (PFNGLEDGEFLAGPROC)_functions.Function("glEdgeFlag");
	glEdgeFlagv = (PFNGLEDGEFLAGVPROC)_functions.Function("glEdgeFlagv");
	glEnd = (PFNGLENDPROC)_functions.Function("glEnd");
	glIndexd = (PFNGLINDEXDPROC)_functions.Function("glIndexd");
	glIndexdv = (PFNGLINDEXDVPROC)_functions.Function("glIndexdv");
	glIndexf = (PFNGLINDEXFPROC)_functions.Function("glIndexf");
	glIndexfv = (PFNGLINDEXFVPROC)_functions.Function("glIndexfv");
	glIndexi = (PFNGLINDEXIPROC)_functions.Function("glIndexi");
	glIndexiv = (PFNGLINDEXIVPROC)_functions.Function("glIndexiv");
	glIndexs = (PFNGLINDEXSPROC)_functions.Function("glIndexs");
	glIndexsv = (PFNGLINDEXSVPROC)_functions.Function("glIndexsv");
	glNormal3b = (PFNGLNORMAL3BPROC)_functions.Function("glNormal3b");
	glNormal3bv = (PFNGLNORMAL3BVPROC)_functions.Function("glNormal3bv");
	glNormal3d = (PFNGLNORMAL3DPROC)_functions.Function("glNormal3d");
	glNormal3dv = (PFNGLNORMAL3DVPROC)_functions.Function("glNormal3dv");
	glNormal3f = (PFNGLNORMAL3FPROC)_functions.Function("glNormal3f");
	glNormal3fv = (PFNGLNORMAL3FVPROC)_functions.Function("glNormal3fv");
	glNormal3i = (PFNGLNORMAL3IPROC)_functions.Function("glNormal3i");
	glNormal3iv = (PFNGLNORMAL3IVPROC)_functions.Function("glNormal3iv");
	glNormal3s = (PFNGLNORMAL3SPROC)_functions.Function("glNormal3s");
	glNormal3sv = (PFNGLNORMAL3SVPROC)_functions.Function("glNormal3sv");
	glRasterPos2d = (PFNGLRASTERPOS2DPROC)_functions.Function("glRasterPos2d");
	glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)_functions.Function("glRasterPos2dv");
	glRasterPos2f = (PFNGLRASTERPOS2FPROC)_functions.Function("glRasterPos2f");
	glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)_functions.Function("glRasterPos2fv");
	glRasterPos2i = (PFNGLRASTERPOS2IPROC)_functions.Function("glRasterPos2i");
	glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)_functions.Function("glRasterPos2iv");
	glRasterPos2s = (PFNGLRASTERPOS2SPROC)_functions.Function("glRasterPos2s");
	glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)_functions.Function("glRasterPos2sv");
	glRasterPos3d = (PFNGLRASTERPOS3DPROC)_functions.Function("glRasterPos3d");
	glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)_functions.Function("glRasterPos3dv");
	glRasterPos3f = (PFNGLRASTERPOS3FPROC)_functions.Function("glRasterPos3f");
	glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)_functions.Function("glRasterPos3fv");
	glRasterPos3i = (PFNGLRASTERPOS3IPROC)_functions.Function("glRasterPos3i");
	glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)_functions.Function("glRasterPos3iv");
	glRasterPos3s = (PFNGLRASTERPOS3SPROC)_functions.Function("glRasterPos3s");
	glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)_functions.Function("glRasterPos3sv");
	glRasterPos4d = (PFNGLRASTERPOS4DPROC)_functions.Function("glRasterPos4d");
	glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)_functions.Function("glRasterPos4dv");
	glRasterPos4f = (PFNGLRASTERPOS4FPROC)_functions.Function("glRasterPos4f");
	glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)_functions.Function("glRasterPos4fv");
	glRasterPos4i = (PFNGLRASTERPOS4IPROC)_functions.Function("glRasterPos4i");
	glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)_functions.Function("glRasterPos4iv");
	glRasterPos4s = (PFNGLRASTERPOS4SPROC)_functions.Function("glRasterPos4s");
	glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)_functions.Function("glRasterPos4sv");
	glRectd = (PFNGLRECTDPROC)_functions.Function("glRectd");
	glRectdv = (PFNGLRECTDVPROC)_functions.Function("glRectdv");
	glRectf = (PFNGLRECTFPROC)_functions.Function("glRectf");
	glRectfv = (PFNGLRECTFVPROC)_functions.Function("glRectfv");
	glRecti = (PFNGLRECTIPROC)_functions.Function("glRecti");
	glRectiv = (PFNGLRECTIVPROC)_functions.Function("glRectiv");
	glRects = (PFNGLRECTSPROC)_functions.Function("glRects");
	glRectsv = (PFNGLRECTSVPROC)_functions.Function("glRectsv");
	glTexCoord1d = (PFNGLTEXCOORD1DPROC)_functions.Function("glTexCoord1d");
	glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)_functions.Function("glTexCoord1dv");
	glTexCoord1f = (PFNGLTEXCOORD1FPROC)_functions.Function("glTexCoord1f");
	glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)_functions.Function("glTexCoord1fv");
	glTexCoord1i = (PFNGLTEXCOORD1IPROC)_functions.Function("glTexCoord1i");
	glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)_functions.Function("glTexCoord1iv");
	glTexCoord1s = (PFNGLTEXCOORD1SPROC)_functions.Function("glTexCoord1s");
	glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)_functions.Function("glTexCoord1sv");
	glTexCoord2d = (PFNGLTEXCOORD2DPROC)_functions.Function("glTexCoord2d");
	glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)_functions.Function("glTexCoord2dv");
	glTexCoord2f = (PFNGLTEXCOORD2FPROC)_functions.Function("glTexCoord2f");
	glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)_functions.Function("glTexCoord2fv");
	glTexCoord2i = (PFNGLTEXCOORD2IPROC)_functions.Function("glTexCoord2i");
	glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)_functions.Function("glTexCoord2iv");
	glTexCoord2s = (PFNGLTEXCOORD2SPROC)_functions.Function("glTexCoord2s");
	glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)_functions.Function("glTexCoord2sv");
	glTexCoord3d = (PFNGLTEXCOORD3DPROC)_functions.Function("glTexCoord3d");
	glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)_functions.Function("glTexCoord3dv");
	glTexCoord3f = (PFNGLTEXCOORD3FPROC)_functions.Function("glTexCoord3f");
	glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)_functions.Function("glTexCoord3fv");
	glTexCoord3i = (PFNGLTEXCOORD3IPROC)_functions.Function("glTexCoord3i");
	glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)_functions.Function("glTexCoord3iv");
	glTexCoord3s = (PFNGLTEXCOORD3SPROC)_functions.Function("glTexCoord3s");
	glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)_functions.Function("glTexCoord3sv");
	glTexCoord4d = (PFNGLTEXCOORD4DPROC)_functions.Function("glTexCoord4d");
	glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)_functions.Function("glTexCoord4dv");
	glTexCoord4f = (PFNGLTEXCOORD4FPROC)_functions.Function("glTexCoord4f");
	glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)_functions.Function("glTexCoord4fv");
	glTexCoord4i = (PFNGLTEXCOORD4IPROC)_functions.Function("glTexCoord4i");
	glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)_functions.Function("glTexCoord4iv");
	glTexCoord4s = (PFNGLTEXCOORD4SPROC)_functions.Function("glTexCoord4s");
	glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)_functions.Function("glTexCoord4sv");
	glVertex2d = (PFNGLVERTEX2DPROC)_functions.Function("glVertex2d");
	glVertex2dv = (PFNGLVERTEX2DVPROC)_functions.Function("glVertex2dv");
	glVertex2f = (PFNGLVERTEX2FPROC)_functions.Function("glVertex2f");
	glVertex2fv = (PFNGLVERTEX2FVPROC)_functions.Function("glVertex2fv");
	glVertex2i = (PFNGLVERTEX2IPROC)_functions.Function("glVertex2i");
	glVertex2iv = (PFNGLVERTEX2IVPROC)_functions.Function("glVertex2iv");
	glVertex2s = (PFNGLVERTEX2SPROC)_functions.Function("glVertex2s");
	glVertex2sv = (PFNGLVERTEX2SVPROC)_functions.Function("glVertex2sv");
	glVertex3d = (PFNGLVERTEX3DPROC)_functions.Function("glVertex3d");
	glVertex3dv = (PFNGLVERTEX3DVPROC)_functions.Function("glVertex3dv");
	glVertex3f = (PFNGLVERTEX3FPROC)_functions.Function("glVertex3f");
	glVertex3fv = (PFNGLVERTEX3FVPROC)_functions.Function("glVertex3fv");
	glVertex3i = (PFNGLVERTEX3IPROC)_functions.Function("glVertex3i");
	glVertex3iv = (PFNGLVERTEX3IVPROC)_functions.Function("glVertex3iv");
	glVertex3s = (PFNGLVERTEX3SPROC)_functions.Function("glVertex3s");
	glVertex3sv = (PFNGLVERTEX3SVPROC)_functions.Function("glVertex3sv");
	glVertex4d = (PFNGLVERTEX4DPROC)_functions.Function("glVertex4d");
	glVertex4dv = (PFNGLVERTEX4DVPROC)_functions.Function("glVertex4dv");
	glVertex4f = (PFNGLVERTEX4FPROC)_functions.Function("glVertex4f");
	glVertex4fv = (PFNGLVERTEX4FVPROC)_functions.Function("glVertex4fv");
	glVertex4i = (PFNGLVERTEX4IPROC)_functions.Function("glVertex4i");
	glVertex4iv = (PFNGLVERTEX4IVPROC)_functions.Function("glVertex4iv");
	glVertex4s = (PFNGLVERTEX4SPROC)_functions.Function("glVertex4s");
	glVertex4sv = (PFNGLVERTEX4SVPROC)_functions.Function("glVertex4sv");
	glClipPlane = (PFNGLCLIPPLANEPROC)_functions.Function("glClipPlane");
	glColorMaterial = (PFNGLCOLORMATERIALPROC)_functions.Function("glColorMaterial");
	glFogf = (PFNGLFOGFPROC)_functions.Function("glFogf");
	glFogfv = (PFNGLFOGFVPROC)_functions.Function("glFogfv");
	glFogi = (PFNGLFOGIPROC)_functions.Function("glFogi");
	glFogiv = (PFNGLFOGIVPROC)_functions.Function("glFogiv");
	glLightf = (PFNGLLIGHTFPROC)_functions.Function("glLightf");
	glLightfv = (PFNGLLIGHTFVPROC)_functions.Function("glLightfv");
	glLighti = (PFNGLLIGHTIPROC)_functions.Function("glLighti");
	glLightiv = (PFNGLLIGHTIVPROC)_functions.Function("glLightiv");
	glLightModelf = (PFNGLLIGHTMODELFPROC)_functions.Function("glLightModelf");
	glLightModelfv = (PFNGLLIGHTMODELFVPROC)_functions.Function("glLightModelfv");
	glLightModeli = (PFNGLLIGHTMODELIPROC)_functions.Function("glLightModeli");
	glLightModeliv = (PFNGLLIGHTMODELIVPROC)_functions.Function("glLightModeliv");
	glLineStipple = (PFNGLLINESTIPPLEPROC)_functions.Function("glLineStipple");
	glMaterialf = (PFNGLMATERIALFPROC)_functions.Function("glMaterialf");
	glMaterialfv = (PFNGLMATERIALFVPROC)_functions.Function("glMaterialfv");
	glMateriali = (PFNGLMATERIALIPROC)_functions.Function("glMateriali");
	glMaterialiv = (PFNGLMATERIALIVPROC)_functions.Function("glMaterialiv");
	glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)_functions.Function("glPolygonStipple");
	glShadeModel = (PFNGLSHADEMODELPROC)_functions.Function("glShadeModel");
	glTexEnvf = (PFNGLTEXENVFPROC)_functions.Function("glTexEnvf");
	glTexEnvfv = (PFNGLTEXENVFVPROC)_functions.Function("glTexEnvfv");
	glTexEnvi = (PFNGLTEXENVIPROC)_functions.Function("glTexEnvi");
	glTexEnviv = (PFNGLTEXENVIVPROC)_functions.Function("glTexEnviv");
	glTexGend = (PFNGLTEXGENDPROC)_functions.Function("glTexGend");
	glTexGendv = (PFNGLTEXGENDVPROC)_functions.Function("glTexGendv");
	glTexGenf = (PFNGLTEXGENFPROC)_functions.Function("glTexGenf");
	glTexGenfv = (PFNGLTEXGENFVPROC)_functions.Function("glTexGenfv");
	glTexGeni = (PFNGLTEXGENIPROC)_functions.Function("glTexGeni");
	glTexGeniv = (PFNGLTEXGENIVPROC)_functions.Function("glTexGeniv");
	glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)_functions.Function("glFeedbackBuffer");
	glSelectBuffer = (PFNGLSELECTBUFFERPROC)_functions.Function("glSelectBuffer");
	glRenderMode = (PFNGLRENDERMODEPROC)_functions.Function("glRenderMode");
	glInitNames = (PFNGLINITNAMESPROC)_functions.Function("glInitNames");
	glLoadName = (PFNGLLOADNAMEPROC)_functions.Function("glLoadName");
	glPassThrough = (PFNGLPASSTHROUGHPROC)_functions.Function("glPassThrough");
	glPopName = (PFNGLPOPNAMEPROC)_functions.Function("glPopName");
	glPushName = (PFNGLPUSHNAMEPROC)_functions.Function("glPushName");
	glClearAccum = (PFNGLCLEARACCUMPROC)_functions.Function("glClearAccum");
	glClearIndex = (PFNGLCLEARINDEXPROC)_functions.Function("glClearIndex");
	glIndexMask = (PFNGLINDEXMASKPROC)_functions.Function("glIndexMask");
	glAccum = (PFNGLACCUMPROC)_functions.Function("glAccum");
	glPopAttrib = (PFNGLPOPATTRIBPROC)_functions.Function("glPopAttrib");
	glPushAttrib = (PFNGLPUSHATTRIBPROC)_functions.Function("glPushAttrib");
	glMap1d = (PFNGLMAP1DPROC)_functions.Function("glMap1d");
	glMap1f = (PFNGLMAP1FPROC)_functions.Function("glMap1f");
	glMap2d = (PFNGLMAP2DPROC)_functions.Function("glMap2d");
	glMap2f = (PFNGLMAP2FPROC)_functions.Function("glMap2f");
	glMapGrid1d = (PFNGLMAPGRID1DPROC)_functions.Function("glMapGrid1d");
	glMapGrid1f = (PFNGLMAPGRID1FPROC)_functions.Function("glMapGrid1f");
	glMapGrid2d = (PFNGLMAPGRID2DPROC)_functions.Function("glMapGrid2d");
	glMapGrid2f = (PFNGLMAPGRID2FPROC)_functions.Function("glMapGrid2f");
	glEvalCoord1d = (PFNGLEVALCOORD1DPROC)_functions.Function("glEvalCoord1d");
	glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)_functions.Function("glEvalCoord1dv");
	glEvalCoord1f = (PFNGLEVALCOORD1FPROC)_functions.Function("glEvalCoord1f");
	glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)_functions.Function("glEvalCoord1fv");
	glEvalCoord2d = (PFNGLEVALCOORD2DPROC)_functions.Function("glEvalCoord2d");
	glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)_functions.Function("glEvalCoord2dv");
	glEvalCoord2f = (PFNGLEVALCOORD2FPROC)_functions.Function("glEvalCoord2f");
	glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)_functions.Function("glEvalCoord2fv");
	glEvalMesh1 = (PFNGLEVALMESH1PROC)_functions.Function("glEvalMesh1");
	glEvalPoint1 = (PFNGLEVALPOINT1PROC)_functions.Function("glEvalPoint1");
	glEvalMesh2 = (PFNGLEVALMESH2PROC)_functions.Function("glEvalMesh2");
	glEvalPoint2 = (PFNGLEVALPOINT2PROC)_functions.Function("glEvalPoint2");
	glAlphaFunc = (PFNGLALPHAFUNCPROC)_functions.Function("glAlphaFunc");
	glPixelZoom = (PFNGLPIXELZOOMPROC)_functions.Function("glPixelZoom");
	glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)_functions.Function("glPixelTransferf");
	glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)_functions.Function("glPixelTransferi");
	glPixelMapfv = (PFNGLPIXELMAPFVPROC)_functions.Function("glPixelMapfv");
	glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)_functions.Function("glPixelMapuiv");
	glPixelMapusv = (PFNGLPIXELMAPUSVPROC)_functions.Function("glPixelMapusv");
	glCopyPixels = (PFNGLCOPYPIXELSPROC)_functions.Function("glCopyPixels");
	glDrawPixels = (PFNGLDRAWPIXELSPROC)_functions.Function("glDrawPixels");
	glGetClipPlane = (PFNGLGETCLIPPLANEPROC)_functions.Function("glGetClipPlane");
	glGetLightfv = (PFNGLGETLIGHTFVPROC)_functions.Function("glGetLightfv");
	glGetLightiv = (PFNGLGETLIGHTIVPROC)_functions.Function("glGetLightiv");
	glGetMapdv = (PFNGLGETMAPDVPROC)_functions.Function("glGetMapdv");
	glGetMapfv = (PFNGLGETMAPFVPROC)_functions.Function("glGetMapfv");
	glGetMapiv = (PFNGLGETMAPIVPROC)_functions.Function("glGetMapiv");
	glGetMaterialfv = (PFNGLGETMATERIALFVPROC)_functions.Function("glGetMaterialfv");
	glGetMaterialiv = (PFNGLGETMATERIALIVPROC)_functions.Function("glGetMaterialiv");
	glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)_functions.Function("glGetPixelMapfv");
	glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)_functions.Function("glGetPixelMapuiv");
	glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)_functions.Function("glGetPixelMapusv");
	glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)_functions.Function("glGetPolygonStipple");
	glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)_functions.Function("glGetTexEnvfv");
	glGetTexEnviv = (PFNGLGETTEXENVIVPROC)_functions.Function("glGetTexEnviv");
	glGetTexGendv = (PFNGLGETTEXGENDVPROC)_functions.Function("glGetTexGendv");
	glGetTexGenfv = (PFNGLGETTEXGENFVPROC)_functions.Function("glGetTexGenfv");
	glGetTexGeniv = (PFNGLGETTEXGENIVPROC)_functions.Function("glGetTexGeniv");
	glIsList = (PFNGLISLISTPROC)_functions.Function("glIsList");
	glFrustum = (PFNGLFRUSTUMPROC)_functions.Function("glFrustum");
	glLoadIdentity = (PFNGLLOADIDENTITYPROC)_functions.Function("glLoadIdentity");
	glLoadMatrixf = (PFNGLLOADMATRIXFPROC)_functions.Function("glLoadMatrixf");
	glLoadMatrixd = (PFNGLLOADMATRIXDPROC)_functions.Function("glLoadMatrixd");
	glMatrixMode = (PFNGLMATRIXMODEPROC)_functions.Function("glMatrixMode");
	glMultMatrixf = (PFNGLMULTMATRIXFPROC)_functions.Function("glMultMatrixf");
	glMultMatrixd = (PFNGLMULTMATRIXDPROC)_functions.Function("glMultMatrixd");
	glOrtho = (PFNGLORTHOPROC)_functions.Function("glOrtho");
	glPopMatrix = (PFNGLPOPMATRIXPROC)_functions.Function("glPopMatrix");
	glPushMatrix = (PFNGLPUSHMATRIXPROC)_functions.Function("glPushMatrix");
	glRotated = (PFNGLROTATEDPROC)_functions.Function("glRotated");
	glRotatef = (PFNGLROTATEFPROC)_functions.Function("glRotatef");
	glScaled = (PFNGLSCALEDPROC)_functions.Function("glScaled");
	glScalef = (PFNGLSCALEFPROC)_functions.Function("glScalef");
	glTranslated = (PFNGLTRANSLATEDPROC)_functions.Function("glTranslated");
	glTranslatef = (PFNGLTRANSLATEFPROC)_functions.Function("glTranslatef");
}

void OpenGLLoader::Init_1_1()
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

void OpenGLLoader::Init_1_2()
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)_functions.Function("glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)_functions.Function("glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)_functions.Function("glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)_functions.Function("glCopyTexSubImage3D");
}

void OpenGLLoader::Init_1_3()
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

void OpenGLLoader::Init_1_4()
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

void OpenGLLoader::Init_1_5()
{
	glGenQueries = (PFNGLGENQUERIESPROC)_functions.Function("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)_functions.Function("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)_functions.Function("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)_functions.Function("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)_functions.Function("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)_functions.Function("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)_functions.Function("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)_functions.Function("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)_functions.Function("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)_functions.Function("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)_functions.Function("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)_functions.Function("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)_functions.Function("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)_functions.Function("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)_functions.Function("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)_functions.Function("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)_functions.Function("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)_functions.Function("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)_functions.Function("glGetBufferPointerv");
}

void OpenGLLoader::Init_2_0()
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

void OpenGLLoader::Init_2_1()
{
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)_functions.Function("glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)_functions.Function("glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)_functions.Function("glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)_functions.Function("glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)_functions.Function("glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)_functions.Function("glUniformMatrix4x3fv");
}

void OpenGLLoader::Init_3_0()
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

void OpenGLLoader::Init_3_1()
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)_functions.Function("glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)_functions.Function("glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)_functions.Function("glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)_functions.Function("glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)_functions.Function("glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)_functions.Function("glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)_functions.Function("glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)_functions.Function("glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)_functions.Function("glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)_functions.Function("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)_functions.Function("glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)_functions.Function("glUniformBlockBinding");
}

void OpenGLLoader::Init_3_2()
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)_functions.Function("glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)_functions.Function("glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)_functions.Function("glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)_functions.Function("glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)_functions.Function("glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)_functions.Function("glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)_functions.Function("glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)_functions.Function("glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)_functions.Function("glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)_functions.Function("glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)_functions.Function("glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)_functions.Function("glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)_functions.Function("glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)_functions.Function("glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)_functions.Function("glFramebufferTexture");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)_functions.Function("glTexImage2DMultisample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)_functions.Function("glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)_functions.Function("glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)_functions.Function("glSampleMaski");
}

void OpenGLLoader::Init_3_3()
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

void OpenGLLoader::Init_4_0()
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

void OpenGLLoader::Init_4_1()
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

void OpenGLLoader::Init_4_2()
{
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)_functions.Function("glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)_functions.Function("glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)_functions.Function("glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)_functions.Function("glGetInternalformativ");
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)_functions.Function("glGetActiveAtomicCounterBufferiv");
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)_functions.Function("glBindImageTexture");
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)_functions.Function("glMemoryBarrier");
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)_functions.Function("glTexStorage1D");
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)_functions.Function("glTexStorage2D");
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)_functions.Function("glTexStorage3D");
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)_functions.Function("glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)_functions.Function("glDrawTransformFeedbackStreamInstanced");
}

void OpenGLLoader::Init_4_3()
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

void OpenGLLoader::Init_4_4()
{
	glBufferStorage = (PFNGLBUFFERSTORAGEPROC)_functions.Function("glBufferStorage");
	glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)_functions.Function("glClearTexImage");
	glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)_functions.Function("glClearTexSubImage");
	glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)_functions.Function("glBindBuffersBase");
	glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)_functions.Function("glBindBuffersRange");
	glBindTextures = (PFNGLBINDTEXTURESPROC)_functions.Function("glBindTextures");
	glBindSamplers = (PFNGLBINDSAMPLERSPROC)_functions.Function("glBindSamplers");
	glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)_functions.Function("glBindImageTextures");
	glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)_functions.Function("glBindVertexBuffers");

}

void OpenGLLoader::Init_4_5()
{
	glClipControl = (PFNGLCLIPCONTROLPROC)_functions.Function("glClipControl");
	glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)_functions.Function("glCreateTransformFeedbacks");
	glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)_functions.Function("glTransformFeedbackBufferBase");
	glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)_functions.Function("glTransformFeedbackBufferRange");
	glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)_functions.Function("glGetTransformFeedbackiv");
	glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)_functions.Function("glGetTransformFeedbacki_v");
	glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)_functions.Function("glGetTransformFeedbacki64_v");
	glCreateBuffers = (PFNGLCREATEBUFFERSPROC)_functions.Function("glCreateBuffers");
	glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)_functions.Function("glNamedBufferStorage");
	glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)_functions.Function("glNamedBufferData");
	glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)_functions.Function("glNamedBufferSubData");
	glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)_functions.Function("glCopyNamedBufferSubData");
	glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)_functions.Function("glClearNamedBufferData");
	glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)_functions.Function("glClearNamedBufferSubData");
	glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)_functions.Function("glMapNamedBuffer");
	glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)_functions.Function("glMapNamedBufferRange");
	glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)_functions.Function("glUnmapNamedBuffer");
	glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)_functions.Function("glFlushMappedNamedBufferRange");
	glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)_functions.Function("glGetNamedBufferParameteriv");
	glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)_functions.Function("glGetNamedBufferParameteri64v");
	glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)_functions.Function("glGetNamedBufferPointerv");
	glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)_functions.Function("glGetNamedBufferSubData");
	glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)_functions.Function("glCreateFramebuffers");
	glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)_functions.Function("glNamedFramebufferRenderbuffer");
	glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)_functions.Function("glNamedFramebufferParameteri");
	glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)_functions.Function("glNamedFramebufferTexture");
	glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)_functions.Function("glNamedFramebufferTextureLayer");
	glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)_functions.Function("glNamedFramebufferDrawBuffer");
	glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)_functions.Function("glNamedFramebufferDrawBuffers");
	glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)_functions.Function("glNamedFramebufferReadBuffer");
	glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)_functions.Function("glInvalidateNamedFramebufferData");
	glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)_functions.Function("glInvalidateNamedFramebufferSubData");
	glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)_functions.Function("glClearNamedFramebufferiv");
	glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)_functions.Function("glClearNamedFramebufferuiv");
	glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)_functions.Function("glClearNamedFramebufferfv");
	glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)_functions.Function("glClearNamedFramebufferfi");
	glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)_functions.Function("glBlitNamedFramebuffer");
	glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)_functions.Function("glCheckNamedFramebufferStatus");
	glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)_functions.Function("glGetNamedFramebufferParameteriv");
	glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)_functions.Function("glGetNamedFramebufferAttachmentParameteriv");
	glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)_functions.Function("glCreateRenderbuffers");
	glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)_functions.Function("glNamedRenderbufferStorage");
	glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)_functions.Function("glNamedRenderbufferStorageMultisample");
	glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)_functions.Function("glGetNamedRenderbufferParameteriv");
	glCreateTextures = (PFNGLCREATETEXTURESPROC)_functions.Function("glCreateTextures");
	glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)_functions.Function("glTextureBuffer");
	glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)_functions.Function("glTextureBufferRange");
	glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)_functions.Function("glTextureStorage1D");
	glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)_functions.Function("glTextureStorage2D");
	glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)_functions.Function("glTextureStorage3D");
	glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)_functions.Function("glTextureStorage2DMultisample");
	glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)_functions.Function("glTextureStorage3DMultisample");
	glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)_functions.Function("glTextureSubImage1D");
	glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)_functions.Function("glTextureSubImage2D");
	glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)_functions.Function("glTextureSubImage3D");
	glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)_functions.Function("glCompressedTextureSubImage1D");
	glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)_functions.Function("glCompressedTextureSubImage2D");
	glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)_functions.Function("glCompressedTextureSubImage3D");
	glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)_functions.Function("glCopyTextureSubImage1D");
	glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)_functions.Function("glCopyTextureSubImage2D");
	glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)_functions.Function("glCopyTextureSubImage3D");
	glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)_functions.Function("glTextureParameterf");
	glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)_functions.Function("glTextureParameterfv");
	glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)_functions.Function("glTextureParameteri");
	glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)_functions.Function("glTextureParameterIiv");
	glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)_functions.Function("glTextureParameterIuiv");
	glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)_functions.Function("glTextureParameteriv");
	glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)_functions.Function("glGenerateTextureMipmap");
	glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)_functions.Function("glBindTextureUnit");
	glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)_functions.Function("glGetTextureImage");
	glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)_functions.Function("glGetCompressedTextureImage");
	glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)_functions.Function("glGetTextureLevelParameterfv");
	glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)_functions.Function("glGetTextureLevelParameteriv");
	glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)_functions.Function("glGetTextureParameterfv");
	glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)_functions.Function("glGetTextureParameterIiv");
	glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)_functions.Function("glGetTextureParameterIuiv");
	glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)_functions.Function("glGetTextureParameteriv");
	glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)_functions.Function("glCreateVertexArrays");
	glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)_functions.Function("glDisableVertexArrayAttrib");
	glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)_functions.Function("glEnableVertexArrayAttrib");
	glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)_functions.Function("glVertexArrayElementBuffer");
	glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)_functions.Function("glVertexArrayVertexBuffer");
	glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)_functions.Function("glVertexArrayVertexBuffers");
	glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)_functions.Function("glVertexArrayAttribBinding");
	glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)_functions.Function("glVertexArrayAttribFormat");
	glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)_functions.Function("glVertexArrayAttribIFormat");
	glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)_functions.Function("glVertexArrayAttribLFormat");
	glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)_functions.Function("glVertexArrayBindingDivisor");
	glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)_functions.Function("glGetVertexArrayiv");
	glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)_functions.Function("glGetVertexArrayIndexediv");
	glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)_functions.Function("glGetVertexArrayIndexed64iv");
	glCreateSamplers = (PFNGLCREATESAMPLERSPROC)_functions.Function("glCreateSamplers");
	glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)_functions.Function("glCreateProgramPipelines");
	glCreateQueries = (PFNGLCREATEQUERIESPROC)_functions.Function("glCreateQueries");
	glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)_functions.Function("glGetQueryBufferObjecti64v");
	glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)_functions.Function("glGetQueryBufferObjectiv");
	glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)_functions.Function("glGetQueryBufferObjectui64v");
	glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)_functions.Function("glGetQueryBufferObjectuiv");
	glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)_functions.Function("glMemoryBarrierByRegion");
	glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)_functions.Function("glGetTextureSubImage");
	glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)_functions.Function("glGetCompressedTextureSubImage");
	glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)_functions.Function("glGetGraphicsResetStatus");
	glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)_functions.Function("glGetnCompressedTexImage");
	glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)_functions.Function("glGetnTexImage");
	glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)_functions.Function("glGetnUniformdv");
	glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)_functions.Function("glGetnUniformfv");
	glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)_functions.Function("glGetnUniformiv");
	glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)_functions.Function("glGetnUniformuiv");
	glReadnPixels = (PFNGLREADNPIXELSPROC)_functions.Function("glReadnPixels");
	glGetnMapdv = (PFNGLGETNMAPDVPROC)_functions.Function("glGetnMapdv");
	glGetnMapfv = (PFNGLGETNMAPFVPROC)_functions.Function("glGetnMapfv");
	glGetnMapiv = (PFNGLGETNMAPIVPROC)_functions.Function("glGetnMapiv");
	glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)_functions.Function("glGetnPixelMapfv");
	glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)_functions.Function("glGetnPixelMapuiv");
	glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)_functions.Function("glGetnPixelMapusv");
	glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)_functions.Function("glGetnPolygonStipple");
	glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)_functions.Function("glGetnColorTable");
	glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)_functions.Function("glGetnConvolutionFilter");
	glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)_functions.Function("glGetnSeparableFilter");
	glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)_functions.Function("glGetnHistogram");
	glGetnMinmax = (PFNGLGETNMINMAXPROC)_functions.Function("glGetnMinmax");
	glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)_functions.Function("glTextureBarrier");
}

void OpenGLLoader::Init_4_6()
{
	glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)_functions.Function("glSpecializeShader");
	glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)_functions.Function("glMultiDrawArraysIndirectCount");
	glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)_functions.Function("glMultiDrawElementsIndirectCount");
	glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)_functions.Function("glPolygonOffsetClamp");
}
