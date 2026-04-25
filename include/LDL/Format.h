/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_Format_H
#define LDL_Format_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Formatter LDL_Formatter;

LDL_LIBRARY void LDL_FormatterClear(LDL_Formatter* formatter);
LDL_LIBRARY LDL_Formatter* LDL_FormatterNew();
LDL_LIBRARY void LDL_FormatterFree(LDL_Formatter* formatter);
LDL_LIBRARY char* LDL_FormatterGetData(LDL_Formatter* formatter);
LDL_LIBRARY const char* LDL_FormatterVFormat(LDL_Formatter* formatter, const char* format, va_list args);
LDL_LIBRARY const char* LDL_FormatterFormat(LDL_Formatter* formatter, const char* format, ...);

#ifdef __cplusplus
}
#endif 

#endif
