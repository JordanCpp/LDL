/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef Fallout_Location_hpp
#define Fallout_Location_hpp

#include "Tile.hpp"
#include "SpriteManager.hpp"

namespace Fallout
{
	class Location
	{
	public:
		Location(LDL::Render2D& render, SpriteManager& spriteManager);
		void Draw(const LDL::Vec2i& start);
		LDL::Render2D     _render;
		SpriteManager&    _spriteManager;
		LDL::Vec2i        _size;
		std::vector<Tile> _tiles;
	};
}

#endif
