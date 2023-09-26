#ifndef LDL_Low_Creators_hpp
#define LDL_Low_Creators_hpp

#include <LDL/Low/Abstract.hpp>

LDL_LIBRARY LDL_IOpenGLLibrary* OpenGLLibraryCreate();
LDL_LIBRARY void Destroy(LDL_IOpenGLLibrary* library);

LDL_LIBRARY LDL_ILibrary* LibraryCreate(const char* path);
LDL_LIBRARY void Destroy(LDL_ILibrary* library);

LDL_LIBRARY LDL_ISurface* SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t bpp);
LDL_LIBRARY LDL_ISurface* SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp);
LDL_LIBRARY void Destroy(LDL_ISurface* surface);

LDL_LIBRARY LDL_IRender* RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window);
LDL_LIBRARY void Destroy(LDL_IRender* render);

LDL_LIBRARY LDL_IWindow* WindowCreate(LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
LDL_LIBRARY void Destroy(LDL_IWindow* window);

LDL_LIBRARY LDL_IRenderContext* RenderContextCreate(size_t mode);
LDL_LIBRARY void Destroy(LDL_IRenderContext* context);

#endif
