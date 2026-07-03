/**
 * @file LDL_Color.h
 * @brief Defines color structures and utility functions for RGBA color manipulation.
 *
 * This file contains the definition of the LDL_Color structure, which represents
 * a color using 8-bit components for Red, Green, Blue, and Alpha. It also provides
 * convenience functions for creating colors with full or custom opacity.
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
* This format is commonly used for graphics rendering, textures, and pixel manipulation.
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
* @param r Red component value (0-255).
* @param g Green component value (0-255).
* @param b Blue component value (0-255).
* @return An LDL_Color structure initialized with the specified RGB values and alpha = 255.
*
* @note This function is useful for creating opaque colors where transparency is not required.
* @see LDL_ColorRgba for creating colors with custom alpha.
*/
LDL_LIBRARY LDL_Color LDL_ColorRgb(uint8_t r, uint8_t g, uint8_t b);

/**
* @brief Creates an RGBA color with a specific opacity.
*
* This function initializes an LDL_Color structure using the provided Red, Green,
* Blue, and Alpha values. It allows full control over the transparency of the color.
*
* @param r Red component value (0-255).
* @param g Green component value (0-255).
* @param b Blue component value (0-255).
* @param a Alpha component value (0-255), defining the transparency level.
* @return An LDL_Color structure initialized with the specified RGBA values.
*
* @see LDL_ColorRgb for creating opaque colors with default alpha.
*/
LDL_LIBRARY LDL_Color LDL_ColorRgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#ifdef __cplusplus
}
#endif

#endif // LDL_Color_H
