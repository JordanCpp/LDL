#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include "RenderContextImplCreator.hpp"

#include "../Software/RenderContextImplSoftware.hpp"
#include "../OpenGL1/RenderContextImplOpenGL1.hpp"
#include "../OpenGL3/RenderContextImplOpenGL3.hpp"
#include "../Direct3D9/RenderContextImplDirect3D9.hpp"

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

RenderContextImpl* RenderContextImplCreator::Create(size_t mode)
{
	RenderContextImpl* result = NULL;

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
	case RenderMode::Direct3D9:
		result = new RenderContextImplDirect3D9(mode);
		break;
	default:
		throw RuntimeError("Unknown graphics mode");
		break;
	}

	return result;
}