#include <LDL/Graphics/Cpu/CpuWindow.hpp>
#include "../../Platforms/Windows/Graphics/Cpu/CpuWindowImpl.hpp"

LDL::Graphics::CpuWindow::CpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode) :
	_CpuWindowImpl(new LDL::Graphics::CpuWindowImpl(pos, size, title, mode))
{
}

LDL::Graphics::CpuWindow::~CpuWindow()
{
	delete _CpuWindowImpl;
}

void LDL::Graphics::CpuWindow::Present(uint8_t* pixels)
{
	_CpuWindowImpl->Present(pixels);
}

bool LDL::Graphics::CpuWindow::GetEvent(LDL::Events::Event& event)
{
	return _CpuWindowImpl->GetEvent(event);
}

void LDL::Graphics::CpuWindow::StopEvent()
{
	_CpuWindowImpl->StopEvent();
}

void LDL::Graphics::CpuWindow::Title(const std::string& title)
{
	_CpuWindowImpl->Title(title);
}

const std::string& LDL::Graphics::CpuWindow::Title()
{
	return _CpuWindowImpl->Title();
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuWindow::Size()
{
	return _CpuWindowImpl->Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::CpuWindow::Pos()
{
	return _CpuWindowImpl->Pos();
}