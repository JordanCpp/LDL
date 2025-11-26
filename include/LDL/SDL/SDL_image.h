// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_SDL_SDL_image_h
#define LDL_SDL_SDL_image_h

#include <LDL/SDL/video.h>

#ifdef __cplusplus
extern "C" {
#endif 

extern SDL_DECLSPEC SDL_Surface* SDLCALL IMG_Load(const char* file);

#ifdef __cplusplus
}
#endif

#endif
