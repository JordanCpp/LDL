// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Null/Library.hpp>

LDL_Library::LDL_Library(const char* path)
{
}

LDL_Library::~LDL_Library()
{
}

LDL_VoidFuncPtr LDL_Library::Function(const char* name)
{
    return NULL;
}

LDL_ILibrary* LDL_CreateLibraryImpl(const char* name)
{
    return NULL;
}
