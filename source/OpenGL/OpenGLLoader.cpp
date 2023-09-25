#include <LDL/OpenGL/OpenGLLoader.hpp>
#include <LDL/OpenGL/OpenGL4_6.hpp>
#include <LDL/Low/Conv.hpp>
#include <LDL/Low/String.hpp>

LDL_OpenGLLoader::LDL_OpenGLLoader() :
	_Major(0),
	_Minor(0)
{
}

LDL_OpenGLLoader::LDL_OpenGLLoader(size_t major, size_t minor) :
	_Major(major),
	_Minor(minor)
{
	Init(_Major, _Minor);
}

LDL_OpenGLLoader::~LDL_OpenGLLoader()
{
}

bool LDL_OpenGLLoader::Init(size_t major, size_t minor)
{
	_Major = major;
	_Minor = minor;

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
		LDL_NumberToString conv;

		LDL_String error = "OpenGL ";
		error.Append(conv.Convert(Major()));
		error.Append(".");
		error.Append(conv.Convert(Minor()));
		error.Append(" not support");

		return false;
	}

	return true;
}

bool LDL_OpenGLLoader::Equal(size_t major, size_t minor)
{
	return Major() == major && Minor() == minor;
}

size_t LDL_OpenGLLoader::Major()
{
	return _Major;
}

size_t LDL_OpenGLLoader::Minor()
{
	return _Minor;
}

void LDL_OpenGLLoader::Init_1_0()
{
	glCullFace = (PFNGLCULLFACEPROC)_Functions.Function("glCullFace");
	glFrontFace = (PFNGLFRONTFACEPROC)_Functions.Function("glFrontFace");
	glHint = (PFNGLHINTPROC)_Functions.Function("glHint");
	glLineWidth = (PFNGLLINEWIDTHPROC)_Functions.Function("glLineWidth");
	glPointSize = (PFNGLPOINTSIZEPROC)_Functions.Function("glPointSize");
	glPolygonMode = (PFNGLPOLYGONMODEPROC)_Functions.Function("glPolygonMode");
	glScissor = (PFNGLSCISSORPROC)_Functions.Function("glScissor");
	glTexParameterf = (PFNGLTEXPARAMETERFPROC)_Functions.Function("glTexParameterf");
	glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)_Functions.Function("glTexParameterfv");
	glTexParameteri = (PFNGLTEXPARAMETERIPROC)_Functions.Function("glTexParameteri");
	glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)_Functions.Function("glTexParameteriv");
	glTexImage1D = (PFNGLTEXIMAGE1DPROC)_Functions.Function("glTexImage1D");
	glTexImage2D = (PFNGLTEXIMAGE2DPROC)_Functions.Function("glTexImage2D");
	glDrawBuffer = (PFNGLDRAWBUFFERPROC)_Functions.Function("glDrawBuffer");
	glClear = (PFNGLCLEARPROC)_Functions.Function("glClear");
	glClearColor = (PFNGLCLEARCOLORPROC)_Functions.Function("glClearColor");
	glClearStencil = (PFNGLCLEARSTENCILPROC)_Functions.Function("glClearStencil");
	glClearDepth = (PFNGLCLEARDEPTHPROC)_Functions.Function("glClearDepth");
	glStencilMask = (PFNGLSTENCILMASKPROC)_Functions.Function("glStencilMask");
	glColorMask = (PFNGLCOLORMASKPROC)_Functions.Function("glColorMask");
	glDepthMask = (PFNGLDEPTHMASKPROC)_Functions.Function("glDepthMask");
	glDisable = (PFNGLDISABLEPROC)_Functions.Function("glDisable");
	glEnable = (PFNGLENABLEPROC)_Functions.Function("glEnable");
	glFinish = (PFNGLFINISHPROC)_Functions.Function("glFinish");
	glFlush = (PFNGLFLUSHPROC)_Functions.Function("glFlush");
	glBlendFunc = (PFNGLBLENDFUNCPROC)_Functions.Function("glBlendFunc");
	glLogicOp = (PFNGLLOGICOPPROC)_Functions.Function("glLogicOp");
	glStencilFunc = (PFNGLSTENCILFUNCPROC)_Functions.Function("glStencilFunc");
	glStencilOp = (PFNGLSTENCILOPPROC)_Functions.Function("glStencilOp");
	glDepthFunc = (PFNGLDEPTHFUNCPROC)_Functions.Function("glDepthFunc");
	glPixelStoref = (PFNGLPIXELSTOREFPROC)_Functions.Function("glPixelStoref");
	glPixelStorei = (PFNGLPIXELSTOREIPROC)_Functions.Function("glPixelStorei");
	glReadBuffer = (PFNGLREADBUFFERPROC)_Functions.Function("glReadBuffer");
	glReadPixels = (PFNGLREADPIXELSPROC)_Functions.Function("glReadPixels");
	glGetBooleanv = (PFNGLGETBOOLEANVPROC)_Functions.Function("glGetBooleanv");
	glGetDoublev = (PFNGLGETDOUBLEVPROC)_Functions.Function("glGetDoublev");
	glGetError = (PFNGLGETERRORPROC)_Functions.Function("glGetError");
	glGetFloatv = (PFNGLGETFLOATVPROC)_Functions.Function("glGetFloatv");
	glGetIntegerv = (PFNGLGETINTEGERVPROC)_Functions.Function("glGetIntegerv");
	glGetString = (PFNGLGETSTRINGPROC)_Functions.Function("glGetString");
	glGetTexImage = (PFNGLGETTEXIMAGEPROC)_Functions.Function("glGetTexImage");
	glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)_Functions.Function("glGetTexParameterfv");
	glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)_Functions.Function("glGetTexParameteriv");
	glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)_Functions.Function("glGetTexLevelParameterfv");
	glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)_Functions.Function("glGetTexLevelParameteriv");
	glIsEnabled = (PFNGLISENABLEDPROC)_Functions.Function("glIsEnabled");
	glDepthRange = (PFNGLDEPTHRANGEPROC)_Functions.Function("glDepthRange");
	glViewport = (PFNGLVIEWPORTPROC)_Functions.Function("glViewport");
	glNewList = (PFNGLNEWLISTPROC)_Functions.Function("glNewList");
	glEndList = (PFNGLENDLISTPROC)_Functions.Function("glEndList");
	glCallList = (PFNGLCALLLISTPROC)_Functions.Function("glCallList");
	glCallLists = (PFNGLCALLLISTSPROC)_Functions.Function("glCallLists");
	glDeleteLists = (PFNGLDELETELISTSPROC)_Functions.Function("glDeleteLists");
	glGenLists = (PFNGLGENLISTSPROC)_Functions.Function("glGenLists");
	glListBase = (PFNGLLISTBASEPROC)_Functions.Function("glListBase");
	glBegin = (PFNGLBEGINPROC)_Functions.Function("glBegin");
	glBitmap = (PFNGLBITMAPPROC)_Functions.Function("glBitmap");
	glColor3b = (PFNGLCOLOR3BPROC)_Functions.Function("glColor3b");
	glColor3bv = (PFNGLCOLOR3BVPROC)_Functions.Function("glColor3bv");
	glColor3d = (PFNGLCOLOR3DPROC)_Functions.Function("glColor3d");
	glColor3dv = (PFNGLCOLOR3DVPROC)_Functions.Function("glColor3dv");
	glColor3f = (PFNGLCOLOR3FPROC)_Functions.Function("glColor3f");
	glColor3fv = (PFNGLCOLOR3FVPROC)_Functions.Function("glColor3fv");
	glColor3i = (PFNGLCOLOR3IPROC)_Functions.Function("glColor3i");
	glColor3iv = (PFNGLCOLOR3IVPROC)_Functions.Function("glColor3iv");
	glColor3s = (PFNGLCOLOR3SPROC)_Functions.Function("glColor3s");
	glColor3sv = (PFNGLCOLOR3SVPROC)_Functions.Function("glColor3sv");
	glColor3ub = (PFNGLCOLOR3UBPROC)_Functions.Function("glColor3ub");
	glColor3ubv = (PFNGLCOLOR3UBVPROC)_Functions.Function("glColor3ubv");
	glColor3ui = (PFNGLCOLOR3UIPROC)_Functions.Function("glColor3ui");
	glColor3uiv = (PFNGLCOLOR3UIVPROC)_Functions.Function("glColor3uiv");
	glColor3us = (PFNGLCOLOR3USPROC)_Functions.Function("glColor3us");
	glColor3usv = (PFNGLCOLOR3USVPROC)_Functions.Function("glColor3usv");
	glColor4b = (PFNGLCOLOR4BPROC)_Functions.Function("glColor4b");
	glColor4bv = (PFNGLCOLOR4BVPROC)_Functions.Function("glColor4bv");
	glColor4d = (PFNGLCOLOR4DPROC)_Functions.Function("glColor4d");
	glColor4dv = (PFNGLCOLOR4DVPROC)_Functions.Function("glColor4dv");
	glColor4f = (PFNGLCOLOR4FPROC)_Functions.Function("glColor4f");
	glColor4fv = (PFNGLCOLOR4FVPROC)_Functions.Function("glColor4fv");
	glColor4i = (PFNGLCOLOR4IPROC)_Functions.Function("glColor4i");
	glColor4iv = (PFNGLCOLOR4IVPROC)_Functions.Function("glColor4iv");
	glColor4s = (PFNGLCOLOR4SPROC)_Functions.Function("glColor4s");
	glColor4sv = (PFNGLCOLOR4SVPROC)_Functions.Function("glColor4sv");
	glColor4ub = (PFNGLCOLOR4UBPROC)_Functions.Function("glColor4ub");
	glColor4ubv = (PFNGLCOLOR4UBVPROC)_Functions.Function("glColor4ubv");
	glColor4ui = (PFNGLCOLOR4UIPROC)_Functions.Function("glColor4ui");
	glColor4uiv = (PFNGLCOLOR4UIVPROC)_Functions.Function("glColor4uiv");
	glColor4us = (PFNGLCOLOR4USPROC)_Functions.Function("glColor4us");
	glColor4usv = (PFNGLCOLOR4USVPROC)_Functions.Function("glColor4usv");
	glEdgeFlag = (PFNGLEDGEFLAGPROC)_Functions.Function("glEdgeFlag");
	glEdgeFlagv = (PFNGLEDGEFLAGVPROC)_Functions.Function("glEdgeFlagv");
	glEnd = (PFNGLENDPROC)_Functions.Function("glEnd");
	glIndexd = (PFNGLINDEXDPROC)_Functions.Function("glIndexd");
	glIndexdv = (PFNGLINDEXDVPROC)_Functions.Function("glIndexdv");
	glIndexf = (PFNGLINDEXFPROC)_Functions.Function("glIndexf");
	glIndexfv = (PFNGLINDEXFVPROC)_Functions.Function("glIndexfv");
	glIndexi = (PFNGLINDEXIPROC)_Functions.Function("glIndexi");
	glIndexiv = (PFNGLINDEXIVPROC)_Functions.Function("glIndexiv");
	glIndexs = (PFNGLINDEXSPROC)_Functions.Function("glIndexs");
	glIndexsv = (PFNGLINDEXSVPROC)_Functions.Function("glIndexsv");
	glNormal3b = (PFNGLNORMAL3BPROC)_Functions.Function("glNormal3b");
	glNormal3bv = (PFNGLNORMAL3BVPROC)_Functions.Function("glNormal3bv");
	glNormal3d = (PFNGLNORMAL3DPROC)_Functions.Function("glNormal3d");
	glNormal3dv = (PFNGLNORMAL3DVPROC)_Functions.Function("glNormal3dv");
	glNormal3f = (PFNGLNORMAL3FPROC)_Functions.Function("glNormal3f");
	glNormal3fv = (PFNGLNORMAL3FVPROC)_Functions.Function("glNormal3fv");
	glNormal3i = (PFNGLNORMAL3IPROC)_Functions.Function("glNormal3i");
	glNormal3iv = (PFNGLNORMAL3IVPROC)_Functions.Function("glNormal3iv");
	glNormal3s = (PFNGLNORMAL3SPROC)_Functions.Function("glNormal3s");
	glNormal3sv = (PFNGLNORMAL3SVPROC)_Functions.Function("glNormal3sv");
	glRasterPos2d = (PFNGLRASTERPOS2DPROC)_Functions.Function("glRasterPos2d");
	glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)_Functions.Function("glRasterPos2dv");
	glRasterPos2f = (PFNGLRASTERPOS2FPROC)_Functions.Function("glRasterPos2f");
	glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)_Functions.Function("glRasterPos2fv");
	glRasterPos2i = (PFNGLRASTERPOS2IPROC)_Functions.Function("glRasterPos2i");
	glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)_Functions.Function("glRasterPos2iv");
	glRasterPos2s = (PFNGLRASTERPOS2SPROC)_Functions.Function("glRasterPos2s");
	glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)_Functions.Function("glRasterPos2sv");
	glRasterPos3d = (PFNGLRASTERPOS3DPROC)_Functions.Function("glRasterPos3d");
	glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)_Functions.Function("glRasterPos3dv");
	glRasterPos3f = (PFNGLRASTERPOS3FPROC)_Functions.Function("glRasterPos3f");
	glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)_Functions.Function("glRasterPos3fv");
	glRasterPos3i = (PFNGLRASTERPOS3IPROC)_Functions.Function("glRasterPos3i");
	glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)_Functions.Function("glRasterPos3iv");
	glRasterPos3s = (PFNGLRASTERPOS3SPROC)_Functions.Function("glRasterPos3s");
	glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)_Functions.Function("glRasterPos3sv");
	glRasterPos4d = (PFNGLRASTERPOS4DPROC)_Functions.Function("glRasterPos4d");
	glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)_Functions.Function("glRasterPos4dv");
	glRasterPos4f = (PFNGLRASTERPOS4FPROC)_Functions.Function("glRasterPos4f");
	glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)_Functions.Function("glRasterPos4fv");
	glRasterPos4i = (PFNGLRASTERPOS4IPROC)_Functions.Function("glRasterPos4i");
	glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)_Functions.Function("glRasterPos4iv");
	glRasterPos4s = (PFNGLRASTERPOS4SPROC)_Functions.Function("glRasterPos4s");
	glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)_Functions.Function("glRasterPos4sv");
	glRectd = (PFNGLRECTDPROC)_Functions.Function("glRectd");
	glRectdv = (PFNGLRECTDVPROC)_Functions.Function("glRectdv");
	glRectf = (PFNGLRECTFPROC)_Functions.Function("glRectf");
	glRectfv = (PFNGLRECTFVPROC)_Functions.Function("glRectfv");
	glRecti = (PFNGLRECTIPROC)_Functions.Function("glRecti");
	glRectiv = (PFNGLRECTIVPROC)_Functions.Function("glRectiv");
	glRects = (PFNGLRECTSPROC)_Functions.Function("glRects");
	glRectsv = (PFNGLRECTSVPROC)_Functions.Function("glRectsv");
	glTexCoord1d = (PFNGLTEXCOORD1DPROC)_Functions.Function("glTexCoord1d");
	glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)_Functions.Function("glTexCoord1dv");
	glTexCoord1f = (PFNGLTEXCOORD1FPROC)_Functions.Function("glTexCoord1f");
	glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)_Functions.Function("glTexCoord1fv");
	glTexCoord1i = (PFNGLTEXCOORD1IPROC)_Functions.Function("glTexCoord1i");
	glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)_Functions.Function("glTexCoord1iv");
	glTexCoord1s = (PFNGLTEXCOORD1SPROC)_Functions.Function("glTexCoord1s");
	glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)_Functions.Function("glTexCoord1sv");
	glTexCoord2d = (PFNGLTEXCOORD2DPROC)_Functions.Function("glTexCoord2d");
	glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)_Functions.Function("glTexCoord2dv");
	glTexCoord2f = (PFNGLTEXCOORD2FPROC)_Functions.Function("glTexCoord2f");
	glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)_Functions.Function("glTexCoord2fv");
	glTexCoord2i = (PFNGLTEXCOORD2IPROC)_Functions.Function("glTexCoord2i");
	glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)_Functions.Function("glTexCoord2iv");
	glTexCoord2s = (PFNGLTEXCOORD2SPROC)_Functions.Function("glTexCoord2s");
	glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)_Functions.Function("glTexCoord2sv");
	glTexCoord3d = (PFNGLTEXCOORD3DPROC)_Functions.Function("glTexCoord3d");
	glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)_Functions.Function("glTexCoord3dv");
	glTexCoord3f = (PFNGLTEXCOORD3FPROC)_Functions.Function("glTexCoord3f");
	glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)_Functions.Function("glTexCoord3fv");
	glTexCoord3i = (PFNGLTEXCOORD3IPROC)_Functions.Function("glTexCoord3i");
	glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)_Functions.Function("glTexCoord3iv");
	glTexCoord3s = (PFNGLTEXCOORD3SPROC)_Functions.Function("glTexCoord3s");
	glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)_Functions.Function("glTexCoord3sv");
	glTexCoord4d = (PFNGLTEXCOORD4DPROC)_Functions.Function("glTexCoord4d");
	glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)_Functions.Function("glTexCoord4dv");
	glTexCoord4f = (PFNGLTEXCOORD4FPROC)_Functions.Function("glTexCoord4f");
	glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)_Functions.Function("glTexCoord4fv");
	glTexCoord4i = (PFNGLTEXCOORD4IPROC)_Functions.Function("glTexCoord4i");
	glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)_Functions.Function("glTexCoord4iv");
	glTexCoord4s = (PFNGLTEXCOORD4SPROC)_Functions.Function("glTexCoord4s");
	glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)_Functions.Function("glTexCoord4sv");
	glVertex2d = (PFNGLVERTEX2DPROC)_Functions.Function("glVertex2d");
	glVertex2dv = (PFNGLVERTEX2DVPROC)_Functions.Function("glVertex2dv");
	glVertex2f = (PFNGLVERTEX2FPROC)_Functions.Function("glVertex2f");
	glVertex2fv = (PFNGLVERTEX2FVPROC)_Functions.Function("glVertex2fv");
	glVertex2i = (PFNGLVERTEX2IPROC)_Functions.Function("glVertex2i");
	glVertex2iv = (PFNGLVERTEX2IVPROC)_Functions.Function("glVertex2iv");
	glVertex2s = (PFNGLVERTEX2SPROC)_Functions.Function("glVertex2s");
	glVertex2sv = (PFNGLVERTEX2SVPROC)_Functions.Function("glVertex2sv");
	glVertex3d = (PFNGLVERTEX3DPROC)_Functions.Function("glVertex3d");
	glVertex3dv = (PFNGLVERTEX3DVPROC)_Functions.Function("glVertex3dv");
	glVertex3f = (PFNGLVERTEX3FPROC)_Functions.Function("glVertex3f");
	glVertex3fv = (PFNGLVERTEX3FVPROC)_Functions.Function("glVertex3fv");
	glVertex3i = (PFNGLVERTEX3IPROC)_Functions.Function("glVertex3i");
	glVertex3iv = (PFNGLVERTEX3IVPROC)_Functions.Function("glVertex3iv");
	glVertex3s = (PFNGLVERTEX3SPROC)_Functions.Function("glVertex3s");
	glVertex3sv = (PFNGLVERTEX3SVPROC)_Functions.Function("glVertex3sv");
	glVertex4d = (PFNGLVERTEX4DPROC)_Functions.Function("glVertex4d");
	glVertex4dv = (PFNGLVERTEX4DVPROC)_Functions.Function("glVertex4dv");
	glVertex4f = (PFNGLVERTEX4FPROC)_Functions.Function("glVertex4f");
	glVertex4fv = (PFNGLVERTEX4FVPROC)_Functions.Function("glVertex4fv");
	glVertex4i = (PFNGLVERTEX4IPROC)_Functions.Function("glVertex4i");
	glVertex4iv = (PFNGLVERTEX4IVPROC)_Functions.Function("glVertex4iv");
	glVertex4s = (PFNGLVERTEX4SPROC)_Functions.Function("glVertex4s");
	glVertex4sv = (PFNGLVERTEX4SVPROC)_Functions.Function("glVertex4sv");
	glClipPlane = (PFNGLCLIPPLANEPROC)_Functions.Function("glClipPlane");
	glColorMaterial = (PFNGLCOLORMATERIALPROC)_Functions.Function("glColorMaterial");
	glFogf = (PFNGLFOGFPROC)_Functions.Function("glFogf");
	glFogfv = (PFNGLFOGFVPROC)_Functions.Function("glFogfv");
	glFogi = (PFNGLFOGIPROC)_Functions.Function("glFogi");
	glFogiv = (PFNGLFOGIVPROC)_Functions.Function("glFogiv");
	glLightf = (PFNGLLIGHTFPROC)_Functions.Function("glLightf");
	glLightfv = (PFNGLLIGHTFVPROC)_Functions.Function("glLightfv");
	glLighti = (PFNGLLIGHTIPROC)_Functions.Function("glLighti");
	glLightiv = (PFNGLLIGHTIVPROC)_Functions.Function("glLightiv");
	glLightModelf = (PFNGLLIGHTMODELFPROC)_Functions.Function("glLightModelf");
	glLightModelfv = (PFNGLLIGHTMODELFVPROC)_Functions.Function("glLightModelfv");
	glLightModeli = (PFNGLLIGHTMODELIPROC)_Functions.Function("glLightModeli");
	glLightModeliv = (PFNGLLIGHTMODELIVPROC)_Functions.Function("glLightModeliv");
	glLineStipple = (PFNGLLINESTIPPLEPROC)_Functions.Function("glLineStipple");
	glMaterialf = (PFNGLMATERIALFPROC)_Functions.Function("glMaterialf");
	glMaterialfv = (PFNGLMATERIALFVPROC)_Functions.Function("glMaterialfv");
	glMateriali = (PFNGLMATERIALIPROC)_Functions.Function("glMateriali");
	glMaterialiv = (PFNGLMATERIALIVPROC)_Functions.Function("glMaterialiv");
	glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)_Functions.Function("glPolygonStipple");
	glShadeModel = (PFNGLSHADEMODELPROC)_Functions.Function("glShadeModel");
	glTexEnvf = (PFNGLTEXENVFPROC)_Functions.Function("glTexEnvf");
	glTexEnvfv = (PFNGLTEXENVFVPROC)_Functions.Function("glTexEnvfv");
	glTexEnvi = (PFNGLTEXENVIPROC)_Functions.Function("glTexEnvi");
	glTexEnviv = (PFNGLTEXENVIVPROC)_Functions.Function("glTexEnviv");
	glTexGend = (PFNGLTEXGENDPROC)_Functions.Function("glTexGend");
	glTexGendv = (PFNGLTEXGENDVPROC)_Functions.Function("glTexGendv");
	glTexGenf = (PFNGLTEXGENFPROC)_Functions.Function("glTexGenf");
	glTexGenfv = (PFNGLTEXGENFVPROC)_Functions.Function("glTexGenfv");
	glTexGeni = (PFNGLTEXGENIPROC)_Functions.Function("glTexGeni");
	glTexGeniv = (PFNGLTEXGENIVPROC)_Functions.Function("glTexGeniv");
	glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)_Functions.Function("glFeedbackBuffer");
	glSelectBuffer = (PFNGLSELECTBUFFERPROC)_Functions.Function("glSelectBuffer");
	glRenderMode = (PFNGLRENDERMODEPROC)_Functions.Function("glRenderMode");
	glInitNames = (PFNGLINITNAMESPROC)_Functions.Function("glInitNames");
	glLoadName = (PFNGLLOADNAMEPROC)_Functions.Function("glLoadName");
	glPassThrough = (PFNGLPASSTHROUGHPROC)_Functions.Function("glPassThrough");
	glPopName = (PFNGLPOPNAMEPROC)_Functions.Function("glPopName");
	glPushName = (PFNGLPUSHNAMEPROC)_Functions.Function("glPushName");
	glClearAccum = (PFNGLCLEARACCUMPROC)_Functions.Function("glClearAccum");
	glClearIndex = (PFNGLCLEARINDEXPROC)_Functions.Function("glClearIndex");
	glIndexMask = (PFNGLINDEXMASKPROC)_Functions.Function("glIndexMask");
	glAccum = (PFNGLACCUMPROC)_Functions.Function("glAccum");
	glPopAttrib = (PFNGLPOPATTRIBPROC)_Functions.Function("glPopAttrib");
	glPushAttrib = (PFNGLPUSHATTRIBPROC)_Functions.Function("glPushAttrib");
	glMap1d = (PFNGLMAP1DPROC)_Functions.Function("glMap1d");
	glMap1f = (PFNGLMAP1FPROC)_Functions.Function("glMap1f");
	glMap2d = (PFNGLMAP2DPROC)_Functions.Function("glMap2d");
	glMap2f = (PFNGLMAP2FPROC)_Functions.Function("glMap2f");
	glMapGrid1d = (PFNGLMAPGRID1DPROC)_Functions.Function("glMapGrid1d");
	glMapGrid1f = (PFNGLMAPGRID1FPROC)_Functions.Function("glMapGrid1f");
	glMapGrid2d = (PFNGLMAPGRID2DPROC)_Functions.Function("glMapGrid2d");
	glMapGrid2f = (PFNGLMAPGRID2FPROC)_Functions.Function("glMapGrid2f");
	glEvalCoord1d = (PFNGLEVALCOORD1DPROC)_Functions.Function("glEvalCoord1d");
	glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)_Functions.Function("glEvalCoord1dv");
	glEvalCoord1f = (PFNGLEVALCOORD1FPROC)_Functions.Function("glEvalCoord1f");
	glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)_Functions.Function("glEvalCoord1fv");
	glEvalCoord2d = (PFNGLEVALCOORD2DPROC)_Functions.Function("glEvalCoord2d");
	glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)_Functions.Function("glEvalCoord2dv");
	glEvalCoord2f = (PFNGLEVALCOORD2FPROC)_Functions.Function("glEvalCoord2f");
	glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)_Functions.Function("glEvalCoord2fv");
	glEvalMesh1 = (PFNGLEVALMESH1PROC)_Functions.Function("glEvalMesh1");
	glEvalPoint1 = (PFNGLEVALPOINT1PROC)_Functions.Function("glEvalPoint1");
	glEvalMesh2 = (PFNGLEVALMESH2PROC)_Functions.Function("glEvalMesh2");
	glEvalPoint2 = (PFNGLEVALPOINT2PROC)_Functions.Function("glEvalPoint2");
	glAlphaFunc = (PFNGLALPHAFUNCPROC)_Functions.Function("glAlphaFunc");
	glPixelZoom = (PFNGLPIXELZOOMPROC)_Functions.Function("glPixelZoom");
	glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)_Functions.Function("glPixelTransferf");
	glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)_Functions.Function("glPixelTransferi");
	glPixelMapfv = (PFNGLPIXELMAPFVPROC)_Functions.Function("glPixelMapfv");
	glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)_Functions.Function("glPixelMapuiv");
	glPixelMapusv = (PFNGLPIXELMAPUSVPROC)_Functions.Function("glPixelMapusv");
	glCopyPixels = (PFNGLCOPYPIXELSPROC)_Functions.Function("glCopyPixels");
	glDrawPixels = (PFNGLDRAWPIXELSPROC)_Functions.Function("glDrawPixels");
	glGetClipPlane = (PFNGLGETCLIPPLANEPROC)_Functions.Function("glGetClipPlane");
	glGetLightfv = (PFNGLGETLIGHTFVPROC)_Functions.Function("glGetLightfv");
	glGetLightiv = (PFNGLGETLIGHTIVPROC)_Functions.Function("glGetLightiv");
	glGetMapdv = (PFNGLGETMAPDVPROC)_Functions.Function("glGetMapdv");
	glGetMapfv = (PFNGLGETMAPFVPROC)_Functions.Function("glGetMapfv");
	glGetMapiv = (PFNGLGETMAPIVPROC)_Functions.Function("glGetMapiv");
	glGetMaterialfv = (PFNGLGETMATERIALFVPROC)_Functions.Function("glGetMaterialfv");
	glGetMaterialiv = (PFNGLGETMATERIALIVPROC)_Functions.Function("glGetMaterialiv");
	glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)_Functions.Function("glGetPixelMapfv");
	glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)_Functions.Function("glGetPixelMapuiv");
	glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)_Functions.Function("glGetPixelMapusv");
	glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)_Functions.Function("glGetPolygonStipple");
	glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)_Functions.Function("glGetTexEnvfv");
	glGetTexEnviv = (PFNGLGETTEXENVIVPROC)_Functions.Function("glGetTexEnviv");
	glGetTexGendv = (PFNGLGETTEXGENDVPROC)_Functions.Function("glGetTexGendv");
	glGetTexGenfv = (PFNGLGETTEXGENFVPROC)_Functions.Function("glGetTexGenfv");
	glGetTexGeniv = (PFNGLGETTEXGENIVPROC)_Functions.Function("glGetTexGeniv");
	glIsList = (PFNGLISLISTPROC)_Functions.Function("glIsList");
	glFrustum = (PFNGLFRUSTUMPROC)_Functions.Function("glFrustum");
	glLoadIdentity = (PFNGLLOADIDENTITYPROC)_Functions.Function("glLoadIdentity");
	glLoadMatrixf = (PFNGLLOADMATRIXFPROC)_Functions.Function("glLoadMatrixf");
	glLoadMatrixd = (PFNGLLOADMATRIXDPROC)_Functions.Function("glLoadMatrixd");
	glMatrixMode = (PFNGLMATRIXMODEPROC)_Functions.Function("glMatrixMode");
	glMultMatrixf = (PFNGLMULTMATRIXFPROC)_Functions.Function("glMultMatrixf");
	glMultMatrixd = (PFNGLMULTMATRIXDPROC)_Functions.Function("glMultMatrixd");
	glOrtho = (PFNGLORTHOPROC)_Functions.Function("glOrtho");
	glPopMatrix = (PFNGLPOPMATRIXPROC)_Functions.Function("glPopMatrix");
	glPushMatrix = (PFNGLPUSHMATRIXPROC)_Functions.Function("glPushMatrix");
	glRotated = (PFNGLROTATEDPROC)_Functions.Function("glRotated");
	glRotatef = (PFNGLROTATEFPROC)_Functions.Function("glRotatef");
	glScaled = (PFNGLSCALEDPROC)_Functions.Function("glScaled");
	glScalef = (PFNGLSCALEFPROC)_Functions.Function("glScalef");
	glTranslated = (PFNGLTRANSLATEDPROC)_Functions.Function("glTranslated");
	glTranslatef = (PFNGLTRANSLATEFPROC)_Functions.Function("glTranslatef");
}

void LDL_OpenGLLoader::Init_1_1()
{
	glDrawArrays = (PFNGLDRAWARRAYSPROC)_Functions.Function("glDrawArrays");
	glDrawElements = (PFNGLDRAWELEMENTSPROC)_Functions.Function("glDrawElements");
	glGetPointerv = (PFNGLGETPOINTERVPROC)_Functions.Function("glGetPointerv");
	glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)_Functions.Function("glPolygonOffset");
	glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)_Functions.Function("glCopyTexImage1D");
	glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)_Functions.Function("glCopyTexImage2D");
	glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)_Functions.Function("glCopyTexSubImage1D");
	glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)_Functions.Function("glCopyTexSubImage2D");
	glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)_Functions.Function("glTexSubImage1D");
	glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)_Functions.Function("glTexSubImage2D");
	glBindTexture = (PFNGLBINDTEXTUREPROC)_Functions.Function("glBindTexture");
	glDeleteTextures = (PFNGLDELETETEXTURESPROC)_Functions.Function("glDeleteTextures");
	glGenTextures = (PFNGLGENTEXTURESPROC)_Functions.Function("glGenTextures");
	glIsTexture = (PFNGLISTEXTUREPROC)_Functions.Function("glIsTexture");
	glArrayElement = (PFNGLARRAYELEMENTPROC)_Functions.Function("glArrayElement");
	glColorPointer = (PFNGLCOLORPOINTERPROC)_Functions.Function("glColorPointer");
	glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)_Functions.Function("glDisableClientState");
	glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC)_Functions.Function("glEdgeFlagPointer");
	glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)_Functions.Function("glEnableClientState");
	glIndexPointer = (PFNGLINDEXPOINTERPROC)_Functions.Function("glIndexPointer");
	glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC)_Functions.Function("glInterleavedArrays");
	glNormalPointer = (PFNGLNORMALPOINTERPROC)_Functions.Function("glNormalPointer");
	glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)_Functions.Function("glTexCoordPointer");
	glVertexPointer = (PFNGLVERTEXPOINTERPROC)_Functions.Function("glVertexPointer");
	glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC)_Functions.Function("glAreTexturesResident");
	glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)_Functions.Function("glPrioritizeTextures");
	glIndexub = (PFNGLINDEXUBPROC)_Functions.Function("glIndexub");
	glIndexubv = (PFNGLINDEXUBVPROC)_Functions.Function("glIndexubv");
	glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC)_Functions.Function("glPopClientAttrib");
	glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC)_Functions.Function("glPushClientAttrib");
}

void LDL_OpenGLLoader::Init_1_2()
{
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)_Functions.Function("glDrawRangeElements");
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)_Functions.Function("glTexImage3D");
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)_Functions.Function("glTexSubImage3D");
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)_Functions.Function("glCopyTexSubImage3D");
}

void LDL_OpenGLLoader::Init_1_3()
{
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)_Functions.Function("glActiveTexture");
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)_Functions.Function("glSampleCoverage");
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)_Functions.Function("glCompressedTexImage3D");
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)_Functions.Function("glCompressedTexImage2D");
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)_Functions.Function("glCompressedTexImage1D");
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)_Functions.Function("glCompressedTexSubImage3D");
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)_Functions.Function("glCompressedTexSubImage2D");
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)_Functions.Function("glCompressedTexSubImage1D");
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)_Functions.Function("glGetCompressedTexImage");
	glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)_Functions.Function("glClientActiveTexture");
	glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)_Functions.Function("glMultiTexCoord1d");
	glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)_Functions.Function("glMultiTexCoord1dv");
	glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)_Functions.Function("glMultiTexCoord1f");
	glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)_Functions.Function("glMultiTexCoord1fv");
	glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)_Functions.Function("glMultiTexCoord1i");
	glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)_Functions.Function("glMultiTexCoord1iv");
	glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)_Functions.Function("glMultiTexCoord1s");
	glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)_Functions.Function("glMultiTexCoord1sv");
	glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)_Functions.Function("glMultiTexCoord2d");
	glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)_Functions.Function("glMultiTexCoord2dv");
	glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)_Functions.Function("glMultiTexCoord2f");
	glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)_Functions.Function("glMultiTexCoord2fv");
	glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)_Functions.Function("glMultiTexCoord2i");
	glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)_Functions.Function("glMultiTexCoord2iv");
	glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)_Functions.Function("glMultiTexCoord2s");
	glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)_Functions.Function("glMultiTexCoord2sv");
	glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)_Functions.Function("glMultiTexCoord3d");
	glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)_Functions.Function("glMultiTexCoord3dv");
	glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)_Functions.Function("glMultiTexCoord3f");
	glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)_Functions.Function("glMultiTexCoord3fv");
	glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)_Functions.Function("glMultiTexCoord3i");
	glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)_Functions.Function("glMultiTexCoord3iv");
	glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)_Functions.Function("glMultiTexCoord3s");
	glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)_Functions.Function("glMultiTexCoord3sv");
	glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)_Functions.Function("glMultiTexCoord4d");
	glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)_Functions.Function("glMultiTexCoord4dv");
	glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)_Functions.Function("glMultiTexCoord4f");
	glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)_Functions.Function("glMultiTexCoord4fv");
	glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)_Functions.Function("glMultiTexCoord4i");
	glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)_Functions.Function("glMultiTexCoord4iv");
	glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)_Functions.Function("glMultiTexCoord4s");
	glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)_Functions.Function("glMultiTexCoord4sv");
	glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)_Functions.Function("glLoadTransposeMatrixf");
	glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)_Functions.Function("glLoadTransposeMatrixd");
	glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)_Functions.Function("glMultTransposeMatrixf");
	glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)_Functions.Function("glMultTransposeMatrixd");
}

void LDL_OpenGLLoader::Init_1_4()
{
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)_Functions.Function("glBlendFuncSeparate");
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)_Functions.Function("glMultiDrawArrays");
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)_Functions.Function("glMultiDrawElements");
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)_Functions.Function("glPointParameterf");
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)_Functions.Function("glPointParameterfv");
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)_Functions.Function("glPointParameteri");
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)_Functions.Function("glPointParameteriv");
	glFogCoordf = (PFNGLFOGCOORDFPROC)_Functions.Function("glFogCoordf");
	glFogCoordfv = (PFNGLFOGCOORDFVPROC)_Functions.Function("glFogCoordfv");
	glFogCoordd = (PFNGLFOGCOORDDPROC)_Functions.Function("glFogCoordd");
	glFogCoorddv = (PFNGLFOGCOORDDVPROC)_Functions.Function("glFogCoorddv");
	glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)_Functions.Function("glFogCoordPointer");
	glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)_Functions.Function("glSecondaryColor3b");
	glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)_Functions.Function("glSecondaryColor3bv");
	glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)_Functions.Function("glSecondaryColor3d");
	glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)_Functions.Function("glSecondaryColor3dv");
	glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)_Functions.Function("glSecondaryColor3f");
	glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)_Functions.Function("glSecondaryColor3fv");
	glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)_Functions.Function("glSecondaryColor3i");
	glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)_Functions.Function("glSecondaryColor3iv");
	glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)_Functions.Function("glSecondaryColor3s");
	glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)_Functions.Function("glSecondaryColor3sv");
	glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)_Functions.Function("glSecondaryColor3ub");
	glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)_Functions.Function("glSecondaryColor3ubv");
	glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)_Functions.Function("glSecondaryColor3ui");
	glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)_Functions.Function("glSecondaryColor3uiv");
	glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)_Functions.Function("glSecondaryColor3us");
	glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)_Functions.Function("glSecondaryColor3usv");
	glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)_Functions.Function("glSecondaryColorPointer");
	glWindowPos2d = (PFNGLWINDOWPOS2DPROC)_Functions.Function("glWindowPos2d");
	glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)_Functions.Function("glWindowPos2dv");
	glWindowPos2f = (PFNGLWINDOWPOS2FPROC)_Functions.Function("glWindowPos2f");
	glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)_Functions.Function("glWindowPos2fv");
	glWindowPos2i = (PFNGLWINDOWPOS2IPROC)_Functions.Function("glWindowPos2i");
	glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)_Functions.Function("glWindowPos2iv");
	glWindowPos2s = (PFNGLWINDOWPOS2SPROC)_Functions.Function("glWindowPos2s");
	glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)_Functions.Function("glWindowPos2sv");
	glWindowPos3d = (PFNGLWINDOWPOS3DPROC)_Functions.Function("glWindowPos3d");
	glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)_Functions.Function("glWindowPos3dv");
	glWindowPos3f = (PFNGLWINDOWPOS3FPROC)_Functions.Function("glWindowPos3f");
	glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)_Functions.Function("glWindowPos3fv");
	glWindowPos3i = (PFNGLWINDOWPOS3IPROC)_Functions.Function("glWindowPos3i");
	glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)_Functions.Function("glWindowPos3iv");
	glWindowPos3s = (PFNGLWINDOWPOS3SPROC)_Functions.Function("glWindowPos3s");
	glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)_Functions.Function("glWindowPos3sv");
	glBlendColor = (PFNGLBLENDCOLORPROC)_Functions.Function("glBlendColor");
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)_Functions.Function("glBlendEquation");
}

void LDL_OpenGLLoader::Init_1_5()
{
	glGenQueries = (PFNGLGENQUERIESPROC)_Functions.Function("glGenQueries");
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)_Functions.Function("glDeleteQueries");
	glIsQuery = (PFNGLISQUERYPROC)_Functions.Function("glIsQuery");
	glBeginQuery = (PFNGLBEGINQUERYPROC)_Functions.Function("glBeginQuery");
	glEndQuery = (PFNGLENDQUERYPROC)_Functions.Function("glEndQuery");
	glGetQueryiv = (PFNGLGETQUERYIVPROC)_Functions.Function("glGetQueryiv");
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)_Functions.Function("glGetQueryObjectiv");
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)_Functions.Function("glGetQueryObjectuiv");
	glBindBuffer = (PFNGLBINDBUFFERPROC)_Functions.Function("glBindBuffer");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)_Functions.Function("glDeleteBuffers");
	glGenBuffers = (PFNGLGENBUFFERSPROC)_Functions.Function("glGenBuffers");
	glIsBuffer = (PFNGLISBUFFERPROC)_Functions.Function("glIsBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)_Functions.Function("glBufferData");
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)_Functions.Function("glBufferSubData");
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)_Functions.Function("glGetBufferSubData");
	glMapBuffer = (PFNGLMAPBUFFERPROC)_Functions.Function("glMapBuffer");
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)_Functions.Function("glUnmapBuffer");
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)_Functions.Function("glGetBufferParameteriv");
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)_Functions.Function("glGetBufferPointerv");
}

void LDL_OpenGLLoader::Init_2_0()
{
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)_Functions.Function("glBlendEquationSeparate");
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)_Functions.Function("glDrawBuffers");
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)_Functions.Function("glStencilOpSeparate");
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)_Functions.Function("glStencilFuncSeparate");
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)_Functions.Function("glStencilMaskSeparate");
	glAttachShader = (PFNGLATTACHSHADERPROC)_Functions.Function("glAttachShader");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)_Functions.Function("glBindAttribLocation");
	glCompileShader = (PFNGLCOMPILESHADERPROC)_Functions.Function("glCompileShader");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)_Functions.Function("glCreateProgram");
	glCreateShader = (PFNGLCREATESHADERPROC)_Functions.Function("glCreateShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)_Functions.Function("glDeleteProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)_Functions.Function("glDeleteShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)_Functions.Function("glDetachShader");
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)_Functions.Function("glDisableVertexAttribArray");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)_Functions.Function("glEnableVertexAttribArray");
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)_Functions.Function("glGetActiveAttrib");
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)_Functions.Function("glGetActiveUniform");
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)_Functions.Function("glGetAttachedShaders");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)_Functions.Function("glGetAttribLocation");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)_Functions.Function("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)_Functions.Function("glGetProgramInfoLog");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)_Functions.Function("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)_Functions.Function("glGetShaderInfoLog");
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)_Functions.Function("glGetShaderSource");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)_Functions.Function("glGetUniformLocation");
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)_Functions.Function("glGetUniformfv");
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)_Functions.Function("glGetUniformiv");
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)_Functions.Function("glGetVertexAttribdv");
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)_Functions.Function("glGetVertexAttribfv");
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)_Functions.Function("glGetVertexAttribiv");
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)_Functions.Function("glGetVertexAttribPointerv");
	glIsProgram = (PFNGLISPROGRAMPROC)_Functions.Function("glIsProgram");
	glIsShader = (PFNGLISSHADERPROC)_Functions.Function("glIsShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)_Functions.Function("glLinkProgram");
	glShaderSource = (PFNGLSHADERSOURCEPROC)_Functions.Function("glShaderSource");
	glUseProgram = (PFNGLUSEPROGRAMPROC)_Functions.Function("glUseProgram");
	glUniform1f = (PFNGLUNIFORM1FPROC)_Functions.Function("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)_Functions.Function("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)_Functions.Function("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)_Functions.Function("glUniform4f");
	glUniform1i = (PFNGLUNIFORM1IPROC)_Functions.Function("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)_Functions.Function("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)_Functions.Function("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)_Functions.Function("glUniform4i");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)_Functions.Function("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)_Functions.Function("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)_Functions.Function("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)_Functions.Function("glUniform4fv");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)_Functions.Function("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)_Functions.Function("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)_Functions.Function("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)_Functions.Function("glUniform4iv");
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)_Functions.Function("glUniformMatrix2fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)_Functions.Function("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)_Functions.Function("glUniformMatrix4fv");
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)_Functions.Function("glValidateProgram");
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)_Functions.Function("glVertexAttrib1d");
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)_Functions.Function("glVertexAttrib1dv");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)_Functions.Function("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)_Functions.Function("glVertexAttrib1fv");
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)_Functions.Function("glVertexAttrib1s");
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)_Functions.Function("glVertexAttrib1sv");
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)_Functions.Function("glVertexAttrib2d");
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)_Functions.Function("glVertexAttrib2dv");
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)_Functions.Function("glVertexAttrib2f");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)_Functions.Function("glVertexAttrib2fv");
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)_Functions.Function("glVertexAttrib2s");
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)_Functions.Function("glVertexAttrib2sv");
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)_Functions.Function("glVertexAttrib3d");
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)_Functions.Function("glVertexAttrib3dv");
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)_Functions.Function("glVertexAttrib3f");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)_Functions.Function("glVertexAttrib3fv");
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)_Functions.Function("glVertexAttrib3s");
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)_Functions.Function("glVertexAttrib3sv");
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)_Functions.Function("glVertexAttrib4Nbv");
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)_Functions.Function("glVertexAttrib4Niv");
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)_Functions.Function("glVertexAttrib4Nsv");
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)_Functions.Function("glVertexAttrib4Nub");
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)_Functions.Function("glVertexAttrib4Nubv");
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)_Functions.Function("glVertexAttrib4Nuiv");
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)_Functions.Function("glVertexAttrib4Nusv");
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)_Functions.Function("glVertexAttrib4bv");
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)_Functions.Function("glVertexAttrib4d");
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)_Functions.Function("glVertexAttrib4dv");
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)_Functions.Function("glVertexAttrib4f");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)_Functions.Function("glVertexAttrib4fv");
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)_Functions.Function("glVertexAttrib4iv");
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)_Functions.Function("glVertexAttrib4s");
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)_Functions.Function("glVertexAttrib4sv");
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)_Functions.Function("glVertexAttrib4ubv");
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)_Functions.Function("glVertexAttrib4uiv");
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)_Functions.Function("glVertexAttrib4usv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)_Functions.Function("glVertexAttribPointer");
}

void LDL_OpenGLLoader::Init_2_1()
{
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)_Functions.Function("glUniformMatrix2x3fv");
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)_Functions.Function("glUniformMatrix3x2fv");
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)_Functions.Function("glUniformMatrix2x4fv");
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)_Functions.Function("glUniformMatrix4x2fv");
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)_Functions.Function("glUniformMatrix3x4fv");
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)_Functions.Function("glUniformMatrix4x3fv");
}

void LDL_OpenGLLoader::Init_3_0()
{
	glColorMaski = (PFNGLCOLORMASKIPROC)_Functions.Function("glColorMaski");
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)_Functions.Function("glGetBooleani_v");
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)_Functions.Function("glGetIntegeri_v");
	glEnablei = (PFNGLENABLEIPROC)_Functions.Function("glEnablei");
	glDisablei = (PFNGLDISABLEIPROC)_Functions.Function("glDisablei");
	glIsEnabledi = (PFNGLISENABLEDIPROC)_Functions.Function("glIsEnabledi");
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)_Functions.Function("glBeginTransformFeedback");
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)_Functions.Function("glEndTransformFeedback");
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)_Functions.Function("glBindBufferRange");
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)_Functions.Function("glBindBufferBase");
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)_Functions.Function("glTransformFeedbackVaryings");
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)_Functions.Function("glGetTransformFeedbackVarying");
	glClampColor = (PFNGLCLAMPCOLORPROC)_Functions.Function("glClampColor");
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)_Functions.Function("glBeginConditionalRender");
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)_Functions.Function("glEndConditionalRender");
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)_Functions.Function("glVertexAttribIPointer");
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)_Functions.Function("glGetVertexAttribIiv");
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)_Functions.Function("glGetVertexAttribIuiv");
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)_Functions.Function("glVertexAttribI1i");
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)_Functions.Function("glVertexAttribI2i");
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)_Functions.Function("glVertexAttribI3i");
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)_Functions.Function("glVertexAttribI4i");
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)_Functions.Function("glVertexAttribI1ui");
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)_Functions.Function("glVertexAttribI2ui");
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)_Functions.Function("glVertexAttribI3ui");
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)_Functions.Function("glVertexAttribI4ui");
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)_Functions.Function("glVertexAttribI1iv");
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)_Functions.Function("glVertexAttribI2iv");
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)_Functions.Function("glVertexAttribI3iv");
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)_Functions.Function("glVertexAttribI4iv");
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)_Functions.Function("glVertexAttribI1uiv");
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)_Functions.Function("glVertexAttribI2uiv");
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)_Functions.Function("glVertexAttribI3uiv");
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)_Functions.Function("glVertexAttribI4uiv");
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)_Functions.Function("glVertexAttribI4bv");
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)_Functions.Function("glVertexAttribI4sv");
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)_Functions.Function("glVertexAttribI4ubv");
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)_Functions.Function("glVertexAttribI4usv");
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)_Functions.Function("glGetUniformuiv");
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)_Functions.Function("glBindFragDataLocation");
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)_Functions.Function("glGetFragDataLocation");
	glUniform1ui = (PFNGLUNIFORM1UIPROC)_Functions.Function("glUniform1ui");
	glUniform2ui = (PFNGLUNIFORM2UIPROC)_Functions.Function("glUniform2ui");
	glUniform3ui = (PFNGLUNIFORM3UIPROC)_Functions.Function("glUniform3ui");
	glUniform4ui = (PFNGLUNIFORM4UIPROC)_Functions.Function("glUniform4ui");
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)_Functions.Function("glUniform1uiv");
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)_Functions.Function("glUniform2uiv");
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)_Functions.Function("glUniform3uiv");
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)_Functions.Function("glUniform4uiv");
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)_Functions.Function("glTexParameterIiv");
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)_Functions.Function("glTexParameterIuiv");
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)_Functions.Function("glGetTexParameterIiv");
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)_Functions.Function("glGetTexParameterIuiv");
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)_Functions.Function("glClearBufferiv");
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)_Functions.Function("glClearBufferuiv");
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)_Functions.Function("glClearBufferfv");
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)_Functions.Function("glClearBufferfi");
	glGetStringi = (PFNGLGETSTRINGIPROC)_Functions.Function("glGetStringi");
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)_Functions.Function("glIsRenderbuffer");
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)_Functions.Function("glBindRenderbuffer");
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)_Functions.Function("glDeleteRenderbuffers");
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)_Functions.Function("glGenRenderbuffers");
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)_Functions.Function("glRenderbufferStorage");
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)_Functions.Function("glGetRenderbufferParameteriv");
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)_Functions.Function("glIsFramebuffer");
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)_Functions.Function("glBindFramebuffer");
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)_Functions.Function("glDeleteFramebuffers");
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)_Functions.Function("glGenFramebuffers");
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)_Functions.Function("glCheckFramebufferStatus");
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)_Functions.Function("glFramebufferTexture1D");
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)_Functions.Function("glFramebufferTexture2D");
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)_Functions.Function("glFramebufferTexture3D");
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)_Functions.Function("glFramebufferRenderbuffer");
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)_Functions.Function("glGetFramebufferAttachmentParameteriv");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)_Functions.Function("glGenerateMipmap");
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)_Functions.Function("glBlitFramebuffer");
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)_Functions.Function("glRenderbufferStorageMultisample");
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)_Functions.Function("glFramebufferTextureLayer");
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)_Functions.Function("glMapBufferRange");
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)_Functions.Function("glFlushMappedBufferRange");
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)_Functions.Function("glBindVertexArray");
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)_Functions.Function("glDeleteVertexArrays");
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)_Functions.Function("glGenVertexArrays");
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)_Functions.Function("glIsVertexArray");
}

void LDL_OpenGLLoader::Init_3_1()
{
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)_Functions.Function("glDrawArraysInstanced");
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)_Functions.Function("glDrawElementsInstanced");
	glTexBuffer = (PFNGLTEXBUFFERPROC)_Functions.Function("glTexBuffer");
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)_Functions.Function("glPrimitiveRestartIndex");
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)_Functions.Function("glCopyBufferSubData");
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)_Functions.Function("glGetUniformIndices");
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)_Functions.Function("glGetActiveUniformsiv");
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)_Functions.Function("glGetActiveUniformName");
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)_Functions.Function("glGetUniformBlockIndex");
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)_Functions.Function("glGetActiveUniformBlockiv");
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)_Functions.Function("glGetActiveUniformBlockName");
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)_Functions.Function("glUniformBlockBinding");
}

void LDL_OpenGLLoader::Init_3_2()
{
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)_Functions.Function("glDrawElementsBaseVertex");
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)_Functions.Function("glDrawRangeElementsBaseVertex");
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)_Functions.Function("glDrawElementsInstancedBaseVertex");
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)_Functions.Function("glMultiDrawElementsBaseVertex");
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)_Functions.Function("glProvokingVertex");
	glFenceSync = (PFNGLFENCESYNCPROC)_Functions.Function("glFenceSync");
	glIsSync = (PFNGLISSYNCPROC)_Functions.Function("glIsSync");
	glDeleteSync = (PFNGLDELETESYNCPROC)_Functions.Function("glDeleteSync");
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)_Functions.Function("glClientWaitSync");
	glWaitSync = (PFNGLWAITSYNCPROC)_Functions.Function("glWaitSync");
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)_Functions.Function("glGetInteger64v");
	glGetSynciv = (PFNGLGETSYNCIVPROC)_Functions.Function("glGetSynciv");
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)_Functions.Function("glGetInteger64i_v");
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)_Functions.Function("glGetBufferParameteri64v");
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)_Functions.Function("glFramebufferTexture");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)_Functions.Function("glTexImage2DMultisample");
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)_Functions.Function("glTexImage3DMultisample");
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)_Functions.Function("glGetMultisamplefv");
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)_Functions.Function("glSampleMaski");
}

void LDL_OpenGLLoader::Init_3_3()
{
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)_Functions.Function("glBindFragDataLocationIndexed");
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)_Functions.Function("glGetFragDataIndex");
	glGenSamplers = (PFNGLGENSAMPLERSPROC)_Functions.Function("glGenSamplers");
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)_Functions.Function("glDeleteSamplers");
	glIsSampler = (PFNGLISSAMPLERPROC)_Functions.Function("glIsSampler");
	glBindSampler = (PFNGLBINDSAMPLERPROC)_Functions.Function("glBindSampler");
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)_Functions.Function("glSamplerParameteri");
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)_Functions.Function("glSamplerParameteriv");
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)_Functions.Function("glSamplerParameterf");
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)_Functions.Function("glSamplerParameterfv");
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)_Functions.Function("glSamplerParameterIiv");
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)_Functions.Function("glSamplerParameterIuiv");
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)_Functions.Function("glGetSamplerParameteriv");
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)_Functions.Function("glGetSamplerParameterIiv");
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)_Functions.Function("glGetSamplerParameterfv");
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)_Functions.Function("glGetSamplerParameterIuiv");
	glQueryCounter = (PFNGLQUERYCOUNTERPROC)_Functions.Function("glQueryCounter");
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)_Functions.Function("glGetQueryObjecti64v");
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)_Functions.Function("glGetQueryObjectui64v");
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)_Functions.Function("glVertexAttribDivisor");
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)_Functions.Function("glVertexAttribP1ui");
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)_Functions.Function("glVertexAttribP1uiv");
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)_Functions.Function("glVertexAttribP2ui");
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)_Functions.Function("glVertexAttribP2uiv");
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)_Functions.Function("glVertexAttribP3ui");
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)_Functions.Function("glVertexAttribP3uiv");
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)_Functions.Function("glVertexAttribP4ui");
	glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)_Functions.Function("glVertexAttribP4uiv");
	glVertexP2ui = (PFNGLVERTEXP2UIPROC)_Functions.Function("glVertexP2ui");
	glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)_Functions.Function("glVertexP2uiv");
	glVertexP3ui = (PFNGLVERTEXP3UIPROC)_Functions.Function("glVertexP3ui");
	glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)_Functions.Function("glVertexP3uiv");
	glVertexP4ui = (PFNGLVERTEXP4UIPROC)_Functions.Function("glVertexP4ui");
	glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)_Functions.Function("glVertexP4uiv");
	glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)_Functions.Function("glTexCoordP1ui");
	glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)_Functions.Function("glTexCoordP1uiv");
	glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)_Functions.Function("glTexCoordP2ui");
	glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)_Functions.Function("glTexCoordP2uiv");
	glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)_Functions.Function("glTexCoordP3ui");
	glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)_Functions.Function("glTexCoordP3uiv");
	glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)_Functions.Function("glTexCoordP4ui");
	glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)_Functions.Function("glTexCoordP4uiv");
	glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)_Functions.Function("glMultiTexCoordP1ui");
	glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)_Functions.Function("glMultiTexCoordP1uiv");
	glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)_Functions.Function("glMultiTexCoordP2ui");
	glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)_Functions.Function("glMultiTexCoordP2uiv");
	glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)_Functions.Function("glMultiTexCoordP3ui");
	glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)_Functions.Function("glMultiTexCoordP3uiv");
	glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)_Functions.Function("glMultiTexCoordP4ui");
	glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)_Functions.Function("glMultiTexCoordP4uiv");
	glNormalP3ui = (PFNGLNORMALP3UIPROC)_Functions.Function("glNormalP3ui");
	glNormalP3uiv = (PFNGLNORMALP3UIVPROC)_Functions.Function("glNormalP3uiv");
	glColorP3ui = (PFNGLCOLORP3UIPROC)_Functions.Function("glColorP3ui");
	glColorP3uiv = (PFNGLCOLORP3UIVPROC)_Functions.Function("glColorP3uiv");
	glColorP4ui = (PFNGLCOLORP4UIPROC)_Functions.Function("glColorP4ui");
	glColorP4uiv = (PFNGLCOLORP4UIVPROC)_Functions.Function("glColorP4uiv");
	glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)_Functions.Function("glSecondaryColorP3ui");
	glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)_Functions.Function("glSecondaryColorP3uiv");
}

void LDL_OpenGLLoader::Init_4_0()
{
	glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)_Functions.Function("glMinSampleShading");
	glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)_Functions.Function("glBlendEquationi");
	glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)_Functions.Function("glBlendEquationSeparatei");
	glBlendFunci = (PFNGLBLENDFUNCIPROC)_Functions.Function("glBlendFunci");
	glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)_Functions.Function("glBlendFuncSeparatei");
	glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)_Functions.Function("glDrawArraysIndirect");
	glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)_Functions.Function("glDrawElementsIndirect");
	glUniform1d = (PFNGLUNIFORM1DPROC)_Functions.Function("glUniform1d");
	glUniform2d = (PFNGLUNIFORM2DPROC)_Functions.Function("glUniform2d");
	glUniform3d = (PFNGLUNIFORM3DPROC)_Functions.Function("glUniform3d");
	glUniform4d = (PFNGLUNIFORM4DPROC)_Functions.Function("glUniform4d");
	glUniform1dv = (PFNGLUNIFORM1DVPROC)_Functions.Function("glUniform1dv");
	glUniform2dv = (PFNGLUNIFORM2DVPROC)_Functions.Function("glUniform2dv");
	glUniform3dv = (PFNGLUNIFORM3DVPROC)_Functions.Function("glUniform3dv");
	glUniform4dv = (PFNGLUNIFORM4DVPROC)_Functions.Function("glUniform4dv");
	glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)_Functions.Function("glUniformMatrix2dv");
	glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)_Functions.Function("glUniformMatrix3dv");
	glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)_Functions.Function("glUniformMatrix4dv");
	glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)_Functions.Function("glUniformMatrix2x3dv");
	glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)_Functions.Function("glUniformMatrix2x4dv");
	glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)_Functions.Function("glUniformMatrix3x2dv");
	glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)_Functions.Function("glUniformMatrix3x4dv");
	glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)_Functions.Function("glUniformMatrix4x2dv");
	glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)_Functions.Function("glUniformMatrix4x3dv");
	glGetUniformdv = (PFNGLGETUNIFORMDVPROC)_Functions.Function("glGetUniformdv");
	glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)_Functions.Function("glGetSubroutineUniformLocation");
	glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)_Functions.Function("glGetSubroutineIndex");
	glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)_Functions.Function("glGetActiveSubroutineUniformiv");
	glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)_Functions.Function("glGetActiveSubroutineUniformName");
	glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)_Functions.Function("glGetActiveSubroutineName");
	glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)_Functions.Function("glUniformSubroutinesuiv");
	glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)_Functions.Function("glGetUniformSubroutineuiv");
	glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)_Functions.Function("glGetProgramStageiv");
	glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)_Functions.Function("glPatchParameteri");
	glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)_Functions.Function("glPatchParameterfv");
	glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)_Functions.Function("glBindTransformFeedback");
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)_Functions.Function("glDeleteTransformFeedbacks");
	glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)_Functions.Function("glGenTransformFeedbacks");
	glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)_Functions.Function("glIsTransformFeedback");
	glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)_Functions.Function("glPauseTransformFeedback");
	glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)_Functions.Function("glResumeTransformFeedback");
	glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)_Functions.Function("glDrawTransformFeedback");
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)_Functions.Function("glDrawTransformFeedbackStream");
	glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)_Functions.Function("glBeginQueryIndexed");
	glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)_Functions.Function("glEndQueryIndexed");
	glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)_Functions.Function("glGetQueryIndexediv");
}

void LDL_OpenGLLoader::Init_4_1()
{
	glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)_Functions.Function("glReleaseShaderCompiler");
	glShaderBinary = (PFNGLSHADERBINARYPROC)_Functions.Function("glShaderBinary");
	glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)_Functions.Function("glGetShaderPrecisionFormat");
	glDepthRangef = (PFNGLDEPTHRANGEFPROC)_Functions.Function("glDepthRangef");
	glClearDepthf = (PFNGLCLEARDEPTHFPROC)_Functions.Function("glClearDepthf");
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)_Functions.Function("glGetProgramBinary");
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)_Functions.Function("glProgramBinary");
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)_Functions.Function("glProgramParameteri");
	glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)_Functions.Function("glUseProgramStages");
	glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)_Functions.Function("glActiveShaderProgram");
	glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)_Functions.Function("glCreateShaderProgramv");
	glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)_Functions.Function("glBindProgramPipeline");
	glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)_Functions.Function("glDeleteProgramPipelines");
	glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)_Functions.Function("glGenProgramPipelines");
	glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)_Functions.Function("glIsProgramPipeline");
	glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)_Functions.Function("glGetProgramPipelineiv");
	glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)_Functions.Function("glProgramUniform1i");
	glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)_Functions.Function("glProgramUniform1iv");
	glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)_Functions.Function("glProgramUniform1f");
	glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)_Functions.Function("glProgramUniform1fv");
	glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)_Functions.Function("glProgramUniform1d");
	glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)_Functions.Function("glProgramUniform1dv");
	glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)_Functions.Function("glProgramUniform1ui");
	glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)_Functions.Function("glProgramUniform1uiv");
	glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)_Functions.Function("glProgramUniform2i");
	glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)_Functions.Function("glProgramUniform2iv");
	glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)_Functions.Function("glProgramUniform2f");
	glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)_Functions.Function("glProgramUniform2fv");
	glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)_Functions.Function("glProgramUniform2d");
	glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)_Functions.Function("glProgramUniform2dv");
	glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)_Functions.Function("glProgramUniform2ui");
	glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)_Functions.Function("glProgramUniform2uiv");
	glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)_Functions.Function("glProgramUniform3i");
	glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)_Functions.Function("glProgramUniform3iv");
	glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)_Functions.Function("glProgramUniform3f");
	glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)_Functions.Function("glProgramUniform3fv");
	glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)_Functions.Function("glProgramUniform3d");
	glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)_Functions.Function("glProgramUniform3dv");
	glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)_Functions.Function("glProgramUniform3ui");
	glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)_Functions.Function("glProgramUniform3uiv");
	glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)_Functions.Function("glProgramUniform4i");
	glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)_Functions.Function("glProgramUniform4iv");
	glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)_Functions.Function("glProgramUniform4f");
	glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)_Functions.Function("glProgramUniform4fv");
	glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)_Functions.Function("glProgramUniform4d");
	glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)_Functions.Function("glProgramUniform4dv");
	glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)_Functions.Function("glProgramUniform4ui");
	glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)_Functions.Function("glProgramUniform4uiv");
	glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)_Functions.Function("glProgramUniformMatrix2fv");
	glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)_Functions.Function("glProgramUniformMatrix3fv");
	glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)_Functions.Function("glProgramUniformMatrix4fv");
	glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)_Functions.Function("glProgramUniformMatrix2dv");
	glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)_Functions.Function("glProgramUniformMatrix3dv");
	glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)_Functions.Function("glProgramUniformMatrix4dv");
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)_Functions.Function("glProgramUniformMatrix2x3fv");
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)_Functions.Function("glProgramUniformMatrix3x2fv");
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)_Functions.Function("glProgramUniformMatrix2x4fv");
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)_Functions.Function("glProgramUniformMatrix4x2fv");
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)_Functions.Function("glProgramUniformMatrix3x4fv");
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)_Functions.Function("glProgramUniformMatrix4x3fv");
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)_Functions.Function("glProgramUniformMatrix2x3dv");
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)_Functions.Function("glProgramUniformMatrix3x2dv");
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)_Functions.Function("glProgramUniformMatrix2x4dv");
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)_Functions.Function("glProgramUniformMatrix4x2dv");
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)_Functions.Function("glProgramUniformMatrix3x4dv");
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)_Functions.Function("glProgramUniformMatrix4x3dv");
	glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)_Functions.Function("glValidateProgramPipeline");
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)_Functions.Function("glGetProgramPipelineInfoLog");
	glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)_Functions.Function("glVertexAttribL1d");
	glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)_Functions.Function("glVertexAttribL2d");
	glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)_Functions.Function("glVertexAttribL3d");
	glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)_Functions.Function("glVertexAttribL4d");
	glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)_Functions.Function("glVertexAttribL1dv");
	glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)_Functions.Function("glVertexAttribL2dv");
	glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)_Functions.Function("glVertexAttribL3dv");
	glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)_Functions.Function("glVertexAttribL4dv");
	glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)_Functions.Function("glVertexAttribLPointer");
	glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)_Functions.Function("glGetVertexAttribLdv");
	glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)_Functions.Function("glViewportArrayv");
	glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)_Functions.Function("glViewportIndexedf");
	glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)_Functions.Function("glViewportIndexedfv");
	glScissorArrayv = (PFNGLSCISSORARRAYVPROC)_Functions.Function("glScissorArrayv");
	glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)_Functions.Function("glScissorIndexed");
	glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)_Functions.Function("glScissorIndexedv");
	glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)_Functions.Function("glDepthRangeArrayv");
	glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)_Functions.Function("glDepthRangeIndexed");
	glGetFloati_v = (PFNGLGETFLOATI_VPROC)_Functions.Function("glGetFloati_v");
	glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)_Functions.Function("glGetDoublei_v");
}

void LDL_OpenGLLoader::Init_4_2()
{
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)_Functions.Function("glDrawArraysInstancedBaseInstance");
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)_Functions.Function("glDrawElementsInstancedBaseInstance");
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)_Functions.Function("glDrawElementsInstancedBaseVertexBaseInstance");
	glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)_Functions.Function("glGetInternalformativ");
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)_Functions.Function("glGetActiveAtomicCounterBufferiv");
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)_Functions.Function("glBindImageTexture");
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)_Functions.Function("glMemoryBarrier");
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)_Functions.Function("glTexStorage1D");
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)_Functions.Function("glTexStorage2D");
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)_Functions.Function("glTexStorage3D");
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)_Functions.Function("glDrawTransformFeedbackInstanced");
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)_Functions.Function("glDrawTransformFeedbackStreamInstanced");
}

void LDL_OpenGLLoader::Init_4_3()
{
	glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)_Functions.Function("glClearBufferData");
	glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)_Functions.Function("glClearBufferSubData");
	glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)_Functions.Function("glDispatchCompute");
	glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)_Functions.Function("glDispatchComputeIndirect");
	glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)_Functions.Function("glCopyImageSubData");
	glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)_Functions.Function("glFramebufferParameteri");
	glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)_Functions.Function("glGetFramebufferParameteriv");
	glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)_Functions.Function("glGetInternalformati64v");
	glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)_Functions.Function("glInvalidateTexSubImage");
	glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)_Functions.Function("glInvalidateTexImage");
	glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)_Functions.Function("glInvalidateBufferSubData");
	glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)_Functions.Function("glInvalidateBufferData");
	glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)_Functions.Function("glInvalidateFramebuffer");
	glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)_Functions.Function("glInvalidateSubFramebuffer");
	glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)_Functions.Function("glMultiDrawArraysIndirect");
	glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)_Functions.Function("glMultiDrawElementsIndirect");
	glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)_Functions.Function("glGetProgramInterfaceiv");
	glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)_Functions.Function("glGetProgramResourceIndex");
	glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)_Functions.Function("glGetProgramResourceName");
	glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)_Functions.Function("glGetProgramResourceiv");
	glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)_Functions.Function("glGetProgramResourceLocation");
	glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)_Functions.Function("glGetProgramResourceLocationIndex");
	glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)_Functions.Function("glShaderStorageBlockBinding");
	glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)_Functions.Function("glTexBufferRange");
	glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)_Functions.Function("glTexStorage2DMultisample");
	glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)_Functions.Function("glTexStorage3DMultisample");
	glTextureView = (PFNGLTEXTUREVIEWPROC)_Functions.Function("glTextureView");
	glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)_Functions.Function("glBindVertexBuffer");
	glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)_Functions.Function("glVertexAttribFormat");
	glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)_Functions.Function("glVertexAttribIFormat");
	glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)_Functions.Function("glVertexAttribLFormat");
	glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)_Functions.Function("glVertexAttribBinding");
	glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)_Functions.Function("glVertexBindingDivisor");
	glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)_Functions.Function("glDebugMessageControl");
	glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)_Functions.Function("glDebugMessageInsert");
	glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)_Functions.Function("glDebugMessageCallback");
	glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)_Functions.Function("glGetDebugMessageLog");
	glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)_Functions.Function("glPushDebugGroup");
	glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)_Functions.Function("glPopDebugGroup");
	glObjectLabel = (PFNGLOBJECTLABELPROC)_Functions.Function("glObjectLabel");
	glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)_Functions.Function("glGetObjectLabel");
	glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)_Functions.Function("glObjectPtrLabel");
	glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)_Functions.Function("glGetObjectPtrLabel");
}

void LDL_OpenGLLoader::Init_4_4()
{
	glBufferStorage = (PFNGLBUFFERSTORAGEPROC)_Functions.Function("glBufferStorage");
	glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)_Functions.Function("glClearTexImage");
	glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)_Functions.Function("glClearTexSubImage");
	glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)_Functions.Function("glBindBuffersBase");
	glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)_Functions.Function("glBindBuffersRange");
	glBindTextures = (PFNGLBINDTEXTURESPROC)_Functions.Function("glBindTextures");
	glBindSamplers = (PFNGLBINDSAMPLERSPROC)_Functions.Function("glBindSamplers");
	glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)_Functions.Function("glBindImageTextures");
	glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)_Functions.Function("glBindVertexBuffers");

}

void LDL_OpenGLLoader::Init_4_5()
{
	glClipControl = (PFNGLCLIPCONTROLPROC)_Functions.Function("glClipControl");
	glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)_Functions.Function("glCreateTransformFeedbacks");
	glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)_Functions.Function("glTransformFeedbackBufferBase");
	glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)_Functions.Function("glTransformFeedbackBufferRange");
	glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)_Functions.Function("glGetTransformFeedbackiv");
	glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)_Functions.Function("glGetTransformFeedbacki_v");
	glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)_Functions.Function("glGetTransformFeedbacki64_v");
	glCreateBuffers = (PFNGLCREATEBUFFERSPROC)_Functions.Function("glCreateBuffers");
	glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)_Functions.Function("glNamedBufferStorage");
	glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)_Functions.Function("glNamedBufferData");
	glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)_Functions.Function("glNamedBufferSubData");
	glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)_Functions.Function("glCopyNamedBufferSubData");
	glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)_Functions.Function("glClearNamedBufferData");
	glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)_Functions.Function("glClearNamedBufferSubData");
	glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)_Functions.Function("glMapNamedBuffer");
	glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)_Functions.Function("glMapNamedBufferRange");
	glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)_Functions.Function("glUnmapNamedBuffer");
	glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)_Functions.Function("glFlushMappedNamedBufferRange");
	glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)_Functions.Function("glGetNamedBufferParameteriv");
	glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)_Functions.Function("glGetNamedBufferParameteri64v");
	glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)_Functions.Function("glGetNamedBufferPointerv");
	glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)_Functions.Function("glGetNamedBufferSubData");
	glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)_Functions.Function("glCreateFramebuffers");
	glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)_Functions.Function("glNamedFramebufferRenderbuffer");
	glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)_Functions.Function("glNamedFramebufferParameteri");
	glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)_Functions.Function("glNamedFramebufferTexture");
	glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)_Functions.Function("glNamedFramebufferTextureLayer");
	glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)_Functions.Function("glNamedFramebufferDrawBuffer");
	glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)_Functions.Function("glNamedFramebufferDrawBuffers");
	glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)_Functions.Function("glNamedFramebufferReadBuffer");
	glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)_Functions.Function("glInvalidateNamedFramebufferData");
	glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)_Functions.Function("glInvalidateNamedFramebufferSubData");
	glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)_Functions.Function("glClearNamedFramebufferiv");
	glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)_Functions.Function("glClearNamedFramebufferuiv");
	glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)_Functions.Function("glClearNamedFramebufferfv");
	glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)_Functions.Function("glClearNamedFramebufferfi");
	glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)_Functions.Function("glBlitNamedFramebuffer");
	glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)_Functions.Function("glCheckNamedFramebufferStatus");
	glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)_Functions.Function("glGetNamedFramebufferParameteriv");
	glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)_Functions.Function("glGetNamedFramebufferAttachmentParameteriv");
	glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)_Functions.Function("glCreateRenderbuffers");
	glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)_Functions.Function("glNamedRenderbufferStorage");
	glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)_Functions.Function("glNamedRenderbufferStorageMultisample");
	glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)_Functions.Function("glGetNamedRenderbufferParameteriv");
	glCreateTextures = (PFNGLCREATETEXTURESPROC)_Functions.Function("glCreateTextures");
	glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)_Functions.Function("glTextureBuffer");
	glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)_Functions.Function("glTextureBufferRange");
	glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)_Functions.Function("glTextureStorage1D");
	glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)_Functions.Function("glTextureStorage2D");
	glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)_Functions.Function("glTextureStorage3D");
	glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)_Functions.Function("glTextureStorage2DMultisample");
	glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)_Functions.Function("glTextureStorage3DMultisample");
	glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)_Functions.Function("glTextureSubImage1D");
	glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)_Functions.Function("glTextureSubImage2D");
	glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)_Functions.Function("glTextureSubImage3D");
	glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)_Functions.Function("glCompressedTextureSubImage1D");
	glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)_Functions.Function("glCompressedTextureSubImage2D");
	glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)_Functions.Function("glCompressedTextureSubImage3D");
	glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)_Functions.Function("glCopyTextureSubImage1D");
	glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)_Functions.Function("glCopyTextureSubImage2D");
	glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)_Functions.Function("glCopyTextureSubImage3D");
	glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)_Functions.Function("glTextureParameterf");
	glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)_Functions.Function("glTextureParameterfv");
	glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)_Functions.Function("glTextureParameteri");
	glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)_Functions.Function("glTextureParameterIiv");
	glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)_Functions.Function("glTextureParameterIuiv");
	glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)_Functions.Function("glTextureParameteriv");
	glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)_Functions.Function("glGenerateTextureMipmap");
	glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)_Functions.Function("glBindTextureUnit");
	glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)_Functions.Function("glGetTextureImage");
	glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)_Functions.Function("glGetCompressedTextureImage");
	glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)_Functions.Function("glGetTextureLevelParameterfv");
	glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)_Functions.Function("glGetTextureLevelParameteriv");
	glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)_Functions.Function("glGetTextureParameterfv");
	glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)_Functions.Function("glGetTextureParameterIiv");
	glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)_Functions.Function("glGetTextureParameterIuiv");
	glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)_Functions.Function("glGetTextureParameteriv");
	glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)_Functions.Function("glCreateVertexArrays");
	glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)_Functions.Function("glDisableVertexArrayAttrib");
	glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)_Functions.Function("glEnableVertexArrayAttrib");
	glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)_Functions.Function("glVertexArrayElementBuffer");
	glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)_Functions.Function("glVertexArrayVertexBuffer");
	glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)_Functions.Function("glVertexArrayVertexBuffers");
	glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)_Functions.Function("glVertexArrayAttribBinding");
	glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)_Functions.Function("glVertexArrayAttribFormat");
	glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)_Functions.Function("glVertexArrayAttribIFormat");
	glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)_Functions.Function("glVertexArrayAttribLFormat");
	glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)_Functions.Function("glVertexArrayBindingDivisor");
	glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)_Functions.Function("glGetVertexArrayiv");
	glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)_Functions.Function("glGetVertexArrayIndexediv");
	glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)_Functions.Function("glGetVertexArrayIndexed64iv");
	glCreateSamplers = (PFNGLCREATESAMPLERSPROC)_Functions.Function("glCreateSamplers");
	glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)_Functions.Function("glCreateProgramPipelines");
	glCreateQueries = (PFNGLCREATEQUERIESPROC)_Functions.Function("glCreateQueries");
	glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)_Functions.Function("glGetQueryBufferObjecti64v");
	glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)_Functions.Function("glGetQueryBufferObjectiv");
	glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)_Functions.Function("glGetQueryBufferObjectui64v");
	glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)_Functions.Function("glGetQueryBufferObjectuiv");
	glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)_Functions.Function("glMemoryBarrierByRegion");
	glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)_Functions.Function("glGetTextureSubImage");
	glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)_Functions.Function("glGetCompressedTextureSubImage");
	glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)_Functions.Function("glGetGraphicsResetStatus");
	glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)_Functions.Function("glGetnCompressedTexImage");
	glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)_Functions.Function("glGetnTexImage");
	glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)_Functions.Function("glGetnUniformdv");
	glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)_Functions.Function("glGetnUniformfv");
	glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)_Functions.Function("glGetnUniformiv");
	glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)_Functions.Function("glGetnUniformuiv");
	glReadnPixels = (PFNGLREADNPIXELSPROC)_Functions.Function("glReadnPixels");
	glGetnMapdv = (PFNGLGETNMAPDVPROC)_Functions.Function("glGetnMapdv");
	glGetnMapfv = (PFNGLGETNMAPFVPROC)_Functions.Function("glGetnMapfv");
	glGetnMapiv = (PFNGLGETNMAPIVPROC)_Functions.Function("glGetnMapiv");
	glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)_Functions.Function("glGetnPixelMapfv");
	glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)_Functions.Function("glGetnPixelMapuiv");
	glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)_Functions.Function("glGetnPixelMapusv");
	glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)_Functions.Function("glGetnPolygonStipple");
	glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)_Functions.Function("glGetnColorTable");
	glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)_Functions.Function("glGetnConvolutionFilter");
	glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)_Functions.Function("glGetnSeparableFilter");
	glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)_Functions.Function("glGetnHistogram");
	glGetnMinmax = (PFNGLGETNMINMAXPROC)_Functions.Function("glGetnMinmax");
	glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)_Functions.Function("glTextureBarrier");
}

void LDL_OpenGLLoader::Init_4_6()
{
	glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)_Functions.Function("glSpecializeShader");
	glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)_Functions.Function("glMultiDrawArraysIndirectCount");
	glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)_Functions.Function("glMultiDrawElementsIndirectCount");
	glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)_Functions.Function("glPolygonOffsetClamp");
}
