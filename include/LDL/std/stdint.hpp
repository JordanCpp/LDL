// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_stdint_hpp
#define LDL_std_stdint_hpp

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
