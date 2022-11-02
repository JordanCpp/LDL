#include <LDL/Graphics/Cpu/CpuRender.hpp>

LDL::Graphics::CpuRender::CpuRender(LDL::Graphics::CpuWindow* window, LDL::Graphics::CpuImage* canvas) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Canvas(canvas)
{
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuRender::Size()
{
	return _BaseRender.Size();
}

const LDL::Graphics::Color& LDL::Graphics::CpuRender::Color()
{
	return _BaseRender.Color();
}

void LDL::Graphics::CpuRender::Clear()
{
	LDL::Graphics::Color* pixels = (LDL::Graphics::Color*)_Canvas->Pixels();

	size_t size = _Canvas->Size().PosX() * _Canvas->Size().PosY();

	for (size_t i = 0; i < size; i++)
	{
		pixels[i] = _BaseRender._Current;
	}
}

void LDL::Graphics::CpuRender::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void LDL::Graphics::CpuRender::Present()
{
	_Window->Present(_Canvas->Pixels());
}

LDL::Graphics::CpuImage* LDL::Graphics::CpuRender::Canvas()
{
	return _Canvas;
}

void LDL::Graphics::CpuRender::Pixel(const LDL::Graphics::Point2u& pos)
{
	size_t i = (_BaseRender._Size._PosX * pos._PosY) + pos._PosX;

	if (i < _BaseRender._Size._PosX * _BaseRender._Size._PosY)
	{
		LDL::Graphics::Color* pixels = (LDL::Graphics::Color*)_Canvas->Pixels();

		pixels[i] = _BaseRender._Current;
	}
}

const LDL::Graphics::Color& LDL::Graphics::CpuRender::GetPixel(const LDL::Graphics::Point2u& pos)
{
	size_t i = (Size().PosX() * pos.PosY()) + pos.PosX();

	LDL::Graphics::Color* pixels = (LDL::Graphics::Color*)_Canvas->Pixels();

	return	pixels[i];
}

void LDL::Graphics::CpuRender::Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	size_t x = pos.PosX();
	size_t y = pos.PosY();

	for (size_t i = 0; i < size.PosX(); i++)
	{
		for (size_t j = 0; j < size.PosY(); j++)
		{
			Pixel(LDL::Graphics::Point2u(x + i, y + j));
		}
	}
}

void LDL::Graphics::CpuRender::Rect(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	size_t x = pos.PosX();
	size_t y = pos.PosY();
	size_t w = size.PosX();
	size_t h = size.PosY();

	for (size_t i = 0; i < w; i++)
	{
		Pixel(LDL::Graphics::Point2u(x + i, y));
	}

	for (size_t i = 0; i < w; i++)
	{
		Pixel(LDL::Graphics::Point2u(x + i, y + h));
	}

	for (size_t i = 0; i < h; i++)
	{
		Pixel(LDL::Graphics::Point2u(x, y + i));
	}

	for (size_t i = 0; i < h; i++)
	{
		Pixel(LDL::Graphics::Point2u(x + w, y + i));
	}
}

void LDL::Graphics::CpuRender::Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2)
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

	Pixel(LDL::Graphics::Point2u(x2, y2));

	while (x1 != x2 || y1 != y2)
	{
		Pixel(LDL::Graphics::Point2u(x1, y1));

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

uint8_t* LDL::Graphics::CpuRender::Pixels()
{
	return _Canvas->Pixels();
}

size_t LDL::Graphics::CpuRender::BytesPerPixel()
{
	return _Canvas->BytesPerPixel();
}

void LDL::Graphics::CpuRender::Draw(LDL::Graphics::CpuImage& image, const LDL::Graphics::Point2u& pos)
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

		srcPixels += srcStride;
		dstPixels += dstStride;
	}
}