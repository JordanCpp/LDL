// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Events_hpp
#define LDL_Events_hpp

#include <LDL/Types.hpp>
#include <LDL/Enums.hpp>

class LDL_GainedFocus
{
public:
	uint8_t Type;
};

class LDL_Keyboard
{
public:
	uint8_t Type;
	uint8_t State;
	uint8_t Key;
};

class LDL_LostFocus
{
public:
	uint8_t Type;
};

class LDL_Mouse
{
public:
	uint8_t Type;
	size_t  PosX;
	size_t  PosY;
	size_t  PosRelX;
	size_t  PosRelY;
	uint8_t State;
	uint8_t Button;
	size_t  Scroll;
	size_t  Delta;
};

class LDL_Quit
{
public:
	uint8_t Type;
};

class LDL_Resize
{
public:
	uint8_t Type;
	size_t Width;
	size_t Height;
};

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

class LDL_Event
{
public:
	union
	{
		uint8_t Type;
		LDL_Quit        Quit;
	    LDL_Mouse       Mouse;
		LDL_Resize      Resize;
		LDL_Keyboard    Keyboard;
		LDL_GainedFocus GainedFocus;
		LDL_LostFocus   LostFocus;
	};

	bool IsKeyPressed(uint8_t key)
	{
		return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == LDL_ButtonState::Pressed);
	}

	bool IsKeyReleased(uint8_t key)
	{
		return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == LDL_ButtonState::Released);

	}

	bool IsMousePressed(uint8_t key)
	{
		return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == LDL_ButtonState::Pressed);
	}

	bool IsMouseReleased(uint8_t key)
	{
		return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == LDL_ButtonState::Released);
	}
};

#endif
