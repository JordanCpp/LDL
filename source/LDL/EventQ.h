
#ifndef LDL_EventQ_H
#define LDL_EventQ_H

#include <LDL/Types.h>
#include <LDL/Events.h>

enum
{
    LDL_EventQueueMax = 256
};

typedef struct LDL_EventQueue
{
    size_t    Head;
    size_t    Tail;
    size_t    Length;
    size_t    Capacity;
    LDL_Event Content[LDL_EventQueueMax];
} LDL_EventQueue;

void LDL_EventQueueInit(LDL_EventQueue* eventQueue);
bool LDL_EventQueueEmpty(LDL_EventQueue* eventQueue);
bool LDL_EventQueueFull(LDL_EventQueue* eventQueue);
size_t LDL_EventQueueSize(LDL_EventQueue* eventQueue);
size_t LDL_EventQueueCapacity(LDL_EventQueue* eventQueue);
size_t LDL_EventQueueNext(LDL_EventQueue* eventQueue, size_t pos);
bool LDL_EventQueueDequeue(LDL_EventQueue* eventQueue, LDL_Event* element);
void LDL_EventQueueEnqueue(LDL_EventQueue* eventQueue, const LDL_Event* element);
LDL_Event* LDL_EventQueuefront(LDL_EventQueue* eventQueue);

#endif
