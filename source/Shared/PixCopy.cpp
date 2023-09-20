#include <LDL/Low/PixCopy.hpp>

void LDL_PixelCopier::Draw(LDL_ISurface* dst, const LDL_Point2u& pos, LDL_ISurface* src)
{
	size_t x = pos.x;
	size_t y = pos.y;

	size_t   dstSizeX  = dst->Size().x;
	size_t   dstSizeY  = dst->Size().y;
	uint8_t  dstBpp    = dst->Bpp();
	uint8_t LDL_FAR* dstPixels = dst->Pixels();
	size_t   dstIndex  = 0;

	size_t   srcSizeX  = src->Size().x;
	size_t   srcSizeY  = src->Size().y;
	uint8_t  srcBpp    = src->Bpp();
	uint8_t LDL_FAR* srcPixels = src->Pixels();
	size_t   srcIndex  = 0;

	size_t limitSizeX = 0;
	size_t limitSizeY = 0;

	if (srcSizeX + x > dstSizeX)
		limitSizeX = dstSizeX - x;
	else
		limitSizeX = srcSizeX;

	if (srcSizeY + y > dstSizeY)
		limitSizeY = dstSizeY - y;
	else
		limitSizeY = srcSizeY;

	for (size_t i = 0; i < limitSizeX; i++)
	{
		for (size_t j = 0; j < limitSizeY; j++)
		{
			dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
			srcIndex = (srcSizeX * j + i) * srcBpp;

#ifdef LDL_COLOR_RGBA
			dstPixels[dstIndex    ] = srcPixels[srcIndex    ];
			dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
			dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2];
#else
			dstPixels[dstIndex + 2] = srcPixels[srcIndex    ];
			dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
			dstPixels[dstIndex    ] = srcPixels[srcIndex + 2];
#endif  
		}
	}
}