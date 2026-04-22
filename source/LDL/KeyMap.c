
#include <LDL/KeyMap.h>

void LDL_KeyMapInit(LDL_KeyMap* keyMap, uint32_t code, uint8_t key)
{
	keyMap->Code = code;
	keyMap->Key  = key;
}

uint8_t LDL_KeyMapGetKey(LDL_KeyMap* keyMap)
{
	return keyMap->Key;
}

uint8_t LDL_KeyMapGetCode(LDL_KeyMap* keyMap)
{
	return keyMap->Code;
}
