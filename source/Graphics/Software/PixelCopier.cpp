#include <LDL/Graphics/PixelCopier.hpp>

using namespace LDL::Graphics;

void PixelCopier::Copy(Surface* srcSurf, Surface* dstSurf, const Point2u& pos)
{
	uint8_t bpp = srcSurf->BytesPerPixel();

	switch (bpp)
	{
	case 4:
		Copy32(srcSurf, dstSurf, pos);
		break;
	case 3:
		Copy24(srcSurf, dstSurf, pos);
		break;
	case 2:
		Copy16(srcSurf, dstSurf, pos);
		break;
	default:
		Copy8(srcSurf, dstSurf, pos);
	}
}

void PixelCopier::Copy8(Surface* srcSurf, Surface* dstSurf, const Point2u& pos)
{
}

void PixelCopier::Copy16(Surface* srcSurf, Surface* dstSurf, const Point2u& pos)
{
}

void PixelCopier::Copy24(Surface* srcSurf, Surface* dstSurf, const Point2u& pos)
{
	Copy32(srcSurf, dstSurf, pos);
}

void PixelCopier::Copy32(Surface* srcSurf, Surface* dstSurf, const Point2u& pos)
{
	uint8_t dstBpp = dstSurf->BytesPerPixel();
	uint8_t srcBpp = srcSurf->BytesPerPixel();

	uint8_t* dstPixels = dstSurf->Pixels() + (pos.PosX() + pos.PosY() * dstSurf->Size().PosX()) * dstBpp;
	uint8_t* srcPixels = srcSurf->Pixels();

	size_t dstStride = dstSurf->Size().PosX() * dstBpp;
	size_t srcStride = srcSurf->Size().PosX() * srcBpp;

	size_t w = srcSurf->Size().PosX();
	size_t h = srcSurf->Size().PosY();

	for (size_t y = 0; y < h; ++y)
	{
		for (size_t x = 0; x < w; ++x)
		{
			uint8_t* dst = dstPixels + x * dstBpp;
			uint8_t* src = srcPixels + x * srcBpp;

			if (src[3] != 0)
			{
#if defined(LDL_CONFIG_COLOR_BGRA)
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