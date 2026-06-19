/**
 * @file LDL_PixFrmt.h
 * @brief Defines pixel format enumerations and utility functions for calculating pixel size.
 * @author Evgeny Zoshchuk (JordanCpp)
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp).
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.
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
     * pixel formats used in image processing and buffer management.
     */
    enum
    {
        /**
         * @brief Represents an undefined or unsupported pixel format.
         */
        LDL_PixelFormatUnknown,

        /**
         * @brief 32-bit format consisting of Red, Green, Blue, and Alpha channels (RGBA).
         * Each channel occupies 8 bits.
         */
        LDL_PixelFormatRGBA32, // Note: I kept your logic, but usually these are named via a typed enum.

        /**
         * @brief 32-bit format consisting of Blue, Green, Red, and Alpha channels (BGRA).
         * Each channel occupies 8 bits.
         */
        LDL_PixelFormatBGRA32,

        /**
         * @brief 24-bit format consisting of Red, Green, and Blue channels (RGB).
         * Each channel occupies 8 bits; no transparency/alpha channel is present.
         */
        LDL_PixelFormatRGB24,

        /**
         * @brief 24-bit format consisting of Blue, Green, and Red channels (BGR).
         * Each channel occupies 8 bits; no transparency/alpha channel is present.
         */
        LDL_PixelFormatBGR24
    };

    /**
     * @brief Calculates the number of bytes required for a single pixel based on the specified format.
     *
     * This function takes a pixel format identifier and returns the memory footprint
     * (in bytes) that one pixel occupies in a buffer using that specific format.
     *
     * @param pixelFormat A value representing the desired pixel format (from the pixel format enumeration).
     * @return uint8_t The number of bytes per pixel. Returns 0 if the provided pixelFormat is unknown or invalid.
     */
    LDL_LIBRARY uint8_t LDL_BytesPerPixelFromPixelFormat(size_t pixelFormat);

#ifdef __cplusplus
}
#endif 

#endif // LDL_PixFrmt_H
