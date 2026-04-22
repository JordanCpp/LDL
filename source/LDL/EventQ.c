
#include <string.h>
#include <LDL/EventQ.h>

void LDL_EventQueueInit(LDL_EventQueue* eventQueue)
{
	eventQueue->Head     = 0;
	eventQueue->Tail     = 0;
	eventQueue->Length   = 0;
	eventQueue->Capacity = LDL_EventQueueMax;
}

bool LDL_EventQueueEmpty(LDL_EventQueue* eventQueue)
{
	return eventQueue->Length == 0;
}

bool LDL_EventQueueFull(LDL_EventQueue* eventQueue)
{
	return eventQueue->Length == eventQueue->Capacity;
}

size_t LDL_EventQueueSize(LDL_EventQueue* eventQueue)
{
	return eventQueue->Length;
}

size_t LDL_EventQueueCapacity(LDL_EventQueue* eventQueue)
{
	return eventQueue->Capacity;
}

size_t LDL_EventQueueNext(LDL_EventQueue* eventQueue, size_t pos)
{
	return (pos + 1) % eventQueue->Capacity;
}

bool LDL_EventQueueDequeue(LDL_EventQueue* eventQueue, LDL_Event* element)
{
    if (!LDL_EventQueueEmpty(eventQueue))
    {
		memcpy(element, &eventQueue->Content[eventQueue->Tail], sizeof(LDL_Event));
		eventQueue->Tail = LDL_EventQueueNext(eventQueue, eventQueue->Tail);
		eventQueue->Length--;

        return true;
    }

    return false;
}

void LDL_EventQueueEnqueue(LDL_EventQueue* eventQueue, const LDL_Event* element)
{
    if (LDL_EventQueueCapacity(eventQueue) == 0)
    {
        return;
    }

    eventQueue->Head = LDL_EventQueueNext(eventQueue, eventQueue->Head);
    memcpy(&eventQueue->Content[eventQueue->Head], element, sizeof(LDL_Event));

    if (LDL_EventQueueFull(eventQueue))
    {
        eventQueue->Tail = LDL_EventQueueNext(eventQueue, eventQueue->Tail);
    }
    else
    {
        eventQueue->Length++;
    }
}

LDL_Event* LDL_EventQueuefront(LDL_EventQueue* eventQueue)
{
    return LDL_EventQueueEmpty(eventQueue) ? NULL : &eventQueue->Content[eventQueue->Tail];
}
