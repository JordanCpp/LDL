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
