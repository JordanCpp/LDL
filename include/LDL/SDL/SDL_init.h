// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_init_h
#define LDL_APIs_SDL_SDL_init_h

#include <LDL/SDL/SDL_config.h>
#include <LDL/SDL/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

#define	SDL_INIT_TIMER		  0x00000001
#define SDL_INIT_AUDIO		  0x00000010
#define SDL_INIT_VIDEO		  0x00000020
#define SDL_INIT_CDROM		  0x00000100
#define SDL_INIT_JOYSTICK	  0x00000200
#define SDL_INIT_NOPARACHUTE  0x00100000
#define SDL_INIT_EVENTTHREAD  0x01000000
#define SDL_INIT_EVERYTHING	  0x0000FFFF

extern SDL_DECLSPEC int  SDLCALL SDL_Init(Uint32 flags);
extern SDL_DECLSPEC void SDLCALL SDL_Quit(void);

#ifdef __cplusplus
}
#endif

#endif
