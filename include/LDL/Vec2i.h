/**
 * @file LDL_Vec2i.h
 * @brief Defines a 2D integer vector structure and utility functions.
 *
 * This file contains the definition of the LDL_Vec2i structure, which represents
 * a 2D vector or point using signed 32-bit integer coordinates. It provides
 * a simple and efficient way to handle 2D positions, sizes, and offsets in
 * graphics and computational geometry applications.
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

#ifndef LDL_Vec2i_H
#define LDL_Vec2i_H

#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_Vec2i
* @brief A structure representing a 2D integer vector.
*
* This structure is used to represent points, positions, dimensions, or
* direction vectors in a 2D space using signed integer coordinates.
* It is commonly used for window coordinates, pixel positions, and
* image dimensions.
*
* The coordinates are stored as signed 32-bit integers, providing a range
* of approximately -2.1 billion to 2.1 billion, which is sufficient for
* most graphics and computational applications.
*/
typedef struct LDL_Vec2i
{
    int x; /**< X-coordinate or horizontal component (signed 32-bit integer). */
    int y; /**< Y-coordinate or vertical component (signed 32-bit integer). */
} LDL_Vec2i;

/**
* @brief Creates a 2D integer vector with the specified components.
*
* This convenience function initializes an LDL_Vec2i structure with
* the provided x and y values. It provides a simple and readable way
* to create vector instances without manual structure initialization.
*
* @param x The X-coordinate or horizontal component value.
* @param y The Y-coordinate or vertical component value.
* @return An LDL_Vec2i structure initialized with the specified x and y values.
*
* @note This function is useful for creating vectors inline, especially
*       in function calls or expressions where temporary vectors are needed.
* @note The return value is passed by value, making it efficient for
*       use in C and C++ code.
*
* @code
* // Example usage:
* LDL_Vec2i position = LDL_GetVec2i(100, 200);
* LDL_Vec2i size = LDL_GetVec2i(640, 480);
* @endcode
*
* @see LDL_Vec2i
*/
LDL_LIBRARY LDL_Vec2i LDL_GetVec2i(int x, int y);

#ifdef __cplusplus
}
#endif

#endif
