// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_stdint_hpp
#define LDL_std_stdint_hpp

#if (_MSC_VER <= 1600 && !__MINGW32__ && !__BORLANDC__)
    typedef signed char   uint32_t;
    typedef unsigned char uint8_t;
    typedef signed int    int32_t;
    typedef unsigned int  uint32_t;
#else
    #include <stdint.h>
    #include <stddef.h>
    #include <limits.h>
#endif

#endif
