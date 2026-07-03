/**
 * @file LDL_PixFrmt.h
 * @brief Defines pixel format enumerations and utility functions for calculating pixel size.
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

#ifndef LDL_PixFrmt_H
#define LDL_PixFrmt_H

#include <LDL/Types.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @enum LDL_PixelFormat
     * @brief An enumeration of supported pixel color formats within the library.
     *
     * This enumeration defines the memory layout and channel order for various
     * pixel formats used in image processing and buffer management. Each format
     * specifies the number of bits per channel, the channel order, and whether
     * an alpha (transparency) channel is present.
     *
     * The formats are organized by bit depth and channel arrangement:
     * - 32-bit formats: RGBA and BGRA (with alpha channel)
     * - 24-bit formats: RGB and BGR (without alpha channel)
     *
     * @note When working with image data, it is important to use the correct
     *       pixel format to properly interpret the byte order and channel layout.
     * @see LDL_BytesPerPixelFromPixelFormat
     */
    enum
    {
        /**
         * @brief Represents an undefined or unsupported pixel format.
         *
         * This value is returned when a pixel format cannot be recognized
         * or is not supported by the library. It typically indicates an error
         * condition or uninitialized state.
         */
        LDL_PixelFormatUnknown,

        /**
         * @brief 32-bit format consisting of Red, Green, Blue, and Alpha channels (RGBA).
         *
         * Each channel occupies 8 bits, for a total of 32 bits (4 bytes) per pixel.
         * The memory layout is: [R][G][B][A] (in order of increasing memory address).
         * Alpha channel controls transparency, where 255 is fully opaque and 0 is fully transparent.
         *
         * This format is commonly used for textures and images that require transparency.
         *
         * @note Total bytes per pixel: 4
         */
        LDL_PixelFormatRGBA32,

        /**
         * @brief 32-bit format consisting of Blue, Green, Red, and Alpha channels (BGRA).
         *
         * Each channel occupies 8 bits, for a total of 32 bits (4 bytes) per pixel.
         * The memory layout is: [B][G][R][A] (in order of increasing memory address).
         * Alpha channel controls transparency, where 255 is fully opaque and 0 is fully transparent.
         *
         * This format is commonly used on Windows (GDI, DirectX) and some graphics APIs.
         *
         * @note Total bytes per pixel: 4
         */
        LDL_PixelFormatBGRA32,

        /**
         * @brief 24-bit format consisting of Red, Green, and Blue channels (RGB).
         *
         * Each channel occupies 8 bits, for a total of 24 bits (3 bytes) per pixel.
         * The memory layout is: [R][G][B] (in order of increasing memory address).
         * No alpha/transparency channel is present; the image is fully opaque.
         *
         * This is a common format for standard images without transparency requirements.
         *
         * @note Total bytes per pixel: 3
         */
        LDL_PixelFormatRGB24,

        /**
         * @brief 24-bit format consisting of Blue, Green, and Red channels (BGR).
         *
         * Each channel occupies 8 bits, for a total of 24 bits (3 bytes) per pixel.
         * The memory layout is: [B][G][R] (in order of increasing memory address).
         * No alpha/transparency channel is present; the image is fully opaque.
         *
         * This format is commonly used in some graphics systems and hardware.
         *
         * @note Total bytes per pixel: 3
         */
        LDL_PixelFormatBGR24
    };

    /**
     * @brief Calculates the number of bytes required for a single pixel based on the specified format.
     *
     * This function takes a pixel format identifier and returns the memory footprint
     * (in bytes) that one pixel occupies in a buffer using that specific format.
     * The result can be used to calculate buffer sizes, perform pointer arithmetic,
     * or determine memory requirements for image processing operations.
     *
     * @param pixelFormat A value representing the desired pixel format (from the pixel format enumeration).
     *                    Valid values include LDL_PixelFormatRGBA32, LDL_PixelFormatBGRA32,
     *                    LDL_PixelFormatRGB24, and LDL_PixelFormatBGR24.
     * @return uint8_t The number of bytes per pixel:
     *         - 4 for 32-bit formats (RGBA32, BGRA32)
     *         - 3 for 24-bit formats (RGB24, BGR24)
     *         - 0 if the provided pixelFormat is LDL_PixelFormatUnknown or invalid
     *
     * @note This function is useful for:
     *       - Calculating image buffer sizes: width * height * bytes_per_pixel
     *       - Performing pointer arithmetic to navigate pixel data
     *       - Allocating memory for image buffers
     *       - Converting between different pixel formats
     *
     * @code
     * // Example: Calculate buffer size for a 640x480 RGBA image
     * uint8_t bytesPerPixel = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatRGBA32);
     * size_t bufferSize = 640 * 480 * bytesPerPixel;
     * uint8_t* imageBuffer = (uint8_t*)malloc(bufferSize);
     * @endcode
     *
     * @see LDL_PixelFormat
     * @see LDL_PixelFormatRGBA32
     * @see LDL_PixelFormatBGRA32
     * @see LDL_PixelFormatRGB24
     * @see LDL_PixelFormatBGR24
     */
    LDL_LIBRARY uint8_t LDL_BytesPerPixelFromPixelFormat(size_t pixelFormat);

#ifdef __cplusplus
}
#endif

#endif // LDL_PixFrmt_H
