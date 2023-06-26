#include "WindowImplCreator.hpp"

#include "../../Platforms/Windows/Graphics/Software/WindowImplSoftware.hpp"
#include "../../Platforms/Windows/Graphics/OpenGL1/WindowImplOpenGL1.hpp"
#include "../../Platforms/Windows/Graphics/OpenGL3/WindowImplOpenGL3.hpp"

#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

WindowImpl* WindowImplCreator::Create(RenderContext* renderContext, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode)
{
	size_t renderMode = renderContext->Mode();

	WindowImpl* result = NULL;

	switch (renderMode)
	{
	case Enums::RenderMode::Software:
		result = new WindowImplSoftware(pos, size, title, renderMode);
		break;
	case Enums::RenderMode::OpenGL1:
		result = new WindowImplOpenGL1(pos, size, title, renderMode);
		break;
	case Enums::RenderMode::OpenGL3:
		result = new WindowImplOpenGL3(pos, size, title, renderMode);
		break;
	default:
		throw RuntimeError("Unknown graphics mode");
		break;
	}

	return result;
}