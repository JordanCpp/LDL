// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/BaseWin.hpp>
#include <LDL/Enums.hpp>

LDL_BaseWindow::LDL_BaseWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode):
    _mode(mode),
    _pos(pos),
    _size(size),
    _title(_bufferTitle, sizeof(_bufferTitle))
{
    _title.assign(title);
}

bool LDL_BaseWindow::HasMode(size_t mode) const
{
    return (_mode & mode) != 0;
}

const LDL_Vec2u& LDL_BaseWindow::Pos() const
{
    return _pos;
}

void LDL_BaseWindow::Pos(const LDL_Vec2u& pos)
{
    _pos = pos;
}

const LDL_Vec2u& LDL_BaseWindow::Size() const
{
    return _size;
}

void LDL_BaseWindow::Size(const LDL_Vec2u& size)
{
    _size = size;
}

const char* LDL_BaseWindow::Title() const
{
    return _title.c_str();
}

void LDL_BaseWindow::Title(const char* source)
{
    _title.assign(source);
}

bool LDL_BaseWindow::IsFullScreen() const
{
    return HasMode(LDL_WindowMode::FullScreen);
}

bool LDL_BaseWindow::IsResized() const
{
    return HasMode(LDL_WindowMode::Resized);
}

bool LDL_BaseWindow::IsFixed() const
{
    return HasMode(LDL_WindowMode::Fixed);
}

bool LDL_BaseWindow::IsMinimized() const
{
    return HasMode(LDL_WindowMode::Minimized);
}

bool LDL_BaseWindow::IsMaximized() const
{
    return HasMode(LDL_WindowMode::Maximized);
}

bool LDL_BaseWindow::IsCentered() const
{
    return HasMode(LDL_WindowMode::Centered);
}
