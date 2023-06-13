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
	size_t   dst_w    = dstSurf->Size().x;
	size_t   dst_h    = dstSurf->Size().y;
	size_t   dst_bpp  = dstSurf->BytesPerPixel();
	uint8_t* dst_data = dstSurf->Pixels();

	size_t   src_w    = srcSurf->Size().x;
	size_t   src_h    = srcSurf->Size().y;
	size_t   src_bpp  = srcSurf->BytesPerPixel();
	uint8_t* src_data = srcSurf->Pixels();

	size_t limit = dst_w * dst_h * dst_bpp;

	for (size_t y = 0; y < src_h; ++y)
	{
		for (size_t x = 0; x < src_w; ++x)
		{
			size_t dst_index = (dst_w * (pos.y + y) + pos.x + x) * dst_bpp;
			size_t src_index = (src_w * y + x) * src_bpp;

			if (dst_index < limit)
			{
				if (srcSurf->Pixels()[src_index + 3] != 0)
				{
#if defined(LDL_CONFIG_COLOR_BGRA)
					dstSurf->Pixels()[dst_index + 0] = srcSurf->Pixels()[src_index + 2];
					dstSurf->Pixels()[dst_index + 1] = srcSurf->Pixels()[src_index + 1];
					dstSurf->Pixels()[dst_index + 2] = srcSurf->Pixels()[src_index + 0];
#else
					dstSurf->Pixels()[dst_index + 0] = srcSurf->Pixels()[src_index + 0];
					dstSurf->Pixels()[dst_index + 1] = srcSurf->Pixels()[src_index + 1];
					dstSurf->Pixels()[dst_index + 2] = srcSurf->Pixels()[src_index + 2];
#endif
				}

			}
		}
	}
}