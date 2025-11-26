// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <dlfcn.h>
#include <LDL/Types.hpp>
#include <LDL/Linux/Library.hpp>

LDL_Library::LDL_Library(const char *path)
{
    _Library = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
}

LDL_Library::~LDL_Library()
{
    if (_Library != NULL)
    {
        dlclose(_Library);
    }
}

LDL_VoidFuncPtr LDL_Library::Function(const char *name)
{
    return (LDL_VoidFuncPtr)dlsym(_Library, name);
}

LDL_ILibrary* LDL_CreateLibrary(const char* name)
{
    return new LDL_Library(name);
}
