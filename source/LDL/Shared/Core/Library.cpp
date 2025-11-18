// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/New.hpp>
#include <LDL/Core/Library.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/Core/LibraryImpl.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/Core/LibraryImpl.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/Core/LibraryImpl.hpp>
#endif

using namespace LDL;

Library::Library(const char* path) :
    _impl(new(_memory) LibraryImpl(path))
{
}

Library::~Library()
{
    _impl->~LibraryImpl();
}

LDL::VoidFuncPtr Library::Function(const char* name)
{
    return (LDL::VoidFuncPtr)_impl->Function(name);
}
