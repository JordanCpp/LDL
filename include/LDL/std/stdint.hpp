// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_stdint_hpp
#define LDL_std_stdint_hpp

#if (_MSC_VER >= 1900 || __GNUC__)
    #include <stdint.h>

    typedef int8_t   Sint8;
    typedef uint8_t  Uint8;

    typedef int16_t  Sint16;
    typedef uint16_t Uint16;

    typedef int32_t  Sint32;
    typedef uint32_t Uint32;

    typedef int64_t  Sint64;
    typedef uint64_t Uint64;
#else
    typedef signed char    Sint8;
    typedef unsigned char  Uint8;

    typedef signed short   Sint16;
    typedef unsigned short Uint16;

    typedef signed int     Sint32;
    typedef unsigned int   Uint32;

    typedef Sint32         Sint64;
    typedef size_t         Uint64;
#endif

#endif
