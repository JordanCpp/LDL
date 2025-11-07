// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_main_h
#define SDL3_SDL_main_h

#include <SDL3/SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(SDL_MAIN_USE_CALLBACKS)

    extern SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]);
    extern SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event);
    extern SDL_AppResult SDL_AppIterate(void* appstate);
    extern void SDL_AppQuit(void* appstate, SDL_AppResult result);

    int main(int argc, char* argv[])
    {
        SDL_AppResult result = SDL_AppInit(NULL, argc, argv);

        if (result != SDL_APP_FAILURE)
        {
            SDL_Event event;

            while (SDL_AppEvent(NULL, &event) != SDL_APP_SUCCESS)
            {
                while (SDL_PollEvent(&event))
                {
                }

                SDL_AppIterate(NULL);
            }

            SDL_AppQuit(NULL, SDL_APP_FAILURE);
        }

        return result;
    }

#endif

#ifdef __cplusplus
}
#endif

#endif
