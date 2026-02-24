// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Events/Event.hpp>
#include <LDLC/LDL_Events.h>

int main()
{
	LDL_TEST_EQUAL(sizeof(LDL_Event) == sizeof(LDL::Event));

	LDL_TEST_EQUAL(sizeof(LDL_EventQuit)        == sizeof(LDL::Quit));
	LDL_TEST_EQUAL(sizeof(LDL_EventMouse)       == sizeof(LDL::Mouse));
	LDL_TEST_EQUAL(sizeof(LDL_EventResize)      == sizeof(LDL::Resize));
	LDL_TEST_EQUAL(sizeof(LDL_EventKeyboard)    == sizeof(LDL::Keyboard));
	LDL_TEST_EQUAL(sizeof(LDL_EventGainedFocus) == sizeof(LDL::GainedFocus));
	LDL_TEST_EQUAL(sizeof(LDL_EventLostFocus)   == sizeof(LDL::LostFocus));

	return 0;
}
