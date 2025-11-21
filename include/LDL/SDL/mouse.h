// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_SDL_mouse_h
#define LDL_SDL_mouse_h

#include <LDL/SDL/config.h>

#ifdef __cplusplus
extern "C" {
#endif 
   
#define SDL_BUTTON(X)		  (1 << ((X)-1))
#define SDL_BUTTON_LEFT		  (1)
#define SDL_BUTTON_MIDDLE	  (2)
#define SDL_BUTTON_RIGHT	  (3)
#define SDL_BUTTON_WHEELUP	  (4)
#define SDL_BUTTON_WHEELDOWN  (5)
#define SDL_BUTTON_X1		  (6)
#define SDL_BUTTON_X2		  (7)
#define SDL_BUTTON_LMASK	  SDL_BUTTON(SDL_BUTTON_LEFT)
#define SDL_BUTTON_MMASK	  SDL_BUTTON(SDL_BUTTON_MIDDLE)
#define SDL_BUTTON_RMASK	  SDL_BUTTON(SDL_BUTTON_RIGHT)
#define SDL_BUTTON_X1MASK	  SDL_BUTTON(SDL_BUTTON_X1)
#define SDL_BUTTON_X2MASK	  SDL_BUTTON(SDL_BUTTON_X2)

#ifdef __cplusplus
}
#endif

#endif
