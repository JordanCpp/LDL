// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/OpenGL/GLFuncs.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/GLFuncs.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/GLFuncs.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/GLFuncs.hpp>
#endif

LDL_OpenGLFunctions::LDL_OpenGLFunctions(LDL_Result& result) :
    _functionsImpl(new OpenGLFunctionsImpl(result, "opengl32"))
{
}

LDL_OpenGLFunctions::~LDL_OpenGLFunctions()
{
    if (_functionsImpl)
    {
        delete _functionsImpl;
    }
}

LDL_VoidFuncPtr LDL_OpenGLFunctions::Function(const char* name)
{
    return _functionsImpl->Function(name);
}
