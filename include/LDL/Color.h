/**
 * @file LDL_Color.h
 * @brief Defines color structures and utility functions for RGBA color manipulation.
 *
 * This file contains the definition of the LDL_Color structure, which represents
 * a color using 8-bit components for Red, Green, Blue, and Alpha.
 *
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp).
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 */

#ifndef LDL_Color_H
#define LDL_Color_H

#include <LDL/Types.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_Color
     * @brief A structure representing a color in RGBA format.
     *
     * Each component is stored as an unsigned 8-bit integer, ranging from 0 to 255.
     */
    typedef struct LDL_Color
    {
        uint8_t r; /**< Red component (0-255). */
        uint8_t g; /**< Green component (0-255). */
        uint8_t b; /**< Blue component (0-255). */
        uint8_t a; /**< Alpha (opacity) component (0-255), where 255 is opaque and 0 is transparent. */
    } LDL_Color;

    /**
     * @brief Creates an RGB color with full opacity.
     *
     * This function initializes an LDL_Color structure using the provided Red, Green,
     * and Blue values, automatically setting the Alpha component to 255 (fully opaque).
     *
     * @param r Red component value (0-25ASS).
     * @param g Green component value (0-255).
     * @param b Blue component value (0-255).
     * @return An LDL_Color structure initialized with the specified RGB values and alpha = 255.
     */
    LDL_LIBRARY LDL_Color LDL_ColorRgb(uint8_t r, uint8_t g, uint8_t b);

    /**
     * @brief Creates an RGBA color with a specific opacity.
     *
     * This function initializes an LDL_Color structure using the provided Red, Green,
     * Blue, and Alpha values.
     *
     * @param r Red component value (0-255).
     * @param g Green component value (0-255).
     * @param b Blue component value (0-255).
     * @param a Alpha component value (0-255), defining the transparency level.
     * @return An LDL_Color structure initialized with the specified RGBA values.
     */
    LDL_LIBRARY LDL_Color LDL_ColorRgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#ifdef __cplusplus
}
#endif 

#endif // LDL_Color_H
