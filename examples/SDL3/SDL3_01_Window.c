// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#define SDL_MAIN_USE_CALLBACKS 1
#include <LDL/SDL3/SDL.h>
#include <LDL/SDL3/SDL_main.h> 

static SDL_Window* window     = NULL;
static SDL_Renderer* renderer = NULL;

#define WINDOW_WIDTH  (640)
#define WINDOW_HEIGTH (480)

/********************************************************************************************************************************
                                                            Init
********************************************************************************************************************************/
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("Init error: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    window = SDL_CreateWindow(__FILE__, WINDOW_WIDTH, WINDOW_HEIGTH, 0);
    if (window == NULL)
    {
        printf("Create window error: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        printf("Create renderer error: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

/********************************************************************************************************************************
                                                            Event
********************************************************************************************************************************/
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

/********************************************************************************************************************************
                                                           Iterate
********************************************************************************************************************************/
SDL_AppResult SDL_AppIterate(void* appstate)
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/********************************************************************************************************************************
                                                            Quit
********************************************************************************************************************************/
void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
