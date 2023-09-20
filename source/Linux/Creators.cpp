#include <LDL/Low/Creators.hpp>
#include "../Renders/SoftRend.hpp"
#include "SoftWin.hpp"
#include "RContext.hpp"

LDL_ISurface* SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow * window, const LDL_Point2u& size, uint8_t bpp)
{
    size_t renderMode = renderContext->Mode();

    LDL_ISurface* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftwareSurface(size, bpp);
        break;
    case LDL_RenderMode::GDI:
        break;
    default:
        break;
    }

    return result;
}

LDL_ISurface* SurfaceCreate(LDL_IRenderContext* renderContext, LDL_IWindow* window, const LDL_Point2u& size, uint8_t LDL_FAR* bytes, uint8_t bpp)
{
    size_t renderMode = renderContext->Mode();

    LDL_ISurface* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftwareSurface(size, bytes, bpp);
        break;
    case LDL_RenderMode::GDI:

        break;
    default:
        break;
    }

    return result;
}

void Destroy(LDL_ISurface* surface)
{
    delete surface;
}

LDL_IRender* RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window)
{
	return new LDL_SoftRender(context, window);
}

void Destroy(LDL_IRender* render)
{
	delete render;
}

LDL_IWindow* WindowCreate(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode)
{
	return new LDL_SoftWindow(errorHandler, pos, size, title, mode);
}

void Destroy(LDL_IWindow* window)
{
	delete window;
}

LDL_IRenderContext* RenderContextCreate(size_t mode)
{
	return new LDL_ImpRenderContext(mode);
}

void Destroy(LDL_IRenderContext* context)
{
	delete context;
}