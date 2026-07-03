/**
 * @file LDL_2DRender.h
 * @brief Defines 2D rendering functionality for drawing primitives and textures.
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

#ifndef LDL_2DRender_H
#define LDL_2DRender_H

#include <LDL/Color.h>
#include <LDL/Window.h>
#include <LDL/Texture.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_2DRender
     * @brief Opaque structure representing a 2D renderer instance.
     *
     * This structure encapsulates the state and resources required for 2D
     * rendering operations. It manages drawing primitives, textures, layers,
     * and color state for rendering to a window.
     *
     * Key features:
     * - Drawing primitives (lines, filled rectangles)
     * - Texture rendering with scaling and positioning
     * - Layer management for depth ordering
     * - Color state management
     * - Batch rendering with Begin/End blocks
     *
     * @note The internal details are hidden to ensure encapsulation.
     * @see LDL_2DRenderCreate
     * @see LDL_2DRenderDestroy
     * @see LDL_2DRenderBegin
     * @see LDL_2DRenderEnd
     */
    typedef struct LDL_2DRender LDL_2DRender;

    /**
     * @brief Creates and initializes a new 2D renderer instance.
     *
     * This function allocates memory for a new renderer object and associates
     * it with the specified context and window. The renderer manages all 2D
     * drawing operations for the window.
     *
     * @param result  Pointer to an LDL_Result variable that will receive the operation status.
     *                If the operation succeeds, the result will be set to success state.
     *                If an error occurs, the result will contain an appropriate error message.
     * @param context Pointer to the rendering context that will be used for rendering.
     * @param window  Pointer to the window that will be used for rendering output.
     * @return A pointer to the newly created LDL_2DRender instance if the
     *         operation was successful; otherwise, a NULL pointer is returned.
     *
     * @note The returned renderer must be freed using LDL_2DRenderDestroy
     *       when no longer needed to avoid memory leaks.
     * @note The renderer automatically uses the window's screen surface for drawing.
     * @note The context must be valid and initialized before creating the renderer.
     * @see LDL_2DRenderDestroy
     * @see LDL_Window
     * @see LDL_Context
     */
    LDL_LIBRARY LDL_2DRender* LDL_2DRenderCreate(LDL_Result* result, LDL_Context* context, LDL_Window* window);

    /**
     * @brief Destroys a 2D renderer instance and releases all associated resources.
     *
     * This function performs the necessary cleanup for the specified renderer,
     * including the deallocation of any internal buffers or rendering resources.
     * After this call, the pointer to the renderer becomes invalid.
     *
     * @param render A pointer to the LDL_2DRender instance that is intended to be destroyed.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @note All rendering state and resources are freed when the renderer is destroyed.
     * @see LDL_2DRenderCreate
     */
    LDL_LIBRARY void LDL_2DRenderDestroy(LDL_2DRender* render);

    /**
     * @brief Retrieves the current rendering layer.
     *
     * This function returns the current layer index being used for rendering.
     * Layers allow depth ordering of rendered objects (higher layer numbers
     * are drawn on top).
     *
     * @param render A pointer to the LDL_2DRender instance.
     * @return The current layer index as a size_t value.
     *
     * @note The default layer is typically 0.
     * @see LDL_2DRenderSetLayer
     */
    LDL_LIBRARY size_t LDL_2DRenderGetLayer(LDL_2DRender* render);

    /**
     * @brief Sets the current rendering layer.
     *
     * This function sets the layer index for subsequent rendering operations.
     * Objects rendered on higher layers will appear on top of objects on lower layers.
     *
     * @param render A pointer to the LDL_2DRender instance.
     * @param layer  The layer index to set for rendering.
     *
     * @note Layers are rendered in ascending order (0, 1, 2, ...).
     * @note Higher layer numbers are drawn later and thus appear on top.
     * @see LDL_2DRenderGetLayer
     */
    LDL_LIBRARY void LDL_2DRenderSetLayer(LDL_2DRender* render, size_t layer);

    /**
     * @brief Retrieves the current drawing color.
     *
     * This function returns the color that will be used for subsequent
     * drawing operations (lines, fills, etc.).
     *
     * @param render A pointer to the LDL_2DRender instance.
     * @return The current color as an LDL_Color structure.
     *
     * @see LDL_2DRenderSetColor
     * @see LDL_Color
     */
    LDL_LIBRARY LDL_Color LDL_2DRenderGetColor(LDL_2DRender* render);

    /**
     * @brief Sets the current drawing color.
     *
     * This function sets the color that will be used for subsequent
     * drawing operations (lines, fills, etc.).
     *
     * @param render A pointer to the LDL_2DRender instance.
     * @param color  The color to set for drawing operations.
     *
     * @note The color is applied to all subsequent drawing operations
     *       until changed again.
     * @note Alpha transparency is supported and will affect drawing.
     * @see LDL_2DRenderGetColor
     * @see LDL_Color
     */
    LDL_LIBRARY void LDL_2DRenderSetColor(LDL_2DRender* render, LDL_Color color);

    /**
     * @brief Clears the rendering area.
     *
     * This function fills the entire window with the current drawing color,
     * effectively clearing the screen. This is typically called at the beginning
     * of each frame.
     *
     * @param render A pointer to the LDL_2DRender instance.
     *
     * @note The current color set via LDL_2DRenderSetColor is used for clearing.
     * @note This operation affects all layers.
     * @see LDL_2DRenderSetColor
     */
    LDL_LIBRARY void LDL_2DRenderClear(LDL_2DRender* render);

    /**
     * @brief Draws a line between two points.
     *
     * This function renders a line from the first point to the second point
     * using the current drawing color.
     *
     * @param render A pointer to the LDL_2DRender instance.
     * @param first  The starting point of the line (in window coordinates).
     * @param last   The ending point of the line (in window coordinates).
     *
     * @note The line is drawn using the current color and layer.
     * @note The coordinates are in pixels relative to the window.
     * @see LDL_2DRenderSetColor
     * @see LDL_2DRenderSetLayer
     */
    LDL_LIBRARY void LDL_2DRenderLine(LDL_2DRender* render, LDL_Vec2i first, LDL_Vec2i last);

    /**
     * @brief Draws a filled rectangle.
     *
     * This function renders a filled rectangle from the first point to the
     * second point using the current drawing color.
     *
     * @param render A pointer to the LDL_2DRender instance.
     * @param first  The top-left corner of the rectangle (in window coordinates).
     * @param last   The bottom-right corner of the rectangle (in window coordinates).
     *
     * @note The rectangle is drawn using the current color and layer.
     * @note The coordinates are in pixels relative to the window.
     * @note The rectangle is filled completely with the current color.
     * @see LDL_2DRenderSetColor
     * @see LDL_2DRenderSetLayer
     */
    LDL_LIBRARY void LDL_2DRenderFill(LDL_2DRender* render, LDL_Vec2i first, LDL_Vec2i last);

    /**
     * @brief Draws a texture on the screen with optional scaling and cropping.
     *
     * This function renders a texture to the window with support for positioning,
     * scaling, and source region selection (cropping). NULL pointers for source
     * or destination parameters indicate default values (full texture / full screen).
     *
     * @param render  A pointer to the LDL_2DRender instance.
     * @param texture A pointer to the LDL_Texture to be drawn.
     * @param dstPos  Pointer to the destination position (top-left corner).
     *                If NULL, position is (0, 0).
     * @param dstSize Pointer to the destination size (width, height).
     *                If NULL, the original texture size is used.
     * @param srcPos  Pointer to the source region position (top-left corner).
     *                If NULL, the region starts at (0, 0).
     * @param srcSize Pointer to the source region size (width, height).
     *                If NULL, the entire texture is used.
     *
     * @note The texture is drawn using the current layer.
     * @note The texture's alpha channel is respected for transparency.
     * @note Scaling is performed automatically if destination size differs
     *       from source size.
     *
     * @code
     * // Example: Draw a texture at (100, 100) with original size
     * LDL_2DRenderDraw(render, texture, LDL_GetVec2i(100, 100), NULL, NULL, NULL);
     *
     * // Example: Draw a texture scaled to 200x200
     * LDL_Vec2i dstPos = LDL_GetVec2i(50, 50);
     * LDL_Vec2i dstSize = LDL_GetVec2i(200, 200);
     * LDL_2DRenderDraw(render, texture, &dstPos, &dstSize, NULL, NULL);
     *
     * // Example: Draw a cropped portion of the texture
     * LDL_Vec2i srcPos = LDL_GetVec2i(10, 10);
     * LDL_Vec2i srcSize = LDL_GetVec2i(50, 50);
     * LDL_2DRenderDraw(render, texture, NULL, NULL, &srcPos, &srcSize);
     * @endcode
     *
     * @see LDL_Texture
     * @see LDL_2DRenderSetLayer
     */
    LDL_LIBRARY void LDL_2DRenderDraw(LDL_2DRender* render, LDL_Texture* texture, LDL_Vec2i* dstPos, LDL_Vec2i* dstSize, LDL_Vec2i* srcPos, LDL_Vec2i* srcSize);

    /**
     * @brief Begins a rendering batch.
     *
     * This function starts a rendering batch, which groups multiple drawing
     * operations together for optimized rendering. All drawing commands between
     * Begin and End are batched and executed efficiently.
     *
     * @param render A pointer to the LDL_2DRender instance.
     *
     * @note Always pair each Begin call with a matching End call.
     * @note Nesting Begin/End calls is not recommended.
     * @note Batch rendering improves performance by reducing state changes.
     * @see LDL_2DRenderEnd
     */
    LDL_LIBRARY void LDL_2DRenderBegin(LDL_2DRender* render);

    /**
     * @brief Ends a rendering batch and flushes all pending commands.
     *
     * This function ends a rendering batch and executes all drawing commands
     * that were queued since the last Begin call. This is typically called
     * at the end of a frame.
     *
     * @param render A pointer to the LDL_2DRender instance.
     *
     * @note All drawing commands are executed when End is called.
     * @note Always pair each End call with a matching Begin call.
     * @see LDL_2DRenderBegin
     *
     * @code
     * // Example: Using Begin/End for batch rendering
     * LDL_2DRenderBegin(render);
     *
     * // All drawing commands are batched
     * LDL_2DRenderClear(render);
     * LDL_2DRenderLine(render, p1, p2);
     * LDL_2DRenderFill(render, rect1, rect2);
     * LDL_2DRenderDraw(render, texture, NULL, NULL, NULL, NULL);
     *
     * LDL_2DRenderEnd(render);  // Execute all batched commands
     * @endcode
     */
    LDL_LIBRARY void LDL_2DRenderEnd(LDL_2DRender* render);

#ifdef __cplusplus
}
#endif

#endif // LDL_2DRender_H
