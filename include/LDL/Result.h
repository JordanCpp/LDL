
#ifndef LDL_Result_H
#define LDL_Result_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Result LDL_Result;

LDL_LIBRARY LDL_Result* LDL_ResultNew();
LDL_LIBRARY void LDL_ResultFree(LDL_Result* result);
LDL_LIBRARY bool LDL_ResultIsOk(LDL_Result* result);
LDL_LIBRARY bool LDL_ResultIsFail(LDL_Result* result);
LDL_LIBRARY const char* LDL_ResultGetMessage(LDL_Result* result);
LDL_LIBRARY void LDL_ResultAddMessage(LDL_Result* result, const char* format, ...);

#ifdef __cplusplus
}
#endif 

#endif
