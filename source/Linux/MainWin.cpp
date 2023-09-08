#include "MainWin.hpp"
#include <LDL/Low/Enums.hpp>

LDL_MainWinow::LDL_MainWinow(LDL_ErrorHandler* errorHandler, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode) :
    _BaseWindow(pos, size, title),
    _ErrorHandler(errorHandler)
{
}

LDL_MainWinow::~LDL_MainWinow()
{
}

bool LDL_MainWinow::Running()
{
    return _Eventer.Running();
}

void LDL_MainWinow::PollEvents()
{
}

bool LDL_MainWinow::GetEvent(LDL_Event& event)
{
    return false;
}

bool LDL_MainWinow::WaitEvent(LDL_Event& event)
{
    return _Eventer.Running();
}

void LDL_MainWinow::StopEvent()
{
    _Eventer.Stop();
}

void LDL_MainWinow::Title(const char* title)
{
    _BaseWindow.Title(title);
}

const char* LDL_MainWinow::Title()
{
    return _BaseWindow.Title();
}

const LDL_Point2u& LDL_MainWinow::Size()
{
    return _BaseWindow.Size();
}

const LDL_Point2u& LDL_MainWinow::Pos()
{
    return _BaseWindow.Pos();
}
