// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_stdbool_hpp
#define LDL_std_stdbool_hpp

#if (_MSC_VER >= 1900)
    #include <stdbool.h>
#else
    #if (_MSC_VER <= 1200) && (!__cplusplus)
        #define bool  char
        #define true  1
        #define false 0
    #endif
#endif

#endif
