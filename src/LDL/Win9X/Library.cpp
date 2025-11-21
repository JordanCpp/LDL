// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Format.hpp>
#include <LDL/Win9X/Library.hpp>

LDL_Library::LDL_Library(const char* path) :
    _module(NULL)
{
    _module = LoadLibrary(path);

    if (_module == NULL)
    {
        LDL_Formatter formatter;
        LDL_ASSERT_DETAIL(_module != NULL, formatter.Format("LoadLibrary failed: %s", path));
    }
}

LDL_Library::~LDL_Library()
{
    LDL_ASSERT(_module != NULL);

    FreeLibrary(_module);
}

VoidFuncPtr LDL_Library::Function(const char* name)
{
    VoidFuncPtr result = (VoidFuncPtr)GetProcAddress(_module, name);

    if (result == NULL)
    {
        LDL_Formatter formatter;
        LDL_ASSERT_DETAIL(_module != NULL, formatter.Format("GetProcAddress failed: %s", name));
    }

    return result;
}

LDL_ILibrary* LDL_CreateLibrary(const char* name)
{
    return new LDL_Library(name);
}
