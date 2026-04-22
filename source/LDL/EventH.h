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

#ifndef LDL_EventH_H
#define LDL_EventH_H

#include <LDL/EventQ.h>

typedef struct LDL_EventHandler
{
	bool           Running;
	LDL_EventQueue Queue;
} LDL_EventHandler;

void LDL_EventHandlerInit(LDL_EventHandler* eventHandler);
bool LDL_EventHandlerEmpty(LDL_EventHandler* eventHandler);
void LDL_EventHandlerPush(LDL_EventHandler* eventHandler, const LDL_Event* event);
bool LDL_EventHandlerPop(LDL_EventHandler* eventHandler, LDL_Event* event);
bool LDL_EventHandlerRunning(LDL_EventHandler* eventHandler);
void LDL_EventHandlerStop(LDL_EventHandler* eventHandler);

#endif
