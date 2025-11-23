// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdexcept>
#include <LDL/Linux/GLX.hpp>
#include <LDL/Linux/GLFuncs.hpp>

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const char* path) :
    _Library(NULL)
{
    _Library = LDL_CreateLibrary(path);
}

VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    VoidFuncPtr result = glXGetProcAddress((const GLubyte*)name);

    if (result == NULL)
    {
        throw std::runtime_error("glXGetProcAddress failes: " + std::string(name));
    }

    return result;
}
