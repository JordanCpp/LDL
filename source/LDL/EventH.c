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

#include <LDL/EventH.h>

void LDL_EventHandlerInit(LDL_EventHandler* eventHandler)
{
    if (eventHandler)
    {
        LDL_EventQueueInit(&eventHandler->Queue);
        eventHandler->Running = true;
    }
}

bool LDL_EventHandlerEmpty(LDL_EventHandler* eventHandler)
{
    if (eventHandler)
    {
        return LDL_EventQueueEmpty(&eventHandler->Queue);
    }

    return true;
}

void LDL_EventHandlerPush(LDL_EventHandler* eventHandler, const LDL_Event* event)
{
    if (eventHandler && event)
    {
        LDL_EventQueueEnqueue(&eventHandler->Queue, event);
    }
}

bool LDL_EventHandlerPop(LDL_EventHandler* eventHandler, LDL_Event* event)
{
    if (eventHandler && event && !LDL_EventHandlerEmpty(eventHandler))
    {
        return LDL_EventQueueDequeue(&eventHandler->Queue, event);
    }

    return false;
}

bool LDL_EventHandlerRunning(LDL_EventHandler* eventHandler)
{
    if (eventHandler)
    {
        return eventHandler->Running;
    }

    return false;
}

void LDL_EventHandlerStop(LDL_EventHandler* eventHandler)
{
    if (eventHandler)
    {
        eventHandler->Running = false;
    }
}
