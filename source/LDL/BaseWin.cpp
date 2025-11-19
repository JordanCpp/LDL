// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/BaseWin.hpp>

LDL_BaseWindow::LDL_BaseWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title):
    _pos(pos),
    _size(size),
    _title(title)
{
}

const LDL_Vec2u& LDL_BaseWindow::Pos()
{
    return _pos;
}

const LDL_Vec2u& LDL_BaseWindow::Size()
{
    return _size;
}

void LDL_BaseWindow::Size(const LDL_Vec2u& size)
{
    _size = size;
}

const char* LDL_BaseWindow::Title()
{
    return _title.c_str();
}

void LDL_BaseWindow::Title(const char* source)
{
    _title = source;
}
