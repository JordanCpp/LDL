// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Linux_OpenGL_OpenGLFunctionsImpl_hpp
#define LDL_Platforms_Windows_Linux_OpenGL_OpenGLFunctionsImpl_hpp

#include <LDL/Core/Library.hpp>

namespace LDL
{
	class OpenGLFunctionsImpl
	{
	public:
		OpenGLFunctionsImpl(const char *path);
		LDL::VoidFuncPtr Function(const char *name);

	private:
		LDL::Library _Library;
	};
}

#endif
