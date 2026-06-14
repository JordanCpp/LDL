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

#ifndef LDL_PixFrmt_H
#define LDL_PixFrmt_H

#include <LDL/Types.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

enum
{
    LDL_PixelFormatUnknown,
    LDL_PixelFormatRGBA32,
    LDL_PixelFormatBGRA32,
    LDL_PixelFormatRGB24,
    LDL_PixelFormatBGR24
};

LDL_LIBRARY uint8_t LDL_BytesPerPixelFromPixelFormat(size_t pixelFormat);

#ifdef __cplusplus
}
#endif 

#endif
