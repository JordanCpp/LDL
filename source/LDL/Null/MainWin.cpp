// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Null/MainWin.hpp>

LDL_MainWindow::LDL_MainWindow(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode)
{
}

LDL_MainWindow::~LDL_MainWindow()
{
}

bool LDL_MainWindow::Running()
{
    return false;
}

void LDL_MainWindow::PollEvents()
{
}

bool LDL_MainWindow::GetEvent(LDL_Event& event)
{
    return false;
}

bool LDL_MainWindow::WaitEvent(LDL_Event& event)
{
    return false;
}

void LDL_MainWindow::StopEvent()
{
}

void LDL_MainWindow::Title(const char* title)
{
}

const char* LDL_MainWindow::Title()
{
    return NULL;
}

const LDL_Vec2u& LDL_MainWindow::Size()
{
    return _pos;
}

const LDL_Vec2u& LDL_MainWindow::Pos()
{
    return _size;
}
