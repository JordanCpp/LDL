
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
