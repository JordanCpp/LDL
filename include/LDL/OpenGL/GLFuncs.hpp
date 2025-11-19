// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLFuncs_hpp
#define LDL_GLFuncs_hpp

#include <LDL/Library.hpp>

class OpenGLFunctionsImpl;

class LDL_LIBRARY OpenGLFunctions
{
public:
	OpenGLFunctions();
	VoidFuncPtr Function(const char* name);

private:
	OpenGLFunctionsImpl* _FunctionsImpl;
};

#endif
