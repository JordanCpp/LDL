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

#ifndef LDL_Types_H
#define LDL_Types_H

#include <stddef.h>

#if (_MSC_VER >= 1900)
    #include <stdbool.h>
#endif

#if (_MSC_VER == 1000)
    typedef int bool;
    #define true  1
    #define false 0
#elif (_MSC_VER <= 1200) && (!__cplusplus)
    #define bool  char
    #define true  1
    #define false 0
#endif

#if defined(__TURBOC__)
    #define bool  char
    #define true  1
    #define false 0
#endif

#if (_MSC_VER >= 1900 || __GNUC__)
    #include <stdint.h>
#else
typedef signed char     int8_t;
typedef unsigned char   uint8_t;

typedef signed short    int16_t;
typedef unsigned short  uint16_t;

typedef signed int      int32_t;
typedef unsigned int    uint32_t;

typedef signed int      int64_t;
typedef unsigned int    uint64_t;

typedef signed int      intptr_t;
typedef unsigned int    uintptr_t;

typedef signed int      intmax_t;
typedef signed int      uintmax_t;
#endif 

typedef void(*LDL_VoidFuncPtr)(void);

#endif
