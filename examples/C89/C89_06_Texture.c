/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.h>

int Random(int min, int max)
{
    int range = max - min + 1;

    return min + rand() % range;
}

const int count = 1000;

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_2DRender* render;
    LDL_BmpLoader* loader;
    LDL_Formatter* formatter;
    LDL_FpsCounter* counter;
    LDL_Texture* texture0;
    LDL_Texture* texture1;
    LDL_Texture* texture2;
    LDL_Event event;
    LDL_Vec2i pos;
    LDL_Vec2i size;
    size_t i;

    srand(time(NULL));

    result = LDL_ResultCreate();
    context = LDL_ContextCreate(result, LDL_ContextOpenGLModern);
    window = LDL_WindowCreate(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL C89 lesson 06 - Texture", LDL_WindowModeResized);
    render = LDL_2DRenderCreate(result, context, window);
    loader = LDL_BmpLoaderCreate(result);
    formatter = LDL_FormatterCreate();
    counter = LDL_FpsCounterCreate(result);

    if (LDL_BmpLoaderLoadFromFile(loader, "LDL_24_256_0.bmp"))
    {
        texture0 = LDL_TextureCreateFromPixels(result, context, LDL_BmpLoaderGetPixelFormat(loader), LDL_BmpLoaderGetSize(loader), LDL_BmpLoaderGetPixels(loader));
    }

    if (LDL_BmpLoaderLoadFromFile(loader, "LDL_24_256_1.bmp"))
    {
        texture1 = LDL_TextureCreateFromPixels(result, context, LDL_BmpLoaderGetPixelFormat(loader), LDL_BmpLoaderGetSize(loader), LDL_BmpLoaderGetPixels(loader));
    }

    if (LDL_BmpLoaderLoadFromFile(loader, "LDL_24_256_2.bmp"))
    {
        texture2 = LDL_TextureCreateFromPixels(result, context, LDL_BmpLoaderGetPixelFormat(loader), LDL_BmpLoaderGetSize(loader), LDL_BmpLoaderGetPixels(loader));
    }

    while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
    {
        LDL_FpsCounterStart(counter);

        while (LDL_WindowGetEvent(window, &event))
        {
            if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
            {
                LDL_WindowStopEvent(window);
            }
        }

        LDL_2DRenderSetColor(render, LDL_ColorRgb(255, 127, 39));
        LDL_2DRenderClear(render);

        LDL_2DRenderBegin(render);

        for (i = 0; i < count; i++)
        {
            LDL_2DRenderSetLayer(render, 1);
            pos  = LDL_GetVec2i(Random(0, LDL_WindowGetSize(window).x), Random(0, LDL_WindowGetSize(window).y));
            size = LDL_GetVec2i(Random(25, 50), Random(25, 50));
            LDL_2DRenderDraw(render, texture0, &pos, &size, NULL, NULL);

            LDL_2DRenderSetLayer(render, 2);
            pos  = LDL_GetVec2i(Random(0, LDL_WindowGetSize(window).x), Random(0, LDL_WindowGetSize(window).y));
            size = LDL_GetVec2i(Random(25, 50), Random(25, 50));
            LDL_2DRenderDraw(render, texture1, &pos, &size, NULL, NULL);

            LDL_2DRenderSetLayer(render, 2);
            pos  = LDL_GetVec2i(Random(0, LDL_WindowGetSize(window).x), Random(0, LDL_WindowGetSize(window).y));
            size = LDL_GetVec2i(Random(25, 50), Random(25, 50));
            LDL_2DRenderDraw(render, texture2, &pos, &size, NULL, NULL);
        }

        LDL_2DRenderEnd(render);

        if (LDL_FpsCounterCalc(counter))
        {
            LDL_WindowSetTitle(window, LDL_FormatterFormat(formatter, "LDL C89 lesson 06 - Texture. Fps: %d", LDL_FpsCounterFps(counter)));
        }
    }

    LDL_FpsCounterDestroy(counter);
    LDL_TextureDestroy(texture0);
    LDL_TextureDestroy(texture1);
    LDL_TextureDestroy(texture2);
    LDL_BmpLoaderDestroy(loader);
    LDL_2DRenderDestroy(render);
    LDL_WindowDestroy(window);
    LDL_ContextDestroy(context);

    if (LDL_ResultIsFail(result))
    {
        printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
    }

    LDL_ResultDestroy(result);

    return 0;
}
