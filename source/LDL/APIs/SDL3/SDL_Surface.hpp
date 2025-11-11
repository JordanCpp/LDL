// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_APIs_SDL3_SDL_Surface_hpp
#define LDL_Shared_APIs_SDL3_SDL_Surface_hpp

#include <LDL/APIs/SDL3/SDL_surface.h>
#include <LDL/Graphics/Surface.hpp>

SDL_PixelFormat LDL_PixelFormatToSDL_PixelFormat(size_t pixelFormat);

struct SDL_SurfaceDetail : public SDL_Surface
{
public:
	SDL_SurfaceDetail(int width, int height, SDL_PixelFormat pixelFormat);
	SDL_SurfaceDetail(int width, int height, SDL_PixelFormat pixelFormat, uint8_t* pixels);
	LDL::Surface& GetSurface();
private:
	LDL::Surface _surface;
};

#endif
