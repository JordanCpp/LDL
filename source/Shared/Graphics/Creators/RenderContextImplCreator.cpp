#include <LDL/Enums/RenderMode.hpp>
#include "RenderContextImplCreator.hpp"

#include "../Renders/Software/RenderContextImplSoftware.hpp"
#include "../Renders/OpenGL1/RenderContextImplOpenGL1.hpp"
#include "../Renders/OpenGL3/RenderContextImplOpenGL3.hpp"
#include "../Renders/Glide/RenderContextImplGlide.hpp"
#include "../Renders/Direct3D6/RenderContextImplDirect3D6.hpp"

#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderContextImpl* RenderContextImplCreator::Create(size_t mode)
{
	RenderContextImpl* result = NULL;

	LDL_ASSERT_DETAIL(mode < RenderMode::Max, "Unknown graphics mode");

	switch (mode)
	{
	case RenderMode::Software:
		result = new RenderContextImplSoftware(mode);
		break;
	case RenderMode::OpenGL1:
		result = new RenderContextImplOpenGL1(mode);
		break;
	case RenderMode::OpenGL3:
		result = new RenderContextImplOpenGL3(mode);
		break;
	case RenderMode::Glide:
		result = new RenderContextImplGlide(mode);
		break;
	case RenderMode::Direct3D6:
		result = new RenderContextImplDirect3D6(mode);
		break;
	}

	return result;
}
