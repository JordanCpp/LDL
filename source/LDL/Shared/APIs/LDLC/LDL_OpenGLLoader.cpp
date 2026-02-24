// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_OpenGLLoader.h>
#include <LDL/APIs/OpenGL/OpenGLLoader.hpp>

using namespace LDL;

struct LDL_OpenGLLoader
{
	OpenGLLoader _openGLLoader;
	LDL_OpenGLLoader(size_t major, size_t minor);
};

LDL_OpenGLLoader::LDL_OpenGLLoader(size_t major, size_t minor) :
	_openGLLoader(major, minor)
{
}

LDL_OpenGLLoader * LDL_OpenGLLoaderNew(size_t major, size_t minor)
{
	LDL_OpenGLLoader* p = new LDL_OpenGLLoader(major, minor);

	return p;
}

void LDL_OpenGLLoaderFree(LDL_OpenGLLoader * openGLLoader)
{
	delete openGLLoader;
}
