/**
 * @file LDL_Enums_H
 * @brief Defines various enumerations for events, window modes, input states, and keyboard keys.
 *
 * This file contains all the fundamental enumeration types used within the LDL library
 * to handle input processing, window management, and rendering context types.
 *
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp).
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 */

#ifndef LDL_Enums_H
#define LDL_Enums_H

 /**
  * @name Event Types
  * @brief Identifiers for different types of system and input events.
  * @{
  */
enum
{
	LDL_EventIsQuit = 1,        /**< Application quit event. */
	LDL_EventIsMouseMove,       /**< Mouse movement event. */
	LDL_EventIsMouseClick,      /**< Mouse button click event. */
	LDL_EventIsResize,          /**< Window resize event. */
	LDL_EventIsKeyboard,        /**< Keyboard input event. */
	LDL_EventIsGainedFocus,     /**< Window gained focus event. */
	LDL_EventIsLostFocus,       /**< Window lost focus event. */
	LDL_EventIsMouseScroll      /**< Mouse scroll wheel event. */
};
/** @} */

/**
 * @name Window Mode Flags
 * @brief Bitwise flags representing different window states and modes.
 * @{
 */
enum
{
	LDL_WindowModeFullScreen = 1 << 1, /**< Fullscreen mode. */
	LDL_WindowModeResized = 1 << 2, /**< Window has been resized. */
	LDL_WindowModeFixed = 1 << 3, /**< Fixed window size (non-resizable). */
	LDL_WindowModeMinimized = 1 << 4, /**< Window is minimized. */
	LDL_WindowModeMaximized = 1 << 5, /**< Window is maximized. */
	LDL_WindowModeCentered = 1 << 6  /**< Window is positioned in the center of the screen. */
};
/** @} */

/**
 * @name Button States
 * @brief Represents the physical state of a button.
 * @{
 */
enum
{
	LDL_ButtonStatePressed = 1, /**< Button is currently held down. */
	LDL_ButtonStateReleased             /**< Button has been released. */
};
/** @} */

/**
 * @name Mouse Button Identifiers
 * @brief Identifiers for standard mouse buttons.
 * @{
 */
enum
{
	LDL_MouseButtonLeft = 1,   /**< Left mouse button. */
	LDL_MouseButtonRight,      /**< Right mouse button. */
	LDL_MouseButtonMiddle      /**< Middle mouse button (scroll wheel click). */
};
/** @} */

/**
 * @name Mouse Scroll Direction
 * @brief Identifiers for the axis of mouse scrolling.
 * @{
 */
enum
{
	LDL_MouseScrollVertical = 1,   /**< Vertical scroll axis. */
	LDL_MouseScrollHorizontal      /**< Horizontal scroll axis. */
};
/** @} */

/**
 * @brief Defines the type of rendering context used by the application.
 */
typedef enum LDL_ContextType
{
	LDL_ContextSoftware = 1,    /**< Software-based rendering. */
	LDL_ContextOpenGLLegacy,    /**< Legacy OpenGL rendering context. */
	LDL_ContextOpenGLHybrid,    /**< Hybrid OpenGL rendering context. */
	LDL_ContextOpenGLModern,    /**< Modern OpenGL (Core Profile) rendering context. */
	LDL_ContextMax              /**< Sentinel value representing the total number of contexts. */
} LDL_ContextType;

/**
 * @name Keyboard Key Codes
 * @brief Enumeration of all supported keyboard keys.
 * @{
 */
enum
{
	LDL_KeyUnknown = 1,         /**< Unknown or unmapped key. */
	LDL_KeyLSystem,             /**< Left System key (e.g., Windows/Command). */
	LDL_KeyRSystem,             /**< Right System key. */
	LDL_KeyMenu,                /**< Menu/App key. */
	LDL_KeySemicolon,           /**< Semicolon key (;). */
	LDL_KeySlash,               /**< Slash key (/). */
	LDL_KeyEqual,               /**< Equal key (=). */
	LDL_KeyHyphen,              /**< Hyphen/Minus key (-). */
	LDL_KeyLBracket,            /**< Left bracket key ([). */
	LDL_KeyRBracket,            /**< Right bracket key (]). */
	LDL_KeyComma,               /**< Comma key (,). */
	LDL_KeyPeriod,              /**< Period/Dot key (.). */
	LDL_KeyQuote,               /**< Quote key ('). */
	LDL_KeyBackslash,           /**< Backslash key (\). */
	LDL_KeyTilde,               /**< Tilde/Grave accent key (~). */
	LDL_KeyEscape,              /**< Escape key. */
	LDL_KeySpace,               /**< Spacebar. */
	LDL_KeyEnter,               /**< Enter/Return key. */
	LDL_KeyBackspace,           /**< Backspace key. */
	LDL_KeyTab,                 /**< Tab key. */
	LDL_KeyPageUp,              /**< Page Up key. */
	LDL_KeyPageDown,            /**< Page Down key. */
	LDL_KeyEnd,                 /**< End key. */
	LDL_KeyHome,                /**< Home key. */
	LDL_KeyInsert,              /**< Insert key. */
	LDL_KeyDelete,              /**< Delete key. */
	LDL_KeyAdd,                 /**< Plus key (+). */
	LDL_KeySubtract,            /**< Minus/Subtraction key (-). */
	LDL_KeyMultiply,            /**< Multiplication key (*). */
	LDL_KeyDivide,              /**< Division key (/). */
	LDL_KeyPause,               /**< Pause/Break key. */
	LDL_KeyF1,                  /**< Function key F1. */
	LDL_KeyF2,                  /**< Function key F2. */
	LDL_KeyF3,                  /**< Function key F3. */
	LDL_KeyF4,                  /**< Function key F4. */
	LDL_KeyF5,                  /**< Function key F5. */
	LDL_KeyF6,                  /**< Function key F6. */
	LDL_KeyF7,                  /**< Function key F7. */
	LDL_KeyF8,                  /**< Function key F8. */
	LDL_KeyF9,                  /**< Function key F9. */
	LDL_KeyF10,                 /**< Function                key F10. */
	LDL_KeyF11,                 /**< Function key F11. */
	LDL_KeyF12,                 /**< Function key F12. */
	LDL_KeyF13,                 /**< Function key F13. */
	LDL_KeyF14,                 /**< Function key F14. */
	LDL_KeyF15,                 /**< Function key F15. */
	LDL_KeyLeft,                /**< Left Arrow key. */
	LDL_KeyRight,               /**< Right Arrow key. */
	LDL_KeyUp,                  /**< Up Arrow key. */
	LDL_KeyDown,                /**< Down Arrow key. */
	LDL_KeyNumpad0,             /**< Numpad 0. */
	LDL_KeyNumpad1,             /**< Numpad 1. */
	LDL_KeyNumpad2,             /**< Numpad 2. */
	LDL_KeyNumpad3,             /**< Numpad 3. */
	LDL_KeyNumpad4,             /**< Numpad 4. */
	LDL_KeyNumpad5,             /**< Numpad 5. */
	LDL_KeyNumpad6,             /**< Numpad 6. */
	LDL_KeyNumpad7,             /**< Numpad 7. */
	LDL_KeyNumpad8,             /**< Numpad 8. */
	LDL_KeyNumpad9,             /**< Numpad 9. */
	LDL_KeyA,                   /**< 'A' key. */
	LDL_KeyZ,                   /**< 'Z' key. */
	LDL_KeyE,                   /**< 'E' key. */
	LDL_KeyR,                   /**< 'R' key. */
	LDL_KeyT,                   /**< 'T' key. */
	LDL_KeyY,                   /**< 'Y' key. */
	LDL_KeyU,                   /**< 'U' key. */
	LDL_KeyI,                   /**< 'I' key. */
	LDL_KeyO,                   /**< 'O' key. */
	LDL_KeyP,                   /**< 'P' key. */
	LDL_KeyQ,                   /**< 'Q' key. */
	LDL_KeyS,                   /**< 'S' key. */
	LDL_KeyD,                   /**< 'D' key. */
	LDL_KeyF,                   /**< 'F' key. */
	LDL_KeyG,                   /**< 'G' key. */
	LDL_KeyH,                   /**< 'H' key. */
	LDL_KeyJ,                   /**< 'J' key. */
	LDL_KeyK,                   /**< 'K' key. */
	LDL_KeyL,                   /**< 'L' key. */
	LDL_KeyM,                   /**< 'M' key. */
	LDL_KeyW,                   /**< 'W' key. */
	LDL_KeyX,                   /**< 'X' key. */
	LDL_KeyC,                   /**< 'C' key. */
	LDL_KeyV,                   /**< 'V' key. */
	LDL_KeyB,                   /**< 'B' key. */
	LDL_KeyN,                   /**< 'N' key. */
	LDL_KeyNum0,                /**< Top-row number 0. */
	LDL_KeyNum1,                /**< Top-row number 1. */
	LDL_KeyNum2,                /**< Top-row number 2. */
	LDL_KeyNum3,                /**< Top-row number 3. */
	LDL_KeyNum4,                /**< Top-row number 4. */
	LDL_KeyNum5,                /**< Top-row number 5. */
	LDL_KeyNum6,                /**< Top-row number 6. */
	LDL_KeyNum7,                /**< Top-row number 7. */
	LDL_KeyNum8,                /**< Top-row number 8. */
	LDL_KeyNum9,                /**< Top-row number 9. */
	LDL_KeyLeftShift,           /**< Left Shift key. */
	LDL_KeyRightShift,          /**< Right Shift key. */
	LDL_KeyLeftControl,         /**< Left Control key. */
	LDL_KeyRightControl         /**< Right Control key. */
};
/** @} */

#endif // LDL_Enums_H
