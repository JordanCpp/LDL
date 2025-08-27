// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Library.hpp>

#if defined(_WIN32)
    #include <LDL/Platforms/Windows/Core/LibraryImpl.hpp>
#elif defined(__unix__)
    #include <LDL/Platforms/Linux/Core/LibraryImpl.hpp>
#endif

using namespace LDL;

Library::Library(const char* path) :
    _impl(new LibraryImpl(path))
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
