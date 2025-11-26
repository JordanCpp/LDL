// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Vec3_hpp
#define LDL_Vec3_hpp

template<class T>
class LDL_Vec3
{
public:
	LDL_Vec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	LDL_Vec3(T v1, T v2, T v3)
	{
		x = v1;
		y = v2;
		z = v3;
	}

	LDL_Vec3(T v)
	{
		x = v;
		y = v;
		z = v;
	}

	LDL_Vec3<T> operator + (const LDL_Vec3<T>& source) const
	{
		LDL_Vec3<T> result;

		result.x = x + source.x;
		result.y = y + source.y;
		result.z = z + source.z;

		return result;
	}

	LDL_Vec3<T> operator - (const LDL_Vec3<T>& source) const
	{
		LDL_Vec3<T> result;

		result.x = x - source.x;
		result.y = y - source.y;
		result.z = z - source.z;

		return result;
	}

	LDL_Vec3<T> operator += (const LDL_Vec3<T>& right)
	{
		x += right.x;
		y += right.y;
		z += right.z;

		return *this;
	}

	LDL_Vec3<T> operator -= (const LDL_Vec3<T>& right)
	{
		x -= right.x;
		y -= right.y;
		z -= right.z;

		return *this;
	}

	LDL_Vec3<T> operator * (const LDL_Vec3<T>& source) const
	{
		LDL_Vec3<T> result;

		result.x = x * source.x;
		result.y = y * source.y;
		result.z = z * source.z;

		return result;
	}

	LDL_Vec3<T> operator * (const T& source) const
	{
		LDL_Vec3<T> result;

		result.x = x * source;
		result.y = y * source;
		result.z = z * source;

		return result;
	}

	T x;
	T y;
	T z;
};

#endif     
