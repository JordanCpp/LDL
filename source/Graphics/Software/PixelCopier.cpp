#include <LDL/Graphics/PixelCopier.hpp>

using namespace LDL::Graphics;

void PixelCopier::Copy(Surface* srcSurf, Surface* dstSurf, const Point2u& pos)
{
	uint8_t* dstPixels = dstSurf->Pixels();
	uint8_t* srcPixels = srcSurf->Pixels();

	size_t srcStride = srcSurf->Size().PosX() * 4;
	size_t dstStride = dstSurf->Size().PosX() * 4;

	size_t w = srcSurf->Size().PosX();
	size_t h = srcSurf->Size().PosY();

	for (size_t y = 0; y < h; ++y)
	{
		for (size_t x = 0; x < w; ++x)
		{
			uint8_t* src = srcPixels + x * 4;
			uint8_t* dst = dstPixels + x * 4;

			if (src[4] != 0)
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