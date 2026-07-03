/**
 * @file LDL_Surface.h
 * @brief Defines surface management for 2D image buffers and pixel manipulation.
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

#ifndef LDL_Surface_H
#define LDL_Surface_H

#include <LDL/Vec2i.h>
#include <LDL/Color.h>
#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_Surface
* @brief Opaque structure representing a 2D pixel surface.
*
* This structure encapsulates a 2D image buffer with pixel data, dimensions,
* format information, and color key support. Surfaces are used for image
* storage, manipulation, and rendering operations.
*
* Key features:
* - Pixel data storage with various formats
* - Capacity and size management
* - Color key support for transparency
* - Pitch (stride) management for efficient scanning
*
* @note The surface manages its own pixel memory and handles cleanup.
* @see LDL_SurfaceCreateFromCapacity
* @see LDL_SurfaceCreateFromSize
* @see LDL_SurfaceCreateFromPixels
*/
typedef struct LDL_Surface LDL_Surface;

/**
* @brief Destroys a surface and frees all associated resources.
*
* This function releases all memory and resources associated with the
* specified surface, including the pixel data buffer.
*
* @param surface Pointer to the surface to destroy.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note After destruction, the surface pointer becomes invalid.
* @see LDL_SurfaceCreateFromCapacity
* @see LDL_SurfaceCreateFromSize
* @see LDL_SurfaceCreateFromPixels
*/
LDL_LIBRARY void LDL_SurfaceDestroy(LDL_Surface* surface);

/**
* @brief Creates a surface with a specified capacity.
*
* This function allocates a new surface with a buffer large enough to hold
* the specified capacity of pixels. The surface size is initially set to
* match the capacity, but can be modified later. Memory is allocated for
* the pixel data based on the pixel format.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @param pixelFormat The pixel format to use for the surface (from LDL_PixelFormat enumeration).
* @param capacity The maximum number of pixels in each dimension.
* @return A pointer to the newly created LDL_Surface instance, or NULL on failure.
*
* @note The capacity determines the maximum dimensions the surface can hold.
* @note The actual size can be smaller than the capacity.
* @note Memory is allocated as: capacity.x * capacity.y * bytes_per_pixel.
* @see LDL_SurfaceCreateFromSize
* @see LDL_SurfaceCreateFromPixels
* @see LDL_SurfaceGetCapacity
* @see LDL_SurfaceGetSize
*/
LDL_LIBRARY LDL_Surface* LDL_SurfaceCreateFromCapacity(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i capacity);

/**
* @brief Creates a surface with a specified size.
*
* This function allocates a new surface with dimensions exactly matching
* the specified size. Memory is allocated for the pixel data based on the
* pixel format and dimensions.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @param pixelFormat The pixel format to use for the surface (from LDL_PixelFormat enumeration).
* @param size The dimensions of the surface in pixels.
* @return A pointer to the newly created LDL_Surface instance, or NULL on failure.
*
* @note The capacity is set equal to the size.
* @note This is the most commonly used creation function for new surfaces.
* @see LDL_SurfaceCreateFromCapacity
* @see LDL_SurfaceCreateFromPixels
*/
LDL_LIBRARY LDL_Surface* LDL_SurfaceCreateFromSize(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size);

/**
* @brief Creates a surface from existing pixel data.
*
* This function creates a new surface that uses the provided pixel data
* without copying it. The surface takes ownership of the pixel data and
* will free it when destroyed.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @param pixelFormat The pixel format of the provided data (from LDL_PixelFormat enumeration).
* @param size The dimensions of the pixel data in pixels.
* @param pixels Pointer to the pixel data buffer. Must be large enough to hold
*               size.x * size.y * bytes_per_pixel bytes.
* @return A pointer to the newly created LDL_Surface instance, or NULL on failure.
*
* @note The surface takes ownership of the pixel data and will free it.
* @note Do not free or modify the pixel data after passing it to this function.
* @note The buffer must be properly aligned for the pixel format.
* @see LDL_SurfaceCreateFromSize
* @see LDL_SurfaceGetPixels
*/
LDL_LIBRARY LDL_Surface* LDL_SurfaceCreateFromPixels(LDL_Result* result, uint8_t pixelFormat, LDL_Vec2i size, uint8_t* pixels);

/**
* @brief Retrieves the maximum capacity of the surface.
*
* This function returns the maximum dimensions that the surface can hold.
* The capacity may be larger than the current size, allowing for future
* expansion.
*
* @param surface Pointer to the surface.
* @return The capacity of the surface as an LDL_Vec2i structure.
*
* @note The capacity is fixed when the surface is created.
* @see LDL_SurfaceGetSize
* @see LDL_SurfaceCreateFromCapacity
*/
LDL_LIBRARY LDL_Vec2i LDL_SurfaceGetCapacity(LDL_Surface* surface);

/**
* @brief Retrieves the current size of the surface.
*
* This function returns the actual dimensions of the surface in pixels.
* The size may be less than or equal to the capacity.
*
* @param surface Pointer to the surface.
* @return The current size of the surface as an LDL_Vec2i structure.
*
* @see LDL_SurfaceGetCapacity
*/
LDL_LIBRARY LDL_Vec2i LDL_SurfaceGetSize(LDL_Surface* surface);

/**
* @brief Retrieves the number of bytes per pixel for the surface.
*
* This function returns the memory footprint of a single pixel based on
* the surface's pixel format.
*
* @param surface Pointer to the surface.
* @return The number of bytes per pixel (e.g., 3 for RGB24, 4 for RGBA32).
*
* @note This value is determined by the pixel format of the surface.
* @see LDL_SurfaceGetPixelFormat
* @see LDL_BytesPerPixelFromPixelFormat
*/
LDL_LIBRARY uint8_t LDL_SurfaceGetBytesPerPixel(LDL_Surface* surface);

/**
* @brief Retrieves a pointer to the surface's pixel data.
*
* This function returns a pointer to the raw pixel data buffer of the surface.
* The data can be read or modified directly.
*
* @param surface Pointer to the surface.
* @return A pointer to the pixel data buffer, or NULL if the surface is invalid.
*
* @note The returned pointer is owned by the surface and should not be freed.
* @note The data format corresponds to the surface's pixel format.
* @note Modifying the pixel data directly affects the surface content.
* @see LDL_SurfaceGetBytesPerPixel
* @see LDL_SurfaceGetPixelFormat
*/
LDL_LIBRARY uint8_t* LDL_SurfaceGetPixels(LDL_Surface* surface);

/**
* @brief Retrieves the pixel format of the surface.
*
* This function returns the pixel format identifier for the surface,
* which describes the memory layout and channel arrangement of the pixel data.
*
* @param surface Pointer to the surface.
* @return The pixel format identifier (from LDL_PixelFormat enumeration).
*
* @see LDL_SurfaceGetBytesPerPixel
* @see LDL_PixelFormat
*/
LDL_LIBRARY uint8_t LDL_SurfaceGetPixelFormat(LDL_Surface* surface);

/**
* @brief Retrieves the pitch (stride) of the surface.
*
* This function returns the number of bytes in each row of the surface,
* which may be larger than the width * bytes_per_pixel due to alignment.
* The pitch is useful for performing efficient row-wise operations.
*
* @param surface Pointer to the surface.
* @return The pitch of the surface in bytes.
*
* @note The pitch is at least: size.x * bytes_per_pixel.
* @note The pitch may include padding for performance optimization.
* @see LDL_SurfaceGetSize
* @see LDL_SurfaceGetBytesPerPixel
*/
LDL_LIBRARY size_t LDL_SurfaceGetPitch(LDL_Surface* surface);

/**
* @brief Sets a color key for transparency.
*
* This function sets a color key for the surface. Pixels matching this color
* will be treated as transparent during rendering operations.
*
* @param surface Pointer to the surface.
* @param color The color to use as a color key.
*
* @note Color key is commonly used for sprite transparency.
* @note The color key is enabled after setting it.
* @see LDL_SurfaceGetColorKey
* @see LDL_SurfaceIsColorKey
*/
LDL_LIBRARY void LDL_SurfaceSetColorKey(LDL_Surface* surface, LDL_Color color);

/**
* @brief Retrieves the current color key.
*
* This function returns the color key that is currently set for the surface.
*
* @param surface Pointer to the surface.
* @return The current color key as an LDL_Color structure.
*
* @note If no color key is set, the returned color is undefined.
* @see LDL_SurfaceSetColorKey
* @see LDL_SurfaceIsColorKey
*/
LDL_LIBRARY LDL_Color LDL_SurfaceGetColorKey(LDL_Surface* surface);

/**
* @brief Checks whether a color key is set for the surface.
*
* This function returns true if a color key has been set for the surface,
* indicating that transparency is enabled.
*
* @param surface Pointer to the surface.
* @return true if a color key is set, false otherwise.
*
* @see LDL_SurfaceSetColorKey
* @see LDL_SurfaceGetColorKey
*/
LDL_LIBRARY bool LDL_SurfaceIsColorKey(LDL_Surface* surface);

#ifdef __cplusplus
}
#endif

#endif // LDL_Surface_H
