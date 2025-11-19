// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/OpenGL/GLFuncs.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/GLFuncs.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/Graphics/OpenGLFunctionsImpl.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/Graphics/OpenGL/FunctionsImpl.hpp>
#endif

OpenGLFunctions::OpenGLFunctions() :
    _FunctionsImpl(new OpenGLFunctionsImpl("opengl32"))
{
}

VoidFuncPtr OpenGLFunctions::Function(const char* name)
{
    return _FunctionsImpl->Function(name);
}
