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

#ifndef LDL_Mapping_H
#define LDL_Mapping_H

#include <LDL/KeyMap.h>

enum
{
	LDL_KeyMappingMax = 256
};

typedef struct LDL_KeyMapping
{
	size_t     Current;
	LDL_KeyMap Table[LDL_KeyMappingMax];
} LDL_KeyMapping;

void LDL_KeyMappingInit(LDL_KeyMapping* keyMapping);
void LDL_KeyMappingAdd(LDL_KeyMapping* keyMapping, uint32_t code, uint8_t key);
uint8_t LDL_KeyMappingFindKey(LDL_KeyMapping* keyMapping, size_t key);

#endif
