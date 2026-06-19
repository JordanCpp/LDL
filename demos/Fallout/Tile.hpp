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

#ifndef Fallout_Tile_hpp
#define Fallout_Tile_hpp

#include "Sprite.hpp"

namespace Fallout
{
	class Tile
	{
	public:
		enum
		{
			Width  = 80,
			Height = 36
		};
		std::string _spriteName;
		Sprite*     _sprite;
	};
}

#endif
