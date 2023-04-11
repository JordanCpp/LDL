#ifndef LDL_NumberToString_h
#define LDL_NumberToString_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_NumberToString LDL_NumberToString;

LDL_EXPORT LDL_NumberToString* LDL_NumberToStringNew();
LDL_EXPORT void LDL_NumberToStringFree(LDL_NumberToString* numberToString);
LDL_EXPORT const char* LDL_NumberToStringConvertInt(LDL_NumberToString* numberToString, intmax_t num);

#ifdef __cplusplus
}
#endif

#endif