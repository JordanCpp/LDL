// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/SDL/SDL.h>
#include <LDL/SDL/SDL_image.h>

void ErrorShow(const char* error)
{
    printf("SDL error: %s \n", error);
}

int main(int argc, char* argv[])
{
    SDL_Surface* screen = NULL;
    SDL_Surface* image  = NULL;
    bool running        = true;
    SDL_Event event;

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        ErrorShow(SDL_GetError());
        return -1;
    }

    screen = SDL_SetVideoMode(640, 480, 24, 0);
    if (screen == NULL)
    {
        ErrorShow(SDL_GetError());
        return -1;
    }

    SDL_WM_SetCaption(__FILE__, NULL);

    image = IMG_Load("data/testyuv.png");
    if (image == NULL)
    {
        ErrorShow(SDL_GetError());
        return -1;
    }

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_BlitSurface(image, NULL, screen, NULL);

        SDL_Flip(screen);
    }

    SDL_FreeSurface(image);
    SDL_FreeSurface(screen);
    SDL_Quit();

    return 0;
}
