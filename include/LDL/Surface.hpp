// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Surface_hpp
#define LDL_Surface_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/Color.hpp>
#include <LDL/PVector.hpp>
#include <LDL/PixFrmt.hpp>

class LDL_LIBRARY LDL_Surface
{
public:
	LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size);
	LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels);
	LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size, const LDL_Vec2u& capacity);
	LDL_Surface(size_t pixelFormat, const LDL_Vec2u& size, const LDL_Vec2u& capacity, uint8_t* pixels);
	~LDL_Surface();
	void ColorKey(const LDL_Color& key);
	const LDL_Color& ColorKey();
	bool Enabled();
	const LDL_Vec2u& Capacity();
	const LDL_Vec2u& Size();
	void LDL_Resize(const LDL_Vec2u& size);
	void Clear();
	uint8_t BytesPerPixel();
	uint8_t* Pixels();
	size_t Format();
	size_t Pitch();
private:
	bool                   _enabled;
	LDL_Color              _key;
	size_t                 _pixelFormat;
	LDL_Vec2u              _capacity;
	LDL_Vec2u              _size;
	LDL_PodVector<uint8_t> _pixels;
};

#endif 
