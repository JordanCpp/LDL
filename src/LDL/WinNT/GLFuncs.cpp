// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/WinNT/GLFuncs.hpp>

OpenGLFunctionsImpl::OpenGLFunctionsImpl(LDL_Result& result, const char* path) :
    _library(NULL)
{
    _library = LDL_CreateLibrary(result);

    _library->Open(path);
}

LDL_VoidFuncPtr OpenGLFunctionsImpl::Function(const char* name)
{
    LDL_VoidFuncPtr result = (LDL_VoidFuncPtr)wglGetProcAddress(name);

    if (IsValid(result))
    {
        result = _library->Function(name);
    }

    return result;
}

bool OpenGLFunctionsImpl::IsValid(LDL_VoidFuncPtr ptr)
{
    return (ptr == 0 || (ptr == (LDL_VoidFuncPtr)0x1) || (ptr == (LDL_VoidFuncPtr)0x2) || (ptr == (LDL_VoidFuncPtr)0x3) || (ptr == (LDL_VoidFuncPtr)-1));
}
