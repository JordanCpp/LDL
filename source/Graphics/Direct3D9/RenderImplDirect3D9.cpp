#include "RenderImplDirect3D9.hpp"
#include "TextureImplDirect3D9.hpp"

#include <LDL/Math/Funcs.hpp>
#include "../source/Platforms/Windows/Graphics/Direct3D9/WindowImplDirect3D9.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImplDirect3D9::RenderImplDirect3D9(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_RenderContextImpl(renderContextImpl)
{
	Begin();
}

void RenderImplDirect3D9::Buffer(uint8_t* dst)
{
}

void RenderImplDirect3D9::Begin()
{
}

void RenderImplDirect3D9::End()
{
}

const Vec2u& RenderImplDirect3D9::Size()
{
	return _Window->Size();
}

const Color& RenderImplDirect3D9::Color()
{
	return _Color;
}

void RenderImplDirect3D9::Clear()
{
}

void RenderImplDirect3D9::Color(const LDL::Graphics::Color& color)
{
	_Color = color;
}

void RenderImplDirect3D9::Pixel(const Vec2u& pos)
{
}

void RenderImplDirect3D9::Line(const Vec2u& pos1, const Vec2u& pos2)
{
}

void RenderImplDirect3D9::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplDirect3D9::Draw(Surface* image, const Vec2u& pos)
{
}

void RenderImplDirect3D9::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplDirect3D9::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplDirect3D9::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplDirect3D9::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size(), Vec2u(0, 0), image->Size());
}

void RenderImplDirect3D9::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	Draw(image, pos, size, Vec2u(0, 0), image->Size());
}

void RenderImplDirect3D9::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void RenderImplDirect3D9::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplDirect3D9::Draw(TextureBatcher* textureBatcher)
{
}