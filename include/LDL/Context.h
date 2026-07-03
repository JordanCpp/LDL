/**
 * @file LDL_Context.h
 * @brief Defines context management for rendering and graphics operations.
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

#ifndef LDL_Context_H
#define LDL_Context_H

#include <LDL/Result.h>
#include <LDL/Enums.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_Context
     * @brief Opaque structure representing a rendering context instance.
     *
     * This structure encapsulates all state and resources required for rendering
     * operations. The context manages the rendering pipeline, including the
     * drawing surface, rendering API state, and graphics resources.
     *
     * Key responsibilities:
     * - Manages rendering state (OpenGL context or software renderer)
     * - Handles drawing operations
     * - Owns textures and other GPU resources
     * - Coordinates with window system for presentation
     *
     * @note The internal details are hidden to ensure encapsulation.
     * @note Interaction with this structure should only occur through the
     *       provided API functions.
     * @see LDL_ContextCreate
     * @see LDL_ContextDestroy
     * @see LDL_ContextType
     */
    typedef struct LDL_Context LDL_Context;

    /**
     * @brief Creates and initializes a new rendering context.
     *
     * This function allocates memory for a new context object and configures it
     * according to the specified type. The context is responsible for managing
     * the rendering state and providing access to the graphics subsystem.
     *
     * @param result Pointer to an LDL_Result variable that will receive the operation status.
     *               If the operation succeeds, the result will be set to success state.
     *               If an error occurs, the result will contain an appropriate error message.
     * @param type   The specific type of rendering context to be created, as defined by
     *               the LDL_ContextType enumeration. Valid types include:
     *               - LDL_ContextSoftware: CPU-based rendering
     *               - LDL_ContextOpenGLLegacy: Legacy OpenGL (fixed-function)
     *               - LDL_ContextOpenGLHybrid: Hybrid OpenGL (mixed features)
     *               - LDL_ContextOpenGLModern: Modern OpenGL (core profile)
     * @return       A pointer to the newly created LDL_Context instance if the
     *               operation was successful; otherwise, a NULL pointer is returned.
     *
     * @note The context type determines which rendering functions are available.
     * @note Some context types may not be supported on all platforms or systems.
     * @note The returned context must be freed using LDL_ContextDestroy when no longer needed.
     *
     * @code
     * // Example: Create a modern OpenGL context
     * LDL_Result* result = LDL_ResultCreate();
     * LDL_Context* context = LDL_ContextCreate(result, LDL_ContextOpenGLModern);
     * if (context == NULL) {
     *     printf("Failed to create context: %s\n", LDL_ResultGetMessage(result));
     * }
     * @endcode
     *
     * @see LDL_ContextDestroy
     * @see LDL_ContextType
     * @see LDL_ContextGet
     */
    LDL_LIBRARY LDL_Context* LDL_ContextCreate(LDL_Result* result, LDL_ContextType type);

    /**
     * @brief Destroys an existing rendering context and releases all associated resources.
     *
     * This function performs the necessary cleanup for the specified context object,
     * including the deallocation of any memory that was reserved during its creation.
     * All textures, surfaces, and other resources associated with the context are
     * automatically freed.
     *
     * @param context Pointer to the LDL_Context instance to be destroyed.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @note After this function is called, the pointer to the context becomes invalid.
     * @note All graphics resources (textures, render targets) must be destroyed
     *       before or with the context.
     * @note If the context is associated with a window, the window should be
     *       destroyed after the context.
     *
     * @see LDL_ContextCreate
     * @see LDL_TextureDestroy
     */
    LDL_LIBRARY void LDL_ContextDestroy(LDL_Context* context);

    /**
     * @brief Retrieves a specific value or size associated with the provided context.
     *
     * This function accesses the internal properties of the specified context
     * and returns a numerical value representing a characteristic of that context.
     * The exact meaning of the return value depends on the context type and state.
     *
     * @param context Pointer to the LDL_Context from which the information is being retrieved.
     * @return A value of type size_t representing the size or property associated
     *         with the given context instance.
     *
     * @note The returned value may represent different properties depending on
     *       the context type:
     *       - For software context: may return buffer size or memory usage
     *       - For OpenGL context: may return GPU memory usage or other metrics
     * @note This function is primarily intended for diagnostic and debugging purposes.
     * @note The exact interpretation of the return value should be documented
     *       in the implementation-specific documentation.
     *
     * @code
     * // Example: Query context property
     * size_t value = LDL_ContextGet(context);
     * printf("Context property value: %zu\n", value);
     * @endcode
     *
     * @see LDL_ContextCreate
     * @see LDL_ContextType
     */
    LDL_LIBRARY size_t LDL_ContextGet(LDL_Context* context);

#ifdef __cplusplus
}
#endif

#endif // LDL_Context_H
