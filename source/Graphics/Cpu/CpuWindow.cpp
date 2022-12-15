#include <LDL/Graphics/Cpu/CpuWindow.hpp>
#include "../../Platforms/Windows/Graphics/Cpu/CpuWindowImpl.hpp"

using namespace LDL::Graphics;

CpuWindow::CpuWindow(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
	_CpuWindowImpl(new CpuWindowImpl(pos, size, title, mode))
{
}

CpuWindow::~CpuWindow()
{
	delete _CpuWindowImpl;
}

void CpuWindow::Present(uint8_t* pixels)
{
	_CpuWindowImpl->Present(pixels);
}

bool CpuWindow::GetEvent(LDL::Events::Event& event)
{
	return _CpuWindowImpl->GetEvent(event);
}

void CpuWindow::StopEvent()
{
	_CpuWindowImpl->StopEvent();
}

void CpuWindow::Title(const std::string& title)
{
	_CpuWindowImpl->Title(title);
}

const std::string& CpuWindow::Title()
{
	return _CpuWindowImpl->Title();
}

const Point2u& CpuWindow::Size()
{
	return _CpuWindowImpl->Size();
}

const Point2u& CpuWindow::Pos()
{
	return _CpuWindowImpl->Pos();
}