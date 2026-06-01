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
    LDL_Result*    result = NULL;
    LDL_Context*   context = NULL;
    LDL_Window*    window = NULL;
    LDL_Render*    render = NULL;
    LDL_BmpLoader* loader = NULL;
    LDL_Texture*   texture = NULL;
    LDL_Event      event;
    LDL_Vec2i      pos;

    result  = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGLLegacy);
    window  = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL C89 lesson 06 - Texture", LDL_WindowModeResized);
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

            LDL_RenderSetLayer(render, 1);
            pos = LDL_GetVec2i(0, 0);
            LDL_RenderDraw(render, texture, &pos, NULL, NULL, NULL);

            LDL_RenderSetLayer(render, 2);
            pos = LDL_GetVec2i(100, 100);
            LDL_RenderDraw(render, texture, &pos, NULL, NULL, NULL);

            LDL_RenderSetLayer(render, 2);
            pos = LDL_GetVec2i(100, 100);
           
            LDL_RenderSetColor(render, LDL_ColorRgb(255, 234, 39));
            LDL_RenderFill2i(render, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600));

            LDL_RenderEnd(render);
        }
    }

    LDL_TextureFree(texture);
    LDL_BmpLoaderFree(loader);
    LDL_RenderFree(render);
    LDL_WindowFree(window);
    LDL_ContextFree(context);

    if (LDL_ResultIsFail(result))
    {
        printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
    }

    LDL_ResultFree(result);

    return 0;
}
