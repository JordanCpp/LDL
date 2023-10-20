#include "RenderImplCreator.hpp"

#include "../Renders/Software/RenderImplSoftware.hpp"
#include "../Renders/OpenGL1/RenderImplOpenGL1.hpp"
#include "../Renders/OpenGL3/RenderImplOpenGL3.hpp"

#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/RenderMode.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderImpl* RenderImplCreator::Create(RenderContext* renderContext, Window* window)
{
	size_t renderMode = renderContext->Mode();

	RenderImpl* result = NULL;

	switch (renderMode)
	{
	case RenderMode::Software:
		result = new RenderImplSoftware(renderContext->GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL1:
		result = new RenderImplOpenGL1(renderContext->GetRenderContextImpl(), window);
		break;
	case RenderMode::OpenGL3:
		result = new RenderImplOpenGL3(renderContext->GetRenderContextImpl(), window);
		break;
	default:
		throw RuntimeError("Unknown graphics mode");
		break;
	}

	return result;
}
