#ifndef LDL_OpenGLLoader_h
#define LDL_OpenGLLoader_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_OpenGLLoader LDL_OpenGLLoader;

LDL_EXPORT LDL_OpenGLLoader* LDL_OpenGLLoaderNew(size_t major, size_t minor);
LDL_EXPORT void LDL_OpenGLLoaderFree(LDL_OpenGLLoader* openGLLoader);

#ifdef __cplusplus
}
#endif

#endif