#ifndef LDL_Events_h
#define LDL_Events_h

#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LDL_EventIsQuit       (1)
#define LDL_EventIsMouseMove  (2)
#define LDL_EventIsMouseClick (3)
#define	LDL_EventIsResize     (4)
#define LDL_EventIsKeyboard   (5)

typedef struct LDL_EventQuit
{
	uint8_t Type;
} LDL_EventQuit;

typedef struct LDL_EventResize
{
	uint8_t Type;
	size_t  Width;
	size_t  Height;
} LDL_EventResize;

typedef struct LDL_EventKeyboard
{
	uint8_t Type;
	uint8_t State;
	size_t  Key;
} LDL_EventKeyboard;

typedef struct LDL_EventMouse
{
	uint8_t Type;
	size_t  PosX;
	size_t  PosY;
	uint8_t State;
	uint8_t Button;
	size_t  Scroll;
	size_t  Delta;
} LDL_EventMouse;

typedef struct LDL_EventGainedFocus
{
	uint8_t Type;
} LDL_EventGainedFocus;

typedef struct LDL_EventLostFocus
{
	uint8_t Type;
} LDL_EventLostFocus;

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

#ifdef __cplusplus
}
#endif

#endif