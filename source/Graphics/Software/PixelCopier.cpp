#include <LDL/Graphics/PixelCopier.hpp>
#include <assert.h>

using namespace LDL::Graphics;
using namespace LDL::Math;

void PixelCopier::Copy(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos)
{
	assert(srcSurf != NULL);
	assert(dstSurf != NULL);

	assert(srcSurf->BytesPerPixel() <= dstSurf->BytesPerPixel());

	assert(srcSurf->Size().x <= dstSurf->Size().x);
	assert(srcSurf->Size().y <= dstSurf->Size().y);

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

void PixelCopier::Copy8(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos)
{
}

void PixelCopier::Copy16(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos)
{
}

void PixelCopier::Copy24(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos)
{
	Copy32(srcSurf, dstSurf, pos);
}

void PixelCopier::Copy32(Surface* srcSurf, Surface* dstSurf, const Vec2u& pos)
{
	uint8_t dstBpp = dstSurf->BytesPerPixel();
	uint8_t srcBpp = srcSurf->BytesPerPixel();

	uint8_t* dstPixels = dstSurf->Pixels() + (pos.x + pos.y * dstSurf->Size().x) * dstBpp;
	uint8_t* srcPixels = srcSurf->Pixels();

	size_t dstStride = dstSurf->Size().x * dstBpp;
	size_t srcStride = srcSurf->Size().x * srcBpp;

	size_t w = srcSurf->Size().x;
	size_t h = srcSurf->Size().y;

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