/**
 * @file LDL_Mat4f.h
 * @brief Defines 4x4 matrix mathematics for 3D transformations.
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

#ifndef LDL_Mat4f_H
#define LDL_Mat4f_H

#include <LDL/Types.h>
#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * @struct LDL_Mat4f
     * @brief A 4x4 matrix structure for 3D transformations.
     *
     * This structure represents a 4x4 matrix stored as an array of 16 floating-point
     * values in column-major order. Column-major layout is used for compatibility
     * with OpenGL and other graphics APIs.
     *
     * Memory layout:
     * Values[0..15] represents:
     * [ m00, m10, m20, m30 ]   (column 0)
     * [ m01, m11, m21, m31 ]   (column 1)
     * [ m02, m12, m22, m32 ]   (column 2)
     * [ m03, m13, m23, m33 ]   (column 3)
     *
     * Common matrix types supported:
     * - Identity matrix
     * - Translation matrices
     * - Rotation matrices (X, Y, Z axes)
     * - Scaling matrices
     * - Orthographic projection
     * - Perspective projection
     * - Look-at view matrices
     * - Matrix multiplication
     *
     * @note All matrix operations modify the matrix in-place unless otherwise specified.
     * @see LDL_Mat4fIdentity
     * @see LDL_Mat4fTranslate
     * @see LDL_Mat4fRotate
     * @see LDL_Mat4fMultiply
     */
    typedef struct LDL_Mat4f
    {
        float Values[16]; /**< 16 floating-point values in column-major order. */
    } LDL_Mat4f;

    /**
     * @brief Retrieves a pointer to the matrix's internal value array.
     *
     * This function returns a pointer to the internal floating-point array
     * of the matrix. The pointer can be used for direct manipulation or
     * for passing to graphics APIs.
     *
     * @param mat A pointer to the LDL_Mat4f structure.
     * @return A pointer to the 16-element float array containing the matrix values.
     *
     * @note The pointer is valid as long as the matrix exists.
     * @note The data is stored in column-major order.
     * @see LDL_Mat4f
     */
    LDL_LIBRARY float* LDL_Mat4fGetValues(LDL_Mat4f* mat);

    /**
     * @brief Initializes a matrix to the identity matrix.
     *
     * This function sets the matrix to the identity matrix:
     * [ 1, 0, 0, 0 ]
     * [ 0, 1, 0, 0 ]
     * [ 0, 0, 1, 0 ]
     * [ 0, 0, 0, 1 ]
     *
     * @param mat A pointer to the LDL_Mat4f structure to initialize.
     *
     * @note The identity matrix is the multiplicative identity for matrices.
     * @note This is the starting point for most transformation operations.
     * @see LDL_Mat4fTranslate
     * @see LDL_Mat4fRotate
     */
    LDL_LIBRARY void LDL_Mat4fIdentity(LDL_Mat4f* mat);

    /**
     * @brief Creates an orthographic projection matrix.
     *
     * This function creates an orthographic (parallel) projection matrix.
     * In orthographic projection, objects maintain their size regardless of
     * distance from the viewer.
     *
     * @param mat    A pointer to the LDL_Mat4f structure to store the result.
     * @param left   Left clipping plane coordinate.
     * @param right  Right clipping plane coordinate.
     * @param bottom Bottom clipping plane coordinate.
     * @param top    Top clipping plane coordinate.
     * @param farv   Far clipping plane distance.
     * @param nearv  Near clipping plane distance.
     *
     * @note The matrix overwrites any previous content in the matrix.
     * @note The resulting matrix maps coordinates from the specified volume
     *       to normalized device coordinates (-1 to 1).
     * @note Common for 2D rendering and UI elements.
     *
     * @code
     * // Example: Create an orthographic projection for a 2D game
     * LDL_Mat4f projection;
     * LDL_Mat4fOrtho(&projection, 0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
     * @endcode
     *
     * @see LDL_Mat4fPerspective
     */
    LDL_LIBRARY void LDL_Mat4fOrtho(LDL_Mat4f* mat, float left, float right, float bottom, float top, float farv, float nearv);

    /**
     * @brief Creates a translation matrix.
     *
     * This function creates a 4x4 translation matrix that moves objects
     * by the specified x, y, and z amounts.
     *
     * @param mat A pointer to the LDL_Mat4f structure to store the result.
     * @param x   Translation amount along the X-axis.
     * @param y   Translation amount along the Y-axis.
     * @param z   Translation amount along the Z-axis.
     *
     * @note The matrix overwrites any previous content in the matrix.
     * @note Translation is applied as: position' = position + (x, y, z).
     * @see LDL_Mat4fRotate
     * @see LDL_Mat4fMultiply
     */
    LDL_LIBRARY void LDL_Mat4fTranslate(LDL_Mat4f* mat, float x, float y, float z);

    /**
     * @brief Multiplies two matrices and stores the result.
     *
     * This function performs matrix multiplication: result = a * b.
     * The matrices are multiplied in column-major order.
     *
     * @param result A pointer to the LDL_Mat4f structure to store the result.
     * @param a      A pointer to the first matrix (left operand).
     * @param b      A pointer to the second matrix (right operand).
     *
     * @note The result can be the same as either a or b (in-place multiplication).
     * @note Matrix multiplication is not commutative: a * b != b * a.
     * @note The order of multiplication matters for transformations:
     *       - Translation * Rotation: Translate then rotate
     *       - Rotation * Translation: Rotate then translate
     *
     * @code
     * // Example: Combine translation and rotation
     * LDL_Mat4f trans, rot, combined;
     * LDL_Mat4fTranslate(&trans, 10.0f, 5.0f, 0.0f);
     * LDL_Mat4fRotate(&rot, 45.0f, 0.0f, 0.0f, 1.0f);
     * LDL_Mat4fMultiply(&combined, &trans, &rot);  // Translate then rotate
     * @endcode
     *
     * @see LDL_Mat4fCross
     */
    LDL_LIBRARY void LDL_Mat4fMultiply(LDL_Mat4f* result, const LDL_Mat4f* a, const LDL_Mat4f* b);

    /**
     * @brief Creates a rotation matrix around an arbitrary axis.
     *
     * This function creates a 4x4 rotation matrix that rotates objects by
     * the specified angle around the given axis.
     *
     * @param mat   A pointer to the LDL_Mat4f structure to store the result.
     * @param angle Rotation angle in degrees.
     * @param x     X component of the rotation axis.
     * @param y     Y component of the rotation axis.
     * @param z     Z component of the rotation axis.
     *
     * @note The axis vector (x, y, z) should be normalized for best results.
     * @note The matrix overwrites any previous content in the matrix.
     * @note Rotation is performed in a right-handed coordinate system.
     *
     * @code
     * // Example: Rotate 45 degrees around the Z-axis
     * LDL_Mat4f rotation;
     * LDL_Mat4fRotate(&rotation, 45.0f, 0.0f, 0.0f, 1.0f);
     *
     * // Example: Rotate 30 degrees around the Y-axis
     * LDL_Mat4fRotate(&rotation, 30.0f, 0.0f, 1.0f, 0.0f);
     * @endcode
     *
     * @see LDL_Mat4fTranslate
     * @see LDL_Mat4fMultiply
     */
    LDL_LIBRARY void LDL_Mat4fRotate(LDL_Mat4f* mat, float angle, float x, float y, float z);

    /**
     * @brief Computes the cross product (matrix multiplication) of two matrices.
     *
     * This function computes result = a * b. It is similar to LDL_Mat4fMultiply
     * but with a different name for clarity.
     *
     * @param result A pointer to the LDL_Mat4f structure to store the result.
     * @param a      A pointer to the first matrix (left operand).
     * @param b      A pointer to the second matrix (right operand).
     *
     * @note This function is functionally identical to LDL_Mat4fMultiply.
     * @note Provided for compatibility and clarity in different contexts.
     * @see LDL_Mat4fMultiply
     */
    LDL_LIBRARY void LDL_Mat4fCross(LDL_Mat4f* result, const LDL_Mat4f* a, const LDL_Mat4f* b);

    /**
     * @brief Creates a view matrix for camera positioning (Look-At).
     *
     * This function creates a view matrix that positions the camera at
     * the eye position looking towards the center position with the given
     * up direction.
     *
     * @param mat     A pointer to the LDL_Mat4f structure to store the result.
     * @param eyeX    X coordinate of the camera (eye) position.
     * @param eyeY    Y coordinate of the camera (eye) position.
     * @param eyeZ    Z coordinate of the camera (eye) position.
     * @param centerX X coordinate of the target (center) position.
     * @param centerY Y coordinate of the target (center) position.
     * @param centerZ Z coordinate of the target (center) position.
     * @param upX     X component of the up vector.
     * @param upY     Y component of the up vector.
     * @param upZ     Z component of the up vector.
     *
     * @note The up vector should be non-zero and not parallel to the view direction.
     * @note The matrix overwrites any previous content in the matrix.
     * @note This is the standard OpenGL look-at function.
     *
     * @code
     * // Example: Position camera at (0, 0, 10) looking at origin
     * LDL_Mat4f view;
     * LDL_Mat4fLookAt(&view, 0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
     * @endcode
     *
     * @see LDL_Mat4fPerspective
     * @see LDL_Mat4fOrtho
     */
    LDL_LIBRARY void LDL_Mat4fLookAt(LDL_Mat4f* mat, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);

    /**
     * @brief Creates a perspective projection matrix.
     *
     * This function creates a perspective projection matrix with the specified
     * field of view, aspect ratio, and clipping planes.
     *
     * @param mat    A pointer to the LDL_Mat4f structure to store the result.
     * @param fovy   Field of view angle in degrees along the Y-axis.
     * @param aspect Aspect ratio (width / height) of the viewport.
     * @param nearv  Distance to the near clipping plane (must be > 0).
     * @param farv   Distance to the far clipping plane (must be > nearv).
     *
     * @note The matrix overwrites any previous content in the matrix.
     * @note Objects closer than nearv or farther than farv are clipped.
     * @note A larger fovy creates a wider field of view.
     * @note The aspect ratio should match the viewport's aspect ratio.
     *
     * @code
     * // Example: Create a perspective projection for a 800x600 viewport
     * LDL_Mat4f projection;
     * LDL_Mat4fPerspective(&projection, 60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
     * @endcode
     *
     * @see LDL_Mat4fOrtho
     * @see LDL_Mat4fLookAt
     */
    LDL_LIBRARY void LDL_Mat4fPerspective(LDL_Mat4f* mat, float fovy, float aspect, float nearv, float farv);

#ifdef __cplusplus
}
#endif

#endif // LDL_Mat4f_H
