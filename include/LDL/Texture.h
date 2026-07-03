/**
 * @file LDL_Texture.h
 * @brief Defines texture management for GPU-accelerated rendering.
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

#ifndef LDL_Texture_H
#define LDL_Texture_H

#include <LDL/Vec2i.h>
#include <LDL/Enums.h>
#include <LDL/Result.h>
#include <LDL/Palette.h>
#include <LDL/Context.h>
#include <LDL/PixFrmt.h>
#include <LDL/Surface.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_Texture
* @brief Opaque structure representing a GPU texture.
*
* This structure encapsulates a texture object stored in GPU memory,
* optimized for fast rendering operations. Textures are created from
* pixel data, surfaces, or allocated directly, and are used as rendering
* resources in the graphics pipeline.
*
* Key features:
* - GPU memory storage for optimal performance
* - Various pixel format support
* - Creation from multiple sources (pixels, surfaces, size)
* - Context-aware management
*
* @note Textures are bound to a specific rendering context.
* @note GPU memory is managed automatically when the texture is destroyed.
* @see LDL_Context
* @see LDL_Surface
*/
typedef struct LDL_Texture LDL_Texture;

/**
* @brief Creates a texture from pixel data.
*
* This function allocates a new texture in GPU memory and initializes it
* with the provided pixel data. The texture is created with the specified
* dimensions and pixel format, and is associated with the given rendering
* context.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @param context Pointer to the rendering context that will own this texture.
* @param pixelFormat The pixel format of the texture (from LDL_PixelFormat enumeration).
* @param size The dimensions of the texture in pixels.
* @param pixels Pointer to the pixel data buffer. Must be large enough to hold
*               size.x * size.y * bytes_per_pixel bytes.
* @return A pointer to the newly created LDL_Texture instance, or NULL on failure.
*
* @note The texture copies the pixel data into GPU memory; the original
*       buffer can be freed after this call.
* @note The context must be valid and initialized before creating textures.
* @note The pixel format must be supported by the underlying graphics system.
* @see LDL_TextureCreateFromSize
* @see LDL_TextureCreateFromSurface
* @see LDL_TextureDestroy
*/
LDL_LIBRARY LDL_Texture* LDL_TextureCreateFromPixels(LDL_Result* result, LDL_Context* context, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);

/**
* @brief Creates an empty texture of the specified size.
*
* This function allocates a new texture in GPU memory with the specified
* dimensions and pixel format, but does not initialize the pixel data.
* The texture content is undefined until filled with data.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @param context Pointer to the rendering context that will own this texture.
* @param pixelFormat The pixel format of the texture (from LDL_PixelFormat enumeration).
* @param size The dimensions of the texture in pixels.
* @return A pointer to the newly created LDL_Texture instance, or NULL on failure.
*
* @note This function is useful for creating render targets or textures
*       that will be filled later.
* @note The texture memory is allocated in GPU memory but not initialized.
* @note The context must be valid and initialized before creating textures.
* @see LDL_TextureCreateFromPixels
* @see LDL_TextureCreateFromSurface
* @see LDL_TextureDestroy
*/
LDL_LIBRARY LDL_Texture* LDL_TextureCreateFromSize(LDL_Result* result, LDL_Context* context, uint8_t pixelFormat, LDL_Vec2i size);

/**
* @brief Creates a texture from a surface.
*
* This function creates a new texture in GPU memory by copying the pixel
* data from an existing LDL_Surface. The texture inherits the pixel format
* and dimensions of the surface.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @param context Pointer to the rendering context that will own this texture.
* @param surface Pointer to the source surface containing the pixel data.
* @return A pointer to the newly created LDL_Texture instance, or NULL on failure.
*
* @note The surface data is copied to GPU memory; the surface remains
*       unchanged and can be destroyed separately.
* @note This is the recommended way to convert surfaces to textures for
*       accelerated rendering.
* @note The surface's pixel format must be supported by the texture system.
* @note Color key information from the surface is preserved.
* @see LDL_TextureCreateFromPixels
* @see LDL_TextureCreateFromSize
* @see LDL_Surface
* @see LDL_TextureDestroy
*/
LDL_LIBRARY LDL_Texture* LDL_TextureCreateFromSurface(LDL_Result* result, LDL_Context* context, LDL_Surface* surface);

/**
* @brief Destroys a texture and frees all associated GPU resources.
*
* This function releases all GPU memory and resources associated with the
* specified texture. After destruction, the texture pointer becomes invalid
* and should not be used.
*
* @param texture Pointer to the texture to destroy.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note GPU memory is automatically released when the texture is destroyed.
* @note All references to this texture in rendering operations become invalid.
* @see LDL_TextureCreateFromPixels
* @see LDL_TextureCreateFromSize
* @see LDL_TextureCreateFromSurface
*/
LDL_LIBRARY void LDL_TextureDestroy(LDL_Texture* texture);

/**
* @brief Retrieves the dimensions of the texture.
*
* This function returns the width and height of the specified texture
* in pixels.
*
* @param texture Pointer to the texture.
* @return The dimensions of the texture as an LDL_Vec2i structure.
*
* @note The size is determined at texture creation time and cannot be changed.
* @see LDL_TextureCreateFromPixels
* @see LDL_TextureCreateFromSize
* @see LDL_TextureCreateFromSurface
*/
LDL_LIBRARY LDL_Vec2i LDL_TextureGetSize(LDL_Texture* texture);

#ifdef __cplusplus
}
#endif

#endif // LDL_Texture_H
