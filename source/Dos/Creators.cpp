#include <LDL/Low/Creators.hpp>
#include "SoftRend.hpp"
#include "SoftWin.hpp"
#include "RContext.hpp"

LDL_ITexture* LDL_TextureCreate(LDL_IRenderContext* renderContext, const LDL_Point2u& size, uint8_t* pixels, uint8_t bpp)
{
    return NULL;
}

void LDL_Destroy(LDL_ITexture* texture)
{
    delete texture;
}

LDL_ISurface* LDL_SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t bpp)
{
    size_t renderMode = renderContext->Mode();

    LDL_ISurface* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftwareSurface(size, bpp);
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
	return new LDL_SoftRender(context, window);
}

void LDL_Destroy(LDL_IRender* render)
{
	delete render;
}

LDL_IWindow* LDL_WindowCreate(LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode)
{
	return new LDL_SoftWindow(context, pos, size, title);
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