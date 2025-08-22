// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Core/LibraryImpl.hpp>

using namespace LDL;
using namespace LDL::Core;

LibraryImpl::LibraryImpl(const std::string& path) :
    _module(NULL)
{
    _module = LoadLibrary(path.c_str());
    LDL_ASSERT_DETAIL(_module != NULL, "LoadLibrary failed: " + path);
}

LibraryImpl::~LibraryImpl()
{
    LDL_ASSERT(_module != NULL);

    FreeLibrary(_module);
}

VoidFuncPtr LibraryImpl::Function(const std::string& name)
{
    VoidFuncPtr result = (VoidFuncPtr)GetProcAddress(_module, name.c_str());
    LDL_ASSERT_DETAIL(result != NULL, "GetProcAddress failed: " + name);

    return result;
}
