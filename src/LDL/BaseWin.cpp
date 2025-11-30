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

const LDL_Vec2u& LDL_BaseWindow::Pos()
{
    return _pos;
}

void LDL_BaseWindow::Pos(const LDL_Vec2u& pos)
{
    _pos = pos;
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
    _title.assign(source);
}

bool LDL_BaseWindow::IsFullScreen()
{
    return (_mode & LDL_WindowMode::FullScreen) != 0;
}

bool LDL_BaseWindow::IsResized()
{
    return (_mode & LDL_WindowMode::Resized) != 0;
}

bool LDL_BaseWindow::IsFixed()
{
    return (_mode & LDL_WindowMode::Fixed) != 0;
}

bool LDL_BaseWindow::IsMinimized()
{
    return (_mode & LDL_WindowMode::Minimized) != 0;
}

bool LDL_BaseWindow::IsMaximized()
{
    return (_mode & LDL_WindowMode::Maximized) != 0;
}

bool LDL_BaseWindow::IsCentered()
{
    return (_mode & LDL_WindowMode::Centered) != 0;
}
