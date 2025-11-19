// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_Surface_hpp
#define LDL_APIs_SDL3_SDL_Surface_hpp

#include <LDL/SDL/SDL_video.h>
#include <LDL/Surface.hpp>

struct SDL_SurfaceDetail : public SDL_Surface
{
public:
	SDL_SurfaceDetail(size_t pixelFormat, const LDL_Vec2u& size);
	SDL_SurfaceDetail(size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels);
	LDL_Surface& GetSurface();
	SDL_PixelFormat* GetPixelFormat();
private:
	LDL_Surface    _surface;
	SDL_PixelFormat _format;
};

#endif
