// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Dos16_GLFuncs_hpp
#define LDL_Dos16_GLFuncs_hpp

#include <LDL/Types.hpp>
#include <LDL/Library.hpp>

class LDL_LIBRARY OpenGLFunctionsImpl
{
public:
	OpenGLFunctionsImpl(const char* path);
	VoidFuncPtr Function(const char* name);
private:
	bool IsValid(VoidFuncPtr ptr);
};

#endif
