// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/OpenGL/OpenGL_Functions.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Graphics/OpenGLFunctionsImpl.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Graphics/OpenGL/FunctionsImpl.hpp>
#endif


using namespace LDL;

OpenGLFunctions::OpenGLFunctions() :
    _FunctionsImpl(new OpenGLFunctionsImpl("opengl32"))
{
}

LDL::VoidFuncPtr OpenGLFunctions::Function(const char* name)
{
    return _FunctionsImpl->Function(name);
}
