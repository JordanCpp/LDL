#include <LDL/Low/Creators.hpp>
#include "../Renders/SoftRend.hpp"
#include "GdiRend.hpp"
#include "SoftWin.hpp"
#include "GdiWin.hpp"
#include "RContext.hpp"

LDL_IRender* RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window)
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
    default:
        break;
    }

    return result;
}

void Destroy(LDL_IRender* render)
{
	delete render;
}

LDL_IWindow* WindowCreate(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode)
{
    size_t renderMode = context->Mode();

    LDL_IWindow* result = NULL;

    switch (renderMode)
    {
    case LDL_RenderMode::Software:
        result = new LDL_SoftWindow(errorHandler, pos, size, title, mode);
        break;
    case LDL_RenderMode::GDI:
        result = new LDL_GdiWindow(errorHandler, pos, size, title, mode);
        break;
    default:
        break;
    }

    return result;
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