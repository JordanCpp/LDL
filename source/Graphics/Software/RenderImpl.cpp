#include "RenderImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->View()),
	_Canvas(_Window->Size())
{
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
}

void RenderImpl::End()
{
	_Window->Present(_Canvas.Pixels());
}

const Point2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const Color& RenderImpl::Color()
{
	return _BaseRender.Color();
}

void RenderImpl::Clear()
{
	Graphics::Color* pixels = (Graphics::Color*)_Canvas.Pixels();

	size_t size = _Canvas.Size().PosX() * _Canvas.Size().PosY();

	for (size_t i = 0; i < size; i++)
	{
		pixels[i] = _BaseRender._Current;
	}
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Point2u& pos)
{
	size_t i = (_BaseRender._Size._PosX * pos._PosY) + pos._PosX;

	LDL::Graphics::Color* pixels = (LDL::Graphics::Color*)_Canvas.Pixels();

	if (i < _BaseRender._Size._PosX * _BaseRender._Size._PosY)
	{
		pixels[i] = _BaseRender._Current;
	}
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
	int x1 = (int)pos1.PosX();
	int y1 = (int)pos1.PosY();

	int x2 = (int)pos2.PosX();
	int y2 = (int)pos2.PosY();

	int deltaX;
	int deltaY;
	int signX;
	int signY;
	int error;
	int error2;

	deltaX = abs(x2 - x1);
	deltaY = abs(y2 - y1);
	signX = x1 < x2 ? 1 : -1;
	signY = y1 < y2 ? 1 : -1;

	error = deltaX - deltaY;

	Pixel(Point2u(x2, y2));

	while (x1 != x2 || y1 != y2)
	{
		Pixel(Point2u(x1, y1));

		error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}

		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
	size_t x = pos.PosX();
	size_t y = pos.PosY();

	for (size_t i = 0; i < size.PosX(); i++)
	{
		for (size_t j = 0; j < size.PosY(); j++)
		{
			Pixel(Point2u(x + i, y + j));
		}
	}
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
	uint8_t* dstPixels = _Canvas.Pixels();
	uint8_t* srcPixels = image->Pixels();

	size_t srcStride = image->Size().PosX() * 4;
	size_t dstStride = _BaseRender.Size().PosX() * 4;

	for (size_t y = 0; y < image->Size().PosY(); ++y)
	{
		for (size_t x = 0; x < image->Size().PosX(); ++x)
		{
			uint8_t* src = srcPixels + x * 4;
			uint8_t* dst = dstPixels + x * 4;

			if (src[4] != 0)
			{
#if defined(WIN32) || defined(WIN64)
				dst[0] = src[2];
				dst[1] = src[1];
				dst[2] = src[0];
#else 
				dst[0] = src[0];
				dst[1] = src[1];
				dst[2] = src[2];
#endif
			}
		}

		srcPixels += srcStride;
		dstPixels += dstStride;
	}
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}