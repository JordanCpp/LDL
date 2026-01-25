// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_StrModif_hpp
#define LDL_StrModif_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_LIBRARY LDL_StringModif
{
public:
	LDL_StringModif(char* data, size_t capacity);
	void clear();
	const char* c_str() const;
	void assign(const char* src);
	void append(const char* src);
private:
	char*  _data;
	size_t _position;
	size_t _capacity;
};

#endif
