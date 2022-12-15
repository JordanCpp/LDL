#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include "../../Platforms/Windows/Graphics/GL1/GpuWindowImpl.hpp"

using namespace LDL::Graphics;

GpuWindow::GpuWindow(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
	_GpuWindowImpl(new GpuWindowImpl(pos, size, title, mode))
{
}

GpuWindow::~GpuWindow()
{
	delete _GpuWindowImpl;
}

void GpuWindow::Present()
{
	_GpuWindowImpl->Present();
}

bool GpuWindow::GetEvent(LDL::Events::Event& event)
{
	return _GpuWindowImpl->GetEvent(event);
}

bool GpuWindow::WaitEvent(LDL::Events::Event& event)
{
	return _GpuWindowImpl->WaitEvent(event);
}

void GpuWindow::StopEvent()
{
	_GpuWindowImpl->StopEvent();
}

void GpuWindow::Title(const std::string& title)
{
	_GpuWindowImpl->Title(title);
}

const std::string& GpuWindow::Title()
{
	return _GpuWindowImpl->Title();
}

const Point2u& GpuWindow::Size()
{
	return _GpuWindowImpl->Size();
}

const Point2u& GpuWindow::Pos()
{
	return _GpuWindowImpl->Pos();
}