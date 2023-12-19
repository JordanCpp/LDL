#include "RenderImplGlide.hpp"
#include "TextureImplGlide.hpp"
#include <LDL/Core/RuntimeError.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/WindowImplGlide.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp"
#endif

using namespace LDL::Core;
using namespace LDL::Glide;
using namespace LDL::Graphics;
using namespace LDL::Math;

struct Vertex
{
	Vertex(FxFloat x, FxFloat y)
	{
		this->x = x;
		this->y = y;
	}

	Vertex(const Vec2u& pos)
	{
		this->x = (FxFloat)pos.x;
		this->y = (FxFloat)pos.y;
	}

	FxFloat x;
	FxFloat y;
};

RenderImplGlide::RenderImplGlide(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_RenderContextImpl(renderContextImpl)
{
	FxU32 windowHandle = (FxU32)_Window->GetWindowImpl()->NativeHandle();

	grGlideInit();
	grSstSelect(0);

	FxBool result = grSstWinOpen(windowHandle, GR_RESOLUTION_800x600, GR_REFRESH_60Hz, GR_COLORFORMAT_RGBA, GR_ORIGIN_UPPER_LEFT, 2, 1);
	if (!result)
		throw RuntimeError("grSstWinOpen failed");

	grVertexLayout(GR_PARAM_XY, 0, GR_PARAM_ENABLE);
	grColorCombine(GR_COMBINE_FUNCTION_LOCAL, GR_COMBINE_FACTOR_NONE, GR_COMBINE_LOCAL_CONSTANT, GR_COMBINE_OTHER_NONE, FXFALSE);
}

RenderImplGlide::~RenderImplGlide()
{
	grGlideShutdown();
}

void RenderImplGlide::Buffer(uint8_t* dst)
{
}

void RenderImplGlide::Begin()
{
}

void RenderImplGlide::End()
{
	grBufferSwap(1);
}

const Vec2u& RenderImplGlide::Size()
{
	return _Window->Size();
}

const Color& RenderImplGlide::Color()
{
	return _Color;
}

void RenderImplGlide::Clear()
{
	grBufferClear(_Color.toInt(), _Color.a, 0);
}

void RenderImplGlide::Color(const LDL::Graphics::Color& color)
{
	_Color = color;
}

void RenderImplGlide::Pixel(const Vec2u& pos)
{
}

void RenderImplGlide::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	grConstantColorValue(_Color.toInt());

	Vertex start(pos1);
	Vertex finish(pos2);

	grDrawLine(&start, &finish);
}

void RenderImplGlide::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplGlide::Draw(Surface* image, const Vec2u& pos)
{
}

void RenderImplGlide::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplGlide::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplGlide::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplGlide::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size(), Vec2u(0, 0), image->Size());
}

void RenderImplGlide::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	Draw(image, pos, size, Vec2u(0, 0), image->Size());
}

void RenderImplGlide::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void RenderImplGlide::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplGlide::Draw(TextureBatcher* textureBatcher)
{
}
