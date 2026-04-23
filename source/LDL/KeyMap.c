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

#include <LDL/KeyMap.h>

void LDL_KeyMapInit(LDL_KeyMap* keyMap, uint32_t code, uint8_t key)
{
	if (keyMap)
	{
		keyMap->Code = code;
		keyMap->Key  = key;
	}
}

uint8_t LDL_KeyMapGetKey(LDL_KeyMap* keyMap)
{
	if (keyMap)
	{
		return keyMap->Key;
	}

	return 0;
}

uint32_t LDL_KeyMapGetCode(LDL_KeyMap* keyMap)
{
	if (keyMap)
	{
		return keyMap->Code;
	}

	return 0;
}
