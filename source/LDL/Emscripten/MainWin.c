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
 * IMPORTANT: emscripten.h / html5.h MUST be included first.
 *
 * Reason: html5.h pulls in stdbool.h which defines bool as _Bool.
 * If any LDL header that contains the old-style "#define bool char"
 * guards (Types.h, VisualC / TurboC paths) were included first, the
 * compiler would see "bool" as "char" and all EM_BOOL callback
 * signatures would mismatch (_Bool vs char).
 *
 * Emscripten defines EM_BOOL as int (not _Bool) in modern SDKs, but
 * the callback typedefs (em_key_callback_func etc.) use `bool` in their
 * declaration, which resolves to _Bool after stdbool.h.  By including
 * html5.h first we guarantee the C compiler sees the correct types
 * before anything from LDL can shadow them.
 */

/* --- Emscripten headers first ---------------------------------------- */
#include <emscripten.h>
#include <emscripten/html5.h>

/* --- Standard C -------------------------------------------------------- */
#include <string.h>

/* --- LDL internal headers (must come after emscripten) --------------- */
#include <LDL/BaseWin.h>
#include <LDL/Emscripten/MainWin.h>

/* ------------------------------------------------------------------ */
/* Canvas target                                                        */
/* ------------------------------------------------------------------ */

#ifndef LDL_EMSCRIPTEN_CANVAS_TARGET
#  define LDL_EMSCRIPTEN_CANVAS_TARGET "#canvas"
#endif

/* DOM_KEY_LOCATION_RIGHT per the DOM spec */
#define LDL_DOM_KEY_LOCATION_RIGHT 2u

/* Synthetic right-modifier codes (see KMapper.c) */
#define LDL_SYNTHETIC_SHIFT_R   (0x10000u | 1u)
#define LDL_SYNTHETIC_CTRL_R    (0x10000u | 2u)

static uint8_t LDL_EmscMouseButton(unsigned short button)
{
    switch (button)
    {
        case 0:  return LDL_MouseButtonLeft;
        case 1:  return LDL_MouseButtonMiddle;
        case 2:  return LDL_MouseButtonRight;
        default: return 0;
    }
}

static uint32_t LDL_EmscKeyCode(const EmscriptenKeyboardEvent* e)
{
    unsigned long kc  = (unsigned long)e->keyCode;
    unsigned long loc = (unsigned long)e->location;

    if (loc == LDL_DOM_KEY_LOCATION_RIGHT)
    {
        if (kc == 16u) return LDL_SYNTHETIC_SHIFT_R;
        if (kc == 17u) return LDL_SYNTHETIC_CTRL_R;
    }

    return (uint32_t)kc;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscKeyDown(int eventType,
                                const EmscriptenKeyboardEvent* e,
                                void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;
    uint32_t code;
    uint8_t  key;

    (void)eventType;

    code = LDL_EmscKeyCode(e);
    key  = LDL_KeyMapperConvertKey(&mw->KeyMapper, code);

    report.Type             = LDL_EventIsKeyboard;
    report.u.Keyboard.State = LDL_ButtonStatePressed;
    report.u.Keyboard.Key   = key;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_TRUE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscKeyUp(int eventType,
                              const EmscriptenKeyboardEvent* e,
                              void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;
    uint32_t code;
    uint8_t  key;

    (void)eventType;

    code = LDL_EmscKeyCode(e);
    key  = LDL_KeyMapperConvertKey(&mw->KeyMapper, code);

    report.Type             = LDL_EventIsKeyboard;
    report.u.Keyboard.State = LDL_ButtonStateReleased;
    report.u.Keyboard.Key   = key;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_TRUE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscMouseMove(int eventType,
                                  const EmscriptenMouseEvent* e,
                                  void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;

    (void)eventType;

    report.Type            = LDL_EventIsMouseMove;
    report.u.Mouse.PosX    = (int32_t)e->targetX;
    report.u.Mouse.PosY    = (int32_t)e->targetY;
    report.u.Mouse.PosRelX = (int32_t)e->movementX;
    report.u.Mouse.PosRelY = (int32_t)e->movementY;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_TRUE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscMouseDown(int eventType,
                                  const EmscriptenMouseEvent* e,
                                  void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;

    (void)eventType;

    report.Type           = LDL_EventIsMouseClick;
    report.u.Mouse.State  = LDL_ButtonStatePressed;
    report.u.Mouse.Button = LDL_EmscMouseButton(e->button);
    report.u.Mouse.PosX   = (int32_t)e->targetX;
    report.u.Mouse.PosY   = (int32_t)e->targetY;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_TRUE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscMouseUp(int eventType,
                                const EmscriptenMouseEvent* e,
                                void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;

    (void)eventType;

    report.Type           = LDL_EventIsMouseClick;
    report.u.Mouse.State  = LDL_ButtonStateReleased;
    report.u.Mouse.Button = LDL_EmscMouseButton(e->button);
    report.u.Mouse.PosX   = (int32_t)e->targetX;
    report.u.Mouse.PosY   = (int32_t)e->targetY;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_TRUE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscWheel(int eventType,
                              const EmscriptenWheelEvent* e,
                              void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;

    (void)eventType;

    report.Type         = LDL_EventIsMouseScroll;
    report.u.Mouse.PosX = (int32_t)e->mouse.targetX;
    report.u.Mouse.PosY = (int32_t)e->mouse.targetY;

    if (e->deltaY != 0.0)
    {
        report.u.Mouse.Scroll = LDL_MouseScrollVertical;
        report.u.Mouse.Delta  = (int32_t)(e->deltaY < 0.0
                                         ? -(long)e->deltaY
                                         :  (long)e->deltaY);
    }
    else
    {
        report.u.Mouse.Scroll = LDL_MouseScrollHorizontal;
        report.u.Mouse.Delta  = (int32_t)(e->deltaX < 0.0
                                         ? -(long)e->deltaX
                                         :  (long)e->deltaX);
    }

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_TRUE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscResize(int eventType,
                               const EmscriptenUiEvent* e,
                               void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;
    int w = 0;
    int h = 0;

    (void)eventType;
    (void)e;

    emscripten_get_canvas_element_size(mw->CanvasTarget, &w, &h);

    report.Type            = LDL_EventIsResize;
    report.u.Resize.Width  = (uint32_t)(w > 0 ? w : 0);
    report.u.Resize.Height = (uint32_t)(h > 0 ? h : 0);

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_FALSE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscFocusIn(int eventType,
                                const EmscriptenFocusEvent* e,
                                void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;

    (void)eventType;
    (void)e;

    report.Type = LDL_EventIsGainedFocus;
    report.u.GainedFocus.Type = LDL_EventIsGainedFocus;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_FALSE;
}

static EM_BOOL EMSCRIPTEN_KEEPALIVE LDL_EmscFocusOut(int eventType,
                                 const EmscriptenFocusEvent* e,
                                 void* userData)
{
    LDL_MainWindow* mw = (LDL_MainWindow*)userData;
    LDL_Event report;

    (void)eventType;
    (void)e;

    report.Type = LDL_EventIsLostFocus;
    report.u.LostFocus.Type = LDL_EventIsLostFocus;

    LDL_EventHandlerPush(&mw->EventHandler, &report);

    return EM_FALSE;
}

void LDL_MainWindowInit(LDL_MainWindow* mainWindow, LDL_Result* result,
                        LDL_Vec2i pos, LDL_Vec2i size,
                        const char* title, size_t mode)
{
    if (!mainWindow || !result)
        return;

    mainWindow->CanvasTarget = LDL_EMSCRIPTEN_CANVAS_TARGET;

    LDL_KeyMapperInit(&mainWindow->KeyMapper);
    LDL_EventHandlerInit(&mainWindow->EventHandler);
    LDL_BaseWindowInit(&mainWindow->BaseWindow, pos, size, title, mode);

    if (!(mode & LDL_WindowModeFullScreen))
    {
        emscripten_set_canvas_element_size(
            mainWindow->CanvasTarget,
            size.x,
            size.y);
    }

    emscripten_set_keydown_callback(
        EMSCRIPTEN_EVENT_TARGET_WINDOW, mainWindow, EM_TRUE,
        LDL_EmscKeyDown);

    emscripten_set_keyup_callback(
        EMSCRIPTEN_EVENT_TARGET_WINDOW, mainWindow, EM_TRUE,
        LDL_EmscKeyUp);

    emscripten_set_mousemove_callback(
        mainWindow->CanvasTarget, mainWindow, EM_FALSE,
        LDL_EmscMouseMove);

    emscripten_set_mousedown_callback(
        mainWindow->CanvasTarget, mainWindow, EM_FALSE,
        LDL_EmscMouseDown);

    emscripten_set_mouseup_callback(
        mainWindow->CanvasTarget, mainWindow, EM_FALSE,
        LDL_EmscMouseUp);

    emscripten_set_wheel_callback(
        mainWindow->CanvasTarget, mainWindow, EM_FALSE,
        LDL_EmscWheel);

    emscripten_set_resize_callback(
        EMSCRIPTEN_EVENT_TARGET_WINDOW, mainWindow, EM_FALSE,
        LDL_EmscResize);

    emscripten_set_focusin_callback(
        mainWindow->CanvasTarget, mainWindow, EM_FALSE,
        LDL_EmscFocusIn);

    emscripten_set_focusout_callback(
        mainWindow->CanvasTarget, mainWindow, EM_FALSE,
        LDL_EmscFocusOut);
}

void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow)
{
    if (!mainWindow)
        return;

    emscripten_set_keydown_callback(
        EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, EM_TRUE, NULL);
    emscripten_set_keyup_callback(
        EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, EM_TRUE, NULL);
    emscripten_set_mousemove_callback(
        mainWindow->CanvasTarget, NULL, EM_FALSE, NULL);
    emscripten_set_mousedown_callback(
        mainWindow->CanvasTarget, NULL, EM_FALSE, NULL);
    emscripten_set_mouseup_callback(
        mainWindow->CanvasTarget, NULL, EM_FALSE, NULL);
    emscripten_set_wheel_callback(
        mainWindow->CanvasTarget, NULL, EM_FALSE, NULL);
    emscripten_set_resize_callback(
        EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, EM_FALSE, NULL);
    emscripten_set_focusin_callback(
        mainWindow->CanvasTarget, NULL, EM_FALSE, NULL);
    emscripten_set_focusout_callback(
        mainWindow->CanvasTarget, NULL, EM_FALSE, NULL);

    while (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
    {
        LDL_Event event;
        LDL_EventHandlerPop(&mainWindow->EventHandler, &event);
    }
}

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_BaseWindowGetPos(&mainWindow->BaseWindow);

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_MainWindowGetSize(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_BaseWindowGetSize(&mainWindow->BaseWindow);

    return LDL_GetVec2i(0, 0);
}

const char* LDL_MainWindowGetTitle(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_BaseWindowGetTitle(&mainWindow->BaseWindow);

    return NULL;
}

void LDL_MainWindowSetTitle(LDL_MainWindow* mainWindow, const char* title)
{
    if (!mainWindow || !title)
        return;

    LDL_BaseWindowSetTitle(&mainWindow->BaseWindow, title);

    EM_ASM({ document.title = UTF8ToString($0); },
           LDL_BaseWindowGetTitle(&mainWindow->BaseWindow));
}

bool LDL_MainWindowGetEvent(LDL_MainWindow* mainWindow, LDL_Event* event)
{
    if (!mainWindow || !event)
        return false;

    if (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
        return LDL_EventHandlerPop(&mainWindow->EventHandler, event);

    return false;
}

void LDL_MainWindowStopEvent(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        LDL_EventHandlerStop(&mainWindow->EventHandler);
}

bool LDL_MainWindowIsRunning(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_EventHandlerRunning(&mainWindow->EventHandler);

    return false;
}
