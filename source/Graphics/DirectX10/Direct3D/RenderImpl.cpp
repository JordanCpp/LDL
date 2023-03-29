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

const Point2u& RenderImpl::Size()
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

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}

void RenderImpl::Initialization()
{
}

void RenderImpl::Deinitialization()
{
}