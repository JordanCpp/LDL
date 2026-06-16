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
    LDL_Result* result = NULL;
    LDL_Context* context = NULL;
    LDL_Window* window = NULL;
    LDL_2DRender* render = NULL;
    LDL_Event    event;

    result = LDL_ResultCreate();
    context = LDL_ContextCreate(result, LDL_ContextOpenGLLegacy);
    window = LDL_WindowCreate(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL C89 lesson 05 - Fill", LDL_WindowModeResized);
    render = LDL_2DRenderCreate(result, context, window);

    while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
    {
        while (LDL_WindowGetEvent(window, &event))
        {
            if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
            {
                LDL_WindowStopEvent(window);
            }
        }

        LDL_2DRenderSetColor(render, LDL_ColorRgb(0, 162, 232));
        LDL_2DRenderClear(render);

        LDL_2DRenderBegin(render);

        LDL_2DRenderSetColor(render, LDL_ColorRgb(237, 28, 36));
        LDL_2DRenderFill(render, LDL_GetVec2i(0, 0), LDL_GetVec2i(800 / 2, 600 / 2));

        LDL_2DRenderEnd(render);
    }

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
