/**
 * @file LDL_3DRender.h
 * @brief Defines 3D rendering functionality with vertex buffers and matrix transformations.
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

#ifndef LDL_3DRender_H
#define LDL_3DRender_H

#include <LDL/Color.h>
#include <LDL/Window.h>
#include <LDL/Texture.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @name Flexible Vertex Format (FVF) Flags
* @brief Bitmask flags defining the layout of vertex data.
*
* These flags are used to specify which components are present in a vertex
* buffer's vertex format. Multiple flags can be combined using bitwise OR.
*
* @{
*/
    enum
    {
        LDL_FVF_XYZ = (1 << 0), /**< Vertex has XYZ position (3 floats). */
        LDL_FVF_XYZW = (1 << 1), /**< Vertex has XYZW position with homogeneous coordinate (4 floats). */
        LDL_FVF_COLOR = (1 << 2), /**< Vertex has color data (RGBA). */
        LDL_FVF_NORMAL = (1 << 3), /**< Vertex has normal vector (3 floats). */
        LDL_FVF_TEXCOORD = (1 << 4)  /**< Vertex has texture coordinates (UV). */
    };
/** @} */

/**
* @struct LDL_3DRender
* @brief Opaque structure representing a 3D renderer instance.
*
* This structure encapsulates the state and resources required for 3D
* rendering operations. It manages vertex buffers, textures, transformation
* matrices (world, view, projection), and rendering state for 3D graphics.
*
* Key features:
* - Vertex buffer rendering
* - Texture binding
* - Matrix transformations (World, View, Projection)
* - Clear screen with color
* - Batch rendering with Begin/End blocks
*
* @note The internal details are hidden to ensure encapsulation.
* @see LDL_3DRenderCreate
* @see LDL_3DRenderDestroy
* @see LDL_VertexBuffer
*/
typedef struct LDL_3DRender LDL_3DRender;

/**
* @struct LDL_VertexBuffer
* @brief Opaque structure representing a vertex buffer object.
*
* This structure encapsulates a vertex buffer that stores vertex data
* for 3D rendering. The buffer format is defined by FVF flags and
* can contain position, color, normal, and texture coordinate data.
*
* Key features:
* - Configurable vertex format via FVF flags
* - Dynamic data upload
* - GPU memory storage for optimal performance
*
* @see LDL_VertexBufferCreate
* @see LDL_VertexBufferDestroy
* @see LDL_VertexBufferCopy
* @see LDL_FVF flags
*/
typedef struct LDL_VertexBuffer LDL_VertexBuffer;

/**
* @brief Creates and initializes a new 3D renderer instance.
*
* This function allocates memory for a new renderer object and associates
* it with the specified context and window. The renderer manages all 3D
* rendering operations for the window.
*
* @param result  Pointer to an LDL_Result variable that will receive the operation status.
*                If the operation succeeds, the result will be set to success state.
*                If an error occurs, the result will contain an appropriate error message.
* @param context Pointer to the rendering context that will be used for rendering.
* @param window  Pointer to the window that will be used for rendering output.
* @return A pointer to the newly created LDL_3DRender instance if the
*         operation was successful; otherwise, a NULL pointer is returned.
*
* @note The returned renderer must be freed using LDL_3DRenderDestroy
*       when no longer needed to avoid memory leaks.
* @note The context must support 3D rendering (OpenGL context).
* @see LDL_3DRenderDestroy
* @see LDL_Context
* @see LDL_Window
*/
LDL_LIBRARY LDL_3DRender* LDL_3DRenderCreate(LDL_Result* result, LDL_Context* context, LDL_Window* window);

/**
* @brief Destroys a 3D renderer instance and releases all associated resources.
*
* This function performs the necessary cleanup for the specified renderer,
* including the deallocation of any internal buffers or rendering resources.
* After this call, the pointer to the renderer becomes invalid.
*
* @param render A pointer to the LDL_3DRender instance that is intended to be destroyed.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note All rendering state and resources are freed when the renderer is destroyed.
* @see LDL_3DRenderCreate
*/
LDL_LIBRARY void LDL_3DRenderDestroy(LDL_3DRender* render);

/**
* @brief Begins a rendering batch.
*
* This function starts a rendering batch, preparing the renderer for
* 3D drawing operations. All drawing commands between Begin and End
* are processed and executed efficiently.
*
* @param render A pointer to the LDL_3DRender instance.
*
* @note Always pair each Begin call with a matching End call.
* @note This function sets up the rendering state for 3D operations.
* @see LDL_3DRenderEnd
*/
LDL_LIBRARY void LDL_3DRenderBegin(LDL_3DRender* render);

/**
* @brief Ends a rendering batch and flushes all pending commands.
*
* This function ends a rendering batch and executes all drawing commands
* that were queued since the last Begin call.
*
* @param render A pointer to the LDL_3DRender instance.
*
* @note Always pair each End call with a matching Begin call.
* @see LDL_3DRenderBegin
*/
LDL_LIBRARY void LDL_3DRenderEnd(LDL_3DRender* render);

/**
* @brief Clears the rendering area with a specified color.
*
* This function clears the window's color buffer with the specified
* RGB color. This is typically called at the beginning of each frame
* to clear the screen.
*
* @param render A pointer to the LDL_3DRender instance.
* @param r      Red component (0.0 to 1.0).
* @param g      Green component (0.0 to 1.0).
* @param b      Blue component (0.0 to 1.0).
*
* @note Values are clamped to the range [0.0, 1.0].
* @note This function clears both color and depth buffers.
* @see LDL_3DRenderBegin
* @see LDL_3DRenderEnd
*/
LDL_LIBRARY void LDL_3DRenderClear(LDL_3DRender* render, float r, float g, float b);

/**
* @brief Draws a vertex buffer.
*
* This function renders the specified vertex buffer using the current
* rendering state, including textures, matrices, and shader settings.
*
* @param render       A pointer to the LDL_3DRender instance.
* @param vertexBuffer A pointer to the LDL_VertexBuffer to be rendered.
*
* @note The vertex buffer must have been populated with data before drawing.
* @note The current world, view, and projection matrices are applied.
* @note If a texture is bound, it will be applied to the vertices.
* @see LDL_VertexBufferCopy
* @see LDL_3DRenderBindTexture
* @see LDL_3DRenderSetWorld
* @see LDL_3DRenderSetView
* @see LDL_3DRenderSetProjection
*/
LDL_LIBRARY void LDL_3DRenderDraw(LDL_3DRender* render, LDL_VertexBuffer* vertexBuffer);

/**
* @brief Binds a texture for rendering.
*
* This function binds the specified texture to the renderer for use in
* subsequent drawing operations. The texture will be applied to vertices
* that have texture coordinates.
*
* @param render  A pointer to the LDL_3DRender instance.
* @param texture A pointer to the LDL_Texture to bind.
*
* @note Textures must be created in the same context as the renderer.
* @note Only one texture can be bound at a time.
* @see LDL_Texture
* @see LDL_3DRenderDraw
*/
LDL_LIBRARY void LDL_3DRenderBindTexture(LDL_3DRender* render, LDL_Texture* texture);

/**
* @brief Creates a new vertex buffer.
*
* This function allocates a new vertex buffer object with the specified
* flexible vertex format (FVF). The buffer is created in GPU memory for
* optimal rendering performance.
*
* @param context Pointer to the rendering context that will own this vertex buffer.
* @param fvf     Flexible Vertex Format flags defining the vertex layout:
*                - LDL_FVF_XYZ: Position (3 floats)
*                - LDL_FVF_XYZW: Position with W (4 floats)
*                - LDL_FVF_COLOR: Color (RGBA)
*                - LDL_FVF_NORMAL: Normal vector (3 floats)
*                - LDL_FVF_TEXCOORD: Texture coordinates (UV)
* @return A pointer to the newly created LDL_VertexBuffer instance,
*         or NULL on failure.
*
* @note Multiple FVF flags can be combined with bitwise OR.
* @note The buffer must be populated with data using LDL_VertexBufferCopy.
* @note The buffer must be destroyed using LDL_VertexBufferDestroy.
*
* @code
* // Example: Create a vertex buffer with position and color
* size_t fvf = LDL_FVF_XYZ | LDL_FVF_COLOR;
* LDL_VertexBuffer* vb = LDL_VertexBufferCreate(context, fvf);
* @endcode
*
* @see LDL_VertexBufferDestroy
* @see LDL_VertexBufferCopy
* @see LDL_FVF flags
*/
LDL_LIBRARY LDL_VertexBuffer* LDL_VertexBufferCreate(LDL_Context* context, size_t fvf);

/**
* @brief Destroys a vertex buffer and releases all associated resources.
*
* This function performs the necessary cleanup for the specified vertex buffer,
* including the deallocation of GPU memory. After this call, the pointer to
* the vertex buffer becomes invalid.
*
* @param vertexBuffer A pointer to the LDL_VertexBuffer instance to be destroyed.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @see LDL_VertexBufferCreate
*/
LDL_LIBRARY void LDL_VertexBufferDestroy(LDL_VertexBuffer* vertexBuffer);

/**
* @brief Sets the vertex buffer for rendering.
*
* This function prepares the specified vertex buffer for rendering.
* It should be called before drawing the buffer.
*
* @param vertexBuffer A pointer to the LDL_VertexBuffer to be set.
*
* @see LDL_3DRenderDraw
*/
LDL_LIBRARY void LDL_VertexBufferSet(LDL_VertexBuffer* vertexBuffer);

/**
* @brief Copies vertex data into the vertex buffer.
*
* This function uploads vertex data from system memory to the GPU vertex buffer.
* The data must match the vertex format specified when the buffer was created.
*
* @param vertexBuffer A pointer to the LDL_VertexBuffer instance.
* @param size         The size of each vertex in bytes.
* @param count        The number of vertices to copy.
* @param source       Pointer to the source data in system memory.
*
* @note The size must match the stride of the vertex format.
* @note The source data is copied to GPU memory.
* @note This function can be called multiple times to update vertex data.
*
* @code
* // Example: Copy vertex data
* struct Vertex {
*     float x, y, z;    // Position
*     float r, g, b, a; // Color
* };
*
* Vertex vertices[] = {
*     { -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
*     {  1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },
*     {  0.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f }
* };
*
* LDL_VertexBufferCopy(vb, sizeof(Vertex), 3, vertices);
* @endcode
*
* @see LDL_VertexBufferCreate
* @see LDL_FVF flags
*/
LDL_LIBRARY void LDL_VertexBufferCopy(LDL_VertexBuffer* vertexBuffer, size_t size, size_t count, void* source);

/**
* @brief Sets the world transformation matrix.
*
* This function sets the world matrix for the renderer, which transforms
* vertices from object space to world space.
*
* @param render A pointer to the LDL_3DRender instance.
* @param matrix Pointer to a 4x4 matrix (16 floats) in column-major order.
*
* @note The matrix must be a 4x4 transformation matrix.
* @note The matrix is applied to all subsequent draw calls.
* @see LDL_3DRenderSetView
* @see LDL_3DRenderSetProjection
*/
LDL_LIBRARY void LDL_3DRenderSetWorld(LDL_3DRender* render, const float* matrix);

/**
* @brief Sets the view transformation matrix.
*
* This function sets the view matrix for the renderer, which transforms
* vertices from world space to camera/view space.
*
* @param render A pointer to the LDL_3DRender instance.
* @param matrix Pointer to a 4x4 matrix (16 floats) in column-major order.
*
* @note The matrix must be a 4x4 transformation matrix.
* @note The matrix is applied to all subsequent draw calls.
* @see LDL_3DRenderSetWorld
* @see LDL_3DRenderSetProjection
*/
LDL_LIBRARY void LDL_3DRenderSetView(LDL_3DRender* render, const float* matrix);

/**
* @brief Sets the projection transformation matrix.
*
* This function sets the projection matrix for the renderer, which transforms
* vertices from view space to clip space.
*
* @param render A pointer to the LDL_3DRender instance.
* @param matrix Pointer to a 4x4 matrix (16 floats) in column-major order.
*
* @note The matrix must be a 4x4 projection matrix (perspective or orthographic).
* @note The matrix is applied to all subsequent draw calls.
*
* @code
* // Example: Set perspective projection
* float projection[16];
* // ... fill with perspective projection matrix ...
* LDL_3DRenderSetProjection(render, projection);
* @endcode
*
* @see LDL_3DRenderSetWorld
* @see LDL_3DRenderSetView
*/
LDL_LIBRARY void LDL_3DRenderSetProjection(LDL_3DRender* render, const float* matrix);

#ifdef __cplusplus
}
#endif

#endif
