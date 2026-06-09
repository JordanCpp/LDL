/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <LDL/LDL.h>

size_t fvf = LDL_FVF_XYZ | LDL_FVF_COLOR;

typedef struct
{
    float x, y, z;
    float r, g, b;
} Vertex;

Vertex triangle[] =
{
    { 0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f},
    {-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f},
    { 0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f}
};

int main(void)
{
    LDL_Result* result;
    LDL_Context* context;
    LDL_Window* window;
    LDL_3DRender* render;
    LDL_Event event;
    LDL_VertexBuffer* buffer;

    result = LDL_ResultCreate();
    context = LDL_ContextCreate(result, LDL_ContextOpenGLLegacy);
    window = LDL_WindowCreate(result, context, LDL_GetVec2i(0, 0), LDL_GetVec2i(800, 600), "LDL 3D Render - Rotating Triangle", LDL_WindowModeResized);
    render = LDL_3DRenderCreate(result, context, window);
    buffer = LDL_VertexBufferNew(context, fvf);

    if (LDL_ResultIsOk(result))
    {
        LDL_VertexBufferCopy(buffer, sizeof(Vertex), 3, triangle);

        while (LDL_WindowIsRunning(window) && LDL_ResultIsOk(result))
        {
            while (LDL_WindowGetEvent(window, &event))
            {
                if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
                {
                    LDL_WindowStopEvent(window);
                }
            }

            LDL_3DRenderBegin(render);
            LDL_3DRenderClear(render, 0.2f, 0.3f, 0.4f);
            LDL_3DRenderDraw(render, buffer);
            LDL_3DRenderEnd(render);
        }
    }

    LDL_VertexBufferFree(buffer);
    LDL_3DRenderDestroy(render);
    LDL_ContextDestroy(context);
    LDL_WindowDestroy(window);
    LDL_ResultDestroy(result);

    if (LDL_ResultIsFail(result))
    {
        printf("LDL result error: %s\n", LDL_ResultGetMessage(result));
    }

    return 0;
}