// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_stdinc_h
#define LDL_APIs_SDL_SDL_stdinc_h

#include <LDL/std/stdbool.hpp>
#include <LDL/std/stdint.hpp>

#ifdef __cplusplus
extern "C" {
#endif 

typedef enum 
{
	SDL_FALSE = 0,
	SDL_TRUE  = 1
} SDL_bool;

typedef int8_t  Sint8;
typedef uint8_t Uint8;

typedef int16_t  Sint16;
typedef uint16_t Uint16;

typedef int32_t  Sint32;
typedef uint32_t Uint32;

typedef int64_t  Sint64;
typedef uint64_t Uint64;

#ifdef __cplusplus
}
#endif

#endif
