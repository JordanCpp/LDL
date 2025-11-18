// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/Graphics/BaseWindow.hpp>

using namespace LDL;

BaseWindow::BaseWindow(const Vec2u& pos, const Vec2u& size, const char* title):
    _pos(pos),
    _size(size),
    _title(title)
{
}

const Vec2u& BaseWindow::Pos()
{
    return _pos;
}

const Vec2u& BaseWindow::Size()
{
    return _size;
}

void BaseWindow::Size(const Vec2u& size)
{
    _size = size;
}

const char* BaseWindow::Title()
{
    return _title.c_str();
}

void BaseWindow::Title(const char* source)
{
    _title = source;
}
