// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Graphics_OpenGL_OpenGLFunctionsImpl_hpp
#define LDL_Platforms_Windows_Graphics_OpenGL_OpenGLFunctionsImpl_hpp

#include <LDL/std/stdbool.hpp>
#include <LDL/Core/Library.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>

namespace LDL
{
	class OpenGLFunctionsImpl
	{
	public:
		OpenGLFunctionsImpl(const char *path);
		VoidFuncPtr Function(const char *name);
	private:
		bool IsValid(LDL::VoidFuncPtr ptr);
		Library _library;
	};

}

#endif
