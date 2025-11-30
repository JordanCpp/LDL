// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/Format.hpp>
#include <LDL/WinNT/Library.hpp>

bool LDL_Library::Open(const char* path)
{
    if (path == NULL || path[0] == '\0')
    {
        _result.Message("Invalid library path: null or empty");
        return false;
    }

    if (_module != NULL)
    {
        _result.Message("Library already loaded");
        return false;
    }

    _module = LoadLibrary(path);

    if (_module == NULL)
    {
        LDL_Formatter formatter;
        _result.Message(formatter.Format("LoadLibrary failed: %s", path));
        return false;
    }

    return true;
}

LDL_Library::LDL_Library(LDL_Result& result) :
    _module(NULL),
    _result(result)
{
}

LDL_Library::~LDL_Library()
{
    if (_module != NULL)
    {
        FreeLibrary(_module);
    }
}

LDL_VoidFuncPtr LDL_Library::Function(const char* name)
{
    LDL_VoidFuncPtr result = NULL;

    if (_module == NULL)
    {
        _result.Message("Library not loaded");
        return NULL;
    }

    if (name == NULL || name[0] == '\0')
    {
        _result.Message("Invalid function name");
        return NULL;
    }

    if (_module)
    {
        result = (LDL_VoidFuncPtr)GetProcAddress(_module, name);

        if (result == NULL)
        {
            LDL_Formatter formatter;
            _result.Message(formatter.Format("GetProcAddress failed: %s", name));
        }
    }

    return result;
}

LDL_ILibrary* LDL_CreateLibrary(LDL_Result& result)
{
    return new LDL_Library(result);
}
