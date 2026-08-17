/**
 * @file LDL_Events.h
 * @brief Defines structures and functions for event handling within the LDL library.
 * @author Evgeny Zoshchuk (JordanCpp)
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp).
 *
 * This file defines a unified event system that encapsulates various input and windowing
 * events, such as keyboard, mouse, resize, focus, and quit events, into a single structure.
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

#ifndef LDL_Events_H
#define LDL_Events_H

#include <LDL/Config.h>
#include <LDL/Types.h>
#include <LDL/Enums.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_EventGainedFocus
* @brief Represents an event triggered when a window or application gains input focus.
*
* This event occurs when the window becomes the active window and receives
* keyboard and mouse input.
*/
typedef struct LDL_EventGainedFocus
    {
    /** @brief The specific type identifier for the gained focus event (LDL_EventIsGainedFocus). */
        uint8_t Type;
    } LDL_EventGainedFocus;

/**
* @struct LDL_EventKeyboard
* @brief Represents an event related to keyboard input, such as key presses or releases.
*
* This event contains information about the state of a keyboard key and
* which key was involved in the event.
*/
typedef struct LDL_EventKeyboard
    {
    /** @brief The current state of the key (LDL_ButtonStatePressed or LDL_ButtonStateReleased). */
        uint8_t State;
    /** @brief The identifier representing the specific keyboard key involved in the event. */
        uint8_t Key;
    } LDL_EventKeyboard;

/**
* @struct LDL_EventLostFocus
* @brief Represents an event triggered when a window or application loses input focus.
*
* This event occurs when the window becomes inactive and no longer receives
* keyboard and mouse input.
*/
typedef struct LDL_EventLostFocus
    {
    /** @brief The specific type identifier for the lost focus event (LDL_EventIsLostFocus). */
        uint8_t Type;
    } LDL_EventLostFocus;

/**
* @struct LDL_EventMouse
* @brief Represents an event related to mouse movement, button clicks, or scroll wheel interaction.
*
* This event contains comprehensive mouse state information including
* cursor position, relative movement, button states, and scroll wheel data.
*/
typedef struct LDL_EventMouse
    {
    /** @brief The current state of the mouse button (LDL_ButtonStatePressed or LDL_ButtonStateReleased). */
        uint8_t State;
    /** @brief The identifier representing which mouse button was involved (LDL_MouseButtonLeft, etc.). */
        uint8_t Button;
    /** @brief The horizontal position of the cursor in screen coordinates. */
        int32_t PosX;
    /** @brief The vertical position of the cursor in screen coordinates. */
        int32_t PosY;
    /** @brief The relative horizontal movement of the mouse since the previous event (delta X). */
        int32_t PosRelX;
    /** @brief The relative vertical movement of the mouse since the previous event (delta Y). */
        int32_t PosRelY;
    /** @brief The current value or position of the mouse scroll wheel. */
        int32_t Scroll;
    /** @brief The change in the scroll wheel position during this specific event (delta scroll). */
        int32_t Delta;
    } LDL_EventMouse;

/**
* @struct LDL_EventQuit
* @brief Represents an event signaling that the application or window has requested to terminate.
*
* This event is triggered when the user closes the window or the application
* programmatically requests termination.
*/
typedef struct LDL_EventQuit
    {
    /** @brief The specific type identifier for the quit event (LDL_EventIsQuit). */
        uint8_t Type;
    } LDL_EventQuit;

/**
* @struct LDL_EventResize
* @brief Represents an event triggered when the dimensions of a window are changed.
*
* This event provides the new width and height of the window after a resize operation.
*/
typedef struct LDL_EventResize
    {
    /** @brief The new width of the window in pixels. */
        uint32_t Width;
    /** @brief The new height of the window in pixels. */
        uint32_t Height;
    } LDL_EventResize;

/**
* @struct LDL_Event
* @brief A unified structure that encapsulates all possible event types within a single object.
*
* This structure uses a type identifier to determine which member of the internal union
* is currently active and contains valid event data. This design allows for efficient
* event handling through a single event type while supporting multiple event variants.
*
* Event types:
* - LDL_EventIsQuit: Application quit request
* - LDL_EventIsMouseMove: Mouse movement
* - LDL_EventIsMouseClick: Mouse button click
* - LDL_EventIsResize: Window resize
* - LDL_EventIsKeyboard: Keyboard input
* - LDL_EventIsGainedFocus: Window gained focus
* - LDL_EventIsLostFocus: Window lost focus
* - LDL_EventIsMouseScroll: Mouse scroll wheel
*
* @note Always check the Type field before accessing union members to ensure valid data.
* @see LDL_EventQuit
* @see LDL_EventMouse
* @see LDL_EventResize
* @see LDL_EventKeyboard
* @see LDL_EventGainedFocus
* @see LDL_EventLostFocus
*/
typedef struct LDL_Event
    {
    /** @brief An unsigned eight-bit integer identifying the specific type of event contained in the union. */
        uint8_t Type;

    /**
    * @brief A union containing the specialized structures for each unique event type.
    *
    * Only one member of this union is valid at a time, determined by the Type field.
    */
        union
        {
        /** @brief Data for a quit event (LDL_EventIsQuit). */
            LDL_EventQuit        Quit;
        /** @brief Data for a mouse movement or button event (LDL_EventIsMouseMove, LDL_EventIsMouseClick, LDL_EventIsMouseScroll). */
            LDL_EventMouse       Mouse;
        /** @brief Data for a window resizing event (LDL_EventIsResize). */
            LDL_EventResize      Resize;
        /** @brief Data for a keyboard input event (LDL_EventIsKeyboard). */
            LDL_EventKeyboard    Keyboard;
        /** @brief Data for a gained focus event (LDL_EventIsGainedFocus). */
            LDL_EventGainedFocus GainedFocus;
        /** @brief Data for a lost focus event (LDL_EventIsLostFocus). */
            LDL_EventLostFocus   LostFocus;
        } u;
    } LDL_Event;

/**
* @brief Checks if a specific keyboard key is currently in a pressed state within the provided event.
*
* This function validates that the event is a keyboard event and that the specified
* key is in the pressed state.
*
* @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
* @param key   The identifier of the keyboard key to check (from LDL_Key enumeration).
* @return      A boolean value that is true if the specified key is in a pressed state; otherwise, false.
*
* @note The event must be of type LDL_EventIsKeyboard for this function to return true.
* @see LDL_EventIsKeyReleased
* @see LDL_Key enumeration
*/
LDL_LIBRARY bool LDL_EventIsKeyPressed(LDL_Event* event, uint8_t key);

/**
* @brief Checks if a specific keyboard key is currently in a released state within the provided event.
*
* This function validates that the event is a keyboard event and that the specified
* key is in the released state.
*
* @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
* @param key   The identifier of the keyboard key to check (from LDL_Key enumeration).
* @return      A boolean value that is true if the specified key is in a released state; otherwise, false.
*
* @note The event must be of type LDL_EventIsKeyboard for this function to return true.
* @see LDL_EventIsKeyPressed
* @see LDL_Key enumeration
*/
LDL_LIBRARY bool LDL_EventIsKeyReleased(LDL_Event* event, uint8_t key);

/**
* @brief Checks if a specific mouse button is currently in a pressed state within the provided event.
*
* This function validates that the event is a mouse event and that the specified
* mouse button is in the pressed state.
*
* @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
* @param key   The identifier of the mouse button to check (LDL_MouseButtonLeft, LDL_MouseButtonRight, or LDL_MouseButtonMiddle).
* @return      A boolean value that is true if the specified mouse button is in a pressed state; otherwise, false.
*
* @note The event must be of type LDL_EventIsMouseClick for this function to return true.
* @see LDL_EventIsMouseReleased
* @see LDL_MouseButton identifiers
*/
LDL_LIBRARY bool LDL_EventIsMousePressed(LDL_Event* event, uint8_t key);

/**
* @brief Checks if a specific mouse button is currently in a released state within the provided event.
*
* This function validates that the event is a mouse event and that the specified
* mouse button is in the released state.
*
* @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
* @param key   The identifier of the mouse button to check (LDL_MouseButtonLeft, LDL_MouseButtonRight, or LDL_MouseButtonMiddle).
* @return      A boolean value that is true if the specified mouse button is in a released state; otherwise, false.
*
* @note The event must be of type LDL_EventIsMouseClick for this function to return true.
* @see LDL_EventIsMousePressed
* @see LDL_MouseButton identifiers
*/
LDL_LIBRARY bool LDL_EventIsMouseReleased(LDL_Event* event, uint8_t key);

#ifdef __cplusplus
}
#endif

#endif
