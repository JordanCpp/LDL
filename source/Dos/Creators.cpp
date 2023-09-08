#include <LDL/Low/Creators.hpp>
#include "SoftRend.hpp"
#include "SoftWin.hpp"
#include "RContext.hpp"

LDL_IRender* RenderCreate(LDL_IRenderContext* context, LDL_IWindow* window)
{
	return new LDL_SoftRend(context, window);
}

void Destroy(LDL_IRender* render)
{
	delete render;
}

LDL_IWindow* WindowCreate(LDL_ErrorHandler* errorHandler, LDL_IRenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title)
{
	return new LDL_SoftWin(errorHandler, context, pos, size, title);
}

void Destroy(LDL_IWindow* window)
{
	delete window;
}

LDL_IRenderContext* RenderContextCreate()
{
	return new LDL_ImpRenderContext;
}

void Destroy(LDL_IRenderContext* context)
{
	delete context;
}