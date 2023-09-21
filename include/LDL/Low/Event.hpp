#ifndef LDL_Low_Events_hpp
#define LDL_Low_Events_hpp

#include <LDL/Low/Types.hpp>
#include <LDL/Low/Enums.hpp>

class LDL_Events
{
public:
	enum
	{
		IsQuit = 1,
		IsMouseMove,
		IsMouseClick,
		IsResize,
		IsKeyboard,
		IsGainedFocus,
		IsLostFocus,
		IsMouseScroll
	};
};

class LDL_EventQuit
{
public:
	uint8_t Type;
};

class LDL_EventResize
{
public:
	uint8_t Type;
	size_t Width;
	size_t Height;
};

class LDL_EventMouse
{
public:
	uint8_t Type;
	uint8_t State;
	uint8_t Button;
	size_t  PosX;
	size_t  PosY;
	size_t  Scroll;
	size_t  Delta;
};

class LDL_EventLostFocus
{
public:
	uint8_t Type;
};

class LDL_EventKeyboard
{
public:
	uint8_t Type;
	uint8_t State;
	size_t Key;
};

class LDL_EventGainedFocus
{
public:
	uint8_t Type;
};

class LDL_Event
{
public:
	union
	{
		uint8_t              Type;
		LDL_EventQuit        Quit;
		LDL_EventResize      Resize;
		LDL_EventMouse       Mouse;
		LDL_EventLostFocus   LostFocus;
		LDL_EventKeyboard    Keyboard;
		LDL_EventGainedFocus GainedFocus;
	};

	bool IsKeyPressed(size_t key)
	{
		return (Type == LDL_Events::IsKeyboard && Keyboard.Key == key && Keyboard.State == LDL_ButtonState::Pressed);
	}

	bool IsKeyReleased(size_t key)
	{
		return (Type == LDL_Events::IsKeyboard && Keyboard.Key == key && Keyboard.State == LDL_ButtonState::Released);
	}

	bool IsMousePressed(size_t key)
	{
		return (Type == LDL_Events::IsMouseClick && Mouse.Button == key && Mouse.State == LDL_ButtonState::Pressed);
	}

	bool IsMouseReleased(size_t key)
	{
		return (Type == LDL_Events::IsMouseClick && Mouse.Button == key && Mouse.State == LDL_ButtonState::Released);
	}
};

#endif
