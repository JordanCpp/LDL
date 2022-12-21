#include <LDL/Graphics/Cpu/CpuRender.hpp>

using namespace LDL::Graphics;

CpuRender::CpuRender(CpuWindow* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(_Window->Size(), 4)
{
}

const Point2u& CpuRender::Size()
{
	return _BaseRender.Size();
}

const Color& CpuRender::Color()
{
	return _BaseRender.Color();
}

void CpuRender::Clear()
{
	uint8_t* pixels = (uint8_t*)_Canvas.Pixels();

	size_t bytes = _Canvas.Size().PosX() * _Canvas.Size().PosY() * BytesPerPixel();

	memset(pixels, _BaseRender._Current.toInt(), bytes);
}

void CpuRender::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void CpuRender::Present()
{
	_Window->Present(_Canvas.Pixels());
}

CpuImage* CpuRender::Canvas()
{
	return &_Canvas;
}

void CpuRender::Pixel(const Point2u& pos)
{
	size_t i = (_BaseRender._Size._PosX * pos._PosY) + pos._PosX;

	if (i < _BaseRender._Size._PosX * _BaseRender._Size._PosY)
	{
		LDL::Graphics::Color* pixels = (LDL::Graphics::Color*)_Canvas.Pixels();

		pixels[i] = _BaseRender._Current;
	}
}

const Color& CpuRender::GetPixel(const Point2u& pos)
{
	size_t i = (Size().PosX() * pos.PosY()) + pos.PosX();

	LDL::Graphics::Color* pixels = (LDL::Graphics::Color*)_Canvas.Pixels();

	return	pixels[i];
}

void CpuRender::Fill(const Point2u& pos, const Point2u& size)
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

void CpuRender::Rect(const Point2u& pos, const Point2u& size)
{
	size_t x = pos.PosX();
	size_t y = pos.PosY();
	size_t w = size.PosX();
	size_t h = size.PosY();

	for (size_t i = 0; i < w; i++)
	{
		Pixel(Point2u(x + i, y));
	}

	for (size_t j = 0; j < w; j++)
	{
		Pixel(Point2u(x + j, y + h));
	}

	for (size_t k = 0; k < h; k++)
	{
		Pixel(Point2u(x, y + k));
	}

	for (size_t g = 0; g < h; g++)
	{
		Pixel(Point2u(x + w, y + g));
	}
}

void CpuRender::Line(const Point2u& pos1, const Point2u& pos2)
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

uint8_t* CpuRender::Pixels()
{
	return _Canvas.Pixels();
}

size_t CpuRender::BytesPerPixel()
{
	return _Canvas.BytesPerPixel();
}

void CpuRender::Draw(CpuImage& image, const Point2u& pos)
{
	uint8_t* dstPixels = Pixels();
	uint8_t* srcPixels = image.Pixels();

	size_t srcStride = image.Size().PosX() * 4;
	size_t dstStride = _BaseRender.Size().PosX() * 4;

	for (size_t y = 0; y < image.Size().PosY(); ++y)
	{
		for (size_t x = 0; x < image.Size().PosX(); ++x)
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