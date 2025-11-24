// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_WinNT_GLFuncs_hpp
#define LDL_WinNT_GLFuncs_hpp

#include <LDL/Types.hpp>
#include <LDL/Library.hpp>
#include <LDL/WinNT/Windows.hpp>

class LDL_LIBRARY OpenGLFunctionsImpl
{
public:
	OpenGLFunctionsImpl(const char* path);
	LDL_VoidFuncPtr Function(const char* name);
private:
	bool IsValid(LDL_VoidFuncPtr ptr);
	LDL_ILibrary* _library;
};

#endif
