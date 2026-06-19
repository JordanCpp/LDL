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

#include "Math.hpp"
#include "LocationPainter.hpp"

using namespace LDL;
using namespace Fallout;

LocationPainter::LocationPainter(LocationData& location, Render2D& render, SpriteManager& spriteManager) :
	_location(location),
	_render(render),
	_spriteManager(spriteManager)
{
}

void LocationPainter::DrawTiles(const Vec2i& pos)
{
    int cols = _location.Size.x;
    int rows = _location.Size.y;

    for (int i = 0; i < (_location.Size.x * _location.Size.y); ++i)
    {
        Vec2i offset = TileIndexToScreen(i, cols);

        Sprite* sprite = _spriteManager.GetSprite(_location.Tiles[i]._spriteName);

        if (sprite)
        {
            _render.Draw(sprite->Single(), Vec2i(pos.x + offset.x, pos.y + offset.y));
        }
    }
}

void LocationPainter::DrawHexs(const LDL::Vec2i& pos)
{
    int cols = _location.Size.x;
    int totalHexes = (_location.Size.x * 2) * (_location.Size.y * 2);

    for (int i = 0; i < totalHexes; ++i)
    {
        Vec2i offset = HexIndexToScreen(i, cols);

        Sprite* sprite = _spriteManager.GetSprite("data/MSEF000.bmp");

        if (sprite)
        {
            _render.Draw(sprite->Single(), Vec2i(pos.x + offset.x, pos.y + offset.y));
        }
    }
}

void LocationPainter::DrawObjects(const LDL::Vec2i& pos)
{
    int cols = _location.Size.x;

    Vec2i hexOffset = HexIndexToScreen(154, cols);

    Sprite* treeSprite = _spriteManager.GetSprite("data/Shina001.bmp");

    if (treeSprite)
    {
        Vec2i spriteSize = treeSprite->Single()->GetSize();

        int drawX = pos.x + hexOffset.x - (spriteSize.x / 2);
        int drawY = pos.y + hexOffset.y - spriteSize.y;

        _render.Draw(treeSprite->Single(), Vec2i(drawX, drawY));
    }
}

void LocationPainter::Draw(const LDL::Vec2i& pos)
{
	DrawTiles(pos);
	DrawHexs(pos);
    DrawObjects(pos);
}
