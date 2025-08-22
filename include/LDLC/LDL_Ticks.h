// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Ticks_h
#define LDL_Ticks_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

LDL_LIBRARY size_t LDL_Ticks();
LDL_LIBRARY void LDL_Delay(size_t count);

#ifdef __cplusplus
}
#endif

#endif
