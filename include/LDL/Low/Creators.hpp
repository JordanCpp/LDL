#ifndef LDL_Low_Creators_hpp
#define LDL_Low_Creators_hpp

#include <LDL/Low/Abstract.hpp>

LDL_LIBRARY LDL_ITexture* LDL_TextureCreate(LDL_IRenderContext* renderContext, const LDL_Point2u& size, uint8_t* pixels, uint8_t bpp);
LDL_LIBRARY void LDL_Destroy(LDL_ITexture* texture);

LDL_LIBRARY LDL_IOpenGLLibrary* LDL_OpenGLLibraryCreate();
LDL_LIBRARY void LDL_Destroy(LDL_IOpenGLLibrary* library);

LDL_LIBRARY LDL_ILibrary* LDL_LibraryCreate(const char* path);
LDL_LIBRARY void LDL_Destroy(LDL_ILibrary* library);

LDL_LIBRARY LDL_ISurface* LDL_SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t bpp);
LDL_LIBRARY LDL_ISurface* LDL_SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp);
LDL_LIBRARY void LDL_Destroy(LDL_ISurface* surface);

LDL_LIBRARY LDL_IRender* LDL_RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window);
LDL_LIBRARY void LDL_Destroy(LDL_IRender* render);

LDL_LIBRARY LDL_IWindow* LDL_WindowCreate(LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
LDL_LIBRARY void LDL_Destroy(LDL_IWindow* window);

LDL_LIBRARY LDL_IRenderContext* LDL_RenderContextCreate(size_t mode);
LDL_LIBRARY void LDL_Destroy(LDL_IRenderContext* context);

#endif
