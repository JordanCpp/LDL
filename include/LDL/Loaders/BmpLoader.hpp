// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_BmpLoader_hpp
#define LDL_Loaders_BmpLoader_hpp

#include <LDL/STL/vector.hpp>
#include <LDL/Math/Vec2.hpp>
#include <LDL/Core/Result.hpp>

namespace LDL
{
	namespace Loaders
	{
		class LDL_LIBRARY BmpLoader
		{
		public:
			BmpLoader(Core::Result& result);
			bool Load(const char* path);
			const Math::Vec2u& Size();
			uint8_t Bpp();
			uint8_t* Pixels();
		private:
			uint8_t         _bpp;
			Core::Result&   _result;
			Math::Vec2u     _size;
			vector<uint8_t> _pixels;
		};
	}
}

#endif
