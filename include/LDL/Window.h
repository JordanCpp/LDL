/**
 * @file LDL_Window.h
 * @brief Defines window management and rendering surface functionality.
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

#ifndef LDL_Window_H
#define LDL_Window_H

#include <LDL/Result.h>
#include <LDL/Vec2i.h>
#include <LDL/Events.h>
#include <LDL/Context.h>
#include <LDL/Surface.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_Window
     * @brief Opaque structure representing a window instance.
     *
     * This structure encapsulates all state and resources required for window
     * management, including the window handle, rendering context, event handling,
     * and screen surface. It provides a complete interface for creating and
     * managing application windows.
     *
     * Key features:
     * - Window creation and destruction
     * - Event handling and polling
     * - Title management
     * - Window size management
     * - Screen surface access
     * - Rendering presentation (swap buffers)
     * - Window mode management (fullscreen, resizable, etc.)
     *
     * @note The internal details are hidden to ensure encapsulation.
     * @see LDL_WindowCreate
     * @see LDL_WindowDestroy
     * @see LDL_WindowGetScreen
     * @see LDL_WindowPresent
     */
    typedef struct LDL_Window LDL_Window;

    /**
     * @brief Creates and initializes a new window instance.
     *
     * This function allocates memory for a new window object and initializes
     * it with the specified parameters. The window is created with a rendering
     * context and an associated screen surface.
     *
     * @param result  Pointer to an LDL_Result variable that will receive the operation status.
     *                If the operation succeeds, the result will be set to success state.
     *                If an error occurs, the result will contain an appropriate error message.
     * @param context Pointer to the rendering context that will be associated with this window.
     * @param pos     The initial position of the window (x, y coordinates) in screen space.
     * @param size    The initial dimensions of the window (width, height) in pixels.
     * @param title   The title string to display in the window title bar.
     * @param mode    Bitwise combination of window mode flags (from LDL_WindowMode enumeration):
     *                - LDL_WindowModeFullScreen: Fullscreen mode
     *                - LDL_WindowModeResized: Allow resizing
     *                - LDL_WindowModeFixed: Fixed size (non-resizable)
     *                - LDL_WindowModeCentered: Center window on screen
     *                - LDL_WindowModeMinimized: Start minimized
     *                - LDL_WindowModeMaximized: Start maximized
     * @return       A pointer to the newly created LDL_Window instance if the
     *               operation was successful; otherwise, a NULL pointer is returned.
     *
     * @note The returned window must be freed using LDL_WindowDestroy when no longer needed.
     * @note The context must be valid and initialized before creating the window.
     * @note If mode is 0, default window settings are used.
     * @note The window's screen surface can be accessed via LDL_WindowGetScreen.
     *
     * @code
     * // Example: Create a centered window
     * LDL_Vec2i pos = LDL_GetVec2i(0, 0);
     * LDL_Vec2i size = LDL_GetVec2i(800, 600);
     * LDL_Window* window = LDL_WindowCreate(result, context, pos, size,
     *                                        "My Application", LDL_WindowModeCentered);
     * @endcode
     *
     * @see LDL_WindowDestroy
     * @see LDL_WindowMode flags
     * @see LDL_WindowGetScreen
     */
    LDL_LIBRARY LDL_Window* LDL_WindowCreate(LDL_Result* result, LDL_Context* context, LDL_Vec2i pos, LDL_Vec2i size, const char* title, size_t mode);

    /**
     * @brief Destroys a window instance and releases all associated resources.
     *
     * This function performs the necessary cleanup for the specified window,
     * including the deallocation of the window handle, screen surface, and
     * any associated resources. After this call, the pointer to the window
     * becomes invalid.
     *
     * @param window A pointer to the LDL_Window instance that is intended to be destroyed.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @note The window's screen surface is automatically destroyed.
     * @note The rendering context associated with the window should be destroyed
     *       separately after the window is destroyed.
     * @see LDL_WindowCreate
     */
    LDL_LIBRARY void LDL_WindowDestroy(LDL_Window* window);

    /**
     * @brief Checks if the window is still running.
     *
     * This function returns true if the window has not received a quit event
     * and is still active. It is typically used as the condition for the main
     * application loop.
     *
     * @param window A pointer to the LDL_Window instance.
     * @return true if the window is running and active; false if a quit event
     *         has been received or the window is closed.
     *
     * @note The window is considered running until LDL_WindowStopEvent is called
     *       or the user closes the window.
     * @see LDL_WindowStopEvent
     * @see LDL_WindowGetEvent
     */
    LDL_LIBRARY bool LDL_WindowIsRunning(LDL_Window* window);

    /**
     * @brief Stops the window event loop.
     *
     * This function signals the window to stop processing events, effectively
     * causing LDL_WindowIsRunning to return false and the application loop to exit.
     *
     * @param window A pointer to the LDL_Window instance.
     *
     * @note This function is typically called in response to a quit event
     *       or when the application wants to exit gracefully.
     * @see LDL_WindowIsRunning
     * @see LDL_WindowGetEvent
     */
    LDL_LIBRARY void LDL_WindowStopEvent(LDL_Window* window);

    /**
     * @brief Retrieves the next event from the window's event queue.
     *
     * This function polls the window's event queue and returns the next pending
     * event. If no events are available, the function returns false and the
     * event structure is not modified.
     *
     * @param window A pointer to the LDL_Window instance.
     * @param event  A pointer to an LDL_Event structure that will receive the event data.
     * @return true if an event was retrieved and stored in the event structure;
     *         false if no events are pending.
     *
     * @note This function should be called in the main application loop to
     *       process all window and input events.
     * @note The event structure's Type field indicates the specific event type.
     * @note Common usage pattern:
     *       - Call LDL_WindowGetEvent in a loop until it returns false
     *       - Process each event based on its Type
     *       - Handle quit events by calling LDL_WindowStopEvent
     *
     * @code
     * // Example: Event processing loop
     * LDL_Event event;
     * while (LDL_WindowGetEvent(window, &event)) {
     *     switch (event.Type) {
     *         case LDL_EventIsQuit:
     *             LDL_WindowStopEvent(window);
     *             break;
     *         case LDL_EventIsKeyboard:
     *             // Handle keyboard input...
     *             break;
     *         case LDL_EventIsMouseClick:
     *             // Handle mouse input...
     *             break;
     *         // ... handle other event types
     *     }
     * }
     * @endcode
     *
     * @see LDL_WindowIsRunning
     * @see LDL_WindowStopEvent
     * @see LDL_Event
     */
    LDL_LIBRARY bool LDL_WindowGetEvent(LDL_Window* window, LDL_Event* event);

    /**
     * @brief Retrieves the current size of the window.
     *
     * This function returns the current dimensions of the window in pixels.
     * The size may change if the window is resized by the user.
     *
     * @param window A pointer to the LDL_Window instance.
     * @return An LDL_Vec2i structure containing the window's width and height.
     *
     * @note The returned size reflects the current window size, which may be
     *       different from the initial size if the window has been resized.
     * @see LDL_WindowCreate
     * @see LDL_EventResize
     */
    LDL_LIBRARY LDL_Vec2i LDL_WindowGetSize(LDL_Window* window);

    /**
     * @brief Retrieves the current title of the window.
     *
     * This function returns a pointer to the string currently displayed in
     * the window's title bar.
     *
     * @param window A pointer to the LDL_Window instance.
     * @return A pointer to a constant string containing the window title.
     *
     * @note The returned string is owned by the window and should not be freed.
     * @see LDL_WindowSetTitle
     */
    LDL_LIBRARY const char* LDL_WindowGetTitle(LDL_Window* window);

    /**
     * @brief Sets the title of the window.
     *
     * This function changes the text displayed in the window's title bar to
     * the specified string.
     *
     * @param window A pointer to the LDL_Window instance.
     * @param title  The new title string to display.
     *
     * @note The title string is copied internally, so it can be freed after
     *       this call if it was dynamically allocated.
     * @note The title is immediately updated and visible to the user.
     * @see LDL_WindowGetTitle
     *
     * @code
     * // Example: Update window title with FPS
     * char title[256];
     * snprintf(title, sizeof(title), "Game - FPS: %zu", fps);
     * LDL_WindowSetTitle(window, title);
     * @endcode
     */
    LDL_LIBRARY void LDL_WindowSetTitle(LDL_Window* window, const char* title);

    /**
     * @brief Presents the window's screen surface to the display.
     *
     * This function swaps the back buffer with the front buffer, making the
     * rendered content visible on the screen. It is typically called once
     * per frame after all rendering operations are complete.
     *
     * @param window A pointer to the LDL_Window instance.
     *
     * @note This function is essential for double-buffered rendering.
     * @note For software rendering, this updates the window content.
     * @note For OpenGL rendering, this performs a buffer swap.
     * @note This function should be called at the end of each frame.
     *
     * @code
     * // Example: Render loop
     * while (LDL_WindowIsRunning(window)) {
     *     // Process events...
     *     // Clear screen...
     *     // Render content...
     *     LDL_WindowPresent(window);  // Display the rendered frame
     * }
     * @endcode
     *
     * @see LDL_WindowGetScreen
     */
    LDL_LIBRARY void LDL_WindowPresent(LDL_Window* window);

    /**
     * @brief Retrieves the screen surface of the window.
     *
     * This function returns a pointer to the window's screen surface, which
     * can be used for direct pixel manipulation and rendering. The surface
     * represents the window's drawing area.
     *
     * @param window A pointer to the LDL_Window instance.
     * @return A pointer to the LDL_Surface representing the window's screen.
     *
     * @note The surface is owned by the window and should not be destroyed
     *       separately. It will be automatically destroyed when the window is
     *       destroyed.
     * @note Modifying the surface pixels allows custom rendering directly
     *       to the window.
     * @note For software rendering, drawing directly to this surface is the
     *       primary method of rendering.
     *
     * @code
     * // Example: Clear screen with a color
     * LDL_Surface* screen = LDL_WindowGetScreen(window);
     * uint8_t* pixels = LDL_SurfaceGetPixels(screen);
     * size_t pitch = LDL_SurfaceGetPitch(screen);
     * LDL_Vec2i size = LDL_SurfaceGetSize(screen);
     *
     * // Fill with blue
     * for (int y = 0; y < size.y; y++) {
     *     for (int x = 0; x < size.x; x++) {
     *         size_t index = y * pitch + x * 4;
     *         pixels[index + 0] = 0;     // R
     *         pixels[index + 1] = 0;     // G
     *         pixels[index + 2] = 255;   // B
     *         pixels[index + 3] = 255;   // A
     *     }
     * }
     * @endcode
     *
     * @see LDL_Surface
     * @see LDL_WindowPresent
     */
    LDL_LIBRARY LDL_Surface* LDL_WindowGetScreen(LDL_Window* window);

#ifdef __cplusplus
}
#endif

#endif // LDL_Window_H
