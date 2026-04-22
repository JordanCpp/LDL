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
