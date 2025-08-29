// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_BmpLoader_hpp
#define LDL_Loaders_BmpLoader_hpp

#include <LDL/STL/vector.hpp>
#include <LDL/Math/Vec2.hpp>
#include <LDL/Core/Result.hpp>
#include <LDL/Graphics/PixelFormat.hpp>

namespace LDL
{
	class LDL_LIBRARY BmpLoader
	{
	public:
		BmpLoader(Result& result);
		bool Load(const char* path);
		const Vec2u& Size();
		uint8_t Bpp();
		uint8_t* Pixels();
		size_t GetPixelFormat();
	private:
		uint8_t         _bpp;
		size_t          _pixelFormat;
		Result&         _result;
		Vec2u           _size;
		vector<uint8_t> _pixels;
	};
}

#endif
