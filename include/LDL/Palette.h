/**
 * @file LDL_Palette.h
 * @brief Defines color palette management for indexed color operations.
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

#ifndef LDL_Palette_H
#define LDL_Palette_H

#include <LDL/Color.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @brief Maximum number of colors that can be stored in a palette.
     *
     * This constant defines the maximum capacity of a palette, which is 256 colors.
     * This is a common size for indexed color palettes used in many graphics formats
     * (e.g., 8-bit BMP, GIF, and other indexed image formats).
     *
     * @note The valid index range for palette operations is 0 to (LDL_PaletteMax - 1).
     * @see LDL_PaletteGet
     * @see LDL_PaletteSet
     */
    enum
    {
        LDL_PaletteMax = 256
    };

    /**
     * @struct LDL_Palette
     * @brief Opaque structure representing a color palette.
     *
     * This structure encapsulates an array of colors that can be used for
     * indexed color operations. A palette maps indices to actual RGBA colors,
     * allowing efficient color management and lookup.
     *
     * Key features:
     * - Stores up to 256 colors (LDL_PaletteMax)
     * - RGBA color support for each entry
     * - Index-based color access
     * - Memory-efficient color management
     *
     * Common use cases:
     * - 8-bit image rendering
     * - Palette-based animation
     * - Color lookup tables (CLUTs)
     * - Legacy graphics formats
     * - Color quantization
     *
     * @note The palette is initialized with default colors when created.
     * @note Each color entry stores 8-bit RGBA components.
     * @see LDL_PaletteCreate
     * @see LDL_PaletteDestroy
     * @see LDL_PaletteGet
     * @see LDL_PaletteSet
     */
    typedef struct LDL_Palette LDL_Palette;

    /**
     * @brief Creates and initializes a new palette instance.
     *
     * This function allocates memory for a new palette object and initializes
     * it with default colors. The palette can hold up to LDL_PaletteMax colors
     * (256 entries).
     *
     * @return A pointer to the newly created LDL_Palette instance if the
     *         allocation was successful; otherwise, a NULL pointer is returned.
     *
     * @note The returned palette must be freed using LDL_PaletteDestroy
     *       when it is no longer needed to avoid memory leaks.
     * @note The palette is initialized with default colors (typically black
     *       or a grayscale ramp) but can be customized using LDL_PaletteSet.
     * @see LDL_PaletteDestroy
     * @see LDL_PaletteSet
     * @see LDL_PaletteGet
     *
     * @code
     * // Example: Create and use a palette
     * LDL_Palette* palette = LDL_PaletteCreate();
     * if (palette) {
     *     // Set custom colors
     *     LDL_PaletteSet(palette, 0, LDL_ColorRgb(255, 0, 0));   // Red
     *     LDL_PaletteSet(palette, 1, LDL_ColorRgb(0, 255, 0));   // Green
     *     LDL_PaletteSet(palette, 2, LDL_ColorRgb(0, 0, 255));   // Blue
     *     // Use palette...
     *     LDL_PaletteDestroy(palette);
     * }
     * @endcode
     */
    LDL_LIBRARY LDL_Palette* LDL_PaletteCreate();

    /**
     * @brief Destroys a palette instance and releases all associated resources.
     *
     * This function performs the necessary cleanup for the specified palette,
     * including the deallocation of all color data. After this call, the pointer
     * to the palette becomes invalid.
     *
     * @param palette A pointer to the LDL_Palette instance that is intended to be destroyed.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @note All color data is lost when the palette is destroyed.
     * @see LDL_PaletteCreate
     */
    LDL_LIBRARY void LDL_PaletteDestroy(LDL_Palette* palette);

    /**
     * @brief Retrieves a color from the palette at the specified index.
     *
     * This function returns the color stored at the given index in the palette.
     * The color is returned as an LDL_Color structure containing the RGBA values.
     *
     * @param palette A pointer to the LDL_Palette instance.
     * @param index   The index of the color to retrieve (0 to LDL_PaletteMax - 1).
     * @return An LDL_Color structure containing the color at the specified index.
     *         If the index is out of range or the palette is invalid,
     *         returns a default color (typically black: r=0, g=0, b=0, a=255).
     *
     * @note The valid index range is 0 to 255 inclusive.
     * @note This function is commonly used when rendering indexed images
     *       or performing color lookups.
     *
     * @code
     * // Example: Get color at index 42
     * LDL_Color color = LDL_PaletteGet(palette, 42);
     * printf("Color at index 42: R=%d, G=%d, B=%d, A=%d\n",
     *        color.r, color.g, color.b, color.a);
     * @endcode
     *
     * @see LDL_PaletteSet
     * @see LDL_Color
     * @see LDL_PaletteMax
     */
    LDL_LIBRARY LDL_Color LDL_PaletteGet(LDL_Palette* palette, size_t index);

    /**
     * @brief Sets a color in the palette at the specified index.
     *
     * This function stores a color at the given index in the palette. The color
     * is specified as an LDL_Color structure containing the RGBA values.
     *
     * @param palette A pointer to the LDL_Palette instance.
     * @param index   The index where the color should be stored (0 to LDL_PaletteMax - 1).
     * @param color   The LDL_Color structure containing the color to store.
     *
     * @note The valid index range is 0 to 255 inclusive.
     * @note If the index is out of range, the function has no effect.
     * @note Setting a color automatically updates the palette entry.
     * @note The color is stored as 8-bit RGBA values.
     *
     * Use cases:
     * - Loading custom color palettes from files
     * - Creating gradient palettes
     * - Implementing color cycling animations
     * - Converting images to indexed color
     *
     * @code
     * // Example: Create a grayscale palette
     * LDL_Palette* palette = LDL_PaletteCreate();
     * for (size_t i = 0; i < 256; i++) {
     *     uint8_t value = (uint8_t)i;
     *     LDL_Color color = LDL_ColorRgb(value, value, value);
     *     LDL_PaletteSet(palette, i, color);
     * }
     *
     * // Example: Set a specific color
     * LDL_PaletteSet(palette, 128, LDL_ColorRgb(255, 128, 64));
     * @endcode
     *
     * @see LDL_PaletteGet
     * @see LDL_Color
     * @see LDL_ColorRgb
     * @see LDL_ColorRgba
     * @see LDL_PaletteMax
     */
    LDL_LIBRARY void LDL_PaletteSet(LDL_Palette* palette, size_t index, LDL_Color color);

#ifdef __cplusplus
}
#endif

#endif // LDL_Palette_H
