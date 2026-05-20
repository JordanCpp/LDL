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

#include <LDL/Enums.h>
#include <LDL/macOS/KMapper.h>

/* macOS virtual key codes */
#define kVK_ANSI_A          0x00
#define kVK_ANSI_S          0x01
#define kVK_ANSI_D          0x02
#define kVK_ANSI_F          0x03
#define kVK_ANSI_H          0x04
#define kVK_ANSI_G          0x05
#define kVK_ANSI_Z          0x06
#define kVK_ANSI_X          0x07
#define kVK_ANSI_C          0x08
#define kVK_ANSI_V          0x09
#define kVK_ANSI_B          0x0B
#define kVK_ANSI_Q          0x0C
#define kVK_ANSI_W          0x0D
#define kVK_ANSI_E          0x0E
#define kVK_ANSI_R          0x0F
#define kVK_ANSI_Y          0x10
#define kVK_ANSI_T          0x11
#define kVK_ANSI_1          0x12
#define kVK_ANSI_2          0x13
#define kVK_ANSI_3          0x14
#define kVK_ANSI_4          0x15
#define kVK_ANSI_6          0x16
#define kVK_ANSI_5          0x17
#define kVK_ANSI_Equal      0x18
#define kVK_ANSI_9          0x19
#define kVK_ANSI_7          0x1A
#define kVK_ANSI_Minus      0x1B
#define kVK_ANSI_8          0x1C
#define kVK_ANSI_0          0x1D
#define kVK_ANSI_RightBracket 0x1E
#define kVK_ANSI_O          0x1F
#define kVK_ANSI_U          0x20
#define kVK_ANSI_LeftBracket 0x21
#define kVK_ANSI_I          0x22
#define kVK_ANSI_P          0x23
#define kVK_ANSI_L          0x25
#define kVK_ANSI_J          0x26
#define kVK_ANSI_Quote      0x27
#define kVK_ANSI_K          0x28
#define kVK_ANSI_Semicolon  0x29
#define kVK_ANSI_Backslash  0x2A
#define kVK_ANSI_Comma      0x2B
#define kVK_ANSI_Slash      0x2C
#define kVK_ANSI_N          0x2D
#define kVK_ANSI_M          0x2E
#define kVK_ANSI_Period     0x2F
#define kVK_ANSI_KeypadDecimal   0x41
#define kVK_ANSI_KeypadMultiply  0x43
#define kVK_ANSI_KeypadPlus      0x45
#define kVK_ANSI_KeypadDivide    0x4B
#define kVK_ANSI_KeypadEnter     0x4C
#define kVK_ANSI_KeypadMinus     0x4E
#define kVK_ANSI_Keypad0    0x52
#define kVK_ANSI_Keypad1    0x53
#define kVK_ANSI_Keypad2    0x54
#define kVK_ANSI_Keypad3    0x55
#define kVK_ANSI_Keypad4    0x56
#define kVK_ANSI_Keypad5    0x57
#define kVK_ANSI_Keypad6    0x58
#define kVK_ANSI_Keypad7    0x59
#define kVK_ANSI_Keypad8    0x5B
#define kVK_ANSI_Keypad9    0x5C
#define kVK_Return          0x24
#define kVK_Tab             0x30
#define kVK_Space           0x31
#define kVK_Delete          0x33
#define kVK_Escape          0x35
#define kVK_Command         0x37
#define kVK_Shift           0x38
#define kVK_CapsLock        0x39
#define kVK_Option          0x3A
#define kVK_Control         0x3B
#define kVK_RightShift      0x3C
#define kVK_RightOption     0x3D
#define kVK_RightControl    0x3E
#define kVK_Function        0x3F
#define kVK_F17             0x40
#define kVK_F18             0x4F
#define kVK_F19             0x50
#define kVK_F20             0x5A
#define kVK_F5              0x60
#define kVK_F6              0x61
#define kVK_F7              0x62
#define kVK_F3              0x63
#define kVK_F8              0x64
#define kVK_F9              0x65
#define kVK_F11             0x67
#define kVK_F13             0x69
#define kVK_F16             0x6A
#define kVK_F14             0x6B
#define kVK_F10             0x6D
#define kVK_F12             0x6F
#define kVK_F15             0x71
#define kVK_Help            0x72
#define kVK_Home            0x73
#define kVK_PageUp          0x74
#define kVK_ForwardDelete   0x75
#define kVK_F4              0x76
#define kVK_End             0x77
#define kVK_F2              0x78
#define kVK_PageDown        0x79
#define kVK_F1              0x7A
#define kVK_LeftArrow       0x7B
#define kVK_RightArrow      0x7C
#define kVK_DownArrow       0x7D
#define kVK_UpArrow         0x7E

void LDL_KeyMapperInit(LDL_KeyMapper* keyMapper)
{
    if (keyMapper)
    {
        LDL_KeyMappingInit(&keyMapper->Mapping);

        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Command,      LDL_KeyLSystem);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Option,       LDL_KeyRSystem);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Help,         LDL_KeyMenu);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Semicolon,    LDL_KeySemicolon);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Slash,        LDL_KeySlash);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Equal,        LDL_KeyEqual);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Minus,        LDL_KeyHyphen);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_LeftBracket,  LDL_KeyLBracket);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_RightBracket, LDL_KeyRBracket);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Comma,        LDL_KeyComma);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Period,       LDL_KeyPeriod);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Backslash,    LDL_KeyBackslash);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Escape,        LDL_KeyEscape);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Space,         LDL_KeySpace);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Return,        LDL_KeyEnter);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Delete,        LDL_KeyBackspace);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Tab,           LDL_KeyTab);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_PageUp,        LDL_KeyPageUp);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_PageDown,      LDL_KeyPageDown);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_End,           LDL_KeyEnd);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Home,          LDL_KeyHome);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Help,          LDL_KeyInsert);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ForwardDelete, LDL_KeyDelete);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_KeypadPlus,     LDL_KeyAdd);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_KeypadMinus,    LDL_KeySubtract);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_KeypadMultiply, LDL_KeyMultiply);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_KeypadDivide,   LDL_KeyDivide);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F1,  LDL_KeyF1);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F2,  LDL_KeyF2);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F3,  LDL_KeyF3);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F4,  LDL_KeyF4);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F5,  LDL_KeyF5);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F6,  LDL_KeyF6);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F7,  LDL_KeyF7);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F8,  LDL_KeyF8);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F9,  LDL_KeyF9);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F10, LDL_KeyF10);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F11, LDL_KeyF11);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F12, LDL_KeyF12);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F13, LDL_KeyF13);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F14, LDL_KeyF14);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_F15, LDL_KeyF15);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_LeftArrow,  LDL_KeyLeft);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_RightArrow, LDL_KeyRight);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_UpArrow,    LDL_KeyUp);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_DownArrow,  LDL_KeyDown);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad0, LDL_KeyNumpad0);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad1, LDL_KeyNumpad1);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad2, LDL_KeyNumpad2);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad3, LDL_KeyNumpad3);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad4, LDL_KeyNumpad4);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad5, LDL_KeyNumpad5);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad6, LDL_KeyNumpad6);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad7, LDL_KeyNumpad7);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad8, LDL_KeyNumpad8);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Keypad9, LDL_KeyNumpad9);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_A, LDL_KeyA);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Z, LDL_KeyZ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_E, LDL_KeyE);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_R, LDL_KeyR);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_T, LDL_KeyT);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Y, LDL_KeyY);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_U, LDL_KeyU);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_I, LDL_KeyI);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_O, LDL_KeyO);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_P, LDL_KeyP);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_Q, LDL_KeyQ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_S, LDL_KeyS);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_D, LDL_KeyD);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_F, LDL_KeyF);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_G, LDL_KeyG);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_H, LDL_KeyH);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_J, LDL_KeyJ);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_K, LDL_KeyK);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_L, LDL_KeyL);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_M, LDL_KeyM);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_W, LDL_KeyW);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_X, LDL_KeyX);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_C, LDL_KeyC);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_V, LDL_KeyV);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_B, LDL_KeyB);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_N, LDL_KeyN);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_0, LDL_KeyNum0);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_1, LDL_KeyNum1);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_2, LDL_KeyNum2);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_3, LDL_KeyNum3);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_4, LDL_KeyNum4);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_5, LDL_KeyNum5);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_6, LDL_KeyNum6);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_7, LDL_KeyNum7);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_8, LDL_KeyNum8);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_ANSI_9, LDL_KeyNum9);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Shift,        LDL_KeyLeftShift);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_RightShift,   LDL_KeyRightShift);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_Control,      LDL_KeyLeftControl);
        LDL_KeyMappingAdd(&keyMapper->Mapping, kVK_RightControl, LDL_KeyRightControl);
    }
}

uint8_t LDL_KeyMapperConvertKey(LDL_KeyMapper* keyMapper, uint32_t key)
{
    if (keyMapper)
    {
        return LDL_KeyMappingFindKey(&keyMapper->Mapping, key);
    }

    return LDL_KeyUnknown;
}
