#include "RenderImpl.hpp"
#include "../../Platforms/Windows/Graphics/Software/WindowImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Canvas(_Window->Size(), 4),
	_ImageResizer(_Window->Size())
{
	_PixelPainter.Bind(&_Canvas);
}

void RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
}

void RenderImpl::End()
{
	_Window->GetWindowImpl()->Present(_Canvas.Pixels(), _Canvas.BytesPerPixel());
}

const Vec2u& RenderImpl::Size()
{
	return _Window->Size();
}

const Color& RenderImpl::Color()
{
	return _PixelPainter.Color();
}

void RenderImpl::Clear()
{
	_PixelPainter.Clear();
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_PixelPainter.Color(color);
}

void RenderImpl::Pixel(const Vec2u& pos)
{
	_PixelPainter.Pixel(pos);
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_PixelPainter.Line(pos1, pos2);
}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
	_PixelPainter.Fill(pos, size);
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	Draw(image->GetTextureImpl()->GetSurface(), pos, size);
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	if (size.x != image->Size().x || size.y != image->Size().y)
	{
		Surface* result = _ImageResizer.Resize(size, image);
		_PixelCopier.Copy(result, &_Canvas, pos);
	}
	else
	{
		_PixelCopier.Copy(image, &_Canvas, pos);
	}
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImpl::Draw(TextureBatcher* textureBatcher)
{
}