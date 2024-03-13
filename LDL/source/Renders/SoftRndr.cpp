/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <LDL/Renders/SoftRndr.hpp>
#include <assert.h>
#include <string.h>

LDL_TextureSoftware::LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t* pixels, uint8_t bpp) :
	_Surface(size, size, bpp)
{
	assert(size.x >= 0);
	assert(size.y >= 0);
	assert(pixels != NULL);
	assert(bpp >= 1 && bpp <= 4);

	memcpy(_Surface.Pixels(), pixels, size.x * size.y * bpp);
}

LDL_TextureSoftware::LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t bpp) :
	_Surface(size, size, bpp)
{
	assert(size.x >= 0);
	assert(size.y >= 0);
	assert(bpp >= 1 && bpp <= 4);
}

LDL_TextureSoftware::LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t* pixels, LDL_Palette* palette) :
	_Surface(size, size, pixels, palette)
{
}

LDL_TextureSoftware::LDL_TextureSoftware(const LDL_Vec2i& size, uint8_t* pixels, LDL_Palette* palette, LDL_Alpha* alpha) :
	_Surface(size, size, pixels, palette, alpha)
{
}

LDL_TextureSoftware::~LDL_TextureSoftware()
{
}

void LDL_TextureSoftware::Copy(const LDL_Vec2i& dstPos, const LDL_Vec2i& srcSize, uint8_t* pixels, uint8_t bpp)
{
	assert(dstPos.x >= 0);
	assert(dstPos.y >= 0);
	assert(srcSize.x >= 0);
	assert(srcSize.y >= 0);
	assert(pixels != NULL);
	assert(bpp >= 1 && bpp <= 4);
}

void LDL_TextureSoftware::Copy(const LDL_Vec2i& dstPos, LDL_Surface* surface, const LDL_Vec2i& srcSize)
{
	assert(dstPos.x >= 0);
	assert(dstPos.y >= 0);
	assert(srcSize.x >= 0);
	assert(srcSize.y >= 0);
	assert(surface != NULL);
}

const LDL_Vec2i& LDL_TextureSoftware::Size()
{
	return _Size;
}

const LDL_Vec2i& LDL_TextureSoftware::Quad()
{
	return _Quad;
}

LDL_Surface* LDL_TextureSoftware::GetSurface()
{
	return &_Surface;
}

LDL_RenderSoftware::LDL_RenderSoftware(LDL_WindowSoftware* window) :
	_Window(window),
	_BaseRender(_Window->Size(), NULL),
	_Screen(_Window->GetScreen())
{
}

LDL_RenderSoftware::LDL_RenderSoftware(LDL_WindowSoftware* window, LDL_Palette* palette) :
	_Window(window),
	_BaseRender(_Window->Size(), palette),
	_Screen(_Window->GetScreen())
{
	if (palette != NULL)
	{
		_Screen->Palette(palette);
	}
}

void LDL_RenderSoftware::Begin()
{
}

void LDL_RenderSoftware::End()
{
	_Window->Present();
}

void LDL_RenderSoftware::Line(const LDL_Vec2i& pos1, const LDL_Vec2i& pos2)
{
	assert(pos1.x >= 0);
	assert(pos1.y >= 0);

	assert(pos2.x >= 0);
	assert(pos2.y >= 0);
}

void LDL_RenderSoftware::Fill(const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	assert(size.x > 0);
	assert(size.y > 0);

	int x = pos.x;
	int y = pos.y;

	int sx  = _Screen->Size().x;
	int bpp = _Screen->Bpp();

	uint8_t*  pixels     = _Screen->Pixels();
	uint8_t   colorIndex = _BaseRender.ColorIndex();
	LDL_Color colorRgb   = _BaseRender.Color();

	if (bpp == 1)
	{
		for (int i = 0; i < size.x; i++)
		{
			for (int j = 0; j < size.y; j++)
			{
				pixels[sx * (y + j) + (x + i)] = colorIndex;
			}
		}
	}
	else
	{
		for (int i = 0; i < size.x; i++)
		{
			for (int j = 0; j < size.y; j++)
			{
				int idx = (sx * (y + j) + (x + i)) * bpp;

#if defined(_WIN32)
				pixels[idx] = colorRgb.b;
				pixels[idx + 2] = colorRgb.r;
#else
				pixels[idx] = colorRgb.r;
				pixels[idx + 2] = colorRgb.b;
#endif
				pixels[idx + 1] = colorRgb.g;

			}
		}
	}
}

void LDL_RenderSoftware::SetColor(uint8_t index)
{
	_BaseRender.SetColor(index);
}

void LDL_RenderSoftware::SetColor(const LDL_Color& color)
{
	_BaseRender.SetColor(color);
}

void LDL_RenderSoftware::Clear()
{
	uint8_t          bpp    = _Screen->Bpp();
	size_t           size   = _Screen->Size().x * _Screen->Size().y * _Screen->Bpp();
	uint8_t LDL_FAR* pixels = _Screen->Pixels();

	uint8_t   colorIndex = _BaseRender.ColorIndex();
	LDL_Color colorRgb   = _BaseRender.Color();

	if (bpp == 1)
	{
		for (size_t i = 0; i < size; i++)
		{
			pixels[i] = colorIndex;
		}
	}
	else
	{
		for (size_t i = 0; i < size; i += 3)
		{
#if defined(_WIN32)
			pixels[i] = colorRgb.b;
			pixels[i + 2] = colorRgb.r;
#else
			pixels[i] = colorRgb.r;
			pixels[i + 2] = colorRgb.b;
#endif
			pixels[i + 1] = colorRgb.g;
		}
	}
}

void LDL_RenderSoftware::Draw(LDL_TextureSoftware* image, const LDL_Vec2i& pos)
{
	Draw(image->GetSurface(), pos, image->Size(), LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderSoftware::Draw(LDL_TextureSoftware* image, const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	Draw(image->GetSurface(), pos, size, LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderSoftware::Draw(LDL_TextureSoftware* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	Draw(image->GetSurface(), dstPos, srcSize, srcPos, srcSize);
}

void LDL_RenderSoftware::Draw(LDL_TextureSoftware* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& dstSize, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	Draw(image->GetSurface(), dstPos, dstSize, srcPos, srcSize);
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2i& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	Draw(image, pos, size, LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void LDL_RenderSoftware::Draw(LDL_Surface* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& dstSize, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	assert(image != NULL);

	assert(dstPos.x >= 0);
	assert(dstPos.y >= 0);

	assert(dstSize.x >= 0);
	assert(dstSize.y >= 0);

	assert(srcPos.x >= 0);
	assert(srcPos.y >= 0);

	assert(srcSize.x >= 0);
	assert(srcSize.y >= 0);

	size_t x = dstPos.x;
	size_t y = dstPos.y;

	size_t   dstSizeX = _Screen->Size().x;
	size_t   dstSizeY = _Screen->Size().y;
	uint8_t  dstBpp   = _Screen->Bpp();
	uint8_t LDL_FAR* dstPixels = _Screen->Pixels();
	size_t   dstIndex;

	size_t   srcSizeX = image->Size().x;
	size_t   srcSizeY = image->Size().y;
	uint8_t  srcBpp   = image->Bpp();
	LDL_Palette* srcPalette = image->Palette();
	uint8_t LDL_FAR* srcPixels = image->Pixels();
	size_t   srcIndex;

	size_t limitSizeX;
	size_t limitSizeY;

	if (srcSizeX + x > dstSizeX)
		limitSizeX = dstSizeX - x;
	else
		limitSizeX = srcSizeX;

	if (srcSizeY + y > dstSizeY)
		limitSizeY = dstSizeY - y;
	else
		limitSizeY = srcSizeY;

	if (dstBpp == 1 && srcBpp == 1)
	{ 
		for (size_t i = 0; i < limitSizeX; i++)
		{
			for (size_t j = 0; j < limitSizeY; j++)
			{
				dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
				srcIndex = (srcSizeX * j + i) * srcBpp;

				dstPixels[dstIndex] = srcPixels[srcIndex];
			}
		}
	}
	else if (dstBpp == 3 && srcBpp == 1)
	{
		LDL_Color color;
		uint8_t srcAlpha = image->Alpha().Index();

		for (size_t i = 0; i < limitSizeX; i++)
		{
			for (size_t j = 0; j < limitSizeY; j++)
			{
				dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
				srcIndex = (srcSizeX * j + i) * srcBpp;

				if (srcPixels[srcIndex] != srcAlpha)
				{
					color = srcPalette->Get(srcPixels[srcIndex]);

#if defined (_WIN32)
					dstPixels[dstIndex] = color.b;
					dstPixels[dstIndex + 1] = color.g;
					dstPixels[dstIndex + 2] = color.r;
#else
					dstPixels[dstIndex] = color.r;
					dstPixels[dstIndex + 1] = color.g;
					dstPixels[dstIndex + 2] = color.b;
#endif  
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < limitSizeX; i++)
		{
			for (size_t j = 0; j < limitSizeY; j++)
			{
				dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
				srcIndex = (srcSizeX * j + i) * srcBpp;

#if defined (_WIN32)
				dstPixels[dstIndex + 2] = srcPixels[srcIndex];
				dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
				dstPixels[dstIndex] = srcPixels[srcIndex + 2];
#else
				dstPixels[dstIndex] = srcPixels[srcIndex];
				dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
				dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2];
#endif  
			}
		}
	}
}