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
	if (Major() == 1 && Minor() == 0)
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

size_t LDL::OpenGLLoader::Major()
{
	return _Major;
}

size_t LDL::OpenGLLoader::Minor()
{
	return _Minor;
}

void OpenGLLoader::Init_1_0()
{
	glAccum = (pglAccum*)_GpuFunctions.Function("glAccum");
	glAlphaFunc = (pglAlphaFunc*)_GpuFunctions.Function("glAlphaFunc");
	glAreTexturesResident = (pglAreTexturesResident*)_GpuFunctions.Function("glAreTexturesResident");
	glArrayElement = (pglArrayElement*)_GpuFunctions.Function("glArrayElement");
	glBegin = (pglBegin*)_GpuFunctions.Function("glBegin");
	glBindTexture = (pglBindTexture*)_GpuFunctions.Function("glBindTexture");
	glBitmap = (pglBitmap*)_GpuFunctions.Function("glBitmap");
	glBlendFunc = (pglBlendFunc*)_GpuFunctions.Function("glBlendFunc");
	glCallList = (pglCallList*)_GpuFunctions.Function("glCallList");
	glCallLists = (pglCallLists*)_GpuFunctions.Function("glCallLists");
	glClear = (pglClear*)_GpuFunctions.Function("glClear");
	glClearAccum = (pglClearAccum*)_GpuFunctions.Function("glClearAccum");
	glClearColor = (pglClearColor*)_GpuFunctions.Function("glClearColor");
	glClearDepth = (pglClearDepth*)_GpuFunctions.Function("glClearDepth");
	glClearIndex = (pglClearIndex*)_GpuFunctions.Function("glClearIndex");
	glClearStencil = (pglClearStencil*)_GpuFunctions.Function("glClearStencil");
	glClipPlane = (pglClipPlane*)_GpuFunctions.Function("glClipPlane");
	glColor3b = (pglColor3b*)_GpuFunctions.Function("glColor3b");
	glColor3bv = (pglColor3bv*)_GpuFunctions.Function("glColor3bv");
	glColor3d = (pglColor3d*)_GpuFunctions.Function("glColor3d");
	glColor3dv = (pglColor3dv*)_GpuFunctions.Function("glColor3dv");
	glColor3f = (pglColor3f*)_GpuFunctions.Function("glColor3f");
	glColor3fv = (pglColor3fv*)_GpuFunctions.Function("glColor3fv");
	glColor3i = (pglColor3i*)_GpuFunctions.Function("glColor3i");
	glColor3iv = (pglColor3iv*)_GpuFunctions.Function("glColor3iv");
	glColor3s = (pglColor3s*)_GpuFunctions.Function("glColor3s");
	glColor3sv = (pglColor3sv*)_GpuFunctions.Function("glColor3sv");
	glColor3ub = (pglColor3ub*)_GpuFunctions.Function("glColor3ub");
	glColor3ubv = (pglColor3ubv*)_GpuFunctions.Function("glColor3ubv");
	glColor3ui = (pglColor3ui*)_GpuFunctions.Function("glColor3ui");
	glColor3uiv = (pglColor3uiv*)_GpuFunctions.Function("glColor3uiv");
	glColor3us = (pglColor3us*)_GpuFunctions.Function("glColor3us");
	glColor3usv = (pglColor3usv*)_GpuFunctions.Function("glColor3usv");
	glColor4b = (pglColor4b*)_GpuFunctions.Function("glColor4b");
	glColor4bv = (pglColor4bv*)_GpuFunctions.Function("glColor4bv");
	glColor4d = (pglColor4d*)_GpuFunctions.Function("glColor4d");
	glColor4dv = (pglColor4dv*)_GpuFunctions.Function("glColor4dv");
	glColor4f = (pglColor4f*)_GpuFunctions.Function("glColor4f");
	glColor4fv = (pglColor4fv*)_GpuFunctions.Function("glColor4fv");
	glColor4i = (pglColor4i*)_GpuFunctions.Function("glColor4i");
	glColor4iv = (pglColor4iv*)_GpuFunctions.Function("glColor4iv");
	glColor4s = (pglColor4s*)_GpuFunctions.Function("glColor4s");
	glColor4sv = (pglColor4sv*)_GpuFunctions.Function("glColor4sv");
	glColor4ub = (pglColor4ub*)_GpuFunctions.Function("glColor4ub");
	glColor4ubv = (pglColor4ubv*)_GpuFunctions.Function("glColor4ubv");
	glColor4ui = (pglColor4ui*)_GpuFunctions.Function("glColor4ui");
	glColor4uiv = (pglColor4uiv*)_GpuFunctions.Function("glColor4uiv");
	glColor4us = (pglColor4us*)_GpuFunctions.Function("glColor4us");
	glColor4usv = (pglColor4usv*)_GpuFunctions.Function("glColor4usv");
	glColorMask = (pglColorMask*)_GpuFunctions.Function("glColorMask");
	glColorMaterial = (pglColorMaterial*)_GpuFunctions.Function("glColorMaterial");
	glColorPointer = (pglColorPointer*)_GpuFunctions.Function("glColorPointer");
	glCopyPixels = (pglCopyPixels*)_GpuFunctions.Function("glCopyPixels");
	glCopyTexImage1D = (pglCopyTexImage1D*)_GpuFunctions.Function("glCopyTexImage1D");
	glCopyTexImage2D = (pglCopyTexImage2D*)_GpuFunctions.Function("glCopyTexImage2D");
	glCopyTexSubImage1D = (pglCopyTexSubImage1D*)_GpuFunctions.Function("glCopyTexSubImage1D");
	glCopyTexSubImage2D = (pglCopyTexSubImage2D*)_GpuFunctions.Function("glCopyTexSubImage2D");
	glCullFace = (pglCullFace*)_GpuFunctions.Function("glCullFace");
	glDeleteLists = (pglDeleteLists*)_GpuFunctions.Function("glDeleteLists");
	glDeleteTextures = (pglDeleteTextures*)_GpuFunctions.Function("glDeleteTextures");
	glDepthFunc = (pglDepthFunc*)_GpuFunctions.Function("glDepthFunc");
	glDepthMask = (pglDepthMask*)_GpuFunctions.Function("glDepthMask");
	glDepthRange = (pglDepthRange*)_GpuFunctions.Function("glDepthRange");
	glDisable = (pglDisable*)_GpuFunctions.Function("glDisable");
	glDisableClientState = (pglDisableClientState*)_GpuFunctions.Function("glDisableClientState");
	glDrawArrays = (pglDrawArrays*)_GpuFunctions.Function("glDrawArrays");
	glDrawBuffer = (pglDrawBuffer*)_GpuFunctions.Function("glDrawBuffer");
	glDrawElements = (pglDrawElements*)_GpuFunctions.Function("glDrawElements");
	glDrawPixels = (pglDrawPixels*)_GpuFunctions.Function("glDrawPixels");
	glEdgeFlag = (pglEdgeFlag*)_GpuFunctions.Function("glEdgeFlag");
	glEdgeFlagPointer = (pglEdgeFlagPointer*)_GpuFunctions.Function("glEdgeFlagPointer");
	glEdgeFlagv = (pglEdgeFlagv*)_GpuFunctions.Function("glEdgeFlagv");
	glEnable = (pglEnable*)_GpuFunctions.Function("glEnable");
	glEnableClientState = (pglEnableClientState*)_GpuFunctions.Function("glEnableClientState");
	glEnd = (pglEnd*)_GpuFunctions.Function("glEnd");
	glEndList = (pglEndList*)_GpuFunctions.Function("glEndList");
	glEvalCoord1d = (pglEvalCoord1d*)_GpuFunctions.Function("glEvalCoord1d");
	glEvalCoord1dv = (pglEvalCoord1dv*)_GpuFunctions.Function("glEvalCoord1dv");
	glEvalCoord1f = (pglEvalCoord1f*)_GpuFunctions.Function("glEvalCoord1f");
	glEvalCoord1fv = (pglEvalCoord1fv*)_GpuFunctions.Function("glEvalCoord1fv");
	glEvalCoord2d = (pglEvalCoord2d*)_GpuFunctions.Function("glEvalCoord2d");
	glEvalCoord2dv = (pglEvalCoord2dv*)_GpuFunctions.Function("glEvalCoord2dv");
	glEvalCoord2f = (pglEvalCoord2f*)_GpuFunctions.Function("glEvalCoord2f");
	glEvalCoord2fv = (pglEvalCoord2fv*)_GpuFunctions.Function("glEvalCoord2fv");
	glEvalMesh1 = (pglEvalMesh1*)_GpuFunctions.Function("glEvalMesh1");
	glEvalMesh2 = (pglEvalMesh2*)_GpuFunctions.Function("glEvalMesh2");
	glEvalPoint1 = (pglEvalPoint1*)_GpuFunctions.Function("glEvalPoint1");
	glEvalPoint2 = (pglEvalPoint2*)_GpuFunctions.Function("glEvalPoint2");
	glFeedbackBuffer = (pglFeedbackBuffer*)_GpuFunctions.Function("glFeedbackBuffer");
	glFinish = (pglFinish*)_GpuFunctions.Function("glFinish");
	glFlush = (pglFlush*)_GpuFunctions.Function("glFlush");
	glFogf = (pglFogf*)_GpuFunctions.Function("glFogf");
	glFogfv = (pglFogfv*)_GpuFunctions.Function("glFogfv");
	glFogi = (pglFogi*)_GpuFunctions.Function("glFogi");
	glFogiv = (pglFogiv*)_GpuFunctions.Function("glFogiv");
	glFrontFace = (pglFrontFace*)_GpuFunctions.Function("glFrontFace");
	glFrustum = (pglFrustum*)_GpuFunctions.Function("glFrustum");
	glGenLists = (pglGenLists*)_GpuFunctions.Function("glGenLists");
	glGenTextures = (pglGenTextures*)_GpuFunctions.Function("glGenTextures");
	glGetBooleanv = (pglGetBooleanv*)_GpuFunctions.Function("glGetBooleanv");
	glGetClipPlane = (pglGetClipPlane*)_GpuFunctions.Function("glGetClipPlane");
	glGetDoublev = (pglGetDoublev*)_GpuFunctions.Function("glGetDoublev");
	glGetError = (pglGetError*)_GpuFunctions.Function("glGetError");
	glGetFloatv = (pglGetFloatv*)_GpuFunctions.Function("glGetFloatv");
	glGetIntegerv = (pglGetIntegerv*)_GpuFunctions.Function("glGetIntegerv");
	glGetLightfv = (pglGetLightfv*)_GpuFunctions.Function("glGetLightfv");
	glGetLightiv = (pglGetLightiv*)_GpuFunctions.Function("glGetLightiv");
	glGetMapdv = (pglGetMapdv*)_GpuFunctions.Function("glGetMapdv");
	glGetMapfv = (pglGetMapfv*)_GpuFunctions.Function("glGetMapfv");
	glGetMapiv = (pglGetMapiv*)_GpuFunctions.Function("glGetMapiv");
	glGetMaterialfv = (pglGetMaterialfv*)_GpuFunctions.Function("glGetMaterialfv");
	glGetMaterialiv = (pglGetMaterialiv*)_GpuFunctions.Function("glGetMaterialiv");
	glGetPixelMapfv = (pglGetPixelMapfv*)_GpuFunctions.Function("glGetPixelMapfv");
	glGetPixelMapuiv = (pglGetPixelMapuiv*)_GpuFunctions.Function("glGetPixelMapuiv");
	glGetPixelMapusv = (pglGetPixelMapusv*)_GpuFunctions.Function("glGetPixelMapusv");
	glGetPointerv = (pglGetPointerv*)_GpuFunctions.Function("glGetPointerv");
	glGetPolygonStipple = (pglGetPolygonStipple*)_GpuFunctions.Function("glGetPolygonStipple");
	//glGetString = (pglGetString*)_GpuFunctions.Function("pglGetString");
	glGetTexEnvfv = (pglGetTexEnvfv*)_GpuFunctions.Function("glGetTexEnvfv");
	glGetTexEnviv = (pglGetTexEnviv*)_GpuFunctions.Function("glGetTexEnviv");
	glGetTexGendv = (pglGetTexGendv*)_GpuFunctions.Function("glGetTexGendv");
	glGetTexGenfv = (pglGetTexGenfv*)_GpuFunctions.Function("glGetTexGenfv");
	glGetTexGeniv = (pglGetTexGeniv*)_GpuFunctions.Function("glGetTexGeniv");
	glGetTexImage = (pglGetTexImage*)_GpuFunctions.Function("glGetTexImage");
	glGetTexLevelParameterfv = (pglGetTexLevelParameterfv*)_GpuFunctions.Function("glGetTexLevelParameterfv");
	glGetTexLevelParameteriv = (pglGetTexLevelParameteriv*)_GpuFunctions.Function("glGetTexLevelParameteriv");
	glGetTexParameterfv = (pglGetTexParameterfv*)_GpuFunctions.Function("glGetTexParameterfv");
	glGetTexParameteriv = (pglGetTexParameteriv*)_GpuFunctions.Function("glGetTexParameteriv");
	glHint = (pglHint*)_GpuFunctions.Function("glHint");
	glIndexMask = (pglIndexMask*)_GpuFunctions.Function("glIndexMask");
	glIndexPointer = (pglIndexPointer*)_GpuFunctions.Function("glIndexPointer");
	glIndexd = (pglIndexd*)_GpuFunctions.Function("glIndexd");
	glIndexdv = (pglIndexdv*)_GpuFunctions.Function("glIndexdv");
	glIndexf = (pglIndexf*)_GpuFunctions.Function("glIndexf");
	glIndexfv = (pglIndexfv*)_GpuFunctions.Function("glIndexfv");
	glIndexi = (pglIndexi*)_GpuFunctions.Function("glIndexi");
	glIndexiv = (pglIndexiv*)_GpuFunctions.Function("glIndexiv");
	glIndexs = (pglIndexs*)_GpuFunctions.Function("glIndexs");
	glIndexsv = (pglIndexsv*)_GpuFunctions.Function("glIndexsv");
	glIndexub = (pglIndexub*)_GpuFunctions.Function("glIndexub");
	glIndexubv = (pglIndexubv*)_GpuFunctions.Function("glIndexubv");
	glInitNames = (pglInitNames*)_GpuFunctions.Function("glInitNames");
	glInterleavedArrays = (pglInterleavedArrays*)_GpuFunctions.Function("glInterleavedArrays");
	glIsEnabled = (pglIsEnabled*)_GpuFunctions.Function("glIsEnabled");
	glIsList = (pglIsList*)_GpuFunctions.Function("glIsList");
	glIsTexture = (pglIsTexture*)_GpuFunctions.Function("glIsTexture");
	glLightModelf = (pglLightModelf*)_GpuFunctions.Function("glLightModelf");
	glLightModelfv = (pglLightModelfv*)_GpuFunctions.Function("glLightModelfv");
	glLightModeli = (pglLightModeli*)_GpuFunctions.Function("glLightModeli");
	glLightModeliv = (pglLightModeliv*)_GpuFunctions.Function("glLightModeliv");
	glLightf = (pglLightf*)_GpuFunctions.Function("glLightf");
	glLightfv = (pglLightfv*)_GpuFunctions.Function("glLightfv");
	glLighti = (pglLighti*)_GpuFunctions.Function("glLighti");
	glLightiv = (pglLightiv*)_GpuFunctions.Function("glLightiv");
	glLineStipple = (pglLineStipple*)_GpuFunctions.Function("glLineStipple");
	glLineWidth = (pglLineWidth*)_GpuFunctions.Function("glLineWidth");
	glListBase = (pglListBase*)_GpuFunctions.Function("glListBase");
	glLoadIdentity = (pglLoadIdentity*)_GpuFunctions.Function("glLoadIdentity");
	glLoadMatrixd = (pglLoadMatrixd*)_GpuFunctions.Function("glLoadMatrixd");
	glLoadMatrixf = (pglLoadMatrixf*)_GpuFunctions.Function("glLoadMatrixf");
	glLoadName = (pglLoadName*)_GpuFunctions.Function("glLoadName");
	glLogicOp = (pglLogicOp*)_GpuFunctions.Function("glLogicOp");
	glMap1d = (pglMap1d*)_GpuFunctions.Function("glMap1d");
	glMap1f = (pglMap1f*)_GpuFunctions.Function("glMap1f");
	glMap2d = (pglMap2d*)_GpuFunctions.Function("glMap2d");
	glMap2f = (pglMap2f*)_GpuFunctions.Function("glMap2f");
	glMapGrid1d = (pglMapGrid1d*)_GpuFunctions.Function("glMapGrid1d");
	glMapGrid1f = (pglMapGrid1f*)_GpuFunctions.Function("glMapGrid1f");
	glMapGrid2d = (pglMapGrid2d*)_GpuFunctions.Function("glMapGrid2d");
	glMapGrid2f = (pglMapGrid2f*)_GpuFunctions.Function("glMapGrid2f");
	glMaterialf = (pglMaterialf*)_GpuFunctions.Function("glMaterialf");
	glMaterialfv = (pglMaterialfv*)_GpuFunctions.Function("glMaterialfv");
	glMateriali = (pglMateriali*)_GpuFunctions.Function("glMateriali");
	glMaterialiv = (pglMaterialiv*)_GpuFunctions.Function("glMaterialiv");
	glMatrixMode = (pglMatrixMode*)_GpuFunctions.Function("glMatrixMode");
	glMultMatrixd = (pglMultMatrixd*)_GpuFunctions.Function("glMultMatrixd");
	glMultMatrixf = (pglMultMatrixf*)_GpuFunctions.Function("glMultMatrixf");
	glNewList = (pglNewList*)_GpuFunctions.Function("glNewList");
	glNormal3b = (pglNormal3b*)_GpuFunctions.Function("glNormal3b");
	glNormal3bv = (pglNormal3bv*)_GpuFunctions.Function("glNormal3bv");
	glNormal3d = (pglNormal3d*)_GpuFunctions.Function("glNormal3d");
	glNormal3dv = (pglNormal3dv*)_GpuFunctions.Function("glNormal3dv");
	glNormal3f = (pglNormal3f*)_GpuFunctions.Function("glNormal3f");
	glNormal3fv = (pglNormal3fv*)_GpuFunctions.Function("glNormal3fv");
	glNormal3i = (pglNormal3i*)_GpuFunctions.Function("glNormal3i");
	glNormal3iv = (pglNormal3iv*)_GpuFunctions.Function("glNormal3iv");
	glNormal3s = (pglNormal3s*)_GpuFunctions.Function("glNormal3s");
	glNormal3sv = (pglNormal3sv*)_GpuFunctions.Function("glNormal3sv");
	glNormalPointer = (pglNormalPointer*)_GpuFunctions.Function("glNormalPointer");
	glOrtho = (pglOrtho*)_GpuFunctions.Function("glOrtho");
	glPassThrough = (pglPassThrough*)_GpuFunctions.Function("glPassThrough");
	glPixelMapfv = (pglPixelMapfv*)_GpuFunctions.Function("glPixelMapfv");
	glPixelMapuiv = (pglPixelMapuiv*)_GpuFunctions.Function("glPixelMapuiv");
	glPixelMapusv = (pglPixelMapusv*)_GpuFunctions.Function("glPixelMapusv");
	glPixelStoref = (pglPixelStoref*)_GpuFunctions.Function("glPixelStoref");
	glPixelStorei = (pglPixelStorei*)_GpuFunctions.Function("glPixelStorei");
	glPixelTransferf = (pglPixelTransferf*)_GpuFunctions.Function("glPixelTransferf");
	glPixelTransferi = (pglPixelTransferi*)_GpuFunctions.Function("glPixelTransferi");
	glPixelZoom = (pglPixelZoom*)_GpuFunctions.Function("glPixelZoom");
	glPointSize = (pglPointSize*)_GpuFunctions.Function("glPointSize");
	glPolygonMode = (pglPolygonMode*)_GpuFunctions.Function("glPolygonMode");
	glPolygonOffset = (pglPolygonOffset*)_GpuFunctions.Function("glPolygonOffset");
	glPolygonStipple = (pglPolygonStipple*)_GpuFunctions.Function("glPolygonStipple");
	glPopAttrib = (pglPopAttrib*)_GpuFunctions.Function("glPopAttrib");
	glPopClientAttrib = (pglPopClientAttrib*)_GpuFunctions.Function("glPopClientAttrib");
	glPopMatrix = (pglPopMatrix*)_GpuFunctions.Function("glPopMatrix");
	glPopName = (pglPopName*)_GpuFunctions.Function("glPopName");
	glPrioritizeTextures = (pglPrioritizeTextures*)_GpuFunctions.Function("glPrioritizeTextures");
	glPushAttrib = (pglPushAttrib*)_GpuFunctions.Function("glPushAttrib");
	glPushClientAttrib = (pglPushClientAttrib*)_GpuFunctions.Function("glPushClientAttrib");
	glPushMatrix = (pglPushMatrix*)_GpuFunctions.Function("glPushMatrix");
	glPushName = (pglPushName*)_GpuFunctions.Function("glPushName");
	glRasterPos2d = (pglRasterPos2d*)_GpuFunctions.Function("glRasterPos2d");
	glRasterPos2dv = (pglRasterPos2dv*)_GpuFunctions.Function("glRasterPos2dv");
	glRasterPos2f = (pglRasterPos2f*)_GpuFunctions.Function("glRasterPos2f");
	glRasterPos2fv = (pglRasterPos2fv*)_GpuFunctions.Function("glRasterPos2fv");
	glRasterPos2i = (pglRasterPos2i*)_GpuFunctions.Function("glRasterPos2i");
	glRasterPos2iv = (pglRasterPos2iv*)_GpuFunctions.Function("glRasterPos2iv");
	glRasterPos2s = (pglRasterPos2s*)_GpuFunctions.Function("glRasterPos2s");
	glRasterPos2sv = (pglRasterPos2sv*)_GpuFunctions.Function("glRasterPos2sv");
	glRasterPos3d = (pglRasterPos3d*)_GpuFunctions.Function("glRasterPos3d");
	glRasterPos3dv = (pglRasterPos3dv*)_GpuFunctions.Function("glRasterPos3dv");
	glRasterPos3f = (pglRasterPos3f*)_GpuFunctions.Function("glRasterPos3f");
	glRasterPos3fv = (pglRasterPos3fv*)_GpuFunctions.Function("glRasterPos3fv");
	glRasterPos3i = (pglRasterPos3i*)_GpuFunctions.Function("glRasterPos3i");
	glRasterPos3iv = (pglRasterPos3iv*)_GpuFunctions.Function("glRasterPos3iv");
	glRasterPos3s = (pglRasterPos3s*)_GpuFunctions.Function("glRasterPos3s");
	glRasterPos3sv = (pglRasterPos3sv*)_GpuFunctions.Function("glRasterPos3sv");
	glRasterPos4d = (pglRasterPos4d*)_GpuFunctions.Function("glRasterPos4d");
	glRasterPos4dv = (pglRasterPos4dv*)_GpuFunctions.Function("glRasterPos4dv");
	glRasterPos4f = (pglRasterPos4f*)_GpuFunctions.Function("glRasterPos4f");
	glRasterPos4fv = (pglRasterPos4fv*)_GpuFunctions.Function("glRasterPos4fv");
	glRasterPos4i = (pglRasterPos4i*)_GpuFunctions.Function("glRasterPos4i");
	glRasterPos4iv = (pglRasterPos4iv*)_GpuFunctions.Function("glRasterPos4iv");
	glRasterPos4s = (pglRasterPos4s*)_GpuFunctions.Function("glRasterPos4s");
	glRasterPos4sv = (pglRasterPos4sv*)_GpuFunctions.Function("glRasterPos4sv");
	glReadBuffer = (pglReadBuffer*)_GpuFunctions.Function("glReadBuffer");
	glReadPixels = (pglReadPixels*)_GpuFunctions.Function("glReadPixels");
	glRectd = (pglRectd*)_GpuFunctions.Function("glRectd");
	glRectdv = (pglRectdv*)_GpuFunctions.Function("glRectdv");
	glRectf = (pglRectf*)_GpuFunctions.Function("glRectf");
	glRectfv = (pglRectfv*)_GpuFunctions.Function("glRectfv");
	glRecti = (pglRecti*)_GpuFunctions.Function("glRecti");
	glRectiv = (pglRectiv*)_GpuFunctions.Function("glRectiv");
	glRects = (pglRects*)_GpuFunctions.Function("glRects");
	glRectsv = (pglRectsv*)_GpuFunctions.Function("glRectsv");
	glRenderMode = (pglRenderMode*)_GpuFunctions.Function("glRenderMode");
	glRotated = (pglRotated*)_GpuFunctions.Function("glRotated");
	glRotatef = (pglRotatef*)_GpuFunctions.Function("glRotatef");
	glScaled = (pglScaled*)_GpuFunctions.Function("glScaled");
	glScalef = (pglScalef*)_GpuFunctions.Function("glScalef");
	glScissor = (pglScissor*)_GpuFunctions.Function("glScissor");
	glSelectBuffer = (pglSelectBuffer*)_GpuFunctions.Function("glSelectBuffer");
	glShadeModel = (pglShadeModel*)_GpuFunctions.Function("glShadeModel");
	glStencilFunc = (pglStencilFunc*)_GpuFunctions.Function("glStencilFunc");
	glStencilMask = (pglStencilMask*)_GpuFunctions.Function("glStencilMask");
	glStencilOp = (pglStencilOp*)_GpuFunctions.Function("glStencilOp");
	glTexCoord1d = (pglTexCoord1d*)_GpuFunctions.Function("glTexCoord1d");
	glTexCoord1dv = (pglTexCoord1dv*)_GpuFunctions.Function("glTexCoord1dv");
	glTexCoord1f = (pglTexCoord1f*)_GpuFunctions.Function("glTexCoord1f");
	glTexCoord1fv = (pglTexCoord1fv*)_GpuFunctions.Function("glTexCoord1fv");
	glTexCoord1i = (pglTexCoord1i*)_GpuFunctions.Function("glTexCoord1i");
	glTexCoord1iv = (pglTexCoord1iv*)_GpuFunctions.Function("glTexCoord1iv");
	glTexCoord1s = (pglTexCoord1s*)_GpuFunctions.Function("glTexCoord1s");
	glTexCoord1sv = (pglTexCoord1sv*)_GpuFunctions.Function("glTexCoord1sv");
	glTexCoord2d = (pglTexCoord2d*)_GpuFunctions.Function("glTexCoord2d");
	glTexCoord2dv = (pglTexCoord2dv*)_GpuFunctions.Function("glTexCoord2dv");
	glTexCoord2f = (pglTexCoord2f*)_GpuFunctions.Function("glTexCoord2f");
	glTexCoord2fv = (pglTexCoord2fv*)_GpuFunctions.Function("glTexCoord2fv");
	glTexCoord2i = (pglTexCoord2i*)_GpuFunctions.Function("glTexCoord2i");
	glTexCoord2iv = (pglTexCoord2iv*)_GpuFunctions.Function("glTexCoord2iv");
	glTexCoord2s = (pglTexCoord2s*)_GpuFunctions.Function("glTexCoord2s");
	glTexCoord2sv = (pglTexCoord2sv*)_GpuFunctions.Function("glTexCoord2sv");
	glTexCoord3d = (pglTexCoord3d*)_GpuFunctions.Function("glTexCoord3d");
	glTexCoord3dv = (pglTexCoord3dv*)_GpuFunctions.Function("glTexCoord3dv");
	glTexCoord3f = (pglTexCoord3f*)_GpuFunctions.Function("glTexCoord3f");
	glTexCoord3fv = (pglTexCoord3fv*)_GpuFunctions.Function("glTexCoord3fv");
	glTexCoord3i = (pglTexCoord3i*)_GpuFunctions.Function("glTexCoord3i");
	glTexCoord3iv = (pglTexCoord3iv*)_GpuFunctions.Function("glTexCoord3iv");
	glTexCoord3s = (pglTexCoord3s*)_GpuFunctions.Function("glTexCoord3s");
	glTexCoord3sv = (pglTexCoord3sv*)_GpuFunctions.Function("glTexCoord3sv");
	glTexCoord4d = (pglTexCoord4d*)_GpuFunctions.Function("glTexCoord4d");
	glTexCoord4dv = (pglTexCoord4dv*)_GpuFunctions.Function("glTexCoord4dv");
	glTexCoord4f = (pglTexCoord4f*)_GpuFunctions.Function("glTexCoord4f");
	glTexCoord4fv = (pglTexCoord4fv*)_GpuFunctions.Function("glTexCoord4fv");
	glTexCoord4i = (pglTexCoord4i*)_GpuFunctions.Function("glTexCoord4i");
	glTexCoord4iv = (pglTexCoord4iv*)_GpuFunctions.Function("glTexCoord4iv");
	glTexCoord4s = (pglTexCoord4s*)_GpuFunctions.Function("glTexCoord4s");
	glTexCoord4sv = (pglTexCoord4sv*)_GpuFunctions.Function("glTexCoord4sv");
	glTexCoordPointer = (pglTexCoordPointer*)_GpuFunctions.Function("glTexCoordPointer");
	glTexEnvf = (pglTexEnvf*)_GpuFunctions.Function("glTexEnvf");
	glTexEnvfv = (pglTexEnvfv*)_GpuFunctions.Function("glTexEnvfv");
	glTexEnvi = (pglTexEnvi*)_GpuFunctions.Function("glTexEnvi");
	glTexEnviv = (pglTexEnviv*)_GpuFunctions.Function("glTexEnviv");
	glTexGend = (pglTexGend*)_GpuFunctions.Function("glTexGend");
	glTexGendv = (pglTexGendv*)_GpuFunctions.Function("glTexGendv");
	glTexGenf = (pglTexGenf*)_GpuFunctions.Function("glTexGenf");
	glTexGenfv = (pglTexGenfv*)_GpuFunctions.Function("glTexGenfv");
	glTexGeni = (pglTexGeni*)_GpuFunctions.Function("glTexGeni");
	glTexGeniv = (pglTexGeniv*)_GpuFunctions.Function("glTexGeniv");
	glTexImage1D = (pglTexImage1D*)_GpuFunctions.Function("glTexImage1D");
	glTexImage2D = (pglTexImage2D*)_GpuFunctions.Function("glTexImage2D");
	glTexParameterf = (pglTexParameterf*)_GpuFunctions.Function("glTexParameterf");
	glTexParameterfv = (pglTexParameterfv*)_GpuFunctions.Function("glTexParameterfv");
	glTexParameteri = (pglTexParameteri*)_GpuFunctions.Function("glTexParameteri");
	glTexParameteriv = (pglTexParameteriv*)_GpuFunctions.Function("glTexParameteriv");
	glTexSubImage1D = (pglTexSubImage1D*)_GpuFunctions.Function("glTexSubImage1D");
	glTexSubImage2D = (pglTexSubImage2D*)_GpuFunctions.Function("glTexSubImage2D");
	glTranslated = (pglTranslated*)_GpuFunctions.Function("glTranslated");
	glTranslatef = (pglTranslatef*)_GpuFunctions.Function("glTranslatef");
	glVertex2d = (pglVertex2d*)_GpuFunctions.Function("glVertex2d");
	glVertex2dv = (pglVertex2dv*)_GpuFunctions.Function("glVertex2dv");
	glVertex2f = (pglVertex2f*)_GpuFunctions.Function("glVertex2f");
	glVertex2fv = (pglVertex2fv*)_GpuFunctions.Function("glVertex2fv");
	glVertex2i = (pglVertex2i*)_GpuFunctions.Function("glVertex2i");
	glVertex2iv = (pglVertex2iv*)_GpuFunctions.Function("glVertex2iv");
	glVertex2s = (pglVertex2s*)_GpuFunctions.Function("glVertex2s");
	glVertex2sv = (pglVertex2sv*)_GpuFunctions.Function("glVertex2sv");
	glVertex3d = (pglVertex3d*)_GpuFunctions.Function("glVertex3d");
	glVertex3dv = (pglVertex3dv*)_GpuFunctions.Function("glVertex3dv");
	glVertex3f = (pglVertex3f*)_GpuFunctions.Function("glVertex3f");
	glVertex3fv = (pglVertex3fv*)_GpuFunctions.Function("glVertex3fv");
	glVertex3i = (pglVertex3i*)_GpuFunctions.Function("glVertex3i");
	glVertex3iv = (pglVertex3iv*)_GpuFunctions.Function("glVertex3iv");
	glVertex3s = (pglVertex3s*)_GpuFunctions.Function("glVertex3s");
	glVertex3sv = (pglVertex3sv*)_GpuFunctions.Function("glVertex3sv");
	glVertex4d = (pglVertex4d*)_GpuFunctions.Function("glVertex4d");
	glVertex4dv = (pglVertex4dv*)_GpuFunctions.Function("glVertex4dv");
	glVertex4f = (pglVertex4f*)_GpuFunctions.Function("glVertex4f");
	glVertex4fv = (pglVertex4fv*)_GpuFunctions.Function("glVertex4fv");
	glVertex4i = (pglVertex4i*)_GpuFunctions.Function("glVertex4i");
	glVertex4iv = (pglVertex4iv*)_GpuFunctions.Function("glVertex4iv");
	glVertex4s = (pglVertex4s*)_GpuFunctions.Function("glVertex4s");
	glVertex4sv = (pglVertex4sv*)_GpuFunctions.Function("glVertex4sv");
	glViewport = (pglViewport*)_GpuFunctions.Function("glViewport");
}

void LDL::OpenGLLoader::Init_1_1()
{
	glVertexPointer = (pglVertexPointer*)_GpuFunctions.Function("glVertexPointer");
}