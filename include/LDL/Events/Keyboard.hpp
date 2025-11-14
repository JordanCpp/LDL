// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Events_Keyboard_hpp
#define LDL_Events_Keyboard_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Enums/ButtonState.hpp>
#include <LDL/Enums/KeyboardKey.hpp>

namespace LDL
{
	class Keyboard
	{
	public:
		uint8_t Type;
		uint8_t State;
		uint8_t Key;
	};
}

#endif
