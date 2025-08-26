// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_LocationLimits_hpp
#define Arcanum_Objects_LocationLimits_hpp

namespace Arcanum
{
	namespace Objects
	{
		class LocationLimits
		{
		public:
			enum
			{
				Tiles     = 100 * 100,
				Critters  = 1024,
				Sceneries = 2048,
				Walls     = 4096
			};
		private:
		};
	}
}

#endif