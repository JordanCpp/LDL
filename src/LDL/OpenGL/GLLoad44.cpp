// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Format.hpp>
#include <LDL/OpenGL/GL4_4.hpp>
#include <LDL/OpenGL/GLLoad44.hpp>

LDL_OpenGLLoader_4_4::LDL_OpenGLLoader_4_4(LDL_Result& result) :
	_result(result),
	_functions(_result)
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

LDL_OpenGLLoader_4_4::~LDL_OpenGLLoader_4_4()
{
}
