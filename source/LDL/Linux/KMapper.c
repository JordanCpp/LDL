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
#include <LDL/Linux/KMapper.h>

void LDL_KeyMapperInit(LDL_KeyMapper* keyMapper)
{
    if (keyMapper)
    {
        LDL_KeyMappingInit(&keyMapper->Mapping);
    }
}

uint8_t LDL_KeyMapperConvertKey(LDL_KeyMapper* keyMapper, uint32_t key)
{
    if (keyMapper)
    {
        return LDL_KeyMappingFindKey(&keyMapper->Mapping, key);
    }

    return LDL_KeyUnknown;
}
