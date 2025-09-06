// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_events_h
#define SDL3_SDL_events_h

#include <LDL/Config.hpp>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_video.h>

typedef enum SDL_EventType
{
    SDL_EVENT_QUIT         = 0x100,
    SDL_EVENT_MOUSE_MOTION = 0x400
} SDL_EventType;

typedef union SDL_QuitEvent
{
    Uint32 type;
} SDL_QuitEvent;

typedef struct SDL_MouseMotionEvent
{
    SDL_EventType        type;      /**< SDL_EVENT_MOUSE_MOTION */
    Uint32               reserved;
    Uint64               timestamp; /**< In nanoseconds, populated using SDL_GetTicksNS() */
    SDL_WindowID         windowID;  /**< The window with mouse focus, if any */
    SDL_MouseID          which;     /**< The mouse instance id in relative mode, SDL_TOUCH_MOUSEID for touch events, or 0 */
    SDL_MouseButtonFlags state;     /**< The current button state */
    float                x;         /**< X coordinate, relative to window */
    float                y;         /**< Y coordinate, relative to window */
    float                xrel;      /**< The relative motion in the X direction */
    float                yrel;      /**< The relative motion in the Y direction */
} SDL_MouseMotionEvent;

typedef union SDL_Event
{
    Uint32               type;
    SDL_QuitEvent        quit;
    SDL_MouseMotionEvent motion;
} SDL_Event;

LDL_LIBRARY bool SDL_PollEvent(SDL_Event* event);

#endif
