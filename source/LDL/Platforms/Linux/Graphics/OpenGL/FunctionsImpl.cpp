// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "FunctionsImpl.hpp"
#include "../GLX.hpp"
#include <stdexcept>

using namespace LDL;

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const char* path) :
    _Library(path)
{
}

LDL::VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    LDL::VoidFuncPtr result = glXGetProcAddress((const GLubyte*)name);

    if (result == NULL)
        throw std::runtime_error("glXGetProcAddress failes: " + std::string(name));

    return result;
}