#include <LDL/Shared/APIs/LDLC/LDL_RenderContext.hpp>

using namespace LDL::Graphics;

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
	renderContext->_renderContext.Context();
}
