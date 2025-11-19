// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Mat4_hpp
#define LDL_Mat4_hpp

#include <string.h>

template<class T>
class LDL_Mat4
{
public:
	LDL_Mat4()
	{
		Identity();
	}

	LDL_Mat4<T>& operator=(const LDL_Mat4<T>& source)
	{
		if (this == &source)
		{
			return *this;
		}

		memcpy(&_values, source._values, sizeof(_values));

		return *this;
	}

	T* Values()
	{
		return _values;
	}

	void Identity()
	{
		_values[0] = 1;
		_values[1] = 0;
		_values[2] = 0;
		_values[3] = 0;
		_values[4] = 0;
		_values[5] = 1;
		_values[6] = 0;
		_values[7] = 0;
		_values[8] = 0;
		_values[9] = 0;
		_values[10] = 1;
		_values[11] = 0;
		_values[12] = 0;
		_values[13] = 0;
		_values[14] = 0;
		_values[15] = 1;
	}

	LDL_Mat4 operator * (const LDL_Mat4& m) const {
		LDL_Mat4 ret;

		ret._values[0] = ((_values[0] * m._values[0]) + (_values[1] * m._values[4]) + (_values[2] * m._values[8]) + (_values[3] * m._values[12]));
		ret._values[1] = ((_values[0] * m._values[1]) + (_values[1] * m._values[5]) + (_values[2] * m._values[9]) + (_values[3] * m._values[13]));
		ret._values[2] = ((_values[0] * m._values[2]) + (_values[1] * m._values[6]) + (_values[2] * m._values[10]) + (_values[3] * m._values[14]));
		ret._values[3] = ((_values[0] * m._values[3]) + (_values[1] * m._values[7]) + (_values[2] * m._values[11]) + (_values[3] * m._values[15]));

		ret._values[4] = ((_values[4] * m._values[0]) + (_values[5] * m._values[4]) + (_values[6] * m._values[8]) + (_values[7] * m._values[12]));
		ret._values[5] = ((_values[4] * m._values[1]) + (_values[5] * m._values[5]) + (_values[6] * m._values[9]) + (_values[7] * m._values[13]));
		ret._values[6] = ((_values[4] * m._values[2]) + (_values[5] * m._values[6]) + (_values[6] * m._values[10]) + (_values[7] * m._values[14]));
		ret._values[7] = ((_values[4] * m._values[3]) + (_values[5] * m._values[7]) + (_values[6] * m._values[11]) + (_values[7] * m._values[15]));

		ret._values[8] = ((_values[8] * m._values[0]) + (_values[9] * m._values[4]) + (_values[10] * m._values[8]) + (_values[11] * m._values[12]));
		ret._values[9] = ((_values[8] * m._values[1]) + (_values[9] * m._values[5]) + (_values[10] * m._values[9]) + (_values[11] * m._values[13]));
		ret._values[10] = ((_values[8] * m._values[2]) + (_values[9] * m._values[6]) + (_values[10] * m._values[10]) + (_values[11] * m._values[14]));
		ret._values[11] = ((_values[8] * m._values[3]) + (_values[9] * m._values[7]) + (_values[10] * m._values[11]) + (_values[11] * m._values[15]));

		ret._values[12] = ((_values[12] * m._values[0]) + (_values[13] * m._values[4]) + (_values[14] * m._values[8]) + (_values[15] * m._values[12]));
		ret._values[13] = ((_values[12] * m._values[1]) + (_values[13] * m._values[5]) + (_values[14] * m._values[9]) + (_values[15] * m._values[13]));
		ret._values[14] = ((_values[12] * m._values[2]) + (_values[13] * m._values[6]) + (_values[14] * m._values[10]) + (_values[15] * m._values[14]));
		ret._values[15] = ((_values[12] * m._values[3]) + (_values[13] * m._values[7]) + (_values[14] * m._values[11]) + (_values[15] * m._values[15]));

		return ret;
	}

	T _values[16];
};

typedef LDL_Mat4<float> Mat4f;

#endif      
