// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_New_hpp
#define LDL_Core_New_hpp

#if (_MSC_VER < 1600 && !__GNUC__)
    #include <LDL/std/stddef.hpp>

inline void* operator new(size_t bytes, void* ptr)
{
    return ptr;
}

inline void operator delete(void* ptr, void* place)
{
}

#else
    #include <new>
#endif

#endif
