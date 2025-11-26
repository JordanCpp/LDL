// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_BmpLoad_hpp
#define LDL_BmpLoad_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/PVector.hpp>
#include <LDL/Result.hpp>
#include <LDL/PixFrmt.hpp>
#include <LDL/Format.hpp>
#include <LDL/FStream.hpp>

class LDL_LIBRARY LDL_BmpLoader
{
public:
	LDL_BmpLoader(LDL_Result& result);
	~LDL_BmpLoader();
	bool Load(const char* path);
	const LDL_Vec2u& Size();
	uint8_t Bpp();
	uint8_t* Pixels();
	size_t Format();
private:
	uint8_t                _bpp;
	size_t                 _pixelFormat;
	LDL_Result&            _result;
	LDL_Vec2u              _size;
	LDL_PodVector<uint8_t> _pixels;
	LDL_Formatter          _formatter;
	LDL_IFileStream*       _stream;
};

#endif
