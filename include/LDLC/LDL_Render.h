#ifndef LDL_Render_h
#define LDL_Render_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_RenderContext.h>
#include <LDLC/LDL_Window.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Texture LDL_Texture;
typedef struct LDL_Render LDL_Render;

LDL_EXPORT LDL_Render* LDL_RenderNew(LDL_RenderContext* renderContext, LDL_Window * window);
LDL_EXPORT void LDL_RenderFree(LDL_Render* render);

LDL_EXPORT void LDL_RenderBegin(LDL_Render* render);
LDL_EXPORT void LDL_RenderEnd(LDL_Render* render);

LDL_EXPORT size_t LDL_RenderGetSizeX(LDL_Render* render);
LDL_EXPORT size_t LDL_RenderGetSizeY(LDL_Render* render);

LDL_EXPORT void LDL_RenderClear(LDL_Render* render);
LDL_EXPORT void LDL_RenderSetColor(LDL_Render* render, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
LDL_EXPORT void LDL_RenderFill(LDL_Render* render, size_t x, size_t y, size_t w, size_t h);
LDL_EXPORT void LDL_RenderLine(LDL_Render* render, size_t x, size_t y, size_t w, size_t h);

LDL_EXPORT void LDL_RenderDrawTexture1(LDL_Render* render, LDL_Texture* texture, size_t x, size_t y);
LDL_EXPORT void LDL_RenderDrawTexture2(LDL_Render* render, LDL_Texture* texture, size_t x, size_t y, size_t w, size_t h);
LDL_EXPORT void LDL_RenderDrawTexture3(LDL_Render* render, LDL_Texture* texture, size_t dx, size_t dy, size_t x, size_t y, size_t w, size_t h);

#ifdef __cplusplus
}
#endif

#endif