/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_Enums_H
#define LDL_Enums_H

enum
{
	LDL_EventIsQuit = 1,
	LDL_EventIsMouseMove,
	LDL_EventIsMouseClick,
	LDL_EventIsResize,
	LDL_EventIsKeyboard,
	LDL_EventIsGainedFocus,
	LDL_EventIsLostFocus,
	LDL_EventIsMouseScroll
};

enum
{
	LDL_WindowModeFullScreen = 1 << 1,
	LDL_WindowModeResized    = 1 << 2,
	LDL_WindowModeFixed      = 1 << 3,
	LDL_WindowModeMinimized  = 1 << 4,
	LDL_WindowModeMaximized  = 1 << 5,
	LDL_WindowModeCentered   = 1 << 6
};

enum
{
	LDL_ButtonStatePressed = 1,
	LDL_ButtonStateReleased
};

enum
{
	LDL_MouseButtonLeft = 1,
	LDL_MouseButtonRight,
	LDL_MouseButtonMiddle
};

enum
{
	LDL_MouseScrollVertical = 1,
	LDL_MouseScrollHorizontal
};

enum
{
	LDL_RenderModeSoftware = 1,
	LDL_RenderModeOpenGL1,
	LDL_RenderModeOpenGL3,
	LDL_RenderModeMax
};

enum
{
	LDL_KeyUnknown = 1,
	LDL_KeyLSystem,
	LDL_KeyRSystem,
	LDL_KeyMenu,
	LDL_KeySemicolon,
	LDL_KeySlash,
	LDL_KeyEqual,
	LDL_KeyHyphen,
	LDL_KeyLBracket,
	LDL_KeyRBracket,
	LDL_KeyComma,
	LDL_KeyPeriod,
	LDL_KeyQuote,
	LDL_KeyBackslash,
	LDL_KeyTilde,
	LDL_KeyEscape,
	LDL_KeySpace,
	LDL_KeyEnter,
	LDL_KeyBackspace,
	LDL_KeyTab,
	LDL_KeyPageUp,
	LDL_KeyPageDown,
	LDL_KeyEnd,
	LDL_KeyHome,
	LDL_KeyInsert,
	LDL_KeyDelete,
	LDL_KeyAdd,
	LDL_KeySubtract,
	LDL_KeyMultiply,
	LDL_KeyDivide,
	LDL_KeyPause,
	LDL_KeyF1,
	LDL_KeyF2,
	LDL_KeyF3,
	LDL_KeyF4,
	LDL_KeyF5,
	LDL_KeyF6,
	LDL_KeyF7,
	LDL_KeyF8,
	LDL_KeyF9,
	LDL_KeyF10,
	LDL_KeyF11,
	LDL_KeyF12,
	LDL_KeyF13,
	LDL_KeyF14,
	LDL_KeyF15,
	LDL_KeyLeft,
	LDL_KeyRight,
	LDL_KeyUp,
	LDL_KeyDown,
	LDL_KeyNumpad0,
	LDL_KeyNumpad1,
	LDL_KeyNumpad2,
	LDL_KeyNumpad3,
	LDL_KeyNumpad4,
	LDL_KeyNumpad5,
	LDL_KeyNumpad6,
	LDL_KeyNumpad7,
	LDL_KeyNumpad8,
	LDL_KeyNumpad9,
	LDL_KeyA,
	LDL_KeyZ,
	LDL_KeyE,
	LDL_KeyR,
	LDL_KeyT,
	LDL_KeyY,
	LDL_KeyU,
	LDL_KeyI,
	LDL_KeyO,
	LDL_KeyP,
	LDL_KeyQ,
	LDL_KeyS,
	LDL_KeyD,
	LDL_KeyF,
	LDL_KeyG,
	LDL_KeyH,
	LDL_KeyJ,
	LDL_KeyK,
	LDL_KeyL,
	LDL_KeyM,
	LDL_KeyW,
	LDL_KeyX,
	LDL_KeyC,
	LDL_KeyV,
	LDL_KeyB,
	LDL_KeyN,
	LDL_KeyNum0,
	LDL_KeyNum1,
	LDL_KeyNum2,
	LDL_KeyNum3,
	LDL_KeyNum4,
	LDL_KeyNum5,
	LDL_KeyNum6,
	LDL_KeyNum7,
	LDL_KeyNum8,
	LDL_KeyNum9,
	LDL_KeyLeftShift,
	LDL_KeyRightShift,
	LDL_KeyLeftControl,
	LDL_KeyRightControl
};

#endif
