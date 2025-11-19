// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/WinNT/Library.hpp>

LDL_Library::LDL_Library(const char* path) :
    _module(NULL)
{
    _module = LoadLibrary(path);

    _assert = "LoadLibrary failed: ";
    _assert += path;

    LDL_ASSERT_DETAIL(_module != NULL, _assert.c_str());
}

LDL_Library::~LDL_Library()
{
    LDL_ASSERT(_module != NULL);

    FreeLibrary(_module);
}

VoidFuncPtr LDL_Library::Function(const char* name)
{
    VoidFuncPtr result = (VoidFuncPtr)GetProcAddress(_module, name);

    _assert = "GetProcAddress failed: ";
    _assert += name;

    LDL_ASSERT_DETAIL(result != NULL, _assert.c_str());

    return result;
}

LDL_ILibrary* CreateLibraryImpl(const char* name)
{
    return new LDL_Library(name);
}
