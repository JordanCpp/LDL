// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/APIs/SDL/SDL.h>

void ErrorShow(const char* error)
{
    printf("SDL error: %s \n", error);
}

void ColorScreen(SDL_Surface* surface, Uint8 r, Uint8 g, Uint8 b)
{
    size_t bpp = surface->format->BytesPerPixel;

    if (bpp == 3 || bpp == 4)
    {
        size_t total = surface->w * surface->h * bpp;
        Uint8* pixels = surface->pixels;

        for (size_t i = 0; i < total; i += bpp)
        {
            pixels[i + 0] = r;
            pixels[i + 1] = g;
            pixels[i + 2] = b;
        }
    }
}

int main(int argc, char* argv[])
{
    SDL_Surface* screen = NULL;
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

    ColorScreen(screen, 237, 28, 36);

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_Flip(screen);
    }

    SDL_FreeSurface(screen);
    SDL_Quit();

    return 0;
}
