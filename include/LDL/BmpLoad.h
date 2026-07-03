/**
 * @file LDL_BmpLoad.h
 * @brief Defines BMP image loading functionality.
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

#ifndef LDL_BmpLoad_H
#define LDL_BmpLoad_H

#include <LDL/Types.h>
#include <LDL/Vec2i.h>
#include <LDL/Config.h>
#include <LDL/Result.h>
#include <LDL/PixFrmt.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_BmpLoader
* @brief Opaque structure representing a BMP image loader.
*
* This structure encapsulates the state and data required for loading
* and parsing BMP (Bitmap) image files. It provides functionality to
* load BMP files from disk, extract pixel data, and retrieve image
* properties such as dimensions and format.
*
* Key features:
* - BMP file loading and parsing
* - Support for various BMP formats (24-bit, 32-bit, etc.)
* - Pixel data extraction
* - Error handling through LDL_Result mechanism
*
* @note The BMP loader handles both compressed and uncompressed BMP files.
* @note The loader manages its own memory for pixel data.
* @see LDL_BmpLoaderCreate
* @see LDL_BmpLoaderDestroy
*/
typedef struct LDL_BmpLoader LDL_BmpLoader;

/**
* @brief Creates a new BMP loader instance.
*
* This function allocates and initializes a new LDL_BmpLoader object.
* The instance can be used to load BMP files and retrieve their pixel data.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to success state.
*               If an error occurs, the result will contain an appropriate error message.
* @return A pointer to the newly created LDL_BmpLoader instance, or NULL on failure.
*
* @note The returned BMP loader must be freed using LDL_BmpLoaderDestroy
*       when it is no longer needed to avoid memory leaks.
* @see LDL_BmpLoaderDestroy
* @see LDL_BmpLoaderLoadFromFile
*/
LDL_LIBRARY LDL_BmpLoader* LDL_BmpLoaderCreate(LDL_Result* result);

/**
* @brief Destroys a BMP loader instance and frees all associated resources.
*
* This function releases all memory and resources associated with the
* specified BMP loader, including any loaded pixel data.
*
* @param loader Pointer to the BMP loader instance to destroy.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note After destruction, any pointers to the loader become invalid.
* @see LDL_BmpLoaderCreate
*/
LDL_LIBRARY void LDL_BmpLoaderDestroy(LDL_BmpLoader* loader);

/**
* @brief Retrieves the dimensions of the loaded BMP image.
*
* This function returns the width and height of the currently loaded
* BMP image in pixels.
*
* @param loader Pointer to the BMP loader instance.
* @return The dimensions of the loaded image as an LDL_Vec2i structure.
*         If no image is loaded, returns a vector with both components set to 0.
*
* @note The dimensions are extracted from the BMP file header.
* @note The width and height are always positive for valid BMP files.
* @see LDL_BmpLoaderLoadFromFile
* @see LDL_BmpLoaderGetPixels
*/
LDL_LIBRARY LDL_Vec2i LDL_BmpLoaderGetSize(LDL_BmpLoader* loader);

/**
* @brief Retrieves a pointer to the loaded BMP pixel data.
*
* This function returns a pointer to the raw pixel data of the currently
* loaded BMP image. The data format can be determined using the
* LDL_BmpLoaderGetPixelFormat function.
*
* @param loader Pointer to the BMP loader instance.
* @return A pointer to uint8_t buffer containing the image pixel data.
*         Returns NULL if no image is loaded or if an error occurs.
*
* @note The pixel data is owned by the BMP loader and should not be
*       freed by the caller. The data remains valid as long as the
*       loader exists and no new image is loaded.
* @note The buffer size can be calculated as:
*       width * height * LDL_BmpLoaderGetBytesPerPixels(loader)
* @note The data is stored in row-major order, typically with
*       bottom-to-top row order (BMP format standard).
* @see LDL_BmpLoaderGetSize
* @see LDL_BmpLoaderGetPixelFormat
* @see LDL_BmpLoaderGetBytesPerPixels
*/
LDL_LIBRARY uint8_t* LDL_BmpLoaderGetPixels(LDL_BmpLoader* loader);

/**
* @brief Retrieves the pixel format of the loaded BMP image.
*
* This function returns the pixel format identifier for the currently
* loaded BMP image, describing the memory layout and channel arrangement
* of the pixel data.
*
* @param loader Pointer to the BMP loader instance.
* @return The pixel format identifier (from LDL_PixelFormat enumeration).
*         Returns LDL_PixelFormatUnknown if no image is loaded.
*
* @note BMP files commonly use RGB24 (24-bit) or RGBA32 (32-bit) formats.
* @note The format is determined by the BMP file's bit depth:
*       - 24-bit: LDL_PixelFormatRGB24
*       - 32-bit: LDL_PixelFormatRGBA32
* @see LDL_BmpLoaderGetBytesPerPixels
* @see LDL_BmpLoaderGetPixels
* @see LDL_PixelFormat
*/
LDL_LIBRARY uint8_t LDL_BmpLoaderGetPixelFormat(LDL_BmpLoader* loader);

/**
* @brief Retrieves the number of bytes per pixel for the loaded BMP image.
*
* This function returns the memory footprint of a single pixel based on
* the loaded BMP image's pixel format.
*
* @param loader Pointer to the BMP loader instance.
* @return The number of bytes per pixel (e.g., 3 for RGB24, 4 for RGBA32).
*         Returns 0 if no image is loaded.
*
* @note This value is derived from the pixel format of the loaded BMP.
* @note Common BMP formats:
*       - 24-bit BMP: 3 bytes per pixel (RGB)
*       - 32-bit BMP: 4 bytes per pixel (RGBA)
* @see LDL_BmpLoaderGetPixelFormat
* @see LDL_BmpLoaderGetPixels
*/
LDL_LIBRARY uint8_t LDL_BmpLoaderGetBytesPerPixels(LDL_BmpLoader* loader);

/**
* @brief Loads a BMP image from a file.
*
* This function loads and parses a BMP image from the specified file path
* into the BMP loader. The image data can then be accessed using other
* functions such as LDL_BmpLoaderGetPixels and LDL_BmpLoaderGetSize.
*
* @param loader Pointer to the BMP loader instance.
* @param path Path to the BMP file to load. The path can be absolute or relative.
* @return true if the BMP file was successfully loaded, false otherwise.
*
* @note Supported BMP formats include:
*       - 24-bit uncompressed RGB
*       - 32-bit uncompressed RGBA
*       - Various compression methods (RLE, etc.)
* @note If a previous image was loaded, it will be replaced by the new one.
* @note The function validates the BMP header and ensures the file is a valid BMP.
* @note Error details can be retrieved from the result object passed to
*       LDL_BmpLoaderCreate if the loader was created with one.
* @see LDL_BmpLoaderCreate
* @see LDL_BmpLoaderGetPixels
* @see LDL_BmpLoaderGetSize
* @see LDL_BmpLoaderGetPixelFormat
*
* @code
* // Example: Loading a BMP file
* LDL_Result* result = LDL_ResultCreate();
* LDL_BmpLoader* loader = LDL_BmpLoaderCreate(result);
*
* if (LDL_BmpLoaderLoadFromFile(loader, "image.bmp")) {
*     LDL_Vec2i size = LDL_BmpLoaderGetSize(loader);
*     uint8_t* pixels = LDL_BmpLoaderGetPixels(loader);
*     uint8_t bpp = LDL_BmpLoaderGetBytesPerPixels(loader);
*     printf("Loaded image: %dx%d, %d bytes per pixel\n", size.x, size.y, bpp);
* } else {
*     printf("Failed to load BMP: %s\n", LDL_ResultGetMessage(result));
* }
*
* LDL_BmpLoaderDestroy(loader);
* LDL_ResultDestroy(result);
* @endcode
*/
LDL_LIBRARY bool LDL_BmpLoaderLoadFromFile(LDL_BmpLoader* loader, const char* path);

#ifdef __cplusplus
}
#endif

#endif // LDL_BmpLoad_H
