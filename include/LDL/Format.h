/**
 * @file LDL_Format.h
 * @brief Defines a string formatting utility for printf-style string construction.
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

#ifndef LDL_Format_H
#define LDL_Format_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_Formatter
* @brief An opaque structure representing a string formatter instance.
*
* This structure encapsulates a dynamic string buffer and state for
* printf-style string formatting. It provides efficient string construction
* by accumulating formatted output in an internal buffer.
*
* Key features:
* - Dynamic buffer management
* - printf-style format specifiers
* - Support for variable arguments (va_list)
* - Reusable formatter instance
* - Automatic memory management
*
* @note The internal implementation details are encapsulated to prevent
*       direct manipulation. All interactions with this object must
*       be performed through the provided API functions.
* @see LDL_FormatterCreate
* @see LDL_FormatterDestroy
* @see LDL_FormatterFormat
*/
typedef struct LDL_Formatter LDL_Formatter;

/**
* @brief Clears the content of the specified formatter instance.
*
* This function resets the internal buffer of the provided formatter,
* effectively removing all previously formatted data and returning
* the state to an empty string.
*
* @param formatter A pointer to the LDL_Formatter instance that is to be cleared.
*
* @note After clearing, LDL_FormatterGetData will return an empty string.
* @note This function is useful for reusing a formatter instance for
*       multiple formatting operations.
* @see LDL_FormatterCreate
* @see LDL_FormatterGetData
*/
LDL_LIBRARY void LDL_FormatterClear(LDL_Formatter* formatter);

/**
* @brief Creates and initializes a new instance of an LDL_Formatter.
*
* This function allocates the necessary memory and sets up the internal
* state required for a new string formatting object. The formatter is
* initialized with an empty buffer.
*
* @return A pointer to the newly created LDL_Formatter instance if the
*         allocation was successful; otherwise, a NULL pointer is returned.
*
* @note The returned formatter must be freed using LDL_FormatterDestroy
*       when it is no longer needed to avoid memory leaks.
* @note The formatter initially contains an empty string.
* @see LDL_FormatterDestroy
* @see LDL_FormatterClear
* @see LDL_FormatterFormat
*/
LDL_LIBRARY LDL_Formatter* LDL_FormatterCreate();

/**
* @brief Destroys an existing LDL_Formatter and releases all associated resources.
*
* This function deallocates the memory used by the formatter object and
* cleans up any internal buffers. After this call, the pointer to the
* formatter becomes invalid and should not be used.
*
* @param formatter A pointer to the LDL_Formatter instance that is intended to be destroyed.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note All formatted data is lost when the formatter is destroyed.
* @see LDL_FormatterCreate
*/
LDL_LIBRARY void LDL_FormatterDestroy(LDL_Formatter* formatter);

/**
* @brief Retrieves the character data currently stored within the formatter.
*
* This function provides access to the internal buffer containing the
* accumulated formatted string. The returned string is null-terminated
* and can be used directly in string operations.
*
* @param formatter A pointer to the LDL_Formatter instance from which
*                  the data is being retrieved.
* @return A pointer to a null-terminated character array containing the
*         formatted string stored in the formatter. Returns an empty
*         string if the formatter is empty or NULL.
*
* @note The returned pointer is owned by the formatter and should not
*       be freed or modified by the caller.
* @note The string remains valid until the formatter is cleared or destroyed.
* @see LDL_FormatterClear
* @see LDL_FormatterFormat
*/
LDL_LIBRARY char* LDL_FormatterGetData(LDL_Formatter* formatter);

/**
* @brief Formats a string using a variable argument list.
*
* This function processes a format string and substitutes placeholders with
* values provided through a `va_list`. The resulting formatted string is
* stored within the specified formatter instance.
*
* @param formatter A pointer to the LDL_Formatter instance where the
*                  formatted result will be stored.
* @param format    A null-terminated string containing the format specification
*                  (using standard printf-style syntax).
* @param args      A variable argument list containing the values to be
*                  inserted into the format string.
* @return A pointer to the internal character buffer of the formatter
*         containing the newly formatted string.
*
* @note This function is useful when you already have a va_list from
*       a variadic function and want to perform formatting.
* @note The format string supports standard printf format specifiers:
*       - %d, %i: signed integer
*       - %u: unsigned integer
*       - %f: floating point
*       - %s: string
*       - %c: character
*       - %x, %X: hexadecimal
*       - %p: pointer
* @note The formatter's previous content is replaced by the new format.
* @see LDL_FormatterFormat
* @see LDL_FormatterGetData
*/
LDL_LIBRARY const char* LDL_FormatterVFormat(LDL_Formatter* formatter, const char* format, va_list args);

/**
* @brief Formats a string using a variable number of arguments.
*
* This function processes a format string and substitutes placeholders with
* values passed directly as arguments to the function via an ellipsis (...).
* The resulting formatted string is stored within the specified formatter instance.
*
* @param formatter A pointer to the LDL_Formatter instance where the
*                  formatted result will be stored.
* @param format    A null-terminated string containing the format specification
*                  (using standard printf-style syntax).
* @param ...       A variable number of arguments that are to be formatted
*                  into the string according to the format specification.
* @return A pointer to the internal character buffer of the formatter
*         containing the newly formatted string.
*
* @note This is the primary formatting function for most use cases.
* @note The format string supports standard printf format specifiers:
*       - %d, %i: signed integer
*       - %u: unsigned integer
*       - %f: floating point
*       - %s: string
*       - %c: character
*       - %x, %X: hexadecimal
*       - %p: pointer
* @note The formatter's previous content is replaced by the new format.
* @note This function is a wrapper around LDL_FormatterVFormat.
*
* @code
* // Example usage:
* LDL_Formatter* formatter = LDL_FormatterCreate();
* const char* result = LDL_FormatterFormat(formatter, "Hello, %s! Number: %d", "World", 42);
* printf("%s\n", result); // Outputs: "Hello, World! Number: 42"
* LDL_FormatterDestroy(formatter);
* @endcode
*
* @see LDL_FormatterVFormat
* @see LDL_FormatterGetData
*/
LDL_LIBRARY const char* LDL_FormatterFormat(LDL_Formatter* formatter, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif // LDL_Format_H
