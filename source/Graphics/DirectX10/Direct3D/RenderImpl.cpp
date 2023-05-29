#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../../../Platforms/Windows/Graphics/DirectX9/Direct3D/WindowImpl.hpp"
#include "TextureImpl.hpp"
#include "RenderContextImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
    _RenderContextImpl(renderContextImpl)
{
}

RenderImpl::~RenderImpl()
{
    Deinitialization();
}

void RenderImpl::Buffer(uint8_t* dst)
{

}

void RenderImpl::Mode2D()
{
}

void RenderImpl::Begin()
{
}

void RenderImpl::End()
{
}

const Vec2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& LDL::Graphics::RenderImpl::Color()
{
	return _BaseRender.Color();
}

void RenderImpl::Clear()
{
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Vec2u& pos)
{
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{
}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImpl::Initialization()
{
}

void RenderImpl::Deinitialization()
{
}