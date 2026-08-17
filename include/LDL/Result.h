/**
 * @file LDL_Result.h
 * @brief Defines error handling and result reporting mechanisms.
 * @author Evgeny Zoshchuk (JordanCpp), AslanD (Ztry8)
 * @copyright Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp), Copyright(C) 2026 AslanD (Ztry8).
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

#ifndef LDL_Result_H
#define LDL_Result_H

#include <LDL/Config.h>
#include <LDL/Types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @struct LDL_Result
* @brief Opaque structure representing a result object for error handling.
*
* This structure encapsulates error state and diagnostic information for
* operations performed by the library. It provides a mechanism to track
* whether operations succeeded or failed, along with descriptive error
* messages that can be used for debugging and user feedback.
*
* The result object maintains:
* - A success/failure state
* - A formatted message string describing the outcome
* - The ability to accumulate multiple messages
*
* @note The result object is designed to be created once and reused
*       across multiple operations to minimize memory allocation overhead.
* @see LDL_ResultCreate
* @see LDL_ResultDestroy
*/
typedef struct LDL_Result LDL_Result;

/**
* @brief Creates a new result object.
*
* This function allocates and initializes a new LDL_Result object in a
* default state (success with no messages). The object can be used to
* track the success or failure of operations throughout the library.
*
* @return A pointer to the newly created LDL_Result instance, or NULL on allocation failure.
*
* @note The returned result object must be freed using LDL_ResultDestroy
*       when it is no longer needed to avoid memory leaks.
* @note Initially, the result object is in a success state with no messages.
* @see LDL_ResultDestroy
* @see LDL_ResultReset
*/
LDL_LIBRARY LDL_Result* LDL_ResultCreate();

/**
* @brief Destroys a result object and frees all associated resources.
*
* This function releases all memory and resources associated with the
* specified result object, including any stored messages.
*
* @param result Pointer to the result object to destroy.
*
* @note It is safe to pass NULL to this function; it will simply do nothing.
* @note After destruction, any pointers to the result object become invalid.
* @see LDL_ResultCreate
*/
LDL_LIBRARY void LDL_ResultDestroy(LDL_Result* result);

/**
* @brief Checks whether the result indicates success.
*
* This function returns true if the result object is in a success state,
* indicating that the last operation performed completed successfully
* without errors.
*
* @param result Pointer to the result object to check.
* @return true if the result indicates success, false otherwise.
*
* @note A newly created result object starts in a success state.
* @note The result state can be modified by various operations that
*       set failure states and messages.
* @see LDL_ResultIsFail
* @see LDL_ResultAddMessage
* @see LDL_ResultReset
*/
LDL_LIBRARY bool LDL_ResultIsOk(LDL_Result* result);

/**
* @brief Checks whether the result indicates failure.
*
* This function returns true if the result object is in a failure state,
* indicating that the last operation performed encountered an error.
*
* @param result Pointer to the result object to check.
* @return true if the result indicates failure, false otherwise.
*
* @note A newly created result object starts in a success state (not failure).
* @note Failure state is typically set when an operation encounters an error
*       and error messages are added to describe the problem.
* @see LDL_ResultIsOk
* @see LDL_ResultAddMessage
* @see LDL_ResultReset
*/
LDL_LIBRARY bool LDL_ResultIsFail(LDL_Result* result);

/**
* @brief Retrieves the current error message from the result object.
*
* This function returns a pointer to a string containing the accumulated
* error messages from the result object. The message provides diagnostic
* information about why an operation failed.
*
* @param result Pointer to the result object.
* @return A pointer to a constant string containing the error message,
*         or NULL if no message is available.
*
* @note The returned string is owned by the result object and should not
*       be modified or freed by the caller.
* @note The message may contain multiple lines or formatted diagnostic
*       information depending on what was added.
* @note If the result is in a success state, this may return NULL or
*       a generic success message.
* @see LDL_ResultAddMessage
*/
LDL_LIBRARY const char* LDL_ResultGetMessage(LDL_Result* result);

/**
* @brief Adds a formatted error message to the result object.
*
* This function appends a formatted message to the result object's
* internal message buffer. When a message is added, the result state
* is automatically set to a failure state.
*
* @param result Pointer to the result object.
* @param format A printf-style format string followed by additional arguments.
* @param ... Variable arguments to be formatted according to the format string.
*
* @note This function uses variable arguments (variadic) similar to printf.
* @note The message is appended to any existing messages, allowing for
*       accumulation of multiple error diagnostics.
* @note After calling this function, LDL_ResultIsFail will return true.
* @note The format string must be compatible with the standard printf
*       formatting specifiers.
*
* @code
* // Example usage:
* LDL_Result* result = LDL_ResultCreate();
* LDL_ResultAddMessage(result, "Failed to open file: %s", filename);
* LDL_ResultAddMessage(result, "Error code: %d", errno);
* @endcode
*
* @see LDL_ResultGetMessage
* @see LDL_ResultReset
*/
LDL_LIBRARY void LDL_ResultAddMessage(LDL_Result* result, const char* format, ...);

/**
* @brief Resets the result object to its initial state.
*
* This function clears all stored messages and resets the result state
* back to success. This allows the same result object to be reused for
* multiple operations without allocating a new one.
*
* @param result Pointer to the result object to reset.
*
* @note After reset, LDL_ResultIsOk will return true and
*       LDL_ResultGetMessage will return NULL or an empty string.
* @note This function is useful for reusing a result object across
*       multiple operations in a loop or sequential processing.
* @note Any previously stored messages are freed and no longer accessible.
*
* @code
* // Example: Reuse result object
* LDL_Result* result = LDL_ResultCreate();
* for (int i = 0; i < 10; i++) {
*     LDL_ResultReset(result);
*     // Perform operation with result tracking...
*     if (LDL_ResultIsFail(result)) {
*         printf("Operation %d failed: %s\n", i, LDL_ResultGetMessage(result));
*     }
* }
* @endcode
*
* @see LDL_ResultCreate
* @see LDL_ResultAddMessage
*/
LDL_LIBRARY void LDL_ResultReset(LDL_Result* result);

#ifdef __cplusplus
}
#endif

#endif
