// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/StrModif.hpp>
#include <LDL/StdFuncs.hpp>

LDL_StringModif::LDL_StringModif(char* data, size_t capacity) :
	_data(data),
	_position(0),
	_capacity(capacity)
{
	if (_data != NULL && _capacity > 0)
	{
		_data[0] = '\0';
	}
}

void LDL_StringModif::clear()
{
	if (_data)
	{
		_data[0] = '\0';
	}

	_position = 0;
}

const char* LDL_StringModif::c_str() const
{
	return _data;
}

void LDL_StringModif::assign(const char* src)
{
	size_t length = LDL_strlen(src);

	if (length + 1 < _capacity)
	{
		LDL_strlcpy(_data, src, _capacity);
		_position = length;
	}
}

void LDL_StringModif::append(const char* src)
{
	if (src != NULL)
	{
		LDL_strlcat(_data, src, _capacity);

		size_t length = LDL_strlen(src);
	}
}
