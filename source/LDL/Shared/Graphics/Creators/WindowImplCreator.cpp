#include "WindowImplCreator.hpp"

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Graphics/WindowImplSoftware.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL1.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL3.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplDirectDraw.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplGlide.hpp>
#include <LDL/Platforms/Windows/Graphics/WindowImplDirect3D6.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Graphics/Software/WindowImplSoftware.hpp>
#include <LDL/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp>
#include <LDL/Platforms/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp>
#include <LDL/Platforms/Linux/Graphics/Glide/WindowImplGlide.hpp>
#endif

#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

WindowImpl* WindowImplCreator::Create(RenderContext* renderContext, const Vec2u& pos, const Vec2u& size, const std::string& title, size_t mode)
{
	size_t renderMode = renderContext->Mode();
	LDL_ASSERT_DETAIL(renderMode < RenderMode::Max, "Unknown graphics mode");

	WindowImpl* result = NULL;

	switch (renderMode)
	{
#if defined(_WIN32)
	case RenderMode::DirectDraw:
		result = new WindowImplDirectDraw(pos, size, title, mode);
		break;

	case RenderMode::Direct3D6:
		result = new WindowImplDirect3D6(pos, size, title, mode);
		break;
#endif
	case RenderMode::Software:
		result = new WindowImplSoftware(pos, size, title, mode);
		break;
	case RenderMode::OpenGL1:
		result = new WindowImplOpenGL1(pos, size, title, mode);
		break;
	case RenderMode::OpenGL3:
		result = new WindowImplOpenGL3(pos, size, title, mode);
		break;
	case RenderMode::Glide:
		result = new WindowImplGlide(pos, size, title, mode);
		break;
	}

	return result;
}
