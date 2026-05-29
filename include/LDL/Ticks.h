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

#ifndef LDL_Ticks_H
#define LDL_Ticks_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

LDL_LIBRARY size_t LDL_Ticks();
LDL_LIBRARY void LDL_Delay(size_t count);

#ifdef __cplusplus
}
#endif 

#endif
