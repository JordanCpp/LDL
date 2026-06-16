/**
 * @file LDL_FpsCount.h
 * @brief Header file containing the interface for the Frames Per Second (FPS) counter utility.
 *
 * This file provides the necessary structures and functions to create, manage,
 * and utilize an FPS counter object, which is used to monitor the performance
 * of an application by calculating the number of frames processed per second.
 *
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation;
 * either version 3 of the License, or (at your option) any later version.
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
	 * The internal details and implementation of this structure are encapsulated
	 * to ensure data integrity. All operations on the FPS counter must be
	 * performed through the provided API functions.
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
	 * @return       A pointer to the newly created LDL_FPSCounter instance if the
	 *               operation succeeded; otherwise, a NULL pointer is returned.
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
	 */
	LDL_LIBRARY void LDL_FpsCounterDestroy(LDL_FpsCounter* fpsCounter);

	/**
	 * @brief Starts or resets the internal timer of the FPS counter.
	 *
	 * This function marks the beginning of a new measurement period by resetting
	 * the internal timestamp. It is typically called at the start of a frame
	 * or before starting the main application loop.
	 *
	 * @param fpsCounter A pointer to the LDL_FpsCounter instance whose timer is being started or reset.
	 */
	LDL_LIBRARY void LDL_FpsCounterStart(LDL_FpsCounter* fpsCounter);

	/**
	 * @brief Performs a calculation step to update the current Frames Per Second value.
	 *
	 * This function processes the elapsed time since the last calculation or
	 * since the start of the timer to compute the updated frames per second metric.
	 *
	 * @param fpsCounter A pointer to the LDL_FPSCounter instance for which the
	 *                   calculation is being performed.
	 * @return           A boolean value that returns true if the calculation was
	 *                   successfully performed; otherwise, returns false.
	 */
	LDL_LIBRARY bool LDL_FpsCounterCalc(LDL_FpsCounter* fpsCounter);

	/**
	 * @brief Retrieves the most recently calculated Frames Per Second (FPS) value.
	 *
	 * This function provides access to the numerical result of the latest
	 * calculation performed by the FPS counter instance.
	 *
	 * @param fpsCounter A pointer to the LDL_FpsCounter instance from which
	 *                   the FPS value is being retrieved.
	 * @return           A value of type size_t representing the number of
	 *                   frames per second calculated for the current period.
	 */
	LDL_LIBRARY size_t LDL_FpsCounterFps(LDL_FpsCounter* fpsCounter);

#ifdef __cplusplus
}
#endif 

#endif
