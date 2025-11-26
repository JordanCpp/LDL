// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Null/GLFuncs.hpp>

OpenGLFunctionsImpl::OpenGLFunctionsImpl(LDL_Result& result, const char* path) :
    _result(result)
{
}

LDL_VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    return NULL;
}
