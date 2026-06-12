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

#include "Location.hpp"

using namespace LDL;
using namespace Fallout;

Vec2i CartToIso(const Vec2i& pt)
{
	return Vec2i(pt.x - pt.y, (pt.x + pt.y) / 2);
}

Location::Location(LDL::Render2D& render, SpriteManager& spriteManager) :
	_render(render),
	_spriteManager(spriteManager)
{
	_size = Vec2i(10, 10);

	_tiles.reserve(_size.x * _size.y);

	for (size_t i = 0; i < _tiles.capacity(); i++)
	{
		Tile tile;
		tile._sprite = _spriteManager.GetSprite("data/HOLA096.bmp");

		_tiles.push_back(tile);
	}
}

void Location::Draw(const Vec2i& start)
{
    for (int y = 0; y < _size.y; y++)
    {
        for (int x = 0; x < _size.x; x++)
        {
            Vec2i pt = Vec2i(2 * 16 * y - 3 * 16 * x, 2 * 12 * y + 12 * x);

            int index = y * _size.x + x;

			_render.Draw(_tiles[index]._sprite->Single(), Vec2i(start.x + pt.x, start.y + pt.y));
        }
    }
}
