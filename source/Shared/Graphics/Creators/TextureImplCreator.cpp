#include "TextureImplCreator.hpp"

#include "../Renders/Software/TextureImplSoftware.hpp"
#include "../Renders/OpenGL1/TextureImplOpenGL1.hpp"
#include "../Renders/OpenGL3/TextureImplOpenGL3.hpp"

#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Enums/RenderMode.hpp>

using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace LDL::Graphics::Creators;

TextureImpl* TextureImplCreator::Create(RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel)
{
	size_t renderMode = renderContext->Mode();

	TextureImpl* result = NULL;

	switch (renderMode)
	{
	case RenderMode::Software:
		result = new TextureImplSoftware(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	case RenderMode::OpenGL3:
		result = new TextureImplOpenGL3(renderContext->GetRenderContextImpl(), size, pixels, bytesPerPixel);
		break;
	default:
		throw RuntimeError("Unknown graphics mode");
		break;
	}

	return result;
}

TextureImpl* TextureImplCreator::Create(RenderContext* renderContext, const Vec2u& size, uint8_t bytesPerPixel)
{
	size_t renderMode = renderContext->Mode();

	TextureImpl* result = NULL;

	switch (renderMode)
	{
	case RenderMode::Software:
		result = new TextureImplSoftware(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	case RenderMode::OpenGL1:
		result = new TextureImplOpenGL1(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	case RenderMode::OpenGL3:
		result = new TextureImplOpenGL3(renderContext->GetRenderContextImpl(), size, bytesPerPixel);
		break;
	default:
		throw RuntimeError("Unknown graphics mode");
		break;
	}

	return result;
}
