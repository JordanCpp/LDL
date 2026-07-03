/**
* @file LDL.h
* @brief Master include file for the LDL (Lightweight Development Library).
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

#ifndef LDL_H
#define LDL_H

/**
* @defgroup LDL_Core Core Library Components
* @brief Fundamental components required for any LDL application.
* @{
*/

/**
* @defgroup LDL_Context Rendering Context Management
* @brief Functions for creating and managing rendering contexts.
* @see LDL_Context.h
*/

/**
* @defgroup LDL_Result Error Handling
* @brief Error reporting and result management utilities.
* @see LDL_Result.h
*/

/**
* @defgroup LDL_Surface Surface Management
* @brief 2D pixel surface creation and manipulation.
* @see LDL_Surface.h
*/

/**
* @defgroup LDL_Window Window Management
* @brief Window creation, event handling, and presentation.
* @see LDL_Window.h
*/

/** @}*/ // End of LDL_Core

/**
* @defgroup LDL_Rendering Rendering Systems
* @brief 2D and 3D rendering subsystems.
* @{
*/

/**
* @defgroup LDL_2DRender 2D Rendering
* @brief 2D rendering primitives, textures, and layers.
* @see LDL_2DRender.h
*/

/**
* @defgroup LDL_3DRender 3D Rendering
* @brief 3D rendering with vertex buffers, matrices, and textures.
* @see LDL_3DRender.h
*/

/**
* @defgroup LDL_Texture Texture Management
* @brief GPU texture creation and management.
* @see LDL_Texture.h
*/

/** @}*/ // End of LDL_Rendering

/**
* @defgroup LDL_Input Input and Timing
* @brief Input handling, timing, and frame rate control.
* @{
*/

/**
* @defgroup LDL_Ticks Timing Utilities
* @brief System tick counters and delay functions.
* @see LDL_Ticks.h
*/

/**
* @defgroup LDL_FpsLimit Frame Rate Limiting
* @brief Frame rate regulation and throttling.
* @see LDL_FpsLimit.h
*/

/**
* @defgroup LDL_FpsCount Frame Rate Counting
* @brief FPS measurement and performance monitoring.
* @see LDL_FpsCount.h
*/

/**
* @defgroup LDL_Mouse Mouse Control
* @brief Mouse cursor manipulation and position tracking.
* @see LDL_Mouse.h
*/

/** @}*/ // End of LDL_Input

/**
* @defgroup LDL_IO File and Library Loading
* @brief File I/O, image loading, and dynamic library management.
* @{
*/

/**
* @defgroup LDL_BmpLoad BMP Image Loading
* @brief BMP file loading and pixel extraction.
* @see LDL_BmpLoad.h
*/

/**
* @defgroup LDL_Image Generic Image Loading
* @brief Image loader for multiple formats.
* @see LDL_Image.h
*/

/**
* @defgroup LDL_Library Dynamic Library Loading
* @brief Runtime library loading and function retrieval.
* @see LDL_Library.h
*/

/**
* @defgroup LDL_Ttf TrueType Font Support
* @brief TrueType font rendering and text handling.
* @see LDL_Ttf.h
*/

/** @}*/ // End of LDL_IO

/**
* @defgroup LDL_Miscellaneous Miscellaneous Utilities
* @brief Additional utility functions and helpers.
* @{
*/

/**
* @defgroup LDL_Color Color Utilities
* @brief RGBA color structures and creation functions.
* @see LDL_Color.h
*/

/**
* @defgroup LDL_Enums Enumerations
* @brief Event types, key codes, and window modes.
* @see LDL_Enums.h
*/

/**
* @defgroup LDL_Events Event System
* @brief Event structures and event handling functions.
* @see LDL_Events.h
*/

/**
* @defgroup LDL_Format String Formatting
* @brief printf-style string formatting utilities.
* @see LDL_Format.h
*/

/**
* @defgroup LDL_Palette Color Palette Management
* @brief Indexed color palette creation and manipulation.
* @see LDL_Palette.h
*/

/**
* @defgroup LDL_Vec2i 2D Vector Math
* @brief 2D integer vector operations.
* @see LDL_Vec2i.h
*/

/**
* @defgroup LDL_PixFrmt Pixel Formats
* @brief Pixel format definitions and byte calculation utilities.
* @see LDL_PixFrmt.h
*/

/** @}*/ // End of LDL_Miscellaneous

#include <LDL/Context.h>
#include <LDL/Result.h>
#include <LDL/Surface.h>
#include <LDL/2DRender.h>
#include <LDL/Library.h>
#include <LDL/Format.h>
#include <LDL/Ticks.h>
#include <LDL/BmpLoad.h>
#include <LDL/Texture.h>
#include <LDL/FpsLimit.h>
#include <LDL/FpsCount.h>
#include <LDL/3DRender.h>
#include <LDL/Image.h>
#include <LDL/Ttf.h>

#endif // LDL_H
