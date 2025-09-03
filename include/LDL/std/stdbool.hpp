// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_stdbool_hpp
#define LDL_std_stdbool_hpp

#if (_MSC_VER < 1600 && !__GNUC__)
    #include <Windows.h>
    #define bool  BOOL
    #define true  TRUE
    #define false FALSE
#endif

#endif
