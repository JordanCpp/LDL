
#ifndef LDL_KeyMap_H
#define LDL_KeyMap_H

#include <LDL/Types.h>

typedef struct LDL_KeyMap
{
	uint8_t  Key;
	uint32_t Code;
} LDL_KeyMap;

void LDL_KeyMapInit(LDL_KeyMap* keyMap, uint32_t code, uint8_t key);
uint8_t LDL_KeyMapGetKey(LDL_KeyMap* keyMap);
uint8_t LDL_KeyMapGetCode(LDL_KeyMap* keyMap);

#endif
