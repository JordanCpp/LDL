// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_video_h
#define LDL_APIs_SDL_SDL_video_h

#include <LDL/APIs/SDL/SDL_config.h>
#include <LDL/APIs/SDL/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

#define SDL_ALPHA_OPAQUE      (255)
#define SDL_ALPHA_TRANSPARENT (0)

typedef struct SDL_Rect 
{
	Sint16 x, y;
	Uint16 w, h;
} SDL_Rect;

typedef struct SDL_Color 
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 unused;
} SDL_Color;


typedef struct SDL_Palette 
{
	int        ncolors;
	SDL_Color* colors;
} SDL_Palette;

typedef struct SDL_PixelFormat 
{
    SDL_Palette* palette;
	Uint8  BitsPerPixel;
	Uint8  BytesPerPixel;
	Uint8  Rloss;
	Uint8  Gloss;
	Uint8  Bloss;
	Uint8  Aloss;
	Uint8  Rshift;
	Uint8  Gshift;
	Uint8  Bshift;
	Uint8  Ashift;
	Uint32 Rmask;
	Uint32 Gmask;
	Uint32 Bmask;
	Uint32 Amask;
	Uint32 colorkey;
	Uint8  alpha;
} SDL_PixelFormat;

typedef struct SDL_Surface 
{
	Uint32           flags;
	SDL_PixelFormat* format;
	int              w;
	int              h;
	Uint16           pitch;
	void*            pixels;
} SDL_Surface;

extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

#ifdef __cplusplus
}
#endif

#endif
