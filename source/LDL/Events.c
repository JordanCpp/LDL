
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
