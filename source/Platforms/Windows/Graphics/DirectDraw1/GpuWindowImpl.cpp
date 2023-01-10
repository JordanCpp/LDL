#include "GpuWindowImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

GpuWindowImpl::GpuWindowImpl(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode) :
    _Window(pos, size, title, mode)
{
}

GpuWindowImpl::~GpuWindowImpl()
{
}

void GpuWindowImpl::Present()
{
}

const Point2u& GpuWindowImpl::Size()
{
    return _Window.Size();
}

const Point2u& LDL::Graphics::GpuWindowImpl::View()
{
    return _Window.View();
}

const Point2u& GpuWindowImpl::Pos()
{
    return _Window.Pos();
}

bool GpuWindowImpl::GetEvent(LDL::Events::Event& event)
{
    return _Window.GetEvent(event);
}

bool GpuWindowImpl::WaitEvent(LDL::Events::Event& event)
{
    return _Window.WaitEvent(event);
}

void GpuWindowImpl::StopEvent()
{
    _Window.StopEvent();
}

const std::string& GpuWindowImpl::Title()
{
    return _Window.Title();
}

void GpuWindowImpl::Title(const std::string& title)
{
    _Window.Title(title);
}

HWND GpuWindowImpl::Hwnd()
{
    return _Window._HWND;
}