/**
 * @file LDL_Mouse.h
 * @brief Defines mouse control and manipulation functions.
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

#ifndef LDL_Mouse_H
#define LDL_Mouse_H

#include <LDL/Vec2i.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Retrieves the current position of the mouse cursor.
*
* This function returns the current screen coordinates of the mouse cursor.
* The position is measured in pixels relative to the top-left corner of the
* screen or the active window, depending on the platform and context.
*
* @return An LDL_Vec2i structure containing the current mouse position:
*         - x: Horizontal coordinate (column) in pixels
*         - y: Vertical coordinate (row) in pixels
*
* @note The coordinate system origin (0, 0) is at the top-left corner.
* @note Positive x extends to the right, positive y extends downward.
* @note This function is useful for:
*       - Implementing custom cursor behavior
*       - Tracking mouse input for UI interactions
*       - Game development and camera control
*
* @code
* // Example: Get and display mouse position
* LDL_Vec2i pos = LDL_MouseGetPos();
* printf("Mouse position: (%d, %d)\n", pos.x, pos.y);
* @endcode
*
* @see LDL_MouseSetPos
* @see LDL_Vec2i
*/
LDL_LIBRARY LDL_Vec2i LDL_MouseGetPos();

/**
* @brief Sets the position of the mouse cursor.
*
* This function moves the mouse cursor to the specified screen coordinates.
* The position is measured in pixels relative to the top-left corner of the
* screen or the active window, depending on the platform and context.
*
* @param pos An LDL_Vec2i structure containing the desired mouse position:
*            - x: Horizontal coordinate (column) in pixels
*            - y: Vertical coordinate (row) in pixels
*
* @note The coordinate system origin (0, 0) is at the top-left corner.
* @note Positive x extends to the right, positive y extends downward.
* @note The function may fail or have no effect if:
*       - The coordinates are outside the valid screen bounds
*       - The application does not have permission to control the cursor
*       - The window is not in focus
* @note This function is commonly used for:
*       - Implementing mouse locking or relative mouse movement
*       - Centering the cursor in game applications
*       - Creating custom cursor control schemes
*       - Implementing mouse emulation
*
* @warning On some platforms, this function may generate a mouse movement
*          event that could be processed by the application.
*
* @code
* // Example: Center the mouse cursor at (100, 100)
* LDL_MouseSetPos(LDL_GetVec2i(100, 100));
*
* // Example: Center the mouse cursor on the screen center
* LDL_Vec2i screenSize = LDL_ScreenGetSize(); // Hypothetical function
* LDL_Vec2i center = LDL_GetVec2i(screenSize.x / 2, screenSize.y / 2);
* LDL_MouseSetPos(center);
* @endcode
*
* @see LDL_MouseGetPos
* @see LDL_Vec2i
* @see LDL_GetVec2i
*/
LDL_LIBRARY void LDL_MouseSetPos(LDL_Vec2i pos);

/**
* @brief Hides the mouse cursor.
*
* This function makes the mouse cursor invisible on the screen. The cursor
* remains functional but is not displayed. This is commonly used in
* applications that render custom cursors or want to provide an immersive
* experience (e.g., first-person games, full-screen applications).
*
* @note The cursor is hidden globally or within the active window,
*       depending on the platform.
* @note The cursor will typically reappear when:
*       - The application loses focus
*       - The user moves the cursor outside the window
*       - LDL_MouseShow is called
*       - The application terminates
* @note Use cases:
*       - First-person shooter games with custom crosshairs
*       - Full-screen multimedia applications
*       - Immersive experiences
*       - Screen recording or presentation software
*
* @warning The cursor visibility state is application-specific and may
*          not persist across application switches.
*
* @code
* // Example: Hide cursor for an FPS game
* LDL_MouseHide();
* // Render custom crosshair...
* @endcode
*
* @see LDL_MouseShow
*/
LDL_LIBRARY void LDL_MouseHide();

/**
* @brief Shows the mouse cursor.
*
* This function makes the mouse cursor visible on the screen, reversing
* the effect of LDL_MouseHide. The cursor will be displayed normally
* and will respond to user movement.
*
* @note This function should be called to restore cursor visibility
*       after hiding it.
* @note The cursor is shown globally or within the active window,
*       depending on the platform.
* @note Use cases:
*       - Returning to menus or UI interactions
*       - Exiting full-screen or immersive modes
*       - Debugging or development purposes
*
* @code
* // Example: Show cursor when entering menu mode
* LDL_MouseShow();
* // Now user can interact with UI elements
* @endcode
*
* @see LDL_MouseHide
*/
LDL_LIBRARY void LDL_MouseShow();

#ifdef __cplusplus
}
#endif

#endif
