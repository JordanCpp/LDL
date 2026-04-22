
#include <LDL/Win9x/KMapper.h>
#include <LDL/Win9x/WinX.h>
#include <LDL/Enums.h>

void LDL_KeyMapperInit(LDL_KeyMapper* keyMapper)
{
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_LWIN, LDL_KeyLSystem);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_RWIN, LDL_KeyRSystem);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_APPS, LDL_KeyMenu);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_1, LDL_KeySemicolon);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_2, LDL_KeySlash);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_PLUS, LDL_KeyEqual);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_MINUS, LDL_KeyHyphen);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_4, LDL_KeyLBracket);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_6, LDL_KeyRBracket);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_COMMA, LDL_KeyComma);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_PERIOD, LDL_KeyPeriod);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_7, LDL_KeyQuote);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_5, LDL_KeyBackslash);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_OEM_3, LDL_KeyTilde);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_ESCAPE, LDL_KeyEscape);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_SPACE, LDL_KeySpace);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_RETURN, LDL_KeyEnter);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_BACK, LDL_KeyBackspace);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_TAB, LDL_KeyTab);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_PRIOR, LDL_KeyPageUp);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NEXT, LDL_KeyPageDown);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_END, LDL_KeyEnd);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_HOME, LDL_KeyHome);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_INSERT, LDL_KeyInsert);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_DELETE, LDL_KeyDelete);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_LEFT, LDL_KeyLeft);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_RIGHT, LDL_KeyRight);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_UP, LDL_KeyUp);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_DOWN, LDL_KeyDown);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F1, LDL_KeyF1);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F2, LDL_KeyF2);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F3, LDL_KeyF3);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F4, LDL_KeyF4);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F5, LDL_KeyF5);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F6, LDL_KeyF6);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F7, LDL_KeyF7);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F8, LDL_KeyF8);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F9, LDL_KeyF9);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F10, LDL_KeyF10);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F11, LDL_KeyF11);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F12, LDL_KeyF12);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F13, LDL_KeyF13);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F14, LDL_KeyF14);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_F15, LDL_KeyF15);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD0, LDL_KeyNumpad0);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD1, LDL_KeyNumpad1);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD2, LDL_KeyNumpad2);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD3, LDL_KeyNumpad3);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD4, LDL_KeyNumpad4);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD5, LDL_KeyNumpad5);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD6, LDL_KeyNumpad6);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD7, LDL_KeyNumpad7);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD8, LDL_KeyNumpad8);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_NUMPAD9, LDL_KeyNumpad9);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_ADD, LDL_KeyAdd);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_SUBTRACT, LDL_KeySubtract);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_MULTIPLY, LDL_KeyMultiply);
    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_DIVIDE, LDL_KeyDivide);

    LDL_KeyMappingAdd(&keyMapper->Mapping,VK_PAUSE, LDL_KeyPause);

    LDL_KeyMappingAdd(&keyMapper->Mapping,'A', LDL_KeyA);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'Z', LDL_KeyZ);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'E', LDL_KeyE);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'R', LDL_KeyR);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'T', LDL_KeyT);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'Y', LDL_KeyY);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'U', LDL_KeyU);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'I', LDL_KeyI);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'O', LDL_KeyO);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'P', LDL_KeyP);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'Q', LDL_KeyQ);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'S', LDL_KeyS);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'D', LDL_KeyD);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'F', LDL_KeyF);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'G', LDL_KeyG);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'H', LDL_KeyH);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'J', LDL_KeyJ);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'K', LDL_KeyK);
    LDL_KeyMappingAdd(&keyMapper->Mapping,'W', LDL_KeyW);
}

uint8_t LDL_KeyMapperConvertKey(LDL_KeyMapper* keyMapper, size_t key)
{
    return LDL_KeyMappingFindKey(&keyMapper->Mapping, key);
}
