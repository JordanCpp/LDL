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

#include <LDL/Events.h>

bool LDL_EventIsKeyPressed(LDL_Event* event, uint8_t key)
{
	return (event->Type == LDL_EventIsKeyboard && event->Keyboard.Key == key && event->Keyboard.State == LDL_ButtonStatePressed);
}

bool LDL_EventIsKeyReleased(LDL_Event* event, uint8_t key)
{
	return (event->Type == LDL_EventIsKeyboard && event->Keyboard.Key == key && event->Keyboard.State == LDL_ButtonStateReleased);

}

bool LDL_EventIsMousePressed(LDL_Event* event, uint8_t key)
{
	return (event->Type == LDL_EventIsMouseClick && event->Mouse.Button == key && event->Mouse.State == LDL_ButtonStatePressed);
}

bool LDL_EventIsMouseReleased(LDL_Event* event, uint8_t key)
{
	return (event->Type == LDL_EventIsMouseClick && event->Mouse.Button == key && event->Mouse.State == LDL_ButtonStateReleased);
}
