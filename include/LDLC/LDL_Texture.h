#ifndef LDL_Texture_h
#define LDL_Texture_h

#include <LDLC/LDL_RenderContext.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Texture LDL_Texture;

LDL_EXPORT LDL_Texture* LDL_TextureNew(LDL_RenderContext* renderContext, size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel);
LDL_EXPORT void LDL_TextureFree(LDL_Texture* render);
LDL_EXPORT size_t LDL_TextureGetSizeX(LDL_Texture* render);
LDL_EXPORT size_t LDL_TextureGetSizeY(LDL_Texture* render);

#ifdef __cplusplus
}
#endif

#endif