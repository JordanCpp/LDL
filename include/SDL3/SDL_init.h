// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_init_h
#define SDL3_SDL_init_h

#include <SDL3/SDL_config.h>
#include <SDL3/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef Uint32 SDL_InitFlags;

#define SDL_INIT_AUDIO      (0x00000010u)
#define SDL_INIT_VIDEO      (0x00000020u)
#define SDL_INIT_JOYSTICK   (0x00000200u)
#define SDL_INIT_HAPTIC     (0x00001000u)
#define SDL_INIT_GAMEPAD    (0x00002000u)
#define SDL_INIT_EVENTS     (0x00004000u)
#define SDL_INIT_SENSOR     (0x00008000u)
#define SDL_INIT_CAMERA     (0x00010000u)

extern SDL_DECLSPEC bool SDLCALL SDL_Init(SDL_InitFlags flags);
extern SDL_DECLSPEC void SDLCALL SDL_Quit(void);

typedef enum SDL_AppResult
{
    SDL_APP_CONTINUE,
    SDL_APP_SUCCESS,
    SDL_APP_FAILURE
} SDL_AppResult;

#ifdef __cplusplus
}
#endif

#endif
