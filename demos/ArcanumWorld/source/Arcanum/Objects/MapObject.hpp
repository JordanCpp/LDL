// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_MapObject_hpp
#define Arcanum_Objects_MapObject_hpp

#include <LDL/Math/Vec2.hpp>

namespace Arcanum
{
	class MapObject
	{
	public:
		const LDL::Vec2u& Pos();
		void Pos(const LDL::Vec2u& pos);
	private:
		LDL::Vec2u _pos;
	};
}

#endif
