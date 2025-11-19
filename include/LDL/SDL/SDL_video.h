// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_video_h
#define LDL_APIs_SDL_SDL_video_h

#include <LDL/SDL/SDL_config.h>
#include <LDL/SDL/SDL_stdinc.h>

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

typedef struct SDL_Surface SDL_Surface;

#define SDL_ANYFORMAT	(0x10000000)  /**< Allow any video depth/pixel-format */
#define SDL_HWPALETTE	(0x20000000)  /**< Surface has exclusive palette */
#define SDL_DOUBLEBUF	(0x40000000)  /**< Set up double-buffered video mode */
#define SDL_FULLSCREEN	(0x80000000)  /**< Surface is a full screen display */
#define SDL_OPENGL      (0x00000002)  /**< Create an OpenGL rendering context */
#define SDL_OPENGLBLIT	(0x0000000A)  /**< Create an OpenGL rendering context and use it for blitting */
#define SDL_RESIZABLE	(0x00000010)  /**< This video mode may be resized */
#define SDL_NOFRAME	    (0x00000020)  /**< No window caption or edge frame */

extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);
extern SDL_DECLSPEC int          SDLCALL SDL_Flip(SDL_Surface* screen);
extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_CreateRGBSurfaceFrom(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_CreateRGBSurfaceFromPixels(size_t pixelFormat, void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
extern SDL_DECLSPEC void         SDLCALL SDL_FreeSurface(SDL_Surface* surface);
extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_LoadBMP(const char* path);
extern SDL_DECLSPEC int          SDLCALL SDL_BlitSurface(SDL_Surface* src, SDL_Rect* srcRect, SDL_Surface* dst, SDL_Rect* dstRect);

extern SDL_DECLSPEC void         SDLCALL SDL_WM_SetCaption(const char* title, const char* icon);

#ifdef __cplusplus
}
#endif

#endif
