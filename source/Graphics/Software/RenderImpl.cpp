#include "RenderImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->View()),
	_Canvas(_Window->Size(), 4)
{
	_PixelPainter.Bind(&_Canvas);
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
}

void RenderImpl::End()
{
	_Window->Present(_Canvas.Pixels(), _Canvas.BytesPerPixel());
}

const Point2u& RenderImpl::Size()
{
	return _BaseRender.Size();
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
	_PixelCopier.Copy(image->GetTextureImpl()->GetSurface(), &_Canvas, pos);
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
	_PixelCopier.Copy(image, &_Canvas, pos);
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}