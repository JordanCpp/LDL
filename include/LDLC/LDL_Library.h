#ifndef LDL_Library_h
#define LDL_Library_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void(*LDL_VoidFuncPtr)(void);

typedef struct LDL_Library LDL_Library;

LDL_LIBRARY LDL_Library* LDL_LibraryNew(const char* path);
LDL_LIBRARY void LDL_LibraryFree(LDL_Library* library);
LDL_LIBRARY LDL_VoidFuncPtr LDL_LibraryFunction(LDL_Library* library, const char* path);

#ifdef __cplusplus
}
#endif

#endif
