#include <LDL/Graphics/GpuWindow.hpp>
#include "../Platforms/Windows/Graphics/GL1/GpuWindowImpl.hpp"

LDL::Graphics::GpuWindow::GpuWindow(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode) :
	_GpuWindowImpl(new LDL::Graphics::GpuWindowImpl(pos, size, title, mode))
{
}

LDL::Graphics::GpuWindow::~GpuWindow()
{
	delete _GpuWindowImpl;
}

void LDL::Graphics::GpuWindow::Present()
{
	_GpuWindowImpl->Present();
}

bool LDL::Graphics::GpuWindow::GetEvent(LDL::Events::Event& event)
{
	return _GpuWindowImpl->GetEvent(event);
}

bool LDL::Graphics::GpuWindow::WaitEvent(LDL::Events::Event& event)
{
	return _GpuWindowImpl->WaitEvent(event);
}

void LDL::Graphics::GpuWindow::StopEvent()
{
	_GpuWindowImpl->StopEvent();
}

void LDL::Graphics::GpuWindow::Title(const std::string& title)
{
	_GpuWindowImpl->Title(title);
}

const std::string& LDL::Graphics::GpuWindow::Title()
{
	return _GpuWindowImpl->Title();
}

const LDL::Graphics::Point2u& LDL::Graphics::GpuWindow::Size()
{
	return _GpuWindowImpl->Size();
}

const LDL::Graphics::Point2u& LDL::Graphics::GpuWindow::Pos()
{
	return _GpuWindowImpl->Pos();
}