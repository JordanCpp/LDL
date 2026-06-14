/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <PixFrmt.h>
#include <LDL/Ttf.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include <stdlib.h>

static uint32_t LDL_Utf8Decode(const char** text) 
{
	const uint8_t* p = (const uint8_t*)*text;
	uint32_t c = *p;

	if (c == 0) return 0;

	if (c < 0x80) 
	{
		(*text)++;
		return c;
	}
	else if ((c & 0xE0) == 0xC0) 
	{
		c = ((p[0] & 0x1F) << 6) | (p[1] & 0x3F);
		*text += 2;
		return c;
	}
	else if ((c & 0xF0) == 0xE0) 
	{
		c = ((p[0] & 0x0F) << 12) | ((p[1] & 0x3F) << 6) | (p[2] & 0x3F);
		*text += 3;
		return c;
	}
	else if ((c & 0xF0) == 0xF0) 
	{
		c = ((p[0] & 0x07) << 18) | ((p[1] & 0x3F) << 12) | ((p[2] & 0x3F) << 6) | (p[3] & 0x3F);
		*text += 4;
		return c;
	}

	(*text)++;

	return 0;
}

struct LDL_Font
{
	LDL_Result* Result;
	FT_Library  Library;
	FT_Face     Face;
};

LDL_Font* LDL_FontLoad(LDL_Result* result, const char* path, int size)
{
	LDL_Font* font;

	if (!path) 
	{
		LDL_ResultAddMessage(result, "LDL_FontLoad: The font path is NULL");
		return NULL;
	}

	font = (LDL_Font*)malloc(sizeof(LDL_Font));
	if (!font) 
	{
		LDL_ResultAddMessage(result, "LDL_FontLoad: Memory allocation error");
		return NULL;
	}

	if (FT_Init_FreeType(&font->Library)) 
	{
		free(font);
		LDL_ResultAddMessage(result, "LDL_FontLoad: Couldn't initialize FreeType");
		return NULL;
	}

	if (FT_New_Face(font->Library, path, 0, &font->Face))
	{
		FT_Done_FreeType(font->Library);
		free(font);
		LDL_ResultAddMessage(result, "LDL_FontLoad: Font loading error %s", path);
		return NULL;
	}

	FT_Set_Pixel_Sizes(font->Face, 0, size);

	return font;
}

void LDL_FontDestroy(LDL_Font* font) 
{
	if (font) 
	{
		FT_Done_Face(font->Face);
		FT_Done_FreeType(font->Library);
		free(font);
	}
}

struct LDL_Rasterizer
{
	LDL_Result* result;
	uint8_t*    pixels;
	LDL_Vec2i   size;
};

LDL_Rasterizer* LDL_RasterizerCreate(LDL_Result* result)
{
	LDL_Rasterizer* rasterizer = (LDL_Rasterizer*)malloc(sizeof(LDL_Rasterizer));

	if (rasterizer)
	{
		rasterizer->result = result;
		rasterizer->pixels = NULL;
		rasterizer->size   = LDL_GetVec2i(0, 0);

		return rasterizer;
	}

	return NULL;
}

void LDL_RasterizerDestroy(LDL_Rasterizer* rasterizer)
{
	if (rasterizer)
	{
		if (rasterizer->pixels)
		{
			free(rasterizer->pixels);
		}

		free(rasterizer);
	}
}

void LDL_RasterizerClear(LDL_Rasterizer* rasterizer)
{
	if (rasterizer)
	{
		if (rasterizer->pixels)
		{
			free(rasterizer->pixels);
		}

		rasterizer->pixels = NULL;
		rasterizer->size   = LDL_GetVec2i(0, 0);
	}
}

void LDL_RasterizerText(LDL_Rasterizer* rasterizer, LDL_Font* font, LDL_Color color, const char* utf8_text)
{
	int total_width = 0, max_bearing_y = 0, max_descent = 0, total_height = 0;
	int current_x = 0;
	const char* p;

	if (!font || !utf8_text)
	{
		LDL_ResultAddMessage(rasterizer->result, "LDL_TextRender: Указатель на шрифт или текст равен NULL");
		return;
	}

	p = utf8_text;

	while (*p)
	{
		uint32_t code = LDL_Utf8Decode(&p);
		if (code == 0) continue;
		if (FT_Load_Char(font->Face, code, FT_LOAD_RENDER)) continue;

		total_width += font->Face->glyph->advance.x >> 6;
		if (font->Face->glyph->bitmap_top > max_bearing_y)
		{
			max_bearing_y = font->Face->glyph->bitmap_top;
		}

		int descent = font->Face->glyph->bitmap.rows - font->Face->glyph->bitmap_top;
		if (descent > max_descent)
		{
			max_descent = descent;
		}
	}

	total_height = max_bearing_y + max_descent;
	if (total_width == 0 || total_height == 0)
	{
		LDL_ResultAddMessage(rasterizer->result, "LDL_TextRender: Сгенерирована пустая строка");
		return;
	}

	LDL_RasterizerClear(rasterizer);

	rasterizer->size.x = total_width;
	rasterizer->size.y = total_height;
	rasterizer->pixels = (uint8_t*)calloc(total_width * total_height * 4, 1);

	p = utf8_text;

	while (*p)
	{
		uint32_t code = LDL_Utf8Decode(&p);

		if (code == 0)
		{
			continue;
		}

		if (FT_Load_Char(font->Face, code, FT_LOAD_RENDER))
		{
			continue;
		}

		FT_Bitmap bitmap = font->Face->glyph->bitmap;
		int bearing_x = font->Face->glyph->bitmap_left;
		int start_y = max_bearing_y - font->Face->glyph->bitmap_top;
		int row, col;

		for (row = 0; row < bitmap.rows; row++)
		{
			for (col = 0; col < bitmap.width; col++)
			{
				uint8_t alpha = bitmap.buffer[row * bitmap.width + col];

				if (alpha == 0) continue;

				int target_x = current_x + bearing_x + col;
				int target_y = start_y + row;

				if (target_x >= total_width || target_y >= total_height || target_x < 0 || target_y < 0)
				{
					continue;
				}

				int idx = (target_y * total_width + target_x) * 4;
				rasterizer->pixels[idx + 0] = color.r;
				rasterizer->pixels[idx + 1] = color.g;
				rasterizer->pixels[idx + 2] = color.b;
				rasterizer->pixels[idx + 3] = alpha;
			}
		}

		current_x += font->Face->glyph->advance.x >> 6;
	}
}

LDL_Vec2i LDL_RasterizerGetSize(LDL_Rasterizer* rasterizer)
{
	return rasterizer ? rasterizer->size : LDL_GetVec2i(0, 0);
}

uint8_t* LDL_RasterizerGetPixels(LDL_Rasterizer* rasterizer)
{
	return rasterizer ? rasterizer->pixels : NULL;
}

uint8_t LDL_RasterizerGetPixelFormat(LDL_Rasterizer* rasterizer)
{
	return LDL_PixelFormatRGBA32;
}
