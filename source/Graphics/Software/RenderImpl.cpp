#include "RenderImpl.hpp"
#include "../../Platforms/Windows/Graphics/Software/WindowImpl.hpp"

using namespace LDL::Graphics;

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

const Point2u& RenderImpl::Size()
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

void RenderImpl::Pixel(const Point2u& pos)
{
	_PixelPainter.Pixel(pos);
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
	_PixelPainter.Line(pos1, pos2);
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
	_PixelPainter.Fill(pos, size);
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
	Draw(image->GetTextureImpl()->GetSurface(), pos, size);
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
	if (size.PosX() != image->Size().PosX() || size.PosY() != image->Size().PosY())
	{
		Surface* result = _ImageResizer.Resize(size, image);
		_PixelCopier.Copy(result, &_Canvas, pos);
	}
	else
	{
		_PixelCopier.Copy(image, &_Canvas, pos);
	}
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize)
{
}

void RenderImpl::Draw(TextureBatcher* textureBatcher)
{
}