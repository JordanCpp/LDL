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
    LDL_Result*  result = NULL;
    LDL_Context* context = NULL;
    LDL_Window*  window = NULL;
    LDL_Render*  render = NULL;
    LDL_Event    event;
    LDL_Vec2i    size;

    result  = LDL_ResultNew();
    context = LDL_ContextNew(LDL_ContextOpenGLLegacy);
    window  = LDL_WindowNew(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL C89 lesson 05 - Fill", LDL_WindowModeResized);
    render  = LDL_RenderNew(result, context, window);

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

            LDL_RenderSetColor(render, LDL_ColorRgb(0, 162, 232));
            LDL_RenderClear(render);

            LDL_RenderBegin(render);

            LDL_RenderSetColor(render, LDL_ColorRgb(237, 28, 36));
            LDL_RenderFill2i(render, LDL_GetVec2i(0, 0), LDL_GetVec2i(800 / 2, 600 / 2));

            LDL_RenderEnd(render);
        }
    }

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
