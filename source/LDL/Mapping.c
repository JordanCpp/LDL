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

#include <LDL/Enums.h>
#include <LDL/Mapping.h>

void LDL_KeyMappingInit(LDL_KeyMapping* keyMapping)
{
	size_t i;

	if (keyMapping)
	{
		for (i = 0; i < LDL_KeyMappingMax; i++)
		{
			LDL_KeyMapInit(&keyMapping->Table[i], 0, 0);
		}

		keyMapping->Current = 0;
	}
}

void LDL_KeyMappingAdd(LDL_KeyMapping* keyMapping, uint32_t code, uint8_t key)
{
	if (keyMapping && keyMapping->Current < LDL_KeyMappingMax)
	{
		LDL_KeyMapInit(&keyMapping->Table[keyMapping->Current], code, key);
		keyMapping->Current++;
	}
}

uint8_t LDL_KeyMappingFindKey(const LDL_KeyMapping* keyMapping, uint32_t scanCode)
{
	size_t i;

	if (keyMapping)
	{
		for (i = 0; i < keyMapping->Current; i++)
		{
			if (keyMapping->Table[i].Code == scanCode)
			{
				return keyMapping->Table[i].Key;
			}
		}
	}

	return LDL_KeyUnknown;
}
