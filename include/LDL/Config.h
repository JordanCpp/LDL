/**
* @file LDL_Config.h
* @brief Defines platform-specific configuration and library export/import macros.
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

#ifndef LDL_Config_H
#define LDL_Config_H

/**
* @def LDL_EXPORT
* @brief Macro for exporting symbols from a shared library.
*
* This macro expands to platform-specific directives for exporting
* functions and variables from a shared library (DLL on Windows,
* shared object on Unix-like systems).
*
* @note On Windows: expands to __declspec(dllexport)
* @note On Unix-like: expands to __attribute__((visibility("default")))
* @note On unsupported platforms: expands to nothing
*
* @see LDL_IMPORT
* @see LDL_LIBRARY
*/

/**
* @def LDL_IMPORT
* @brief Macro for importing symbols from a shared library.
*
* This macro expands to platform-specific directives for importing
* functions and variables from a shared library (DLL on Windows).
*
* @note On Windows: expands to __declspec(dllimport)
* @note On Unix-like: expands to nothing (not needed for ELF)
* @note On unsupported platforms: expands to nothing
*
* @see LDL_EXPORT
* @see LDL_LIBRARY
*/

#if defined(_WIN32)
#define LDL_EXPORT __declspec(dllexport)
#define LDL_IMPORT __declspec(dllimport)
#elif defined(__unix__)
#define LDL_EXPORT __attribute__((visibility("default")))
#define LDL_IMPORT
#else
#define LDL_EXPORT
#define LDL_IMPORT
#endif

/**
* @def LDL_LIBRARY
* @brief Main library export/import macro for LDL library symbols.
*
* This macro determines whether symbols should be exported or imported
* based on the library build configuration (static vs shared) and
* platform-specific requirements.
*
* Behavior:
* - If LDL_STATIC_LIBRARY is defined: expands to nothing (static linking)
* - Else if LDL_SHARED_LIBRARY is defined: expands to LDL_EXPORT
* - Else: expands to LDL_IMPORT (default for client applications)
*
* @note This macro should be used for all public API functions and variables.
* @note In static library builds, this macro evaluates to nothing.
* @note In shared library builds, this macro controls symbol visibility.
*
* @code
* // Example usage:
* LDL_LIBRARY LDL_Color LDL_ColorRgb(uint8_t r, uint8_t g, uint8_t b);
* @endcode
*
* @see LDL_EXPORT
* @see LDL_IMPORT
* @see LDL_STATIC_LIBRARY
* @see LDL_SHARED_LIBRARY
*/

#if defined(LDL_STATIC_LIBRARY)
#define LDL_LIBRARY
#else
#if defined(LDL_SHARED_LIBRARY)
#define LDL_LIBRARY LDL_EXPORT
#else
#define LDL_LIBRARY LDL_IMPORT
#endif
#endif

/**
* @def LDL_API_CALL
* @brief Defines the calling convention for LDL API functions.
*
* This macro specifies the calling convention used for LDL library
* functions. On Windows, it uses __cdecl (standard C calling convention).
* On other platforms, it expands to nothing.
*
* @note On Windows: expands to __cdecl
* @note On Unix-like: expands to nothing
* @note This ensures proper stack cleanup and calling convention
*       compatibility across platforms.
*
* @see LDL_GL_CALL
*/

/**
* @def LDL_GL_CALL
* @brief Defines the calling convention for OpenGL functions.
*
* This macro specifies the calling convention used for OpenGL functions.
* On Windows, it uses __stdcall (standard for Win32 API and OpenGL).
* On other platforms, it expands to nothing.
*
* @note On Windows: expands to __stdcall
* @note On Unix-like: expands to nothing
* @note This ensures compatibility with OpenGL function pointers.
*
* @see LDL_API_CALL
*/

#if defined(_WIN32)
#define LDL_API_CALL __cdecl
#define LDL_GL_CALL  __stdcall
#else
#define LDL_API_CALL
#define LDL_GL_CALL
#endif

/**
* @def LDL_API_ENTRY
* @brief Combines library export with extern linkage specification.
*
* This macro combines the LDL_LIBRARY export/import macro with the
* extern specifier to ensure proper C linkage for all API functions.
*
* @note Expands to: LDL_LIBRARY extern
* @note This is typically used for global function declarations.
* @note This macro ensures functions are not optimized away by the linker.
*
* @code
* // Example usage:
* LDL_API_ENTRY void LDL_FunctionName();
* @endcode
*
* @see LDL_LIBRARY
*/

#define LDL_API_ENTRY LDL_LIBRARY extern

#endif
