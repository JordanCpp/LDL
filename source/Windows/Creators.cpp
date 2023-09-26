#include <LDL/Low/Creators.hpp>
#include "../Renders/SoftRend.hpp"
#include "GdiRend.hpp"
#include "SoftWin.hpp"
#include "GdiWin.hpp"
#include "RContext.hpp"
#include "GdiSurf.hpp"
#include "Library.hpp"
#include "GLLib.hpp"
#include "../WinGL/GL1Win.hpp"
#include "../Renders/GL1Rend.hpp"
#include "../Renders/GL1Texture.hpp"

LDL_ITexture* LDL_TextureCreate(LDL_IRenderContext* renderContext, const LDL_Point2u& size, uint8_t* pixels, uint8_t bpp)
{
    return new LDL_GL1Texture(renderContext, size, pixels, bpp);
}

void LDL_Destroy(LDL_ITexture* texture)
{
    delete texture;
}

LDL_IOpenGLLibrary* LDL_OpenGLLibraryCreate()
{
    return new LDL_ImpOpenGLLibrary;
}

void LDL_Destroy(LDL_IOpenGLLibrary* library)
{
    delete library;
}

LDL_ILibrary* LDL_LibraryCreate(const char* path)
{
    return new LDL_Library(path);
}

void LDL_Destroy(LDL_ILibrary* library)
{
    delete library;
}

LDL_ISurface* LDL_SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow * window, const LDL_Point2u& size, uint8_t bpp)
{
    size_t renderMode = renderContext->Mode();

    LDL_ISurface* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftwareSurface(size, bpp);
        break;
    case LDL_RenderMode::GDI:
        result = new LDL_GdiSurface(window, size, bpp);
        break;
    default:
        break;
    }

    return result;
}

LDL_ISurface* LDL_SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp)
{
    size_t renderMode = renderContext->Mode();

    LDL_ISurface* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftwareSurface(size, bytes, bpp);
        break;
    case LDL_RenderMode::GDI:
        result = new LDL_GdiSurface(window, size, bytes, bpp);
        break;
    default:
        break;
    }

    return result;
}

void LDL_Destroy(LDL_ISurface* surface)
{
    delete surface;
}

LDL_IRender* LDL_RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window)
{
    size_t renderMode = context->Mode();

    LDL_IRender* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftRender(context, window);
        break;
    case LDL_RenderMode::GDI:
        result = new LDL_GdiRender(context, window);
        break;
    case LDL_RenderMode::OpenGL1:
        result = new LDL_GL1Render(context, window);
        break;
    default:
        break;
    }

    return result;
}

void LDL_Destroy(LDL_IRender* render)
{
	delete render;
}

LDL_IWindow* LDL_WindowCreate(LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode)
{
    size_t renderMode = context->Mode();

    LDL_IWindow* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftWindow(pos, size, title, mode);
        break;
    case LDL_RenderMode::GDI:
        result = new LDL_GdiWindow(pos, size, title, mode);
        break;
    case LDL_RenderMode::OpenGL1:
        result = new LDL_GL1Window(pos, size, title, mode);
        break;
    default:
        break;
    }

    return result;
}

void LDL_Destroy(LDL_IWindow* window)
{
	delete window;
}

LDL_IRenderContext* LDL_RenderContextCreate(size_t mode)
{
	return new LDL_ImpRenderContext(mode);
}

void LDL_Destroy(LDL_IRenderContext* context)
{
	delete context;
}