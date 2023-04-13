#ifndef LDL_ImageLoader_h
#define LDL_ImageLoader_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_ImageLoader LDL_ImageLoader;

LDL_EXPORT LDL_ImageLoader* LDL_ImageLoaderNew(void* allocator);
LDL_EXPORT void LDL_ImageLoaderFree(LDL_ImageLoader* ptr);
LDL_EXPORT size_t LDL_ImageLoaderGetSizeX(LDL_ImageLoader* imageLoader);
LDL_EXPORT size_t LDL_ImageLoaderGetSizeY(LDL_ImageLoader* imageLoader);
LDL_EXPORT uint8_t LDL_ImageLoaderGetBytesPerPixel(LDL_ImageLoader* imageLoader);
LDL_EXPORT uint8_t* LDL_ImageLoaderGetPixels(LDL_ImageLoader* imageLoader);
LDL_EXPORT void LDL_ImageLoaderLoadFromFile(LDL_ImageLoader* imageLoader, const char* path);
LDL_EXPORT void LDL_ImageLoaderLoadColorKeyFromFile(LDL_ImageLoader* imageLoader, uint8_t r, uint8_t g, uint8_t b, uint8_t a, const char* path);
LDL_EXPORT void LDL_ImageLoaderLoadFromMemory(LDL_ImageLoader* imageLoader, uint8_t* data, size_t bytes);
LDL_EXPORT void LDL_ImageLoaderLoadColorKeyFromMemory(LDL_ImageLoader* imageLoader, uint8_t r, uint8_t g, uint8_t b, uint8_t a, uint8_t* data, size_t bytes);

#ifdef __cplusplus
}
#endif

#endif