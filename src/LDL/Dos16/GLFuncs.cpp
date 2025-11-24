// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Dos16/GLFuncs.hpp>

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const char* path)
{
}

LDL_VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    return NULL;
}

bool OpenGLFunctionsImpl::IsValid(LDL_VoidFuncPtr ptr)
{
    return true;
}
