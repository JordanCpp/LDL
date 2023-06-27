#include "RenderImplDirect3D9.hpp"
#include "TextureImplDirect3D9.hpp"

#include <LDL/Core/Library.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Math/Funcs.hpp>
#include "../source/Platforms/Windows/Graphics/Direct3D9/WindowImplDirect3D9.hpp"

using namespace LDL::Core;
using namespace LDL::Math;
using namespace LDL::Graphics;

RenderImplDirect3D9::RenderImplDirect3D9(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_RenderContextImpl(renderContextImpl)
{
	Begin();

	Library library("direct3d9.dll");

	Direct3DCreate9 = (PFNDirect3DCreate9)library.Function("Direct3DCreate9");

	_Direct = Direct3DCreate9(D3D_SDK_VERSION);
	if (_Direct == NULL)
		throw LDL::Core::RuntimeError("Direct3DCreate9 failed");
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