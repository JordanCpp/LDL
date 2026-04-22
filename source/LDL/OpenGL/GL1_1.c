/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <LDL/OpenGL/GL1_1.h>

PFNGLDRAWARRAYSPROC glDrawArrays = NULL;
PFNGLDRAWELEMENTSPROC glDrawElements = NULL;
PFNGLGETPOINTERVPROC glGetPointerv = NULL;
PFNGLPOLYGONOFFSETPROC glPolygonOffset = NULL;
PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D = NULL;
PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D = NULL;
PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D = NULL;
PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D = NULL;
PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D = NULL;
PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D = NULL;
PFNGLBINDTEXTUREPROC glBindTexture = NULL;
PFNGLDELETETEXTURESPROC glDeleteTextures = NULL;
PFNGLGENTEXTURESPROC glGenTextures = NULL;
PFNGLISTEXTUREPROC glIsTexture = NULL;
PFNGLARRAYELEMENTPROC glArrayElement = NULL;
PFNGLCOLORPOINTERPROC glColorPointer = NULL;
PFNGLDISABLECLIENTSTATEPROC glDisableClientState = NULL;
PFNGLEDGEFLAGPOINTERPROC glEdgeFlagPointer = NULL;
PFNGLENABLECLIENTSTATEPROC glEnableClientState = NULL;
PFNGLINDEXPOINTERPROC glIndexPointer = NULL;
PFNGLINTERLEAVEDARRAYSPROC glInterleavedArrays = NULL;
PFNGLNORMALPOINTERPROC glNormalPointer = NULL;
PFNGLTEXCOORDPOINTERPROC glTexCoordPointer = NULL;
PFNGLVERTEXPOINTERPROC glVertexPointer = NULL;
PFNGLARETEXTURESRESIDENTPROC glAreTexturesResident = NULL;
PFNGLPRIORITIZETEXTURESPROC glPrioritizeTextures = NULL;
PFNGLINDEXUBPROC glIndexub = NULL;
PFNGLINDEXUBVPROC glIndexubv = NULL;
PFNGLPOPCLIENTATTRIBPROC glPopClientAttrib = NULL;
PFNGLPUSHCLIENTATTRIBPROC glPushClientAttrib = NULL;
