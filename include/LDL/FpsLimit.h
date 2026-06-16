/**
 * @file LDL_FpsLimit.h
 * @brief Header file containing the interface for the Frames Per Second (FPS) limiter utility.
 *
 * This file provides the necessary structures and functions to implement a frame rate
 * regulator. The purpose of this utility is to prevent the application from executing
 * too many frames per second, thereby reducing CPU/GPU usage and ensuring a consistent
 * playback speed by introducing controlled delays (throttling).
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

#ifndef LDL_FpsLimit_H
#define LDL_FpsLimit_H

#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @brief Default configuration constant for the FPS limiter.
	 *
	 * This constant defines a standard target of 60 Frames Per Second, which can be
	 * used when initializing the limiter if no specific value is desired.
	 */
	enum
	{
		LDL_FpsLimiterDefault = 60
	};

	/**
	 * @struct LDL_FpsLimiter
	 * @brief An opaque structure representing an instance of the FPS limiter.
	 *
	 * The internal implementation details of this structure are hidden to ensure
	 * encapsulation. All operations involving the regulation of frame rates must
	 * be performed through the provided API functions.
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
	 *               status code of the creation process.
	 * @param fps    The target number of Frames Per Second that the limiter should
	 *               aim to maintain.
	 * @return       A pointer to the newly created LDL_FpsLimiter instance if the
	 *               operation was successful; otherwise, a NULL pointer is returned.
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
	 */
	LDL_LIBRARY void LDL_FpsLimiterThrottle(LDL_FpsLimiter* fpsLimiter);

#ifdef __cplusplus
}
#endif 

#endif
