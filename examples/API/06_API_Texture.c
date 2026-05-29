/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <LDL/LDL.h>

int main(void)
{
    LDL_Result*    result;
    LDL_Context*   context;
    LDL_Window*    window;
    LDL_Render*    render;
    LDL_Event      event;
    LDL_BmpLoader* loader;
    LDL_Texture*   texture;
    LDL_Vec2i      pos;

    result  = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGL1);
    window  = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL 06 - Texture", LDL_WindowModeResized);
    render  = LDL_RenderNew(result, context, window);
    loader  = LDL_BmpLoaderNew(result);

    if (LDL_BmpLoaderLoadFromFile(loader, "LDL_24_256.bmp"))
    {
        texture = LDL_TextureNewFromPixels(context, LDL_BmpLoaderGetPixelFormat(loader), LDL_BmpLoaderGetSize(loader), LDL_BmpLoaderGetPixels(loader));
    }

    if (LDL_ResultIsOk(result))
    {
        while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
        {
            while (LDL_WindowGetEvent(window, &event))
            {
                if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                {
                    LDL_WindowStopEvent(window);
                }
            }

            LDL_RenderSetColor(render, LDL_ColorRgb(255, 127, 39));
            LDL_RenderClear(render);

            LDL_RenderBegin(render);

            pos = LDL_GetVec2i(0, 0);
            LDL_RenderDraw(render, texture, &pos, NULL, NULL, NULL);

            LDL_RenderEnd(render);
        }
    }

    LDL_TextureFree(texture);
    LDL_BmpLoaderFree(loader);
    LDL_ContextFree(context);
    LDL_WindowFree(window);
    LDL_ResultFree(result);

    if (LDL_ResultIsFail(result))
    {
        printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
    }

    return 0;
}
