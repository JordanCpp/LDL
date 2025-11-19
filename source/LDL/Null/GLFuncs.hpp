// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Graphics_OpenGL_OpenGLFunctionsImpl_hpp
#define LDL_Platforms_WinNT_Graphics_OpenGL_OpenGLFunctionsImpl_hpp

#include <LDL/Types.hpp>
#include <LDL/Library.hpp>
#include <LDL/WinNT/Windows.hpp>

namespace LDL
{
	class LDL_LIBRARY OpenGLFunctionsImpl
	{
	public:
		OpenGLFunctionsImpl(const char *path);
		VoidFuncPtr Function(const char *name);
	private:
		bool IsValid(LDL::VoidFuncPtr ptr);
		ILibrary* _library;
	};

}

#endif
