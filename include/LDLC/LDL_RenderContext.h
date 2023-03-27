#ifndef LDL_RenderContext_h
#define LDL_RenderContext_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_RenderContext LDL_RenderContext;

LDL_EXPORT LDL_RenderContext* LDL_RenderContextNew();
LDL_EXPORT void LDL_RenderContextFree(LDL_RenderContext* renderContext);
LDL_EXPORT void LDL_RenderContextGetContext(LDL_RenderContext* renderContext);

#ifdef __cplusplus
}
#endif

#endif