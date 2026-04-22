/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_Events_H
#define LDL_Events_H

#include <LDL/Config.h>
#include <LDL/Types.h>
#include <LDL/Enums.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_EventGainedFocus
{
	uint8_t Type;
} LDL_EventGainedFocus;

typedef struct LDL_EventKeyboard
{
	uint8_t Type;
	uint8_t State;
	uint8_t Key;
} LDL_EventKeyboard;

typedef struct LDL_EventLostFocus
{
	uint8_t Type;
} LDL_EventLostFocus;

typedef struct LDL_EventMouse
{
	uint8_t Type;
	size_t  PosX;
	size_t  PosY;
	size_t  PosRelX;
	size_t  PosRelY;
	uint8_t State;
	uint8_t Button;
	size_t  Scroll;
	size_t  Delta;
} LDL_EventMouse;

typedef struct LDL_EventQuit
{
	uint8_t Type;
} LDL_EventQuit;

typedef struct LDL_EventResize
{
	uint8_t Type;
	size_t Width;
	size_t Height;
} LDL_EventResize;

typedef struct LDL_Event
{
	union
	{
		uint8_t              Type;
		LDL_EventQuit        Quit;
		LDL_EventMouse       Mouse;
		LDL_EventResize      Resize;
		LDL_EventKeyboard    Keyboard;
		LDL_EventGainedFocus GainedFocus;
		LDL_EventLostFocus   LostFocus;
	};
} LDL_Event;

LDL_LIBRARY bool LDL_EventIsKeyPressed(LDL_Event* event, uint8_t key);
LDL_LIBRARY bool LDL_EventIsKeyReleased(LDL_Event* event, uint8_t key);

LDL_LIBRARY bool LDL_EventIsMousePressed(LDL_Event* event, uint8_t key);
LDL_LIBRARY bool LDL_EventIsMouseReleased(LDL_Event* event, uint8_t key);

#ifdef __cplusplus
}
#endif

#endif
