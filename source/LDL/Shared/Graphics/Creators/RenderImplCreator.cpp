#include "RenderImplCreator.hpp"

#include "../Renders/Software/RenderImplSoftware.hpp"
#include "../Renders/OpenGL1/RenderImplOpenGL1.hpp"
#include "../Renders/OpenGL3/RenderImplOpenGL3.hpp"
#include "../Renders/Glide/RenderImplGlide.hpp"

#include <LDL/Core/Assert.hpp>
#include <LDL/Enums/RenderMode.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderImpl* RenderImplCreator::Create(RenderContext* renderContext, Window* window)
{
	size_t mode = renderContext->Mode();
	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	RenderImpl* result = NULL;

	switch (mode)
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
	case RenderMode::Glide:
		result = new RenderImplGlide(renderContext->GetRenderContextImpl(), window);
		break;
	}

	return result;
}
