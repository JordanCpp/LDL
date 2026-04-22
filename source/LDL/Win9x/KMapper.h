
#ifndef LDL_Win9x_KMapper_H
#define LDL_Win9x_KMapper_H

#include <LDL/Mapping.h>

typedef struct LDL_KeyMapper
{
	LDL_KeyMapping Mapping;
} LDL_KeyMapper;

void LDL_KeyMapperInit(LDL_KeyMapper* keyMapper);
uint8_t LDL_KeyMapperConvertKey(LDL_KeyMapper* keyMapper, size_t key);

#endif
