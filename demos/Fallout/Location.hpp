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
#include "MapObject.hpp"

namespace Fallout
{
	class Location
	{
	public:
		LDL::Vec2i             Size;
		std::vector<Tile>      Tiles;
		std::vector<MapObject> Objects;
	};
}

#endif
