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
 * Emscripten key mapping.
 *
 * Emscripten exposes DOM KeyboardEvent.keyCode values via
 * EmscriptenKeyboardEvent.keyCode (int).  The codes are the same as the
 * legacy DOM Level 2 keyCodes (identical to Windows virtual key codes for
 * most printable/control keys), which lets us reuse the Win9x mapping
 * table almost verbatim.
 *
 * Reference:
 *   https://emscripten.org/docs/api_reference/html5.h.html
 *   https://developer.mozilla.org/en-US/docs/Web/API/KeyboardEvent/keyCode
 */

#include <LDL/Enums.h>
#include <LDL/Emscripten/KMapper.h>

/* DOM Level 2 / Windows VK codes used by Emscripten */
#define DOM_VK_BACK_SPACE   8
#define DOM_VK_TAB          9
#define DOM_VK_RETURN       13
#define DOM_VK_SHIFT        16
#define DOM_VK_CONTROL      17
#define DOM_VK_PAUSE        19
#define DOM_VK_ESCAPE       27
#define DOM_VK_SPACE        32
#define DOM_VK_PAGE_UP      33
#define DOM_VK_PAGE_DOWN    34
#define DOM_VK_END          35
#define DOM_VK_HOME         36
#define DOM_VK_LEFT         37
#define DOM_VK_UP           38
#define DOM_VK_RIGHT        39
#define DOM_VK_DOWN         40
#define DOM_VK_INSERT       45
#define DOM_VK_DELETE       46
#define DOM_VK_0            48
#define DOM_VK_1            49
#define DOM_VK_2            50
#define DOM_VK_3            51
#define DOM_VK_4            52
#define DOM_VK_5            53
#define DOM_VK_6            54
#define DOM_VK_7            55
#define DOM_VK_8            56
#define DOM_VK_9            57
#define DOM_VK_A            65
#define DOM_VK_B            66
#define DOM_VK_C            67
#define DOM_VK_D            68
#define DOM_VK_E            69
#define DOM_VK_F            70
#define DOM_VK_G            71
#define DOM_VK_H            72
#define DOM_VK_I            73
#define DOM_VK_J            74
#define DOM_VK_K            75
#define DOM_VK_L            76
#define DOM_VK_M            77
#define DOM_VK_N            78
#define DOM_VK_O            79
#define DOM_VK_P            80
#define DOM_VK_Q            81
#define DOM_VK_R            82
#define DOM_VK_S            83
#define DOM_VK_T            84
#define DOM_VK_U            85
#define DOM_VK_V            86
#define DOM_VK_W            87
#define DOM_VK_X            88
#define DOM_VK_Y            89
#define DOM_VK_Z            90
#define DOM_VK_WIN_L        91
#define DOM_VK_WIN_R        92
#define DOM_VK_CONTEXT_MENU 93
#define DOM_VK_NUMPAD0      96
#define DOM_VK_NUMPAD1      97
#define DOM_VK_NUMPAD2      98
#define DOM_VK_NUMPAD3      99
#define DOM_VK_NUMPAD4      100
#define DOM_VK_NUMPAD5      101
#define DOM_VK_NUMPAD6      102
#define DOM_VK_NUMPAD7      103
#define DOM_VK_NUMPAD8      104
#define DOM_VK_NUMPAD9      105
#define DOM_VK_MULTIPLY     106
#define DOM_VK_ADD          107
#define DOM_VK_SUBTRACT     109
#define DOM_VK_DECIMAL      110
#define DOM_VK_DIVIDE       111
#define DOM_VK_F1           112
#define DOM_VK_F2           113
#define DOM_VK_F3           114
#define DOM_VK_F4           115
#define DOM_VK_F5           116
#define DOM_VK_F6           117
#define DOM_VK_F7           118
#define DOM_VK_F8           119
#define DOM_VK_F9           120
#define DOM_VK_F10          121
#define DOM_VK_F11          122
#define DOM_VK_F12          123
#define DOM_VK_F13          124
#define DOM_VK_F14          125
#define DOM_VK_F15          126
#define DOM_VK_SEMICOLON    186
#define DOM_VK_EQUAL        187
#define DOM_VK_COMMA        188
#define DOM_VK_HYPHEN       189
#define DOM_VK_PERIOD       190
#define DOM_VK_SLASH        191
#define DOM_VK_BACK_QUOTE   192
#define DOM_VK_OPEN_BRACKET 219
#define DOM_VK_BACK_SLASH   220
#define DOM_VK_CLOSE_BRACKET 221
#define DOM_VK_QUOTE        222
#define DOM_VK_SHIFT_R      (0x10000 | 1)  /* synthetic: right-shift via location */
#define DOM_VK_CTRL_R       (0x10000 | 2)  /* synthetic: right-ctrl  via location */

void LDL_KeyMapperInit(LDL_KeyMapper* keyMapper)
{
    if (!keyMapper)
        return;

    LDL_KeyMappingInit(&keyMapper->Mapping);

    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_WIN_L,        LDL_KeyLSystem);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_WIN_R,        LDL_KeyRSystem);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_CONTEXT_MENU, LDL_KeyMenu);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_SEMICOLON,     LDL_KeySemicolon);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_SLASH,         LDL_KeySlash);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_EQUAL,         LDL_KeyEqual);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_HYPHEN,        LDL_KeyHyphen);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_OPEN_BRACKET,  LDL_KeyLBracket);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_CLOSE_BRACKET, LDL_KeyRBracket);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_COMMA,         LDL_KeyComma);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_PERIOD,        LDL_KeyPeriod);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_QUOTE,         LDL_KeyQuote);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_BACK_SLASH,    LDL_KeyBackslash);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_BACK_QUOTE,    LDL_KeyTilde);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_ESCAPE,      LDL_KeyEscape);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_SPACE,       LDL_KeySpace);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_RETURN,      LDL_KeyEnter);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_BACK_SPACE,  LDL_KeyBackspace);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_TAB,         LDL_KeyTab);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_PAGE_UP,     LDL_KeyPageUp);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_PAGE_DOWN,   LDL_KeyPageDown);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_END,         LDL_KeyEnd);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_HOME,        LDL_KeyHome);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_INSERT,      LDL_KeyInsert);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_DELETE,      LDL_KeyDelete);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_PAUSE,       LDL_KeyPause);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_ADD,      LDL_KeyAdd);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_SUBTRACT, LDL_KeySubtract);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_MULTIPLY, LDL_KeyMultiply);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_DIVIDE,   LDL_KeyDivide);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F1,  LDL_KeyF1);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F2,  LDL_KeyF2);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F3,  LDL_KeyF3);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F4,  LDL_KeyF4);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F5,  LDL_KeyF5);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F6,  LDL_KeyF6);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F7,  LDL_KeyF7);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F8,  LDL_KeyF8);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F9,  LDL_KeyF9);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F10, LDL_KeyF10);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F11, LDL_KeyF11);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F12, LDL_KeyF12);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F13, LDL_KeyF13);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F14, LDL_KeyF14);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F15, LDL_KeyF15);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_LEFT,  LDL_KeyLeft);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_RIGHT, LDL_KeyRight);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_UP,    LDL_KeyUp);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_DOWN,  LDL_KeyDown);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD0, LDL_KeyNumpad0);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD1, LDL_KeyNumpad1);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD2, LDL_KeyNumpad2);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD3, LDL_KeyNumpad3);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD4, LDL_KeyNumpad4);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD5, LDL_KeyNumpad5);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD6, LDL_KeyNumpad6);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD7, LDL_KeyNumpad7);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD8, LDL_KeyNumpad8);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_NUMPAD9, LDL_KeyNumpad9);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_A, LDL_KeyA);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_B, LDL_KeyB);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_C, LDL_KeyC);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_D, LDL_KeyD);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_E, LDL_KeyE);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_F, LDL_KeyF);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_G, LDL_KeyG);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_H, LDL_KeyH);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_I, LDL_KeyI);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_J, LDL_KeyJ);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_K, LDL_KeyK);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_L, LDL_KeyL);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_M, LDL_KeyM);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_N, LDL_KeyN);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_O, LDL_KeyO);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_P, LDL_KeyP);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_Q, LDL_KeyQ);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_R, LDL_KeyR);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_S, LDL_KeyS);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_T, LDL_KeyT);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_U, LDL_KeyU);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_V, LDL_KeyV);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_W, LDL_KeyW);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_X, LDL_KeyX);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_Y, LDL_KeyY);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_Z, LDL_KeyZ);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_0, LDL_KeyNum0);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_1, LDL_KeyNum1);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_2, LDL_KeyNum2);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_3, LDL_KeyNum3);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_4, LDL_KeyNum4);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_5, LDL_KeyNum5);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_6, LDL_KeyNum6);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_7, LDL_KeyNum7);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_8, LDL_KeyNum8);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_9, LDL_KeyNum9);

    /*
     * Shift / Control: Emscripten reports location via
     * EmscriptenKeyboardEvent.location.  We encode right-side modifiers
     * as synthetic codes above 0x10000 and translate them in MainWin.c
     * before calling LDL_KeyMapperConvertKey.
     */
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_SHIFT,   LDL_KeyLeftShift);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_SHIFT_R, LDL_KeyRightShift);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_CONTROL,   LDL_KeyLeftControl);
    LDL_KeyMappingAdd(&keyMapper->Mapping, DOM_VK_CTRL_R,    LDL_KeyRightControl);
}

uint8_t LDL_KeyMapperConvertKey(LDL_KeyMapper* keyMapper, uint32_t key)
{
    if (keyMapper)
    {
        return LDL_KeyMappingFindKey(&keyMapper->Mapping, key);
    }

    return LDL_KeyUnknown;
}
