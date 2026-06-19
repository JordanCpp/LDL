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

#ifndef LDL_Renders_Soft_BufSoft_H
#define LDL_Renders_Soft_BufSoft_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>

typedef struct LDL_LineSoftware
{
    uint8_t   Layer;
    LDL_Color Color;
    LDL_Vec2i First;
    LDL_Vec2i Last;
} LDL_LineSoftware;

typedef struct LDL_FillSoftware
{
    uint8_t   Layer;
    LDL_Color Color;
    LDL_Vec2i First;
    LDL_Vec2i Last;
} LDL_FillSoftware;

typedef struct LDL_TextureSoftware
{
    uint8_t   Layer;
    uint8_t*  dstPixels;
    LDL_Vec2i dstArea;
    LDL_Vec2i dstPos;
    LDL_Vec2i dstSize;
    uint8_t*  srcPixels;
    LDL_Vec2i srcArea;
    LDL_Vec2i srcPos;
    LDL_Vec2i srcSize;
} LDL_TextureSoftware;

typedef struct LDL_CommandSoftware
{
    size_t            BatchCount;
} LDL_CommandSoftware;

typedef struct LDL_BufferSoftware
{
    size_t            BatchCount;
} LDL_BufferSoftware;

#endif
