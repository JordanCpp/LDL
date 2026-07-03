/**
 * @file LDL_Ttf.h
 * @brief Defines TrueType font loading and text rasterization functionality.
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

#ifndef LDL_Ttf_H
#define LDL_Ttf_H

#include <LDL/Vec2i.h>
#include <LDL/Result.h>
#include <LDL/Color.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_Font
     * @brief Opaque structure representing a loaded TrueType font.
     *
     * This structure encapsulates a loaded TrueType font file and its associated
     * rendering data. The font is loaded from a .ttf file and prepared for
     * text rendering at a specific size.
     *
     * Key features:
     * - TrueType font loading from file
     * - Configurable font size (in points)
     * - UTF-8 text support
     * - Memory-efficient font data storage
     *
     * @note The font data is loaded into memory and cached for rendering.
     * @see LDL_FontLoad
     * @see LDL_FontDestroy
     * @see LDL_RasterizerText
     */
    typedef struct LDL_Font LDL_Font;

    /**
     * @struct LDL_Rasterizer
     * @brief Opaque structure representing a text rasterizer instance.
     *
     * This structure encapsulates the state and resources required for
     * rendering text from a TrueType font. It generates pixel data for
     * text strings that can be used as textures or surfaces.
     *
     * Key features:
     * - Text rendering to pixel buffer
     * - UTF-8 string support
     * - Configurable text color
     * - Pixel format management
     * - Size retrieval of rendered text
     *
     * @note The rasterizer converts text to a pixel buffer that can be
     *       used for rendering or texture creation.
     * @see LDL_RasterizerCreate
     * @see LDL_RasterizerDestroy
     * @see LDL_RasterizerText
     */
    typedef struct LDL_Rasterizer LDL_Rasterizer;

    /**
     * @brief Loads a TrueType font from a file.
     *
     * This function loads a TrueType font (.ttf) from the specified file path
     * and prepares it for rendering at the specified size. The font is loaded
     * into memory and can be used for text rasterization.
     *
     * @param result Pointer to an LDL_Result variable that will receive the operation status.
     *               If the operation succeeds, the result will be set to success state.
     *               If an error occurs, the result will contain an appropriate error message.
     * @param path   Path to the TrueType font file (.ttf). The path can be absolute or relative.
     * @param size   The desired font size in points. This determines the height of the rendered text.
     * @return A pointer to the newly created LDL_Font instance if the
     *         operation was successful; otherwise, a NULL pointer is returned.
     *
     * @note The returned font must be freed using LDL_FontDestroy when no longer needed.
     * @note The font file must be a valid TrueType font.
     * @note The size parameter is in points (1/72 inch), typical values range from 12 to 72.
     * @note Font loading may fail if the file does not exist or is not a valid TTF.
     *
     * @code
     * // Example: Load a font
     * LDL_Result* result = LDL_ResultCreate();
     * LDL_Font* font = LDL_FontLoad(result, "arial.ttf", 24);
     * if (font == NULL) {
     *     printf("Failed to load font: %s\n", LDL_ResultGetMessage(result));
     * }
     * @endcode
     *
     * @see LDL_FontDestroy
     * @see LDL_RasterizerText
     */
    LDL_LIBRARY LDL_Font* LDL_FontLoad(LDL_Result* result, const char* path, int size);

    /**
     * @brief Destroys a font instance and releases all associated resources.
     *
     * This function performs the necessary cleanup for the specified font,
     * including the deallocation of font data and rendering information.
     * After this call, the pointer to the font becomes invalid.
     *
     * @param font A pointer to the LDL_Font instance that is intended to be destroyed.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @note All font data is freed when the font is destroyed.
     * @see LDL_FontLoad
     */
    LDL_LIBRARY void LDL_FontDestroy(LDL_Font* font);

    /**
     * @brief Creates a new text rasterizer instance.
     *
     * This function allocates memory for a new rasterizer object that can
     * render text from loaded fonts. The rasterizer manages the rendering
     * of text strings to pixel buffers.
     *
     * @param result Pointer to an LDL_Result variable that will receive the operation status.
     *               If the operation succeeds, the result will be set to success state.
     *               If an error occurs, the result will contain an appropriate error message.
     * @return A pointer to the newly created LDL_Rasterizer instance if the
     *         operation was successful; otherwise, a NULL pointer is returned.
     *
     * @note The returned rasterizer must be freed using LDL_RasterizerDestroy
     *       when no longer needed to avoid memory leaks.
     * @see LDL_RasterizerDestroy
     * @see LDL_RasterizerText
     */
    LDL_LIBRARY LDL_Rasterizer* LDL_RasterizerCreate(LDL_Result* result);

    /**
     * @brief Destroys a rasterizer instance and releases all associated resources.
     *
     * This function performs the necessary cleanup for the specified rasterizer,
     * including the deallocation of any internal buffers or rendering resources.
     * After this call, the pointer to the rasterizer becomes invalid.
     *
     * @param rasterizer A pointer to the LDL_Rasterizer instance that is intended to be destroyed.
     *
     * @note It is safe to pass NULL to this function; it will simply do nothing.
     * @see LDL_RasterizerCreate
     */
    LDL_LIBRARY void LDL_RasterizerDestroy(LDL_Rasterizer* rasterizer);

    /**
     * @brief Renders text to the rasterizer's pixel buffer.
     *
     * This function renders the specified UTF-8 encoded text using the loaded
     * font and color. The rendered text is stored in the rasterizer's internal
     * pixel buffer and can be retrieved using LDL_RasterizerGetPixels.
     *
     * @param rasterizer A pointer to the LDL_Rasterizer instance.
     * @param font       A pointer to the LDL_Font to use for rendering.
     * @param color      The LDL_Color to use for text rendering (supports alpha).
     * @param utf8_text  A null-terminated UTF-8 encoded string to render.
     *
     * @note The text is rendered with the specified color and font.
     * @note The rasterizer's internal buffer is resized to fit the text.
     * @note Supports UTF-8 encoding for international characters.
     * @note The rendered text includes alpha transparency for smooth edges.
     * @note After rendering, use LDL_RasterizerGetSize and LDL_RasterizerGetPixels
     *       to retrieve the result.
     *
     * @code
     * // Example: Render text
     * LDL_Rasterizer* rasterizer = LDL_RasterizerCreate(result);
     * LDL_Color color = LDL_ColorRgb(255, 255, 255);
     * LDL_RasterizerText(rasterizer, font, color, "Hello, World!");
     *
     * LDL_Vec2i size = LDL_RasterizerGetSize(rasterizer);
     * uint8_t* pixels = LDL_RasterizerGetPixels(rasterizer);
     * // Use pixels as a texture or surface...
     * @endcode
     *
     * @see LDL_RasterizerGetSize
     * @see LDL_RasterizerGetPixels
     * @see LDL_RasterizerGetPixelFormat
     * @see LDL_FontLoad
     * @see LDL_Color
     */
    LDL_LIBRARY void LDL_RasterizerText(LDL_Rasterizer* rasterizer, LDL_Font* font, LDL_Color color, const char* utf8_text);

    /**
     * @brief Retrieves the dimensions of the rendered text.
     *
     * This function returns the width and height of the last rendered text
     * in pixels. The size represents the actual rendered dimensions, which
     * may include padding for anti-aliasing.
     *
     * @param rasterizer A pointer to the LDL_Rasterizer instance.
     * @return An LDL_Vec2i structure containing the width and height of the
     *         rendered text in pixels. If no text has been rendered, returns
     *         a vector with both components set to 0.
     *
     * @note The size is updated after each call to LDL_RasterizerText.
     * @note The size includes any anti-aliasing padding.
     * @see LDL_RasterizerText
     * @see LDL_RasterizerGetPixels
     */
    LDL_LIBRARY LDL_Vec2i LDL_RasterizerGetSize(LDL_Rasterizer* rasterizer);

    /**
     * @brief Retrieves a pointer to the rendered text pixel data.
     *
     * This function returns a pointer to the pixel buffer containing the
     * rendered text. The pixel format can be determined using
     * LDL_RasterizerGetPixelFormat.
     *
     * @param rasterizer A pointer to the LDL_Rasterizer instance.
     * @return A pointer to uint8_t buffer containing the text pixel data.
     *         Returns NULL if no text has been rendered or if an error occurs.
     *
     * @note The pixel data is owned by the rasterizer and should not be freed.
     * @note The data remains valid until the next call to LDL_RasterizerText
     *       or the rasterizer is destroyed.
     * @note The buffer size can be calculated as:
     *       width * height * bytes_per_pixel
     * @see LDL_RasterizerText
     * @see LDL_RasterizerGetSize
     * @see LDL_RasterizerGetPixelFormat
     */
    LDL_LIBRARY uint8_t* LDL_RasterizerGetPixels(LDL_Rasterizer* rasterizer);

    /**
     * @brief Retrieves the pixel format of the rendered text.
     *
     * This function returns the pixel format identifier for the rendered text
     * pixel data. The format describes the memory layout and channel arrangement
     * of the pixel buffer.
     *
     * @param rasterizer A pointer to the LDL_Rasterizer instance.
     * @return The pixel format identifier (from LDL_PixelFormat enumeration).
     *         Returns LDL_PixelFormatUnknown if no text has been rendered.
     *
     * @note The pixel format is typically RGBA32 for text rendering.
     * @see LDL_RasterizerGetPixels
     * @see LDL_PixelFormat
     */
    LDL_LIBRARY uint8_t LDL_RasterizerGetPixelFormat(LDL_Rasterizer* rasterizer);

#ifdef __cplusplus
}
#endif

#endif // LDL_Ttf_H
