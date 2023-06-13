#include <LDL/Graphics/Render.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/RenderImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/RenderImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/RenderImpl.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/RenderImpl.hpp"
#elif LDL_RENDER_DIRECTX1
#include "DirectDraw/RenderImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/RenderImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/RenderImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/RenderImpl.hpp"
#endif

using namespace LDL::Graphics;
using namespace LDL::Math;

Render::Render(RenderContext* renderContext, Window* window) :
	_RenderImpl(new RenderImpl(renderContext->GetRenderContextImpl(), window))
{
}

Render::~Render()
{
	delete _RenderImpl;
}

RenderImpl* Render::GetRenderImpl()
{
	return _RenderImpl;
}


void Render::Buffer(uint8_t* dst)
{
	_RenderImpl->Buffer(dst);
}

void Render::Begin()
{
	_RenderImpl->Begin();
}

void Render::End()
{
	_RenderImpl->End();
}

const Vec2u& Render::Size()
{
	return _RenderImpl->Size();
}

const Color& Render::Color()
{
	return _RenderImpl->Color();
}

void Render::Clear()
{
	_RenderImpl->Clear();
}

void Render::Color(const LDL::Graphics::Color& color)
{
	_RenderImpl->Color(color);
}

void Render::Pixel(const Vec2u& pos)
{
	_RenderImpl->Pixel(pos);
}

void Render::Fill(const Vec2u& pos, const Vec2u& size)
{
	_RenderImpl->Fill(pos, size);
}

void Render::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_RenderImpl->Line(pos1, pos2);
}

void Render::Draw(Texture* image, const Vec2u& pos)
{
	_RenderImpl->Draw(image, pos);
}

void Render::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	_RenderImpl->Draw(image, pos, size);
}

void Render::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderImpl->Draw(image, dstPos, srcPos, srcSize);
}

void Render::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderImpl->Draw(image, dstPos, dstSize, srcPos, srcSize);
}

void Render::Draw(Surface* image, const Vec2u& pos)
{
	_RenderImpl->Draw(image, pos);
}

void Render::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_RenderImpl->Draw(image, pos, size);
}

void Render::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void Render::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void Render::Draw(TextureBatcher* textureBatcher)
{
	_RenderImpl->Draw(textureBatcher);
}