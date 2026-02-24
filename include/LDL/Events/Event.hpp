// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Events_Event_hpp
#define LDL_Events_Event_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Events/Mouse.hpp>
#include <LDL/Events/Quit.hpp>
#include <LDL/Events/Resize.hpp>
#include <LDL/Events/Keyboard.hpp>
#include <LDL/Events/GainedFocus.hpp>
#include <LDL/Events/LostFocus.hpp>

namespace LDL
{
	class Event
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

		union
		{
			uint8_t          Type;
			LDL::Quit        Quit;
			LDL::Mouse       Mouse;
			LDL::Resize      Resize;
			LDL::Keyboard    Keyboard;
			LDL::GainedFocus GainedFocus;
			LDL::LostFocus   LostFocus;
		};

		bool IsKeyPressed(uint8_t key)
		{
			return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == ButtonState::Pressed);
		}

		bool IsKeyReleased(uint8_t key)
		{
			return (Type == IsKeyboard && Keyboard.Key == key && Keyboard.State == ButtonState::Released);
		}

		bool IsMousePressed(uint8_t key)
		{
			return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == ButtonState::Pressed);
		}

		bool IsMouseReleased(uint8_t key)
		{
			return (Type == IsMouseClick && Mouse.Button == key && Mouse.State == ButtonState::Released);
		}
	};
}

#endif
