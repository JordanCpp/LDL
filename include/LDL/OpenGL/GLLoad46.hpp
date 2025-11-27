// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLLoad46_hpp
#define LDL_GLLoad46_hpp

#include <LDL/OpenGL/GLFuncs.hpp>

class LDL_LIBRARY LDL_OpenGLLoader_4_6
{
public:
	LDL_OpenGLLoader_4_6(LDL_Result& result);
	~LDL_OpenGLLoader_4_6();
private:
	LDL_Result&         _result;
	LDL_OpenGLFunctions _functions;
};

#endif   
