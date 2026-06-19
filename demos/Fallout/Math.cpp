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

using namespace LDL;
using namespace Fallout;

LDL::Vec2i Fallout::TileIndexToScreen(int index, int cols)
{
    int tx = index % cols;
    int ty = index / cols;

    int x = 2 * Stx * ty - 3 * Stx * tx;
    int y = 2 * Sty * ty + Sty * tx;

    return Vec2i(x, y);
}

int Fallout::ScreenToTileIndex(int screenX, int screenY, int cols)
{
    int x = screenX - 8;
    int y = screenY + 20;

    int tx = (x - 4 * y / 3) / 64;
    int ty = (x + 4 * y) / 128;

    return ty * cols - tx;
}

LDL::Vec2i Fallout::HexIndexToScreen(int index, int cols)
{
    int cols2 = cols * 2;
    int tx = index % cols2;
    int ty = index / cols2;

    int target_ty = index / cols2;
    int target_tx = index % cols2;

    int x = Stx * (target_ty - target_tx - (target_tx / 2)) - 8;
    int y = Sty * (target_ty + target_tx - (target_tx / 2)) - 32;

    return Vec2i(x, y);
}

int Fallout::ScreenToHexIndex(int screenX, int screenY, int cols)
{
    int x = screenX + 8;
    int y = screenY + 32;

    int tx = (y * Stx - x * Sty) / (2 * Stx * Sty);
    int ty = (3 * y * Stx + x * Sty) / (4 * Stx * Sty);

    return ty * (cols * 2) + tx;
}
