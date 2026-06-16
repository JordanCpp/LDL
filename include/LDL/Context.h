/**
 * @file LDL_Context.h
 * @brief Header file containing declarations for managing LDL context objects.
 *
 * This file provides the interface for creating, destroying, and interacting with
 * context instances within the LDL library.
 *
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it can be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 */

#ifndef LDL_Context_H
#define LDL_Context_H

#include <LDL/Result.h>
#include <LDL/Enums.h>

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * @struct LDL_Context
	 * @brief An opaque structure representing a context instance within the LDL library.
	 *
	 * The internal details of this structure are hidden to ensure encapsulation.
	 * Interaction with this structure should only occur through the provided API functions.
	 */
	typedef struct LDL_Context LDL_Context;

	/**
	 * @brief Creates and initializes a new instance of an LDL context.
	 *
	 * This function allocates memory for a new context object and configures it
	 * according to the specified type. The outcome of the operation (success or failure)
	 * is reported via the provided result pointer.
	 *
	 * @param result A pointer to an LDL_Result structure that will be updated with
	 *               the status of the creation process.
	 * @param type   The specific type of context to be created, as defined by the
	 *               LDL_ContextType enumeration.
	 * @return       A pointer to the newly created LDL_Context instance if the
	 *               operation was successful; otherwise, a NULL pointer is returned.
	 */
	LDL_LIBRARY LDL_Context* LDL_ContextCreate(LDL_Result* result, LDL_ContextType type);

	/**
	 * @brief Destroys an existing LDL context and releases all associated resources.
	 *
	 * This function performs the necessary cleanup for the specified context object,
	 * including the deallocation of any memory that was reserved during its creation.
	 * After this function is called, the pointer to the context becomes invalid.
	 *
	 * @param context A pointer to the LDL_Context instance that is intended to be destroyed.
	 */
	LDL_LIBRARY void LDL_ContextDestroy(LDL_Context* context);

	/**
	 * @brief Retrieves a specific value or size associated with the provided context.
	 *
	 * This function accesses the internal properties of the specified context
	 * and returns a numerical value representing a characteristic of that context.
	 *
	 * @param context A pointer to the LDL_Context from which the information is being retrieved.
	 * @return        A value of type size_t representing the size or property associated
	 *                with the given context instance.
	 */
	LDL_LIBRARY size_t LDL_ContextGet(LDL_Context* context);

#ifdef __cplusplus
}
#endif 

#endif
