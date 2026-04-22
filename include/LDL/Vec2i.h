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

#ifndef LDL_Vec2i_H
#define LDL_Vec2i_H

#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Vec2i
{
	int x;
	int y;

} LDL_Vec2i;

LDL_LIBRARY LDL_Vec2i LDL_GetVec2i(int x, int y);

#ifdef __cplusplus
}
#endif 

#endif
