// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Convert_h
#define LDL_Convert_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Convert LDL_Convert;

LDL_LIBRARY LDL_Convert* LDL_ConvertNew();
LDL_LIBRARY void LDL_ConvertFree(LDL_Convert* numberToString);
LDL_LIBRARY const char* LDL_ConvertToString(LDL_Convert* numberToString, intmax_t num);

#ifdef __cplusplus
}
#endif

#endif
