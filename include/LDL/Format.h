
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
LDL_LIBRARY const char* LDL_FormatterFormat(LDL_Formatter* formatter, const char* format, ...);

#ifdef __cplusplus
}
#endif 

#endif
