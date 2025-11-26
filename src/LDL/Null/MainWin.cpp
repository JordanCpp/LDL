// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Null/MainWin.hpp>

LDL_MainWindow::LDL_MainWindow(LDL_Result& result, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode) :
    _result(result),
    _baseWindow(pos, size, title, mode)
{
}

LDL_MainWindow::~LDL_MainWindow()
{
}

bool LDL_MainWindow::Running()
{
    return _eventer.Running();
}

void LDL_MainWindow::PollEvents()
{
}

bool LDL_MainWindow::GetEvent(LDL_Event& event)
{
    return _eventer.Running();
}

bool LDL_MainWindow::WaitEvent(LDL_Event& event)
{
    return false;
}

void LDL_MainWindow::StopEvent()
{
    _eventer.Stop();
}

void LDL_MainWindow::Title(const char* title)
{
    _baseWindow.Title(title);
}

const char* LDL_MainWindow::Title()
{
    return _baseWindow.Title();
}

const LDL_Vec2u& LDL_MainWindow::Size()
{
    return _baseWindow.Size();
}

const LDL_Vec2u& LDL_MainWindow::Pos()
{
    return _baseWindow.Pos();
}
