/**
 * @file LDL_Format.h
 * @brief Header file containing the interface for the LDL string formatting utility.
 *
 * This file provides a robust mechanism for creating, managing, and utilizing
 * a formatter object to construct formatted strings using printf-style syntax.
 *
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)
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
	 * The internal implementation details of the LDL_Formatter are encapsulated
	 * to prevent direct manipulation. All interactions with this object must
	 * be performed through the provided API functions.
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
	 */
	LDL_LIBRARY void LDL_FormatterClear(LDL_Formatter* formatter);

	/**
	 * @brief Creates and initializes a new instance of an LDL_Formatter.
	 *
	 * This function allocates the necessary memory and sets up the internal
	 * state required for a new string formatting object.
	 *
	 * @return A pointer to the newly created LDL_CA_Formatter instance if the
	 *         allocation was successful; otherwise, a NULL pointer is returned.
	 */
	LDL_LIBRARY LDL_Formatter* LDL_FormatterCreate();

	/**
	 * @brief Destroys an existing LDL_Formatter and releases all associated resources.
	 *
	 * This function deallocates the memory used by the formatter object and
	 * cleans up any internal buffers. After this call, the pointer to the
	 * formatter becomes invalid and should not be used.
	 *
	 * @param formatter A pointer to the LDL_Format instance that is intended to be destroyed.
	 */
	LDL_LIBRARY void LDL_FormatterDestroy(LDL_Formatter* formatter);

	/**
	 * @brief Retrieves the character data currently stored within the formatter.
	 *
	 * This function provides access to the internal buffer containing the
	 * accumulated formatted string.
	 *
	 * @param formatter A pointer to the LDL_Formatter instance from which
	 *                  the data is being retrieved.
	 * @return A pointer to a null-terminated character array containing the
	 *         formatted string stored in the formatter.
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
	 */
	LDL_LIBRARY const char* LDL_FormatterFormat(LDL_Formatter* formatter, const char* format, ...);

#ifdef __cplusplus
}
#endif 

#endif
