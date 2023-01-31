#include <LDL/OpenGL/OpenGLLoader.hpp>
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Core/IntegerToString.hpp>

using namespace LDL;

OpenGLLoader::OpenGLLoader(size_t major, size_t minor) :
	_Major(major),
	_Minor(minor)
{
	if (Equal(1, 0))
	{
		Init_1_0();
	}
	else if (Equal(1, 1))
	{
		Init_1_0();
		Init_1_1();
	}
	else
	{
		Core::IntegerToString conv;

		std::string error = "OpenGL ";
		error += conv.Convert(Major());
		error += ".";
		error += conv.Convert(Minor());
		error += " not support";

		throw LDL::Core::RuntimeError(error);
	}
}

OpenGLLoader::~OpenGLLoader()
{
}

bool OpenGLLoader::Equal(size_t major, size_t minor)
{
	return Major() == major && Minor() == minor;
}

size_t OpenGLLoader::Major()
{
	return _Major;
}

size_t OpenGLLoader::Minor()
{
	return _Minor;
}

void OpenGLLoader::Init_1_0()
{
	glAccum = (pglAccum*)_Functions.Function("glAccum");
	glAlphaFunc = (pglAlphaFunc*)_Functions.Function("glAlphaFunc");
	glAreTexturesResident = (pglAreTexturesResident*)_Functions.Function("glAreTexturesResident");
	glArrayElement = (pglArrayElement*)_Functions.Function("glArrayElement");
	glBegin = (pglBegin*)_Functions.Function("glBegin");
	glBindTexture = (pglBindTexture*)_Functions.Function("glBindTexture");
	glBitmap = (pglBitmap*)_Functions.Function("glBitmap");
	glBlendFunc = (pglBlendFunc*)_Functions.Function("glBlendFunc");
	glCallList = (pglCallList*)_Functions.Function("glCallList");
	glCallLists = (pglCallLists*)_Functions.Function("glCallLists");
	glClear = (pglClear*)_Functions.Function("glClear");
	glClearAccum = (pglClearAccum*)_Functions.Function("glClearAccum");
	glClearColor = (pglClearColor*)_Functions.Function("glClearColor");
	glClearDepth = (pglClearDepth*)_Functions.Function("glClearDepth");
	glClearIndex = (pglClearIndex*)_Functions.Function("glClearIndex");
	glClearStencil = (pglClearStencil*)_Functions.Function("glClearStencil");
	glClipPlane = (pglClipPlane*)_Functions.Function("glClipPlane");
	glColor3b = (pglColor3b*)_Functions.Function("glColor3b");
	glColor3bv = (pglColor3bv*)_Functions.Function("glColor3bv");
	glColor3d = (pglColor3d*)_Functions.Function("glColor3d");
	glColor3dv = (pglColor3dv*)_Functions.Function("glColor3dv");
	glColor3f = (pglColor3f*)_Functions.Function("glColor3f");
	glColor3fv = (pglColor3fv*)_Functions.Function("glColor3fv");
	glColor3i = (pglColor3i*)_Functions.Function("glColor3i");
	glColor3iv = (pglColor3iv*)_Functions.Function("glColor3iv");
	glColor3s = (pglColor3s*)_Functions.Function("glColor3s");
	glColor3sv = (pglColor3sv*)_Functions.Function("glColor3sv");
	glColor3ub = (pglColor3ub*)_Functions.Function("glColor3ub");
	glColor3ubv = (pglColor3ubv*)_Functions.Function("glColor3ubv");
	glColor3ui = (pglColor3ui*)_Functions.Function("glColor3ui");
	glColor3uiv = (pglColor3uiv*)_Functions.Function("glColor3uiv");
	glColor3us = (pglColor3us*)_Functions.Function("glColor3us");
	glColor3usv = (pglColor3usv*)_Functions.Function("glColor3usv");
	glColor4b = (pglColor4b*)_Functions.Function("glColor4b");
	glColor4bv = (pglColor4bv*)_Functions.Function("glColor4bv");
	glColor4d = (pglColor4d*)_Functions.Function("glColor4d");
	glColor4dv = (pglColor4dv*)_Functions.Function("glColor4dv");
	glColor4f = (pglColor4f*)_Functions.Function("glColor4f");
	glColor4fv = (pglColor4fv*)_Functions.Function("glColor4fv");
	glColor4i = (pglColor4i*)_Functions.Function("glColor4i");
	glColor4iv = (pglColor4iv*)_Functions.Function("glColor4iv");
	glColor4s = (pglColor4s*)_Functions.Function("glColor4s");
	glColor4sv = (pglColor4sv*)_Functions.Function("glColor4sv");
	glColor4ub = (pglColor4ub*)_Functions.Function("glColor4ub");
	glColor4ubv = (pglColor4ubv*)_Functions.Function("glColor4ubv");
	glColor4ui = (pglColor4ui*)_Functions.Function("glColor4ui");
	glColor4uiv = (pglColor4uiv*)_Functions.Function("glColor4uiv");
	glColor4us = (pglColor4us*)_Functions.Function("glColor4us");
	glColor4usv = (pglColor4usv*)_Functions.Function("glColor4usv");
	glColorMask = (pglColorMask*)_Functions.Function("glColorMask");
	glColorMaterial = (pglColorMaterial*)_Functions.Function("glColorMaterial");
	glColorPointer = (pglColorPointer*)_Functions.Function("glColorPointer");
	glCopyPixels = (pglCopyPixels*)_Functions.Function("glCopyPixels");
	glCopyTexImage1D = (pglCopyTexImage1D*)_Functions.Function("glCopyTexImage1D");
	glCopyTexImage2D = (pglCopyTexImage2D*)_Functions.Function("glCopyTexImage2D");
	glCopyTexSubImage1D = (pglCopyTexSubImage1D*)_Functions.Function("glCopyTexSubImage1D");
	glCopyTexSubImage2D = (pglCopyTexSubImage2D*)_Functions.Function("glCopyTexSubImage2D");
	glCullFace = (pglCullFace*)_Functions.Function("glCullFace");
	glDeleteLists = (pglDeleteLists*)_Functions.Function("glDeleteLists");
	glDeleteTextures = (pglDeleteTextures*)_Functions.Function("glDeleteTextures");
	glDepthFunc = (pglDepthFunc*)_Functions.Function("glDepthFunc");
	glDepthMask = (pglDepthMask*)_Functions.Function("glDepthMask");
	glDepthRange = (pglDepthRange*)_Functions.Function("glDepthRange");
	glDisable = (pglDisable*)_Functions.Function("glDisable");
	glDisableClientState = (pglDisableClientState*)_Functions.Function("glDisableClientState");
	glDrawArrays = (pglDrawArrays*)_Functions.Function("glDrawArrays");
	glDrawBuffer = (pglDrawBuffer*)_Functions.Function("glDrawBuffer");
	glDrawElements = (pglDrawElements*)_Functions.Function("glDrawElements");
	glDrawPixels = (pglDrawPixels*)_Functions.Function("glDrawPixels");
	glEdgeFlag = (pglEdgeFlag*)_Functions.Function("glEdgeFlag");
	glEdgeFlagPointer = (pglEdgeFlagPointer*)_Functions.Function("glEdgeFlagPointer");
	glEdgeFlagv = (pglEdgeFlagv*)_Functions.Function("glEdgeFlagv");
	glEnable = (pglEnable*)_Functions.Function("glEnable");
	glEnableClientState = (pglEnableClientState*)_Functions.Function("glEnableClientState");
	glEnd = (pglEnd*)_Functions.Function("glEnd");
	glEndList = (pglEndList*)_Functions.Function("glEndList");
	glEvalCoord1d = (pglEvalCoord1d*)_Functions.Function("glEvalCoord1d");
	glEvalCoord1dv = (pglEvalCoord1dv*)_Functions.Function("glEvalCoord1dv");
	glEvalCoord1f = (pglEvalCoord1f*)_Functions.Function("glEvalCoord1f");
	glEvalCoord1fv = (pglEvalCoord1fv*)_Functions.Function("glEvalCoord1fv");
	glEvalCoord2d = (pglEvalCoord2d*)_Functions.Function("glEvalCoord2d");
	glEvalCoord2dv = (pglEvalCoord2dv*)_Functions.Function("glEvalCoord2dv");
	glEvalCoord2f = (pglEvalCoord2f*)_Functions.Function("glEvalCoord2f");
	glEvalCoord2fv = (pglEvalCoord2fv*)_Functions.Function("glEvalCoord2fv");
	glEvalMesh1 = (pglEvalMesh1*)_Functions.Function("glEvalMesh1");
	glEvalMesh2 = (pglEvalMesh2*)_Functions.Function("glEvalMesh2");
	glEvalPoint1 = (pglEvalPoint1*)_Functions.Function("glEvalPoint1");
	glEvalPoint2 = (pglEvalPoint2*)_Functions.Function("glEvalPoint2");
	glFeedbackBuffer = (pglFeedbackBuffer*)_Functions.Function("glFeedbackBuffer");
	glFinish = (pglFinish*)_Functions.Function("glFinish");
	glFlush = (pglFlush*)_Functions.Function("glFlush");
	glFogf = (pglFogf*)_Functions.Function("glFogf");
	glFogfv = (pglFogfv*)_Functions.Function("glFogfv");
	glFogi = (pglFogi*)_Functions.Function("glFogi");
	glFogiv = (pglFogiv*)_Functions.Function("glFogiv");
	glFrontFace = (pglFrontFace*)_Functions.Function("glFrontFace");
	glFrustum = (pglFrustum*)_Functions.Function("glFrustum");
	glGenLists = (pglGenLists*)_Functions.Function("glGenLists");
	glGenTextures = (pglGenTextures*)_Functions.Function("glGenTextures");
	glGetBooleanv = (pglGetBooleanv*)_Functions.Function("glGetBooleanv");
	glGetClipPlane = (pglGetClipPlane*)_Functions.Function("glGetClipPlane");
	glGetDoublev = (pglGetDoublev*)_Functions.Function("glGetDoublev");
	glGetError = (pglGetError*)_Functions.Function("glGetError");
	glGetFloatv = (pglGetFloatv*)_Functions.Function("glGetFloatv");
	glGetIntegerv = (pglGetIntegerv*)_Functions.Function("glGetIntegerv");
	glGetLightfv = (pglGetLightfv*)_Functions.Function("glGetLightfv");
	glGetLightiv = (pglGetLightiv*)_Functions.Function("glGetLightiv");
	glGetMapdv = (pglGetMapdv*)_Functions.Function("glGetMapdv");
	glGetMapfv = (pglGetMapfv*)_Functions.Function("glGetMapfv");
	glGetMapiv = (pglGetMapiv*)_Functions.Function("glGetMapiv");
	glGetMaterialfv = (pglGetMaterialfv*)_Functions.Function("glGetMaterialfv");
	glGetMaterialiv = (pglGetMaterialiv*)_Functions.Function("glGetMaterialiv");
	glGetPixelMapfv = (pglGetPixelMapfv*)_Functions.Function("glGetPixelMapfv");
	glGetPixelMapuiv = (pglGetPixelMapuiv*)_Functions.Function("glGetPixelMapuiv");
	glGetPixelMapusv = (pglGetPixelMapusv*)_Functions.Function("glGetPixelMapusv");
	glGetPointerv = (pglGetPointerv*)_Functions.Function("glGetPointerv");
	glGetPolygonStipple = (pglGetPolygonStipple*)_Functions.Function("glGetPolygonStipple");
	glGetString = (pglGetString*)_Functions.Function("glGetString");
	glGetTexEnvfv = (pglGetTexEnvfv*)_Functions.Function("glGetTexEnvfv");
	glGetTexEnviv = (pglGetTexEnviv*)_Functions.Function("glGetTexEnviv");
	glGetTexGendv = (pglGetTexGendv*)_Functions.Function("glGetTexGendv");
	glGetTexGenfv = (pglGetTexGenfv*)_Functions.Function("glGetTexGenfv");
	glGetTexGeniv = (pglGetTexGeniv*)_Functions.Function("glGetTexGeniv");
	glGetTexImage = (pglGetTexImage*)_Functions.Function("glGetTexImage");
	glGetTexLevelParameterfv = (pglGetTexLevelParameterfv*)_Functions.Function("glGetTexLevelParameterfv");
	glGetTexLevelParameteriv = (pglGetTexLevelParameteriv*)_Functions.Function("glGetTexLevelParameteriv");
	glGetTexParameterfv = (pglGetTexParameterfv*)_Functions.Function("glGetTexParameterfv");
	glGetTexParameteriv = (pglGetTexParameteriv*)_Functions.Function("glGetTexParameteriv");
	glHint = (pglHint*)_Functions.Function("glHint");
	glIndexMask = (pglIndexMask*)_Functions.Function("glIndexMask");
	glIndexPointer = (pglIndexPointer*)_Functions.Function("glIndexPointer");
	glIndexd = (pglIndexd*)_Functions.Function("glIndexd");
	glIndexdv = (pglIndexdv*)_Functions.Function("glIndexdv");
	glIndexf = (pglIndexf*)_Functions.Function("glIndexf");
	glIndexfv = (pglIndexfv*)_Functions.Function("glIndexfv");
	glIndexi = (pglIndexi*)_Functions.Function("glIndexi");
	glIndexiv = (pglIndexiv*)_Functions.Function("glIndexiv");
	glIndexs = (pglIndexs*)_Functions.Function("glIndexs");
	glIndexsv = (pglIndexsv*)_Functions.Function("glIndexsv");
	glIndexub = (pglIndexub*)_Functions.Function("glIndexub");
	glIndexubv = (pglIndexubv*)_Functions.Function("glIndexubv");
	glInitNames = (pglInitNames*)_Functions.Function("glInitNames");
	glInterleavedArrays = (pglInterleavedArrays*)_Functions.Function("glInterleavedArrays");
	glIsEnabled = (pglIsEnabled*)_Functions.Function("glIsEnabled");
	glIsList = (pglIsList*)_Functions.Function("glIsList");
	glIsTexture = (pglIsTexture*)_Functions.Function("glIsTexture");
	glLightModelf = (pglLightModelf*)_Functions.Function("glLightModelf");
	glLightModelfv = (pglLightModelfv*)_Functions.Function("glLightModelfv");
	glLightModeli = (pglLightModeli*)_Functions.Function("glLightModeli");
	glLightModeliv = (pglLightModeliv*)_Functions.Function("glLightModeliv");
	glLightf = (pglLightf*)_Functions.Function("glLightf");
	glLightfv = (pglLightfv*)_Functions.Function("glLightfv");
	glLighti = (pglLighti*)_Functions.Function("glLighti");
	glLightiv = (pglLightiv*)_Functions.Function("glLightiv");
	glLineStipple = (pglLineStipple*)_Functions.Function("glLineStipple");
	glLineWidth = (pglLineWidth*)_Functions.Function("glLineWidth");
	glListBase = (pglListBase*)_Functions.Function("glListBase");
	glLoadIdentity = (pglLoadIdentity*)_Functions.Function("glLoadIdentity");
	glLoadMatrixd = (pglLoadMatrixd*)_Functions.Function("glLoadMatrixd");
	glLoadMatrixf = (pglLoadMatrixf*)_Functions.Function("glLoadMatrixf");
	glLoadName = (pglLoadName*)_Functions.Function("glLoadName");
	glLogicOp = (pglLogicOp*)_Functions.Function("glLogicOp");
	glMap1d = (pglMap1d*)_Functions.Function("glMap1d");
	glMap1f = (pglMap1f*)_Functions.Function("glMap1f");
	glMap2d = (pglMap2d*)_Functions.Function("glMap2d");
	glMap2f = (pglMap2f*)_Functions.Function("glMap2f");
	glMapGrid1d = (pglMapGrid1d*)_Functions.Function("glMapGrid1d");
	glMapGrid1f = (pglMapGrid1f*)_Functions.Function("glMapGrid1f");
	glMapGrid2d = (pglMapGrid2d*)_Functions.Function("glMapGrid2d");
	glMapGrid2f = (pglMapGrid2f*)_Functions.Function("glMapGrid2f");
	glMaterialf = (pglMaterialf*)_Functions.Function("glMaterialf");
	glMaterialfv = (pglMaterialfv*)_Functions.Function("glMaterialfv");
	glMateriali = (pglMateriali*)_Functions.Function("glMateriali");
	glMaterialiv = (pglMaterialiv*)_Functions.Function("glMaterialiv");
	glMatrixMode = (pglMatrixMode*)_Functions.Function("glMatrixMode");
	glMultMatrixd = (pglMultMatrixd*)_Functions.Function("glMultMatrixd");
	glMultMatrixf = (pglMultMatrixf*)_Functions.Function("glMultMatrixf");
	glNewList = (pglNewList*)_Functions.Function("glNewList");
	glNormal3b = (pglNormal3b*)_Functions.Function("glNormal3b");
	glNormal3bv = (pglNormal3bv*)_Functions.Function("glNormal3bv");
	glNormal3d = (pglNormal3d*)_Functions.Function("glNormal3d");
	glNormal3dv = (pglNormal3dv*)_Functions.Function("glNormal3dv");
	glNormal3f = (pglNormal3f*)_Functions.Function("glNormal3f");
	glNormal3fv = (pglNormal3fv*)_Functions.Function("glNormal3fv");
	glNormal3i = (pglNormal3i*)_Functions.Function("glNormal3i");
	glNormal3iv = (pglNormal3iv*)_Functions.Function("glNormal3iv");
	glNormal3s = (pglNormal3s*)_Functions.Function("glNormal3s");
	glNormal3sv = (pglNormal3sv*)_Functions.Function("glNormal3sv");
	glNormalPointer = (pglNormalPointer*)_Functions.Function("glNormalPointer");
	glOrtho = (pglOrtho*)_Functions.Function("glOrtho");
	glPassThrough = (pglPassThrough*)_Functions.Function("glPassThrough");
	glPixelMapfv = (pglPixelMapfv*)_Functions.Function("glPixelMapfv");
	glPixelMapuiv = (pglPixelMapuiv*)_Functions.Function("glPixelMapuiv");
	glPixelMapusv = (pglPixelMapusv*)_Functions.Function("glPixelMapusv");
	glPixelStoref = (pglPixelStoref*)_Functions.Function("glPixelStoref");
	glPixelStorei = (pglPixelStorei*)_Functions.Function("glPixelStorei");
	glPixelTransferf = (pglPixelTransferf*)_Functions.Function("glPixelTransferf");
	glPixelTransferi = (pglPixelTransferi*)_Functions.Function("glPixelTransferi");
	glPixelZoom = (pglPixelZoom*)_Functions.Function("glPixelZoom");
	glPointSize = (pglPointSize*)_Functions.Function("glPointSize");
	glPolygonMode = (pglPolygonMode*)_Functions.Function("glPolygonMode");
	glPolygonOffset = (pglPolygonOffset*)_Functions.Function("glPolygonOffset");
	glPolygonStipple = (pglPolygonStipple*)_Functions.Function("glPolygonStipple");
	glPopAttrib = (pglPopAttrib*)_Functions.Function("glPopAttrib");
	glPopClientAttrib = (pglPopClientAttrib*)_Functions.Function("glPopClientAttrib");
	glPopMatrix = (pglPopMatrix*)_Functions.Function("glPopMatrix");
	glPopName = (pglPopName*)_Functions.Function("glPopName");
	glPrioritizeTextures = (pglPrioritizeTextures*)_Functions.Function("glPrioritizeTextures");
	glPushAttrib = (pglPushAttrib*)_Functions.Function("glPushAttrib");
	glPushClientAttrib = (pglPushClientAttrib*)_Functions.Function("glPushClientAttrib");
	glPushMatrix = (pglPushMatrix*)_Functions.Function("glPushMatrix");
	glPushName = (pglPushName*)_Functions.Function("glPushName");
	glRasterPos2d = (pglRasterPos2d*)_Functions.Function("glRasterPos2d");
	glRasterPos2dv = (pglRasterPos2dv*)_Functions.Function("glRasterPos2dv");
	glRasterPos2f = (pglRasterPos2f*)_Functions.Function("glRasterPos2f");
	glRasterPos2fv = (pglRasterPos2fv*)_Functions.Function("glRasterPos2fv");
	glRasterPos2i = (pglRasterPos2i*)_Functions.Function("glRasterPos2i");
	glRasterPos2iv = (pglRasterPos2iv*)_Functions.Function("glRasterPos2iv");
	glRasterPos2s = (pglRasterPos2s*)_Functions.Function("glRasterPos2s");
	glRasterPos2sv = (pglRasterPos2sv*)_Functions.Function("glRasterPos2sv");
	glRasterPos3d = (pglRasterPos3d*)_Functions.Function("glRasterPos3d");
	glRasterPos3dv = (pglRasterPos3dv*)_Functions.Function("glRasterPos3dv");
	glRasterPos3f = (pglRasterPos3f*)_Functions.Function("glRasterPos3f");
	glRasterPos3fv = (pglRasterPos3fv*)_Functions.Function("glRasterPos3fv");
	glRasterPos3i = (pglRasterPos3i*)_Functions.Function("glRasterPos3i");
	glRasterPos3iv = (pglRasterPos3iv*)_Functions.Function("glRasterPos3iv");
	glRasterPos3s = (pglRasterPos3s*)_Functions.Function("glRasterPos3s");
	glRasterPos3sv = (pglRasterPos3sv*)_Functions.Function("glRasterPos3sv");
	glRasterPos4d = (pglRasterPos4d*)_Functions.Function("glRasterPos4d");
	glRasterPos4dv = (pglRasterPos4dv*)_Functions.Function("glRasterPos4dv");
	glRasterPos4f = (pglRasterPos4f*)_Functions.Function("glRasterPos4f");
	glRasterPos4fv = (pglRasterPos4fv*)_Functions.Function("glRasterPos4fv");
	glRasterPos4i = (pglRasterPos4i*)_Functions.Function("glRasterPos4i");
	glRasterPos4iv = (pglRasterPos4iv*)_Functions.Function("glRasterPos4iv");
	glRasterPos4s = (pglRasterPos4s*)_Functions.Function("glRasterPos4s");
	glRasterPos4sv = (pglRasterPos4sv*)_Functions.Function("glRasterPos4sv");
	glReadBuffer = (pglReadBuffer*)_Functions.Function("glReadBuffer");
	glReadPixels = (pglReadPixels*)_Functions.Function("glReadPixels");
	glRectd = (pglRectd*)_Functions.Function("glRectd");
	glRectdv = (pglRectdv*)_Functions.Function("glRectdv");
	glRectf = (pglRectf*)_Functions.Function("glRectf");
	glRectfv = (pglRectfv*)_Functions.Function("glRectfv");
	glRecti = (pglRecti*)_Functions.Function("glRecti");
	glRectiv = (pglRectiv*)_Functions.Function("glRectiv");
	glRects = (pglRects*)_Functions.Function("glRects");
	glRectsv = (pglRectsv*)_Functions.Function("glRectsv");
	glRenderMode = (pglRenderMode*)_Functions.Function("glRenderMode");
	glRotated = (pglRotated*)_Functions.Function("glRotated");
	glRotatef = (pglRotatef*)_Functions.Function("glRotatef");
	glScaled = (pglScaled*)_Functions.Function("glScaled");
	glScalef = (pglScalef*)_Functions.Function("glScalef");
	glScissor = (pglScissor*)_Functions.Function("glScissor");
	glSelectBuffer = (pglSelectBuffer*)_Functions.Function("glSelectBuffer");
	glShadeModel = (pglShadeModel*)_Functions.Function("glShadeModel");
	glStencilFunc = (pglStencilFunc*)_Functions.Function("glStencilFunc");
	glStencilMask = (pglStencilMask*)_Functions.Function("glStencilMask");
	glStencilOp = (pglStencilOp*)_Functions.Function("glStencilOp");
	glTexCoord1d = (pglTexCoord1d*)_Functions.Function("glTexCoord1d");
	glTexCoord1dv = (pglTexCoord1dv*)_Functions.Function("glTexCoord1dv");
	glTexCoord1f = (pglTexCoord1f*)_Functions.Function("glTexCoord1f");
	glTexCoord1fv = (pglTexCoord1fv*)_Functions.Function("glTexCoord1fv");
	glTexCoord1i = (pglTexCoord1i*)_Functions.Function("glTexCoord1i");
	glTexCoord1iv = (pglTexCoord1iv*)_Functions.Function("glTexCoord1iv");
	glTexCoord1s = (pglTexCoord1s*)_Functions.Function("glTexCoord1s");
	glTexCoord1sv = (pglTexCoord1sv*)_Functions.Function("glTexCoord1sv");
	glTexCoord2d = (pglTexCoord2d*)_Functions.Function("glTexCoord2d");
	glTexCoord2dv = (pglTexCoord2dv*)_Functions.Function("glTexCoord2dv");
	glTexCoord2f = (pglTexCoord2f*)_Functions.Function("glTexCoord2f");
	glTexCoord2fv = (pglTexCoord2fv*)_Functions.Function("glTexCoord2fv");
	glTexCoord2i = (pglTexCoord2i*)_Functions.Function("glTexCoord2i");
	glTexCoord2iv = (pglTexCoord2iv*)_Functions.Function("glTexCoord2iv");
	glTexCoord2s = (pglTexCoord2s*)_Functions.Function("glTexCoord2s");
	glTexCoord2sv = (pglTexCoord2sv*)_Functions.Function("glTexCoord2sv");
	glTexCoord3d = (pglTexCoord3d*)_Functions.Function("glTexCoord3d");
	glTexCoord3dv = (pglTexCoord3dv*)_Functions.Function("glTexCoord3dv");
	glTexCoord3f = (pglTexCoord3f*)_Functions.Function("glTexCoord3f");
	glTexCoord3fv = (pglTexCoord3fv*)_Functions.Function("glTexCoord3fv");
	glTexCoord3i = (pglTexCoord3i*)_Functions.Function("glTexCoord3i");
	glTexCoord3iv = (pglTexCoord3iv*)_Functions.Function("glTexCoord3iv");
	glTexCoord3s = (pglTexCoord3s*)_Functions.Function("glTexCoord3s");
	glTexCoord3sv = (pglTexCoord3sv*)_Functions.Function("glTexCoord3sv");
	glTexCoord4d = (pglTexCoord4d*)_Functions.Function("glTexCoord4d");
	glTexCoord4dv = (pglTexCoord4dv*)_Functions.Function("glTexCoord4dv");
	glTexCoord4f = (pglTexCoord4f*)_Functions.Function("glTexCoord4f");
	glTexCoord4fv = (pglTexCoord4fv*)_Functions.Function("glTexCoord4fv");
	glTexCoord4i = (pglTexCoord4i*)_Functions.Function("glTexCoord4i");
	glTexCoord4iv = (pglTexCoord4iv*)_Functions.Function("glTexCoord4iv");
	glTexCoord4s = (pglTexCoord4s*)_Functions.Function("glTexCoord4s");
	glTexCoord4sv = (pglTexCoord4sv*)_Functions.Function("glTexCoord4sv");
	glTexCoordPointer = (pglTexCoordPointer*)_Functions.Function("glTexCoordPointer");
	glTexEnvf = (pglTexEnvf*)_Functions.Function("glTexEnvf");
	glTexEnvfv = (pglTexEnvfv*)_Functions.Function("glTexEnvfv");
	glTexEnvi = (pglTexEnvi*)_Functions.Function("glTexEnvi");
	glTexEnviv = (pglTexEnviv*)_Functions.Function("glTexEnviv");
	glTexGend = (pglTexGend*)_Functions.Function("glTexGend");
	glTexGendv = (pglTexGendv*)_Functions.Function("glTexGendv");
	glTexGenf = (pglTexGenf*)_Functions.Function("glTexGenf");
	glTexGenfv = (pglTexGenfv*)_Functions.Function("glTexGenfv");
	glTexGeni = (pglTexGeni*)_Functions.Function("glTexGeni");
	glTexGeniv = (pglTexGeniv*)_Functions.Function("glTexGeniv");
	glTexImage1D = (pglTexImage1D*)_Functions.Function("glTexImage1D");
	glTexImage2D = (pglTexImage2D*)_Functions.Function("glTexImage2D");
	glTexParameterf = (pglTexParameterf*)_Functions.Function("glTexParameterf");
	glTexParameterfv = (pglTexParameterfv*)_Functions.Function("glTexParameterfv");
	glTexParameteri = (pglTexParameteri*)_Functions.Function("glTexParameteri");
	glTexParameteriv = (pglTexParameteriv*)_Functions.Function("glTexParameteriv");
	glTexSubImage1D = (pglTexSubImage1D*)_Functions.Function("glTexSubImage1D");
	glTexSubImage2D = (pglTexSubImage2D*)_Functions.Function("glTexSubImage2D");
	glTranslated = (pglTranslated*)_Functions.Function("glTranslated");
	glTranslatef = (pglTranslatef*)_Functions.Function("glTranslatef");
	glVertex2d = (pglVertex2d*)_Functions.Function("glVertex2d");
	glVertex2dv = (pglVertex2dv*)_Functions.Function("glVertex2dv");
	glVertex2f = (pglVertex2f*)_Functions.Function("glVertex2f");
	glVertex2fv = (pglVertex2fv*)_Functions.Function("glVertex2fv");
	glVertex2i = (pglVertex2i*)_Functions.Function("glVertex2i");
	glVertex2iv = (pglVertex2iv*)_Functions.Function("glVertex2iv");
	glVertex2s = (pglVertex2s*)_Functions.Function("glVertex2s");
	glVertex2sv = (pglVertex2sv*)_Functions.Function("glVertex2sv");
	glVertex3d = (pglVertex3d*)_Functions.Function("glVertex3d");
	glVertex3dv = (pglVertex3dv*)_Functions.Function("glVertex3dv");
	glVertex3f = (pglVertex3f*)_Functions.Function("glVertex3f");
	glVertex3fv = (pglVertex3fv*)_Functions.Function("glVertex3fv");
	glVertex3i = (pglVertex3i*)_Functions.Function("glVertex3i");
	glVertex3iv = (pglVertex3iv*)_Functions.Function("glVertex3iv");
	glVertex3s = (pglVertex3s*)_Functions.Function("glVertex3s");
	glVertex3sv = (pglVertex3sv*)_Functions.Function("glVertex3sv");
	glVertex4d = (pglVertex4d*)_Functions.Function("glVertex4d");
	glVertex4dv = (pglVertex4dv*)_Functions.Function("glVertex4dv");
	glVertex4f = (pglVertex4f*)_Functions.Function("glVertex4f");
	glVertex4fv = (pglVertex4fv*)_Functions.Function("glVertex4fv");
	glVertex4i = (pglVertex4i*)_Functions.Function("glVertex4i");
	glVertex4iv = (pglVertex4iv*)_Functions.Function("glVertex4iv");
	glVertex4s = (pglVertex4s*)_Functions.Function("glVertex4s");
	glVertex4sv = (pglVertex4sv*)_Functions.Function("glVertex4sv");
	glViewport = (pglViewport*)_Functions.Function("glViewport");
}

void LDL::OpenGLLoader::Init_1_1()
{
	glVertexPointer = (pglVertexPointer*)_Functions.Function("glVertexPointer");
}