// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_OpenGL_OpenGL_Functions_hpp
#define LDL_APIs_OpenGL_OpenGL_Functions_hpp

#include <LDL/Core/Library.hpp>

namespace LDL
{
	class OpenGLFunctionsImpl;

	class LDL_LIBRARY OpenGLFunctions
	{
	public:
		OpenGLFunctions();
		LDL::VoidFuncPtr Function(const char *name);

	private:
		OpenGLFunctionsImpl *_FunctionsImpl;
	};
}

#endif
