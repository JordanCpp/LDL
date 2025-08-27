// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_Tile_hpp
#define Arcanum_Objects_Tile_hpp

#include <Arcanum/Graphics/Sprite.hpp>
#include <Arcanum/Objects/MapObject.hpp>

namespace Arcanum
{
	class Tile
	{
	public:
		enum
		{
			Width = 78,
			Height = 40
		};

		Tile();
		const LDL::Vec2u& Pos();
		void Pos(const LDL::Vec2u& pos);
		void Init(Sprite* sprite);
		Sprite* Body();
	private:
		MapObject _mapObject;
		Sprite*   _body;
	};
}

#endif
