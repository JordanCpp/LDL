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

#include <LDL/OpenGL/GL4_4.h>

PFNGLBUFFERSTORAGEPROC glBufferStorage = NULL;
PFNGLCLEARTEXIMAGEPROC glClearTexImage = NULL;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = NULL;
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = NULL;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = NULL;
PFNGLBINDTEXTURESPROC glBindTextures = NULL;
PFNGLBINDSAMPLERSPROC glBindSamplers = NULL;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = NULL;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = NULL;
