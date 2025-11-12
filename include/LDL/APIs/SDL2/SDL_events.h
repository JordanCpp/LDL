// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL2_SDL_events_h
#define LDL_APIs_SDL2_SDL_events_h

#include <LDL/APIs/SDL2/SDL_config.h>
#include <LDL/APIs/SDL2/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef enum SDL_EventType
{
    SDL_FIRSTEVENT = 0,
    SDL_QUIT       = 0x100
} SDL_EventType;

typedef struct SDL_QuitEvent
{
    Uint32 type;
    Uint32 timestamp;
} SDL_QuitEvent;

typedef union SDL_Event
{
    Uint32 type;
    SDL_QuitEvent quit;
} SDL_Event;

extern SDL_DECLSPEC int SDLCALL SDL_PollEvent(SDL_Event* event);

#ifdef __cplusplus
}
#endif

#endif
