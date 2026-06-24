/*
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

/*
 * Emscripten/WebGL OpenGL window implementation.
 *
 * WebGL version selection:
 *   LDL_ContextOpenGL1 -> WebGL 1  (GLES 2 subset, OpenGL 1.x-like fixed-pipeline
 *                                   is NOT available; use shader-based fallback)
 *   LDL_ContextOpenGL3 -> WebGL 2  (GLES 3 / OpenGL 3.3 core profile)
 *
 * The context attributes are set conservatively so the code runs on
 * older mobile browsers as well as desktop ones.
 *
 * Fullscreen mode:
 *   When LDL_WindowModeFullScreen is set we call
 *   emscripten_request_fullscreen so the browser enters real fullscreen.
 *   The canvas size is then managed by the browser/Emscripten runtime.
 */

#include <string.h>
#include <emscripten.h>
#include <emscripten/html5.h>

#include <LDL/Result.h>
#include <LDL/Enums.h>
#include <LDL/Emscripten/WinGL.h>

/*
 * Fill EmscriptenWebGLContextAttributes for the requested context type.
 *
 * Both WebGL 1 and WebGL 2 are requested with:
 *   - double-buffering  (antialias off for perf; enable if needed)
 *   - depth  24-bit
 *   - stencil 8-bit
 *   - alpha channel
 *   - premultipliedAlpha off  (matches desktop GL convention)
 */
static void LDL_WinGLFillAttribs(EmscriptenWebGLContextAttributes* attrs,
                                  int contextVersion)
{
    emscripten_webgl_init_context_attributes(attrs);

    attrs->alpha                 = EM_TRUE;
    attrs->depth                 = EM_TRUE;
    attrs->stencil               = EM_TRUE;
    attrs->antialias             = EM_FALSE;
    attrs->premultipliedAlpha    = EM_FALSE;
    attrs->preserveDrawingBuffer = EM_FALSE;
    attrs->powerPreference       = EM_WEBGL_POWER_PREFERENCE_DEFAULT;
    attrs->failIfMajorPerformanceCaveat = EM_FALSE;

    attrs->majorVersion = contextVersion;
    attrs->minorVersion = 0;

    attrs->enableExtensionsByDefault = EM_TRUE;
}

void LDL_WindowOpenGLInit(LDL_WindowOpenGL* window, LDL_Result* result,
                          LDL_Vec2i pos, LDL_Vec2i size,
                          const char* title, size_t mode)
{
    EmscriptenWebGLContextAttributes attrs;
    int contextVersion;
    EMSCRIPTEN_RESULT emResult;

    if (!window || !result)
        return;

    window->Result  = result;
    window->Context = 0;

    LDL_MainWindowInit(&window->MainWindow, result, pos, size, title, mode);

    contextVersion = 1;
    LDL_WinGLFillAttribs(&attrs, contextVersion);

    window->Context = emscripten_webgl_create_context(
                          window->MainWindow.CanvasTarget, &attrs);

    if (window->Context <= 0)
    {
        if (contextVersion == 2)
        {
            LDL_WinGLFillAttribs(&attrs, 1);
            window->Context = emscripten_webgl_create_context(
                                  window->MainWindow.CanvasTarget, &attrs);
        }

        if (window->Context <= 0)
        {
            LDL_ResultAddMessage(result,
                "LDL_WindowOpenGLInit: emscripten_webgl_create_context failed\n");
            return;
        }
    }

    emResult = emscripten_webgl_make_context_current(window->Context);
    if (emResult != EMSCRIPTEN_RESULT_SUCCESS)
    {
        LDL_ResultAddMessage(result,
            "LDL_WindowOpenGLInit: emscripten_webgl_make_context_current failed\n");
        return;
    }

    LDL_WindowOpenGLSetTitle(window, title);

    if (mode & LDL_WindowModeFullScreen)
    {
        EmscriptenFullscreenStrategy strategy;
        memset(&strategy, 0, sizeof(strategy));
        strategy.scaleMode              = EMSCRIPTEN_FULLSCREEN_SCALE_STRETCH;
        strategy.canvasResolutionScaleMode =
            EMSCRIPTEN_FULLSCREEN_CANVAS_SCALE_HIDEF;
        strategy.filteringMode          = EMSCRIPTEN_FULLSCREEN_FILTERING_DEFAULT;

        emscripten_request_fullscreen_strategy(
            window->MainWindow.CanvasTarget, EM_TRUE, &strategy);
    }
}

void LDL_WindowOpenGLDeinit(LDL_WindowOpenGL* window)
{
    if (!window)
        return;

    LDL_MainWindowDeinit(&window->MainWindow);

    if (window->Context > 0)
    {
        emscripten_webgl_destroy_context(window->Context);
        window->Context = 0;
    }
}

LDL_Vec2i LDL_WindowOpenGLGetPos(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowGetPos(&window->MainWindow);

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_WindowOpenGLGetSize(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowGetSize(&window->MainWindow);

    return LDL_GetVec2i(0, 0);
}

bool LDL_WindowOpenGLGetEvent(LDL_WindowOpenGL* window, LDL_Event* event)
{
    if (window && event)
        return LDL_MainWindowGetEvent(&window->MainWindow, event);

    return false;
}

void LDL_WindowOpenGLStopEvent(LDL_WindowOpenGL* window)
{
    if (window)
        LDL_MainWindowStopEvent(&window->MainWindow);
}

bool LDL_WindowOpenGLIsRunning(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowIsRunning(&window->MainWindow);

    return false;
}

const char* LDL_WindowOpenGLGetTitle(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowGetTitle(&window->MainWindow);

    return NULL;
}

void LDL_WindowOpenGLSetTitle(LDL_WindowOpenGL* window, const char* title)
{
    if (window && title)
        LDL_MainWindowSetTitle(&window->MainWindow, title);
}

void LDL_WindowOpenGLPresent(LDL_WindowOpenGL* window)
{
#if defined(__EMSCRIPTEN_OFFSCREENCANVAS__)
    if (window && window->Context > 0)
        emscripten_webgl_commit_frame();
#else
    (void)window;
#endif
}
