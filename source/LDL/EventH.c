
#include <LDL/EventH.h>

void LDL_EventHandlerInit(LDL_EventHandler* eventHandler)
{
    LDL_EventQueueInit(&eventHandler->Queue);

    eventHandler->Running = true;
}

bool LDL_EventHandlerEmpty(LDL_EventHandler* eventHandler)
{
    return LDL_EventQueueEmpty(&eventHandler->Queue);
}

void LDL_EventHandlerPush(LDL_EventHandler* eventHandler, const LDL_Event* event)
{
    LDL_EventQueueEnqueue(&eventHandler->Queue, event);
}

bool LDL_EventHandlerPop(LDL_EventHandler* eventHandler, LDL_Event* event)
{
    if (!LDL_EventHandlerEmpty(eventHandler))
    {
        LDL_EventQueueDequeue(&eventHandler->Queue, event);

        return true;
    }

    return false;
}

bool LDL_EventHandlerRunning(LDL_EventHandler* eventHandler)
{
    return eventHandler->Running;
}

void LDL_EventHandlerStop(LDL_EventHandler* eventHandler)
{
    eventHandler->Running = false;
}
