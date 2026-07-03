/**
 * @file LDL_Image.h
 * @brief Defines image loading and manipulation functionality.
 *
 * This file provides an interface for loading images from files, retrieving
 * image properties such as size and pixel data, and managing the image loader
 * lifecycle. It supports various pixel formats and error handling through
 * the LDL_Result mechanism.
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

#ifndef LDL_Image_H
#define LDL_Image_H

#include <LDL/Vec2i.h>
#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_ImageLoader
     * @brief Opaque structure representing an image loader instance.
     *
     * This structure encapsulates the state and data required for loading
     * and managing image files. It is used as a handle for all image-related
     * operations. The internal implementation details are hidden from the user.
     */
    typedef struct LDL_ImageLoader LDL_ImageLoader;

    /**
     * @brief Creates a new image loader instance.
     *
     * This function allocates and initializes a new LDL_ImageLoader object.
     * The instance can be used to load images from files and retrieve their data.
     *
     * @param result Pointer to an LDL_Result variable that will receive the operation status.
     *               If the operation succeeds, the result will be set to LDL_RESULT_SUCCESS.
     *               If an error occurs, the result will contain an appropriate error code.
     * @return A pointer to the newly created LDL_ImageLoader instance, or NULL on failure.
     *
     * @note The returned image loader must be freed using LDL_ImageLoaderDestroy
     *       when it is no longer needed to avoid memory leaks.
     * @see LDL_ImageLoaderDestroy
     */
    LDL_LIBRARY LDL_ImageLoader* LDL_ImageLoaderCreate(LDL_Result* result);

    /**
     * @brief Destroys an image loader instance and frees all associated resources.
     *
     * This function releases all memory and resources associated with the
     * specified image loader. After this call, the image loader pointer is
     * invalid and should not be used again.
     *
     * @param imageLoader Pointer to the image loader instance to destroy.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @see LDL_ImageLoaderCreate
     */
    LDL_LIBRARY void LDL_ImageLoaderDestroy(LDL_ImageLoader* imageLoader);

    /**
     * @brief Clears the current image data from the image loader.
     *
     * This function releases any currently loaded image data from the loader,
     * resetting it to an empty state. The image loader instance remains valid
     * and can be reused to load a new image.
     *
     * @param imageLoader Pointer to the image loader instance to clear.
     *
     * @note This function does not destroy the image loader; it only clears
     *       the currently loaded image data.
     * @see LDL_ImageLoaderCreate
     * @see LDL_ImageLoaderDestroy
     */
    LDL_LIBRARY void LDL_ImageLoaderClear(LDL_ImageLoader* imageLoader);

    /**
     * @brief Loads an image from a file.
     *
     * This function loads an image from the specified file path into the image
     * loader. The image data can then be accessed using other functions such as
     * LDL_ImageLoaderGetPixels and LDL_ImageLoaderGetSize.
     *
     * @param imageLoader Pointer to the image loader instance.
     * @param path Path to the image file to load. The path can be absolute or relative.
     *
     * @note Supported image formats depend on the underlying implementation.
     *       Common formats include PNG, JPEG, BMP, and others.
     * @note If a previous image was loaded, it will be replaced by the new one.
     * @see LDL_ImageLoaderGetPixels
     * @see LDL_ImageLoaderGetSize
     * @see LDL_ImageLoaderGetPixelFormat
     */
    LDL_LIBRARY void LDL_ImageLoaderLoadFromFile(LDL_ImageLoader* imageLoader, const char* path);

    /**
     * @brief Retrieves the dimensions of the loaded image.
     *
     * This function returns the width and height of the currently loaded image
     * as a LDL_Vec2i structure.
     *
     * @param imageLoader Pointer to the image loader instance.
     * @return A LDL_Vec2i structure containing the image width and height.
     *         If no image is loaded, returns a vector with both components set to 0.
     *
     * @note The returned dimensions are in pixels.
     * @see LDL_Vec2i
     * @see LDL_ImageLoaderGetPixels
     */
    LDL_LIBRARY LDL_Vec2i LDL_ImageLoaderGetSize(LDL_ImageLoader* imageLoader);

    /**
     * @brief Retrieves a pointer to the loaded image pixel data.
     *
     * This function returns a pointer to the raw pixel data of the currently
     * loaded image. The pixel data format can be determined using the
     * LDL_ImageLoaderGetPixelFormat function.
     *
     * @param imageLoader Pointer to the image loader instance.
     * @return A pointer to uint8_t buffer containing the image pixel data.
     *         Returns NULL if no image is loaded or if an error occurs.
     *
     * @note The pixel data is owned by the image loader and should not be
     *       freed by the caller. The data remains valid as long as the image
     *       loader exists and no new image is loaded.
     * @note The buffer size can be calculated as width * height * bytes_per_pixel.
     * @see LDL_ImageLoaderGetSize
     * @see LDL_ImageLoaderGetPixelFormat
     */
    LDL_LIBRARY uint8_t* LDL_ImageLoaderGetPixels(LDL_ImageLoader* imageLoader);

    /**
     * @brief Retrieves the pixel format of the loaded image.
     *
     * This function returns a value indicating the pixel format used by the
     * currently loaded image. The format determines how the pixel data should
     * be interpreted (e.g., RGB, RGBA, grayscale, etc.).
     *
     * @param imageLoader Pointer to the image loader instance.
     * @return A uint8_t value representing the pixel format.
     *         Returns 0 if no image is loaded.
     *
     * @note The specific format values and their meanings depend on the
     *       underlying implementation. Common values include:
     *       - 0: Unknown or no image
     *       - 1: RGB (3 bytes per pixel)
     *       - 2: RGBA (4 bytes per pixel)
     *       - Other values may indicate different formats.
     * @see LDL_ImageLoaderGetPixels
     */
    LDL_LIBRARY uint8_t LDL_ImageLoaderGetPixelFormat(LDL_ImageLoader* imageLoader);

#ifdef __cplusplus
}
#endif

#endif // LDL_Image_H
