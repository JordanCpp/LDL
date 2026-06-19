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

#ifndef Fallout_Math_hpp
#define Fallout_Math_hpp

#include <vector>
#include <LDL/C++98/LDL.hpp>

namespace Fallout
{
    const int Stx = 16;
    const int Sty = 12;

    LDL::Vec2i TileIndexToScreen(int index, int cols);
    int ScreenToTileIndex(int screenX, int screenY, int cols);

    LDL::Vec2i HexIndexToScreen(int index, int cols);
    int ScreenToHexIndex(int screenX, int screenY, int cols);
}

#endif
