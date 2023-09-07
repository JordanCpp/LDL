#include <LDL/Low/PixCopy.hpp>

void LDL_PixelCopier::Draw(LDL_Surface& dst, const LDL_Point2u& pos, LDL_Surface& src)
{
	size_t x = pos.x;
	size_t y = pos.y;

	size_t   dstSizeX  = dst.Size().x;
	size_t   dstSizeY  = dst.Size().y;
	uint8_t  dstBpp    = dst.Bpp();
	uint8_t LDL_FAR* dstPixels = dst.Pixels();
	size_t   dstIndex  = 0;

	size_t   srcSizeX  = src.Size().x;
	size_t   srcSizeY  = src.Size().y;
	uint8_t  srcBpp    = src.Bpp();
	uint8_t LDL_FAR* srcPixels = src.Pixels();
	size_t   srcIndex  = 0;

	for (size_t i = 0; i < srcSizeX; i++)
	{
		for (size_t j = 0; j < srcSizeY; j++)
		{
			dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
			srcIndex = (srcSizeX * j + i) * srcBpp;

#ifdef LDL_COLOR_RGBA
			dstPixels[dstIndex + 0] = srcPixels[srcIndex + 0];
			dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
			dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2];
#else
			dstPixels[dstIndex + 2] = srcPixels[srcIndex + 0];
			dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
			dstPixels[dstIndex + 0] = srcPixels[srcIndex + 2];
#endif  
		}
	}
}