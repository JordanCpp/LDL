/**
 * @file LDL_Library.h
 * @brief Defines dynamic library loading and function management.
 *
 * This file provides an interface for loading dynamic libraries (shared objects
 * on Unix-like systems, DLLs on Windows) and retrieving function pointers from them.
 * It enables runtime linking and plugin functionality, allowing applications to
 * load libraries dynamically at runtime.
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

#ifndef LDL_Library_H
#define LDL_Library_H

#include <LDL/Result.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_Library
* @brief Opaque structure representing a dynamically loaded library.
*
* This structure encapsulates the handle and state of a loaded dynamic
* library. It is used as a handle for all library-related operations.
* The internal implementation details are hidden from the user to provide
* a platform-independent interface for dynamic library loading.
*/
typedef struct LDL_Library LDL_Library;

/**
* @brief Creates a new library manager instance.
*
* This function allocates and initializes a new LDL_Library object.
* The instance can be used to open dynamic libraries and retrieve
* function pointers from them.
*
* @param result Pointer to an LDL_Result variable that will receive the operation status.
*               If the operation succeeds, the result will be set to LDL_RESULT_SUCCESS.
*               If an error occurs, the result will contain an appropriate error code.
* @return A pointer to the newly created LDL_Library instance, or NULL on failure.
*
* @note The returned library manager must be freed using LDL_LibraryDestroy
*       when it is no longer needed to avoid memory leaks.
* @see LDL_LibraryDestroy
* @see LDL_LibraryOpen
*/
LDL_LIBRARY LDL_Library* LDL_LibraryCreate(LDL_Result* result);

/**
* @brief Destroys a library manager instance and frees all associated resources.
*
* This function releases all memory and resources associated with the
* specified library manager. If a library is currently open, it will be
* automatically closed before destruction.
*
* @param library Pointer to the library manager instance to destroy.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @see LDL_LibraryCreate
* @see LDL_LibraryClose
*/
LDL_LIBRARY void LDL_LibraryDestroy(LDL_Library* library);

/**
* @brief Opens a dynamic library from the specified file path.
*
* This function loads a dynamic library from the given file path and
* makes its symbols available for function retrieval. The library remains
* loaded until explicitly closed or the library manager is destroyed.
*
* @param library Pointer to the library manager instance.
* @param path Path to the dynamic library file to open.
*             - On Windows: Typically a .dll file
*             - On Linux/Unix: Typically a .so file
*             - On macOS: Typically a .dylib or .bundle file
* @return true if the library was successfully opened, false otherwise.
*
* @note If a library is already open, it will be automatically closed
*       before opening the new one.
* @note The path can be absolute or relative. On some platforms, the
*       system library search path may also be used.
* @note Use LDL_LibraryGetFunction to retrieve function pointers from
*       the opened library.
* @see LDL_LibraryGetFunction
* @see LDL_LibraryClose
*/
LDL_LIBRARY bool LDL_LibraryOpen(LDL_Library* library, const char* path);

/**
* @brief Closes an open dynamic library.
*
* This function unloads the currently opened dynamic library and releases
* all associated resources. After closing, function pointers obtained from
* this library become invalid and should not be used.
*
* @param library Pointer to the library manager instance.
*
* @note This function has no effect if no library is currently open.
* @note It is safe to call this function multiple times; subsequent calls
*       will have no effect.
* @see LDL_LibraryOpen
*/
LDL_LIBRARY void LDL_LibraryClose(LDL_Library* library);

/**
* @brief Retrieves a function pointer from the loaded library.
*
* This function looks up a function symbol by name in the currently
* loaded dynamic library and returns a pointer to it. The returned
* pointer can be cast to the appropriate function type for calling.
*
* @param library Pointer to the library manager instance.
* @param name The name of the function to retrieve.
* @return A function pointer to the requested symbol, or NULL if the
*         symbol cannot be found or no library is currently open.
*
* @note The returned pointer should be cast to the appropriate function
*       signature before being called.
* @note Function name matching may be case-sensitive depending on the
*       platform and compiler used to build the library.
* @note This function may return NULL if the symbol is not exported
*       or if name mangling is used.
* @warning Function pointers become invalid after the library is closed
*          or destroyed.
* @see LDL_LibraryOpen
* @see LDL_LibraryClose
*/
LDL_LIBRARY LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library, const char* name);

#ifdef __cplusplus
}
#endif

#endif // LDL_Library_H
