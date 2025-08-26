// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Core_PathNormalizer_hpp
#define Arcanum_Core_PathNormalizer_hpp

#include <string>

namespace Arcanum
{
	namespace Core
	{
		class PathNormalizer
		{
		public:
			void Normalize(char* path);
			void Normalize(std::string& path);
		private:
		};
	}
}

#endif