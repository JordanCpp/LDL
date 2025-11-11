// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_events_h
#define LDL_APIs_SDL3_SDL_events_h

#include <LDL/APIs/SDL/SDL_config.h>

#ifdef __cplusplus
extern "C" {
#endif 
   
typedef enum 
{
    SDL_NOEVENT,
    SDL_MOUSEMOTION,
    SDL_QUIT
} SDL_EventType;

typedef struct SDL_QuitEvent 
{
    Uint8 type;
} SDL_QuitEvent;

typedef struct SDL_MouseMotionEvent 
{
	Uint8 type;
	Uint8 which;
	Uint8 state;
	Uint16 x, y;
	Sint16 xrel;
	Sint16 yrel;
} SDL_MouseMotionEvent;

typedef union SDL_Event
{
    Uint8                type;
    SDL_QuitEvent        quit;
	SDL_MouseMotionEvent motion;
} SDL_Event;

extern SDL_DECLSPEC bool SDLCALL SDL_PollEvent(SDL_Event* event);

#ifdef __cplusplus
}
#endif

#endif
