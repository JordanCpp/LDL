
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
