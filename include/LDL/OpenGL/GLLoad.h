
#ifndef LDL_OpenGL_GLLoad_H
#define LDL_OpenGL_GLLoad_H

#include <LDL/Config.h>
#include <LDL/Types.h>
#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_OpenGLLoader LDL_OpenGLLoader;

LDL_LIBRARY LDL_OpenGLLoader* LDL_OpenGLLoaderNew(LDL_Result* result, size_t major, size_t minor);
LDL_LIBRARY void LDL_OpenGLLoaderFree(LDL_OpenGLLoader* loader);

#ifdef __cplusplus
}
#endif

#endif
