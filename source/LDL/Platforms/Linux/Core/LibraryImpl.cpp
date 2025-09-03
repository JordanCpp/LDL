// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <dlfcn.h>
#include <LDL/std/stddef.hpp>
#include <LDL/Platforms/Linux/Core/LibraryImpl.hpp>

using namespace LDL;

LibraryImpl::LibraryImpl(const char *path)
{
    _Library = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
}

LibraryImpl::~LibraryImpl()
{
    if (_Library != NULL)
    {
        dlclose(_Library);
    }
}

LDL::VoidFuncPtr LibraryImpl::Function(const char *name)
{
    return (LDL::VoidFuncPtr)dlsym(_Library, name);
}
