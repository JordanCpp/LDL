// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_rwops_h
#define LDL_APIs_SDL_SDL_rwops_h

#include <LDL/SDL/SDL_config.h>
#include <LDL/Types.hpp>

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct SDL_RWops SDL_RWops;

#define RW_SEEK_SET  (0)
#define	RW_SEEK_CUR  (1)
#define	RW_SEEK_END  (2)

extern SDL_DECLSPEC SDL_RWops* SDLCALL SDL_RWFromFile(const char* file, const char* mode);
extern SDL_DECLSPEC SDL_RWops* SDLCALL SDL_RWFromMem(void* mem, int size);
extern SDL_DECLSPEC void       SDLCALL SDL_RWclose(SDL_RWops* context);
extern SDL_DECLSPEC int        SDLCALL SDL_RWseek(SDL_RWops* context, int offset, int whence);
extern SDL_DECLSPEC int        SDLCALL SDL_RWread(SDL_RWops* context, void* ptr, int size, int maxnum);
extern SDL_DECLSPEC int        SDLCALL SDL_RWwrite(SDL_RWops* context, const void* ptr, int size, int num);
extern SDL_DECLSPEC int        SDLCALL SDL_RWtell(SDL_RWops* context);

#ifdef __cplusplus
}
#endif

#endif
