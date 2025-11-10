// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Surface* screen = NULL;
    SDL_Event event;
    bool running = true;

    screen = SDL_SetVideoMode(640, 480, 24, 0);

    Uint8* pixels = screen->pixels;

    if (screen->format->BytesPerPixel == 3)
    {
        for (size_t i = 0; i < screen->w * screen->h; i++)
        {
            pixels[i + 0] = 237;
            pixels[i + 1] = 28;
            pixels[i + 2] = 36;
        }
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

        SDL_Flip(screen);
    }

    return 0;
}
