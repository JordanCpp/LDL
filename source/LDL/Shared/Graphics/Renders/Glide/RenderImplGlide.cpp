// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Shared/Graphics/Renders/Glide/RenderImplGlide.hpp>

#if defined(_WIN32)
    #include <LDL/Platforms/Windows/Graphics/WindowImplGlide.hpp>
#elif defined(__unix__)
    #include <LDL/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp>
#endif

using namespace LDL;
using namespace LDL::Glide;

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

RenderImplGlide::RenderImplGlide(Result& result, RenderContextImpl* renderContextImpl, Window* window) :
	_result(result),
	_window(window),
	_renderContextImpl(renderContextImpl)
{
	FxU32 windowHandle = (FxU32)_window->GetWindowImpl()->NativeHandle();

	grGlideInit();
	grSstSelect(0);

	FxBool res = grSstWinOpen(windowHandle, GR_RESOLUTION_800x600, GR_REFRESH_60Hz, GR_COLORFORMAT_RGBA, GR_ORIGIN_UPPER_LEFT, 2, 1);
	
	if (!res)
	{
		_result.Message("grSstWinOpen failed");
		return;
	}

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
	return _window->Size();
}

const Color& RenderImplGlide::GetColor()
{
	return _color;
}

void RenderImplGlide::Clear()
{
	grBufferClear(_color.toInt(), _color.a, 0);
}

void RenderImplGlide::SetColor(const Color& color)
{
	_color = color;
}

void RenderImplGlide::Pixel(const Vec2u& pos)
{
}

void RenderImplGlide::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	grConstantColorValue(_color.toInt());

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
