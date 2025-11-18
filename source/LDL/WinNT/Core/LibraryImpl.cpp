// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/WinNT/Core/LibraryImpl.hpp>

using namespace LDL;

LibraryImpl::LibraryImpl(const char* path) :
    _module(NULL)
{
    _module = LoadLibrary(path);

    _assert = "LoadLibrary failed: ";
    _assert += path;

    LDL_ASSERT_DETAIL(_module != NULL, _assert.c_str());
}

LibraryImpl::~LibraryImpl()
{
    LDL_ASSERT(_module != NULL);

    FreeLibrary(_module);
}

VoidFuncPtr LibraryImpl::Function(const char* name)
{
    VoidFuncPtr result = (VoidFuncPtr)GetProcAddress(_module, name);

    _assert = "GetProcAddress failed: ";
    _assert += name;

    LDL_ASSERT_DETAIL(result != NULL, _assert.c_str());

    return result;
}
