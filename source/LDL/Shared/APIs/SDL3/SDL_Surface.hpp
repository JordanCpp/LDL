// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_SDL3_SDL_Surface_hpp
#define LDL_Shared_SDL3_SDL_Surface_hpp

#include <LDL/APIs/SDL3/SDL_surface.h>
#include <LDL/Graphics/Surface.hpp>

SDL_PixelFormat LDL_PixelFormatToSDL_PixelFormat(size_t pixelFormat);

struct SDL_SurfaceDetail : public SDL_Surface
{
private:
	LDL::Surface _surface;
public:
	SDL_SurfaceDetail(int width, int height, SDL_PixelFormat format);
	LDL::Surface& GetSurface();
};

#endif
