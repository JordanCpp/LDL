/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software); you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation); either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY); without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <LDL/Enums.h>
#include <LDL/Linux/GLX.h>
#include <LDL/Linux/KMapper.h>

void LDL_KeyMapperInit(LDL_KeyMapper *keyMapper)
{
    if (keyMapper)
    {
        LDL_KeyMappingInit(&keyMapper->Mapping);

        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Meta_L, LDL_KeyLSystem);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Super_L, LDL_KeyLSystem);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Meta_R, LDL_KeyLSystem);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Super_R, LDL_KeyRSystem);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Menu, LDL_KeyMenu);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_semicolon, LDL_KeySemicolon);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_slash, LDL_KeySlash);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_equal, LDL_KeyEqual);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_hyphen, LDL_KeyHyphen);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_bracketleft, LDL_KeyLBracket);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_bracketright, LDL_KeyRBracket);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_comma, LDL_KeyComma);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_period, LDL_KeyPeriod);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_backslash, LDL_KeyBackslash);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Escape, LDL_KeyEscape);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_space, LDL_KeySpace);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Return, LDL_KeyEnter);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_BackSpace, LDL_KeyBackspace);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Tab, LDL_KeyTab);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Page_Up, LDL_KeyPageUp);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Page_Down, LDL_KeyPageDown);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_End, LDL_KeyEnd);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Home, LDL_KeyHome);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Insert, LDL_KeyInsert);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Clear, LDL_KeyDelete);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_Add, LDL_KeyAdd);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_Subtract, LDL_KeySubtract);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_Multiply, LDL_KeyMultiply);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_Divide, LDL_KeyDivide);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Break, LDL_KeyPause);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F1, LDL_KeyF1);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F2, LDL_KeyF2);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F3, LDL_KeyF3);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F4, LDL_KeyF4);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F5, LDL_KeyF5);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F6, LDL_KeyF6);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F7, LDL_KeyF7);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F8, LDL_KeyF8);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F9, LDL_KeyF9);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F10, LDL_KeyF10);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F11, LDL_KeyF11);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F12, LDL_KeyF12);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F13, LDL_KeyF13);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F14, LDL_KeyF14);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F15, LDL_KeyF15);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Left, LDL_KeyLeft);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Right, LDL_KeyRight);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Up, LDL_KeyUp);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Down, LDL_KeyDown);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_0, LDL_KeyNumpad0);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_1, LDL_KeyNumpad1);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_2, LDL_KeyNumpad2);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_3, LDL_KeyNumpad3);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_4, LDL_KeyNumpad4);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_5, LDL_KeyNumpad5);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_6, LDL_KeyNumpad6);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_7, LDL_KeyNumpad7);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_8, LDL_KeyNumpad8);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_KP_9, LDL_KeyNumpad9);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_a, LDL_KeyA);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_A, LDL_KeyA);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_z, LDL_KeyZ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Z, LDL_KeyZ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_e, LDL_KeyE);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_E, LDL_KeyE);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_r, LDL_KeyR);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_R, LDL_KeyR);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_t, LDL_KeyT);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_T, LDL_KeyT);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_y, LDL_KeyY);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Y, LDL_KeyY);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_u, LDL_KeyU);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_U, LDL_KeyU);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_i, LDL_KeyI);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_I, LDL_KeyI);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_o, LDL_KeyO);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_O, LDL_KeyO);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_p, LDL_KeyP);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_P, LDL_KeyP);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_q, LDL_KeyQ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Q, LDL_KeyQ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_s, LDL_KeyS);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_S, LDL_KeyS);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_d, LDL_KeyD);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_D, LDL_KeyD);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_f, LDL_KeyF);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_F, LDL_KeyF);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_g, LDL_KeyG);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_G, LDL_KeyG);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_h, LDL_KeyH);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_H, LDL_KeyH);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_j, LDL_KeyJ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_J, LDL_KeyJ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_k, LDL_KeyK);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_K, LDL_KeyK);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_l, LDL_KeyL);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_L, LDL_KeyL);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_m, LDL_KeyM);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_M, LDL_KeyM);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_w, LDL_KeyW);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_W, LDL_KeyW);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_x, LDL_KeyX);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_X, LDL_KeyX);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_c, LDL_KeyC);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_C, LDL_KeyC);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_v, LDL_KeyV);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_V, LDL_KeyV);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_b, LDL_KeyB);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_B, LDL_KeyB);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_n, LDL_KeyN);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_N, LDL_KeyN);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_0, LDL_KeyNum0);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_1, LDL_KeyNum1);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_2, LDL_KeyNum2);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_3, LDL_KeyNum3);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_4, LDL_KeyNum4);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_5, LDL_KeyNum5);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_6, LDL_KeyNum6);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_7, LDL_KeyNum7);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_8, LDL_KeyNum8);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_9, LDL_KeyNum9);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Shift_L, LDL_KeyLeftShift);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Shift_R, LDL_KeyRightShift);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Control_L, LDL_KeyLeftControl);
        LDL_KeyMappingAdd(&keyMapper->Mapping, XK_Control_R, LDL_KeyRightControl);
    }
}

uint8_t LDL_KeyMapperConvertKey(LDL_KeyMapper *keyMapper, uint32_t key)
{
    if (keyMapper)
    {
        return LDL_KeyMappingFindKey(&keyMapper->Mapping, key);
    }

    return LDL_KeyUnknown;
}
