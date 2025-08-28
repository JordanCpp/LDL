// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Windows/Graphics/OpenGLFunctionsImpl.hpp>

using namespace LDL;

OpenGLFunctionsImpl::OpenGLFunctionsImpl(const char* path) :
    _library(path)
{
}

VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    VoidFuncPtr result = (VoidFuncPtr)wglGetProcAddress(name);

    if (IsValid(result))
    {
        result = _library.Function(name);
    }

    return result;
}

bool OpenGLFunctionsImpl::IsValid(VoidFuncPtr ptr)
{
    return (ptr == 0 || (ptr == (VoidFuncPtr)0x1) || (ptr == (VoidFuncPtr)0x2) || (ptr == (VoidFuncPtr)0x3) || (ptr == (VoidFuncPtr)-1));
}
