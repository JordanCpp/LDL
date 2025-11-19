// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_Scenery_hpp
#define Arcanum_Objects_Scenery_hpp

#include <Arcanum/Graphics/Sprite.hpp>
#include <Arcanum/Objects/MapObject.hpp>

namespace Arcanum
{
	class Scenery
	{
	public:
		Scenery();
		void Init(Sprite* sprite);
		Sprite* Body();
		const LDL_Vec2u& Pos();
		void Pos(const LDL_Vec2u& pos);
	private:
		MapObject _mapObject;
		Sprite*   _body;
	};
}

#endif
