#ifndef LDL_Surface_h
#define LDL_Surface_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Surface LDL_Surface;

LDL_EXPORT void LDL_SurfaceFree(LDL_Surface* surface);
LDL_EXPORT LDL_Surface* LDL_SurfaceNew(size_t w, size_t h, uint8_t bytesPerPixel);
LDL_EXPORT LDL_Surface* LDL_SurfaceNewFromBytes(size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel);
LDL_EXPORT LDL_Surface* LDL_SurfaceNewCapacity(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t bytesPerPixel);
LDL_EXPORT LDL_Surface* LDL_SurfaceNewCapacityFromBytes(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t* pixels, uint8_t bytesPerPixel);
LDL_EXPORT size_t  LDL_SurfaceGetSizeX(LDL_Surface* surface);
LDL_EXPORT size_t  LDL_SurfaceGetSizeY(LDL_Surface* surface);
LDL_EXPORT size_t  LDL_SurfaceGetCapacitySizeX(LDL_Surface* surface);
LDL_EXPORT size_t  LDL_SurfaceGetCapacitySizeY(LDL_Surface* surface);
LDL_EXPORT void LDL_SurfaceResize(LDL_Surface* surface, size_t w, size_t h);
LDL_EXPORT void LDL_SurfaceClear(LDL_Surface* surface);
LDL_EXPORT uint8_t LDL_SurfaceBytesPerPixel(LDL_Surface* surface);
LDL_EXPORT uint8_t* LDL_SurfacePixels(LDL_Surface* surface);

#ifdef __cplusplus
}
#endif

#endif