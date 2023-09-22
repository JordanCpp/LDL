#ifndef LDL_Low_Creators_hpp
#define LDL_Low_Creators_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/EHandler.hpp>

LDL_ILibrary* LibraryCreate(const char* path);
void Destroy(LDL_ILibrary* library);

LDL_ISurface* SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t bpp);
LDL_ISurface* SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp);
void Destroy(LDL_ISurface* surface);

LDL_IRender* RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window);
void Destroy(LDL_IRender* render);

LDL_IWindow* WindowCreate(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
void Destroy(LDL_IWindow* window);

LDL_IRenderContext* RenderContextCreate(size_t mode);
void Destroy(LDL_IRenderContext* context);

#endif
