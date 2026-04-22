
#ifndef LDL_Library_H
#define LDL_Library_H

#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Library LDL_Library;

LDL_LIBRARY LDL_Library* LDL_LibraryNew(LDL_Result* result);
LDL_LIBRARY void LDL_LibraryFree(LDL_Library* library);
LDL_LIBRARY bool LDL_LibraryOpen(LDL_Library* library, const char* path);
LDL_LIBRARY void LDL_LibraryClose(LDL_Library* library);
LDL_LIBRARY LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library, const char* name);

#ifdef __cplusplus
}
#endif 

#endif
