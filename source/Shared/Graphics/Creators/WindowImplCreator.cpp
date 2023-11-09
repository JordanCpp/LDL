#include "WindowImplCreator.hpp"

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/Software/WindowImplSoftware.hpp"
#include "../source/Platforms/Windows/Graphics/OpenGL1/WindowImplOpenGL1.hpp"
#include "../source/Platforms/Windows/Graphics/OpenGL3/WindowImplOpenGL3.hpp"
#include "../source/Platforms/Windows/Graphics/DirectDraw/WindowImplDirectDraw.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Graphics/Software/WindowImplSoftware.hpp"
#include "../source/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp"
#include "../source/Platforms/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp"
#endif

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
#if defined(_WIN32)
	case Enums::RenderMode::DirectDraw:
		result = new WindowImplDirectDraw(pos, size, title, mode);
		break;
#endif
	case Enums::RenderMode::Software:
		result = new WindowImplSoftware(pos, size, title, mode);
		break;
	case Enums::RenderMode::OpenGL1:
		result = new WindowImplOpenGL1(pos, size, title, mode);
		break;
	case Enums::RenderMode::OpenGL3:
		result = new WindowImplOpenGL3(pos, size, title, mode);
		break;
	default:
		throw RuntimeError("Unknown graphics mode");
		break;
	}

	return result;
}
