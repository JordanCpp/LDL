/**
 * @file LDL_FpsLimit.h
 * @brief Defines a Frames Per Second (FPS) limiter utility for frame rate regulation.
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

#ifndef LDL_FpsLimit_H
#define LDL_FpsLimit_H

#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Default configuration constant for the FPS limiter.
*
* This constant defines a standard target of 60 Frames Per Second, which is
* commonly used for smooth animation and gameplay. It can be used as a
* default value when initializing the limiter if no specific value is desired.
*/
    enum
    {
        LDL_FpsLimiterDefault = 60
    };

/**
* @struct LDL_FpsLimiter
* @brief An opaque structure representing an instance of the FPS limiter.
*
* This structure encapsulates the timing state and configuration required to
* regulate frame rates. It tracks elapsed time between frames and introduces
* delays when necessary to maintain a consistent frame rate.
*
* Key features:
* - Frame rate regulation through throttling
* - Configurable target FPS
* - Automatic delay calculation
* - CPU usage reduction
* - Consistent frame timing
*
* @note The internal implementation details of this structure are hidden to ensure
*       encapsulation. All operations involving the regulation of frame rates must
*       be performed through the provided API functions.
* @see LDL_FpsLimiterCreate
* @see LDL_FpsLimiterDestroy
* @see LDL_FpsLimiterMark
* @see LDL_FpsLimiterThrottle
*/
typedef struct LDL_FpsLimiter LDL_FpsLimiter;

/**
* @brief Creates and initializes a new instance of an LDL_FpsLimiter.
*
* This function allocates memory for a new FPS limiter object and configures
* it to target a specific number of frames per second. The success or failure
* of the allocation is reported via the provided result pointer.
*
* @param result A pointer to an LDL_Result structure that will receive the
*               status code of the creation process. If the operation succeeds,
*               the result will be set to success state. If an error occurs,
*               the result will contain an appropriate error message.
* @param fps    The target number of Frames Per Second that the limiter should
*               aim to maintain. A value of 0 disables the limiter.
* @return       A pointer to the newly created LDL_FpsLimiter instance if the
*               operation was successful; otherwise, a NULL pointer is returned.
*
* @note The returned FPS limiter must be freed using LDL_FpsLimiterDestroy
*       when it is no longer needed to avoid memory leaks.
* @note Typical target values:
*       - 30: Minimum for smooth animation
*       - 60: Standard for most applications and games
*       - 120: High refresh rate displays
*       - 144: Gaming monitors
* @note The limiter uses a high-resolution timer for accurate timing.
* @see LDL_FpsLimiterDestroy
* @see LDL_FpsLimiterDefault
* @see LDL_FpsLimiterMark
*/
LDL_LIBRARY LDL_FpsLimiter* LDL_FpsLimiterCreate(LDL_Result* result, size_t fps);

/**
* @brief Destroys an existing FPS limiter and releases all associated resources.
*
* This function performs the necessary cleanup for the specified FPS limiter
* instance, including the deallocation of any internal timing or synchronization
* primitives. After this call, the pointer to the FPS limiter becomes invalid.
*
* @param fpsLimiter A pointer to the LDL_FpsLimiter instance that is intended
*                   to be destroyed.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note All timing configuration and state data is lost when the limiter is destroyed.
* @see LDL_FpsLimiterCreate
*/
LDL_LIBRARY void LDL_FpsLimiterDestroy(LDL_FpsLimiter* fpsLimiter);

/**
* @brief Marks the start of a new frame or time interval.
*
* This function should be called at the beginning of a frame execution cycle.
* It records the current timestamp, which serves as the reference point for
* calculating how much time has elapsed and whether a delay is required
* to maintain the target frame rate.
*
* @param fpsLimiter A pointer to the LDL_FpsLimiter instance whose timing
*                   is being recorded.
*
* @note Always call this function at the start of each frame before any
*       rendering or processing occurs.
* @note The recorded timestamp is used by LDL_FpsLimiterThrottle to determine
*       if a delay is needed.
* @see LDL_FpsLimiterThrottle
*
* @code
* // Example: Using FPS limiter in a game loop
* LDL_FpsLimiter* limiter = LDL_FpsLimiterCreate(result, 60);
*
* while (running) {
*     LDL_FpsLimiterMark(limiter);  // Mark start of frame
*
*     // Process input
*     // Update game logic
*     // Render frame
*
*     LDL_FpsLimiterThrottle(limiter);  // Delay if running too fast
* }
* @endcode
*/
LDL_LIBRARY void LDL_FpsLimiterMark(LDL_FpsLimiter* fpsLimiter);

/**
* @brief Regulates the execution speed by introducing a delay if necessary.
*
* This function checks the elapsed time since the last call to `LDL_FpsLimiterMark`.
* If the application is running faster than the configured target Frames Per Second,
* this function will block (throttle) the current thread for the required amount
* of time to bring the execution speed back in line with the target limit.
*
* @param fpsLimiter A pointer to the LDL_FpsLimiter instance responsible for
*                   performing the throttling operation.
*
* @note This function should be called at the end of each frame after all
*       processing and rendering is complete.
* @note The delay is calculated as: delay = (1 / target_fps) - elapsed_time
* @note If the application is already running at or below the target FPS,
*       no delay is introduced.
* @note This function uses LDL_Delay for sleeping, which may not be
*       perfectly precise due to OS scheduling.
* @note For high-precision timing, consider using spin-locks or busy-waiting
*       for very short delays.
*
* @code
* // Example: Complete game loop with FPS limiting
* bool running = true;
* LDL_FpsLimiter* limiter = LDL_FpsLimiterCreate(result, 60);
*
* while (running) {
*     LDL_FpsLimiterMark(limiter);
*
*     // Game logic and rendering...
*
*     LDL_FpsLimiterThrottle(limiter);
*
*     // Process events
*     // Handle window messages
* }
*
* LDL_FpsLimiterDestroy(limiter);
* @endcode
*
* @see LDL_FpsLimiterMark
* @see LDL_Delay
*/
LDL_LIBRARY void LDL_FpsLimiterThrottle(LDL_FpsLimiter* fpsLimiter);

#ifdef __cplusplus
}
#endif

#endif // LDL_FpsLimit_H
