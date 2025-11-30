// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/StrView.hpp>
#include <LDL/StdFuncs.hpp>

LDL_StringView::LDL_StringView(char* data, size_t capacity) :
	_data(data),
	_position(0),
	_capacity(capacity)
{
}

void LDL_StringView::clear()
{
	_data[0]  = '\0';
	_position = 0;
}

const char* LDL_StringView::c_str() const
{
	return _data;
}

void LDL_StringView::assign(const char* src)
{
	size_t length = LDL_strlen(src);

	if (length + _position + 1 < _capacity)
	{
		LDL_strlcpy(_data, src, _capacity);
		_position = length;
	}
}

void LDL_StringView::append(const char* src)
{
	LDL_strlcat(_data, src, _capacity);

	size_t length = LDL_strlen(src);
}
