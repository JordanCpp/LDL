
#ifndef SDL3_SDL_init_h
#define SDL3_SDL_init_h

#include <SDL3/SDL_stdinc.h>

typedef Uint32 SDL_InitFlags;

bool SDL_Init(SDL_InitFlags flags);
void SDL_Quit(void);

#endif
