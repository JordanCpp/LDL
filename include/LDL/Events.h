/**
 * @file LDL_Events.h
 * @brief Header file containing structures and functions for event handling within the LDL library.
 *
 * This file defines a unified event system that encapsulates various input and windowing
 * events, such as keyboard, mouse, resize, focus, and quit events, into a single structure.
 *
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)
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
	 */
	typedef struct LDL_EventGainedFocus
	{
		/** @brief The specific type identifier for the gained focus event. */
		uint8_t Type;
	} LDL_EventGainedFocus;

	/**
	 * @struct LDL_EventKeyboard
	 * @brief Represents an event related to keyboard input, such as key presses or releases.
	 */
	typedef struct LDL_EventKeyboard
	{
		/** @brief The current state of the key (for example, pressed or released). */
		uint8_t State;
		/** @brief The identifier representing the specific keyboard key involved in the event. */
		uint8_t Key;
	} LDL_EventKeyboard;

	/**
	 * @struct LDL_EventLostFocus
	 * @brief Represents an event triggered when a window or application loses input focus.
	 */
	typedef struct LDL_EventLostFocus
	{
		/** @brief The specific type identifier for the lost focus event. */
		uint8_t Type;
	} LDL_EventLostFocus;

	/**
	 * @struct LDL_EventMouse
	 * @brief Represents an event related to mouse movement, button clicks, or scroll wheel interaction.
	 */
	typedef struct LDL_EventMouse
	{
		/** @brief The current state of the mouse button (for example, pressed or released). */
		uint8_t State;
		/** @brief The identifier representing which mouse button was involved in the event. */
		uint8_t Button;
		/** @brief The horizontal position of the cursor in screen coordinates. */
		int32_t PosX;
		/** @brief The vertical position of the cursor in screen coordinates. */
		int32_t PosY;
		/** @brief The relative horizontal movement of the mouse since the previous event. */
		int32_t PosRelX;
		/** @brief The relative vertical movement of the mouse since the previous event. */
		int32_t PosRelY;
		/** @brief The current value or position of the mouse scroll wheel. */
		int32_t Scroll;
		/** @brief The change in the scroll wheel position during this specific event. */
	    int32_t Delta;
	} LDL_EventMouse;

	/**
	 * @struct LDL_EventQuit
	 * @brief Represents an event signaling that the application or window has requested to terminate.
	 */
	typedef struct LDL_EventQuit
	{
		/** @brief The specific type identifier for the quit event. */
		uint8_t Type;
	} LDL_EventQuit;

	/**
	 * @struct LDL_EventResize
	 * @brief Represents an event triggered when the dimensions of a window are changed.
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
	 * is currently active and contains valid event data.
	 */
	typedef struct LDL_Event
	{
		/** @brief An unsigned eight-bit integer identifying the specific type of event contained in the union. */
		uint8_t Type;

		/**
		 * @brief A union containing the specialized structures for each unique event type.
		 */
		union
		{
			/** @brief Data for a quit event. */
			LDL_EventQuit        Quit;
			/** @brief Data for a mouse movement or button event. */
			LDL_EventMouse       Mouse;
			/** @brief Data for a window resizing event. */
			LDL_EventResize      Resize;
			/** @brief Data for a keyboard input event. */
			LDL_EventKeyboard    Keyboard;
			/** @brief Data for a gained focus event. */
			LDL_EventGainedFocus GainedFocus;
			/** @brief Data for a lost focus event. */
			LDL_EventLostFocus   LostFocus;
		} u;
	} LDL_Event;

	/**
	 * @brief Checks if a specific keyboard key is currently in a pressed state within the provided event.
	 *
	 * @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
	 * @param key   The identifier of the keyboard key to check.
	 * @return      A boolean value that is true if the specified key is in a pressed state; otherwise, false.
	 */
	LDL_LIBRARY bool LDL_EventIsKeyPressed(LDL_Event* event, uint8_t key);

	/**
	 * @brief Checks if a specific keyboard key is currently in a released state within the provided event.
	 *
	 * @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
	 * @param key   The identifier of the keyboard key to check.
	 * @return      A boolean value that is true if the specified key is in a released state; otherwise, false.
	 */
	LDL_LIBRARY bool LDL_EventIsKeyReleased(LDL_Event* event, uint8_t key);

	/**
	 * @brief Checks if a specific mouse button is currently in a pressed state within the provided event.
	 *
	 * @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
	 * @param key   The identifier of the mouse button to check.
	 * @return      A boolean value that is true if the specified mouse button is in a pressed state; otherwise, false.
	 */
	LDL_LIBRARY bool LDL_EventIsMousePressed(LDL_Event* event, uint8_t key);

	/**
	 * @brief Checks if a specific mouse button is currently in a released state within the provided event.
	 *
	 * @param event A pointer to the LDL_Event structure that contains the event data to be inspected.
	 * @param key   The identifier of the mouse button to check.
	 * @return      A boolean value that is true if the specified mouse button is in a released state; otherwise, false.
	 */
	LDL_LIBRARY bool LDL_EventIsMouseReleased(LDL_Event* event, uint8_t key);

#ifdef __cplusplus
}
#endif

#endif
