/**
 * @file LDL_Ticks.h
 * @brief Defines time measurement and delay functions.
 *
 * This file provides platform-independent functions for measuring time
 * in milliseconds and creating delays. It includes functionality for
 * obtaining the current system uptime in milliseconds and for pausing
 * program execution for a specified duration.
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

#ifndef LDL_Ticks_H
#define LDL_Ticks_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief Retrieves the current system uptime in milliseconds.
*
* This function returns the number of milliseconds that have elapsed
* since the system was started or since an arbitrary starting point
* (typically system boot time). The value is monotonically increasing
* and is suitable for measuring time intervals and performance timing.
*
* @return The current time value in milliseconds as a size_t integer.
*
* @note The actual start point (epoch) depends on the platform:
*       - On Windows: Typically returns the time since system start (GetTickCount)
*       - On Linux/Unix: Typically returns the time since system boot
*       - On macOS: Returns the time since system boot
* @note The value may wrap around after approximately 49.7 days on some
*       platforms if using a 32-bit counter. For longer durations, consider
*       using higher-precision timers.
* @note This function is useful for:
*       - Frame timing and delta time calculations
*       - Animation timing and interpolation
*       - Performance profiling and benchmarking
*       - Timeout and interval management
*
* @code
* // Example: Measure elapsed time
* size_t startTime = LDL_Ticks();
* // ... perform some operation ...
* size_t endTime = LDL_Ticks();
* size_t elapsedMs = endTime - startTime;
* printf("Operation took %zu milliseconds\n", elapsedMs);
* @endcode
*
* @see LDL_Delay
*/
LDL_LIBRARY size_t LDL_Ticks();

/**
* @brief Pauses program execution for a specified number of milliseconds.
*
* This function suspends the current thread's execution for approximately
* the specified number of milliseconds. It is useful for implementing
* timing loops, animations, and controlling execution speed.
*
* @param count The number of milliseconds to delay. Must be a non-negative value.
*
* @note The actual delay may be slightly longer than requested due to
*       system scheduling granularity and overhead.
* @note On some platforms, the minimum delay resolution may be higher than
*       1 millisecond (typically around 15-16ms on Windows).
* @note Calling this function with a value of 0 will typically yield the
*       current thread's remaining time slice to the operating system.
* @note This function blocks the calling thread, so use with caution in
*       performance-critical sections or real-time applications.
* @note Common use cases include:
*       - Creating frame rate limits (e.g., 60 FPS cap)
*       - Animation timing control
*       - Simple polling loops with reduced CPU usage
*       - Simulating delays in game loops
*
* @warning This function is not suitable for precise timing or
*          real-time applications due to OS scheduling variations.
* @warning Do not use this function in performance-critical loops that
*          require precise timing.
*
* @code
* // Example: Frame rate limiting to 60 FPS (approximately 16.67ms per frame)
* while (running) {
*     // Render frame...
*     LDL_Delay(16); // Delay approximately 16ms to achieve ~60 FPS
* }
* @endcode
*
* @see LDL_Ticks
*/
LDL_LIBRARY void LDL_Delay(size_t count);

#ifdef __cplusplus
}
#endif

#endif
