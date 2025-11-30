// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Linux_GLFuncs_hpp
#define LDL_Linux_GLFuncs_hpp

#include <LDL/Library.hpp>

class OpenGLFunctionsImpl
{
public:
	OpenGLFunctionsImpl(LDL_Result& result, const char* path);
	LDL_VoidFuncPtr Function(const char* name);
private:
	LDL_ILibrary* _Library;
};

#endif
