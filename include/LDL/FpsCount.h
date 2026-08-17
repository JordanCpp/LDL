/**
 * @file LDL_FpsCount.h
 * @brief Defines a Frames Per Second (FPS) counter utility for performance monitoring.
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

#ifndef LDL_FpsCount_H
#define LDL_FpsCount_H

#include <LDL/Result.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_FpsCounter
* @brief An opaque structure representing an instance of the FPS counter.
*
* This structure encapsulates the state and timing information required to
* calculate and track frames per second. It manages internal timestamps,
* frame counters, and the calculated FPS value.
*
* Key features:
* - Frame counting and timing
* - Automatic FPS calculation
* - Performance monitoring
* - Error handling through LDL_Result
*
* @note The internal details and implementation of this structure are encapsulated
*       to ensure data integrity. All operations on the FPS counter must be
*       performed through the provided API functions.
* @see LDL_FpsCounterCreate
* @see LDL_FpsCounterDestroy
* @see LDL_FpsCounterStart
* @see LDL_FpsCounterCalc
*/
typedef struct LDL_FpsCounter LDL_FpsCounter;

/**
* @brief Creates and initializes a new instance of an LDL_FpsCounter.
*
* This function allocates memory for a new FPS counter object and prepares
* its internal state for tracking frames per second. The outcome of the
* allocation and initialization process is recorded in the provided result pointer.
*
* @param result A pointer to an LDL_Result structure that will receive the
*               status code indicating whether the creation was successful or failed.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @return       A pointer to the newly created LDL_FpsCounter instance if the
*               operation succeeded; otherwise, a NULL pointer is returned.
*
* @note The returned FPS counter must be freed using LDL_FpsCounterDestroy
*       when it is no longer needed to avoid memory leaks.
* @note The counter is initialized with zero frames and a reset timer.
* @see LDL_FpsCounterDestroy
* @see LDL_FpsCounterStart
*/
LDL_LIBRARY LDL_FpsCounter* LDL_FpsCounterCreate(LDL_Result* result);

/**
* @brief Destroys an existing FPS counter and releases all associated memory resources.
*
* This function performs the necessary cleanup for the specified FPS counter instance,
* including the deallocation of any internal buffers or timing information used by
* the object. After this call, the pointer to the FPS counter becomes invalid.
*
* @param fpsCounter A pointer to the LDL_FpsCounter instance that is intended to be destroyed.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note All timing and frame count data is lost when the counter is destroyed.
* @see LDL_FpsCounterCreate
*/
LDL_LIBRARY void LDL_FpsCounterDestroy(LDL_FpsCounter* fpsCounter);

/**
* @brief Starts or resets the internal timer of the FPS counter.
*
* This function marks the beginning of a new measurement period by resetting
* the internal timestamp and frame counter. It is typically called at the start
* of a frame or before starting the main application loop.
*
* @param fpsCounter A pointer to the LDL_FpsCounter instance whose timer is being started or reset.
*
* @note After calling this function, the FPS counter will begin counting
*       frames from zero.
* @note This function should be called before the first frame or when
*       resetting the measurement period is desired.
* @note The timer uses the system's high-resolution timer for accurate
*       measurements.
* @see LDL_FpsCounterCalc
* @see LDL_FpsCounterFps
*
* @code
* // Example: Initialize and start FPS counter
* LDL_Result* result = LDL_ResultCreate();
* LDL_FpsCounter* fpsCounter = LDL_FpsCounterCreate(result);
* LDL_FpsCounterStart(fpsCounter);
*
* while (running) {
*     // Render frame...
*     LDL_FpsCounterCalc(fpsCounter);
*     size_t fps = LDL_FpsCounterFps(fpsCounter);
*     printf("FPS: %zu\n", fps);
* }
* @endcode
*/
LDL_LIBRARY void LDL_FpsCounterStart(LDL_FpsCounter* fpsCounter);

/**
* @brief Performs a calculation step to update the current Frames Per Second value.
*
* This function processes the elapsed time since the last calculation or
* since the start of the timer to compute the updated frames per second metric.
* It increments the internal frame counter and calculates the FPS value
* at regular intervals.
*
* @param fpsCounter A pointer to the LDL_FpsCounter instance for which the
*                   calculation is being performed.
* @return           A boolean value that returns true if the calculation was
*                   successfully performed; otherwise, returns false.
*
* @note This function should be called once per frame, typically at the
*       end of each frame rendering cycle.
* @note The FPS value is updated at regular intervals (typically once per second)
*       to provide stable readings.
* @note The returned value indicates whether the FPS counter is ready to
*       provide updated FPS data.
* @see LDL_FpsCounterStart
* @see LDL_FpsCounterFps
*/
LDL_LIBRARY bool LDL_FpsCounterCalc(LDL_FpsCounter* fpsCounter);

/**
* @brief Retrieves the most recently calculated Frames Per Second (FPS) value.
*
* This function provides access to the numerical result of the latest
* calculation performed by the FPS counter instance. The value represents
* the number of frames rendered in the last second.
*
* @param fpsCounter A pointer to the LDL_FpsCounter instance from which
*                   the FPS value is being retrieved.
* @return           A value of type size_t representing the number of
*                   frames per second calculated for the current period.
*
* @note The returned value is only updated after calls to LDL_FpsCounterCalc.
* @note If no calculation has been performed yet, the returned value will be 0.
* @note The value is stable and represents the average FPS over the
*       measurement period.
*
* @code
* // Example: Display FPS in a window title
* size_t fps = LDL_FpsCounterFps(fpsCounter);
* char title[256];
* snprintf(title, sizeof(title), "My Application - FPS: %zu", fps);
* SetWindowTitle(title);
* @endcode
*
* @see LDL_FpsCounterCalc
* @see LDL_FpsCounterStart
*/
LDL_LIBRARY size_t LDL_FpsCounterFps(LDL_FpsCounter* fpsCounter);

#ifdef __cplusplus
}
#endif

#endif
