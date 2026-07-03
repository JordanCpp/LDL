/**
* @file LDL_Enums.h
* @brief Defines various enumerations for events, window modes, input states, and keyboard keys.
* @author Evgeny Zoshchuk (JordanCpp)
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
*
* These values are used to identify the type of event that has occurred
* in the event processing system. Each event type corresponds to a specific
* user interaction or system notification.
*
* @{
*/
enum
{
    LDL_EventIsQuit = 1,    /**< Application quit event - triggered when user closes the window.*/
    LDL_EventIsMouseMove,   /**< Mouse movement event - triggered when cursor position changes.*/
    LDL_EventIsMouseClick,  /**< Mouse button click event - triggered on mouse button press/release.*/
    LDL_EventIsResize,      /**< Window resize event - triggered when window dimensions change.*/
    LDL_EventIsKeyboard,    /**< Keyboard input event - triggered on key press/release.*/
    LDL_EventIsGainedFocus, /**< Window gained focus event - triggered when window becomes active.*/
    LDL_EventIsLostFocus,   /**< Window lost focus event - triggered when window becomes inactive.*/
    LDL_EventIsMouseScroll  /**< Mouse scroll wheel event - triggered on scroll wheel movement.*/
};
/** @}*/

/**
* @name Window Mode Flags
* @brief Bitwise flags representing different window states and modes.
*
* These flags can be combined using bitwise OR operations to specify
* multiple window states simultaneously.
*
* @{
*/
enum
{
    LDL_WindowModeFullScreen = 1 << 1, /**< Fullscreen mode - window occupies entire screen.*/
    LDL_WindowModeResized = 1 << 2,/**< Window has been resized - indicates recent resize operation.*/
    LDL_WindowModeFixed = 1 << 3,  /**< Fixed window size - window cannot be resized by user.*/
    LDL_WindowModeMinimized = 1 << 4,  /**< Window is minimized - window is hidden in taskbar.*/
    LDL_WindowModeMaximized = 1 << 5,  /**< Window is maximized - window occupies full desktop area.*/
    LDL_WindowModeCentered = 1 << 6/**< Window is centered - window positioned at screen center.*/
};
/** @}*/

/**
* @name Button States
* @brief Represents the physical state of a button.
*
* These values indicate whether a button (mouse or keyboard) is currently
* pressed or released.
*
* @{
*/
enum
{
    LDL_ButtonStatePressed = 1, /**< Button is currently held down.*/
    LDL_ButtonStateReleased /**< Button has been released (not currently pressed).*/
};
/** @}*/

/**
* @name Mouse Button Identifiers
* @brief Identifiers for standard mouse buttons.
*
* These values identify which mouse button was involved in a mouse event.
*
* @{
*/
enum
{
    LDL_MouseButtonLeft = 1,   /**< Left mouse button - primary button.*/
    LDL_MouseButtonRight,  /**< Right mouse button - secondary button.*/
    LDL_MouseButtonMiddle  /**< Middle mouse button - scroll wheel click.*/
};
/** @}*/

/**
* @name Mouse Scroll Direction
* @brief Identifiers for the axis of mouse scrolling.
*
* These values indicate the direction of mouse scroll wheel movement.
*
* @{
*/
enum
{
    LDL_MouseScrollVertical = 1,   /**< Vertical scroll axis - up/down scrolling.*/
    LDL_MouseScrollHorizontal  /**< Horizontal scroll axis - left/right scrolling.*/
};
/** @}*/

/**
* @typedef LDL_ContextType
* @brief Defines the type of rendering context used by the application.
*
* This enumeration specifies the rendering backend or API that the
* application will use for drawing operations.
*
* @var LDL_ContextSoftware
* Software-based rendering - uses CPU for all rendering operations.
*
* @var LDL_ContextOpenGLLegacy
* Legacy OpenGL rendering context - supports fixed-function pipeline (OpenGL 1.x-2.x).
*
* @var LDL_ContextOpenGLHybrid
* Hybrid OpenGL rendering context - combines legacy and modern features.
*
* @var LDL_ContextOpenGLModern
* Modern OpenGL rendering context - uses core profile (OpenGL 3.x+).
*
* @var LDL_ContextMax
* Sentinel value representing the total number of context types.
*
* @note The context type affects which rendering functions are available.
* @note Some context types may not be supported on all platforms.
*/
typedef enum LDL_ContextType
{
    LDL_ContextSoftware = 1,/**< Software-based rendering - CPU rendered.*/
    LDL_ContextOpenGLLegacy,/**< Legacy OpenGL rendering context - fixed-function pipeline.*/
    LDL_ContextOpenGLHybrid,/**< Hybrid OpenGL rendering context - mixed legacy/modern.*/
    LDL_ContextOpenGLModern,/**< Modern OpenGL (Core Profile) rendering context - shader-based.*/
    LDL_ContextMax          /**< Sentinel value representing the total number of contexts.*/
} LDL_ContextType;

/**
* @name Keyboard Key Codes
* @brief Enumeration of all supported keyboard keys.
*
* These values represent physical keys on a standard keyboard. They are
* used to identify which key was pressed or released in keyboard events.
*
* The values are organized into logical groups:
* - System keys (Windows/Command, Menu)
* - Symbol keys (;, /, =, -, [, ], etc.)
* - Navigation keys (Arrow keys, Page Up/Down, Home, End, etc.)
* - Function keys (F1-F15)
* - Number pad keys (Numpad 0-9)
* - Alphanumeric keys (A-Z, 0-9)
* - Modifier keys (Shift, Control)
*
* @{
*/
enum
{
    LDL_KeyUnknown = 1,     /**< Unknown or unmapped key.*/
    LDL_KeyLSystem,         /**< Left System key (Windows key on Windows, Command key on macOS).*/
    LDL_KeyRSystem,         /**< Right System key (Windows key on Windows, Command key on macOS).*/
    LDL_KeyMenu,            /**< Menu/App key - opens context menu.*/
    LDL_KeySemicolon,       /**< Semicolon key (;).*/
    LDL_KeySlash,           /**< Slash key (/).*/
    LDL_KeyEqual,           /**< Equal key (=).*/
    LDL_KeyHyphen,          /**< Hyphen/Minus key (-).*/
    LDL_KeyLBracket,        /**< Left bracket key ([).*/
    LDL_KeyRBracket,        /**< Right bracket key (]).*/
    LDL_KeyComma,           /**< Comma key (,).*/
    LDL_KeyPeriod,          /**< Period/Dot key (.).*/
    LDL_KeyQuote,           /**< Quote key (').*/
    LDL_KeyBackslash,       /**< Backslash key (\).*/
    LDL_KeyTilde,           /**< Tilde/Grave accent key (~).*/
    LDL_KeyEscape,          /**< Escape key - typically cancels current operation.*/
    LDL_KeySpace,           /**< Spacebar - produces space character.*/
    LDL_KeyEnter,           /**< Enter/Return key - confirms input or new line.*/
    LDL_KeyBackspace,       /**< Backspace key - deletes previous character.*/
    LDL_KeyTab,             /**< Tab key - moves focus or inserts tab character.*/
    LDL_KeyPageUp,          /**< Page Up key - scrolls one page up.*/
    LDL_KeyPageDown,        /**< Page Down key - scrolls one page down.*/
    LDL_KeyEnd,             /**< End key - moves cursor to end of line/document.*/
    LDL_KeyHome,            /**< Home key - moves cursor to beginning of line/document.*/
    LDL_KeyInsert,          /**< Insert key - toggles insert/overwrite mode.*/
    LDL_KeyDelete,          /**< Delete key - deletes next character or selection.*/
    LDL_KeyAdd,             /**< Plus key (+) on keypad.*/
    LDL_KeySubtract,        /**< Minus/Subtraction key (-) on keypad.*/
    LDL_KeyMultiply,        /**< Multiplication key (*) on keypad.*/
    LDL_KeyDivide,          /**< Division key (/) on keypad.*/
    LDL_KeyPause,           /**< Pause/Break key - pauses execution or scrolling.*/
    LDL_KeyF1,              /**< Function key F1 - often used for help.*/
    LDL_KeyF2,              /**< Function key F2 - often used for rename.*/
    LDL_KeyF3,              /**< Function key F3 - often used for search.*/
    LDL_KeyF4,              /**< Function key F4 - often used for address bar or close.*/
    LDL_KeyF5,              /**< Function key F5 - often used for refresh.*/
    LDL_KeyF6,              /**< Function key F6 - often used for navigation.*/
    LDL_KeyF7,              /**< Function key F7 - often used for spell check.*/
    LDL_KeyF8,              /**< Function key F8 - often used for startup or safe mode.*/
    LDL_KeyF9,              /**< Function key F9 - often used for debugging or mail.*/
    LDL_KeyF10,             /**< Function key F10 - often used for menu bar.*/
    LDL_KeyF11,             /**< Function key F11 - often used for fullscreen.*/
    LDL_KeyF12,             /**< Function key F12 - often used for developer tools.*/
    LDL_KeyF13,             /**< Function key F13 - additional function key.*/
    LDL_KeyF14,             /**< Function key F14 - additional function key.*/
    LDL_KeyF15,             /**< Function key F15 - additional function key.*/
    LDL_KeyLeft,            /**< Left Arrow key - moves cursor left.*/
    LDL_KeyRight,           /**< Right Arrow key - moves cursor right.*/
    LDL_KeyUp,              /**< Up Arrow key - moves cursor up.*/
    LDL_KeyDown,            /**< Down Arrow key - moves cursor down.*/
    LDL_KeyNumpad0,         /**< Numpad 0 key.*/
    LDL_KeyNumpad1,         /**< Numpad 1 key.*/
    LDL_KeyNumpad2,         /**< Numpad 2 key.*/
    LDL_KeyNumpad3,         /**< Numpad 3 key.*/
    LDL_KeyNumpad4,         /**< Numpad 4 key.*/
    LDL_KeyNumpad5,         /**< Numpad 5 key.*/
    LDL_KeyNumpad6,         /**< Numpad 6 key.*/
    LDL_KeyNumpad7,         /**< Numpad 7 key.*/
    LDL_KeyNumpad8,         /**< Numpad 8 key.*/
    LDL_KeyNumpad9,         /**< Numpad 9 key.*/
    LDL_KeyA,               /**< 'A' key.*/
    LDL_KeyZ,               /**< 'Z' key.*/
    LDL_KeyE,               /**< 'E' key.*/
    LDL_KeyR,               /**< 'R' key.*/
    LDL_KeyT,               /**< 'T' key.*/
    LDL_KeyY,               /**< 'Y' key.*/
    LDL_KeyU,               /**< 'U' key.*/
    LDL_KeyI,               /**< 'I' key.*/
    LDL_KeyO,               /**< 'O' key.*/
    LDL_KeyP,               /**< 'P' key.*/
    LDL_KeyQ,               /**< 'Q' key.*/
    LDL_KeyS,               /**< 'S' key.*/
    LDL_KeyD,               /**< 'D' key.*/
    LDL_KeyF,               /**< 'F' key.*/
    LDL_KeyG,               /**< 'G' key.*/
    LDL_KeyH,               /**< 'H' key.*/
    LDL_KeyJ,               /**< 'J' key.*/
    LDL_KeyK,               /**< 'K' key.*/
    LDL_KeyL,               /**< 'L' key.*/
    LDL_KeyM,               /**< 'M' key.*/
    LDL_KeyW,               /**< 'W' key.*/
    LDL_KeyX,               /**< 'X' key.*/
    LDL_KeyC,               /**< 'C' key.*/
    LDL_KeyV,               /**< 'V' key.*/
    LDL_KeyB,               /**< 'B' key.*/
    LDL_KeyN,               /**< 'N' key.*/
    LDL_KeyNum0,            /**< Top-row number 0 key.*/
    LDL_KeyNum1,            /**< Top-row number 1 key.*/
    LDL_KeyNum2,            /**< Top-row number 2 key.*/
    LDL_KeyNum3,            /**< Top-row number 3 key.*/
    LDL_KeyNum4,            /**< Top-row number 4 key.*/
    LDL_KeyNum5,            /**< Top-row number 5 key.*/
    LDL_KeyNum6,            /**< Top-row number 6 key.*/
    LDL_KeyNum7,            /**< Top-row number 7 key.*/
    LDL_KeyNum8,            /**< Top-row number 8 key.*/
    LDL_KeyNum9,            /**< Top-row number 9 key.*/
    LDL_KeyLeftShift,       /**< Left Shift key - modifies key behavior.*/
    LDL_KeyRightShift,      /**< Right Shift key - modifies key behavior.*/
    LDL_KeyLeftControl,     /**< Left Control key - keyboard shortcut modifier.*/
    LDL_KeyRightControl     /**< Right Control key - keyboard shortcut modifier.*/
};
/** @}*/

#endif // LDL_Enums_H
