// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Types_hpp
#define LDL_Types_hpp

#include <limits.h>
#include <stddef.h>

#if (_MSC_VER >= 1900)
    #include <stdbool.h>
#else
    #if (_MSC_VER <= 1200) && (!__cplusplus)
        #define bool  char
        #define true  1
        #define false 0
    #endif
#endif

#if defined(__TURBOC__)
    #define bool  char
    #define true  1
    #define false 0
#endif

#if (_MSC_VER >= 1900 || __GNUC__)
    #include <stdint.h>
#else
    typedef signed char     int8_t;
    typedef unsigned char   uint8_t;

    typedef signed short    int16_t;
    typedef unsigned short  uint16_t;

    typedef signed int      int32_t;
    typedef unsigned int    uint32_t;

    typedef signed int      int64_t;
    typedef unsigned int    uint64_t;

    typedef signed int      intptr_t;
    typedef unsigned int    uintptr_t;

    typedef signed int      intmax_t;
    typedef signed int      uintmax_t;
#endif

#endif    
