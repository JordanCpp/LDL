// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Events/Event.hpp>
#include <LDLC/LDL_Events.h>

int main()
{
	LDL_TEST_EQUAL(sizeof(LDL_Event) == sizeof(LDL::Events::Event));

	LDL_TEST_EQUAL(sizeof(LDL_EventQuit)        == sizeof(LDL::Events::Quit));
	LDL_TEST_EQUAL(sizeof(LDL_EventMouse)       == sizeof(LDL::Events::Mouse));
	LDL_TEST_EQUAL(sizeof(LDL_EventResize)      == sizeof(LDL::Events::Resize));
	LDL_TEST_EQUAL(sizeof(LDL_EventKeyboard)    == sizeof(LDL::Events::Keyboard));
	LDL_TEST_EQUAL(sizeof(LDL_EventGainedFocus) == sizeof(LDL::Events::GainedFocus));
	LDL_TEST_EQUAL(sizeof(LDL_EventLostFocus)   == sizeof(LDL::Events::LostFocus));

	return 0;
}
