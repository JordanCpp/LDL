#include <LDLC/LDL_RenderContext.h>
#include <LDL/Graphics/RenderContext.hpp>

using namespace LDL::Graphics;

struct LDL_RenderContext
{
	RenderContext _RenderContext;
	LDL_RenderContext();
};

LDL_RenderContext::LDL_RenderContext()
{
}

LDL_RenderContext* LDL_RenderContextNew()
{
	LDL_RenderContext* p = new LDL_RenderContext;

	return p;
}

void LDL_RenderContextFree(LDL_RenderContext* renderContext)
{
	delete renderContext;
}

void LDL_RenderContextGetContext(LDL_RenderContext* renderContext)
{
	renderContext->_RenderContext.Context();
}
